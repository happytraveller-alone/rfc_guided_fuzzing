//----- (00000001800451F4) ----------------------------------------------------
void __fastcall LogReceiveAlertEvent(unsigned int a1, const unsigned __int16 *a2, char a3, unsigned __int8 a4)
{
  int v5; // ebx
  int v6; // [rsp+20h] [rbp-28h]
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-18h] BYREF

  v5 = a4;
  if ( (g_dwEventLogging & 4) != 0 && a3 == 2 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    v6 = v5;
    SchEventWrite(&SSLEVENT_RECEIVE_FATAL_ALERT, L"dud", a1, &DestinationString, v6);
  }
}

