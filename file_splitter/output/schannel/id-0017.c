// File count: 17
// Total lines: 463
-----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::GenerateServerHelloResponse(CSsl3TlsClientContext *this, struct SPBuffer *a2)
{
  unsigned int v4; // ebp
  unsigned int v5; // esi
  char v6; // r8
  int v7; // r14d
  __int64 v8; // rax
  __int64 v9; // r12
  unsigned int v10; // r13d
  char v11; // r11
  __int16 v12; // r10
  int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // r8d
  int v16; // ecx
  int v17; // ecx
  int v18; // r8d
  unsigned int v19; // r9d
  unsigned int v20; // r8d
  int v21; // r9d
  unsigned int v22; // r9d
  unsigned int v23; // r10d
  unsigned int OutputBuffer; // ebx
  unsigned int v25; // r14d
  unsigned int v26; // ecx
  __int64 v27; // rax
  __int16 v28; // r12
  _BYTE *v29; // rsi
  unsigned int v30; // r9d
  __int16 *v31; // rbp
  __int16 v32; // cx
  const void *v33; // r8
  __int64 v34; // r9
  unsigned __int8 *v35; // rsi
  unsigned int v36; // r14d
  __int64 v37; // rax
  __int64 v38; // rbx
  __int64 v39; // rax
  unsigned int CcsAndFinishMessage; // eax
  __int64 v42; // rbx
  int UserMappingDataMsg; // esi
  int v44; // edx
  int v45; // r8d
  CSsl3TlsClientContext *v46; // rcx
  __int64 v47; // rdx
  unsigned int v48; // ebx
  int v49; // ecx
  unsigned int v50; // r8d
  unsigned int v51; // ecx
  __int64 v52; // rcx
  int v53; // eax
  unsigned int v54; // r14d
  __int64 v55; // r9
  size_t v56; // r8
  unsigned int v57; // ebp
  bool v58; // zf
  unsigned int v59; // edx
  unsigned int v60; // ebp
  __int64 v61; // r9
  __int64 v62; // rax
  unsigned int CertVerify; // eax
  int v64; // edi
  int v65; // ebx
  __int64 v66; // r9
  int v67; // ebp
  __int16 v68; // cx
  _BYTE *v69; // rdx
  int v70; // eax
  unsigned int v71; // [rsp+30h] [rbp-68h] BYREF
  unsigned int v72; // [rsp+34h] [rbp-64h]
  int v73; // [rsp+38h] [rbp-60h]
  void *Src; // [rsp+40h] [rbp-58h]
  struct _UNICODE_STRING DestinationString; // [rsp+48h] [rbp-50h] BYREF
  size_t Size; // [rsp+A0h] [rbp+8h] BYREF
  unsigned int v77; // [rsp+B0h] [rbp+18h]
  unsigned int v78; // [rsp+B8h] [rbp+20h]

  v78 = 0;
  v4 = 0;
  v71 = 0;
  v5 = 0;
  v6 = *((_BYTE *)this + 233);
  v7 = 0;
  Src = 0i64;
  v77 = 0;
  v8 = *((_QWORD *)this + 1);
  v72 = 0;
  LODWORD(Size) = 0;
  v9 = v6 != 0 ? 13 : 5;
  v73 = v6 != 0 ? 13 : 5;
  v10 = v6 != 0 ? 12 : 4;
  if ( *(_DWORD *)(v8 + 48) == 4 )
  {
    if ( !*((_QWORD *)this + 106) )
      return 590624;
    goto LABEL_3;
  }
  if ( !*((_BYTE *)this + 1315) )
  {
LABEL_3:
    if ( (*((_DWORD *)this + 16) & 0x80800) != 0 )
      CSsl3TlsContext::FreeTlsClientAuthHandshakeHashes(this);
    goto LABEL_5;
  }
  v42 = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)this + 248i64))(this);
  if ( v42 )
  {
    if ( *((_BYTE *)this + 922) )
    {
      UserMappingDataMsg = CreateUserMappingDataMsg(
                             0i64,
                             0,
                             *(unsigned __int16 **)(*((_QWORD *)this + 10) + 872i64),
                             *(unsigned __int16 **)(*((_QWORD *)this + 10) + 880i64));
      if ( !UserMappingDataMsg )
      {
        OutputBuffer = 1359;
        v44 = 151;
        v45 = 1359;
        goto LABEL_117;
      }
      v5 = v10 + UserMappingDataMsg;
      v72 = v5;
    }
    v4 = *(_DWORD *)(v42 + 448);
    v46 = this;
    Src = *(void **)(v42 + 440);
    v77 = v4;
    if ( v4 > 0x3FFF )
    {
      OutputBuffer = 1359;
      v44 = 150;
      v45 = 1359;
LABEL_118:
      CSslContext::SetErrorAndFatalAlert((__int64)v46, v44, v45, 0x50u);
      return OutputBuffer;
    }
    LODWORD(Size) = v4 + v10 + 3;
    OutputBuffer = CSsl3TlsClientContext::GenerateCertVerify(this, 0i64, &v71);
    if ( OutputBuffer )
      return OutputBuffer;
    v78 = v10 + v71;
  }
  else
  {
    v47 = *((_QWORD *)this + 10);
    v48 = *(_DWORD *)(v47 + 212);
    if ( (g_dwEventLogging & 2) != 0 )
    {
      RtlInitUnicodeString(&DestinationString, (PCWSTR)(v47 + 216));
      SchEventWrite(&SSLEVENT_NO_CLIENT_CERT_FOUND, L"du", v48, &DestinationString);
    }
    if ( (*((_BYTE *)this + 64) & 0x30) != 0 )
    {
      v49 = 2;
      if ( (*((_BYTE *)this + 32) & 4) != 0 )
      {
        v50 = *((_DWORD *)this + 13);
        v51 = *((_DWORD *)this + 12) + 2;
        if ( v50 )
        {
          if ( (*((_BYTE *)this + 56) & 1) != 0 )
            v50 -= v51 % v50;
          v51 += v50;
        }
        v49 = *((_DWORD *)this + 11) + v51;
      }
      v7 = v49 + *((_DWORD *)this + 15);
    }
    else
    {
      LODWORD(Size) = v10 + 3;
    }
  }
