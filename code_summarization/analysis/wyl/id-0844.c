//----- (0000000180044E9C) ----------------------------------------------------
void __fastcall LogDtlsRecordOutOfRecvWindow(unsigned int a1, const unsigned __int16 *a2)
{
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 2) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    SchEventWrite(&SSLEVENT_DTLS_RECORD_OUTSIDE_OF_RECV_WINDOW, L"du", a1, &DestinationString);
  }
}
