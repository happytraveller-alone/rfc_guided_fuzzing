//----- (000000018005E8A8) ----------------------------------------------------
__int64 __fastcall CSslCredential::CreateCredential(
        CSslCredential *this,
        int a2,
        char *a3,
        __int64 a4,
        struct LSA_SCHANNEL_SUB_CRED *a5,
        char a6,
        unsigned __int8 a7,
        int a8,
        struct _TLS_PARAMETERS *a9,
        unsigned int a10)
{
  void *v14; // r12
  char v15; // r11
  CCipherMill *v16; // rcx
  const struct _CERT_CONTEXT *v18; // rax
  DWORD LastError; // eax
  unsigned int PublicKeyFromCert; // ebx
  const CERT_CONTEXT *v21; // rcx
  void *v22; // rcx
  CCipherMill *v23; // rcx
  __int64 v24; // rdx
  NTSTATUS v25; // ebx
  ULONG v26; // eax
  __int64 v27; // r8
  __int64 v28; // r9
  DWORD PublicKeyLength; // eax
  PCCERT_CHAIN_CONTEXT *v30; // r13
  __int64 v31; // rcx
  __int64 v32; // r8
  __int64 v33; // r9
  int v34; // eax
  unsigned int v35; // eax
  __int64 v36; // rcx
  char v37; // al
  __int64 v38; // r8
  __int64 v39; // r9
  DWORD v40; // eax
  DWORD dwError; // eax
  struct _CERT_SERVER_OCSP_RESPONSE_OPEN_PARA *p_pOpenPara; // r8
  HCERT_SERVER_OCSP_RESPONSE v43; // rax
  DWORD v44; // eax
  bool v45; // r15
  unsigned int v46; // eax
  unsigned int v47; // eax
  const struct _CERT_CONTEXT *v48; // rcx
  const wchar_t *v49; // rcx
  CCipherMill *v50; // rcx
  unsigned __int8 v51; // cl
  int v52; // r8d
  unsigned __int8 v53; // al
  unsigned int v54; // r9d
  PCERT_CHAIN_PARA pChainPara; // [rsp+20h] [rbp-168h]
  DWORD pChainParaa; // [rsp+20h] [rbp-168h]
  int v57; // [rsp+60h] [rbp-128h] BYREF
  unsigned int v58; // [rsp+64h] [rbp-124h] BYREF
  struct CEccCurveInfo *v59; // [rsp+68h] [rbp-120h] BYREF
  struct _TLS_PARAMETERS *v60; // [rsp+70h] [rbp-118h]
  struct _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+78h] [rbp-110h] BYREF
  int v62[4]; // [rsp+88h] [rbp-100h] BYREF
  __int64 v63; // [rsp+98h] [rbp-F0h]
  struct _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+A0h] [rbp-E8h] BYREF
  struct _CERT_SERVER_OCSP_RESPONSE_OPEN_PARA pOpenPara; // [rsp+B8h] [rbp-D0h] BYREF
  struct _CERT_CHAIN_PARA v66; // [rsp+E0h] [rbp-A8h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v67; // [rsp+140h] [rbp-48h] BYREF

  v60 = a9;
  v14 = 0i64;
  memset_0(&v66, 0, 0x60ui64);
  v15 = 0;
  *((_DWORD *)this + 163) = a2;
  v57 = 0;
  v59 = 0i64;
  v63 = 0i64;
  pPolicyPara = 0i64;
  *(_OWORD *)v62 = 0i64;
  memset(&pPolicyStatus, 0, sizeof(pPolicyStatus));
  if ( a3 )
  {
    StringCchCopyW((char *)this + 656, 260i64, a3);
    goto LABEL_6;
  }
  v16 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
    v15 = 0;
