//----- (00000001800571A4) ----------------------------------------------------
__int64 __fastcall AcquireDefaultClientCredential(struct CSsl3TlsClientContext *this, int a2)
{
  DWORD v2; // r14d
  CERT_NAME_BLOB *v3; // r15
  unsigned __int8 v5; // si
  int CredentialManagerForCert; // ebx
  unsigned int v8; // eax
  unsigned __int16 *v9; // rax
  __int64 v10; // rbx
  __int64 v11; // r10
  unsigned int v12; // eax
  unsigned __int8 *v13; // rbx
  unsigned __int8 *v14; // rdx
  unsigned __int64 v15; // r8
  unsigned __int8 *v16; // rax
  CERT_NAME_BLOB *v17; // rax
  CERT_NAME_BLOB *v18; // rdx
  __int64 v19; // r8
  int v20; // ecx
  HCERTSTORE v21; // rsi
  int v22; // eax
  void *pvPara; // [rsp+20h] [rbp-60h]
  struct _CERT_CHAIN_FIND_BY_ISSUER_PARA v25; // [rsp+40h] [rbp-40h] BYREF
  unsigned __int8 v26; // [rsp+B0h] [rbp+30h] BYREF
  int v27; // [rsp+C0h] [rbp+40h] BYREF

  v2 = 0;
  v3 = 0i64;
  v27 = 0;
  v5 = 0;
  v26 = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
  CredentialManagerForCert = SslImpersonateClient(*(_QWORD *)(*((_QWORD *)this + 10) + 752i64), &v27);
  if ( !CredentialManagerForCert )
  {
    if ( v27 )
    {
      v8 = IsThreadLocalSystemOrNetworkService(&v26);
      if ( v8
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      {
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          (unsigned int)(CredentialManagerForCert + 21),
          &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
          v8);
      }
      RevertToSelf();
      v27 = 0;
      v5 = v26;
    }
    if ( !*((_DWORD *)this + 262) )
    {
      v9 = (unsigned __int16 *)(*(__int64 (__fastcall **)(struct CSsl3TlsClientContext *))(*(_QWORD *)this + 320i64))(this);
      CredentialManagerForCert = QueryCredentialManagerForCert(this, v9);
      CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 1);
      if ( CredentialManagerForCert >= 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
        goto LABEL_45;
      }
    }
    if ( a2 )
    {
      CredentialManagerForCert = 590624;
      goto LABEL_45;
    }
    v10 = *((_QWORD *)this + 112);
    v11 = v10;
    if ( v10 )
    {
      v12 = *((_DWORD *)this + 222);
      if ( v12 > 2 )
      {
        v13 = (unsigned __int8 *)(v10 + 2);
        v14 = v13;
        v15 = (unsigned __int64)&v13[v12 - 2];
        if ( v11 + 3 < v15 )
        {
          v16 = (unsigned __int8 *)(v11 + 3);
          do
          {
            ++v2;
            v14 += (*v16 | ((unsigned __int64)*v14 << 8)) + 2;
            v16 = v14 + 1;
          }
          while ( (unsigned __int64)(v14 + 1) < v15 );
        }
        v17 = (CERT_NAME_BLOB *)SPExternalAlloc(16 * v2);
        v3 = v17;
        if ( !v17 )
        {
          CredentialManagerForCert = -2146893056;
          goto LABEL_45;
        }
        if ( v2 )
        {
          v18 = v17;
          v19 = v2;
          do
          {
            v18->pbData = v13 + 2;
            v20 = v13[1] | (*v13 << 8);
            v18->cbData = v20;
            v13 += (unsigned int)(v20 + 2);
            ++v18;
            --v19;
          }
          while ( v19 );
        }
      }
    }
    CredentialManagerForCert = SslImpersonateClient(*(_QWORD *)(*((_QWORD *)this + 10) + 752i64), &v27);
    if ( !CredentialManagerForCert )
    {
      v21 = CertOpenStore((LPCSTR)0xA, 1u, 0i64, v5 != 0 ? 180228 : 114692, L"MY");
      if ( !v21 )
      {
        CredentialManagerForCert = GetLastError();
        goto LABEL_45;
      }
      v25.pvFindArg = 0i64;
      *(_QWORD *)&v25.cbSize = 0i64;
      v25.pszUsageIdentifier = "1.3.6.1.5.5.7.3.2";
      v22 = *((_DWORD *)this + 262);
      *(_OWORD *)&v25.dwKeySpec = 0i64;
      v25.dwKeySpec = 0;
      v25.cIssuer = v2;
      v25.cbSize = 56;
      v25.pfnFindCallback = 0i64;
      v25.rgIssuer = v3;
      if ( v22 == 1 )
      {
        CredentialManagerForCert = FindClientCertificate(
                                     this,
                                     v21,
                                     (const struct _CERT_CHAIN_CONTEXT **)this + 130,
                                     &v25,
                                     &v27,
                                     1,
                                     1);
        if ( CredentialManagerForCert >= 0 )
          goto LABEL_44;
        CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 2);
        v22 = *((_DWORD *)this + 262);
      }
      if ( v22 == 2 )
      {
        CredentialManagerForCert = FindClientCertificate(
                                     this,
                                     v21,
                                     (const struct _CERT_CHAIN_CONTEXT **)this + 130,
                                     &v25,
                                     &v27,
                                     1,
                                     0);
        if ( CredentialManagerForCert >= 0 )
          goto LABEL_44;
        CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 3);
        v22 = *((_DWORD *)this + 262);
      }
      if ( v22 == 3 )
      {
        CredentialManagerForCert = FindClientCertificate(
                                     this,
                                     v21,
                                     (const struct _CERT_CHAIN_CONTEXT **)this + 130,
                                     &v25,
                                     &v27,
                                     0,
                                     1);
        if ( CredentialManagerForCert >= 0 )
          goto LABEL_44;
        CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 4);
        v22 = *((_DWORD *)this + 262);
      }
      if ( v22 != 4 )
      {
LABEL_43:
        CredentialManagerForCert = 590624;
        goto LABEL_44;
      }
      CredentialManagerForCert = FindClientCertificate(
                                   this,
                                   v21,
                                   (const struct _CERT_CHAIN_CONTEXT **)this + 130,
                                   &v25,
                                   &v27,
                                   0,
                                   0);
      if ( CredentialManagerForCert < 0 )
      {
        CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 5);
        goto LABEL_43;
      }
LABEL_44:
      CertCloseStore(v21, 0);
    }
  }
LABEL_45:
  if ( v27 )
    RevertToSelf();
  if ( v3 )
    SPExternalFree(v3);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        23i64,
        &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
        (unsigned int)CredentialManagerForCert);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
      && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && CredentialManagerForCert
       || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
    {
      LODWORD(pvPara) = CredentialManagerForCert;
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x18u,
        (__int64)&WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
        CredentialManagerForCert,
        pvPara);
    }
  }
  return (unsigned int)CredentialManagerForCert;
}
// 180057616: variable 'pvPara' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18008275C: using guessed type wchar_t aMy[3];

