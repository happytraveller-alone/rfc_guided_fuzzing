// File count: 173
// Total lines: 77
-----------------------------------------
__int64 __fastcall GetCipherInfo(struct CSslUserContext *a1, struct _SecPkgContext_CipherInfo *a2)
{
  unsigned __int16 v4; // ax
  unsigned int v5; // r14d
  __int64 v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  int v12[3]; // [rsp+30h] [rbp-D0h] BYREF
  _WORD Src[64]; // [rsp+3Ch] [rbp-C4h] BYREF
  _WORD v14[64]; // [rsp+BCh] [rbp-44h] BYREF
  DWORD v15; // [rsp+13Ch] [rbp+3Ch]
  DWORD v16; // [rsp+140h] [rbp+40h]
  _WORD v17[64]; // [rsp+144h] [rbp+44h] BYREF
  DWORD v18; // [rsp+1C4h] [rbp+C4h]
  _WORD v19[64]; // [rsp+1C8h] [rbp+C8h] BYREF
  DWORD v20; // [rsp+248h] [rbp+148h]
  DWORD v21; // [rsp+24Ch] [rbp+14Ch]
  _WORD v22[72]; // [rsp+250h] [rbp+150h] BYREF

  memset_0(v12, 0, 0x2A4ui64);
  v4 = ConvertSchannelProtocolToSsl(*((_DWORD *)a1 + 6));
  v5 = SslLookupCipherSuiteInfo(
         *((_QWORD *)a1 + 11),
         v4,
         *((unsigned int *)a1 + 14),
         *((unsigned int *)a1 + 15),
         v12,
         0);
  if ( !v5 )
  {
    v6 = -1i64;
    a2->dwProtocol = v12[0];
    v7 = -1i64;
    a2->dwCipherSuite = v12[1];
    a2->dwBaseCipherSuite = v12[2];
    a2->dwVersion = 1;
    do
      ++v7;
    while ( Src[v7] );
    memcpy_0(a2->szCipherSuite, Src, 2i64 * (unsigned int)(v7 + 1));
    v8 = -1i64;
    do
      ++v8;
    while ( v14[v8] );
    memcpy_0(a2->szCipher, v14, 2i64 * (unsigned int)(v8 + 1));
    a2->dwCipherLen = v15;
    a2->dwCipherBlockLen = v16;
    v9 = -1i64;
    do
      ++v9;
    while ( v17[v9] );
    memcpy_0(a2->szHash, v17, 2i64 * (unsigned int)(v9 + 1));
    a2->dwHashLen = v18;
    v10 = -1i64;
    do
      ++v10;
    while ( v19[v10] );
    memcpy_0(a2->szExchange, v19, 2i64 * (unsigned int)(v10 + 1));
    a2->dwMinExchangeLen = v20;
    a2->dwMaxExchangeLen = v21;
    do
      ++v6;
    while ( v22[v6] );
    memcpy_0(a2->szCertificate, v22, 2i64 * (unsigned int)(v6 + 1));
    a2->dwKeyType = *((_DWORD *)a1 + 15);
  }
  return v5;
}
// 180098510: using guessed type __int64 __fastcall SslLookupCipherSuiteInfo(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 18000EDBC: using guessed type _WORD Src[64];
// 18000EDBC: using guessed type _WORD var_254[64];
// 18000EDBC: using guessed type _WORD var_1CC[64];
// 18000EDBC: using guessed type _WORD var_148[64];
// 18000EDBC: using guessed type _WORD var_C0[72];
