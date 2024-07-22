//----- (0000000180045164) ----------------------------------------------------
void __fastcall LogNoPrivateKeyEvent(unsigned int a1, const unsigned __int16 *a2, char a3)
{
  const WCHAR *v5; // rdx
  struct _UNICODE_STRING v6; // [rsp+40h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+50h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    v5 = (const WCHAR *)pszClientString;
    if ( a3 )
      v5 = pszServerString;
    RtlInitUnicodeString(&v6, v5);
    SchEventWrite(&SSLEVENT_NO_PRIVATE_KEY, L"duub", a1, &DestinationString, &v6, 0i64, 0i64);
  }
}