LABEL_6:
    v16 = WPP_GLOBAL_Control;
  }
  if ( *((_BYTE *)this + 648) == v15 )
    return 14i64;
  if ( !a5 )
  {
    if ( v16 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v16 + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)v16 + 2), 11i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
    return 87i64;
  }
  if ( (*((_BYTE *)a5 + 48) & 1) != 0 )
    *((_DWORD *)this + 6) |= 0x20u;
  v18 = CertDuplicateCertificateContext(*(PCCERT_CONTEXT *)a5);
  *((_QWORD *)this + 4) = v18;
  if ( !v18 )
  {
    *((_DWORD *)this + 18) = 10004;
    LastError = GetLastError();
    PublicKeyFromCert = LastError;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, LastError);
    goto LABEL_20;
  }
  PublicKeyFromCert = GetPublicKeyFromCert(v18, (struct _PUBLICKEY **)this + 54, (unsigned int *)this + 33);
  if ( PublicKeyFromCert )
  {
    *((_DWORD *)this + 18) = 10005;
    v23 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      goto LABEL_21;
    v24 = 13i64;
    goto LABEL_32;
  }
  v25 = BCryptHash(
          49i64,
          0i64,
          0i64,
          *(_QWORD *)(*((_QWORD *)this + 4) + 8i64),
          *(_DWORD *)(*((_QWORD *)this + 4) + 16i64),
          (char *)this + 40,
          20);
  if ( v25 < 0 )
  {
    *((_DWORD *)this + 18) = 10016;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        14i64,
        &WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
        (unsigned int)v25);
    v26 = RtlNtStatusToDosError(v25);
    goto LABEL_38;
  }
  PublicKeyFromCert = CSslCredential::GetPrivateFromCert(this, a4, a5);
  if ( PublicKeyFromCert )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        15i64,
        &WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
        PublicKeyFromCert);
    *((_BYTE *)this + 76) = 1;
    goto LABEL_21;
  }
  if ( *((_BYTE *)this + 79) )
  {
    PublicKeyFromCert = GetCertEndpointBindings(
                          *((const struct _CERT_CONTEXT **)this + 4),
                          (unsigned __int8 **)this + 58,
                          (unsigned int *)this + 118);
    if ( PublicKeyFromCert )
    {
      *((_DWORD *)this + 18) = 10015;
      v23 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_21;
      v24 = 16i64;
LABEL_32:
      WPP_SF_D(*((_QWORD *)v23 + 2), v24, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, PublicKeyFromCert);
      goto LABEL_21;
    }
  }
  PublicKeyFromCert = SslImpersonateClient(a4, &v57);
  if ( PublicKeyFromCert )
    goto LABEL_21;
  if ( *((_DWORD *)this + 33) == 8707 )
  {
    PublicKeyLength = CertGetPublicKeyLength(
                        1u,
                        (PCERT_PUBLIC_KEY_INFO)(*(_QWORD *)(*((_QWORD *)this + 4) + 24i64) + 96i64));
    *((_DWORD *)this + 34) = PublicKeyLength;
    if ( !PublicKeyLength )
    {
      *((_DWORD *)this + 18) = 10006;
      v26 = GetLastError();
LABEL_38:
      PublicKeyFromCert = v26;
      goto LABEL_20;
    }
    PublicKeyFromCert = CertGetEccCurveType(*((_QWORD *)this + 4), (unsigned int *)this + 35);
    if ( PublicKeyFromCert )
    {
      *((_DWORD *)this + 18) = 10006;
      goto LABEL_21;
    }
  }
  if ( (a6 & 1) != 0 || a8 )
    v14 = *(void **)(*((_QWORD *)this + 4) + 32i64);
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(0i64, &ChainBuildStart, v27, v28, &v67);
  v30 = (PCCERT_CHAIN_CONTEXT *)((char *)this + 64);
  if ( !CertGetCertificateChain(
          0i64,
          *((PCCERT_CONTEXT *)this + 4),
          0i64,
          v14,
          &v66,
          a6 & 4,
          0i64,
          (PCCERT_CHAIN_CONTEXT *)this + 8) )
  {
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v31, &ChainBuildStop, v32, v33, &v67);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v34 = GetLastError();
      LODWORD(pChainPara) = a6 & 4;
      WPP_SF_Dd(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x11u,
        (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
        v34,
        pChainPara);
    }
    *v30 = 0i64;
    v35 = GetLastError();
    LogGetCertificateChainFailureEvent(
      *((_DWORD *)this + 163),
      (const unsigned __int16 *)this + 328,
      *((_BYTE *)this + 79),
      *((const struct _CERT_CONTEXT **)this + 4),
      v35,
      a6 & 4);
    goto LABEL_84;
  }
  v37 = Microsoft_Windows_Schannel_EventsEnableBits;
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
  {
    McGenEventWrite_EventWriteTransfer(v31, &ChainBuildStop, v32, v33, &v67);
    v37 = Microsoft_Windows_Schannel_EventsEnableBits;
  }
  v62[0] = 24;
  pPolicyPara.pvExtraPolicyPara = v62;
  v62[1] = 2;
  v62[2] = 640;
  pPolicyPara.cbSize = 16;
  if ( (v37 & 1) != 0 )
    McGenEventWrite_EventWriteTransfer((__int64)v62, &ChainVerifyStart, v32, v33, &v67);
  if ( !CertVerifyCertificateChainPolicy((LPCSTR)4, *v30, &pPolicyPara, &pPolicyStatus) )
  {
    v36 = (__int64)WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      goto LABEL_76;
    v40 = GetLastError();
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v40);
  }
  v36 = (__int64)WPP_GLOBAL_Control;
