//----- (00000001800684B0) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateStatusRequestExtension(CTls13ClientHandshake *this)
{
  __int16 v1; // r8
  __int64 result; // rax
  __int64 v4; // rcx
  __int64 v5; // rcx
  char v6; // [rsp+30h] [rbp+8h] BYREF
  int v7; // [rsp+38h] [rbp+10h] BYREF

  v1 = *((_WORD *)this + 76);
  if ( !v1 )
    return 0i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader((__int64)this, 5, v1);
  if ( !(_DWORD)result )
  {
    v4 = *((_QWORD *)this + 4);
    v6 = 1;
    result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v4 + 32i64))(v4, 1i64, &v6);
    if ( !(_DWORD)result )
    {
      v5 = *((_QWORD *)this + 4);
      v7 = 0;
      return (*(__int64 (__fastcall **)(__int64, __int64, int *))(*(_QWORD *)v5 + 32i64))(v5, 4i64, &v7);
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

