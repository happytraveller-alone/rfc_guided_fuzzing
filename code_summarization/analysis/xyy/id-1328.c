//----- (0000000180068550) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::GenerateStatusRequestExtension(CTls13ServerHandshake *this)
{
  __int64 v2; // rdi
  __int64 result; // rax
  int v4; // esi
  __int64 v5; // rcx
  char v6; // [rsp+30h] [rbp+8h] BYREF
  char v7; // [rsp+31h] [rbp+9h]
  char v8; // [rsp+32h] [rbp+Ah]
  char v9; // [rsp+33h] [rbp+Bh]

  v2 = *(_QWORD *)(*((_QWORD *)this + 1) + 1512i64);
  if ( !v2 )
    return 0i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             5,
             *((_WORD *)this + 76));
  if ( !(_DWORD)result )
  {
    v4 = *(_DWORD *)(v2 + 16);
    v5 = *((_QWORD *)this + 4);
    v7 = BYTE2(v4);
    v8 = BYTE1(v4);
    v6 = 1;
    v9 = v4;
    result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v5 + 32i64))(v5, 4i64, &v6);
    if ( !(_DWORD)result )
      return (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**((_QWORD **)this + 4) + 32i64))(
               *((_QWORD *)this + 4),
               (unsigned __int16)v4,
               *(_QWORD *)(v2 + 8));
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
