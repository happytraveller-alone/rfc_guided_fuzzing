// File count: 1314
// Total lines: 48
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateKeyShareEntry(__int64 a1)
{
  __int64 result; // rax
  __int16 v3; // ax
  __int64 v4; // rcx
  __int64 v5; // rcx
  __int16 v6; // [rsp+30h] [rbp+8h] BYREF
  __int16 v7; // [rsp+38h] [rbp+10h] BYREF

  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 68i64) == 40 && g_fEnableHelloRetryRequest )
  {
    *(_WORD *)(a1 + 44) = 0;
    return 0i64;
  }
  else
  {
    v3 = *(_WORD *)(a1 + 44);
    v4 = *(_QWORD *)(a1 + 32);
    v6 = __ROR2__(v3, 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v4 + 32i64))(v4, 2i64, &v6);
    if ( !(_DWORD)result )
    {
      v5 = *(_QWORD *)(a1 + 32);
      v7 = __ROR2__(*(_WORD *)(a1 + 48) + *(unsigned __int8 *)(a1 + 46), 8);
      result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v5 + 32i64))(v5, 2i64, &v7);
      if ( !(_DWORD)result )
      {
        if ( !*(_BYTE *)(a1 + 46) )
          return (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)(a1 + 32) + 32i64))(
                   *(_QWORD *)(a1 + 32),
                   *(unsigned __int16 *)(a1 + 48),
                   *(_QWORD *)(a1 + 56) + 8i64);
        result = (*(__int64 (__fastcall **)(_QWORD, __int64, void *))(**(_QWORD **)(a1 + 32) + 32i64))(
                   *(_QWORD *)(a1 + 32),
                   1i64,
                   &unk_1800858AA);
        if ( !(_DWORD)result )
          return (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)(a1 + 32) + 32i64))(
                   *(_QWORD *)(a1 + 32),
                   *(unsigned __int16 *)(a1 + 48),
                   *(_QWORD *)(a1 + 56) + 8i64);
      }
    }
  }
  return result;
}
// 1800927A0: using guessed type int g_fEnableHelloRetryRequest;
