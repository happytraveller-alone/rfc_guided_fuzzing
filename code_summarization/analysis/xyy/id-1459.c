//----- (0000000180074C40) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::DhGenerateServerExchangeValue(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int *a3)
{
  __int64 v3; // rax
  unsigned int *v4; // rsi
  bool v6; // zf
  enum _eTlsSignatureAlgorithm v7; // edi
  char *v8; // r14
  unsigned int ServerEphemKey; // ebx
  __int64 v10; // r15
  unsigned int v11; // r14d
  int v12; // r13d
  __int64 v13; // rax
  __int16 v14; // si
  int v16; // eax
  DWORD v17; // eax
  unsigned int v18; // r13d
  unsigned int v19; // edi
  char *v20; // r15
  unsigned int v21; // r14d
  size_t v22; // r8
  __int64 v23; // rsi
  unsigned __int8 v24; // al
  __int64 v25; // rdi
  unsigned __int8 *v26; // rbx
  char *v27; // r15
  unsigned __int8 v28; // al
  unsigned __int8 *v29; // rbx
  unsigned __int8 *v30; // rdi
  enum _eTlsSignatureAlgorithm v31; // esi
  unsigned int v32; // r15d
  unsigned int v33; // r13d
  __int32 v34; // esi
  unsigned int v35; // eax
  enum _eTlsHashAlgorithm v36; // [rsp+40h] [rbp-28h] BYREF
  unsigned int Size; // [rsp+44h] [rbp-24h]
  enum _eTlsSignatureAlgorithm Size_4; // [rsp+48h] [rbp-20h]
  unsigned int v39; // [rsp+4Ch] [rbp-1Ch] BYREF
  int v40; // [rsp+50h] [rbp-18h] BYREF
  unsigned int v41; // [rsp+54h] [rbp-14h]
  unsigned __int16 *v42; // [rsp+58h] [rbp-10h] BYREF
  __int16 v43; // [rsp+B0h] [rbp+48h]
  DWORD pcbResult; // [rsp+C8h] [rbp+60h] BYREF

  v3 = *((_QWORD *)this + 1);
  pcbResult = 0;
  v4 = a3;
  v40 = 0;
  v42 = 0i64;
  v6 = *(_DWORD *)(v3 + 52) == 2;
  v36 = TlsHashAlgorithm_None;
  v43 = 0;
  v39 = 0;
  if ( v6 )
  {
    v7 = TlsSignatureAlgorithm_Rsa;
  }
  else
  {
    if ( *(_DWORD *)(v3 + 52) != 3 )
      goto LABEL_34;
    v7 = TlsSignatureAlgorithm_Dsa;
  }
  v8 = (char *)this + 960;
  Size_4 = v7;
  if ( !*((_QWORD *)this + 120) )
  {
    ServerEphemKey = GetServerEphemKey(this, (struct CEphemKeyData **)this + 120);
    if ( ServerEphemKey )
      return ServerEphemKey;
  }
  v6 = (*((_DWORD *)this + 16) & 0x40400) == 0;
  v10 = *(_QWORD *)(*(_QWORD *)v8 + 16i64);
  v11 = *(_DWORD *)(v10 + 4);
  Size = v11;
  v41 = 3 * v11;
  v12 = 3 * v11 + 12;
  if ( v6 )
  {
LABEL_13:
    v16 = ComputeSignatureLength((__int64 **)this, v7, v36, &pcbResult);
    ServerEphemKey = v16;
    if ( v16 < 0 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 1051, v16, 0x50u);
      return ServerEphemKey;
    }
    v17 = 140;
    if ( pcbResult > 0x8C )
      v17 = pcbResult;
    v18 = v17 + v12;
    if ( !a2 )
    {
      *v4 = v18;
      return 0;
    }
    if ( *v4 < v18 )
    {
      *v4 = v18;
      return (unsigned int)-2146893023;
    }
    v19 = Size;
    v20 = (char *)(v10 + 8);
    v21 = v11 >> 8;
    v22 = Size;
    *a2 = v21;
    a2[1] = v19;
    v23 = v19;
    memcpy_0(a2 + 2, v20, v22);
    v24 = Size;
    v25 = v19 + 2;
    v26 = &a2[v25];
    v27 = &v20[v23];
    *v26 = v21;
    v26[1] = v24;
    memcpy_0(&a2[v25 + 2], v27, (unsigned int)v23);
    v28 = Size;
    v29 = &a2[v25 + v25];
    *v29 = v21;
    v29[1] = v28;
    memcpy_0(v29 + 2, &v27[v23], (unsigned int)v23);
    v30 = &v29[v25];
    v31 = Size_4;
    v32 = (_DWORD)v30 - (_DWORD)a2;
    v33 = v18 - v41 - 6;
    if ( (*((_DWORD *)this + 16) & 0x40400) != 0 )
    {
      if ( Size_4 == TlsSignatureAlgorithm_Dsa && v36 != TlsHashAlgorithm_Sha1 || v33 < 2 )
        return 1359;
      *(_WORD *)v30 = v43;
      v30 += 2;
      v33 -= 2;
    }
    pcbResult = v33 - 2;
    ServerEphemKey = SslImpersonateClient(*(_QWORD *)(*((_QWORD *)this + 10) + 752i64), &v40);
    if ( ServerEphemKey )
    {
LABEL_35:
      if ( v40 )
        RevertToSelf();
      return ServerEphemKey;
    }
    v34 = v31 - 1;
    if ( !v34 )
    {
      v35 = SignRsaParams(this, a2, v32, v42, v36, v39, v30 + 2, &pcbResult);
LABEL_32:
      ServerEphemKey = v35;
      if ( !v35 )
      {
        *v30 = BYTE1(pcbResult);
        v30[1] = pcbResult;
        *a3 = (_DWORD)v30 - (_DWORD)a2 + pcbResult + 2;
      }
      goto LABEL_35;
    }
    if ( v34 == 1 )
    {
      v35 = SignDssParams(this, a2, v32, v30 + 2, &pcbResult);
      goto LABEL_32;
    }
LABEL_34:
    ServerEphemKey = -2146893048;
    goto LABEL_35;
  }
  v12 = 3 * v11 + 14;
  v13 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 248i64))(this);
  if ( v13 )
  {
    v14 = __ROR2__(
            CTlsSignatureSuiteList::GetMinimumCodePointToSign(
              (CSsl3TlsServerContext *)((char *)this + 510),
              v7,
              *(_DWORD *)(v13 + 428),
              *((_DWORD *)this + 16),
              0),
            8);
    v43 = v14;
    if ( !v14 )
      return 2148074289i64;
    GetSignatureSuiteInfoByCodePoint(v14, 0i64, &v36, 0i64, (const unsigned __int16 **)&v42, 0i64, &v39);
    v4 = a3;
    goto LABEL_13;
  }
  return (unsigned int)-2146893052;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