LABEL_76:
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
  {
    McGenEventWrite_EventWriteTransfer(v36, &ChainVerifyStop, v38, v39, &v67);
    v36 = (__int64)WPP_GLOBAL_Control;
  }
  dwError = pPolicyStatus.dwError;
  if ( pPolicyStatus.dwError )
  {
    if ( (CCipherMill **)v36 != &WPP_GLOBAL_Control && (*(_BYTE *)(v36 + 28) & 1) != 0 )
    {
      WPP_SF_D(*(_QWORD *)(v36 + 16), 19i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, pPolicyStatus.dwError);
      dwError = pPolicyStatus.dwError;
    }
    v36 = 2148204810i64;
    if ( dwError == -2146762486 )
      LogIncompleteCertificateChainEvent(
        *((_DWORD *)this + 163),
        (const unsigned __int16 *)this + 328,
        *((_BYTE *)this + 79),
        *((const struct _CERT_CONTEXT **)this + 4),
        0x800B010A);
  }
LABEL_84:
  if ( v57 )
  {
    RevertToSelf();
    v57 = 0;
  }
  if ( *((_BYTE *)this + 79) )
  {
    v36 = (__int64)*v30;
    if ( *v30 )
    {
      if ( (a6 & 0x10) == 0 )
      {
        p_pOpenPara = 0i64;
        if ( g_pszOcspReadDirectory )
        {
          pOpenPara.pcbUsedSize = 0i64;
          *(_OWORD *)&pOpenPara.pfnUpdateCallback = 0i64;
          pOpenPara.cbSize = 40;
          p_pOpenPara = &pOpenPara;
          pOpenPara.dwFlags = 1;
          pOpenPara.pwszOcspDirectory = (PWSTR)g_pszOcspReadDirectory;
        }
        v43 = CertOpenServerOcspResponse((PCCERT_CHAIN_CONTEXT)v36, 1u, p_pOpenPara);
        *((_QWORD *)this + 57) = v43;
        if ( !v43
          && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        {
          v44 = GetLastError();
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v44);
        }
      }
    }
  }
  v45 = (a6 & 8) != 0;
  v46 = SerializeCertChain(
          v36,
          *((const struct _CERT_CONTEXT **)this + 4),
          *v30,
          v45,
          (unsigned __int8 **)this + 55,
          (unsigned int *)this + 112);
  PublicKeyFromCert = v46;
  if ( v46 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 21i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v46);
    *((_DWORD *)this + 18) = 10007;
    goto LABEL_21;
  }
  if ( *((_DWORD *)this + 112) > 0x4000u )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
    *((_DWORD *)this + 18) = 10008;
    PublicKeyFromCert = 87;
    goto LABEL_21;
  }
  v47 = CSslCredential::FillInCredStructWithCertInfo(this);
  PublicKeyFromCert = v47;
  if ( v47 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 23i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v47);
    *((_DWORD *)this + 18) = 10009;
    goto LABEL_21;
  }
  CTlsSignatureSuiteList::SetCertificateChainSignatureSuites(
    (CSslCredential *)((char *)this + 512),
    *((const struct _CERT_CONTEXT **)this + 4),
    *v30,
    v45);
  v48 = (const struct _CERT_CONTEXT *)*((_QWORD *)this + 4);
  v58 = 64;
  PublicKeyFromCert = GetCngHashAndSignatureString(
                        v48,
                        (unsigned __int16 *)this + 136,
                        &v58,
                        (char *)this + 144,
                        pChainParaa);
  v49 = (const wchar_t *)((char *)this + 144);
  if ( PublicKeyFromCert )
  {
    *v49 = 0;
    *((_WORD *)this + 136) = 0;
    v50 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
  }
  else
  {
    *((_BYTE *)this + 80) = wcscmp_0(v49, L"SHA1") == 0;
  }
  if ( !a10 )
    goto LABEL_20;
  if ( *((_DWORD *)this + 33) == 8707 )
  {
    PublicKeyFromCert = CCipherMill::GetCurveInfo(v50, *((_DWORD *)this + 35), &v59);
    if ( PublicKeyFromCert )
    {
      *((_DWORD *)this + 18) = 10018;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
      goto LABEL_21;
    }
  }
  v51 = *((_BYTE *)this + 79);
  if ( v51 )
  {
    v52 = 41984;
    if ( *((_DWORD *)this + 33) == 41984 )
    {
      v53 = 1;
LABEL_124:
      v54 = *((_DWORD *)this + 107);
      goto LABEL_125;
    }
  }
  v52 = *((_DWORD *)this + 33);
  v53 = 0;
  if ( v52 != 8707 )
    goto LABEL_124;
  v54 = *((_DWORD *)this + 34);
