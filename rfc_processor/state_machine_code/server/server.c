#include <tls.h>

enum ServerState {
  START,
  RECVD_CH,
  NEGOTIATED,
  WAIT_EOED,
  WAIT_FLIGHT2,
  WAIT_CERT,
  WAIT_CV,
  WAIT_FINISHED,
  CONNECTED
};

void tls13_server_handshake(TLS_CTX *ctx) {
  ServerState state = START;
  bool using_0rtt = false;
  bool client_auth_required = false;

  while (state != CONNECTED) {
    switch (state) {

    case START:
      /* RFC 8446 Section 4.1.2 - Client Hello
       * "When a client first connects to a server, it is REQUIRED to send
       * the ClientHello as its first TLS message."
       */
      if (recv_client_hello(ctx)) {
        state = RECVD_CH;
      }
      break;

    case RECVD_CH:
      /* RFC 8446 Section 4.1.4 - Hello Retry Request
       * "The server will send this message in response to a ClientHello
       * message if it is able to find an acceptable set of parameters
       * but the ClientHello does not contain sufficient information
       * to proceed with the handshake."
       */
      if (need_hello_retry_request(ctx)) {
        send_hello_retry_request(ctx);
        state = START;
      } else {
        state = NEGOTIATED;
      }
      break;

    case NEGOTIATED:
      /* RFC 8446 Section 4.1.3 - Server Hello
       * "The server will send this message in response to a ClientHello
       * message to proceed with the handshake if it is able to negotiate
       * an acceptable set of handshake parameters based on the ClientHello."
       */
      send_server_hello(ctx);
      ctx->k_send = derive_handshake_key(ctx);

      /* RFC 8446 Section 4.3.1 - Encrypted Extensions
       * "The server MUST send the EncryptedExtensions message immediately
       * after the ServerHello message."
       */
      send_encrypted_extensions(ctx);

      /* RFC 8446 Section 4.3.2 - Certificate Request
       * "A server can optionally request a certificate from the client"
       */
      if (client_auth_required) {
        send_certificate_request(ctx);
      }

      /* RFC 8446 Section 4.4.2 - Certificate
       * "The server MUST send a Certificate message whenever the agreed-upon
       * key exchange method uses certificates for authentication."
       */
      if (!using_psk(ctx)) {
        send_certificate(ctx);
        send_certificate_verify(ctx);
      }

      /* RFC 8446 Section 4.4.4 - Finished
       * "The Finished message is the final message in the Authentication
       * Block."
       */
      send_finished(ctx);

      ctx->k_send = derive_application_key(ctx);

      /* RFC 8446 Section 4.2.10 - Early Data Indication
       * "When a PSK is used and early data is allowed for that PSK, the client
       * can send Application Data in its first flight of messages."
       */
      if (using_0rtt) {
        ctx->k_recv = derive_early_data_key(ctx);
        state = WAIT_EOED;
      } else {
        ctx->k_recv = derive_handshake_key(ctx);
        state = WAIT_FLIGHT2;
      }
      break;

    case WAIT_EOED:
      /* RFC 8446 Section 4.2.10 - Early Data Indication
       * "If the server accepts early data, the client MUST send EndOfEarlyData
       * after receiving the server's Finished message."
       */
      if (recv_early_data(ctx)) {
        // Continue processing early data
      } else if (recv_end_of_early_data(ctx)) {
        ctx->k_recv = derive_handshake_key(ctx);
        state = WAIT_FLIGHT2;
      }
      break;

    case WAIT_FLIGHT2:
      if (client_auth_required) {
        state = WAIT_CERT;
      } else {
        state = WAIT_FINISHED;
      }
      break;

    case WAIT_CERT:
      /* RFC 8446 Section 4.4.2 - Certificate
       * "The client MUST send a Certificate message if and only if the server
       * has requested client authentication via a CertificateRequest message."
       */
      if (recv_certificate(ctx)) {
        if (is_empty_certificate(ctx)) {
          state = WAIT_FINISHED;
        } else {
          state = WAIT_CV;
        }
      }
      break;

    case WAIT_CV:
      /* RFC 8446 Section 4.4.3 - Certificate Verify
       * "The client MUST send this message whenever authenticating via a
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
        ctx->k_recv = derive_application_key(ctx);
        state = CONNECTED;
      }
      break;

    case CONNECTED:
      // Handshake complete
      break;
    }
  }
}