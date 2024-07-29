//----- (00000001800682E8) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateServerNameExtension(CTls13ClientHandshake *this)
{
  __int64 v2; // rdi
  __int64 result; // rax
  __int64 v4; // rcx
  __int16 v5; // si
  __int64 v6; // rcx
  __int64 v7; // rcx
  unsigned __int16 v8; // si
  char v9; // [rsp+40h] [rbp+8h] BYREF
  __int16 v10; // [rsp+48h] [rbp+10h] BYREF
  __int16 v11; // [rsp+50h] [rbp+18h] BYREF

  v2 = *(_QWORD *)(*((_QWORD *)this + 2) + 40i64);
  if ( !v2 )
    return 0i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             0,
             *((_WORD *)this + 81));
  if ( !(_DWORD)result )
  {
    v4 = *((_QWORD *)this + 4);
    v5 = *((_WORD *)this + 81) - 2;
    v10 = __ROR2__(v5, 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v4 + 32i64))(v4, 2i64, &v10);
    if ( !(_DWORD)result )
    {
      v6 = *((_QWORD *)this + 4);
      v9 = 0;
      result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v6 + 32i64))(v6, 1i64, &v9);
      if ( !(_DWORD)result )
      {
        v7 = *((_QWORD *)this + 4);
        v8 = v5 - 3;
        v11 = __ROR2__(v8, 8);
        result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v7 + 32i64))(v7, 2i64, &v11);
        if ( !(_DWORD)result )
        {
          result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**((_QWORD **)this + 4) + 32i64))(
                     *((_QWORD *)this + 4),
                     v8,
                     v2);
          if ( !(_DWORD)result )
          {
            CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 0);
            return 0i64;
          }
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
