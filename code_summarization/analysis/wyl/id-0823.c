//----- (0000000180043AE4) ----------------------------------------------------
__int64 __fastcall VerifyUnicodeStringIsInBuffer(const unsigned __int16 *a1, char *a2, int a3)
{
  char *v3; // rdx

  if ( a1 >= (const unsigned __int16 *)a2 )
  {
    v3 = &a2[a3 - 2];
    while ( a1 <= (const unsigned __int16 *)v3 )
    {
      if ( !*a1 )
        return 0i64;
      ++a1;
    }
  }
  return 2148074333i64;
}
