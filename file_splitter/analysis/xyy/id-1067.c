//----- (0000000180059674) ----------------------------------------------------
__int64 __fastcall CSessionCacheTable::PurgeCacheEntries(
        CSessionCacheTable *this,
        unsigned int a2,
        struct _LUID *a3,
        int a4,
        int *a5,
        const unsigned __int16 *a6)
{
  struct _RTL_RESOURCE *v7; // r15
  __int64 **v8; // r14
  __int64 *v9; // rsi
  __int64 *v10; // rbx
  __int64 **v11; // rdi
  struct _RTL_RESOURCE *v12; // rbp
  __int64 v13; // rdx
  __int64 **v14; // rcx
  __int64 *v15; // rcx
  __int64 ***v16; // rax
  _QWORD *v17; // rbx
  __int64 v18; // rcx
  _QWORD *v19; // rax
  __int64 **v20; // rax
  __int64 *v21; // rbx
  __int64 *v22; // rcx
  __int64 *v24; // [rsp+30h] [rbp-48h] BYREF
  __int64 **v25; // [rsp+38h] [rbp-40h]

  v25 = &v24;
  v7 = (struct _RTL_RESOURCE *)((char *)this + 48);
  v8 = (__int64 **)((char *)this + 16);
  v24 = (__int64 *)&v24;
  RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
  v9 = *v8;
  while ( v9 != (__int64 *)v8 )
  {
    v10 = v9 - 38;
    v11 = (__int64 **)v9;
    v9 = (__int64 *)*v9;
    v12 = (struct _RTL_RESOURCE *)(v10 + 9);
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v10 + 9), 1u);
    if ( (a4 == *((_DWORD *)v10 + 68) || (a2 & 0x20000) != 0)
      && (*(unsigned __int8 (__fastcall **)(__int64 *, struct _LUID *, const unsigned __int16 *, _QWORD))(*v10 + 72))(
           v10,
           a3,
           a6,
           a2) )
    {
      if ( *((int *)v10 + 58) <= 1 )
      {
        v13 = v10[36];
        if ( *(__int64 **)(v13 + 8) != v10 + 36 )
          goto LABEL_17;
        v14 = (__int64 **)v10[37];
        if ( *v14 != v10 + 36 )
          goto LABEL_17;
        *v14 = (__int64 *)v13;
        *(_QWORD *)(v13 + 8) = v14;
        v15 = *v11;
        if ( (__int64 **)(*v11)[1] != v11 )
          goto LABEL_17;
        v16 = (__int64 ***)v11[1];
        if ( *v16 != v11 )
          goto LABEL_17;
        *v16 = (__int64 **)v15;
        v17 = v10 + 40;
        v15[1] = (__int64)v16;
        v18 = *v17;
        if ( *(_QWORD **)(*v17 + 8i64) != v17
          || (v19 = (_QWORD *)v17[1], (_QWORD *)*v19 != v17)
          || (*v19 = v18,
              *(_QWORD *)(v18 + 8) = v19,
              _InterlockedDecrement(a5),
              LsaIModifyPerformanceCounter(4i64),
              v20 = v25,
              *v25 != (__int64 *)&v24) )
        {
LABEL_17:
          __fastfail(3u);
        }
        v11[1] = (__int64 *)v25;
        *v11 = (__int64 *)&v24;
        *v20 = (__int64 *)v11;
        v25 = v11;
      }
      else
      {
        *((_WORD *)v10 + 118) = 0;
      }
    }
    RtlReleaseResource(v12);
  }
  RtlReleaseResource(v7);
  v21 = v24;
  while ( v21 != (__int64 *)&v24 )
  {
    v22 = v21 - 38;
    v21 = (__int64 *)*v21;
    if ( v22 )
      (*(void (__fastcall **)(__int64 *, __int64))(*v22 + 8))(v22, 1i64);
  }
  return 0i64;
}
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);

