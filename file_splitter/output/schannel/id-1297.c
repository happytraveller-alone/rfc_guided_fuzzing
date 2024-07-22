//----- (000000018006669C) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateMsg(__int64 a1)
{
  __int64 result; // rax
  __int64 v3; // rax
  char v4; // al
  __int64 v5; // rcx
  char v6; // [rsp+30h] [rbp+8h] BYREF

  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(a1, 11, *(_WORD *)(a1 + 136));
  if ( !(_DWORD)result )
  {
    v3 = *(_QWORD *)(a1 + 8);
    v4 = (*(_DWORD *)(v3 + 64) & 0x40051555) != 0 ? 0 : *(_BYTE *)(v3 + 1600);
    v5 = *(_QWORD *)(a1 + 32);
    v6 = v4;
    result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v5 + 32i64))(v5, 1i64, &v6);
    if ( !(_DWORD)result )
    {
      if ( !v6 )
        goto LABEL_10;
      if ( !*(_QWORD *)(*(_QWORD *)(a1 + 8) + 1592i64) )
        return 2148074244i64;
      result = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(a1 + 32) + 32i64))(*(_QWORD *)(a1 + 32));
      if ( !(_DWORD)result )
      {
LABEL_10:
        result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateList(a1);
        if ( !(_DWORD)result )
          return (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(a1 + 32) + 40i64))(*(_QWORD *)(a1 + 32));
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

