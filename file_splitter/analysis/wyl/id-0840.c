//----- (0000000180044BCC) ----------------------------------------------------
void __fastcall LogCipherMismatchEvent(unsigned int a1, const unsigned __int16 *a2, unsigned int a3)
{
  struct _UNICODE_STRING v5; // [rsp+30h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    MapProtocolToString(a3, &v5);
    SchEventWrite(&SSLEVENT_CIPHER_MISMATCH, L"duu", a1, &DestinationString, &v5);
  }
}

