//----- (0000000180053B60) ----------------------------------------------------
DWORD __fastcall DssPublicKeyFromCert(struct _CERT_PUBLIC_KEY_INFO *a1, struct _PUBLICKEYSTRUC *a2, unsigned int *a3)
{
  DWORD cbData; // r9d
  DWORD LastError; // esi
  BYTE *pbData; // r8
  DWORD v10; // edi
  const void **pvStructInfo; // r15
  unsigned int *v12; // r14
  unsigned int v13; // edx
  unsigned int v14; // r8d
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  char *v18; // rdi
  char *v19; // rdi
  __int64 v20; // rcx
  char *v21; // rdi
  size_t v22; // rbx
  __int64 v23; // rcx
  char *v24; // rdi
  size_t v25; // rbx
  DWORD pcbStructInfo; // [rsp+70h] [rbp+8h] BYREF
  DWORD v27; // [rsp+88h] [rbp+20h] BYREF

  cbData = a1->PublicKey.cbData;
  LastError = 0;
  pbData = a1->PublicKey.pbData;
  pcbStructInfo = 0;
  if ( !CryptDecodeObject(1u, (LPCSTR)0x26, pbData, cbData, 0, 0i64, &pcbStructInfo)
    || !CryptDecodeObject(
          1u,
          (LPCSTR)0x27,
          a1->Algorithm.Parameters.pbData,
          a1->Algorithm.Parameters.cbData,
          0,
          0i64,
          &v27) )
  {
    return GetLastError();
  }
  v10 = pcbStructInfo + v27 + 40;
  if ( !a2 )
    goto LABEL_7;
  if ( *a3 < v10 )
  {
    LastError = -2146893023;
LABEL_7:
    *a3 = v10;
    return LastError;
  }
  pvStructInfo = (const void **)SPExternalAlloc(pcbStructInfo + v27);
  if ( !pvStructInfo )
    return -2146893056;
  v12 = (unsigned int *)((char *)pvStructInfo + pcbStructInfo);
  if ( CryptDecodeObject(1u, (LPCSTR)0x26, a1->PublicKey.pbData, a1->PublicKey.cbData, 0, pvStructInfo, &pcbStructInfo)
    && CryptDecodeObject(
         1u,
         (LPCSTR)0x27,
         a1->Algorithm.Parameters.pbData,
         a1->Algorithm.Parameters.cbData,
         0,
         v12,
         &v27) )
  {
    v13 = *v12;
    if ( *v12 > 0x100000 || (v14 = v12[4], v14 > 0x100000) || v12[8] > 0x100000 || *(_DWORD *)pvStructInfo > 0x100000u )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids);
      LastError = -2146893048;
    }
    else
    {
      v15 = *v12;
      v16 = *v12;
      if ( v13 <= *(_DWORD *)pvStructInfo )
        v15 = *(_DWORD *)pvStructInfo;
      if ( v13 <= v12[8] )
        v16 = v12[8];
      v17 = v14 + v15 + v16 + v13 + 40;
      if ( v10 < v17 )
      {
        *a3 = v17;
        return -2146893023;
      }
      *(_DWORD *)&a2->bType = 518;
      a2->aiKeyAlg = 8704;
      *(_DWORD *)&a2[1].bType = 827544388;
      a2[1].aiKeyAlg = 8 * *v12;
      memcpy_0(&a2[2], *((const void **)v12 + 1), *v12);
      v18 = (char *)&a2[2] + *v12;
      memcpy_0(v18, *((const void **)v12 + 3), v12[4]);
      v19 = &v18[v12[4]];
      memcpy_0(v19, *((const void **)v12 + 5), v12[8]);
      v20 = v12[8];
      v21 = &v19[v20];
      if ( (unsigned int)v20 < *v12 )
      {
        v22 = *v12 - (unsigned int)v20;
        memset_0(v21, 0, v22);
        v21 += v22;
      }
      memcpy_0(v21, pvStructInfo[1], *(unsigned int *)pvStructInfo);
      v23 = *(unsigned int *)pvStructInfo;
      v24 = &v21[v23];
      if ( (unsigned int)v23 < *v12 )
      {
        v25 = *v12 - (unsigned int)v23;
        memset_0(v24, 0, v25);
        v24 += v25;
      }
      *(_DWORD *)v24 = -1;
      *(_OWORD *)(v24 + 4) = 0i64;
      *((_DWORD *)v24 + 5) = 0;
      *a3 = (_DWORD)v24 - (_DWORD)a2 + 24;
    }
  }
  else
  {
    LastError = GetLastError();
  }
  SPExternalFree(pvStructInfo);
  return LastError;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
