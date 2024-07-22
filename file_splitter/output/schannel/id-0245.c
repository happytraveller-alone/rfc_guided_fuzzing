//----- (0000000180014550) ----------------------------------------------------
__int64 __fastcall CSessionCacheTable::DereferenceCacheItemInternal(
        CSessionCacheTable *this,
        struct CSessionCacheItem *a2,
        char a3,
        char a4)
{
  unsigned __int32 v8; // ebx
  CSessionCacheTable **v9; // rdx
  CSessionCacheTable *v10; // rax

  if ( a3 && !a4 )
    RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
  v8 = _InterlockedDecrement((volatile signed __int32 *)a2 + 58);
  if ( v8 == 1 )
  {
    LsaIModifyPerformanceCounter(5i64);
    if ( !a3 )
      return v8;
    v9 = (CSessionCacheTable **)*((_QWORD *)this + 5);
    v10 = (struct CSessionCacheItem *)((char *)a2 + 320);
    if ( *v9 != (CSessionCacheTable *)((char *)this + 32) )
      __fastfail(3u);
    *(_QWORD *)v10 = (char *)this + 32;
    *((_QWORD *)a2 + 41) = v9;
    *v9 = v10;
    *((_QWORD *)this + 5) = v10;
  }
  else if ( !a3 )
  {
    return v8;
  }
  if ( !a4 )
    RtlReleaseResource((PRTL_RESOURCE)((char *)this + 48));
  return v8;
}
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);

