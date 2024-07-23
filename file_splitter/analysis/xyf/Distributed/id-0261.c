//----- (0000000180014DB8) ----------------------------------------------------
DWORD __fastcall GetPublicKeyFromCert(const struct _CERT_CONTEXT *a1, struct _PUBLICKEY **a2, unsigned int *a3)
{
  PCERT_INFO pCertInfo; // rbx
  struct _CERT_PUBLIC_KEY_INFO *p_SubjectPublicKeyInfo; // rsi
  int v7; // eax
  unsigned int v8; // edi
  DWORD result; // eax
  int v10; // eax
  int v11; // eax
  char *v12; // rax
  unsigned int *v13; // rbx
  DWORD v14; // eax
  DWORD v15; // esi
  unsigned int *v16; // rax
  PCCRYPT_OID_INFO v17; // rdx
  int v18; // edi
  char *v19; // rax
  __int64 v20; // [rsp+20h] [rbp-10h] BYREF
  unsigned int v21; // [rsp+60h] [rbp+30h] BYREF
  int v22; // [rsp+78h] [rbp+48h] BYREF

  pCertInfo = a1->pCertInfo;
  v20 = 0i64;
  p_SubjectPublicKeyInfo = &pCertInfo->SubjectPublicKeyInfo;
  if ( pCertInfo == (PCERT_INFO)-96i64 )
    return -2146893052;
  v7 = MapOidToKeyExch(p_SubjectPublicKeyInfo->Algorithm.pszObjId);
  v22 = v7;
  v8 = v7;
  if ( !v7 )
    return -2146893043;
  v10 = v7 - 8704;
  if ( v10 )
  {
    v11 = v10 - 3;
    if ( !v11 )
    {
      result = GetAlgIdFromEccTypeCertParameters(
                 pCertInfo->SubjectPublicKeyInfo.Algorithm.Parameters.pbData,
                 pCertInfo->SubjectPublicKeyInfo.Algorithm.Parameters.cbData,
                 (PCCRYPT_OID_INFO *)&v20,
                 &v22);
      if ( result )
        return result;
      result = EcdsaPublicKeyFromCert((__int64)&pCertInfo->SubjectPublicKeyInfo, v20, 0i64, &v21);
      if ( result )
        return result;
      if ( v21 < 0xFFFFFFF0 )
      {
        v16 = (unsigned int *)SPExternalAlloc(v21 + 16);
        v13 = v16;
        if ( v16 )
        {
          v17 = (PCCRYPT_OID_INFO)v20;
          *(_QWORD *)v16 = v16 + 4;
          v16[2] = v21;
          v18 = EcdsaPublicKeyFromCert((__int64)p_SubjectPublicKeyInfo, (__int64)v17, v16 + 4, v16 + 2);
          if ( v18 )
          {
            SPExternalFree(v13);
            return v18;
          }
          v8 = v22;
          goto LABEL_20;
        }
        return -2146893056;
      }
      return 534;
    }
    if ( v11 == 33277 )
    {
      result = RsaPublicKeyFromCert(&pCertInfo->SubjectPublicKeyInfo, 0i64, &v21);
      if ( result )
        return result;
      if ( v21 < 0xFFFFFFF0 )
      {
        v12 = (char *)SPExternalAlloc(v21 + 16);
        v13 = (unsigned int *)v12;
        if ( v12 )
        {
          *(_QWORD *)v12 = v12 + 16;
          *((_DWORD *)v12 + 2) = v21;
          v14 = RsaPublicKeyFromCert(p_SubjectPublicKeyInfo, (struct _PUBLICKEYSTRUC *)v12 + 2, (unsigned int *)v12 + 2);
          goto LABEL_11;
        }
        return -2146893056;
      }
      return 534;
    }
    return -2146893052;
  }
  result = DssPublicKeyFromCert(&pCertInfo->SubjectPublicKeyInfo, 0i64, &v21);
  if ( result )
    return result;
  if ( v21 + 16 < v21 )
    return -2146893056;
  v19 = (char *)SPExternalAlloc(v21 + 16);
  v13 = (unsigned int *)v19;
  if ( !v19 )
    return -2146893056;
  *(_QWORD *)v19 = v19 + 16;
  *((_DWORD *)v19 + 2) = v21;
  v14 = DssPublicKeyFromCert(p_SubjectPublicKeyInfo, (struct _PUBLICKEYSTRUC *)v19 + 2, (unsigned int *)v19 + 2);
LABEL_11:
  v15 = v14;
  if ( v14 )
  {
    SPExternalFree(v13);
    return v15;
  }
LABEL_20:
  *a2 = (struct _PUBLICKEY *)v13;
  if ( a3 )
    *a3 = v8;
  return 0;
}

