// File count: 421
// Total lines: 160
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::EccGenerateServerMasterKey(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  __int64 v3; // rax
  struct _BCRYPT_ECCKEY_BLOB *v7; // rbx
  unsigned __int64 v8; // r13
  size_t v9; // r14
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  void *v12; // rsp
  size_t v13; // rdx
  unsigned __int8 *v14; // rcx
  int EccPublicKeyBlob; // esi
  __int64 *v16; // rcx
  __int64 v17; // rax
  ULONG dwMagic; // esi
  __int64 *v19; // rax
  __int64 v20; // rcx
  unsigned int EccDhPskSessionKeysHelper; // esi
  struct _BCRYPT_ECCKEY_BLOB *v23; // rax
  __int64 *v24; // rax
  __int64 v25; // rcx
  unsigned __int8 v26; // r9
  int v27; // edx
  __int64 v28; // [rsp+0h] [rbp-30h] BYREF
  unsigned __int64 v29; // [rsp+30h] [rbp+0h] BYREF
  __int64 v30[5]; // [rsp+38h] [rbp+8h] BYREF

  v3 = *((_QWORD *)this + 120);
  v29 = 0i64;
  v7 = 0i64;
  v8 = *(unsigned int *)(v3 + 24);
  if ( !(_DWORD)v8 )
    goto LABEL_31;
  v9 = (unsigned int)v8;
  if ( v8 > g_ulMaxStackAllocSize )
    goto LABEL_31;
  v10 = v8 + g_ulAdditionalProbeSize + 8;
  if ( v10 < v8 || !(unsigned int)VerifyStackAvailable(v10) )
    goto LABEL_31;
  v11 = (unsigned int)(v8 + 8) + 15i64;
  if ( v11 <= (unsigned int)(v8 + 8) )
    v11 = 0xFFFFFFFFFFFFFF0i64;
  v12 = alloca(v11 & 0xFFFFFFFFFFFFFFF0ui64);
  v7 = (struct _BCRYPT_ECCKEY_BLOB *)&v29;
  if ( &v28 == (__int64 *)-48i64 || (LODWORD(v29) = 1801679955, (v7 = (struct _BCRYPT_ECCKEY_BLOB *)v30) == 0i64) )
  {
LABEL_31:
    if ( (int)v8 + 8 >= (unsigned int)v8 )
    {
      v23 = (struct _BCRYPT_ECCKEY_BLOB *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)((unsigned int)(v8 + 8));
      if ( !v23 )
        goto LABEL_36;
      v23->dwMagic = 1885431112;
      v7 = v23 + 1;
    }
    if ( v7 )
    {
      v9 = v8;
      goto LABEL_9;
    }
LABEL_36:
    EccDhPskSessionKeysHelper = 14;
    goto LABEL_28;
  }
LABEL_9:
  memset_0(v7, 0, v9);
  *v7 = **(struct _BCRYPT_ECCKEY_BLOB **)(*((_QWORD *)this + 120) + 16i64);
  if ( !a2 || a3 <= 2 )
  {
    EccDhPskSessionKeysHelper = -2146893048;
    goto LABEL_25;
  }
  v13 = *a2;
  v14 = a2 + 1;
  if ( (_DWORD)v13 + 1 != a3 || !*a2 )
  {
    EccDhPskSessionKeysHelper = -2146893048;
    goto LABEL_49;
  }
  if ( a2 == (unsigned __int8 *)-1i64 )
    goto LABEL_47;
  if ( (*((_BYTE *)this + 20) & 8) != 0 )
  {
    EccPublicKeyBlob = MontgomeryGetEccPublicKeyBlob(v14, v13, v7, v8);
  }
  else
  {
    EccPublicKeyBlob = 0;
    if ( *v14 == 4 && v13 + 7 <= v9 )
      memcpy_0(&v7[1], v14 + 1, (unsigned int)(v13 - 1));
    else
      EccPublicKeyBlob = -2146893048;
  }
  if ( EccPublicKeyBlob )
  {
LABEL_47:
    EccDhPskSessionKeysHelper = 1359;
LABEL_49:
    v26 = 50;
    v27 = 702;
    goto LABEL_50;
  }
  v16 = (__int64 *)*((_QWORD *)this + 1);
  v17 = v16[106];
  if ( v17 && *(_BYTE *)(v17 + 24) )
  {
    dwMagic = v7->dwMagic;
    v7->dwMagic = *((_DWORD *)this + 4);
    v19 = (__int64 *)*((_QWORD *)this + 1);
    if ( v19 )
      v20 = *v19;
    else
      v20 = 0i64;
    if ( !(unsigned int)SslImportKey(v20, &v29, L"SSLECCPUBLICBLOB", v7, v8, 0) )
      goto LABEL_24;
    v7->dwMagic = dwMagic;
    v24 = (__int64 *)*((_QWORD *)this + 1);
    if ( v24 )
    {
      v25 = *v24;
      goto LABEL_45;
    }
  }
  else if ( v16 )
  {
    v25 = *v16;
    goto LABEL_45;
  }
  v25 = 0i64;
LABEL_45:
  EccDhPskSessionKeysHelper = SslImportKey(v25, &v29, L"ECCPUBLICBLOB", v7, v8, 0);
  if ( EccDhPskSessionKeysHelper )
  {
    v26 = 51;
    v27 = 703;
LABEL_50:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v27, EccDhPskSessionKeysHelper, v26);
    goto LABEL_25;
  }
LABEL_24:
  EccDhPskSessionKeysHelper = MakeEccDhPskSessionKeysHelper(this, *(_QWORD *)(*((_QWORD *)this + 120) + 8i64), v29, 1);
LABEL_25:
  if ( v7 && v7[-1].dwMagic == 1885431112 )
    ((void (__fastcall *)(struct _BCRYPT_ECCKEY_BLOB *))g_pfnFree)(&v7[-1]);
LABEL_28:
  if ( v29 )
    SslFreeObject(v29, 0i64);
  return EccDhPskSessionKeysHelper;
}
// 180082258: using guessed type wchar_t aSsleccpublicbl[17];
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
