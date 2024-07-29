//----- (0000000180054D10) ----------------------------------------------------
void __fastcall CTlsSignatureSuiteList::SetCertificateChainSignatureSuites(
        CTlsSignatureSuiteList *this,
        const struct _CERT_CONTEXT *a2,
        const struct _CERT_CHAIN_CONTEXT *a3,
        char a4)
{
  char v6; // si
  DWORD v7; // edi
  PCERT_SIMPLE_CHAIN v8; // rbp
  const CERT_CONTEXT *pCertContext; // r14

  *(_WORD *)this = 0;
  *((_WORD *)this + 17) = 0;
  v6 = 1;
  if ( a3 )
  {
    v7 = 0;
    v8 = *a3->rgpChain;
    if ( !v8->cElement )
      return;
    do
    {
      pCertContext = v8->rgpElement[v7]->pCertContext;
      if ( v7
        && !a4
        && CertCompareCertificateName(
             pCertContext->dwCertEncodingType,
             &pCertContext->pCertInfo->Issuer,
             &pCertContext->pCertInfo->Subject) )
      {
        break;
      }
      v6 = CTlsSignatureSuiteList::AddCertificateSignatureSuite(this, pCertContext);
      if ( !v6 )
        goto LABEL_10;
      ++v7;
    }
    while ( v7 < v8->cElement );
  }
  else
  {
    v6 = CTlsSignatureSuiteList::AddCertificateSignatureSuite(this, a2);
  }
  if ( !v6 )
  {
LABEL_10:
    *(_WORD *)this = 0;
    *((_WORD *)this + 17) = 0;
  }
}

