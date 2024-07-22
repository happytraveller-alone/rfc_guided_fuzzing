//----- (000000018002A428) ----------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  int v4; // ebx

  if ( fdwReason == 1 )
  {
    CSslGlobals::m_hInstance = hinstDLL;
    DisableThreadLibraryCalls(hinstDLL);
    if ( RtlInitializeCriticalSection(&CSslGlobals::m_InitCriticalSection) >= 0 )
    {
      g_bInitCritSecInitialized = 1;
      if ( RtlInitializeCriticalSection(&CSslGlobals::m_DTLSInitCriticalSection) >= 0 )
      {
        g_bDTLSInitCritSecInitialized = 1;
        if ( (int)TlsInitializeDefaultAlgorithms() >= 0 )
        {
          GetExternalSchannelAlgorithms();
          McGenEventRegister_EtwEventRegister();
          WPP_INIT_CONTROL_ARRAY();
          WPP_GLOBAL_Control = (CCipherMill *)&WPP_MAIN_CB;
          WPP_REGISTRATION_GUIDS = (__int64)&WPP_ThisDir_CTLGUID_SchannelWppGuid;
          WppInitUm();
          return 1;
        }
      }
    }
    return 0;
  }
  else
  {
    if ( fdwReason )
      return 1;
    v4 = SchannelShutdown();
    if ( g_bInitCritSecInitialized )
      RtlDeleteCriticalSection(&CSslGlobals::m_InitCriticalSection);
    if ( g_bDTLSInitCritSecInitialized )
      RtlDeleteCriticalSection(&CSslGlobals::m_DTLSInitCriticalSection);
    RemoveExternalSchannelAlgorithms();
    McGenEventUnregister_EtwEventUnregister();
    DeleteDebugTracing();
    WppCleanupUm();
    return v4;
  }
}
// 180092198: using guessed type unsigned __int8 g_bDTLSInitCritSecInitialized;
// 180092199: using guessed type unsigned __int8 g_bInitCritSecInitialized;
// 180092A60: using guessed type __int64 WPP_MAIN_CB;
// 180092A88: using guessed type __int64 WPP_REGISTRATION_GUIDS;

