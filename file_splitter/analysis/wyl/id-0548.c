//----- (0000000180027A84) ----------------------------------------------------
__int64 CSslGlobals::InitializeCryptLocatorEvents(void)
{
  DWORD LastError; // ebx
  CCipherMill *v2; // rcx
  __int64 v3; // rdx

  LastError = 0;
  CSslGlobals::m_hImplicitCertChangeEvent = CreateEventA(0i64, 0, 0, 0i64);
  if ( CSslGlobals::m_hImplicitCertChangeEvent )
  {
    CSslGlobals::m_hImplicitIssersChangeEvent = CreateEventA(0i64, 0, 0, 0i64);
    if ( CSslGlobals::m_hImplicitIssersChangeEvent )
      return LastError;
    LastError = GetLastError();
    v2 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v3 = 12i64;
      goto LABEL_10;
    }
  }
  else
  {
    LastError = GetLastError();
    v2 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v3 = 11i64;
LABEL_10:
      WPP_SF_D(*((_QWORD *)v2 + 2), v3, &WPP_092b895ef39c3c047a28e4103b904d61_Traceguids, LastError);
    }
  }
  if ( LastError )
    CSslGlobals::CleanupCryptLocatorEvents();
  return LastError;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
