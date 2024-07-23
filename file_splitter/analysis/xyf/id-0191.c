//----- (00000001800102DC) ----------------------------------------------------
__int64 __fastcall IsRemoteCertificateBlacklisted(
        struct _TLS_PARAMETERS *a1,
        unsigned int a2,
        const struct _CERT_CONTEXT *a3,
        struct _PUBLICKEY *a4,
        struct _SecPkgContext_ApplicationProtocol *a5,
        struct CCipherSuiteInfo *a6,
        unsigned __int8 a7)
{
  unsigned int v7; // ebx
  struct CEccCurveInfo *v11; // r13
  PCERT_INFO pCertInfo; // rdx
  unsigned int PublicKeyLength; // r12d
  int v15; // edi
  DWORD CngHashAndSignatureString; // eax
  __int64 v17; // r9
  unsigned int EccCurveType; // eax
  CCipherMill *v20; // rcx
  unsigned int CurveInfo; // eax
  ULONG v22; // eax
  CCipherMill *v23; // rcx
  __int64 v24; // rdx
  DWORD v25; // [rsp+20h] [rbp-E0h]
  bool v26; // [rsp+60h] [rbp-A0h]
  unsigned int v27; // [rsp+64h] [rbp-9Ch] BYREF
  unsigned int v28; // [rsp+68h] [rbp-98h]
  struct CEccCurveInfo *v29; // [rsp+70h] [rbp-90h] BYREF
  struct _UNICODE_STRING *v30; // [rsp+78h] [rbp-88h]
  struct _UNICODE_STRING v31; // [rsp+80h] [rbp-80h] BYREF
  struct _TLS_PARAMETERS *v32; // [rsp+90h] [rbp-70h]
  unsigned __int16 v33[64]; // [rsp+A0h] [rbp-60h] BYREF
  unsigned __int16 v34[64]; // [rsp+120h] [rbp+20h] BYREF
  char v35[512]; // [rsp+1A0h] [rbp+A0h] BYREF

  v7 = 0;
  v28 = a2;
  v32 = a1;
  v27 = 0;
  v29 = 0i64;
  v26 = 0;
  v11 = 0i64;
  memset_0(v34, 0, sizeof(v34));
  memset_0(v33, 0, sizeof(v33));
  memset_0(v35, 0, 0x1FEui64);
  *(_DWORD *)&v31.Length = 33423360;
  v31.Buffer = (PWSTR)v35;
  v30 = 0i64;
  if ( !a1 || !a2 || !a3 || !a6 || !a4 || !*(_QWORD *)a4 || !a3->pCertInfo )
    return 2148074244i64;
  pCertInfo = a3->pCertInfo;
  if ( a5
    && a5->ProtoNegoStatus == SecApplicationProtocolNegotiationStatus_Success
    && a5->ProtoNegoExt == SecApplicationProtocolNegotiationExt_ALPN )
  {
    v22 = CreateUnicodeStringFromAlpnId(a5->ProtocolId, a5->ProtocolIdSize, 1, &v31);
    v17 = v22;
    if ( v22 )
    {
      v23 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074244i64;
      v24 = 16i64;
      goto LABEL_38;
    }
    pCertInfo = a3->pCertInfo;
    v30 = &v31;
  }
  PublicKeyLength = CertGetPublicKeyLength(1u, &pCertInfo->SubjectPublicKeyInfo);
  v15 = *(_DWORD *)(*(_QWORD *)a4 + 4i64);
  if ( !PublicKeyLength || !v15 )
    return 2148074244i64;
  if ( v15 == 8707 )
  {
    EccCurveType = CertGetEccCurveType((__int64)a3, &v27);
    v17 = EccCurveType;
    if ( EccCurveType )
    {
      v23 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074244i64;
      v24 = 17i64;
      goto LABEL_38;
    }
    CurveInfo = CCipherMill::GetCurveInfo(v20, v27, &v29);
    v17 = CurveInfo;
    if ( CurveInfo )
    {
      v23 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074244i64;
      v24 = 18i64;
      goto LABEL_38;
    }
    v11 = v29;
  }
  v27 = 64;
  CngHashAndSignatureString = GetCngHashAndSignatureString(a3, v33, &v27, (char *)v34, v25);
  v17 = CngHashAndSignatureString;
  if ( CngHashAndSignatureString )
  {
    v23 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074244i64;
    v24 = 19i64;
LABEL_38:
    WPP_SF_D(*((_QWORD *)v23 + 2), v24, &WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids, v17);
    return 2148074244i64;
  }
  if ( !a7 && v15 == 41984 )
    v26 = *((_DWORD *)a6 + 8) == 41984;
  if ( IsCertificateBlacklisted(v32, v28, v15, PublicKeyLength, v11, v26, 0, v34, v33, v30, 1) )
    return (unsigned int)-2146893007;
  return v7;
}
// 18001042C: variable 'v25' is possibly undefined
// 1800104EC: variable 'v20' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

