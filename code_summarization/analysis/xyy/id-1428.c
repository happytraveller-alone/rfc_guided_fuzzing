//----- (00000001800723A4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::RsaGenerateServerExchangeValue(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int *a3)
{
  int v3; // eax
  __int64 v5; // rcx
  __int64 result; // rax
  __int64 v9; // rax
  unsigned int v10; // eax
  unsigned int v11; // ebx
  __int64 *v12; // rax
  __int64 v13; // r9
  __int64 v14; // rcx
  int EphemeralKey; // eax
  ULONG v16; // ebx
  __int64 *v17; // rax
  __int64 v18; // rcx
  int EphemBlobFromKey; // eax
  unsigned __int8 *v20; // r15
  __int64 v21; // rsi
  unsigned __int8 *v22; // rbx
  __int64 v23; // rcx
  int v24; // eax
  unsigned __int8 *v25; // rdi
  int v26; // esi
  int v27; // eax
  int v28; // edx
  __int64 *v29; // rax
  __int64 v30; // rcx
  int v31; // [rsp+50h] [rbp-29h] BYREF
  int v32; // [rsp+54h] [rbp-25h]
  int v33; // [rsp+58h] [rbp-21h] BYREF
  unsigned int v34; // [rsp+5Ch] [rbp-1Dh] BYREF
  unsigned int v35; // [rsp+60h] [rbp-19h] BYREF
  unsigned __int8 *v36; // [rsp+68h] [rbp-11h] BYREF
  unsigned __int8 v37[40]; // [rsp+70h] [rbp-9h] BYREF

  v3 = *a3;
  v33 = 0;
  v5 = *((_QWORD *)this + 3);
  v35 = 0;
  v36 = 0i64;
  v32 = v3;
  v31 = 0;
  if ( !v5 )
    return 2148074253i64;
  if ( (*((_BYTE *)this + 32) & 1) == 0 )
    goto LABEL_9;
  v9 = *((_QWORD *)this + 1);
  if ( !v9 )
    goto LABEL_9;
  v10 = *(_DWORD *)(v9 + 28);
  if ( v10 != 3 )
  {
    if ( v10 <= 0x61 )
    {
LABEL_9:
      *a3 = 0;
      return 0i64;
    }
    if ( v10 <= 0x64 )
    {
      v11 = 128;
      goto LABEL_14;
    }
    if ( v10 != 131200 )
      goto LABEL_9;
  }
  v11 = 64;
LABEL_14:
  result = GetRsaKeyModulus(*(_QWORD *)(v5 + 8), &v34);
  if ( !(_DWORD)result )
  {
    if ( v34 <= v11 )
      goto LABEL_9;
    if ( !a2 )
    {
      *a3 = v11 + v34 + 10;
      return 0i64;
    }
    if ( (*((_BYTE *)this + 32) & 1) != 0 && (v12 = (__int64 *)*((_QWORD *)this + 1)) != 0i64 )
    {
      v13 = *((unsigned int *)v12 + 7);
    }
    else
    {
      v12 = (__int64 *)*((_QWORD *)this + 1);
      v13 = 0i64;
    }
    if ( v12 )
      v14 = *v12;
    else
      v14 = 0i64;
    EphemeralKey = SslCreateEphemeralKey(
                     v14,
                     (char *)this + 112,
                     *((unsigned __int16 *)this + 17),
                     v13,
                     0,
                     8 * v11,
                     0i64,
                     0,
                     0);
    v16 = EphemeralKey;
    if ( EphemeralKey )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 818, EphemeralKey, 0x33u);
      return v16;
    }
    v17 = (__int64 *)*((_QWORD *)this + 1);
    if ( v17 )
      v18 = *v17;
    else
      v18 = 0i64;
    EphemBlobFromKey = GetEphemBlobFromKey(v18, *((_QWORD *)this + 14), L"RSAPUBLICBLOB", &v35, &v36);
    v20 = v36;
    v16 = EphemBlobFromKey;
    if ( EphemBlobFromKey )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 819, EphemBlobFromKey, 0x33u);
LABEL_44:
      if ( v20 )
        SPExternalFree(v20);
      return v16;
    }
    *a2 = BYTE1(*((_DWORD *)v36 + 3));
    a2[1] = v20[12];
    memcpy_0(a2 + 2, &v20[*((unsigned int *)v20 + 2) + 24], *((unsigned int *)v20 + 3));
    v21 = *((unsigned int *)v20 + 3);
    v22 = &a2[v21 + 2];
    *v22 = BYTE1(*((_DWORD *)v20 + 2));
    v22[1] = v20[8];
    memcpy_0(v22 + 2, v20 + 24, *((unsigned int *)v20 + 2));
    v23 = *((unsigned int *)v20 + 2);
    v24 = v32 - v23 - v21;
    LODWORD(v21) = *((_DWORD *)v20 + 3);
    v32 = v24;
    v25 = &v22[v23 + 2];
    v26 = v23 + v21;
    v16 = SslImpersonateClient(*(_QWORD *)(*((_QWORD *)this + 10) + 752i64), &v33);
    if ( !v16 )
    {
      v27 = CSsl3TlsContext::ComputeRsaServerExchangeHashes((UCHAR *)this, a2, v26 + 4, v37);
      v16 = v27;
      if ( v27 )
      {
        v28 = 815;
LABEL_35:
        CSslContext::SetErrorAndFatalAlert((__int64)this, v28, v27, 0x50u);
        goto LABEL_42;
      }
      v29 = (__int64 *)*((_QWORD *)this + 1);
      if ( v29 )
        v30 = *v29;
      else
        v30 = 0i64;
      v27 = SslSignHash(v30, *(_QWORD *)(*((_QWORD *)this + 3) + 8i64), v37, 36i64, v25 + 2, v32 - 6, &v31, 0);
      v16 = v27;
      if ( v27 )
      {
        v28 = 820;
        goto LABEL_35;
      }
      *v25 = BYTE1(v31);
      v25[1] = v31;
      *a3 = (_DWORD)v25 - (_DWORD)a2 + v31 + 2;
    }
LABEL_42:
    if ( v33 )
      RevertToSelf();
    goto LABEL_44;
  }
  return result;
}
// 180098540: using guessed type __int64 __fastcall SslSignHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098548: using guessed type __int64 __fastcall SslCreateEphemeralKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _DWORD, _DWORD);

