//----- (0000000180002D50) ----------------------------------------------------
unsigned __int8 __fastcall CSessionCacheTable::ExpireAndPurgeItems(CSessionCacheTable *this, int *a2, int a3, char a4)
{
  struct _RTL_RESOURCE *v8; // r12
  DWORD TickCount; // edi
  char *v10; // r14
  int *v11; // rbx
  __int64 *v12; // rbx
  int *v14; // rax
  int *v15; // r9
  unsigned int v16; // r8d
  unsigned int v17; // edx
  char v18; // cl
  __int64 v19; // rdx
  int *v20; // rcx
  int **v21; // r8
  __int64 **v22; // rsi
  __int64 v23; // rcx
  __int64 ***v24; // rax
  __int64 v25; // rcx
  int **v26; // rax
  __int64 **v27; // rax
  __int64 v28; // rax
  __int64 *v29; // rcx
  __int64 *v30; // r8
  __int64 *v31; // rdx
  __int64 *v32; // [rsp+20h] [rbp-38h] BYREF
  __int64 **v33; // [rsp+28h] [rbp-30h]

  v8 = (struct _RTL_RESOURCE *)((char *)this + 48);
  TickCount = GetTickCount();
  v33 = &v32;
  v32 = (__int64 *)&v32;
  RtlAcquireResourceExclusive(v8, 1u);
  v10 = (char *)this + 32;
  v11 = (int *)*((_QWORD *)this + 4);
  while ( v11 != (int *)v10 )
  {
    v14 = v11;
    v15 = v11;
    v11 = *(int **)v11;
    if ( *(v14 - 22) > 1 )
      continue;
    v16 = *(v14 - 10);
    v17 = TickCount - *(v14 - 11);
    if ( TickCount <= *(v14 - 11) )
    {
      if ( TickCount < *(v14 - 11) && v17 - 1 >= v16 )
      {
LABEL_34:
        *((_WORD *)v14 - 42) = 0;
        v18 = 0;
        goto LABEL_8;
      }
    }
    else if ( v17 > v16 )
    {
      goto LABEL_34;
    }
    v18 = *((_BYTE *)v14 - 84);
LABEL_8:
    if ( *a2 > a3 )
    {
      *((_WORD *)v14 - 42) = 0;
    }
    else if ( v18 == 1 )
    {
      continue;
    }
    if ( *((_BYTE *)v14 - 83) != 1 )
    {
      v19 = *((_QWORD *)v14 - 4);
      v20 = v14 - 8;
      if ( *(int **)(v19 + 8) != v14 - 8 )
        goto LABEL_32;
      v21 = (int **)*((_QWORD *)v20 + 1);
      if ( *v21 != v20 )
        goto LABEL_32;
      *v21 = (int *)v19;
      v22 = (__int64 **)(v14 - 4);
      *(_QWORD *)(v19 + 8) = v21;
      v23 = *((_QWORD *)v14 - 2);
      if ( *(int **)(v23 + 8) != v14 - 4 )
        goto LABEL_32;
      v24 = (__int64 ***)v22[1];
      if ( *v24 != v22 )
        goto LABEL_32;
      *v24 = (__int64 **)v23;
      *(_QWORD *)(v23 + 8) = v24;
      v25 = *(_QWORD *)v15;
      if ( *(int **)(*(_QWORD *)v15 + 8i64) != v15 )
        goto LABEL_32;
      v26 = (int **)*((_QWORD *)v15 + 1);
      if ( *v26 != v15 )
        goto LABEL_32;
      *v26 = (int *)v25;
      *(_QWORD *)(v25 + 8) = v26;
      _InterlockedDecrement(a2);
      LsaIModifyPerformanceCounter(4i64);
      v27 = v33;
      if ( *v33 != (__int64 *)&v32 )
        goto LABEL_32;
      v22[1] = (__int64 *)v33;
      *v22 = (__int64 *)&v32;
      *v27 = (__int64 *)v22;
      v33 = v22;
      if ( *a2 < a3 && a4 )
        break;
    }
  }
  RtlReleaseResource(v8);
  v12 = v32;
  if ( v32 != (__int64 *)&v32 )
  {
    while ( 1 )
    {
      v28 = *v12;
      v29 = v12 - 38;
      v30 = v12;
      v12 = (__int64 *)v28;
      if ( *(__int64 **)(v28 + 8) != v30 )
        break;
      v31 = (__int64 *)v30[1];
      if ( (__int64 *)*v31 != v30 )
        break;
      *v31 = v28;
      *(_QWORD *)(v28 + 8) = v31;
      if ( v29 )
        (*(void (__fastcall **)(__int64 *, __int64))(*v29 + 8))(v29, 1i64);
      if ( v12 == (__int64 *)&v32 )
        return 1;
    }
LABEL_32:
    __fastfail(3u);
  }
  return 1;
}
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);

