//----- (0000000180067E74) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateRenegotiationInfoExtension(CTls13ClientHandshake *this)
{
  __int64 result; // rax
  __int64 v3; // rcx
  char v4; // [rsp+38h] [rbp+10h] BYREF

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader((__int64)this, 65281, 1);
  if ( !(_DWORD)result )
  {
    v3 = *((_QWORD *)this + 4);
    v4 = 0;
    return (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v3 + 32i64))(v3, 1i64, &v4);
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

