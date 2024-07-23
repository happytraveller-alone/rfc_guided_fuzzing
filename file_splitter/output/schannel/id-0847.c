// File count: 847
// Total lines: 34
-----------------------------------------
void __fastcall LogGetCertificateChainFailureEvent(
        unsigned int a1,
        const unsigned __int16 *a2,
        char a3,
        const struct _CERT_CONTEXT *a4,
        unsigned int a5,
        unsigned int a6)
{
  const WCHAR *v9; // rdx
  DWORD cbCertEncoded; // [rsp+38h] [rbp-40h]
  struct _UNICODE_STRING v13; // [rsp+50h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    v9 = (const WCHAR *)pszClientString;
    if ( a3 )
      v9 = pszServerString;
    RtlInitUnicodeString(&v13, v9);
    cbCertEncoded = a4->cbCertEncoded;
    SchEventWrite(
      &SSLEVENT_GET_CERT_CHAIN_FAILURE,
      L"duuddb",
      a1,
      &DestinationString,
      &v13,
      a5,
      a6,
      cbCertEncoded,
      a4->pbCertEncoded);
  }
}