LABEL_5:
  v11 = *((_BYTE *)this + 233);
  v12 = *((_WORD *)this + 16);
  v13 = v5 + v78 + Size + v10 + *((_DWORD *)this + 240);
  if ( v11 )
  {
    v16 = v9 + v13;
  }
  else
  {
    if ( (v12 & 4) != 0 )
    {
      v14 = *((_DWORD *)this + 12) + v13;
      v15 = *((_DWORD *)this + 13);
      if ( v15 )
      {
        if ( (*((_BYTE *)this + 56) & 1) != 0 )
          v15 -= v14 % v15;
        v14 += v15;
      }
      v13 = *((_DWORD *)this + 11) + v14;
    }
    v16 = *((_DWORD *)this + 15) + v13;
  }
  v17 = v7 + v16;
  v18 = 1;
  if ( (v12 & 4) != 0 )
  {
    v19 = *((_DWORD *)this + 13);
    v20 = *((_DWORD *)this + 12) + 1;
    if ( v19 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v19 -= v20 % v19;
      v20 += v19;
    }
    v18 = *((_DWORD *)this + 11) + v20;
  }
  if ( (*((_BYTE *)this + 64) & 0x30) != 0 )
    v21 = v11 != 0 ? 48 : 40;
  else
    v21 = v11 != 0 ? 24 : 16;
  if ( (v12 & 1) != 0 )
  {
    v22 = *((_DWORD *)this + 12) + v21;
    v23 = *((_DWORD *)this + 13);
    if ( v23 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v23 -= v22 % v23;
      v22 += v23;
    }
    v21 = *((_DWORD *)this + 11) + v22;
  }
  OutputBuffer = CSsl3TlsContext::AllocateOutputBuffer(this, a2, v17 + v21 + v18 + 2 * *((_DWORD *)this + 15));
  if ( OutputBuffer )
    return OutputBuffer;
  if ( v7 )
  {
    v52 = *((_BYTE *)this + 233) && (*((_BYTE *)this + 32) & 4) != 0 ? *((unsigned int *)this + 11) : 0i64;
    *(_WORD *)(v52 + v9 + *((_QWORD *)a2 + 1) + *((unsigned int *)a2 + 1)) = 10497;
    v53 = CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, 21, 2u);
    OutputBuffer = v53;
    if ( v53 )
    {
      CSslContext::SetError((__int64)this, 951, v53);
      return OutputBuffer;
    }
  }
  v25 = 0;
  if ( !*((_BYTE *)this + 233) && (*((_BYTE *)this + 32) & 4) != 0 )
    v26 = *((_DWORD *)this + 11);
  else
    v26 = 0;
  v27 = v9 + *((unsigned int *)a2 + 1);
  v28 = 0;
  v29 = (_BYTE *)(*((_QWORD *)a2 + 1) + v27 + v26);
  if ( v72 )
  {
    v54 = CreateUserMappingDataMsg(
            &v29[v10],
            v72,
            *(unsigned __int16 **)(*((_QWORD *)this + 10) + 872i64),
            *(unsigned __int16 **)(*((_QWORD *)this + 10) + 880i64));
    if ( !v54 )
      return 1359;
    SetHandshakeHeader((__int64)v29, 23, 0i64, v54, *((_WORD *)this + 110), *((unsigned __int8 *)this + 233));
    if ( *((_BYTE *)this + 233) )
    {
      ++*((_WORD *)this + 110);
      v28 = 1;
    }
    v25 = v10 + v54;
    if ( !*((_BYTE *)this + 1032) )
    {
      LOBYTE(v55) = 1;
      OutputBuffer = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, _BYTE *, _QWORD, __int64))(*(_QWORD *)this
                                                                                                  + 504i64))(
                       this,
                       v29,
                       v25,
                       v55);
    }
    if ( !OutputBuffer )
    {
      v29 += v25;
      goto LABEL_27;
    }
    v45 = OutputBuffer;
    v44 = 1001;
