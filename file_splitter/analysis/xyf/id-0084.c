//----- (00000001800069C4) ----------------------------------------------------
__int64 __fastcall CSessionCacheTable::ReferenceCacheItemInternal(
        CSessionCacheTable *this,
        struct CSessionCacheItem *a2)
{
  unsigned __int32 v2; // ebx

  v2 = _InterlockedIncrement((volatile signed __int32 *)a2 + 58);
  if ( v2 == 2 )
    LsaIModifyPerformanceCounter(5i64);
  return v2;
}
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);

