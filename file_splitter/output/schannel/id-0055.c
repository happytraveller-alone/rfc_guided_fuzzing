// File count: 55
// Total lines: 18
------------------------------------------
NTSTATUS __fastcall GenerateTlsHash(
        enum _eTlsHashAlgorithm a1,
        UCHAR *a2,
        unsigned __int8 *a3,
        ULONG a4,
        unsigned __int8 *a5,
        unsigned int *a6)
{
  NTSTATUS result; // eax
  BCRYPT_ALG_HANDLE hAlgorithm; // [rsp+30h] [rbp-18h] BYREF

  hAlgorithm = 0i64;
  result = TlsGetBCryptHashProvider(a1, &hAlgorithm, a6);
  if ( !result )
    return GenerateHash(hAlgorithm, a2, a3, a4, a5, *a6);
  return result;
}
