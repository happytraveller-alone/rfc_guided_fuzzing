// File count: 174
// Total lines: 47
-----------------------------------------
__int64 __fastcall GetOldConnectionInfo(struct CSslUserContext *a1, struct _SecPkgContext_ConnectionInfo *a2)
{
  unsigned __int16 v4; // ax
  unsigned int v5; // esi
  ALG_ID v6; // eax
  ALG_ID v7; // eax
  __int64 v8; // rdx
  ALG_ID v9; // eax
  int v11; // [rsp+30h] [rbp-348h] BYREF
  char v12[268]; // [rsp+34h] [rbp-344h] BYREF
  DWORD v13; // [rsp+140h] [rbp-238h]
  DWORD v14; // [rsp+1C8h] [rbp-1B0h]

  v11 = 1;
  memset_0(v12, 0, 0x324ui64);
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
    a2->dwProtocol = *((_DWORD *)a1 + 6);
    v6 = LookupSymmetricCipherAlg((struct _NCRYPT_SSL_CIPHER_SUITE_EX *)&v11);
    a2->aiCipher = v6;
    if ( v6 - 28672 <= 0xF )
      a2->aiCipher = 28672;
    a2->dwCipherStrength = v13;
    v7 = LookupChecksumAlg((wchar_t *)&v11);
    a2->aiHash = v7;
    if ( v7 - 36864 <= 0xF )
      a2->aiHash = 36864;
    a2->dwHashStrength = v14;
    v9 = LookupExchangeAlg((wchar_t *)&v11, v8);
    a2->aiExch = v9;
    if ( v9 - 45056 <= 4 )
      a2->aiExch = 45056;
    a2->dwExchStrength = *((_DWORD *)a1 + 7);
  }
  return v5;
}
// 18000F069: variable 'v8' is possibly undefined
// 180098510: using guessed type __int64 __fastcall SslLookupCipherSuiteInfo(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
