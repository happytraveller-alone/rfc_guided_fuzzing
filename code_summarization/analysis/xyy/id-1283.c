//----- (0000000180065254) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::ComputeSupportedVersionsExtensionSize(CTls13ClientHandshake *this)
{
  __int64 v1; // r9
  _DWORD *v2; // r8
  unsigned __int8 v3; // dl
  __int64 result; // rax

  v1 = *((_QWORD *)this + 1);
  v2 = &TlsVersions;
  *((_BYTE *)this + 54) = 0;
  do
  {
    v3 = *((_BYTE *)this + 54);
    if ( (*(_DWORD *)(v1 + 64) & *v2) != 0 )
    {
      v3 += 2;
      *((_BYTE *)this + 54) = v3;
    }
    v2 += 2;
  }
  while ( v2 < WPP_922678f99ae534148d3bb024010f1556_Traceguids );
  if ( v3 < 2u )
    return 87i64;
  result = 0i64;
  *((_BYTE *)this + 54) = v3 + 1;
  return result;
}
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];

