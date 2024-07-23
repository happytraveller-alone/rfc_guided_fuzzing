// File count: 856
// Total lines: 37
-----------------------------------------
void SchShutdownEvents(void)
{
  int v0; // eax
  int v1; // [rsp+20h] [rbp-18h]

  if ( g_RegistrationHandle )
  {
    v0 = EtwEventUnregister();
    if ( v0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        v1 = v0;
        WPP_SF_SD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xBu,
          (__int64)&WPP_9cc880ee923835bef0ce0974c4127801_Traceguids,
          L"Schannel",
          v1);
      }
    }
  }
  if ( pszClientString )
  {
    LocalFree(pszClientString);
    pszClientString = 0i64;
  }
  if ( pszServerString )
  {
    LocalFree((HLOCAL)pszServerString);
    pszServerString = 0i64;
  }
}
// 180080EA0: using guessed type __int64 EtwEventUnregister(void);
// 180084F18: using guessed type wchar_t aSchannel_2[9];
// 180092D80: using guessed type unsigned __int64 g_RegistrationHandle;
