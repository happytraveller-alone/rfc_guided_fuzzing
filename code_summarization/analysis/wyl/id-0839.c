//----- (0000000180044B64) ----------------------------------------------------
void __fastcall LogCertMappingFailureEvent(unsigned int a1, const unsigned __int16 *a2, int a3)
{
  int v5; // [rsp+20h] [rbp-38h]
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 2) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    v5 = a3;
    SchEventWrite(&SSLEVENT_CERT_MAPPING_FAILURE, L"dudb", a1, &DestinationString, v5, 0i64, 0i64);
  }
}
