//----- (0000000180024B84) ----------------------------------------------------
__int64 __fastcall GetSslEccCurveOrder(BYTE **a1, unsigned __int16 *a2)
{
  __int64 result; // rax
  const unsigned __int16 *v5; // rdx

  if ( a2 )
    *(_DWORD *)a2 = 0;
  if ( !a1 )
    return 3221225485i64;
  result = ReadMultiSzFromRegistry(L"Software\\Policies\\Microsoft\\Cryptography\\Configuration\\SSL\\00010002", a2, a1);
  if ( (_DWORD)result )
  {
    result = ReadMultiSzFromRegistry(
               L"System\\CurrentControlSet\\Control\\Cryptography\\Configuration\\Local\\SSL\\00010002",
               v5,
               a1);
    if ( !(_DWORD)result )
      *(_DWORD *)a2 = 0;
  }
  else
  {
    *(_DWORD *)a2 = 1;
  }
  return result;
}
// 180024BBE: variable 'v5' is possibly undefined

