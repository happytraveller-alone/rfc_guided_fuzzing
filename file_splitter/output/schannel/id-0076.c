//----- (000000018000629C) ----------------------------------------------------
__int64 __fastcall CSessionCacheManager::AcquireCacheTableLock(
        __int64 a1,
        const unsigned __int16 *a2,
        unsigned __int8 *const a3)
{
  CSessionCacheManager *v3; // rbx
  unsigned int v4; // eax
  __int64 v5; // rcx

  v3 = CSessionCacheManager::m_pSessionCacheManager;
  v4 = 0;
  if ( !CSessionCacheManager::m_pSessionCacheManager )
    return 0i64;
  if ( a2 )
  {
    v4 = CSessionCacheManager::ComputeClientCacheIndex(CSessionCacheManager::m_pSessionCacheManager, a2);
  }
  else if ( a3 )
  {
    v4 = *(_DWORD *)a3 % *((_DWORD *)CSessionCacheManager::m_pSessionCacheManager + 4);
  }
  v5 = *((_QWORD *)v3 + 5) + 152i64 * (v4 / *((_DWORD *)v3 + 13));
  if ( !v5 )
    return 0i64;
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(v5 + 48), 1u);
  return 1i64;
}

