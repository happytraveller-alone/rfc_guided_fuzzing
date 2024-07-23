//----- (00000001800613D0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::SetNegotiatedSrtpParameters(
        CSsl3TlsClientContext *this,
        unsigned __int16 *const a2,
        unsigned __int16 a3,
        unsigned __int8 *const a4,
        unsigned __int8 a5)
{
  unsigned __int8 *v9; // rsi
  __int64 v10; // rbp
  __int64 result; // rax
  unsigned __int16 *v12; // rax
  __int16 MatchingProtectionProfile; // r12
  CCipherMill *v14; // rcx
  __int64 v15; // rdx
  unsigned __int8 *v16; // rax
  const void *v17; // r14
  unsigned __int8 *v18; // rax
  unsigned int v19; // ebx

  v9 = 0i64;
  LOBYTE(v10) = 0;
  result = CSsl3TlsContext::ValidateProtectionProfiles(a2, a3, 0);
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
      v14 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v15 = 70i64;
LABEL_29:
      WPP_SF_(*((_QWORD *)v14 + 2), v15, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      return 2148074278i64;
    }
    if ( a5 )
    {
      v16 = (unsigned __int8 *)*((_QWORD *)this + 167);
      if ( !v16 )
      {
        v14 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v15 = 71i64;
        goto LABEL_29;
      }
      v10 = *v16;
      v17 = v16 + 1;
      if ( a5 != (_BYTE)v10 || RtlCompareMemory(a4, v16 + 1, *v16) != v10 )
      {
        v14 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v15 = 72i64;
        goto LABEL_29;
      }
      v18 = (unsigned __int8 *)(*(__int64 (__fastcall **)(CSsl3TlsClientContext *, _QWORD))(*(_QWORD *)this + 8i64))(
                                 this,
                                 (unsigned int)v10);
      v9 = v18;
      if ( !v18 )
        return 14i64;
      memcpy_0(v18, v17, (unsigned int)v10);
    }
    v19 = CSsl3TlsContext::SetSelectedSrtpParameters(this, MatchingProtectionProfile, v9, v10);
    if ( v19 )
    {
      if ( v9 )
        (*(void (__fastcall **)(CSsl3TlsClientContext *, unsigned __int8 *))(*(_QWORD *)this + 16i64))(this, v9);
      return v19;
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

