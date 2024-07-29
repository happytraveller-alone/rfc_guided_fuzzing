//----- (0000000180067D60) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::GeneratePskExtension(CTls13ServerHandshake *this)
{
  __int16 v1; // r8
  __int64 result; // rax
  __int64 v4; // rcx
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  v1 = *((_WORD *)this + 78);
  if ( !v1 )
    return 0i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader((__int64)this, 41, v1);
  if ( !(_DWORD)result )
  {
    v4 = *((_QWORD *)this + 4);
    v5 = __ROR2__(*((_WORD *)this + 94), 8);
    return (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v4 + 32i64))(v4, 2i64, &v5);
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

