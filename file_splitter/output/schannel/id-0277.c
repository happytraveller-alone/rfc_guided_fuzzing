// File count: 277
// Total lines: 31
-----------------------------------------
void __fastcall CSessionCacheClientItem::CompleteCacheAdd(
        CSessionCacheClientItem *this,
        struct CSessionCacheManager *a2,
        struct CSslContext *a3,
        char a4)
{
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rax

  v6 = *((_QWORD *)this + 48);
  *(_QWORD *)((char *)this + 188) = *(_QWORD *)(*((_QWORD *)a3 + 10) + 760i64);
  if ( v6 )
  {
    *(_BYTE *)(v6 + 236) = 0;
    CSessionCacheTable::DereferenceCacheItemInternal(
      *(CSessionCacheTable **)(*((_QWORD *)this + 48) + 224i64),
      *((struct CSessionCacheItem **)this + 48),
      1,
      a4);
    *((_QWORD *)this + 48) = 0i64;
  }
  v7 = *((_QWORD *)a3 + 1);
  *((_QWORD *)this + 22) = v7;
  *((_DWORD *)this + 46) = *((_DWORD *)a3 + 4);
  v8 = *(_QWORD *)(v7 + 848);
  if ( v8 )
    _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v8 + 16) + 12i64));
  _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v7 + 856) + 12i64));
}
