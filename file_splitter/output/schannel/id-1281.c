// File count: 1281
// Total lines: 37
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::ComputeServerNameExtensionSize(CTls13ClientHandshake *this)
{
  CTlsExtClient *v1; // rbx
  const unsigned __int16 *v3; // rax
  unsigned int v4; // ebx
  __int64 v6; // rcx
  __int64 v7; // rax

  v1 = (CTlsExtClient *)*((_QWORD *)this + 2);
  *((_WORD *)this + 81) = 0;
  v3 = (const unsigned __int16 *)(*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 1) + 320i64))(*((_QWORD *)this + 1));
  v4 = CTlsExtClient::BuildServerNameString(v1, v3);
  if ( v4 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
    return v4;
  }
  else
  {
    v6 = *(_QWORD *)(*((_QWORD *)this + 2) + 40i64);
    if ( v6 )
    {
      v7 = -1i64;
      do
        ++v7;
      while ( *(_BYTE *)(v6 + v7) );
      if ( (_WORD)v7 )
        *((_WORD *)this + 81) = v7 + 5;
    }
    return 0i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
