//----- (0000000180063AB8) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeCertificateAuthoritiesExtensionSize(CTls13ServerHandshake *this)
{
  __int16 v1; // ax

  if ( *((_QWORD *)this + 22) && (v1 = *((_WORD *)this + 92)) != 0 )
  {
    *((_WORD *)this + 93) = v1 + 2;
    return 0i64;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 21i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
    return 87i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
