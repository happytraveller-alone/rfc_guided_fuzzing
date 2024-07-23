// File count: 1364
// Total lines: 71
----------------------------------------
__int64 __fastcall CTls13Context::GenerateClientHelloHash(
        CTls13Context *this,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned int *a5)
{
  __int64 result; // rax
  __int64 HashInfoFromAlgorithmName; // rax
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  int v12; // [rsp+20h] [rbp-E0h]
  unsigned int v13; // [rsp+40h] [rbp-C0h] BYREF
  void *v14; // [rsp+48h] [rbp-B8h] BYREF
  __int16 Src; // [rsp+50h] [rbp-B0h] BYREF
  char v16; // [rsp+52h] [rbp-AEh]
  char v17; // [rsp+53h] [rbp-ADh]
  char v18[60]; // [rsp+54h] [rbp-ACh] BYREF
  wchar_t String1[64]; // [rsp+90h] [rbp-70h] BYREF

  if ( !a2 || !a3 || !a4 || !a5 || !*a5 )
    return 87i64;
  memset_0(String1, 0, sizeof(String1));
  memset_0(&Src, 0, 0x40ui64);
  v13 = 0;
  v14 = 0i64;
  result = SslGetCipherSuitePRFHashAlgorithm(a2, 772i64, a3, 0i64, String1, 0);
  if ( !(_DWORD)result )
  {
    HashInfoFromAlgorithmName = I_GetHashInfoFromAlgorithmName(String1);
    if ( HashInfoFromAlgorithmName )
    {
      result = TlsGetBCryptHashProvider(
                 (enum _eTlsHashAlgorithm)*(_DWORD *)(HashInfoFromAlgorithmName + 20),
                 &v14,
                 &v13);
      if ( !(_DWORD)result )
      {
        v10 = v13;
        v16 = 0;
        v12 = *a5;
        Src = 254;
        v17 = v13;
        result = BCryptHash(v14, 0i64, 0i64, a4, v12, v18, v13);
        if ( !(_DWORD)result )
        {
          v11 = v10 + 4;
          if ( v11 <= *a5 )
          {
            *a5 = v11;
            memcpy_0(a4, &Src, v11);
            return 0i64;
          }
          else
          {
            return 1359i64;
          }
        }
      }
    }
    else
    {
      return 2148074244i64;
    }
  }
  return result;
}
// 180098360: using guessed type __int64 __fastcall BCryptHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098438: using guessed type __int64 __fastcall SslGetCipherSuitePRFHashAlgorithm(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 18006BA8C: using guessed type char var_EC[60];
