//----- (0000000180026908) ----------------------------------------------------
CCipherSuiteInfo *__fastcall CCipherSuiteInfo::CCipherSuiteInfo(
        CCipherSuiteInfo *this,
        unsigned __int64 a2,
        struct _NCRYPT_SSL_CIPHER_SUITE_EX *a3)
{
  _DWORD *v3; // rdi
  _DWORD *v4; // r14
  __int64 v7; // rdx
  __int64 v8; // rdx
  int v9; // r9d
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 *v12; // rax
  __int64 v13; // rcx
  unsigned int v14; // eax
  bool v15; // al
  __int64 v16; // rax
  unsigned __int64 v17; // rcx
  const wchar_t *v18; // r14
  int v19; // edi
  const wchar_t **i; // rsi

  v3 = (_DWORD *)((char *)this + 48);
  *((_DWORD *)this + 2) = 0;
  v4 = (_DWORD *)((char *)this + 52);
  *((_DWORD *)this + 3) = *((_DWORD *)a3 + 69);
  *((_DWORD *)this + 4) = *((_DWORD *)a3 + 102) >> 3;
  *((_DWORD *)this + 5) = *((_DWORD *)a3 + 68);
  *((_DWORD *)this + 6) = *((_DWORD *)a3 + 135);
  *((_DWORD *)this + 7) = *((_DWORD *)a3 + 2);
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_BYTE *)this + 56) = 0;
  *((_QWORD *)this + 8) = 0i64;
  *((_QWORD *)this + 106) = 0i64;
  *((_QWORD *)this + 107) = 0i64;
  CCipherMill::ReferenceProvider(this, a2, (unsigned __int64 *)this);
  *((_DWORD *)this + 8) = LookupExchangeAlg((wchar_t *)a3, v7);
  *((_DWORD *)this + 9) = LookupCertificateAlg((wchar_t *)a3, v8);
  *((_DWORD *)this + 10) = LookupSymmetricCipherAlg(a3);
  *((_DWORD *)this + 11) = LookupChecksumAlg((wchar_t *)a3);
  wcscpy_s((wchar_t *)this + 101, 0x40ui64, (const wchar_t *)a3 + 72);
  wcscpy_s((wchar_t *)this + 165, 0x40ui64, (const wchar_t *)a3 + 206);
  wcscpy_s((wchar_t *)this + 229, 0x40ui64, (const wchar_t *)a3 + 274);
  wcscpy_s((wchar_t *)this + 293, 0x40ui64, (const wchar_t *)a3 + 140);
  wcscpy_s((wchar_t *)this + 357, 0x40ui64, (const wchar_t *)a3 + 340);
  if ( *((_DWORD *)a3 + 1) != 772 )
  {
    v9 = *((_DWORD *)this + 8);
    if ( v3 )
      *v3 = 0;
    v10 = (unsigned int)g_dwKeyExchangeInfoTotalCount;
    v11 = 0i64;
    if ( g_dwKeyExchangeInfoTotalCount )
    {
      v12 = g_pKeyExchangeInfo;
      while ( 1 )
      {
        v13 = *v12;
        if ( *v12 )
        {
          if ( *(_DWORD *)(v13 + 12) == v9 )
            break;
        }
        v11 = (unsigned int)(v11 + 1);
        ++v12;
        if ( (unsigned int)v11 >= g_dwKeyExchangeInfoTotalCount )
          goto LABEL_11;
      }
      I_GetKeyExchangeDetailsFromKeyExchangeInfo(v13, v11, (unsigned int)g_dwKeyExchangeInfoTotalCount, 0i64, v3);
    }
LABEL_11:
    I_GetSignatureDetailsFromAlgId(*((_DWORD *)this + 9), v11, v10, 0i64, v4);
  }
  GetKeyStorageProviderHandle((LPCWSTR)a3 + 274, (unsigned __int8 *)this + 56, (unsigned __int64 *)this + 8);
  v14 = *((_DWORD *)a3 + 2);
  v15 = v14 == 3 || v14 > 0x61 && (v14 <= 0x64 || v14 == 131200);
  *((_BYTE *)this + 72) = v15;
  wcscpy_s((wchar_t *)this + 37, 0x40ui64, (const wchar_t *)a3 + 8);
  v16 = -1i64;
  v17 = -1i64;
  do
    ++v17;
  while ( *((_WORD *)this + v17 + 37) );
  if ( v17 > 5 )
  {
    do
      ++v16;
    while ( *((_WORD *)this + v16 + 37) );
    v18 = (const wchar_t *)((char *)this + 2 * v16);
    v19 = 0;
    for ( i = (const wchar_t **)&off_18007F170; wcsicmp(v18 + 32, *i); i += 99 )
    {
      if ( (unsigned int)++v19 >= 3 )
        return this;
    }
    *((_WORD *)v18 + 32) = 0;
  }
  return this;
}
// 180026992: variable 'v7' is possibly undefined
// 18002699D: variable 'v8' is possibly undefined
// 180026A91: variable 'v11' is possibly undefined
// 180026A91: variable 'v10' is possibly undefined
// 18007F170: using guessed type wchar_t *off_18007F170;
// 1800923B0: using guessed type int g_dwKeyExchangeInfoTotalCount;
// 1800923C0: using guessed type _QWORD g_pKeyExchangeInfo[12];

