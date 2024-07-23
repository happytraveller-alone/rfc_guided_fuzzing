// File count: 1322
// Total lines: 57
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::GenerateSelectedALPNExtension(CTls13ServerHandshake *this)
{
  _DWORD *v2; // rax
  _DWORD *v3; // rdi
  __int64 result; // rax
  __int64 v5; // rcx
  unsigned __int16 v6; // si
  unsigned __int8 v7; // [rsp+40h] [rbp+8h] BYREF
  __int16 v8; // [rsp+48h] [rbp+10h] BYREF

  if ( !*((_WORD *)this + 83) )
    return 0i64;
  v2 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 1) + 88i64))(*((_QWORD *)this + 1));
  v3 = v2;
  if ( !v2 || *v2 != 1 || v2[1] != 2 )
    return 0i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             16,
             *((_WORD *)this + 83));
  if ( !(_DWORD)result )
  {
    v5 = *((_QWORD *)this + 4);
    v6 = *((_WORD *)this + 83) - 2;
    v8 = __ROR2__(v6, 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v5 + 32i64))(v5, 2i64, &v8);
    if ( !(_DWORD)result )
    {
      v7 = *((_BYTE *)v3 + 8);
      if ( v6 != v7 + 1i64 )
        return 87i64;
      result = (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned __int8 *))(**((_QWORD **)this + 4) + 32i64))(
                 *((_QWORD *)this + 4),
                 1i64,
                 &v7);
      if ( !(_DWORD)result )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 33i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids, v6);
        result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**((_QWORD **)this + 4) + 32i64))(
                   *((_QWORD *)this + 4),
                   v7,
                   (__int64)v3 + 9);
        if ( !(_DWORD)result )
        {
          CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 16);
          return 0i64;
        }
      }
    }
  }
  return result;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
