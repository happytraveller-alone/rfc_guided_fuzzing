//----- (000000018001336C) ----------------------------------------------------
__int64 __fastcall SerializeCertContext(PCCERT_CONTEXT pCertContext, unsigned __int8 *a2, unsigned int *a3)
{
  HCERTSTORE hCertStore; // rcx
  int v7; // esi
  DWORD v8; // ecx
  unsigned int v9; // eax
  HCERTSTORE v11; // rcx
  int pvSaveToPara; // [rsp+30h] [rbp-10h] BYREF
  unsigned __int8 *v13; // [rsp+38h] [rbp-8h]
  DWORD pcbElement; // [rsp+60h] [rbp+20h] BYREF

  pcbElement = 0;
  if ( !pCertContext )
  {
    *a3 = 0;
    return 0i64;
  }
  if ( !CertSerializeCertificateStoreElement(pCertContext, 0, 0i64, &pcbElement) )
    return 2148074253i64;
  hCertStore = pCertContext->hCertStore;
  if ( hCertStore )
  {
    pvSaveToPara = 0;
    v13 = 0i64;
    if ( !CertSaveStore(hCertStore, 1u, 1u, 2u, &pvSaveToPara, 0) )
      return 2148074253i64;
    v7 = pvSaveToPara;
  }
  else
  {
    v7 = 0;
  }
  v8 = pcbElement;
  v9 = v7 + pcbElement + 8;
  if ( !a2 )
  {
    *a3 = v9;
    return 0i64;
  }
  if ( *a3 >= v9 )
  {
    *a3 = v9;
    *(_DWORD *)a2 = v7;
    if ( !pCertContext->hCertStore )
      goto LABEL_13;
    v11 = pCertContext->hCertStore;
    v13 = a2 + 4;
    pvSaveToPara = v7;
    if ( CertSaveStore(v11, 1u, 1u, 2u, &pvSaveToPara, 0) )
    {
      v8 = pcbElement;
LABEL_13:
      *(_DWORD *)&a2[v7 + 4] = v8;
      if ( CertSerializeCertificateStoreElement(pCertContext, 0, &a2[v7 + 8], &pcbElement) )
        return 0i64;
    }
    return 2148074253i64;
  }
  return 2148074273i64;
}

