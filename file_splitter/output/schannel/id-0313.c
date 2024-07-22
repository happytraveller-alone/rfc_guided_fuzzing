//----- (0000000180017230) ----------------------------------------------------
__int64 SchannelShutdown(void)
{
  BOOL v0; // ebx
  unsigned int v1; // ebx
  CSslCredManager *v3; // rcx
  CCipherMill *v4; // rcx

  v0 = LsaTable == 0;
  RtlEnterCriticalSection(&CSslGlobals::m_InitCriticalSection);
  if ( !v0 )
  {
    v3 = CSessionCacheManager::m_pSessionCacheManager;
    if ( CSessionCacheManager::m_pSessionCacheManager )
    {
      CSessionCacheManager::ShutdownSessionCache(CSessionCacheManager::m_pSessionCacheManager);
      CSessionCacheManager::m_pSessionCacheManager = 0i64;
    }
    if ( CSslCredManager::m_pCredManager )
    {
      CSslCredManager::FreeCredentialManager(v3);
      CSslCredManager::m_pCredManager = 0i64;
    }
    if ( DTLSCookieManager::m_pCookieMgr )
    {
      DTLSCookieManager::`scalar deleting destructor'(DTLSCookieManager::m_pCookieMgr);
      DTLSCookieManager::m_pCookieMgr = 0i64;
    }
    ShutdownIssuerCache();
    SchShutdownEvents();
    UnloadSslRegOptions();
    TlsCloseBCryptHashProviders();
    if ( g_hSHAProvider )
    {
      BCryptCloseAlgorithmProvider(g_hSHAProvider, 0);
      g_hSHAProvider = 0i64;
    }
    if ( g_hMD5Provider )
    {
      BCryptCloseAlgorithmProvider(g_hMD5Provider, 0);
      g_hMD5Provider = 0i64;
    }
    if ( g_hDSAProvider )
    {
      BCryptCloseAlgorithmProvider(g_hDSAProvider, 0);
      g_hDSAProvider = 0i64;
    }
    if ( g_hRSAProvider )
    {
      BCryptCloseAlgorithmProvider(g_hRSAProvider, 0);
      g_hRSAProvider = 0i64;
    }
    if ( g_hDhSchannelProv )
    {
      CryptReleaseContext(g_hDhSchannelProv, 0);
      g_hDhSchannelProv = 0i64;
    }
    RtlAcquireResourceExclusive(&Resource, 1u);
    CCipherMill::ClearCipherMill(v4, 1);
    RtlReleaseResource(&Resource);
    CSslGlobals::CleanupPeriodicCleanupHandler();
    CSslGlobals::CleanupCryptLocatorHandles();
    CSslGlobals::CleanupCryptLocatorEvents();
    if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
    {
      CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized = 0;
      TlgUnregisterAggregateProvider();
    }
  }
  if ( g_hSspicli )
  {
    FreeLibrary(g_hSspicli);
    g_hSspicli = 0i64;
    g_pFreeContextBuffer = 0i64;
  }
  if ( g_hMskeyprotect )
  {
    FreeLibrary(g_hMskeyprotect);
    g_hMskeyprotect = 0i64;
    g_pKeyFileProtectSessionTicket = 0i64;
    g_pKeyFileUnprotectSessionTicket = 0i64;
  }
  if ( g_pSslProvCacheRWLock )
  {
    RtlDeleteResource(g_pSslProvCacheRWLock);
    LocalFree(g_pSslProvCacheRWLock);
  }
  v1 = 0;
  for ( g_pSslProvCacheRWLock = 0i64; v1 < g_cCachedPagedSslProvs; ++v1 )
    DestroyCachedSslProv((struct CACHED_SSL_PROVIDER *)((char *)&g_rgCachedPagedSslProvs + 16 * v1));
  g_cCachedPagedSslProvs = 0;
  CSslGlobals::m_bSchannelInitialized = 0;
  RtlLeaveCriticalSection(&CSslGlobals::m_InitCriticalSection);
  return 1i64;
}
// 18003ECF1: variable 'v3' is possibly undefined
// 18003EDE5: variable 'v4' is possibly undefined
// 180092180: using guessed type unsigned int (__stdcall *g_pKeyFileUnprotectSessionTicket)(unsigned __int8 *, unsigned int, const unsigned __int16 *, unsigned __int8 **, unsigned int *);
// 180092188: using guessed type unsigned int (__stdcall *g_pKeyFileProtectSessionTicket)(unsigned __int8 *, unsigned int, const unsigned __int16 *, unsigned __int8 **, unsigned int *);
// 1800921A0: using guessed type int (__stdcall *g_pFreeContextBuffer)(void *);
// 1800921D8: using guessed type int CSslGlobals::m_bSchannelInitialized;
// 180092620: using guessed type __int64 LsaTable;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 180092A90: using guessed type unsigned int g_cCachedPagedSslProvs;

