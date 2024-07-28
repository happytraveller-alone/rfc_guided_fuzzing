//----- (00000001800524A0) ----------------------------------------------------
__int64 __fastcall SpQueryKeyInfo(struct CSslUserContext *a1, _OWORD *a2)
{
  unsigned __int16 v4; // ax
  unsigned int v5; // edi
  __int64 v6; // rdx
  unsigned __int16 *v7; // rax
  bool v8; // zf
  void *v9; // rcx
  int v11; // [rsp+30h] [rbp-348h] BYREF
  char v12[4]; // [rsp+34h] [rbp-344h] BYREF
  int v13; // [rsp+38h] [rbp-340h]
  wchar_t Source[64]; // [rsp+C0h] [rbp-2B8h] BYREF
  int v15; // [rsp+140h] [rbp-238h]
  wchar_t v16[134]; // [rsp+254h] [rbp-124h] BYREF

  v11 = 1;
  memset_0(v12, 0, 0x324ui64);
  *a2 = 0i64;
  a2[1] = 0i64;
  v4 = ConvertSchannelProtocolToSsl(*((_DWORD *)a1 + 6));
  v5 = SslLookupCipherSuiteInfo(
         *((_QWORD *)a1 + 11),
         v4,
         *((unsigned int *)a1 + 14),
         *((unsigned int *)a1 + 15),
         v12,
         0);
  if ( v5 || v13 != *((_DWORD *)a1 + 14) )
  {
    v5 = -2146893052;
  }
  else
  {
    *((_DWORD *)a2 + 4) = v15;
    *((_DWORD *)a2 + 6) = LookupSymmetricCipherAlg((struct _NCRYPT_SSL_CIPHER_SUITE_EX *)&v11);
    *((_DWORD *)a2 + 5) = LookupCertificateAlg((wchar_t *)&v11, v6);
    *((_QWORD *)a2 + 1) = AllocateAndCopyString(Source);
    v7 = AllocateAndCopyString(v16);
    v8 = *((_QWORD *)a2 + 1) == 0i64;
    *(_QWORD *)a2 = v7;
    if ( !v8 && v7 )
      return v5;
    v5 = -2146893056;
  }
  if ( *(_QWORD *)a2 )
  {
    LocalFree(*(HLOCAL *)a2);
    *(_QWORD *)a2 = 0i64;
  }
  v9 = (void *)*((_QWORD *)a2 + 1);
  if ( v9 )
  {
    LocalFree(v9);
    *((_QWORD *)a2 + 1) = 0i64;
  }
  return v5;
}
// 18005254B: variable 'v6' is possibly undefined
// 180098510: using guessed type __int64 __fastcall SslLookupCipherSuiteInfo(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 1800524A0: using guessed type wchar_t Source[64];
// 1800524A0: using guessed type wchar_t var_124[134];
