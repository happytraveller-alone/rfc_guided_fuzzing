//----- (00000001800653C8) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateALPNExtension(CTls13ClientHandshake *this)
{
  __int16 v1; // r8
  __int64 v3; // rsi
  __int64 result; // rax
  unsigned __int16 v5; // di
  __int64 v6; // rcx
  unsigned __int16 v7; // [rsp+40h] [rbp+8h] BYREF

  v1 = *((_WORD *)this + 82);
  if ( !v1 )
    return 0i64;
  v3 = *(_QWORD *)(*((_QWORD *)this + 1) + 784i64);
  if ( !v3 || v3 == -6 )
    return 0i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader((__int64)this, 16, v1);
  if ( (_DWORD)result )
    return result;
  v5 = *((_WORD *)this + 82) - 2;
  if ( v5 != *(_WORD *)(v3 + 4) )
    return 87i64;
  v6 = *((_QWORD *)this + 4);
  v7 = __ROR2__(v5, 8);
  result = (*(__int64 (__fastcall **)(__int64, __int64, unsigned __int16 *))(*(_QWORD *)v6 + 32i64))(v6, 2i64, &v7);
  if ( !(_DWORD)result )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids, v7);
    result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**((_QWORD **)this + 4) + 32i64))(
               *((_QWORD *)this + 4),
               v5,
               v3 + 6);
    if ( !(_DWORD)result )
    {
      *(_QWORD *)(*((_QWORD *)this + 1) + 136i64) |= 0x4000000ui64;
      CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 16);
      return 0i64;
    }
  }
  return result;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
