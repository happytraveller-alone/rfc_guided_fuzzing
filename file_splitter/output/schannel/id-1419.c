//----- (0000000180070C68) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::ValidateProtectionProfiles(unsigned __int16 *const a1, unsigned __int16 a2, int a3)
{
  CCipherMill *v4; // rcx
  __int64 v5; // rdx
  unsigned __int16 *v6; // rdx

  if ( !a1 )
    return 87i64;
  if ( a2 < 2u || (a2 & 1) != 0 || a2 > 0xFFFDu )
  {
    v4 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v5 = 81i64;
  }
  else if ( a3 || a2 == 2 )
  {
    v6 = (unsigned __int16 *const)((char *)a1 + (a2 & 0xFFFE));
    while ( 1 )
    {
      if ( a1 >= v6 )
        return 0i64;
      if ( !*a1 )
        break;
      ++a1;
    }
    v4 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v5 = 83i64;
  }
  else
  {
    v4 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v5 = 82i64;
  }
  WPP_SF_(*((_QWORD *)v4 + 2), v5, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  return 2148074278i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

