//----- (000000018000E850) ----------------------------------------------------
__int64 __fastcall SchannelInit(int a1)
{
  unsigned int v2; // ebx
  __int64 v4; // r8
  CCipherMill *v5; // rcx
  CSessionCacheManager *CacheManager; // rax
  CSslCredManager *v7; // rax
  unsigned int LastError; // edi
  unsigned __int16 *v9; // rcx

  v2 = 1;
  if ( !CSslGlobals::m_bSchannelInitialized )
  {
    RtlEnterCriticalSection(&CSslGlobals::m_InitCriticalSection);
    if ( CSslGlobals::m_bSchannelInitialized )
    {
LABEL_7:
      RtlLeaveCriticalSection(&CSslGlobals::m_InitCriticalSection);
      return v2;
    }
    DisableThreadLibraryCalls(CSslGlobals::m_hInstance);
    SafeAllocaInitialize();
    if ( !a1 )
    {
      if ( BCryptOpenAlgorithmProvider(&g_hSHAProvider, L"SHA1", 0i64, 0)
        || BCryptOpenAlgorithmProvider(&g_hMD5Provider, L"MD5", 0i64, 0)
        || BCryptOpenAlgorithmProvider(&g_hDSAProvider, L"DSA", 0i64, 0)
        || BCryptOpenAlgorithmProvider(&g_hRSAProvider, L"RSA", 0i64, 0)
        || (unsigned int)CCipherMill::BuildCipherMill(v5) )
      {
        goto LABEL_33;
      }
      if ( !CryptAcquireContextW(&g_hDhSchannelProv, 0i64, 0i64, 0x12u, 0xF0000000) )
      {
        g_hDhSchannelProv = 0i64;
        LastError = GetLastError();
        v9 = (unsigned __int16 *)WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            10i64,
            &WPP_60bc9b1becfd3dd8c20089fcdaea9e65_Traceguids,
            LastError);
        LogGlobalAcquireContextFailedEvent(v9, LastError);
      }
      if ( !(unsigned int)LoadSslRegistryOptions() )
        goto LABEL_33;
      SchInitializeEvents();
      CacheManager = CSessionCacheManager::CreateCacheManager();
      if ( !CacheManager
        || (unsigned int)CSessionCacheManager::InitializeSessionCache(CacheManager)
        || (unsigned int)InitializeIssuerCache() )
      {
        goto LABEL_33;
      }
      v7 = CSslCredManager::m_pCredManager;
      if ( !CSslCredManager::m_pCredManager )
      {
        v7 = (CSslCredManager *)SPExternalAlloc(0x60u);
        if ( v7 )
          *(_QWORD *)v7 = &CSslCredManager::`vftable';
        CSslCredManager::m_pCredManager = v7;
        if ( !v7 )
          goto LABEL_33;
      }
      if ( !CSslCredManager::InitCredentialManager(v7) )
        goto LABEL_33;
      SslInitSystemMapper();
      if ( (unsigned int)InitializeSslMemoryOptions()
        || (unsigned int)CSslGlobals::InitializePeriodicCleanupHandler()
        || (unsigned int)CSslGlobals::InitializeCryptLocatorEvents() )
      {
        goto LABEL_33;
      }
      I_CertWnfEnableFlushCache();
    }
    if ( !(unsigned int)InitializeClientSideSslProvCache() )
    {
      LoadSecurityDll();
      CSslGlobals::m_bSchannelInitialized = 1;
      if ( a1 )
        goto LABEL_7;
      if ( (g_dwEventLogging & 4) != 0 )
        SchEventWrite(&SSLEVENT_SCHANNEL_STARTED, 0i64, v4);
      if ( !(unsigned int)TlgRegisterAggregateProviderEx() )
      {
        CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized = 1;
        QueryPerformanceFrequency(&CSchannelTelemetryContext::m_liPerfCtrFreq);
      }
LABEL_31:
      if ( !CSslGlobals::m_bSchannelInitialized )
        SchannelShutdown();
      goto LABEL_7;
    }
LABEL_33:
    v2 = 0;
    goto LABEL_31;
  }
  return v2;
}
// 18000E98F: variable 'v5' is possibly undefined
// 1800385D6: variable 'v4' is possibly undefined
// 1800385C2: variable 'v9' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18007D478: using guessed type void *CSslCredManager::`vftable';
// 1800921D8: using guessed type int CSslGlobals::m_bSchannelInitialized;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 180098170: using guessed type __int64 I_CertWnfEnableFlushCache(void);

