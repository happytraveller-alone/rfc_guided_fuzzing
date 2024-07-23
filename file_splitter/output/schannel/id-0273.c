// File count: 273
// Total lines: 73
-----------------------------------------
__int64 TlsInitializeDefaultAlgorithms()
{
  _QWORD *v0; // rax
  __int64 v1; // rdx
  char *v2; // rcx
  _QWORD *v3; // rax
  char *v4; // rcx
  __int64 v5; // rdx
  wchar_t ***v6; // rax
  wchar_t **v7; // rcx
  __int64 v8; // rdx
  __int16 ***v9; // rax
  __int16 **v10; // rcx
  __int64 v11; // rdx

  v0 = g_pHashInfo;
  v1 = 7i64;
  v2 = (char *)&unk_18007D340;
  do
  {
    *v0 = v2;
    v2 += 24;
    ++v0;
    --v1;
  }
  while ( v1 );
  g_dwHashInfoTotalCount = 7;
  v3 = &g_pSignatureInfo;
  v4 = (char *)&unk_18007D290;
  v5 = 7i64;
  do
  {
    *v3 = v4;
    v4 += 24;
    ++v3;
    --v5;
  }
  while ( v5 );
  g_dwSignatureInfoTotalCount = 7;
  v6 = (wchar_t ***)&g_pKeyExchangeInfo;
  v7 = &off_18007D1E0;
  v8 = 7i64;
  do
  {
    *v6 = v7;
    v7 += 3;
    ++v6;
    --v8;
  }
  while ( v8 );
  g_dwKeyExchangeInfoTotalCount = 7;
  v9 = (__int16 ***)&g_pCipherInfo;
  v10 = &off_18007D100;
  v11 = 7i64;
  do
  {
    *v9 = v10;
    v10 += 4;
    ++v9;
    --v11;
  }
  while ( v11 );
  g_dwCipherInfoTotalCount = 7;
  return 0i64;
}
// 18007D100: using guessed type __int16 *off_18007D100;
// 18007D1E0: using guessed type wchar_t *off_18007D1E0;
// 180092218: using guessed type int g_dwSignatureInfoTotalCount;
// 180092320: using guessed type int g_dwCipherInfoTotalCount;
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];
// 1800923B0: using guessed type int g_dwKeyExchangeInfoTotalCount;
