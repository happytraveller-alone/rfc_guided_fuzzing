// File count: 1337
// Total lines: 95
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseCertificateVerify(
        __int64 a1,
        __int64 a2,
        unsigned int a3)
{
  __int64 v5; // rcx
  unsigned __int8 v6; // r9
  int v7; // edx
  unsigned int EccCurveType; // ebx
  __int64 v10; // rbx
  unsigned int v11; // esi
  CTlsSignatureSuiteList *v12; // r13
  __int16 v13; // r14
  __int64 v14; // rbx
  struct _RTL_RESOURCE *v15; // r15
  __int64 v16; // r12
  bool v17; // zf
  __int64 v18; // r15
  enum _eTlsSignatureAlgorithm v19; // [rsp+78h] [rbp+10h] BYREF

  if ( !a2 || !a3 )
    return 87i64;
  if ( a3 < 2 )
  {
    v5 = *(_QWORD *)(a1 + 8);
    v6 = 50;
    v7 = 1305;
LABEL_5:
    EccCurveType = -2146893048;
    CSslContext::SetErrorAndFatalAlert(v5, v7, -2146893048, v6);
    return EccCurveType;
  }
  v10 = *(_QWORD *)(a1 + 8);
  v11 = a3 - 2;
  v12 = (CTlsSignatureSuiteList *)(v10 + 474);
  v13 = *(_WORD *)a2;
  if ( v10 == -474 )
    return 1359i64;
  v14 = *(_QWORD *)(v10 + 88);
  if ( !v14 )
    return 1359i64;
  v15 = (struct _RTL_RESOURCE *)(v14 + 72);
  RtlAcquireResourceShared((PRTL_RESOURCE)(v14 + 72), 1u);
  v16 = *(_QWORD *)(v14 + 48);
  if ( !v16 )
  {
    EccCurveType = 1359;
LABEL_14:
    RtlReleaseResource(v15);
    return EccCurveType;
  }
  EccCurveType = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::DetermineCertVerifySignatureAlgorithm(
                   a1,
                   *(const struct _CERT_CONTEXT **)(v14 + 48));
  if ( EccCurveType )
    goto LABEL_14;
  v17 = *(_DWORD *)(a1 + 104) == 3;
  v19 = TlsSignatureAlgorithm_Anonymous;
  if ( v17 )
  {
    EccCurveType = CertGetEccCurveType(v16, (unsigned int *)&v19);
    if ( EccCurveType )
      goto LABEL_14;
  }
  RtlReleaseResource(v15);
  v18 = *(_QWORD *)(a1 + 8);
  if ( !CTlsSignatureSuiteList::IsSupportedCodePoint(v12, v13) )
  {
    v6 = 47;
    v7 = 1307;
    v5 = v18;
    goto LABEL_5;
  }
  v19 = TlsSignatureAlgorithm_Anonymous;
  GetSignatureSuiteInfoByCodePoint(
    v13,
    &v19,
    (enum _eTlsHashAlgorithm *)(a1 + 100),
    0i64,
    (const unsigned __int16 **)(a1 + 112),
    0i64,
    0i64);
  if ( v19 == TlsSignatureAlgorithm_Anonymous
    || v19 != *(_DWORD *)(a1 + 104)
    || !*(_DWORD *)(a1 + 100)
    || !*(_QWORD *)(a1 + 112) )
  {
    v5 = *(_QWORD *)(a1 + 8);
    v6 = 40;
    v7 = 1307;
    goto LABEL_5;
  }
  return CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::VerifySignature(a1, (unsigned __int8 *)(a2 + 2), v11);
}
