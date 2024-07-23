// File count: 1238
// Total lines: 62
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::SelectSrtpParameters(
        CSsl3TlsServerContext *this,
        unsigned __int16 *const a2,
        unsigned __int16 a3,
        unsigned __int8 *const a4,
        unsigned __int8 a5)
{
  unsigned __int8 *v9; // rsi
  char v10; // bp
  __int64 result; // rax
  unsigned __int16 *v12; // rax
  __int16 MatchingProtectionProfile; // r15
  unsigned __int8 *v14; // rax
  unsigned int v15; // edi

  v9 = 0i64;
  v10 = 0;
  result = CSsl3TlsContext::ValidateProtectionProfiles(a2, a3, 1);
  if ( !(_DWORD)result )
  {
    v12 = (unsigned __int16 *)*((_QWORD *)this + 100);
    if ( !v12 )
      return 87i64;
    if ( a4 )
    {
      if ( !a5 )
        return 87i64;
    }
    else if ( a5 )
    {
      return 87i64;
    }
    MatchingProtectionProfile = CSsl3TlsContext::FindMatchingProtectionProfile(v12 + 1, *v12, a2, a3);
    if ( !MatchingProtectionProfile )
    {
      CSsl3TlsContext::FreeSelectedSrtpParameters(this);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 62i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      return 0i64;
    }
    if ( a5 && *((_BYTE *)this + 988) )
    {
      v14 = (unsigned __int8 *)(*(__int64 (__fastcall **)(CSsl3TlsServerContext *, _QWORD))(*(_QWORD *)this + 8i64))(
                                 this,
                                 a5);
      v9 = v14;
      if ( !v14 )
        return 14i64;
      memcpy_0(v14, a4, a5);
      v10 = a5;
    }
    v15 = CSsl3TlsContext::SetSelectedSrtpParameters(this, MatchingProtectionProfile, v9, v10);
    if ( !v15 )
      return 0i64;
    if ( v9 )
      (*(void (__fastcall **)(CSsl3TlsServerContext *, unsigned __int8 *))(*(_QWORD *)this + 16i64))(this, v9);
    return v15;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
