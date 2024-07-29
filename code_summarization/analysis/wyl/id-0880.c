//----- (0000000180047D14) ----------------------------------------------------
__int64 __fastcall SslBuildCertLogonRequest(
        const struct _CERT_CHAIN_CONTEXT *a1,
        int a2,
        struct _SSL_CERT_LOGON_REQ **a3,
        unsigned int *a4)
{
  PCERT_SIMPLE_CHAIN v5; // r13
  PCCERT_CONTEXT pCertContext; // r15
  unsigned int v7; // ebx
  __int64 v8; // rsi
  __int64 v9; // rdi
  PCCERT_CONTEXT v10; // r14
  unsigned int v11; // ebp
  _DWORD *v12; // rax
  _DWORD *v13; // rdi
  unsigned int v15; // r14d
  DWORD v16; // r14d
  _DWORD *v17; // r12
  __int64 v18; // rbx

  v5 = *a1->rgpChain;
  pCertContext = (*v5->rgpElement)->pCertContext;
  v7 = pCertContext->cbCertEncoded + 32;
  if ( pCertContext->cbCertEncoded >= 0xFFFFFFE0 )
    return 534i64;
  v8 = 0i64;
  v9 = 0i64;
  if ( v5->cElement )
  {
    while ( 1 )
    {
      v10 = v5->rgpElement[v9]->pCertContext;
      if ( (_DWORD)v9 )
      {
        if ( CertCompareCertificateName(v10->dwCertEncodingType, &v10->pCertInfo->Issuer, &v10->pCertInfo->Subject) )
          goto LABEL_8;
        v7 += 8;
      }
      if ( v7 + v10->pCertInfo->Issuer.cbData < v7 )
        return 3221225621i64;
      v8 = (unsigned int)(v8 + 1);
      v9 = (unsigned int)(v9 + 1);
      v7 += v10->pCertInfo->Issuer.cbData;
      if ( (unsigned int)v9 >= v5->cElement )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    v11 = (v7 + 3) & 0xFFFFFFFC;
    v12 = LocalAlloc(0x40u, v11);
    v13 = v12;
    if ( v12 )
    {
      *v12 = 2;
      v15 = 8 * v8 + 24;
      v12[2] = v15;
      v12[1] = v11;
      v12[3] = pCertContext->cbCertEncoded;
      v12[4] = a2 | 0x80;
      memcpy_0((char *)v12 + v15, pCertContext->pbCertEncoded, pCertContext->cbCertEncoded);
      v16 = pCertContext->cbCertEncoded + v15;
      v13[5] = v8;
      if ( (_DWORD)v8 )
      {
        v17 = v13 + 7;
        do
        {
          v18 = *(_QWORD *)(*(_QWORD *)((char *)v17 + (unsigned __int64)v5->rgpElement - (_QWORD)v13 - 28) + 8i64);
          *(v17 - 1) = v16;
          *v17 = *(_DWORD *)(*(_QWORD *)(v18 + 24) + 48i64);
          memcpy_0(
            (char *)v13 + v16,
            *(const void **)(*(_QWORD *)(v18 + 24) + 56i64),
            *(unsigned int *)(*(_QWORD *)(v18 + 24) + 48i64));
          v17 += 2;
          v16 += *(_DWORD *)(*(_QWORD *)(v18 + 24) + 48i64);
          --v8;
        }
        while ( v8 );
      }
      *a3 = (struct _SSL_CERT_LOGON_REQ *)v13;
      *a4 = v11;
      return 0i64;
    }
    else
    {
      return 2148074240i64;
    }
  }
}
