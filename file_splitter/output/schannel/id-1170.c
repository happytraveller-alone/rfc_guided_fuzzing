//----- (000000018005DB20) ----------------------------------------------------
__int64 __fastcall ComputeIssuerCacheIndex(unsigned __int8 *a1, unsigned int a2)
{
  __int64 result; // rax
  unsigned __int8 *v3; // r8
  __int64 v4; // r9
  int v5; // ecx

  result = 0i64;
  v3 = a1;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = a2;
      do
      {
        v5 = *v3++;
        LODWORD(result) = (v5 ^ 0x55) + result;
        --v4;
      }
      while ( v4 );
    }
    return (unsigned int)result % dword_1800926FC;
  }
  return result;
}
// 1800926FC: using guessed type int dword_1800926FC;

