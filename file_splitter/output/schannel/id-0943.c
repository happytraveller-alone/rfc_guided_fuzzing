// File count: 943
// Total lines: 44
-----------------------------------------
__int64 __fastcall HandleSpecialMessage(
        struct CSslUserContext *a1,
        unsigned __int8 *a2,
        int a3,
        enum eTlsRecordType *a4)
{
  int v4; // eax
  int v8; // eax

  v4 = *((_DWORD *)a1 + 6);
  if ( (v4 & 0x800A2AAA) != 0 && !a3 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    return 2148074248i64;
  }
  if ( (v4 & 0x40051555) != 0 && a3 == 4 )
  {
    if ( *a2 || a2[1] || a2[2] || a2[3] || (v4 & 0x1000) != 0 )
      return 2148074248i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    v8 = 22;
  }
  else
  {
    if ( a3 != 2 || (unsigned __int8)(*a2 - 1) > 1u )
      return 2148074248i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_dd(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xCu,
        (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
        *a2,
        a2[1]);
    if ( !IsValidAlert(a2[1]) )
      return 2148074248i64;
    v8 = 21;
  }
  *(_DWORD *)a4 = v8;
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
