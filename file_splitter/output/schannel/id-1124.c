// File count: 1124
// Total lines: 14
----------------------------------------
unsigned int __fastcall CSsl3TlsContext::ComputeRsaServerExchangeHashes(
        UCHAR *this,
        unsigned __int8 *a2,
        ULONG a3,
        unsigned __int8 *a4)
{
  unsigned int result; // eax

  result = GenerateHash(g_hMD5Provider, this, a2, a3, a4, 0x10u);
  if ( !result )
    return GenerateHash(g_hSHAProvider, this, a2, a3, a4 + 16, 0x14u);
  return result;
}
