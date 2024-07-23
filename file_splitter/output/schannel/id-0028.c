// File count: 28
// Total lines: 40
------------------------------------------
char __fastcall CSessionCacheManager::CacheExpireElements(CSessionCacheManager *this, char a2, char a3)
{
  int v6; // eax
  char v7; // di
  unsigned int v8; // esi
  int v9; // edx
  char v10; // r9

  v6 = _InterlockedIncrement((volatile signed __int32 *)this + 25);
  v7 = 0;
  if ( !a2 || v6 <= 1 )
  {
    RtlEnterCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 56));
    v8 = 0;
    if ( *((_DWORD *)this + 12) )
    {
      v9 = *((_DWORD *)this + 7);
      do
      {
        if ( !a2 || (v10 = 1, a3) )
          v10 = 0;
        CSessionCacheTable::ExpireAndPurgeItems(
          (CSessionCacheTable *)(*((_QWORD *)this + 5) + 152i64 * v8),
          (int *)this + 8,
          v9,
          v10);
        v9 = *((_DWORD *)this + 7);
        if ( *((_DWORD *)this + 8) < v9 && a2 && !a3 )
          break;
        ++v8;
      }
      while ( v8 < *((_DWORD *)this + 12) );
    }
    RtlLeaveCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 56));
    v7 = 1;
  }
  _InterlockedDecrement((volatile signed __int32 *)this + 25);
  return v7;
}
