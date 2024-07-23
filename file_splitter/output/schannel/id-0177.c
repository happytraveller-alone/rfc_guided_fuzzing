// File count: 177
// Total lines: 64
-----------------------------------------
__int64 __fastcall LookupSymmetricCipherAlg(struct _NCRYPT_SSL_CIPHER_SUITE_EX *a1)
{
  wchar_t *v1; // rdi
  unsigned int v3; // ebx
  int v4; // eax
  __int64 v6; // rdx
  __int64 v7; // r8
  unsigned int v8; // [rsp+30h] [rbp+8h] BYREF

  v1 = (wchar_t *)((char *)a1 + 144);
  v3 = 0;
  if ( !wcscmp_0((const wchar_t *)a1 + 72, L"AES") )
  {
    v4 = *((_DWORD *)a1 + 68);
    if ( v4 == 256 )
    {
      return 26128;
    }
    else
    {
      v3 = 26129;
      if ( v4 == 128 )
        return 26126;
    }
  }
  else if ( !wcscmp_0(v1, L"DES") )
  {
    return 26113;
  }
  else if ( !wcscmp_0(v1, L"RC4") )
  {
    return 26625;
  }
  else if ( !wcscmp_0(v1, L"3DES") )
  {
    return 26115;
  }
  else if ( *v1 )
  {
    v8 = 0;
    if ( wcscmp_0(v1, L"CHACHA20_POLY1305") )
    {
      if ( (unsigned int)I_GetCipherDetailsFromAlgorithmName(v1, v6, v7, &v8)
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xDu,
          (__int64)&WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids,
          v1);
      }
      return v8;
    }
  }
  else
  {
    return 24576;
  }
  return v3;
}
// 1800386FD: variable 'v6' is possibly undefined
// 1800386FD: variable 'v7' is possibly undefined
