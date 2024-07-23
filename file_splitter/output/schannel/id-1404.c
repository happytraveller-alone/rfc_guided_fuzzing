// File count: 1404
// Total lines: 41
----------------------------------------
__int64 __fastcall CSsl3TlsContext::FindMatchingProtectionProfile(
        unsigned __int16 *const a1,
        unsigned __int16 a2,
        unsigned __int16 *const a3,
        unsigned __int16 a4)
{
  unsigned __int16 *v4; // r10
  unsigned __int16 *v5; // r9
  unsigned __int16 *v6; // rax
  unsigned __int16 v7; // dx

  if ( !a1 )
    return 0i64;
  if ( !a2 )
    return 0i64;
  if ( !a3 )
    return 0i64;
  if ( !a4 )
    return 0i64;
  v4 = (unsigned __int16 *const)((char *)a1 + (a2 & 0xFFFE));
  if ( a1 >= v4 )
    return 0i64;
  v5 = (unsigned __int16 *const)((char *)a3 + (a4 & 0xFFFE));
  while ( 1 )
  {
    v6 = a3;
    if ( a3 < v5 )
      break;
LABEL_11:
    if ( ++a1 >= v4 )
      return 0i64;
  }
  v7 = *a1;
  while ( v7 != *v6 )
  {
    if ( ++v6 >= v5 )
      goto LABEL_11;
  }
  return v7;
}
