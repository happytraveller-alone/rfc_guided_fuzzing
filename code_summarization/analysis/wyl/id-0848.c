//----- (0000000180045064) ----------------------------------------------------
void __fastcall LogGlobalAcquireContextFailedEvent(unsigned __int16 *a1, unsigned int a2)
{
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, L"DSS");
    SchEventWrite(&SSLEVENT_GLOBAL_ACQUIRE_CONTEXT_FAILED, L"ud", (__int64)&DestinationString, a2);
  }
}

