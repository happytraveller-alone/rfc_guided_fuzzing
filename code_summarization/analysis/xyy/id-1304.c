//----- (0000000180066F08) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCookieExtension(__int64 a1)
{
  __int16 v2; // r8
  __int64 result; // rax
  __int64 v4; // rcx
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  if ( !*(_QWORD *)(a1 + 88) )
    return 0i64;
  if ( !*(_WORD *)(a1 + 96) )
    return 0i64;
  v2 = *(_WORD *)(a1 + 98);
  if ( !v2 )
    return 0i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(a1, 44, v2);
  if ( !(_DWORD)result )
  {
    v4 = *(_QWORD *)(a1 + 32);
    v5 = __ROR2__(*(_WORD *)(a1 + 96), 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v4 + 32i64))(v4, 2i64, &v5);
    if ( !(_DWORD)result )
    {
      if ( v5 )
        return (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(a1 + 32) + 32i64))(
                 *(_QWORD *)(a1 + 32),
                 *(unsigned __int16 *)(a1 + 96),
                 *(_QWORD *)(a1 + 88));
      else
        return 315i64;
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
