// File count: 53
// Total lines: 32
------------------------------------------
unsigned __int8 __fastcall CSessionCacheManager::FinishCacheAddItem(CSessionCacheManager *this, struct CSslContext *a2)
{
  __int64 *v2; // rsi
  __int64 v5; // rbp
  __int64 v6; // r9
  unsigned int v7; // edx
  unsigned int v8; // eax
  __int64 v9; // rax

  v2 = (__int64 *)*((_QWORD *)a2 + 11);
  if ( !v2 )
    return 0;
  v5 = *((_QWORD *)a2 + 10);
  if ( !v5 )
    return 0;
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(v2[28] + 48), 1u);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(v2 + 9), 1u);
  v7 = *(_DWORD *)(v5 + 208);
  v8 = *((_DWORD *)v2 + 70);
  *((_BYTE *)v2 + 236) = 1;
  if ( v7 >= v8 )
    v7 = v8;
  v9 = *v2;
  *((_DWORD *)v2 + 70) = v7;
  LOBYTE(v6) = 1;
  (*(void (__fastcall **)(__int64 *, CSessionCacheManager *, struct CSslContext *, __int64))(v9 + 64))(v2, this, a2, v6);
  RtlReleaseResource((PRTL_RESOURCE)(v2 + 9));
  RtlReleaseResource((PRTL_RESOURCE)(v2[28] + 48));
  return 1;
}
// 1800042B3: variable 'v6' is possibly undefined
