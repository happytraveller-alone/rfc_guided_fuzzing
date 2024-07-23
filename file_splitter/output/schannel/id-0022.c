// File count: 22
// Total lines: 17
------------------------------------------
void __fastcall CSessionCacheManager::PurgeCacheForProcessId(CSessionCacheManager *this, int a2)
{
  unsigned int v2; // edi

  v2 = 0;
  if ( *((_DWORD *)this + 8) )
  {
    if ( *((_DWORD *)this + 12) )
    {
      do
        CSessionCacheTable::ExpireItemsBoundToProcess((CSessionCacheTable *)(*((_QWORD *)this + 5) + 152i64 * v2++), a2);
      while ( v2 < *((_DWORD *)this + 12) );
    }
    CSessionCacheManager::CacheExpireElements(this, 0, 0);
  }
}
