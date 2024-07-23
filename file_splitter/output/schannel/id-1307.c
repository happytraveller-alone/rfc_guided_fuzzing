// File count: 1307
// Total lines: 23
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
        __int64 a1,
        __int16 a2,
        __int16 a3)
{
  __int64 v4; // rcx
  __int64 result; // rax
  __int64 v7; // rcx
  __int16 v8; // [rsp+30h] [rbp+8h] BYREF
  __int16 v9; // [rsp+48h] [rbp+20h] BYREF

  v4 = *(_QWORD *)(a1 + 32);
  v8 = __ROR2__(a2, 8);
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v4 + 32i64))(v4, 2i64, &v8);
  if ( !(_DWORD)result )
  {
    v7 = *(_QWORD *)(a1 + 32);
    v9 = __ROR2__(a3, 8);
    return (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v7 + 32i64))(v7, 2i64, &v9);
  }
  return result;
}
