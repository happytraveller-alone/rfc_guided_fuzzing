//----- (00000001800279E8) ----------------------------------------------------
__int64 CSslGlobals::InitializePeriodicCleanupHandler(void)
{
  DWORD v0; // ebx
  DWORD LastError; // edi
  HANDLE EventA; // rax

  v0 = 0;
  LastError = 0;
  if ( (unsigned int)_InterlockedIncrement((volatile signed __int32 *)&CSslGlobals::m_lReentryCount) <= 1 )
  {
    EventA = CreateEventA(0i64, 0, 0, 0i64);
    CSslGlobals::m_hCleanupEvent = EventA;
    if ( !EventA
      || (CSslGlobals::m_hCleanupWaitObject = (HANDLE)RegisterWaitForSingleObjectEx(
                                                        EventA,
                                                        CSslGlobals::PeriodicCleanupHandler,
                                                        0i64,
                                                        1000 * CSslGlobals::m_dwCleanupIntervalInSeconds,
                                                        0)) == 0i64 )
    {
      LastError = GetLastError();
      if ( LastError )
        CSslGlobals::CleanupPeriodicCleanupHandler();
    }
    v0 = LastError;
  }
  _InterlockedDecrement((volatile signed __int32 *)&CSslGlobals::m_lReentryCount);
  return v0;
}
// 180080BC0: using guessed type __int64 __fastcall RegisterWaitForSingleObjectEx(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180092EE0: using guessed type unsigned int CSslGlobals::m_lReentryCount;

