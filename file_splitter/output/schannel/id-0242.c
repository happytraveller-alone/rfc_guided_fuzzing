// File count: 242
// Total lines: 34
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::UpdateHandshakeHash(CSsl3TlsContext *this, unsigned __int8 *a2, unsigned int a3)
{
  __int64 v6; // rbx
  _QWORD *v7; // rax
  __int64 v8; // rcx
  unsigned int v9; // r14d

  if ( !a2 )
    return 0i64;
  if ( !a3 )
    return 0i64;
  if ( !*a2 )
    return 0i64;
  v6 = 0i64;
  if ( !*((_DWORD *)this + 137) )
    return 0i64;
  while ( 1 )
  {
    v7 = (_QWORD *)*((_QWORD *)this + 1);
    v8 = v7 ? *v7 : 0i64;
    v9 = SslHashHandshake(v8, *((_QWORD *)this + v6 + 74), a2, a3, 0);
    if ( v9 )
      break;
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= *((_DWORD *)this + 137) )
      return 0i64;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids, v9);
  return v9;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098420: using guessed type __int64 __fastcall SslHashHandshake(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
