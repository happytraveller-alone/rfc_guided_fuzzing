// File count: 846
// Total lines: 19
-----------------------------------------
void __fastcall LogFastMappingFailureEvent(
        unsigned int a1,
        const unsigned __int16 *a2,
        const struct _CERT_CONTEXT *a3,
        int a4)
{
  int v7; // [rsp+20h] [rbp-38h]
  DWORD cbCertEncoded; // [rsp+28h] [rbp-30h]
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 2) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    cbCertEncoded = a3->cbCertEncoded;
    v7 = a4;
    SchEventWrite(&SSLEVENT_FAST_MAPPING_FAILURE, L"dudb", a1, &DestinationString, v7, cbCertEncoded, a3->pbCertEncoded);
  }
}
