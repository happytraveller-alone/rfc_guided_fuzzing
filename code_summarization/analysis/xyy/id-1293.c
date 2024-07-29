//----- (0000000180066274) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateEntryExtensions(__int64 a1)
{
  __int16 v1; // ax
  __int64 v3; // rcx
  __int64 result; // rax
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  v1 = *(_WORD *)(a1 + 154);
  v3 = *(_QWORD *)(a1 + 32);
  v5 = __ROR2__(v1, 8);
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v5);
  if ( !(_DWORD)result )
  {
    if ( *(_WORD *)(a1 + 154) )
    {
      if ( (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 64i64) & 0x40051555) == 0 )
        return CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateGenericExtensions(a1, 11);
      if ( !*(_WORD *)(a1 + 152) )
        return CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateGenericExtensions(a1, 11);
      result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 8i64))(a1);
      if ( !(_DWORD)result )
        return CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateGenericExtensions(a1, 11);
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

