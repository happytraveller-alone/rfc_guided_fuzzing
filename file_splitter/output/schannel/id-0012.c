// File count: 12
// Total lines: 7
-------------------------------------------
__int64 __fastcall CSessionCacheManager::RunBalancer(CSessionCacheManager *this, int a2)
{
  if ( *((int *)this + 8) > 0 )
    CSessionCacheManager::CacheExpireElements(this, 1, a2 == CSslGlobals::m_dwCleanupIntervalInSeconds);
  return 0i64;
}
