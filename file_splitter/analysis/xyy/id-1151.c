//----- (000000018005CD60) ----------------------------------------------------
void __fastcall CSessionCacheItem::CompleteCacheAdd(
        CSessionCacheItem *this,
        struct CSessionCacheManager *a2,
        struct CSslContext *a3)
{
  __int64 v3; // rdx
  __int64 v4; // rax

  v3 = *((_QWORD *)a3 + 1);
  *((_QWORD *)this + 22) = v3;
  *((_DWORD *)this + 46) = *((_DWORD *)a3 + 4);
  v4 = *(_QWORD *)(v3 + 848);
  if ( v4 )
    _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v4 + 16) + 12i64));
  _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v3 + 856) + 12i64));
}
