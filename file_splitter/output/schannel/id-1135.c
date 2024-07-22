//----- (000000018005BCB0) ----------------------------------------------------
__int64 __fastcall CheckClientVerifyMessage(
        struct CSsl3TlsServerContext *a1,
        const unsigned __int16 *a2,
        const unsigned __int16 *a3,
        unsigned int a4,
        unsigned int a5,
        ULONG a6,
        unsigned __int8 *pbEncoded,
        DWORD cbEncoded)
{
  UCHAR *v8; // r12
  unsigned __int8 *v12; // rsi
  const unsigned __int16 **v14; // r13
  __int64 v15; // rax
  __int64 v16; // r8
  unsigned int Property; // ebx
  int v18; // r8d
  int v19; // edx
  struct CSsl3TlsServerContext *v20; // rcx
  __int64 *v21; // rax
  __int64 v22; // rcx
  unsigned int v23; // eax
  __int64 v24; // r15
  int v25; // ecx
  unsigned __int8 *v26; // rax
  int v27; // eax
  DWORD v28; // eax
  int v29; // eax
  UCHAR pbOutput[4]; // [rsp+40h] [rbp-89h] BYREF
  ULONG cbSignature; // [rsp+44h] [rbp-85h] BYREF
  ULONG cbHash; // [rsp+48h] [rbp-81h] BYREF
  __int64 v34; // [rsp+50h] [rbp-79h] BYREF
  BCRYPT_HANDLE hObject; // [rsp+58h] [rbp-71h] BYREF
  ULONG pcbResult[2]; // [rsp+60h] [rbp-69h] BYREF
  const unsigned __int16 *v37; // [rsp+68h] [rbp-61h] BYREF
  __int128 v38; // [rsp+70h] [rbp-59h] BYREF
  UCHAR pbHash[64]; // [rsp+80h] [rbp-49h] BYREF

  v8 = pbEncoded;
  hObject = 0i64;
  v12 = 0i64;
  v14 = 0i64;
  cbHash = 64;
  memset_0(pbHash, 0, sizeof(pbHash));
  v37 = 0i64;
  v15 = *(_QWORD *)a1;
  v38 = 0i64;
  (*(void (__fastcall **)(struct CSsl3TlsServerContext *, __int64 *))(v15 + 232))(a1, &v34);
  RtlAcquireResourceShared((PRTL_RESOURCE)(v34 + 72), 1u);
  *(_QWORD *)pcbResult = *(_QWORD *)(v34 + 16);
  if ( !wcsncmp(a2, L"RSA", 3ui64) )
  {
    if ( a6 == 8 )
    {
      v14 = (const unsigned __int16 **)&v38;
      DWORD2(v38) = a5;
      *(_QWORD *)&v38 = a3;
    }
    else
    {
      if ( a6 != 2 )
      {
        Property = 1359;
        goto LABEL_33;
      }
      v14 = &v37;
      v37 = a3;
    }
  }
  v16 = (*(__int64 (__fastcall **)(struct CSsl3TlsServerContext *, _QWORD))(*(_QWORD *)a1 + 512i64))(a1, a4);
  if ( !v16 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(v34 + 72));
    Property = 1359;
    v18 = 1359;
    v19 = 1303;
LABEL_6:
    v20 = a1;
LABEL_7:
    CSslContext::SetErrorAndFatalAlert((__int64)v20, v19, v18, 0x50u);
    goto LABEL_33;
  }
  v21 = (__int64 *)*((_QWORD *)a1 + 1);
  if ( v21 )
    v22 = *v21;
  else
    v22 = 0i64;
  Property = SslComputeClientAuthHash(v22, *(_QWORD *)pcbResult, v16, a2, pbHash, 64, &cbHash, 0);
  RtlReleaseResource((PRTL_RESOURCE)(v34 + 72));
  v20 = a1;
  if ( Property )
  {
    v18 = Property;
    v19 = 1303;
    goto LABEL_7;
  }
  v23 = ConvertPubKeyToBcryptHdl(a1, a2, &hObject);
  Property = v23;
  if ( v23 )
  {
    v18 = v23;
    v19 = 1304;
    goto LABEL_6;
  }
  if ( !wcsncmp(a2, L"RSA", 3ui64) )
  {
    v28 = cbEncoded;
  }
  else
  {
    *(_DWORD *)pbOutput = 0;
    pcbResult[0] = 0;
    v24 = 47i64;
    if ( !wcsncmp(a2, L"DSA", 3ui64) )
      v24 = 40i64;
    Property = BCryptGetProperty(hObject, L"KeyLength", pbOutput, 4u, pcbResult, 0);
    if ( Property )
      goto LABEL_33;
    v25 = ((pbOutput[0] & 7) != 0) + (*(_DWORD *)pbOutput >> 3);
    if ( !v25 )
      goto LABEL_33;
    cbSignature = 2 * v25;
    v26 = (unsigned __int8 *)SPExternalAlloc(2 * v25);
    v12 = v26;
    if ( !v26 )
    {
      Property = 14;
      goto LABEL_33;
    }
    v27 = DecodeSigAndReverse(pbEncoded, cbEncoded, v26, &cbSignature, (const char *)v24);
    Property = v27;
    if ( v27 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)a1, 1305, v27, 0x32u);
LABEL_32:
      LocalFree(v12);
      goto LABEL_33;
    }
    v28 = cbSignature;
    v8 = v12;
  }
  v29 = BCryptVerifySignature(hObject, v14, pbHash, cbHash, v8, v28, a6);
  Property = v29;
  if ( v29 )
    CSslContext::SetErrorAndFatalAlert((__int64)a1, 1306, v29, 0x33u);
  if ( v12 )
    goto LABEL_32;
LABEL_33:
  if ( hObject )
    BCryptDestroyKey(hObject);
  return Property;
}
// 180098588: using guessed type __int64 __fastcall SslComputeClientAuthHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);

