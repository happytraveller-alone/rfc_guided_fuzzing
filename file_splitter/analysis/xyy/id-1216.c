//----- (0000000180060B8C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::GenerateCertVerify(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int *a3)
{
  __int64 v3; // rax
  wchar_t *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  int v11; // r12d
  __int64 v12; // r15
  __int64 v13; // rax
  __int64 v14; // rdx
  unsigned int v15; // ecx
  __int64 v16; // rax
  unsigned int v17; // r14d
  __int64 result; // rax
  unsigned int v19; // ecx
  int v20; // edx
  enum _eTlsHashAlgorithm v21; // eax
  char *v22; // rdi
  __int16 v23; // r12
  unsigned __int8 v24; // r9
  unsigned int v25; // edi
  int v26; // edx
  CSsl3TlsClientContext *v27; // rcx
  unsigned __int64 TlsClientAuthHandshakeHash; // rdi
  __int64 *v29; // rax
  __int64 v30; // rcx
  char v31; // cl
  unsigned int v32; // r14d
  unsigned int v33; // r14d
  unsigned int v34; // eax
  unsigned int *v35; // rcx
  unsigned int v36; // eax
  unsigned int *v37; // rcx
  size_t Size; // [rsp+70h] [rbp-69h] BYREF
  unsigned int v39; // [rsp+78h] [rbp-61h] BYREF
  unsigned int v40; // [rsp+7Ch] [rbp-5Dh] BYREF
  enum _eTlsHashAlgorithm v41; // [rsp+80h] [rbp-59h] BYREF
  wchar_t *String1; // [rsp+88h] [rbp-51h]
  LPCWSTR v43; // [rsp+90h] [rbp-49h] BYREF
  unsigned int *v44; // [rsp+98h] [rbp-41h]
  void *v45; // [rsp+A0h] [rbp-39h]
  BYTE Src[64]; // [rsp+B0h] [rbp-29h] BYREF

  v3 = *((_QWORD *)this + 10);
  Size = 0i64;
  v44 = a3;
  v7 = 0i64;
  v45 = *(void **)(v3 + 752);
  v8 = *(_QWORD *)this;
  v40 = 32772;
  String1 = 0i64;
  v43 = 0i64;
  v9 = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *))(v8 + 248))(this);
  v11 = 0;
  v39 = 0;
  v12 = v9;
  v13 = *(_QWORD *)(v9 + 432);
  if ( v13 )
  {
    v14 = 118i64;
    v15 = *(_DWORD *)(v13 + 8) + 2;
    if ( v15 > 0x76 )
      v14 = v15;
  }
  else
  {
    v16 = *(_QWORD *)(v12 + 32);
    if ( v16 )
      v14 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v16 + 24) + 120i64) + 52);
    else
      v14 = 68i64;
  }
  v17 = v14 + 2;
  if ( (*((_DWORD *)this + 16) & 0x80800) == 0 )
    v17 = v14;
  result = 0i64;
  if ( !a2 )
  {
    *a3 = v17;
    return result;
  }
  if ( *((_QWORD *)this + 117) && !*((_BYTE *)this + 1032) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 46i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    v19 = *((_DWORD *)this + 236);
    HIDWORD(Size) = v17 - 2;
    if ( v19 <= v17 - 2 )
    {
      memcpy_0(a2 + 2, *((const void **)this + 117), v19);
      v20 = *((_DWORD *)this + 236);
LABEL_70:
      a2[v11] = BYTE1(v20);
      v35 = v44;
      a2[v11 + 1] = v20;
      *v35 = v11 + v20 + 2;
      return 0i64;
    }
    goto LABEL_57;
  }
  switch ( *(_DWORD *)(v12 + 132) )
  {
    case 0x2200:
      v7 = (wchar_t *)L"DSA";
      goto LABEL_26;
    case 0x2203:
      v7 = (wchar_t *)L"ECDSA";
LABEL_26:
      LODWORD(Size) = 20;
      goto LABEL_27;
    case 0x2400:
    case 0xA400:
      v7 = (wchar_t *)L"RSA";
      v40 = 32776;
      LODWORD(Size) = 36;
      v39 = 2;
LABEL_27:
      String1 = v7;
      break;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_S(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Fu, (__int64)&WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids, v7);
  if ( (*((_DWORD *)this + 16) & 0x80800) != 0 )
  {
    v21 = (unsigned int)ConvertCertificateAlgToTlsSignatureAlgorithm(*(_DWORD *)(v12 + 132), v14, v10);
    v41 = v21;
    v22 = (char *)this + 510;
    if ( *(_QWORD *)(v12 + 112) )
    {
      v22 = (char *)operator new(0x24ui64);
      if ( v22 )
      {
        *(_OWORD *)(v22 + 2) = 0i64;
        *(_OWORD *)(v22 + 18) = 0i64;
        *(_WORD *)v22 = 0;
        *((_WORD *)v22 + 17) = 0;
      }
      else
      {
        v22 = 0i64;
      }
      CTlsSignatureSuiteList::SetDefaultClientHello((CTlsSignatureSuiteList *)v22);
      CTlsSignatureSuiteList::Restrict(
        (CTlsSignatureSuiteList *)v22,
        (CSsl3TlsClientContext *)((char *)this + 510),
        *((_DWORD *)this + 16));
      v21 = v41;
    }
    v23 = __ROR2__(
            CTlsSignatureSuiteList::GetMinimumCodePointToSign(
              (CTlsSignatureSuiteList *)v22,
              (enum _eTlsSignatureAlgorithm)v21,
              *(_DWORD *)(v12 + 428),
              *((_DWORD *)this + 16),
              0),
            8);
    if ( *(_QWORD *)(v12 + 112) && v22 )
      operator delete(v22);
    if ( !v23 )
    {
      v24 = 40;
      v25 = -2146893007;
      v26 = 304;
LABEL_42:
      v27 = this;
LABEL_43:
      CSslContext::SetErrorAndFatalAlert((__int64)v27, v26, v25, v24);
      return v25;
    }
    GetSignatureSuiteInfoByCodePoint(v23, 0i64, &v41, &v40, &v43, (unsigned int *)&Size, &v39);
    TlsClientAuthHandshakeHash = CSsl3TlsContext::FindTlsClientAuthHandshakeHash(this, v41);
    if ( !TlsClientAuthHandshakeHash || v17 < 2 )
    {
      v24 = 80;
      v25 = 1359;
      v26 = 304;
      goto LABEL_43;
    }
    *(_WORD *)a2 = v23;
    v11 = 2;
  }
  else
  {
    TlsClientAuthHandshakeHash = *((_QWORD *)this + 74);
  }
  RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u);
  v29 = (__int64 *)*((_QWORD *)this + 1);
  if ( v29 )
    v30 = *v29;
  else
    v30 = 0i64;
  v25 = SslComputeClientAuthHash(
          v30,
          *(_QWORD *)(*((_QWORD *)this + 165) + 16i64),
          TlsClientAuthHandshakeHash,
          String1,
          Src,
          Size,
          &Size,
          0);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
  if ( v25 )
  {
    v24 = 80;
    v26 = 300;
    goto LABEL_42;
  }
  v31 = *((_BYTE *)this + 1032);
  v32 = v17 - v11 - 2;
  HIDWORD(Size) = v32;
  if ( v31 )
  {
    if ( *((_DWORD *)this + 236) > v32 )
    {
LABEL_57:
      v24 = 80;
      v25 = -2146893018;
      v26 = 302;
      goto LABEL_42;
    }
    memcpy_0(&a2[v11 + 2], *((const void **)this + 117), *((unsigned int *)this + 236));
    v31 = *((_BYTE *)this + 1032);
  }
  v33 = v40;
  v34 = SignHashUsingCred(
          this,
          (struct CSslCredential *)v12,
          v45,
          v40,
          v39,
          String1,
          v43,
          Src,
          Size,
          &a2[v11 + 2],
          (DWORD *)&Size + 1,
          v31,
          *((_DWORD *)this + 236));
  v25 = v34;
  if ( v34 != -1073741168 && v34 != -2146893790 )
  {
    if ( v34 == 590610 )
    {
      if ( *((_BYTE *)this + 266) )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 49i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        *((_DWORD *)this + 17) = 77;
        return 590610i64;
      }
    }
    else if ( !v34 )
    {
      v20 = HIDWORD(Size);
      goto LABEL_70;
    }
    v24 = 80;
    v26 = 301;
    goto LABEL_42;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 48i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
  if ( (*((_DWORD *)this + 16) & 0x80800) != 0 )
  {
    v25 = -2146893043;
    CSslContext::SetError((__int64)this, 303, -2146893043);
    return v25;
  }
  v36 = Size;
  *((_DWORD *)a2 + 1) = v33;
  *(_DWORD *)a2 = 68;
  *((_DWORD *)a2 + 2) = v36;
  memcpy_0(a2 + 12, Src, v36);
  v37 = v44;
  *((_OWORD *)a2 + 3) = *(_OWORD *)(v12 + 40);
  *((_DWORD *)a2 + 16) = *(_DWORD *)(v12 + 56);
  result = 590684i64;
  *v37 = 68;
  return result;
}
// 180060D7D: variable 'v14' is possibly undefined
// 180060D7D: variable 'v10' is possibly undefined
// 180060E2C: variable 'v27' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098588: using guessed type __int64 __fastcall SslComputeClientAuthHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
