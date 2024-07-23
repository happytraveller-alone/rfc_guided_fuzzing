// File count: 1061
// Total lines: 16
----------------------------------------
__int64 __fastcall CSessionCacheManager::CacheGetInfo(
        CSessionCacheManager *this,
        char a2,
        struct _SSL_SESSION_CACHE_INFO_RESPONSE *a3)
{
  unsigned int v3; // ebx

  *(_OWORD *)a3 = 0i64;
  *((_QWORD *)a3 + 2) = 0i64;
  v3 = 0;
  *((_DWORD *)a3 + 6) = 0;
  for ( *(_DWORD *)a3 = *((_DWORD *)this + 7); v3 < *((_DWORD *)this + 12); ++v3 )
    CSessionCacheTable::CacheGetInfo((CSessionCacheTable *)(*((_QWORD *)this + 5) + 152i64 * v3), a2, a3);
  return 0i64;
}
