// File count: 441
// Total lines: 37
-----------------------------------------
__int64 __fastcall CTls13ExtServer::ParseExtension(__int64 a1, int a2, unsigned __int8 *a3, __int64 a4)
{
  unsigned __int16 v5; // si
  int v7; // r8d
  unsigned int v9; // eax
  __int64 result; // rax

  v5 = a4;
  v7 = (unsigned __int8)*(_DWORD *)(a1 + 16);
  v9 = v7 | (a2 << 8);
  if ( v9 >= 0x2901 )
  {
    switch ( v9 )
    {
      case 0x2901u:
        return CTls13ExtServer::ParsePreSharedKeyExtension((CTls13ExtServer *)a1, a3, a4, a4);
      case 0x2B01u:
        return CTls13ExtServer::ParseSupportedVersionsExtension((CTls13ExtServer *)a1, a3, a4);
      case 0x2D01u:
        return CTls13ExtServer::ParsePskKeyExchangeModesExtension((CTls13ExtServer *)a1, a3, a4, a4);
      case 0x3101u:
        if ( (_WORD)a4 )
          return 2148074248i64;
        *(_BYTE *)(*(_QWORD *)(a1 + 40) + 1506i64) = 1;
        return 0i64;
      case 0x3301u:
        return CTls13ExtServer::ParseKeyShareExtension((CTls13ExtServer *)a1, a3, a4);
    }
  }
  if ( (_WORD)a2 != 57 && (_WORD)a2 != 0xFFA5 )
    return CTlsExtServer::ParseExtension(a1, a2, a3, v5);
  result = CTls13Context::RetrieveGenericExtension(*(_QWORD *)(a1 + 40) + 1000i64, a2, v7, (__int64)a3, a4);
  if ( !(_DWORD)result )
    return CTlsExtServer::ParseExtension(a1, a2, a3, v5);
  return result;
}
