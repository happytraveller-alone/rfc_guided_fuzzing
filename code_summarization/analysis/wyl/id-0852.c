//----- (0000000180045258) ----------------------------------------------------
void __fastcall LogSessionTicketMisconfiguration(
        unsigned int a1,
        const unsigned __int16 *a2,
        const unsigned __int16 *a3)
{
  struct _UNICODE_STRING v5; // [rsp+30h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    RtlInitUnicodeString(&v5, a3);
    SchEventWrite(&SSLEVENT_SESSION_TICKET_MISCONFIGURATION, L"duu", a1, &DestinationString, &v5);
  }
}