LABEL_117:
    v46 = this;
    goto LABEL_118;
  }
LABEL_27:
  if ( !(_DWORD)Size )
    goto LABEL_28;
  v56 = v4;
  v57 = HIWORD(v4);
  v58 = *((_BYTE *)this + 233) == 0;
  LODWORD(Size) = v77 >> 8;
  if ( v58 )
  {
    memcpy_0(v29 + 7, Src, v56);
    v59 = v77;
    v29[5] = Size;
    v29[6] = v59;
    v29[4] = v57;
  }
  else
  {
    memcpy_0(v29 + 15, Src, v56);
    v59 = v77;
    v29[13] = Size;
    v29[14] = v59;
    v29[12] = v57;
  }
  v60 = v59 + v10 + 3;
  SetHandshakeHeader((__int64)v29, 11, 0i64, v59 + 3, *((_WORD *)this + 110), *((unsigned __int8 *)this + 233));
  if ( *((_BYTE *)this + 233) )
  {
    ++v28;
    ++*((_WORD *)this + 110);
  }
  if ( !*((_BYTE *)this + 1032) )
  {
    LOBYTE(v61) = 1;
    OutputBuffer = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, _BYTE *, _QWORD, __int64))(*(_QWORD *)this
                                                                                                + 504i64))(
                     this,
                     v29,
                     v60,
                     v61);
  }
  if ( OutputBuffer )
  {
    v45 = OutputBuffer;
    v44 = 1002;
    goto LABEL_117;
  }
  v29 += v60;
  v25 += v60;
