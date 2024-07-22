//----- (0000000180054B34) ----------------------------------------------------
__int64 __fastcall SerializeCertChain(
        __int64 a1,
        const struct _CERT_CONTEXT *a2,
        const struct _CERT_CHAIN_CONTEXT *a3,
        char a4,
        unsigned __int8 **a5,
        unsigned int *a6)
{
  unsigned int v6; // ebx
  unsigned int v10; // edi
  unsigned __int8 *v11; // rax
  char *v12; // rcx
  PCERT_SIMPLE_CHAIN *rgpChain; // rax
  DWORD v14; // ebp
  PCERT_SIMPLE_CHAIN i; // r15
  PCCERT_CONTEXT pCertContext; // r14
  unsigned int v17; // ecx
  unsigned __int8 *v18; // rax
  DWORD v19; // ebp
  char *j; // rsi
  PCCERT_CONTEXT v21; // rdi
  char *v22; // rsi

  v6 = 0;
  if ( !a6 )
    return 2148074244i64;
  if ( a3 )
  {
    rgpChain = a3->rgpChain;
    v10 = 0;
    v14 = 0;
    for ( i = *rgpChain; v14 < i->cElement; v10 = v17 + 3 )
    {
      pCertContext = i->rgpElement[v14]->pCertContext;
      if ( v14 )
      {
        if ( !a4
          && CertCompareCertificateName(
               pCertContext->dwCertEncodingType,
               &pCertContext->pCertInfo->Issuer,
               &pCertContext->pCertInfo->Subject) )
        {
          break;
        }
      }
      v17 = v10 + pCertContext->cbCertEncoded;
      if ( v10 > v17 )
        return 534;
      ++v14;
    }
    if ( !a5 )
      goto LABEL_5;
    if ( *a5 )
    {
      if ( *a6 < v10 )
        return (unsigned int)-2146893023;
    }
    else
    {
      v18 = (unsigned __int8 *)SPExternalAlloc(v10);
      *a5 = v18;
      if ( !v18 )
        return (unsigned int)-2146893056;
    }
    *a6 = v10;
    v19 = 0;
    for ( j = (char *)*a5; v19 < i->cElement; j = &v22[v21->cbCertEncoded] )
    {
      v21 = i->rgpElement[v19]->pCertContext;
      if ( v19
        && !a4
        && CertCompareCertificateName(v21->dwCertEncodingType, &v21->pCertInfo->Issuer, &v21->pCertInfo->Subject) )
      {
        break;
      }
      *j = BYTE2(v21->cbCertEncoded);
      j[1] = BYTE1(v21->cbCertEncoded);
      j[2] = v21->cbCertEncoded;
      v22 = j + 3;
      memcpy_0(v22, v21->pbCertEncoded, v21->cbCertEncoded);
      ++v19;
    }
    return v6;
  }
  v10 = a2->cbCertEncoded + 3;
  if ( a5 )
  {
    if ( !*a5 )
    {
      v11 = (unsigned __int8 *)SPExternalAlloc(v10);
      *a5 = v11;
      if ( !v11 )
        return (unsigned int)-2146893056;
LABEL_11:
      *a6 = v10;
      v12 = (char *)*a5;
      *v12 = BYTE2(a2->cbCertEncoded);
      v12[1] = BYTE1(a2->cbCertEncoded);
      v12[2] = a2->cbCertEncoded;
      memcpy_0(v12 + 3, a2->pbCertEncoded, a2->cbCertEncoded);
      return v6;
    }
    if ( *a6 >= v10 )
      goto LABEL_11;
    return (unsigned int)-2146893023;
  }
LABEL_5:
  *a6 = v10;
  return v6;
}

