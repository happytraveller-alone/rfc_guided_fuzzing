//----- (000000018006D824) ----------------------------------------------------
__int64 __fastcall CTls13Context::ParseCcsRecord(__int64 a1, __int64 a2, unsigned int a3, int a4, int a5)
{
  int v5; // r10d
  _BYTE *v6; // rax

  if ( !a2 )
    return 2148074333i64;
  if ( !a3 )
    return 2148074333i64;
  v5 = *(unsigned __int8 *)(a1 + 282);
  if ( (_BYTE)v5 == 0xFF )
    return 2148074333i64;
  v6 = (_BYTE *)(a2 + a3);
  if ( v6 && a4 == 1 && *v6 == 1 )
  {
    if ( (a5 & 0xFFFFFFFB) == 0 || *(_BYTE *)(a1 + 233) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
      return 2148074278i64;
    }
    else
    {
      *(_BYTE *)(a1 + 282) = v5 + 1;
      if ( (unsigned __int8)(v5 + 1) <= 5u )
      {
        return 0i64;
      }
      else
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          *(_BYTE *)(a1 + 282) = v5;
          WPP_SF_d(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x15u,
            (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
            v5);
        }
        return 2148074263i64;
      }
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
    return 2148074248i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

