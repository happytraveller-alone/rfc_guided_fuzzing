// File count: 857
// Total lines: 140
----------------------------------------
BOOL __stdcall SslCrackCertificate(
        PUCHAR pbCertificate,
        DWORD cbCertificate,
        DWORD dwFlags,
        PX509Certificate *ppCertificate)
{
  DWORD v4; // ebx
  char v7; // r14
  struct _X509Certificate *v9; // rdi
  __int64 v10; // rcx
  PCCERT_CONTEXT CertificateContext; // rax
  const CERT_CONTEXT *v12; // rsi
  DWORD v13; // r14d
  PctPublicKey *pPublicKey; // rcx
  BOOL result; // eax
  DWORD v16; // eax
  __int64 csz; // rbp
  struct _X509Certificate *v18; // rax
  size_t cbData; // r8
  PCERT_INFO pCertInfo; // rdx
  CHAR *pszIssuer; // r9
  PctPublicKey *v22; // rax
  PctPublicKey *v23; // r14
  struct _PUBLICKEY *v24; // r8
  __int64 v25; // rcx
  bool v26; // zf
  DWORD v27; // eax
  DWORD v28; // edx
  struct _PUBLICKEY *v29; // [rsp+30h] [rbp-28h] BYREF

  v4 = 0;
  v7 = dwFlags;
  v9 = 0i64;
  if ( !(unsigned int)SchannelInit(1) )
    return 0;
  if ( (v7 & 2) != 0 )
  {
    if ( cbCertificate < 0x12 )
      return 0;
    v10 = *(_QWORD *)(pbCertificate + 4) - 0x6669747265630B04i64;
    if ( *(_QWORD *)(pbCertificate + 4) == 0x6669747265630B04i64 )
    {
      v10 = *((unsigned int *)pbCertificate + 3) - 1952539497i64;
      if ( *((_DWORD *)pbCertificate + 3) == 1952539497i64 )
        v10 = pbCertificate[16] - 101i64;
    }
    if ( !v10 )
    {
      pbCertificate += 17;
      cbCertificate -= 17;
    }
  }
  CertificateContext = CertCreateCertificateContext(1u, pbCertificate, cbCertificate);
  v12 = CertificateContext;
  if ( !CertificateContext )
  {
    GetLastError();
    return 0;
  }
  v13 = CertNameToStrA(
          CertificateContext->dwCertEncodingType,
          &CertificateContext->pCertInfo->Subject,
          0x20000003u,
          0i64,
          0);
  if ( !v13 )
    goto LABEL_12;
  v16 = CertNameToStrA(v12->dwCertEncodingType, &v12->pCertInfo->Issuer, 0x20000003u, 0i64, 0);
  csz = v16;
  if ( !v16 )
    goto LABEL_12;
  v18 = (struct _X509Certificate *)SPExternalAlloc(v16 + v13 + 66);
  v9 = v18;
  if ( !v18 )
    goto LABEL_13;
  v18->pPublicKey = 0i64;
  v18->pszIssuer = (PSTR)&v18[1];
  v18->pszSubject = (char *)&v18[1] + csz;
  cbData = 16i64;
  v18->Version = v12->pCertInfo->dwVersion;
  pCertInfo = v12->pCertInfo;
  if ( pCertInfo->SerialNumber.cbData <= 0x10 )
    cbData = pCertInfo->SerialNumber.cbData;
  memcpy_0(v18->SerialNumber, pCertInfo->SerialNumber.pbData, cbData);
  pszIssuer = v9->pszIssuer;
  v9->ValidFrom = v12->pCertInfo->NotBefore;
  v9->ValidUntil = v12->pCertInfo->NotAfter;
  if ( !CertNameToStrA(v12->dwCertEncodingType, &v12->pCertInfo->Issuer, 0x20000003u, pszIssuer, csz)
    || !CertNameToStrA(v12->dwCertEncodingType, &v12->pCertInfo->Subject, 0x20000003u, v9->pszSubject, v13) )
  {
LABEL_12:
    GetLastError();
    goto LABEL_13;
  }
  v29 = 0i64;
  v22 = (PctPublicKey *)SPExternalAlloc(0x20u);
  v9->pPublicKey = v22;
  if ( !v22
    || (v22->Type = 0,
        v9->pPublicKey->cbKey = 20,
        v23 = v9->pPublicKey,
        *(_DWORD *)v23->pKey = 826364754,
        GetPublicKeyFromCert(v12, &v29, 0i64)) )
  {
LABEL_13:
    CertFreeCertificateContext(v12);
    if ( v9 )
    {
      pPublicKey = v9->pPublicKey;
      if ( pPublicKey )
        SPExternalFree(pPublicKey);
      SPExternalFree(v9);
    }
    return 0;
  }
  v24 = v29;
  v25 = *(_QWORD *)v29;
  v26 = *(_DWORD *)(*(_QWORD *)v29 + 4i64) == 41984;
  v23[1].Type = *(_DWORD *)(*(_QWORD *)v29 + 12i64) >> 3;
  if ( v26 )
  {
    v27 = *(_DWORD *)(v25 + 12);
    v23[1].cbKey = v27;
    *(_DWORD *)v23[1].pKey = (v27 >> 3) - 1;
    v4 = *(_DWORD *)(v25 + 16);
  }
  else
  {
    v28 = *(_DWORD *)(v25 + 12) >> 3;
    v23[1].cbKey = v28;
    *(_DWORD *)v23[1].pKey = (v28 >> 3) - 1;
  }
  v23[2].Type = v4;
  SPExternalFree(v24);
  CertFreeCertificateContext(v12);
  result = 1;
  *ppCertificate = v9;
  return result;
}
