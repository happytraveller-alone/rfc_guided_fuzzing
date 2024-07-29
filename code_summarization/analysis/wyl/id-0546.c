//----- (000000018002796C) ----------------------------------------------------
struct CSessionCacheManager *CSessionCacheManager::CreateCacheManager(void)
{
  CSessionCacheManager *v0; // rcx
  CSessionCacheManager *v1; // rax
  unsigned int v2; // eax

  v0 = CSessionCacheManager::m_pSessionCacheManager;
  if ( !CSessionCacheManager::m_pSessionCacheManager )
  {
    v1 = (CSessionCacheManager *)SPExternalAlloc(0x68u);
    v0 = v1;
    if ( v1 )
    {
      *((_QWORD *)v1 + 1) = 0i64;
      *(_QWORD *)v1 = &CSessionCacheManager::`vftable';
      *((_DWORD *)v1 + 4) = 20000;
      *((_DWORD *)v1 + 5) = CSslGlobals::m_dwClientLifespan;
      *((_DWORD *)v1 + 6) = CSslGlobals::m_dwServerLifespan;
      v2 = CSslGlobals::m_dwMaximumEntries;
      *((_QWORD *)v0 + 5) = 0i64;
      *((_DWORD *)v0 + 7) = v2;
      *((_DWORD *)v0 + 13) = 1000;
    }
    else
    {
      v0 = 0i64;
    }
    CSessionCacheManager::m_pSessionCacheManager = v0;
  }
  return v0;
}
// 18007D450: using guessed type void *CSessionCacheManager::`vftable';
