//----- (000000018007AAD8) ----------------------------------------------------
__int64 __fastcall PAC_ReMarshallValidationInfoWithGroups(
        struct _NETLOGON_VALIDATION_SAM_INFO3 *a1,
        struct _SAMPR_PSID_ARRAY *a2,
        void *a3,
        unsigned __int8 **a4,
        unsigned int *a5)
{
  char *v5; // r8
  struct _NETLOGON_VALIDATION_SAM_INFO3 *v7; // rax
  __int64 v8; // rcx
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  int v18; // edx
  unsigned int v19; // ebx
  __int128 v20; // xmm1
  __int128 v21; // xmm0
  __int64 v22; // rax
  unsigned int v23; // edx
  size_t v24; // rsi
  void *v25; // rax
  __int64 v26; // rdi
  unsigned int v27; // ebx
  int v28; // eax
  unsigned int v29; // r10d
  unsigned int v30; // ecx
  __int64 v31; // r8
  __int64 v32; // rax
  __int64 v33; // r9
  __int64 v34; // rcx
  char v36[168]; // [rsp+20h] [rbp-E0h] BYREF
  int v37; // [rsp+C8h] [rbp-38h]
  unsigned int v38; // [rsp+130h] [rbp+30h]
  __int64 v39; // [rsp+138h] [rbp+38h]
  __int64 v40; // [rsp+140h] [rbp+40h]
  int v41; // [rsp+148h] [rbp+48h]
  __int64 v42; // [rsp+150h] [rbp+50h]

  v5 = v36;
  v7 = a1;
  v8 = 2i64;
  do
  {
    v11 = *((_OWORD *)v7 + 1);
    *(_OWORD *)v5 = *(_OWORD *)v7;
    v12 = *((_OWORD *)v7 + 2);
    *((_OWORD *)v5 + 1) = v11;
    v13 = *((_OWORD *)v7 + 3);
    *((_OWORD *)v5 + 2) = v12;
    v14 = *((_OWORD *)v7 + 4);
    *((_OWORD *)v5 + 3) = v13;
    v15 = *((_OWORD *)v7 + 5);
    *((_OWORD *)v5 + 4) = v14;
    v16 = *((_OWORD *)v7 + 6);
    *((_OWORD *)v5 + 5) = v15;
    v17 = *((_OWORD *)v7 + 7);
    v7 = (struct _NETLOGON_VALIDATION_SAM_INFO3 *)((char *)v7 + 128);
    *((_OWORD *)v5 + 6) = v16;
    v5 += 128;
    *((_OWORD *)v5 - 1) = v17;
    --v8;
  }
  while ( v8 );
  v18 = *(_DWORD *)a2;
  v19 = 0;
  v20 = *((_OWORD *)v7 + 1);
  *(_OWORD *)v5 = *(_OWORD *)v7;
  v21 = *((_OWORD *)v7 + 2);
  v22 = *((_QWORD *)v7 + 6);
  *((_OWORD *)v5 + 1) = v20;
  *((_OWORD *)v5 + 2) = v21;
  *((_QWORD *)v5 + 6) = v22;
  v37 &= ~0x200u;
  v23 = v38 + v18;
  v40 = 0i64;
  v42 = 0i64;
  v41 = 0;
  if ( v23 < v38 )
  {
    return (unsigned int)-1073741675;
  }
  else
  {
    v24 = 16i64 * v23;
    v25 = MIDL_user_allocate(v24);
    v26 = (__int64)v25;
    if ( v25 )
    {
      memset_0(v25, 0, v24);
      v28 = *(_DWORD *)a2;
      if ( *(_DWORD *)a2 )
      {
        v37 |= 0x20u;
        v29 = 0;
        v30 = 0;
        if ( *((_DWORD *)a1 + 68) )
        {
          do
          {
            v31 = *((_QWORD *)a1 + 35);
            if ( (*(_DWORD *)(v31 + 16i64 * v30 + 8) & 0x20000000) == 0 )
            {
              v32 = 2i64 * v29++;
              *(_OWORD *)(v26 + 8 * v32) = *(_OWORD *)(v31 + 16i64 * v30);
            }
            ++v30;
          }
          while ( v30 < *((_DWORD *)a1 + 68) );
          v28 = *(_DWORD *)a2;
        }
        if ( v28 )
        {
          do
          {
            v33 = v29++;
            v33 *= 2i64;
            v34 = v19++;
            *(_QWORD *)(v26 + 8 * v33) = *(_QWORD *)(*((_QWORD *)a2 + 1) + 8 * v34);
            *(_DWORD *)(v26 + 8 * v33 + 8) = 536870919;
          }
          while ( v19 < *(_DWORD *)a2 );
        }
        v39 = v26;
        v38 = v29;
      }
      v27 = PAC_EncodeValidationInformation((struct _NETLOGON_VALIDATION_SAM_INFO3 *)v36, a4, a5);
      (*(void (__fastcall **)(__int64))(LsaTable + 48))(v26);
    }
    else
    {
      return (unsigned int)-1073741801;
    }
  }
  return v27;
}
// 180092620: using guessed type __int64 LsaTable;
