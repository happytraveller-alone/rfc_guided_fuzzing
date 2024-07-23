// File count: 280
// Total lines: 12
-----------------------------------------
__int64 __fastcall SpMarshallSupplementalCreds(__int64 a1, unsigned __int8 *a2, unsigned int *a3, char **a4)
{
  if ( a2 && *(_DWORD *)a2 >= 3u )
  {
    if ( *(_DWORD *)a2 <= 4u )
      return SpMarshallSupplementalCredsV4(a1, a2, a3, a4);
    if ( *(_DWORD *)a2 == 5 )
      return SpMarshallSupplementalCredsV5(a1, a2, a3, (void **)a4);
  }
  return 3221225485i64;
}
