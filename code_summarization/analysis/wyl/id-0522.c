//----- (00000001800265B0) ----------------------------------------------------
__int64 __fastcall CCipherMill::InitializeCipherSuite(
        CCipherMill *this,
        struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *a2,
        unsigned int a3,
        CCipherSuiteInfo *a4,
        char *a5,
        wchar_t *String1,
        struct ProviderEccCurves *a7)
{
  __int64 v7; // rdi
  CCipherSuiteInfo *v10; // rbx
  unsigned int v11; // r10d
  char *v12; // rcx
  char *v13; // r8
  int v14; // edx
  int v15; // eax
  unsigned __int64 v16; // r12
  __int64 v17; // r14
  __int64 v18; // rsi
  int v20; // r9d
  int v21; // r8d
  int v22; // edx
  int v23; // ecx
  int v24; // ecx

  v7 = a3;
  v10 = 0i64;
  v11 = 0;
  if ( !qword_180092498 )
    return 1168i64;
  while ( 1 )
  {
    v12 = *(char **)(qword_180092490 + 16i64 * v11);
    v13 = (char *)(a5 - v12);
    do
    {
      v14 = *(unsigned __int16 *)&v13[(_QWORD)v12];
      v15 = *(unsigned __int16 *)v12 - v14;
      if ( v15 )
        break;
      v12 += 2;
    }
    while ( v14 );
    if ( !v15 )
      break;
    if ( ++v11 >= qword_180092498 )
      return 1168i64;
  }
  v16 = qword_1800924A0[v11];
  if ( (_DWORD)v7 )
  {
    v17 = v7;
    do
    {
      v18 = *(_QWORD *)a2;
      if ( !wcsicmp(String1, (const wchar_t *)(*(_QWORD *)a2 + 16i64)) )
      {
        if ( !v10 )
          v10 = CCipherSuiteInfo::CCipherSuiteInfo(a4, v16, (struct _NCRYPT_SSL_CIPHER_SUITE_EX *)v18);
        *((_DWORD *)v10 + 2) |= ConvertSslVersionToSchannelProtocol(*(_DWORD *)(v18 + 4));
        if ( a7
          && *((_DWORD *)a7 + 2) != v20
          && (!wcscmp_0((const wchar_t *)(v18 + 412), L"ECDH")
           || !wcscmp_0((const wchar_t *)(v18 + 412), L"ECDH_P256")
           || !wcscmp_0((const wchar_t *)(v18 + 412), L"ECDH_P384")
           || !wcscmp_0((const wchar_t *)(v18 + 412), L"ECDH_P521")
           || !*(_WORD *)(v18 + 412)) )
        {
          *((_QWORD *)v10 + 106) = a7;
        }
        v21 = *(_DWORD *)(v18 + 276);
        v22 = *(_DWORD *)(v18 + 408) >> 3;
        v23 = v22 + 3;
        if ( dword_1800925D4 > (unsigned int)(v22 + 3) )
          v23 = dword_1800925D4;
        dword_1800925D4 = v23;
        v24 = v22 + v21;
        if ( dword_1800925D8 > (unsigned int)(v22 + v21) )
          v24 = dword_1800925D8;
        dword_1800925D8 = v24;
      }
      a2 = (struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *)((char *)a2 + 16);
      --v17;
    }
    while ( v17 );
  }
  return v10 == 0i64 ? 0x490 : 0;
}
// 1800266A7: variable 'v20' is possibly undefined
// 180092490: using guessed type __int64 qword_180092490;
// 1800924A0: using guessed type unsigned __int64 qword_1800924A0[32];
// 1800925D4: using guessed type int dword_1800925D4;
// 1800925D8: using guessed type int dword_1800925D8;

