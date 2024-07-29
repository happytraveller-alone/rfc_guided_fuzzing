//----- (00000001800675F4) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(
        __int64 a1,
        char a2,
        unsigned __int16 a3)
{
  __int64 result; // rax
  __int64 v6; // rcx
  __int64 v7; // rcx
  __int64 v8; // rcx
  __int16 v9[12]; // [rsp+20h] [rbp-18h] BYREF
  char v10; // [rsp+50h] [rbp+18h] BYREF
  char v11; // [rsp+58h] [rbp+20h] BYREF

  if ( a3 < 4u )
    return 87i64;
  v6 = *(_QWORD *)(a1 + 32);
  v10 = a2;
  result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v6 + 32i64))(v6, 1i64, &v10);
  if ( !(_DWORD)result )
  {
    v7 = *(_QWORD *)(a1 + 32);
    v11 = 0;
    result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v7 + 32i64))(v7, 1i64, &v11);
    if ( !(_DWORD)result )
    {
      v8 = *(_QWORD *)(a1 + 32);
      v9[0] = __ROR2__(a3 - 4, 8);
      return (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v8 + 32i64))(v8, 2i64, v9);
    }
  }
  return result;
}
// 1800675F4: using guessed type __int16 var_18[12];

