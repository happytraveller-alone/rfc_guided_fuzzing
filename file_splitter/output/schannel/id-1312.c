// File count: 1312
// Total lines: 25
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::GenerateHRRExtensions(CTls13ServerHandshake *this)
{
  __int16 v1; // ax
  __int64 v3; // rcx
  __int64 result; // rax
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  v1 = *((_WORD *)this + 20);
  v3 = *((_QWORD *)this + 4);
  v5 = __ROR2__(v1, 8);
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v5);
  if ( !(_DWORD)result )
  {
    result = CTls13ServerHandshake::GenerateSupportedVersionsExtension(this);
    if ( !(_DWORD)result )
    {
      result = CTls13ServerHandshake::GenerateNamedGroupExtension(this);
      if ( !(_DWORD)result )
        return CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateGenericExtensions((__int64)this, 2);
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
