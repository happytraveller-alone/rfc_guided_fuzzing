//----- (00000001800687B4) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::GenerateSupportedVersionsExtension(CTls13ServerHandshake *this)
{
  __int64 result; // rax
  __int64 v3; // rcx
  __int16 v4; // [rsp+30h] [rbp+8h] BYREF

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             43,
             *((unsigned __int8 *)this + 54));
  if ( !(_DWORD)result )
  {
    v3 = *((_QWORD *)this + 4);
    v4 = 1027;
    return (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v4);
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
