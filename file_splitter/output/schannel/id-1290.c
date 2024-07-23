// File count: 1290
// Total lines: 36
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::GenerateCertificateAuthoritiesExtension(CTls13ServerHandshake *this)
{
  __int64 result; // rax
  __int64 v3; // rcx
  __int16 v4; // [rsp+30h] [rbp+8h] BYREF

  if ( *((_QWORD *)this + 22) && *((_WORD *)this + 92) )
  {
    result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
               (__int64)this,
               47,
               *((_WORD *)this + 93));
    if ( !(_DWORD)result )
    {
      v3 = *((_QWORD *)this + 4);
      v4 = __ROR2__(*((_WORD *)this + 92), 8);
      result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v4);
      if ( !(_DWORD)result )
        return (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**((_QWORD **)this + 4) + 32i64))(
                 *((_QWORD *)this + 4),
                 *((unsigned __int16 *)this + 92),
                 *((_QWORD *)this + 22));
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
    return 87i64;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
