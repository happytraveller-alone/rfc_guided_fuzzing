// File count: 1365
// Total lines: 390
---------------------------------------
__int64 __fastcall CTls13ServerContext::GenerateClientHelloResponse(CTls13ServerContext *this, struct SPBuffer *a2)
{
  __int64 *v2; // rax
  struct SPBuffer *v3; // r14
  __int64 v5; // r13
  unsigned int inited; // edi
  int v7; // edx
  CTls13ServerContext *v8; // rcx
  int v10; // edi
  unsigned int OutputBuffer; // esi
  int v12; // edx
  __int64 v13; // rcx
  __int64 v14; // rax
  int v15; // r14d
  __int64 v16; // rax
  __int64 v17; // r13
  __int64 v18; // rax
  __int64 v19; // rsi
  void *v20; // rcx
  PCCERT_SERVER_OCSP_RESPONSE_CONTEXT ServerOcspResponseContext; // rax
  DWORD LastError; // eax
  __int64 v23; // rax
  unsigned __int8 v24; // di
  int v25; // eax
  __int64 v26; // rcx
  bool v27; // zf
  __int64 v28; // rax
  unsigned int v29; // ecx
  __int64 *v30; // r14
  _QWORD *v31; // r12
  char v32; // cl
  __int64 v33; // rax
  __int64 v34; // rcx
  char v35; // cl
  char v36[8]; // [rsp+50h] [rbp-79h] BYREF
  __int64 v37; // [rsp+58h] [rbp-71h] BYREF
  unsigned int v38; // [rsp+60h] [rbp-69h] BYREF
  __int64 v39; // [rsp+68h] [rbp-61h]
  struct SPBuffer *v40; // [rsp+70h] [rbp-59h]
  unsigned __int16 v41[2]; // [rsp+80h] [rbp-49h] BYREF
  int v42; // [rsp+84h] [rbp-45h]
  int v43; // [rsp+88h] [rbp-41h]
  __int16 v44; // [rsp+8Ch] [rbp-3Dh] BYREF
  int v45; // [rsp+90h] [rbp-39h]
  int v46; // [rsp+94h] [rbp-35h]
  __int16 v47; // [rsp+98h] [rbp-31h]
  int v48; // [rsp+9Ch] [rbp-2Dh]
  int v49; // [rsp+A0h] [rbp-29h]
  __int16 v50; // [rsp+A4h] [rbp-25h]
  int v51; // [rsp+A8h] [rbp-21h]
  int v52; // [rsp+ACh] [rbp-1Dh]
  __int16 v53; // [rsp+B0h] [rbp-19h]
  int v54; // [rsp+B4h] [rbp-15h]
  int v55; // [rsp+B8h] [rbp-11h]
  __int16 v56; // [rsp+BCh] [rbp-Dh]
  int v57; // [rsp+C0h] [rbp-9h]
  int v58; // [rsp+C4h] [rbp-5h]
  __int16 v59; // [rsp+C8h] [rbp-1h]
  int v60; // [rsp+CCh] [rbp+3h]
  int v61; // [rsp+D0h] [rbp+7h]

  v2 = (__int64 *)*((_QWORD *)this + 1);
  v40 = a2;
  v3 = a2;
  if ( v2 )
    v5 = *v2;
  else
    v5 = 0i64;
  v39 = v5;
  v41[0] = 0;
  v42 = 22;
  v43 = 1;
  v44 = 0;
  v46 = 3;
  v49 = 3;
  v52 = 3;
  v55 = 3;
  v58 = 3;
  v61 = 3;
  v45 = 22;
  v47 = 0;
  v48 = 22;
  v50 = 0;
  v51 = 22;
  v53 = 0;
  v54 = 22;
  v56 = 0;
  v57 = 22;
  v59 = 0;
  v60 = 22;
  v36[0] = 1;
  inited = CTls13ServerHandshake::ComputeServerHelloOrHRRSize((CTls13ServerContext *)((char *)this + 1288), v5, 1, v41);
  if ( inited
    || (inited = CTls13Context::SetCcsRecordInfo(
                   (CTls13ServerContext *)((char *)this + 1000),
                   (struct CTlsRecord::CMessageInfo *)&v44,
                   v36)) != 0 )
  {
    v7 = 1253;
LABEL_6:
    v8 = this;
LABEL_7:
    CSslContext::SetError((__int64)v8, v7, inited);
    return inited;
  }
  v10 = (unsigned __int8)(v36[0] + 1);
  OutputBuffer = CTls13ServerHandshake::ComputeEncryptedExtensionsMsgSize(
                   (CTls13ServerContext *)((char *)this + 1288),
                   &v41[6 * (unsigned __int8)v36[0]]);
  if ( OutputBuffer )
  {
LABEL_10:
    v12 = 1253;
LABEL_11:
    CSslContext::SetError((__int64)this, v12, OutputBuffer);
    return OutputBuffer;
  }
  v13 = *((_QWORD *)this + 17);
  if ( (v13 & 0x8000) != 0 )
  {
    v14 = *((_QWORD *)this + 1);
    v36[0] = 0;
    if ( !v14 )
      return 1359i64;
    v15 = *(_DWORD *)(v14 + 48);
    if ( (v13 & 0x100) != 0 && v15 != 4 )
    {
      v16 = (unsigned __int8)v10;
      LOBYTE(v10) = v10 + 1;
      OutputBuffer = CTls13ServerHandshake::ComputeCertificateRequestSize(
                       (CTls13ServerContext *)((char *)this + 1288),
                       &v41[6 * v16]);
      if ( OutputBuffer )
        goto LABEL_10;
    }
    v17 = *((_QWORD *)this + 10);
    if ( !v17 )
      return 1359i64;
    v18 = *(_QWORD *)this;
    v37 = 0i64;
    (*(void (__fastcall **)(CTls13ServerContext *, __int64 *))(v18 + 232))(this, &v37);
    if ( !v37 )
      return 1359i64;
    RtlAcquireResourceShared((PRTL_RESOURCE)(v37 + 72), 1u);
    v19 = *(_QWORD *)(v37 + 336);
    if ( !v19 )
    {
      RtlReleaseResource((PRTL_RESOURCE)(v37 + 72));
      return 1359i64;
    }
    if ( (*((_DWORD *)this + 34) & 0x20000) != 0 )
    {
      v20 = *(void **)(v19 + 456);
      if ( v20 )
      {
        if ( v15 != 4 )
        {
          ServerOcspResponseContext = CertGetServerOcspResponseContext(v20, 0, 0i64);
          *((_QWORD *)this + 189) = ServerOcspResponseContext;
          if ( !ServerOcspResponseContext
            && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            LastError = GetLastError();
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              59i64,
              &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
              LastError);
          }
        }
      }
    }
    v23 = (unsigned __int8)v10;
    v24 = v10 + 1;
    OutputBuffer = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeCertificateMsgSize(
                     (__int64)this + 1288,
                     v19,
                     *(_BYTE *)(v17 + 156) & 0x80,
                     &v41[6 * v23]);
    RtlReleaseResource((PRTL_RESOURCE)(v37 + 72));
    if ( OutputBuffer )
      goto LABEL_10;
    v25 = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateVerifySize(
            (__int64)this + 1288,
            &v41[6 * v24]);
    LOBYTE(v10) = v24 + 1;
    OutputBuffer = v25;
    if ( v25 )
      goto LABEL_10;
    v5 = v39;
    v3 = v40;
  }
  else
  {
    v36[0] = 1;
  }
  OutputBuffer = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeFinishedSize(
                   (__int64)this + 1288,
                   (__int64)&v41[6 * (unsigned __int8)v10]);
  if ( OutputBuffer )
    goto LABEL_10;
  v26 = *((_QWORD *)this + 151);
  v38 = 0;
  inited = (*(__int64 (__fastcall **)(__int64, _QWORD, unsigned __int16 *, unsigned int *))(*(_QWORD *)v26 + 16i64))(
             v26,
             (unsigned __int8)(v10 + 1),
             v41,
             &v38);
  v8 = this;
  if ( inited )
  {
    v7 = 1254;
    goto LABEL_7;
  }
  OutputBuffer = CSsl3TlsContext::AllocateOutputBuffer(this, v3, v38);
  if ( OutputBuffer )
    goto LABEL_37;
  OutputBuffer = (*(__int64 (__fastcall **)(_QWORD, struct SPBuffer *))(**((_QWORD **)this + 151) + 24i64))(
                   *((_QWORD *)this + 151),
                   v3);
  if ( OutputBuffer )
    goto LABEL_37;
  if ( *((_DWORD *)this + 17) == 93 )
  {
    inited = CSsl3TlsServerContext::InitUpdateClientHash(this);
  }
  else
  {
    inited = (*(__int64 (__fastcall **)(CTls13ServerContext *, _QWORD, _QWORD, _QWORD))(*(_QWORD *)this + 504i64))(
               this,
               *((_QWORD *)this + 110),
               *((unsigned int *)this + 218),
               0i64);
    if ( *((_QWORD *)this + 110) )
    {
      (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 16i64))(this);
      *((_QWORD *)this + 110) = 0i64;
    }
    *((_DWORD *)this + 218) = 0;
  }
  if ( inited )
  {
    v7 = 1007;
    goto LABEL_6;
  }
  if ( this == (CTls13ServerContext *)-304i64 )
  {
    CSslContext::SetError(-304i64, 1255, 1359);
    return 1359i64;
  }
  OutputBuffer = CTls13ServerHandshake::GenerateServerHelloOrHRR(
                   (CTls13ServerContext *)((char *)this + 1288),
                   1,
                   (unsigned __int8 *)this + 304);
  if ( OutputBuffer )
  {
LABEL_37:
    v12 = 1255;
    goto LABEL_11;
  }
  v27 = (*((_BYTE *)this + 32) & 1) == 0;
  LODWORD(v37) = 1255;
  if ( v27 || (v28 = *((_QWORD *)this + 1)) == 0 )
    v29 = 0;
  else
    v29 = *(_DWORD *)(v28 + 28);
  v30 = (__int64 *)((char *)this + 168);
  v31 = (_QWORD *)((char *)this + 160);
  OutputBuffer = CTls13Context::GenerateHandshakeWriteKeys(
                   (CTls13ServerContext *)((char *)this + 1000),
                   v5,
                   *((_QWORD *)this + 14),
                   *((_QWORD *)this + 74),
                   *((_WORD *)this + 17),
                   v29,
                   v36[0],
                   (unsigned __int64 *)this + 20,
                   (unsigned __int64 *)this + 21,
                   (enum eSslErrorState *)&v37);
  if ( OutputBuffer )
  {
    v12 = v37;
    goto LABEL_11;
  }
  v32 = *((_BYTE *)this + 233);
  *((_WORD *)this + 16) |= 0xCu;
  if ( !v32 && *((_QWORD *)this + 19) )
  {
    SslFreeObject(*((_QWORD *)this + 19), 0i64);
    v32 = *((_BYTE *)this + 233);
  }
  v33 = *v30;
  *v30 = 0i64;
  *((_QWORD *)this + 19) = v33;
  if ( !v32 )
    *((_QWORD *)this + 23) = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  *((_BYTE *)this + 1216) = 2;
  OutputBuffer = CTls13Context::GenerateCcsRecord((CTls13ServerContext *)((char *)this + 1000));
  if ( OutputBuffer
    || (OutputBuffer = CTls13ServerHandshake::GenerateEncryptedExtensionsMsg((CTls13ServerContext *)((char *)this + 1288))) != 0
    || !v36[0]
    && ((*((_DWORD *)this + 34) & 0x100i64) != 0
     && *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) != 4
     && (OutputBuffer = CTls13ServerHandshake::GenerateCertificateRequest((CTls13ServerContext *)((char *)this + 1288))) != 0
     || (OutputBuffer = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateCertificateMsg((__int64)this + 1288)) != 0
     || (OutputBuffer = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateCertificateVerify((__int64)this + 1288)) != 0)
    || (OutputBuffer = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateFinished((__int64)this + 1288)) != 0 )
  {
    v12 = 1255;
    goto LABEL_11;
  }
  *((_WORD *)this + 16) |= 0xAu;
  v34 = *((_QWORD *)this + 18);
  if ( v34 )
    SslFreeObject(v34, 0i64);
  *((_QWORD *)this + 18) = *v31;
  *v31 = 0i64;
  if ( !*((_BYTE *)this + 233) )
    *((_QWORD *)this + 22) = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  inited = CTls13Context::GenerateApplicationWriteKeys(
             (CTls13ServerContext *)((char *)this + 1000),
             v5,
             *((_QWORD *)this + 74),
             (unsigned __int64 *)this + 20,
             (unsigned __int64 *)this + 21,
             (enum eSslErrorState *)&v37);
  if ( inited )
  {
    v7 = v37;
    goto LABEL_6;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 384i64))(this) )
  {
    inited = CTls13Context::PopulateSecTrafficSecret(
               (__int64)this + 1000,
               v5,
               1,
               2u,
               *((_QWORD *)this + 1),
               v41[0],
               *((_WORD *)v40 + 2));
    if ( inited )
    {
      v7 = 610;
      goto LABEL_6;
    }
    inited = CTls13Context::PopulateSecTrafficSecret((__int64)this + 1000, v5, 0, 2u, *((_QWORD *)this + 1), 0, 0);
    if ( inited )
    {
      v7 = 609;
      goto LABEL_6;
    }
    inited = CTls13Context::PopulateSecTrafficSecret((__int64)this + 1000, v5, 1, 3u, *((_QWORD *)this + 1), 0, 0);
    if ( inited )
    {
      v7 = 612;
      goto LABEL_6;
    }
  }
  v35 = *((_BYTE *)this + 233);
  *((_WORD *)this + 16) |= 0xCu;
  if ( !v35 )
  {
    v35 = 0;
    if ( *((_QWORD *)this + 19) )
    {
      SslFreeObject(*((_QWORD *)this + 19), 0i64);
      v35 = *((_BYTE *)this + 233);
    }
  }
  *((_QWORD *)this + 19) = *v30;
  *v30 = 0i64;
  if ( !v35 )
    *((_QWORD *)this + 23) = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  *((_BYTE *)this + 1216) = 3;
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 18006BC00: using guessed type char var_D0[8];
