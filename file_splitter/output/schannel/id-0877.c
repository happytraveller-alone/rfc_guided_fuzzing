//----- (00000001800475D8) ----------------------------------------------------
__int64 __fastcall SpGetKeyingMaterialInfoForSca(
        void *a1,
        unsigned int a2,
        struct _SecPkgContext_KeyingMaterialInfo *a3)
{
  CHAR *v6; // rdi
  BYTE *v7; // rsi
  ULONG v8; // ebx
  int v9; // ebx
  __int64 v10; // rdx
  int v11; // eax
  NTSTATUS v12; // ecx
  WORD v13; // r15
  __int64 v14; // rbx
  WORD v15; // r12
  DWORD v16; // r13d
  int v17; // eax
  __int64 v19; // [rsp+30h] [rbp-50h]
  __int128 v20; // [rsp+38h] [rbp-48h] BYREF
  __int64 v21; // [rsp+48h] [rbp-38h]
  __int128 v22; // [rsp+50h] [rbp-30h] BYREF
  __int128 v23; // [rsp+60h] [rbp-20h]
  __int64 v24; // [rsp+70h] [rbp-10h]
  unsigned int v25; // [rsp+C8h] [rbp+48h]

  v24 = 0i64;
  v21 = 0i64;
  v6 = 0i64;
  v22 = 0i64;
  v7 = 0i64;
  v23 = 0i64;
  v20 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(__int128 *))(LsaTable + 192))(&v20) )
    return 1359;
  v9 = BYTE8(v20) & 0x40;
  v10 = v9 != 0 ? 20 : 40;
  if ( !a1 || a2 < (unsigned int)v10 || !a3 )
    return 87;
  v11 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, void *))(LsaTable + 80))(0i64, v10, &v22, a1);
  if ( v11 < 0 )
  {
LABEL_7:
    v12 = v11;
LABEL_8:
    v8 = RtlNtStatusToDosError(v12);
    goto LABEL_27;
  }
  v13 = v22;
  if ( v9 )
  {
    v14 = DWORD1(v22);
    v15 = WORD4(v22);
    v16 = v23;
    v19 = HIDWORD(v22);
  }
  else
  {
    v14 = *((_QWORD *)&v22 + 1);
    v15 = v23;
    v16 = v24;
    v19 = *((_QWORD *)&v23 + 1);
  }
  if ( (unsigned __int16)(v22 - 1) > 0x103u || !v14 || !v16 )
    return 87;
  v25 = (unsigned __int16)v22;
  v6 = (CHAR *)SPExternalAlloc((unsigned __int16)v22);
  if ( !v6 )
    return 14;
  v11 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, CHAR *, __int64))(LsaTable + 80))(0i64, v25, v6, v14);
  v8 = v11;
  if ( v11 < 0 )
    goto LABEL_7;
  if ( v6[v13 - 1] )
    goto LABEL_19;
  if ( !v15 )
  {
LABEL_26:
    a3->cbLabel = v13;
    a3->pszLabel = v6;
    a3->cbContextValue = v15;
    a3->pbContextValue = v7;
    a3->cbKeyingMaterial = v16;
LABEL_27:
    if ( !v8 )
      return v8;
    if ( !v6 )
      goto LABEL_30;
    goto LABEL_29;
  }
  if ( v19 )
  {
    v7 = (BYTE *)SPExternalAlloc(v15);
    if ( !v7 )
    {
      v8 = 14;
      goto LABEL_29;
    }
    v17 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, BYTE *, __int64))(LsaTable + 80))(0i64, v15, v7, v19);
    v8 = v17;
    if ( v17 < 0 )
    {
      v12 = v17;
      goto LABEL_8;
    }
    goto LABEL_26;
  }
LABEL_19:
  v8 = 87;
LABEL_29:
  SPExternalFree(v6);
LABEL_30:
  if ( v7 )
    SPExternalFree(v7);
  return v8;
}
// 180092620: using guessed type __int64 LsaTable;

