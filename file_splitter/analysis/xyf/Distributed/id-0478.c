//----- (0000000180023050) ----------------------------------------------------
void __fastcall CSessionCacheServerItem::CompleteCacheAdd(
        CSessionCacheServerItem *this,
        struct CSessionCacheManager *a2,
        struct CSslContext *a3)
{
  __int64 v3; // rax
  __int64 v4; // rdx
  __int64 v5; // rax

  v3 = *((_QWORD *)a3 + 10);
  if ( v3 && (*(_BYTE *)(v3 + 156) & 0x20) != 0 )
    *((_WORD *)this + 118) = 256;
  v4 = *((_QWORD *)a3 + 1);
  *((_QWORD *)this + 22) = v4;
  *((_DWORD *)this + 46) = *((_DWORD *)a3 + 4);
  v5 = *(_QWORD *)(v4 + 848);
  if ( v5 )
    _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v5 + 16) + 12i64));
  _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v4 + 856) + 12i64));
}

