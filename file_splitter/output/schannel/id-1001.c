// File count: 1001
// Total lines: 92
----------------------------------------
__int64 __fastcall CheckForLocalStoreCertificateRenewal(
        HCERTSTORE hCertStore,
        PCCERT_CONTEXT pCertContext,
        char a3,
        const struct _CERT_CONTEXT **a4)
{
  unsigned int v4; // r14d
  unsigned int v5; // r12d
  DWORD LastError; // eax
  __int64 v8; // rdx
  const CERT_CONTEXT *CertificateInStore; // rsi
  PCCERT_CONTEXT v11; // r15
  DWORD v12; // eax
  DWORD pcbData; // [rsp+30h] [rbp-40h] BYREF
  DWORD pvFindPara; // [rsp+38h] [rbp-38h] BYREF
  char *v15; // [rsp+40h] [rbp-30h]
  const struct _CERT_CONTEXT **v16; // [rsp+48h] [rbp-28h]
  char pvData[24]; // [rsp+50h] [rbp-20h] BYREF

  v4 = 0;
  v16 = a4;
  v5 = 0;
  pcbData = 20;
  if ( a3 )
  {
    if ( CertGetCertificateContextProperty(pCertContext, 3u, pvData, &pcbData) )
    {
      pvFindPara = pcbData;
      v15 = pvData;
      CertificateInStore = CertFindCertificateInStore(hCertStore, 1u, 0, 0x10000u, &pvFindPara, 0i64);
      if ( CertificateInStore )
        goto LABEL_13;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 0i64;
      LastError = GetLastError();
      v8 = 26i64;
    }
    else
    {
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 0i64;
      LastError = GetLastError();
      v8 = 25i64;
    }
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), v8, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, LastError);
    return 0i64;
  }
  CertificateInStore = CertDuplicateCertificateContext(pCertContext);
LABEL_13:
  while ( 1 )
  {
    pcbData = 20;
    if ( !CertGetCertificateContextProperty(CertificateInStore, 0x40u, pvData, &pcbData) )
      break;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 28i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids);
    pvFindPara = pcbData;
    v15 = pvData;
    v11 = CertFindCertificateInStore(hCertStore, 1u, 0, 0x10000u, &pvFindPara, 0i64);
    if ( !v11 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        v12 = GetLastError();
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v12);
      }
      goto LABEL_29;
    }
    CertFreeCertificateContext(CertificateInStore);
    ++v5;
    CertificateInStore = v11;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids);
    v4 = 1;
    if ( v5 >= 0x53A )
      goto LABEL_30;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids);
LABEL_29:
  if ( v4 )
  {
LABEL_30:
    *v16 = CertificateInStore;
    return v4;
  }
  CertFreeCertificateContext(CertificateInStore);
  return v4;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
