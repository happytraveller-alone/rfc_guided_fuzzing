//----- (0000000180068414) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateSignatureAlgorithmsExtension(
        __int64 a1)
{
  __int64 result; // rax
  __int64 v3; // rcx
  unsigned __int16 v4; // di
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(a1, 13, *(_WORD *)(a1 + 124));
  if ( !(_DWORD)result )
  {
    v3 = *(_QWORD *)(a1 + 32);
    v4 = *(_WORD *)(a1 + 124) - 2;
    v5 = __ROR2__(v4, 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v5);
    if ( !(_DWORD)result )
      return (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(a1 + 32) + 32i64))(
               *(_QWORD *)(a1 + 32),
               v4,
               *(_QWORD *)(a1 + 128));
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

