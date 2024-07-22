//----- (0000000180067DD4) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::GeneratePskKeyExchangeModesExtension(CTls13ClientHandshake *this)
{
  __int64 result; // rax
  __int64 v3; // rcx
  __int64 v4; // rcx
  char v5; // [rsp+30h] [rbp+8h] BYREF
  char v6; // [rsp+38h] [rbp+10h] BYREF

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             45,
             *((_WORD *)this + 83));
  if ( !(_DWORD)result )
  {
    v3 = *((_QWORD *)this + 4);
    v5 = 1;
    result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v3 + 32i64))(v3, 1i64, &v5);
    if ( !(_DWORD)result )
    {
      v4 = *((_QWORD *)this + 4);
      v6 = 1;
      result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v4 + 32i64))(v4, 1i64, &v6);
      if ( !(_DWORD)result )
      {
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 45);
        return 0i64;
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

