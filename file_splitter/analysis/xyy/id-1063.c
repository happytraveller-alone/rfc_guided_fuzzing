//----- (00000001800592E8) ----------------------------------------------------
__int64 __fastcall CSessionCacheManager::CacheRetrieveNewServerItem(
        CSessionCacheManager *this,
        int a2,
        unsigned __int8 *const a3,
        struct CSessionCacheServerItem **a4)
{
  __int64 result; // rax
  struct CSessionCacheItem *v7; // rcx
  struct CSessionCacheItem *v8; // [rsp+30h] [rbp-18h] BYREF

  result = CSessionCacheManager::CacheRetrieveNewItem(this, 1, 0i64, a3, &v8);
  if ( !(_DWORD)result )
  {
    v7 = v8;
    *a4 = v8;
    if ( v7 )
      *((_DWORD *)v7 + 42) = a2;
    else
      return 87i64;
  }
  return result;
}

