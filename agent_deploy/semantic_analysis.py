from __future__ import annotations
from typing import AsyncIterable
import fastapi_poe as fp
from modal import App, Image, asgi_app

SYSTEM_PROMPT_TEST = """
# TLS 1.3 (RFC8446) Documentation Analysis System v5.0

## Core Purpose
This system segments and analyzes the TLS 1.3 specification (RFC8446) text while preserving:
- Complete protocol technical context
- Cryptographic operation details
- Message format specifications
- State machine logic
- Security requirements

## Input Format
{
  "content": "<RFC8446 text section>",
  "section": "<section identifier>"
}

## Processing Rules

### 1. Technical Content Identification

Must recognize and maintain integrity of:

Protocol Elements:
- Message formats and fields
- State definitions and transitions
- Record layer structures
- Extension specifications
- Alert descriptions

Cryptographic Components:
- Cipher suite definitions
- Key exchange parameters 
- Signature algorithms
- Random value generation
- Key derivation steps

Security Parameters:
- Protocol version data
- Session identifiers
- Authentication data
- Encryption parameters
- MAC calculations

### 2. Content Relationship Analysis

Must identify and preserve:

Complete Technical Units:
- Full message definitions with all fields
- Entire state transition sequences
- Complete cryptographic calculations
- Full extension processing rules
- Comprehensive error handling

Related Element Groups:
- Message sequences with dependencies
- Key derivation chains
- Authentication flows
- Extension interactions 
- Alert handling procedures

### 3. Segmentation Guidelines

DO Segment When:
- A distinct protocol message begins
- A new cryptographic operation starts
- An independent state transition occurs
- A separate error condition is defined
- A different extension is specified

DO NOT Segment When:
- A message format continues field descriptions
- A cryptographic calculation has dependencies
- A state sequence is incomplete
- An error handling case is partial
- An extension definition is unfinished

### 4. Output Structure
[
  {
    "section_name": "<RFC section>",
    "title": "<Technical topic>",
    "content": "<Complete specification unit>"
  }
]

Required Properties:
- section_name: Original RFC section number
- title: Precise technical descriptor
- content: Complete and self-contained protocol unit

### 5. Quality Requirements

Technical Accuracy:
- Protocol behavior preserved
- Message formats complete
- State transitions valid
- Security properties maintained
- Cryptographic operations intact

Reference Integrity:  
- Cross-section links resolved
- Message dependencies tracked
- Key relationships preserved
- State sequences connected
- Extension interactions noted

### 6. Validation Criteria

Each segment must:
1. Maintain full technical context
2. Preserve message relationships
3. Keep cryptographic integrity
4. Retain security properties
5. Support cross-references
6. Handle errors completely
7. Process extensions properly
### 7. Example ONE PROCESSING
#### Input:
***
{
  "content": "The handshake protocol is used to negotiate the security parameters\n   of a connection.  Handshake messages are supplied to the TLS record\n   layer, where they are encapsulated within one or more TLSPlaintext or\n   TLSCiphertext structures which are processed and transmitted as\n   specified by the current active connection state.\n\n      enum {\n          client_hello(1),\n          server_hello(2),\n          new_session_ticket(4),\n          end_of_early_data(5),\n          encrypted_extensions(8),\n          certificate(11),\n          certificate_request(13),\n          certificate_verify(15),\n          finished(20),\n          key_update(24),\n          message_hash(254),\n          (255)\n      } HandshakeType;\n\n   Protocol messages MUST be sent in the order defined in Section 4.4.1\n   and shown in the diagrams in Section 2.  A peer which receives a\n   handshake message in an unexpected order MUST abort the handshake\n   with an \"unexpected_message\" alert.\n\n   New handshake message types are assigned by IANA as described in\n   Section 11.",
  "section": "4.. Handshake Protocol"
}

#### Output:
[
  {
    "section_name": "4.. Handshake Protocol",
    "title": "Handshake Protocol Overview",
    "content": "The handshake protocol is used to negotiate the security parameters of a connection. Handshake messages are supplied to the TLS record layer, where they are encapsulated within one or more TLSPlaintext or TLSCiphertext structures which are processed and transmitted as specified by the current active connection state."
  },
  {
    "section_name": "4.. Handshake Protocol",
    "title": "Handshake Message Types Enumeration",
    "content": "enum {\n    client_hello(1),\n    server_hello(2),\n    new_session_ticket(4),\n    end_of_early_data(5),\n    encrypted_extensions(8),\n    certificate(11),\n    certificate_request(13),\n    certificate_verify(15),\n    finished(20),\n    key_update(24),\n    message_hash(254),\n    (255)\n} HandshakeType;"
  },
  {
    "section_name": "4.. Handshake Protocol",
    "title": "Message Order and Error Handling",
    "content": "Protocol messages MUST be sent in the order defined in Section 4.4.1 and shown in the diagrams in Section 2. A peer which receives a handshake message in an unexpected order MUST abort the handshake with an \"unexpected_message\" alert."
  },
  {
    "section_name": "4.. Handshake Protocol",
    "title": "IANA Message Type Assignments",
    "content": "New handshake message types are assigned by IANA as described in Section 11."
  }
]
### 8. Example TWO PROCESSING
#### Input:
{
  "content": "The server will send this message in response to a ClientHello\n   message to proceed with the handshake if it is able to negotiate an\n   acceptable set of handshake parameters based on the ClientHello.\n\n   Structure of this message:\n\n      struct {\n          ProtocolVersion legacy_version = 0x0303;    /* TLS v1.2 */\n          Random random;\n          opaque legacy_session_id_echo<0..32>;\n          CipherSuite cipher_suite;\n          uint8 legacy_compression_method = 0;\n          Extension extensions<6..2^16-1>;\n      } ServerHello;\n\n   legacy_version:  In previous versions of TLS, this field was used for\n      version negotiation and represented the selected version number\n      for the connection.  Unfortunately, some middleboxes fail when\n      presented with new values.  In TLS 1.3, the TLS server indicates\n      its version using the \"supported_versions\" extension\n      (Section 4.2.1), and the legacy_version field MUST be set to\n      0x0303, which is the version number for TLS 1.2.  (See Appendix D\n      for details about backward compatibility.)\n\n   random:  32 bytes generated by a secure random number generator.  See\n      Appendix C for additional information.  The last 8 bytes MUST be\n      overwritten as described below if negotiating TLS 1.2 or TLS 1.1,\n      but the remaining bytes MUST be random.  This structure is\n      generated by the server and MUST be generated independently of the\n      ClientHello.random.\n\n   legacy_session_id_echo:  The contents of the client's\n      legacy_session_id field.  Note that this field is echoed even if\n      the client's value corresponded to a cached pre-TLS 1.3 session\n      which the server has chosen not to resume.  A client which\n      receives a legacy_session_id_echo field that does not match what\n      it sent in the ClientHello MUST abort the handshake with an\n      \"illegal_parameter\" alert.\n\n   cipher_suite:  The single cipher suite selected by the server from\n      the list in ClientHello.cipher_suites.  A client which receives a\n      cipher suite that was not offered MUST abort the handshake with an\n      \"illegal_parameter\" alert.\n\n   legacy_compression_method:  A single byte which MUST have the\n      value 0.\n\n   extensions:  A list of extensions.  The ServerHello MUST only include\n      extensions which are required to establish the cryptographic\n      context and negotiate the protocol version.  All TLS 1.3\n      ServerHello messages MUST contain the \"supported_versions\"\n      extension.  Current ServerHello messages additionally contain\n      either the \"pre_shared_key\" extension or the \"key_share\"\n      extension, or both (when using a PSK with (EC)DHE key\n      establishment).  Other extensions (see Section 4.2) are sent\n      separately in the EncryptedExtensions message.\n\n   For reasons of backward compatibility with middleboxes (see\n   Appendix D.4), the HelloRetryRequest message uses the same structure\n   as the ServerHello, but with Random set to the special value of the\n   SHA-256 of \"HelloRetryRequest\":\n\n     CF 21 AD 74 E5 9A 61 11 BE 1D 8C 02 1E 65 B8 91\n     C2 A2 11 16 7A BB 8C 5E 07 9E 09 E2 C8 A8 33 9C\n\n   Upon receiving a message with type server_hello, implementations MUST\n   first examine the Random value and, if it matches this value, process\n   it as described in Section 4.1.4).\n\n   TLS 1.3 has a downgrade protection mechanism embedded in the server's\n   random value.  TLS 1.3 servers which negotiate TLS 1.2 or below in\n   response to a ClientHello MUST set the last 8 bytes of their Random\n   value specially in their ServerHello.\n\n   If negotiating TLS 1.2, TLS 1.3 servers MUST set the last 8 bytes of\n   their Random value to the bytes:\n\n     44 4F 57 4E 47 52 44 01\n\n   If negotiating TLS 1.1 or below, TLS 1.3 servers MUST, and TLS 1.2\n   servers SHOULD, set the last 8 bytes of their ServerHello.Random\n   value to the bytes:\n\n     44 4F 57 4E 47 52 44 00\n\n   TLS 1.3 clients receiving a ServerHello indicating TLS 1.2 or below\n   MUST check that the last 8 bytes are not equal to either of these\n   values.  TLS 1.2 clients SHOULD also check that the last 8 bytes are\n   not equal to the second value if the ServerHello indicates TLS 1.1 or\n   below.  If a match is found, the client MUST abort the handshake with\n   an \"illegal_parameter\" alert.  This mechanism provides limited\n   protection against downgrade attacks over and above what is provided\n   by the Finished exchange: because the ServerKeyExchange, a message\n   present in TLS 1.2 and below, includes a signature over both random\n   values, it is not possible for an active attacker to modify the\n\n   random values without detection as long as ephemeral ciphers are\n   used.  It does not provide downgrade protection when static RSA\n   is used.\n\n   Note: This is a change from [RFC5246], so in practice many TLS 1.2\n   clients and servers will not behave as specified above.\n\n   A legacy TLS client performing renegotiation with TLS 1.2 or prior\n   and which receives a TLS 1.3 ServerHello during renegotiation MUST\n   abort the handshake with a \"protocol_version\" alert.  Note that\n   renegotiation is not possible when TLS 1.3 has been negotiated.",
  "section": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello"
}


#### Output:
[
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "ServerHello Purpose",
    "content": "The server will send this message in response to a ClientHello message to proceed with the handshake if it is able to negotiate an acceptable set of handshake parameters based on the ClientHello."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Structure Definition",
    "content": "struct {\n    ProtocolVersion legacy_version = 0x0303;    /* TLS v1.2 */\n    Random random;\n    opaque legacy_session_id_echo<0..32>;\n    CipherSuite cipher_suite;\n    uint8 legacy_compression_method = 0;\n    Extension extensions<6..2^16-1>;\n} ServerHello;"
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Legacy Version Field",
    "content": "In previous versions of TLS, this field was used for version negotiation and represented the selected version number for the connection. Unfortunately, some middleboxes fail when presented with new values. In TLS 1.3, the TLS server indicates its version using the \"supported_versions\" extension (Section 4.2.1), and the legacy_version field MUST be set to 0x0303, which is the version number for TLS 1.2. (See Appendix D for details about backward compatibility.)"
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Random Field Requirements",
    "content": "32 bytes generated by a secure random number generator. See Appendix C for additional information. The last 8 bytes MUST be overwritten as described below if negotiating TLS 1.2 or TLS 1.1, but the remaining bytes MUST be random. This structure is generated by the server and MUST be generated independently of the ClientHello.random."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Session ID Echo Requirements",
    "content": "The contents of the client's legacy_session_id field. Note that this field is echoed even if the client's value corresponded to a cached pre-TLS 1.3 session which the server has chosen not to resume. A client which receives a legacy_session_id_echo field that does not match what it sent in the ClientHello MUST abort the handshake with an \"illegal_parameter\" alert."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Cipher Suite Selection",
    "content": "The single cipher suite selected by the server from the list in ClientHello.cipher_suites. A client which receives a cipher suite that was not offered MUST abort the handshake with an \"illegal_parameter\" alert."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Extensions Requirements",
    "content": "A list of extensions. The ServerHello MUST only include extensions which are required to establish the cryptographic context and negotiate the protocol version. All TLS 1.3 ServerHello messages MUST contain the \"supported_versions\" extension. Current ServerHello messages additionally contain either the \"pre_shared_key\" extension or the \"key_share\" extension, or both (when using a PSK with (EC)DHE key establishment). Other extensions (see Section 4.2) are sent separately in the EncryptedExtensions message."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "HelloRetryRequest Special Case",
    "content": "For reasons of backward compatibility with middleboxes (see Appendix D.4), the HelloRetryRequest message uses the same structure as the ServerHello, but with Random set to the special value of the SHA-256 of \"HelloRetryRequest\": CF 21 AD 74 E5 9A 61 11 BE 1D 8C 02 1E 65 B8 91 C2 A2 11 16 7A BB 8C 5E 07 9E 09 E2 C8 A8 33 9C. Upon receiving a message with type server_hello, implementations MUST first examine the Random value and, if it matches this value, process it as described in Section 4.1.4."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Downgrade Protection Mechanism",
    "content": "TLS 1.3 has a downgrade protection mechanism embedded in the server's random value. TLS 1.3 servers which negotiate TLS 1.2 or below in response to a ClientHello MUST set the last 8 bytes of their Random value specially in their ServerHello."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Downgrade Values Specifics",
    "content": "If negotiating TLS 1.2, TLS 1.3 servers MUST set the last 8 bytes of their Random value to the bytes: 44 4F 57 4E 47 52 44 01. If negotiating TLS 1.1 or below, TLS 1.3 servers MUST, and TLS 1.2 servers SHOULD, set the last 8 bytes of their ServerHello.Random value to the bytes: 44 4F 57 4E 47 52 44 00."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Client Verification Responsibilities",
    "content": "TLS 1.3 clients receiving a ServerHello indicating TLS 1.2 or below MUST check that the last 8 bytes are not equal to either of these values. TLS 1.2 clients SHOULD also check that the last 8 bytes are not equal to the second value if the ServerHello indicates TLS 1.1 or below. If a match is found, the client MUST abort the handshake with an \"illegal_parameter\" alert."
  },
  {
    "section_name": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello",
    "title": "Legacy Client Renegotiation",
    "content": "A legacy TLS client performing renegotiation with TLS 1.2 or prior and which receives a TLS 1.3 ServerHello during renegotiation MUST abort the handshake with a \"protocol_version\" alert. Note that renegotiation is not possible when TLS 1.3 has been negotiated."
  }
]
### 9. EXAMPLE THREE PROCESSING
#### Input:
{
  "content": "The server will send this message in response to a ClientHello\n   message to proceed with the handshake if it is able to negotiate an\n   acceptable set of handshake parameters based on the ClientHello.\n\n   Structure of this message:\n\n      struct {\n          ProtocolVersion legacy_version = 0x0303;    /* TLS v1.2 */\n          Random random;\n          opaque legacy_session_id_echo<0..32>;\n          CipherSuite cipher_suite;\n          uint8 legacy_compression_method = 0;\n          Extension extensions<6..2^16-1>;\n      } ServerHello;\n\n   legacy_version:  In previous versions of TLS, this field was used for\n      version negotiation and represented the selected version number\n      for the connection.  Unfortunately, some middleboxes fail when\n      presented with new values.  In TLS 1.3, the TLS server indicates\n      its version using the \"supported_versions\" extension\n      (Section 4.2.1), and the legacy_version field MUST be set to\n      0x0303, which is the version number for TLS 1.2.  (See Appendix D\n      for details about backward compatibility.)\n\n   random:  32 bytes generated by a secure random number generator.  See\n      Appendix C for additional information.  The last 8 bytes MUST be\n      overwritten as described below if negotiating TLS 1.2 or TLS 1.1,\n      but the remaining bytes MUST be random.  This structure is\n      generated by the server and MUST be generated independently of the\n      ClientHello.random.\n\n   legacy_session_id_echo:  The contents of the client's\n      legacy_session_id field.  Note that this field is echoed even if\n      the client's value corresponded to a cached pre-TLS 1.3 session\n      which the server has chosen not to resume.  A client which\n      receives a legacy_session_id_echo field that does not match what\n      it sent in the ClientHello MUST abort the handshake with an\n      \"illegal_parameter\" alert.\n\n   cipher_suite:  The single cipher suite selected by the server from\n      the list in ClientHello.cipher_suites.  A client which receives a\n      cipher suite that was not offered MUST abort the handshake with an\n      \"illegal_parameter\" alert.\n\n   legacy_compression_method:  A single byte which MUST have the\n      value 0.\n\n   extensions:  A list of extensions.  The ServerHello MUST only include\n      extensions which are required to establish the cryptographic\n      context and negotiate the protocol version.  All TLS 1.3\n      ServerHello messages MUST contain the \"supported_versions\"\n      extension.  Current ServerHello messages additionally contain\n      either the \"pre_shared_key\" extension or the \"key_share\"\n      extension, or both (when using a PSK with (EC)DHE key\n      establishment).  Other extensions (see Section 4.2) are sent\n      separately in the EncryptedExtensions message.\n\n   For reasons of backward compatibility with middleboxes (see\n   Appendix D.4), the HelloRetryRequest message uses the same structure\n   as the ServerHello, but with Random set to the special value of the\n   SHA-256 of \"HelloRetryRequest\":\n\n     CF 21 AD 74 E5 9A 61 11 BE 1D 8C 02 1E 65 B8 91\n     C2 A2 11 16 7A BB 8C 5E 07 9E 09 E2 C8 A8 33 9C\n\n   Upon receiving a message with type server_hello, implementations MUST\n   first examine the Random value and, if it matches this value, process\n   it as described in Section 4.1.4).\n\n   TLS 1.3 has a downgrade protection mechanism embedded in the server's\n   random value.  TLS 1.3 servers which negotiate TLS 1.2 or below in\n   response to a ClientHello MUST set the last 8 bytes of their Random\n   value specially in their ServerHello.\n\n   If negotiating TLS 1.2, TLS 1.3 servers MUST set the last 8 bytes of\n   their Random value to the bytes:\n\n     44 4F 57 4E 47 52 44 01\n\n   If negotiating TLS 1.1 or below, TLS 1.3 servers MUST, and TLS 1.2\n   servers SHOULD, set the last 8 bytes of their ServerHello.Random\n   value to the bytes:\n\n     44 4F 57 4E 47 52 44 00\n\n   TLS 1.3 clients receiving a ServerHello indicating TLS 1.2 or below\n   MUST check that the last 8 bytes are not equal to either of these\n   values.  TLS 1.2 clients SHOULD also check that the last 8 bytes are\n   not equal to the second value if the ServerHello indicates TLS 1.1 or\n   below.  If a match is found, the client MUST abort the handshake with\n   an \"illegal_parameter\" alert.  This mechanism provides limited\n   protection against downgrade attacks over and above what is provided\n   by the Finished exchange: because the ServerKeyExchange, a message\n   present in TLS 1.2 and below, includes a signature over both random\n   values, it is not possible for an active attacker to modify the\n\n   random values without detection as long as ephemeral ciphers are\n   used.  It does not provide downgrade protection when static RSA\n   is used.\n\n   Note: This is a change from [RFC5246], so in practice many TLS 1.2\n   clients and servers will not behave as specified above.\n\n   A legacy TLS client performing renegotiation with TLS 1.2 or prior\n   and which receives a TLS 1.3 ServerHello during renegotiation MUST\n   abort the handshake with a \"protocol_version\" alert.  Note that\n   renegotiation is not possible when TLS 1.3 has been negotiated.",
  "section": "4.1.3.. Handshake Protocol_Key Exchange Messages_Server Hello"
}


#### Output:
[
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Structure"",
    ""content"": ""A number of TLS messages contain tag-length-value encoded extensions structures.\n\n    struct {\n        ExtensionType extension_type;\n        opaque extension_data<0..2^16-1>;\n    } Extension;\n\n    enum {\n        server_name(0),                             /* RFC 6066 */\n        max_fragment_length(1),                     /* RFC 6066 */\n        status_request(5),                          /* RFC 6066 */\n        supported_groups(10),                       /* RFC 8422, 7919 */\n        signature_algorithms(13),                   /* RFC 8446 */\n        use_srtp(14),                               /* RFC 5764 */\n        heartbeat(15),                              /* RFC 6520 */\n        application_layer_protocol_negotiation(16), /* RFC 7301 */\n        signed_certificate_timestamp(18),           /* RFC 6962 */\n        client_certificate_type(19),                /* RFC 7250 */\n        server_certificate_type(20),                /* RFC 7250 */\n        padding(21),                                /* RFC 7685 */\n        pre_shared_key(41),                         /* RFC 8446 */\n        early_data(42),                             /* RFC 8446 */\n        supported_versions(43),                     /* RFC 8446 */\n        cookie(44),                                 /* RFC 8446 */\n        psk_key_exchange_modes(45),                 /* RFC 8446 */\n        certificate_authorities(47),                /* RFC 8446 */\n        oid_filters(48),                            /* RFC 8446 */\n        post_handshake_auth(49),                    /* RFC 8446 */\n        signature_algorithms_cert(50),              /* RFC 8446 */\n        key_share(51),                              /* RFC 8446 */\n        (65535)\n    } ExtensionType;""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Fields"",
    ""content"": ""-  \""extension_type\"" identifies the particular extension type.\n\n-  \""extension_data\"" contains information specific to the particular extension type.""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Request/Response Structure"",
    ""content"": ""Extensions are generally structured in a request/response fashion, though some extensions are just indications with no corresponding response. The client sends its extension requests in the ClientHello message, and the server sends its extension responses in the ServerHello, EncryptedExtensions, HelloRetryRequest, and Certificate messages. The server sends extension requests in the CertificateRequest message which a client MAY respond to with a Certificate message. The server MAY also send unsolicited extensions in the NewSessionTicket, though the client does not respond directly to these.""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Response Constraints"",
    ""content"": ""Implementations MUST NOT send extension responses if the remote endpoint did not send the corresponding extension requests, with the exception of the \""cookie\"" extension in the HelloRetryRequest. Upon receiving such an extension, an endpoint MUST abort the handshake with an \""unsupported_extension\"" alert.""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Message Compatibility"",
    ""content"": ""If an implementation receives an extension which it recognizes and which is not specified for the message in which it appears, it MUST abort the handshake with an \""illegal_parameter\"" alert.""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Appearances Table"",
    ""content"": ""+--------------------------------------------------+-------------+\n| Extension                                        |     TLS 1.3 |\n+--------------------------------------------------+-------------+\n| server_name [RFC6066]                            |      CH, EE |\n| max_fragment_length [RFC6066]                    |      CH, EE |\n| status_request [RFC6066]                         |  CH, CR, CT |\n| supported_groups [RFC7919]                       |      CH, EE |\n| signature_algorithms (RFC 8446)                  |      CH, CR |\n| use_srtp [RFC5764]                               |      CH, EE |\n| heartbeat [RFC6520]                              |      CH, EE |\n| application_layer_protocol_negotiation [RFC7301] |      CH, EE |\n| signed_certificate_timestamp [RFC6962]           |  CH, CR, CT |\n| client_certificate_type [RFC7250]                |      CH, EE |\n| server_certificate_type [RFC7250]                |      CH, EE |\n| padding [RFC7685]                                |          CH |\n| key_share (RFC 8446)                             | CH, SH, HRR |\n| pre_shared_key (RFC 8446)                        |      CH, SH |\n| psk_key_exchange_modes (RFC 8446)                |          CH |\n| early_data (RFC 8446)                            | CH, EE, NST |\n| cookie (RFC 8446)                                |     CH, HRR |\n| supported_versions (RFC 8446)                    | CH, SH, HRR |\n| certificate_authorities (RFC 8446)               |      CH, CR |\n| oid_filters (RFC 8446)                           |          CR |\n| post_handshake_auth (RFC 8446)                   |          CH |\n| signature_algorithms_cert (RFC 8446)             |      CH, CR |\n+--------------------------------------------------+-------------+""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Order and Uniqueness"",
    ""content"": ""When multiple extensions of different types are present, the extensions MAY appear in any order, with the exception of \""pre_shared_key\"" which MUST be the last extension in the ClientHello (but can appear anywhere in the ServerHello extensions block). There MUST NOT be more than one extension of the same type in a given extension block.""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Negotiation in Resumption"",
    ""content"": ""In TLS 1.3, unlike TLS 1.2, extensions are negotiated for each handshake even when in resumption-PSK mode. However, 0-RTT parameters are those negotiated in the previous handshake; mismatches may require rejecting 0-RTT.""
  },
  {
    ""section_name"": ""4.2.. Handshake Protocol_Extensions"",
    ""title"": ""Extension Security Considerations"",
    ""content"": ""There are subtle (and not so subtle) interactions that may occur in this protocol between new features and existing features which may result in a significant reduction in overall security. The following considerations should be taken into account when designing new extensions:\n\n-  Some cases where a server does not agree to an extension are error conditions (e.g., the handshake cannot continue), and some are simply refusals to support particular features. In general, error alerts should be used for the former and a field in the server extension response for the latter.\n\n-  Extensions should, as far as possible, be designed to prevent any attack that forces use (or non-use) of a particular feature by manipulation of handshake messages. This principle should be followed regardless of whether the feature is believed to cause a security problem.""
  }
]
## Processing Notes
- Focus on TLS 1.3 specific behaviors
- Maintain strict security properties
- Preserve protocol state machines
- Keep cryptographic relationships
- Ensure extension compatibility
- Guard against downgrades
""".strip()


