//----- (0000000180061888) ----------------------------------------------------
__int64 __fastcall SignHashUsingCred(
        struct CSslContext *a1,
        struct CSslCredential *a2,
        void *a3,
        unsigned int a4,
        unsigned int a5,
        wchar_t *String1,
        LPCWSTR a7,
        PBYTE pbHashValue,
        DWORD cbHashValue,
        PBYTE pbEncoded,
        DWORD *pcbEncoded,
        char a12,
        unsigned int a13)
{
  DWORD *v13; // rsi
  const wchar_t *v14; // r14
  DWORD LastError; // ebx
  unsigned __int8 *v16; // rdi
  int v17; // r15d
  __int64 v18; // rdx
  BYTE *pbSignature; // r13
  LPCWSTR *v20; // r14
  unsigned int v21; // ebx
  __int64 result; // rax
  struct CSslCredential *v23; // r14
  CCipherMill *v24; // rcx
  size_t v25; // r14
  unsigned __int8 *v26; // rax
  size_t v27; // r15
  int v28; // r14d
  size_t v29; // r15
  unsigned int v30; // edx
  __int128 *v31; // r8
  __int64 v32; // rdx
  DWORD *pcbResult; // [rsp+38h] [rbp-61h]
  size_t v34; // [rsp+50h] [rbp-49h]
  BOOL v35; // [rsp+68h] [rbp-31h]
  LPCWSTR v36; // [rsp+70h] [rbp-29h] BYREF
  __int128 v37; // [rsp+78h] [rbp-21h] BYREF
  int v38; // [rsp+88h] [rbp-11h]
  unsigned __int8 *v39; // [rsp+90h] [rbp-9h]
  struct CSslContext *v40; // [rsp+E8h] [rbp+4Fh] BYREF
  struct CSslCredential *v41; // [rsp+F0h] [rbp+57h]
  void *v42; // [rsp+F8h] [rbp+5Fh]
  unsigned int v43; // [rsp+100h] [rbp+67h]

  v43 = a4;
  v42 = a3;
  v41 = a2;
  v40 = a1;
  v13 = pcbEncoded;
  v14 = String1;
  LastError = 0;
  v16 = 0i64;
  v35 = 0;
  v17 = 0;
  LODWORD(pcbEncoded) = *pcbEncoded;
  if ( !wcsncmp(String1, L"RSA", 3ui64) )
    v17 = 1;
  else
    v35 = wcsncmp(v14, L"DSA", 3ui64) == 0;
  v18 = (__int64)v40;
  pbSignature = pbEncoded;
  if ( !*((_BYTE *)v40 + 266) )
  {
    v36 = 0i64;
    v20 = 0i64;
    LODWORD(v40) = 0;
    v21 = a5;
    v37 = 0i64;
    if ( v17 )
    {
      if ( a5 == 8 )
      {
        v20 = (LPCWSTR *)&v37;
        *(_QWORD *)&v37 = a7;
        DWORD2(v37) = cbHashValue;
      }
      else
      {
        if ( a5 != 2 )
          return 1359i64;
        v20 = &v36;
        v36 = a7;
      }
    }
    if ( SslImpersonateClient((__int64)v42, (int *)&v40) )
      return 1359i64;
    LastError = NCryptSignHash(*((_QWORD *)v41 + 13), v20, pbHashValue, cbHashValue, pbSignature, *v13, v13, v21 | 0x40);
    if ( (_DWORD)v40 )
      RevertToSelf();
    if ( LastError )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          42i64,
          &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
          LastError);
      return LastError;
    }
LABEL_28:
    v24 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 44i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids, *v13);
      v24 = WPP_GLOBAL_Control;
    }
    if ( !v17 )
    {
      v25 = *v13;
      v26 = (unsigned __int8 *)SPExternalAlloc(*v13);
      v16 = v26;
      if ( !v26 )
        return 14;
      v27 = v25;
      memcpy_0(v26, pbSignature, v25);
      v28 = (unsigned int)v25 >> 1;
      v29 = v27 >> 1;
      if ( !*((_QWORD *)v41 + 14) )
      {
        ReverseInPlace(v16, v28);
        ReverseInPlace(&v16[v29], v30);
      }
      *v13 = (unsigned int)pcbEncoded;
      if ( v35 )
      {
        v31 = (__int128 *)v16;
        v32 = 40i64;
      }
      else
      {
        *((_QWORD *)&v37 + 1) = v16;
        v39 = &v16[v29];
        v31 = &v37;
        LODWORD(v37) = v28;
        v32 = 47i64;
        v38 = v28;
      }
      if ( !CryptEncodeObject(1u, (LPCSTR)v32, v31, pbSignature, v13) )
      {
        LastError = GetLastError();
LABEL_46:
        SPExternalFree(v16);
        return LastError;
      }
      v24 = WPP_GLOBAL_Control;
    }
    if ( v24 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v24 + 28) & 4) != 0 )
      WPP_SF_D(*((_QWORD *)v24 + 2), 45i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids, *v13);
    if ( !v16 )
      return LastError;
    goto LABEL_46;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 43i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    v18 = (__int64)v40;
  }
  if ( a12 )
  {
    v23 = v41;
    *v13 = a13;
    goto LABEL_25;
  }
  LODWORD(v34) = cbHashValue;
  pcbResult = (DWORD *)v14;
  v23 = v41;
  result = RemotelySignHash(
             *((_QWORD *)v41 + 14),
             *(_QWORD *)(v18 + 104),
             *((_QWORD *)v41 + 13),
             *((_DWORD *)v41 + 32),
             v43,
             a5,
             (LPCWSTR)pcbResult,
             a7,
             pbHashValue,
             v34);
  LastError = result;
  if ( !(_DWORD)result )
  {
LABEL_25:
    if ( v17 && *((_QWORD *)v23 + 14) )
      ReverseInPlace(pbSignature, *v13);
    goto LABEL_28;
  }
  return result;
}
// 180061AB2: variable 'v34' is possibly undefined
// 180061B69: variable 'v30' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
