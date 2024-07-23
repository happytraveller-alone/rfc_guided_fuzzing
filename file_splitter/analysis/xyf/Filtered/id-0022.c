//----- (00000001800028C8) ----------------------------------------------------
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

// 清理与特定进程 ID 相关的所有缓存项。它首先在所有缓存表中标记或删除与该进程相关的项，然后执行一次全面的过期元素清理。
// 这种操作通常用于在进程结束或需要刷新缓存时确保不会留下过时或无用的缓存数据。