LABEL_125:
  if ( IsCertificateBlacklisted(
         v60,
         a10,
         v52,
         v54,
         v59,
         v53,
         v51,
         (const unsigned __int16 *)this + 72,
         (const unsigned __int16 *)this + 136,
         0i64,
         1) )
  {
    PublicKeyFromCert = -2146893007;
    *((_DWORD *)this + 18) = 10018;
    goto LABEL_21;
  }
LABEL_20:
  if ( PublicKeyFromCert )
  {
LABEL_21:
    v21 = (const CERT_CONTEXT *)*((_QWORD *)this + 4);
    if ( v21 )
    {
      CertFreeCertificateContext(v21);
      *((_QWORD *)this + 4) = 0i64;
    }
    v22 = (void *)*((_QWORD *)this + 54);
    if ( v22 )
    {
      SPExternalFree(v22);
      *((_QWORD *)this + 54) = 0i64;
    }
  }
  if ( v57 )
    RevertToSelf();
  return PublicKeyFromCert;
}
// 18005E9A4: variable 'v15' is possibly undefined
// 18005ED1A: variable 'v27' is possibly undefined
// 18005ED1A: variable 'v28' is possibly undefined
// 18005ED7E: variable 'v31' is possibly undefined
// 18005ED7E: variable 'v32' is possibly undefined
// 18005ED7E: variable 'v33' is possibly undefined
// 18005EDC6: variable 'pChainPara' is possibly undefined
// 18005EF1C: variable 'v38' is possibly undefined
// 18005EF1C: variable 'v39' is possibly undefined
// 18005F080: variable 'v36' is possibly undefined
// 18005F182: variable 'pChainParaa' is possibly undefined
// 18005F210: variable 'v50' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C60: using guessed type EVENT_DESCRIPTOR ChainVerifyStop;
// 180084C70: using guessed type EVENT_DESCRIPTOR ChainVerifyStart;
// 180084C80: using guessed type EVENT_DESCRIPTOR ChainBuildStop;
// 180084C90: using guessed type EVENT_DESCRIPTOR ChainBuildStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180098360: using guessed type __int64 __fastcall BCryptHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);

