//----- (0000000180016DA0) ----------------------------------------------------
__int64 __fastcall SpDeleteUserModeContext(__int64 a1)
{
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  SslDeleteUserContext(a1);
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

