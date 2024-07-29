//----- (000000018006B70C) ----------------------------------------------------
__int64 __fastcall CTls13ClientContext::GenerateClientFinished(CTls13ClientContext *this, struct SPBuffer *a2)
{
  __int64 v2; // rsi
  CTls13Context *v5; // r12
  unsigned int OutputBuffer; // edi
  char v7; // r10
  int v8; // edx
  CTls13ClientContext *v9; // rcx
  __int64 v11; // rdx
  __int64 v12; // rdi
  __int16 *v13; // r9
  unsigned __int8 v14; // di
  unsigned int v15; // r14d
  int v16; // edx
  __int64 v17; // rax
  __int64 v18; // rax
  unsigned __int8 v19; // di
  __int64 v20; // rcx
  __int64 *v21; // rax
  __int64 v22; // rdx
  __int64 *v23; // rax
  __int64 v24; // rdx
  __int64 *v25; // rax
  __int64 v26; // rdx
  char v27[4]; // [rsp+40h] [rbp-40h] BYREF
  unsigned int v28; // [rsp+44h] [rbp-3Ch] BYREF
  __int16 v29[2]; // [rsp+48h] [rbp-38h] BYREF
  int v30; // [rsp+4Ch] [rbp-34h]
  int v31; // [rsp+50h] [rbp-30h]
  __int16 v32; // [rsp+54h] [rbp-2Ch]
  int v33; // [rsp+58h] [rbp-28h]
  int v34; // [rsp+5Ch] [rbp-24h]
  __int16 v35; // [rsp+60h] [rbp-20h]
  int v36; // [rsp+64h] [rbp-1Ch]
  int v37; // [rsp+68h] [rbp-18h]
  __int16 v38; // [rsp+6Ch] [rbp-14h]
  int v39; // [rsp+70h] [rbp-10h]
  int v40; // [rsp+74h] [rbp-Ch]

  v2 = *((_QWORD *)this + 116);
  v27[0] = 0;
  v29[0] = 0;
  v32 = 0;
  v35 = 0;
  v30 = 22;
  v31 = 3;
  v5 = (CTls13ClientContext *)((char *)this + 1368);
  v34 = 3;
  v37 = 3;
  v40 = 3;
  v33 = 22;
  v36 = 22;
  v38 = 0;
  v39 = 22;
  OutputBuffer = CTls13Context::SetCcsRecordInfo(
                   (CTls13ClientContext *)((char *)this + 1368),
                   (struct CTlsRecord::CMessageInfo *)v29,
                   v27);
  if ( OutputBuffer )
  {
    v8 = 153;
LABEL_3:
    v9 = this;
LABEL_4:
    CSslContext::SetError((__int64)v9, v8, OutputBuffer);
    return OutputBuffer;
  }
  if ( *((_BYTE *)this + 1315) == v7 )
  {
    v14 = v27[0];
  }
  else
  {
    v11 = *((_QWORD *)this + 10);
    if ( !v11 )
      return 1359i64;
    v12 = (unsigned __int8)v27[0];
    if ( v2 && *(_BYTE *)(v2 + 78) != v7 && *(_BYTE *)(v2 + 79) == v7 )
      *(&v31 + 3 * (unsigned __int8)v27[0]) = 2;
    v13 = &v29[6 * v12];
    v14 = v12 + 1;
    v15 = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateMsgSize(
            (__int64)this + 1656,
            v2,
            *(_BYTE *)(v11 + 156) & 0x80,
            v13);
    if ( v15
      || v2
      && (v17 = v14,
          ++v14,
          (v15 = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateVerifySize(
                   (__int64)this + 1656,
                   &v29[6 * v17])) != 0) )
    {
      v16 = 153;
LABEL_14:
      CSslContext::SetError((__int64)this, v16, v15);
      return v15;
    }
  }
  v18 = v14;
  v19 = v14 + 1;
  v15 = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeFinishedSize(
          (__int64)this + 1656,
          (__int64)&v29[6 * v18]);
  if ( v15 )
  {
    v16 = 905;
    goto LABEL_14;
  }
  v20 = *((_QWORD *)this + 197);
  v28 = 0;
  OutputBuffer = (*(__int64 (__fastcall **)(__int64, _QWORD, __int16 *, unsigned int *))(*(_QWORD *)v20 + 16i64))(
                   v20,
                   v19,
                   v29,
                   &v28);
  v9 = this;
  if ( OutputBuffer )
  {
    v8 = 906;
    goto LABEL_4;
  }
  OutputBuffer = CSsl3TlsContext::AllocateOutputBuffer(this, a2, v28);
  if ( OutputBuffer )
    goto LABEL_24;
  OutputBuffer = (*(__int64 (__fastcall **)(_QWORD, struct SPBuffer *))(**((_QWORD **)this + 197) + 24i64))(
                   *((_QWORD *)this + 197),
                   a2);
  if ( OutputBuffer )
    goto LABEL_24;
  OutputBuffer = CTls13Context::GenerateCcsRecord(v5);
  if ( OutputBuffer
    || *((_BYTE *)this + 1315)
    && ((OutputBuffer = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateMsg((__int64)this + 1656)) != 0
     || v2
     && (OutputBuffer = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateCertificateVerify((__int64)this + 1656)) != 0) )
  {
    v8 = 154;
    goto LABEL_3;
  }
  OutputBuffer = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateFinished((__int64)this + 1656);
  if ( OutputBuffer )
  {
LABEL_24:
    v8 = 907;
    goto LABEL_3;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(CTls13ClientContext *))(*(_QWORD *)this + 384i64))(this) )
  {
    v21 = (__int64 *)*((_QWORD *)this + 1);
    if ( v21 )
      v22 = *v21;
    else
      v22 = 0i64;
    OutputBuffer = CTls13Context::PopulateSecTrafficSecret((__int64)v5, v22, 0, 2u, (__int64)v21, 0, *((_WORD *)a2 + 2));
    if ( OutputBuffer )
    {
      v8 = 609;
      goto LABEL_3;
    }
    v23 = (__int64 *)*((_QWORD *)this + 1);
    if ( v23 )
      v24 = *v23;
    else
      v24 = 0i64;
    OutputBuffer = CTls13Context::PopulateSecTrafficSecret((__int64)v5, v24, 1, 3u, (__int64)v23, 0, 0);
    if ( OutputBuffer )
    {
      v8 = 612;
      goto LABEL_3;
    }
    v25 = (__int64 *)*((_QWORD *)this + 1);
    if ( v25 )
      v26 = *v25;
    else
      v26 = 0i64;
    OutputBuffer = CTls13Context::PopulateSecTrafficSecret((__int64)v5, v26, 0, 3u, (__int64)v25, 0, 0);
    if ( OutputBuffer )
    {
      v8 = 611;
      goto LABEL_3;
    }
  }
  return 0i64;
}
// 18006B7B6: variable 'v7' is possibly undefined
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 18006B70C: using guessed type char var_40[4];
