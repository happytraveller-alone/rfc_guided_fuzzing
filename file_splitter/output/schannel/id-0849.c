// File count: 849
// Total lines: 32
-----------------------------------------
void __fastcall LogIncompleteCertificateChainEvent(
        unsigned int a1,
        const unsigned __int16 *a2,
        char a3,
        const struct _CERT_CONTEXT *a4,
        unsigned int a5)
{
  const WCHAR *v8; // rdx
  DWORD cbCertEncoded; // [rsp+30h] [rbp-38h]
  struct _UNICODE_STRING v11; // [rsp+40h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+50h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    v8 = (const WCHAR *)pszClientString;
    if ( a3 )
      v8 = pszServerString;
    RtlInitUnicodeString(&v11, v8);
    cbCertEncoded = a4->cbCertEncoded;
    SchEventWrite(
      &SSLEVENT_INCOMPLETE_CERT_CHAIN_FAILURE,
      L"duudb",
      a1,
      &DestinationString,
      &v11,
      a5,
      cbCertEncoded,
      a4->pbCertEncoded);
  }
}
