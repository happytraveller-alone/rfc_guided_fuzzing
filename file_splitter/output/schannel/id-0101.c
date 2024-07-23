// File count: 101
// Total lines: 290
----------------------------------------
__int64 __fastcall CSsl3TlsContext::DigestRemoteCertificate(
        CSsl3TlsContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  unsigned int v3; // edi
  CSsl3TlsContext *v4; // rsi
  unsigned __int8 *v5; // r14
  int v6; // ebp
  unsigned int v7; // ebp
  _QWORD *v8; // rax
  void *v9; // rcx
  void *v10; // rcx
  const CERT_CONTEXT *v11; // rcx
  int v12; // ebx
  unsigned __int8 *v13; // r9
  unsigned int v14; // ecx
  DWORD v15; // r8d
  __int64 v16; // rax
  PCCERT_CONTEXT CertificateContext; // rax
  const struct _CERT_CONTEXT *v18; // r14
  unsigned int PublicKeyFromCert; // ebx
  int *v20; // r13
  int v21; // r12d
  __int64 v22; // rcx
  struct _SecPkgContext_ApplicationProtocol *v23; // rax
  _DWORD *v24; // rax
  _DWORD *v25; // r14
  unsigned __int8 *v26; // r12
  _DWORD *v27; // r15
  const void *v28; // rdx
  size_t v29; // r8
  __int64 v30; // rbx
  __int64 v31; // rax
  __int64 v33; // rax
  __int64 v34; // rax
  const unsigned __int16 *v35; // rbx
  const wchar_t *v36; // r9
  int v37; // r8d
  int v38; // edx
  unsigned __int8 v39; // r9
  struct _SecPkgContext_ApplicationProtocol *v40; // [rsp+20h] [rbp-A8h]
  struct CCipherSuiteInfo *v41; // [rsp+28h] [rbp-A0h]
  unsigned int v42; // [rsp+40h] [rbp-88h]
  int v43; // [rsp+40h] [rbp-88h]
  int v44; // [rsp+44h] [rbp-84h]
  struct _PUBLICKEY *v45; // [rsp+48h] [rbp-80h] BYREF
  unsigned __int8 *v46; // [rsp+50h] [rbp-78h]
  unsigned __int8 *v47; // [rsp+58h] [rbp-70h]
  __int16 v48; // [rsp+60h] [rbp-68h] BYREF
  __int128 v49; // [rsp+62h] [rbp-66h]
  __int128 v50; // [rsp+72h] [rbp-56h]
  __int16 v51; // [rsp+82h] [rbp-46h]

  v3 = 0;
  v48 = 0;
  v4 = this;
  v49 = 0i64;
  v50 = 0i64;
  v51 = 0;
  if ( a3 < 3 )
    goto LABEL_66;
  v5 = a2 + 3;
  v6 = (*a2 << 16) + (a2[1] << 8);
  v47 = a2 + 3;
  v7 = a2[2] + v6;
  if ( a3 != v7 + 3 )
    goto LABEL_66;
  if ( v7 )
  {
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
    v8 = (_QWORD *)*((_QWORD *)v4 + 11);
    v9 = (void *)v8[3];
    if ( v9 )
    {
      SPExternalFree(v9);
      v33 = *((_QWORD *)v4 + 11);
      *(_DWORD *)(v33 + 32) = 0;
      *(_QWORD *)(v33 + 24) = 0i64;
      v8 = (_QWORD *)*((_QWORD *)v4 + 11);
    }
    v10 = (void *)v8[5];
    if ( v10 )
    {
      SPExternalFree(v10);
      *(_QWORD *)(*((_QWORD *)v4 + 11) + 40i64) = 0i64;
      v8 = (_QWORD *)*((_QWORD *)v4 + 11);
    }
    v11 = (const CERT_CONTEXT *)v8[6];
    if ( v11 )
    {
      CertFreeCertificateContext(v11);
      *(_QWORD *)(*((_QWORD *)v4 + 11) + 48i64) = 0i64;
    }
    v12 = 0;
    v44 = 0;
    v13 = v5;
    v14 = v7;
    while ( 1 )
    {
      if ( v14 <= 3
        || (v15 = v13[2] + (*v13 << 16) + (v13[1] << 8), v16 = v15 + 3, v14 < (unsigned int)v16)
        || (v46 = &v13[v16],
            v42 = -3 - v15 + v14,
            CertificateContext = CertCreateCertificateContext(1u, v13 + 3, v15),
            (v18 = CertificateContext) == 0i64) )
      {
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
        this = v4;
        goto LABEL_66;
      }
      if ( (*((_DWORD *)v4 + 16) & 0xC0C00) != 0 )
      {
        if ( v12
          && CertCompareCertificateName(
               CertificateContext->dwCertEncodingType,
               &CertificateContext->pCertInfo->Issuer,
               &CertificateContext->pCertInfo->Subject) )
        {
LABEL_36:
          CertFreeCertificateContext(v18);
          goto LABEL_28;
        }
        if ( !CTlsSignatureSuiteList::AddCertificateSignatureSuite((CTlsSignatureSuiteList *)&v48, v18) )
        {
          RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
          v3 = -2146893048;
          CSslContext::SetErrorAndFatalAlert((__int64)v4, 252, -2146893048, 0x2Bu);
          CertFreeCertificateContext(v18);
          return v3;
        }
      }
      if ( v12 )
        goto LABEL_36;
      v45 = 0i64;
      PublicKeyFromCert = GetPublicKeyFromCert(v18, &v45, 0i64);
      if ( PublicKeyFromCert )
      {
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
        v37 = -2146893048;
        goto LABEL_56;
      }
      v20 = (int *)*((_QWORD *)v4 + 1);
      v21 = *((_DWORD *)v4 + 16) & 0x40051555;
      if ( !v20 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 51i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
        PublicKeyFromCert = -1073741595;
        v39 = 80;
        v37 = -1073741595;
        v38 = 254;
        goto LABEL_58;
      }
      v22 = *((_QWORD *)v4 + 10);
      if ( *(_DWORD *)(v22 + 196) )
      {
        if ( v21 )
        {
          v23 = (struct _SecPkgContext_ApplicationProtocol *)(*(__int64 (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)v4 + 88i64))(v4);
          v22 = *((_QWORD *)v4 + 10);
        }
        else
        {
          v23 = 0i64;
        }
        PublicKeyFromCert = IsRemoteCertificateBlacklisted(
                              *(struct _TLS_PARAMETERS **)(v22 + 200),
                              *(_DWORD *)(v22 + 196),
                              v18,
                              v45,
                              v23,
                              (struct CCipherSuiteInfo *)v20,
                              v21 != 0);
        if ( PublicKeyFromCert )
        {
          RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
          if ( PublicKeyFromCert == -2146893007 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 52i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
            }
            v37 = -2146893007;
LABEL_56:
            v38 = 251;
            v39 = 43;
LABEL_58:
            CSslContext::SetErrorAndFatalAlert((__int64)v4, v38, v37, v39);
          }
          CertFreeCertificateContext(v18);
          return PublicKeyFromCert;
        }
      }
      if ( !v21 && !(unsigned int)IsCertKeyUsageCompliant(v20[8], v20[9], v18) )
      {
        v34 = (*(__int64 (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)v4 + 320i64))(v4);
        v35 = (const unsigned __int16 *)v34;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          v36 = L"NULL";
          if ( v34 )
            v36 = (const wchar_t *)v34;
          LODWORD(v40) = v20[8];
          LODWORD(v41) = v20[9];
          WPP_SF_Sdd(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x35u,
            (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
            v36,
            v40,
            v41);
        }
        CSchannelTelemetryContext::LogCertKeyUsageError((unsigned int)v20[8], v20[9], v35);
      }
      v12 = v44;
      *(_QWORD *)(*((_QWORD *)v4 + 11) + 40i64) = v45;
      *(_QWORD *)(*((_QWORD *)v4 + 11) + 48i64) = v18;
LABEL_28:
      v14 = v42;
      v44 = ++v12;
      if ( !v42 )
      {
        if ( (*((_DWORD *)v4 + 16) & 0xC0C00) != 0
          && !CTlsSignatureSuiteList::IsSupportedSignatureSuiteList(
                (CSsl3TlsContext *)((char *)v4 + 474),
                (struct CTlsSignatureSuiteList *)&v48) )
        {
          RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
          v3 = -2146893048;
          CSslContext::SetErrorAndFatalAlert((__int64)v4, 252, -2146893048, 0x28u);
        }
        else
        {
          v43 = v12 + v7;
          v24 = SPExternalAlloc(v12 + v7);
          v25 = v24;
          if ( v24 )
          {
            v26 = v47;
            v27 = v24;
            do
            {
              v28 = v26 + 3;
              v29 = v26[2] + (*v26 << 16) + (v26[1] << 8);
              *v27 = v29;
              v7 += -3 - v29;
              v30 = (unsigned int)v29;
              v26 += (unsigned int)(v29 + 3);
              memcpy_0(v27 + 1, v28, v29);
              v27 = (_DWORD *)((char *)v27 + v30 + 4);
            }
            while ( v7 );
            v31 = *((_QWORD *)v4 + 11);
            *(_DWORD *)(v31 + 32) = v43;
            *(_QWORD *)(v31 + 24) = v25;
            RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
          }
          else
          {
            RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 11) + 72i64));
            return 14;
          }
        }
        return v3;
      }
      v13 = v46;
    }
  }
  if ( (*((_DWORD *)this + 16) & 0x800A2AAA) != 0 )
  {
LABEL_66:
    v3 = -2146893048;
    CSslContext::SetErrorAndFatalAlert((__int64)this, 250, -2146893048, 0x2Au);
  }
  else
  {
    *((_BYTE *)this + 552) = 1;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 50i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  }
  return v3;
}
// 180033D18: variable 'v40' is possibly undefined
// 180033D18: variable 'v41' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180083C60: using guessed type wchar_t aNull_0[5];
