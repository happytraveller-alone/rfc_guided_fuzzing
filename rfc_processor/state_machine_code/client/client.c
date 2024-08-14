#include <tls.h>

enum ClientState {
  START,
  WAIT_SH,
  WAIT_EE,
  WAIT_CERT_CR,
  WAIT_CERT,
  WAIT_CV,
  WAIT_FINISHED,
  CONNECTED
};

void tls13_client_handshake(TLS_CTX *ctx) {
  ClientState state = START;
  bool can_send_early_data = false;
  bool using_psk = false;
  bool client_auth_requested = false;

  while (state != CONNECTED) {
    switch (state) {

    case START:
      /* RFC 8446 Section 4.1.2 - Client Hello
       * "When a client first connects to a server, it is REQUIRED to send
       * the ClientHello as its first TLS message."
       * Send ClientHello and optionally early data.
       */
      send_client_hello(ctx);
      if (can_send_early_data) {
        ctx->k_send = derive_early_data_key(ctx);
        send_early_data(ctx);
      }
      state = WAIT_SH;
      break;

    case WAIT_SH:
      /* RFC 8446 Section 4.1.4 - Hello Retry Request
       * "The server will send this message in response to a ClientHello
       * message if it is able to find an acceptable set of parameters
       * but the ClientHello does not contain sufficient information
       * to proceed with the handshake."
       */
      if (recv_hello_retry_request(ctx)) {
        state = START;
        break;
      }

      /* RFC 8446 Section 4.1.3 - Server Hello
       * "The server will send this message in response to a ClientHello
       * message to proceed with the handshake if it is able to negotiate
       * an acceptable set of handshake parameters based on the ClientHello."
       */
      if (recv_server_hello(ctx)) {
        ctx->k_recv = derive_handshake_key(ctx);
        state = WAIT_EE;
      }
      break;

    case WAIT_EE:
      /* RFC 8446 Section 4.3.1 - Encrypted Extensions
       * "The server MUST send the EncryptedExtensions message immediately
       * after the ServerHello message."
       */
      if (recv_encrypted_extensions(ctx)) {
        using_psk = check_if_using_psk(ctx);
        state = using_psk ? WAIT_FINISHED : WAIT_CERT_CR;
      }
      break;

    case WAIT_CERT_CR:
      /* RFC 8446 Section 4.4.2 - Certificate
       * "The server MUST send a Certificate message whenever the agreed-upon
       * key exchange method uses certificates for authentication."
       */
      if (recv_certificate(ctx)) {
        state = WAIT_CV;
        break;
      }

      /* RFC 8446 Section 4.3.2 - Certificate Request
       * "A server MAY request a certificate from the client by sending a
       * CertificateRequest message."
       */
      if (recv_certificate_request(ctx)) {
        client_auth_requested = true;
        state = WAIT_CERT;
        break;
      }

      state = WAIT_FINISHED;
      break;

    case WAIT_CERT:
      /* RFC 8446 Section 4.4.2 - Certificate
       * "The server MUST send a Certificate message whenever the agreed-upon
       * key exchange method uses certificates for authentication."
       */
      if (recv_certificate(ctx)) {
        state = WAIT_CV;
      }
      break;

    case WAIT_CV:
      /* RFC 8446 Section 4.4.3 - Certificate Verify
       * "The server MUST send this message when authenticating via a
       * certificate."
       */
      if (recv_certificate_verify(ctx)) {
        state = WAIT_FINISHED;
      }
      break;

    case WAIT_FINISHED:
      /* RFC 8446 Section 4.4.4 - Finished
       * "The Finished message is the final message in the Authentication
       * Block."
       */
      if (recv_finished(ctx)) {
        /* RFC 8446 Section 4.2.10 - Early Data Indication
         * "If the server accepts early data, then the server responds with
         * an 'early_data' extension in EncryptedExtensions."
         */
        if (can_send_early_data) {
          send_end_of_early_data(ctx);
        }

        ctx->k_send = derive_handshake_key(ctx);

        /* RFC 8446 Section 4.4.2 - Certificate
         * "The client MUST send a Certificate message if and only if the server
         * has requested client authentication via a CertificateRequest
         * message."
         */
        if (client_auth_requested) {
          send_certificate(ctx);
          send_certificate_verify(ctx);
        }

        send_finished(ctx);

        ctx->k_send = ctx->k_recv = derive_application_key(ctx);
        state = CONNECTED;
      }
      break;

    case CONNECTED:
      // Handshake complete
      break;
    }
  }
}