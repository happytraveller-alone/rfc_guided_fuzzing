//----- (0000000180055070) ----------------------------------------------------
void CSslGlobals::CleanupPeriodicCleanupHandler(void)
{
  int LastError; // eax

  if ( (unsigned int)_InterlockedIncrement((volatile signed __int32 *)&CSslGlobals::m_lReentryCount) <= 1 )
  {
    if ( CSslGlobals::m_hCleanupWaitObject )
    {
      if ( !UnregisterWaitEx(CSslGlobals::m_hCleanupWaitObject, (HANDLE)0xFFFFFFFFFFFFFFFFi64)
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      {
        LastError = GetLastError();
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xAu,
          (__int64)&WPP_092b895ef39c3c047a28e4103b904d61_Traceguids,
          LastError);
      }
      CSslGlobals::m_hCleanupWaitObject = 0i64;
    }
    if ( CSslGlobals::m_hCleanupEvent )
    {
      CloseHandle(CSslGlobals::m_hCleanupEvent);
      CSslGlobals::m_hCleanupEvent = 0i64;
    }
  }
  _InterlockedDecrement((volatile signed __int32 *)&CSslGlobals::m_lReentryCount);
}
// 180092EE0: using guessed type unsigned int CSslGlobals::m_lReentryCount;