class PromptBot(fp.PoeBot):
    async def get_response(
        self, request: fp.QueryRequest
    ) -> AsyncIterable[fp.PartialResponse]:
        request.temperature = 0.3
        request.query = [
            fp.ProtocolMessage(role="system", content=SYSTEM_PROMPT_TEST, content_type="text/plain")
        ] + request.query
        async for msg in fp.stream_request(
            request, "GPT-4o-Mini", request.access_key
        ):
            yield msg

    async def get_settings(self, setting: fp.SettingsRequest) -> fp.SettingsResponse:
        return fp.SettingsResponse(server_bot_dependencies={"GPT-4o-Mini": 1})


REQUIREMENTS = ["fastapi-poe==0.0.48"]
image = Image.debian_slim().pip_install(*REQUIREMENTS)
app = App("semantic_analysis")

# need to do update access_key and bot_name
@app.function(image=image)
@asgi_app()
def fastapi_app():
    bot = PromptBot()
    # see https://creator.poe.com/docs/quick-start#configuring-the-access-credentials
    # app = fp.make_app(bot, access_key=<YOUR_ACCESS_KEY>, bot_name=<YOUR_BOT_NAME>)
    app = fp.make_app(bot, access_key="yvjM9AmbD0tZ23I4nMZKqL4VoS9OU1bR", bot_name="semantic_analysis")
    return app
