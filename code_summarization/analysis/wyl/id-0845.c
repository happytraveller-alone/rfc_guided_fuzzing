//----- (0000000180044EE8) ----------------------------------------------------
void __fastcall LogDtlsRetransmitRequested(unsigned int a1, const unsigned __int16 *a2)
{
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 4) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    SchEventWrite(&SSLEVENT_DTLS_RETRANSMIT_REQUESTED, L"du", a1, &DestinationString);
  }
}

