// File count: 71
// Total lines: 20
------------------------------------------
__int64 __fastcall CSessionCacheManager::CacheRetrieveNewClientItem(
        CSessionCacheManager *this,
        const unsigned __int16 *a2,
        struct CSessionCacheClientItem **a3)
{
  __int64 result; // rax
  bool v5; // zf
  struct CSessionCacheItem *v6; // [rsp+58h] [rbp+20h] BYREF

  result = CSessionCacheManager::CacheRetrieveNewItem(this, 0, a2, 0i64, &v6);
  if ( !(_DWORD)result )
  {
    v5 = v6 == 0i64;
    *a3 = v6;
    if ( v5 )
      return 87i64;
  }
  return result;
}