LABEL_28:
  v30 = *((_DWORD *)this + 240);
  v31 = (__int16 *)((char *)this + 220);
  v32 = *((_WORD *)this + 110);
  v33 = (const void *)*((_QWORD *)this + 119);
  LODWORD(Size) = v30 + v10;
  SetHandshakeHeader((__int64)v29, 16, v33, v30, v32, *((unsigned __int8 *)this + 233));
  if ( *((_BYTE *)this + 233) )
  {
    ++v28;
    ++*v31;
  }
  if ( !*((_BYTE *)this + 1032) )
  {
    LOBYTE(v34) = 1;
    OutputBuffer = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, _BYTE *, _QWORD, __int64))(*(_QWORD *)this
                                                                                                + 504i64))(
                     this,
                     v29,
                     (unsigned int)Size,
                     v34);
  }
  if ( OutputBuffer )
  {
    v45 = OutputBuffer;
    v44 = 1003;
    goto LABEL_117;
  }
  v35 = &v29[(unsigned int)Size];
  v36 = Size + v25;
  if ( (*((_DWORD *)this + 34) & 0x8000000) == 0 || *((_BYTE *)this + 1032) )
    goto LABEL_38;
  v37 = *(_QWORD *)this;
  if ( (unsigned int)(*(_DWORD *)(*((_QWORD *)this + 1) + 48i64) - 2) > 2 )
  {
    v62 = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *))(v37 + 160))(this);
    OutputBuffer = MakeRsaSessionKeysHelper(this, v62);
    (*(void (__fastcall **)(CSsl3TlsClientContext *, _QWORD))(*(_QWORD *)this + 168i64))(this, 0i64);
  }
  else
  {
    v38 = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *))(v37 + 144))(this);
    v39 = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)this + 160i64))(this);
    OutputBuffer = MakeEccDhPskSessionKeysHelper(this, v39, v38, 0);
    (*(void (__fastcall **)(CSsl3TlsClientContext *, _QWORD))(*(_QWORD *)this + 168i64))(this, 0i64);
    (*(void (__fastcall **)(CSsl3TlsClientContext *, _QWORD))(*(_QWORD *)this + 152i64))(this, 0i64);
  }
  if ( !OutputBuffer )
  {
LABEL_38:
    if ( !v78 )
      goto LABEL_39;
    CertVerify = CSsl3TlsClientContext::GenerateCertVerify(this, &v35[v10], (unsigned int *)&Size);
    OutputBuffer = CertVerify;
    if ( CertVerify == 590684 )
    {
      v64 = Size;
      if ( (unsigned int)Size > *(_DWORD *)a2 )
      {
        OutputBuffer = 1359;
      }
      else
      {
        memcpy_0(*((void **)a2 + 1), v35, (unsigned int)Size);
        *((_DWORD *)a2 + 1) = v64;
      }
    }
    else if ( !CertVerify )
    {
      v65 = Size;
      SetHandshakeHeader((__int64)v35, 15, 0i64, Size, *v31, *((unsigned __int8 *)this + 233));
      if ( *((_BYTE *)this + 233) )
        ++*v31;
      v67 = v65 + v10;
      LOBYTE(v66) = 1;
      CcsAndFinishMessage = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, unsigned __int8 *, _QWORD, __int64))(*(_QWORD *)this + 504i64))(
                              this,
                              v35,
                              v65 + v10,
                              v66);
      OutputBuffer = CcsAndFinishMessage;
      if ( CcsAndFinishMessage )
      {
        v44 = 1004;
        goto LABEL_116;
      }
      v36 += v67;
LABEL_39:
      if ( *((_BYTE *)this + 233) )
      {
        v68 = *((_WORD *)this + 17);
        v69 = (_BYTE *)*((_QWORD *)a2 + 1);
        v69[1] = HIBYTE(v68);
        v69[11] = BYTE1(v36);
        v70 = v36 + v73;
        v69[2] = v68;
        *v69 = 22;
        v69[12] = v36;
        *((_DWORD *)a2 + 1) += v70;
        goto LABEL_41;
      }
      CcsAndFinishMessage = CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, 22, v36);
      OutputBuffer = CcsAndFinishMessage;
      if ( !CcsAndFinishMessage )
      {
LABEL_41:
        CcsAndFinishMessage = CSsl3TlsContext::GenerateCcsAndFinishMessage(this, a2);
        OutputBuffer = CcsAndFinishMessage;
        if ( !CcsAndFinishMessage )
          return OutputBuffer;
        v44 = 152;
        goto LABEL_116;
      }
      v44 = 952;
LABEL_116:
      v45 = CcsAndFinishMessage;
      goto LABEL_117;
    }
    *v31 -= v28;
  }
  return OutputBuffer;
}
// 18000227D: variable 'v34' is possibly undefined
// 18002C3CB: variable 'v55' is possibly undefined
// 18002C4C8: variable 'v61' is possibly undefined
// 18002C5FC: variable 'v66' is possibly undefined
