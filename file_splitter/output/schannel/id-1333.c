// File count: 1333
// Total lines: 133
---------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ParseCertData(
        __int64 a1,
        const BYTE *a2,
        DWORD a3,
        int a4,
        CTlsSignatureSuiteList *a5,
        __int64 a6)
{
  PCCERT_CONTEXT CertificateContext; // rax
  const CERT_CONTEXT *v9; // rdi
  __int64 v10; // rcx
  struct _CRYPTOAPI_BLOB *pCertInfo; // rdx
  unsigned int v12; // esi
  unsigned __int8 v13; // r9
  int v14; // edx
  int PublicKeyFromCert; // eax
  __int64 v16; // rcx
  struct _PUBLICKEY *v17; // rbx
  __int64 v18; // r14
  unsigned int v19; // edx
  bool v20; // r12
  struct CCipherSuiteInfo *v21; // r15
  struct _SecPkgContext_ApplicationProtocol *v22; // rax
  unsigned int v23; // eax
  unsigned int v24; // r14d
  __int64 v25; // rax
  struct _PUBLICKEY *v27; // [rsp+78h] [rbp+10h] BYREF

  if ( !a2 || !a3 )
  {
    v10 = *(_QWORD *)(a1 + 8);
    goto LABEL_35;
  }
  CertificateContext = CertCreateCertificateContext(1u, a2, a3);
  v9 = CertificateContext;
  if ( CertificateContext )
  {
    pCertInfo = (struct _CRYPTOAPI_BLOB *)CertificateContext->pCertInfo;
    v12 = 0;
    v27 = 0i64;
    if ( pCertInfo )
    {
      if ( a4 && CertCompareCertificateName(CertificateContext->dwCertEncodingType, pCertInfo + 3, pCertInfo + 5) )
        goto LABEL_32;
      if ( CTlsSignatureSuiteList::AddCertificateSignatureSuite(a5, v9) )
      {
        if ( !a4 )
        {
          PublicKeyFromCert = GetPublicKeyFromCert(v9, &v27, 0i64);
          v16 = *(_QWORD *)(a1 + 8);
          v12 = PublicKeyFromCert;
          if ( PublicKeyFromCert )
          {
            CSslContext::SetErrorAndFatalAlert(v16, 251, PublicKeyFromCert, 0x2Bu);
            v17 = v27;
          }
          else
          {
            v18 = *(_QWORD *)(v16 + 80);
            v17 = v27;
            if ( v18 )
            {
              v19 = *(_DWORD *)(v18 + 196);
              v20 = (*(_DWORD *)(v16 + 64) & 0x40051555) != 0;
              if ( v19
                && ((v21 = *(struct CCipherSuiteInfo **)(v16 + 8), (*(_DWORD *)(v16 + 64) & 0x40051555) == 0)
                  ? (v22 = 0i64)
                  : (struct _SecPkgContext_ApplicationProtocol *)(v22 = (struct _SecPkgContext_ApplicationProtocol *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v16 + 88i64))(v16),
                                                                  v19 = *(_DWORD *)(v18 + 196)),
                    v23 = IsRemoteCertificateBlacklisted(
                            *(struct _TLS_PARAMETERS **)(v18 + 200),
                            v19,
                            v9,
                            v17,
                            v22,
                            v21,
                            v20),
                    (v24 = v23) != 0) )
              {
                if ( v23 == -2146893007 )
                {
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                  {
                    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
                  }
                  CSslContext::SetErrorAndFatalAlert(*(_QWORD *)(a1 + 8), 251, -2146893007, 0x2Bu);
                }
                v12 = v24;
              }
              else
              {
                v25 = a6;
                *(_QWORD *)(a6 + 40) = v17;
                v17 = 0i64;
                *(_QWORD *)(v25 + 48) = v9;
                v9 = 0i64;
              }
            }
            else
            {
              v12 = -2146893052;
            }
          }
          if ( v17 )
            SPExternalFree(v17);
          if ( !v9 )
            return v12;
        }
        goto LABEL_32;
      }
      v13 = 43;
      v14 = 252;
    }
    else
    {
      v13 = 42;
      v14 = 250;
    }
    v12 = -2146893048;
    CSslContext::SetErrorAndFatalAlert(*(_QWORD *)(a1 + 8), v14, -2146893048, v13);
LABEL_32:
    CertFreeCertificateContext(v9);
    return v12;
  }
  v10 = *(_QWORD *)(a1 + 8);
LABEL_35:
  CSslContext::SetErrorAndFatalAlert(v10, 250, -2146893048, 0x2Au);
  return 2148074248i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
