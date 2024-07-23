// File count: 838
// Total lines: 60
-----------------------------------------
void __fastcall LogBogusServerCertEvent(
        unsigned int a1,
        const unsigned __int16 *a2,
        const struct _CERT_CONTEXT *a3,
        unsigned __int16 *a4,
        unsigned int a5)
{
  const struct _EVENT_DESCRIPTOR *v8; // rcx
  BYTE *pbCertEncoded; // [rsp+28h] [rbp-40h]
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-28h] BYREF
  struct _UNICODE_STRING v11; // [rsp+50h] [rbp-18h] BYREF

  RtlInitUnicodeString(&DestinationString, a2);
  if ( (g_dwEventLogging & 1) != 0 )
  {
    if ( a5 == -2146893022 )
    {
      RtlInitUnicodeString(&v11, a4);
      SchEventWrite(
        &SSLEVENT_NAME_MISMATCHED_SERVER_CERT,
        L"duub",
        a1,
        &DestinationString,
        &v11,
        a3->cbCertEncoded,
        a3->pbCertEncoded);
    }
    else
    {
      switch ( a5 )
      {
        case 0x80090325:
          pbCertEncoded = a3->pbCertEncoded;
          v8 = (const struct _EVENT_DESCRIPTOR *)&SSLEVENT_UNTRUSTED_SERVER_CERT;
          break;
        case 0x80090328:
          pbCertEncoded = a3->pbCertEncoded;
          v8 = &SSLEVENT_EXPIRED_SERVER_CERT;
          break;
        case 0x80092010:
          pbCertEncoded = a3->pbCertEncoded;
          v8 = (const struct _EVENT_DESCRIPTOR *)&SSLEVENT_REVOKED_SERVER_CERT;
          break;
        default:
          SchEventWrite(
            &SSLEVENT_BOGUS_SERVER_CERT,
            L"dudb",
            a1,
            &DestinationString,
            a5,
            a3->cbCertEncoded,
            a3->pbCertEncoded);
          return;
      }
      SchEventWrite(v8, L"dub", a1, &DestinationString, a3->cbCertEncoded, pbCertEncoded);
    }
  }
}
// 180084FE0: using guessed type struct _EVENT_DESCRIPTOR SSLEVENT_BOGUS_SERVER_CERT;
