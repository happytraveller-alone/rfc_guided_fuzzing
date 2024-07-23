// File count: 1315
// Total lines: 22
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateKeyShareExtension(CTls13ClientHandshake *this)
{
  __int64 result; // rax
  __int64 v3; // rcx
  __int16 v4; // [rsp+30h] [rbp+8h] BYREF

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             51,
             *((_WORD *)this + 26));
  if ( !(_DWORD)result )
  {
    v3 = *((_QWORD *)this + 4);
    v4 = __ROR2__(*((_WORD *)this + 26) - 2, 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v4);
    if ( !(_DWORD)result )
      return CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateKeyShareEntry((__int64)this);
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
