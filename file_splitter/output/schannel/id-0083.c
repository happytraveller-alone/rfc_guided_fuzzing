// File count: 83
// Total lines: 123
-----------------------------------------
__int64 __fastcall CSessionCacheManager::CacheRetrieveNewItem(
        CSessionCacheManager *this,
        char a2,
        const unsigned __int16 *a3,
        unsigned __int8 *const a4,
        struct CSessionCacheItem **a5)
{
  __int64 v7; // rbx
  unsigned int v8; // ebx
  wchar_t *v9; // rax
  unsigned __int16 *v10; // rdi
  unsigned int v11; // r14d
  CSessionCacheClientItem *v12; // rax
  CSessionCacheClientItem *v13; // rdi
  unsigned int v14; // ebx
  unsigned int v15; // ebx
  CSessionCacheTable *v16; // rcx
  _QWORD *v17; // rbp
  __int64 *v18; // r8
  __int64 v19; // rcx
  __int64 **v20; // rax
  _QWORD *v21; // rdi
  _QWORD *v22; // rcx
  __int128 v24; // xmm0
  unsigned int v25; // eax
  int v26; // edx
  unsigned int v27; // ecx
  CSessionCacheItem *v28; // rax
  unsigned __int8 v29[16]; // [rsp+20h] [rbp-38h] BYREF
  __int128 v30; // [rsp+30h] [rbp-28h]

  if ( !a2 )
  {
    v7 = -1i64;
    do
      ++v7;
    while ( a3[v7] );
    v8 = v7 + 1;
    v9 = (wchar_t *)SPExternalAlloc(2 * v8);
    v10 = v9;
    if ( !v9 )
      return 14i64;
    wcscpy_s(v9, v8, a3);
    v11 = CSessionCacheManager::ComputeClientCacheIndex(this, v10);
    v12 = (CSessionCacheClientItem *)SPExternalAlloc(0x1B8u);
    if ( !v12 )
      return 14i64;
    v13 = CSessionCacheClientItem::CSessionCacheClientItem(v12, this, *((_DWORD *)this + 5), v10);
LABEL_7:
    if ( v13 )
      goto LABEL_8;
    return 14i64;
  }
  v24 = *((_OWORD *)a4 + 1);
  v25 = _mm_cvtsi128_si32(*(__m128i *)a4);
  *(_OWORD *)v29 = *(_OWORD *)a4;
  v26 = v25 % *((_DWORD *)this + 4);
  v27 = *(_DWORD *)&v29[4];
  v11 = v26;
  *(_DWORD *)v29 = v26;
  if ( g_SslMachineID != -1 )
    v27 = g_SslMachineID;
  *(_DWORD *)&v29[4] = v27;
  v30 = v24;
  v28 = (CSessionCacheItem *)(*(__int64 (__fastcall **)(struct IAllocate *, __int64))(*(_QWORD *)CSessionCacheServerItem::m_pServerCacheLookaside
                                                                                    + 24i64))(
                               CSessionCacheServerItem::m_pServerCacheLookaside,
                               360i64);
  v13 = v28;
  if ( !v28 )
  {
    v13 = 0i64;
    goto LABEL_7;
  }
  CSessionCacheItem::CSessionCacheItem(v28, *((_DWORD *)this + 6), v29);
  *((_QWORD *)v13 + 42) = 0i64;
  *(_QWORD *)v13 = &CSessionCacheServerItem::`vftable';
  *((_QWORD *)v13 + 43) = 0i64;
  *((_DWORD *)v13 + 88) = 0;
  *((_DWORD *)v13 + 54) = -2146893019;
LABEL_8:
  v14 = *((_DWORD *)v13 + 17);
  if ( v14 )
  {
    (*(void (__fastcall **)(CSessionCacheClientItem *, __int64))(*(_QWORD *)v13 + 8i64))(v13, 1i64);
    return v14;
  }
  else
  {
    v15 = *((_DWORD *)this + 13);
    *a5 = v13;
    v16 = (CSessionCacheTable *)(v11 / v15);
    v17 = (_QWORD *)(*((_QWORD *)this + 5) + 152i64 * (_QWORD)v16);
    CSessionCacheTable::ReferenceCacheItemInternal(v16, v13);
    *((_QWORD *)v13 + 28) = v17;
    v18 = (__int64 *)((char *)v13 + 288);
    v19 = *v17 + 16i64 * (v11 % v15);
    v20 = *(__int64 ***)(v19 + 8);
    if ( *v20 != (__int64 *)v19
      || (*((_QWORD *)v13 + 37) = v20,
          v21 = (_QWORD *)((char *)v13 + 304),
          *v18 = v19,
          *v20 = v18,
          *(_QWORD *)(v19 + 8) = v18,
          v22 = (_QWORD *)v17[3],
          (_QWORD *)*v22 != v17 + 2) )
    {
      __fastfail(3u);
    }
    *v21 = v17 + 2;
    v21[1] = v22;
    *v22 = v21;
    v17[3] = v21;
    _InterlockedIncrement((volatile signed __int32 *)this + 8);
    LsaIModifyPerformanceCounter(4i64);
    return 0i64;
  }
}
// 18007C330: using guessed type void *CSessionCacheServerItem::`vftable';
// 1800919F4: using guessed type unsigned int g_SslMachineID;
// 1800927F8: using guessed type struct IAllocate *CSessionCacheServerItem::m_pServerCacheLookaside;
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
