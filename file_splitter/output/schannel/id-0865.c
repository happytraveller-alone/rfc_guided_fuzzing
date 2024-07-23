// File count: 865
// Total lines: 157
----------------------------------------
ULONG __fastcall CSsl3TlsContext::QueryIssuerList(CSsl3TlsContext *this, void *a2)
{
  void *v2; // rsi
  unsigned int v4; // r14d
  int v6; // r15d
  __int64 v7; // rdi
  unsigned int v8; // eax
  unsigned __int8 *v9; // rdi
  unsigned int v10; // r13d
  unsigned __int8 *v11; // rdx
  unsigned __int8 *v12; // r8
  unsigned __int8 *i; // rax
  unsigned int v14; // esi
  HLOCAL v15; // rbx
  int v16; // r12d
  NTSTATUS v17; // ecx
  __int64 v18; // rdx
  __int64 v19; // r9
  int *v20; // r8
  int v21; // ecx
  __int64 v22; // rcx
  int v23; // ecx
  __int64 v24; // rcx
  int v25; // edi
  __int64 v26; // rax
  __int64 *v27; // r9
  __int64 v28; // rdx
  int v29; // ebx
  __int64 v30; // [rsp+30h] [rbp-30h] BYREF
  unsigned int v31; // [rsp+38h] [rbp-28h]
  char v32[32]; // [rsp+40h] [rbp-20h] BYREF
  __int64 v34; // [rsp+B0h] [rbp+50h] BYREF
  int v35; // [rsp+B8h] [rbp+58h] BYREF
  unsigned int v36; // [rsp+BCh] [rbp+5Ch]

  v34 = 0i64;
  v2 = a2;
  v4 = 0;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v32) )
    return 1359;
  v31 = 0;
  v6 = v32[8] & 0x40;
  v30 = 0i64;
  v7 = *((_QWORD *)this + 112);
  if ( v7 )
  {
    v8 = *((_DWORD *)this + 222);
    if ( v8 > 2 )
    {
      v9 = (unsigned __int8 *)(v7 + 2);
      v10 = v8 - 2;
      v11 = v9;
      v12 = &v9[v8 - 2];
      for ( i = v9 + 1; i < v12; i = v11 + 1 )
      {
        v11 += (*i | ((unsigned __int64)*v11 << 8)) + 2;
        ++v4;
      }
      v14 = v4 * (v6 != 0 ? 8 : 16);
      v15 = SPExternalAlloc(v14);
      if ( !v15 )
        return -2146893056;
      v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(0i64, v14 + v10, &v34);
      if ( v16 < 0 )
      {
        SPExternalFree(v15);
LABEL_12:
        v17 = v16;
        return RtlNtStatusToDosError(v17);
      }
      v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, unsigned __int8 *))(LsaTable + 72))(
              0i64,
              v10,
              v34 + v14,
              v9);
      if ( v16 < 0 )
      {
        SPExternalFree(v15);
        (*(void (__fastcall **)(_QWORD, __int64))(LsaTable + 64))(0i64, v34);
        goto LABEL_12;
      }
      v18 = v34 + v14;
      if ( v4 )
      {
        v19 = v4;
        v20 = (int *)v15;
        if ( v6 )
        {
          do
          {
            v21 = v9[1] | (*v9 << 8);
            *v20 = v21;
            v22 = (unsigned int)(v21 + 2);
            v9 += v22;
            v20[1] = v18 + 2;
            v18 += v22;
            v20 += 2;
            --v19;
          }
          while ( v19 );
        }
        else
        {
          do
          {
            v23 = v9[1] | (*v9 << 8);
            *v20 = v23;
            v24 = (unsigned int)(v23 + 2);
            v9 += v24;
            *((_QWORD *)v20 + 1) = v18 + 2;
            v18 += v24;
            v20 += 4;
            --v19;
          }
          while ( v19 );
        }
      }
      v25 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, HLOCAL))(LsaTable + 72))(0i64, v14, v34, v15);
      if ( v25 < 0 )
      {
        SPExternalFree(v15);
        (*(void (__fastcall **)(_QWORD, __int64))(LsaTable + 64))(0i64, v34);
        v17 = v25;
        return RtlNtStatusToDosError(v17);
      }
      SPExternalFree(v15);
      v2 = a2;
    }
  }
  if ( v6 )
  {
    v35 = v34;
    v26 = LsaTable;
    v36 = v4;
    v27 = (__int64 *)&v35;
    v28 = 8i64;
  }
  else
  {
    v30 = v34;
    v26 = LsaTable;
    v31 = v4;
    v27 = &v30;
    v28 = 16i64;
  }
  v29 = (*(__int64 (__fastcall **)(_QWORD, __int64, void *, __int64 *))(v26 + 72))(0i64, v28, v2, v27);
  if ( v29 < 0 )
  {
    if ( v34 )
      (*(void (__fastcall **)(_QWORD))(LsaTable + 64))(0i64);
    v17 = v29;
    return RtlNtStatusToDosError(v17);
  }
  return 0;
}
// 180092620: using guessed type __int64 LsaTable;
