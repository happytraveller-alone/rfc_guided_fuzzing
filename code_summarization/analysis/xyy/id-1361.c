//----- (000000018006B424) ----------------------------------------------------
__int64 __fastcall CTls13ClientContext::GenerateCertVerifyHashForRemoteSigning(CTls13ClientContext *this)
{
  __int64 v1; // rsi
  __int64 v2; // rax
  char *v4; // r14
  unsigned int CertificateMsg; // eax
  unsigned int v6; // ebx
  int v7; // r8d
  __int64 v8; // rcx
  __int16 v9; // cx
  const WCHAR *lpString; // r15
  size_t Size; // [rsp+48h] [rbp-71h]
  ULONG v13; // [rsp+60h] [rbp-59h] BYREF
  unsigned int v14; // [rsp+64h] [rbp-55h] BYREF
  enum _eTlsHashAlgorithm v15; // [rsp+68h] [rbp-51h] BYREF
  unsigned int v16; // [rsp+6Ch] [rbp-4Dh] BYREF
  unsigned int v17; // [rsp+70h] [rbp-49h] BYREF
  LPCWSTR v18; // [rsp+78h] [rbp-41h] BYREF
  void *v19[2]; // [rsp+80h] [rbp-39h] BYREF
  __int16 v20[2]; // [rsp+90h] [rbp-29h] BYREF
  int v21; // [rsp+94h] [rbp-25h]
  int v22; // [rsp+98h] [rbp-21h]
  unsigned __int8 Src[64]; // [rsp+A0h] [rbp-19h] BYREF

  v1 = *((_QWORD *)this + 116);
  v2 = *((_QWORD *)this + 10);
  v20[0] = 0;
  v21 = 22;
  v22 = 1;
  *(_OWORD *)v19 = 0i64;
  if ( !v1 || !v2 || !*(_BYTE *)(v1 + 78) || *(_BYTE *)(v1 + 79) )
    goto LABEL_20;
  v4 = (char *)this + 1656;
  CertificateMsg = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateMsgSize(
                     (__int64)this + 1656,
                     v1,
                     *(_BYTE *)(v2 + 156) & 0x80,
                     v20);
  v6 = CertificateMsg;
  if ( CertificateMsg )
    goto LABEL_6;
  v8 = *((_QWORD *)this + 197);
  v14 = 0;
  CertificateMsg = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *, unsigned int *))(*(_QWORD *)v8 + 16i64))(
                     v8,
                     1i64,
                     v20,
                     &v14);
  v6 = CertificateMsg;
  if ( CertificateMsg )
    goto LABEL_6;
  LODWORD(v19[0]) = v14;
  v19[1] = SPExternalAlloc(v14);
  if ( !v19[1] )
  {
    v6 = -2146893056;
    v7 = -2146893056;
    goto LABEL_7;
  }
  CertificateMsg = (*(__int64 (__fastcall **)(_QWORD, void **))(**((_QWORD **)this + 197) + 24i64))(
                     *((_QWORD *)this + 197),
                     v19);
  v6 = CertificateMsg;
  if ( CertificateMsg
    || (CertificateMsg = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateMsg((__int64)v4),
        (v6 = CertificateMsg) != 0)
    || (CertificateMsg = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::DetermineCertVerifyCodePoint((__int64)v4),
        (v6 = CertificateMsg) != 0) )
  {
LABEL_6:
    v7 = CertificateMsg;
LABEL_7:
    CSslContext::SetError((__int64)this, 155, v7);
    goto LABEL_21;
  }
  v9 = *((_WORD *)this + 888);
  v15 = TlsHashAlgorithm_None;
  v13 = 0;
  v17 = 0;
  v18 = 0i64;
  v16 = 0;
  GetSignatureSuiteInfoByCodePoint(v9, (enum _eTlsSignatureAlgorithm *)&v13, &v15, &v17, &v18, 0i64, &v16);
  if ( v13 == 1 )
  {
    lpString = L"RSA";
    goto LABEL_18;
  }
  if ( v13 != 3 )
  {
LABEL_20:
    v6 = -2146893052;
    goto LABEL_21;
  }
  lpString = L"ECDSA";
LABEL_18:
  memset_0(Src, 0, sizeof(Src));
  v13 = 0;
  v6 = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertVerifyContentHash(
         (__int64)v4,
         0,
         v15,
         0i64,
         Src,
         0x40u,
         &v13);
  if ( !v6 )
  {
    LODWORD(Size) = v13;
    v6 = RemotelySignHash(
           0i64,
           *((_QWORD *)this + 13),
           *(_QWORD *)(v1 + 104),
           *(_DWORD *)(v1 + 128),
           v17,
           v16,
           lpString,
           v18,
           Src,
           Size);
  }
LABEL_21:
  if ( v19[1] )
    SPExternalFree(v19[1]);
  return v6;
}
// 18006B667: variable 'Size' is possibly undefined
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

