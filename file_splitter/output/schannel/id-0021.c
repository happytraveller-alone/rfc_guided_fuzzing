// File count: 21
// Total lines: 23
------------------------------------------
__int64 __fastcall CSessionCacheClientItem::CloneCacheElement(
        CSessionCacheClientItem *this,
        struct CSessionCacheManager *a2,
        struct CSessionCacheClientItem **a3)
{
  __int64 result; // rax
  struct CSessionCacheClientItem *v6; // rcx
  struct CSessionCacheClientItem *v7; // [rsp+30h] [rbp+8h] BYREF

  v7 = 0i64;
  result = CSessionCacheManager::CacheRetrieveNewClientItem(a2, *((const unsigned __int16 **)this + 46), &v7);
  if ( !(_DWORD)result )
  {
    v6 = v7;
    *((_DWORD *)v7 + 42) = *((_DWORD *)this + 42);
    *(_QWORD *)((char *)v6 + 188) = *(_QWORD *)((char *)this + 188);
    result = 0i64;
    *((_QWORD *)v6 + 48) = this;
    *a3 = v6;
  }
  return result;
}
