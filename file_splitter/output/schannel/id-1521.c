// File count: 1521
// Total lines: 113
---------------------------------------
__int64 __fastcall PAC_InitAndUpdateGroupsEx(
        struct _NETLOGON_VALIDATION_SAM_INFO3 *a1,
        struct _SAMPR_PSID_ARRAY *a2,
        void *a3,
        struct _PACTYPE *a4,
        struct _PACTYPE **a5)
{
  struct _PACTYPE **v5; // r12
  int v7; // ebx
  size_t v8; // r14
  unsigned int v9; // ecx
  unsigned int v10; // r8d
  unsigned int v11; // r13d
  unsigned int v12; // ebp
  _DWORD *v13; // rdx
  unsigned int v14; // edx
  size_t v15; // rbx
  unsigned int *v16; // rax
  unsigned int *v17; // rdi
  void *v18; // rdx
  void *v19; // rbx
  unsigned int v20; // ebp
  void *i; // r14
  unsigned int v22; // eax
  __int64 v23; // rbx
  void *Src; // [rsp+30h] [rbp-38h] BYREF
  size_t Size; // [rsp+80h] [rbp+18h] BYREF

  Size = (size_t)a3;
  v5 = a5;
  Src = 0i64;
  *a5 = 0i64;
  v7 = PAC_ReMarshallValidationInfoWithGroups(a1, a2, a3, (unsigned __int8 **)&Src, (unsigned int *)&Size);
  if ( v7 >= 0 )
  {
    v8 = (unsigned int)Size;
    if ( (unsigned int)Size >= 0xFFFF )
      goto LABEL_3;
    v9 = (Size + 7) & 0xFFFFFFF8;
    v10 = 0;
    v11 = 1;
    v12 = 1;
    if ( *(_DWORD *)a4 )
    {
      v13 = (_DWORD *)((char *)a4 + 12);
      do
      {
        if ( *(v13 - 1) != 1 )
        {
          if ( *v13 >= 0xFFFFu )
            goto LABEL_3;
          if ( v9 + ((*v13 + 7) & 0xFFFFFFF8) < v9 )
          {
            v7 = -1073741675;
            goto LABEL_20;
          }
          v9 += (*v13 + 7) & 0xFFFFFFF8;
          ++v12;
        }
        ++v10;
        v13 += 4;
      }
      while ( v10 < *(_DWORD *)a4 );
    }
    v14 = v9 + 16 * v12 + 8;
    if ( v14 >= 0xFFFF )
    {
LABEL_3:
      v7 = -1073741637;
      goto LABEL_20;
    }
    v15 = (v14 + 7) & 0xFFFFFFF8;
    v16 = (unsigned int *)MIDL_user_allocate(v15);
    v17 = v16;
    if ( v16 )
    {
      memset_0(v16, 0, v15);
      v18 = Src;
      *v17 = v12;
      v17[2] = 1;
      v17[3] = v8;
      v19 = (void *)(((unsigned __int64)&v17[4 * v12 + 3] + 3) & 0xFFFFFFFFFFFFFFF8ui64);
      *((_QWORD *)v17 + 2) = v19;
      memcpy_0(v19, v18, v8);
      v20 = 0;
      for ( i = (void *)(((unsigned __int64)v19 + v17[3] + 7) & 0xFFFFFFFFFFFFFFF8ui64); v20 < *(_DWORD *)a4; ++v20 )
      {
        v22 = *((_DWORD *)a4 + 4 * v20 + 2);
        if ( v22 != 1 )
        {
          v23 = 2i64 * v11;
          v17[2 * v23 + 2] = v22;
          v17[2 * v23 + 3] = *((_DWORD *)a4 + 4 * v20 + 3);
          *(_QWORD *)&v17[2 * v23 + 4] = i;
          memcpy_0(i, *((const void **)a4 + 2 * v20 + 2), *((unsigned int *)a4 + 4 * v20 + 3));
          i = (void *)(((unsigned __int64)i + v17[4 * v11++ + 3] + 7) & 0xFFFFFFFFFFFFFFF8ui64);
        }
      }
      *v5 = (struct _PACTYPE *)v17;
      v7 = 0;
    }
    else
    {
      v7 = -1073741670;
    }
  }
LABEL_20:
  if ( Src )
    (*(void (__fastcall **)(void *))(LsaTable + 48))(Src);
  return (unsigned int)v7;
}
// 180092620: using guessed type __int64 LsaTable;
