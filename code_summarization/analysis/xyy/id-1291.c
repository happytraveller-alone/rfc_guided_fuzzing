//----- (0000000180065FEC) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateEntry(
        __int64 a1,
        __int64 a2,
        char a3)
{
  unsigned __int16 v5; // di
  __int64 v6; // rsi
  __int64 v7; // r9
  __int64 result; // rax
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int16 v12[20]; // [rsp+20h] [rbp-28h] BYREF
  char v13; // [rsp+58h] [rbp+10h] BYREF
  __int16 v14; // [rsp+68h] [rbp+20h] BYREF

  v5 = 0;
  v6 = 0i64;
  v7 = 65530i64;
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 16) > 0xFFFAu )
      return 87i64;
    v5 = *(_WORD *)(a2 + 16);
    v6 = *(_QWORD *)(a2 + 8);
  }
  if ( a3 )
  {
    v7 = 65530 - (unsigned int)v5;
    if ( (int)v7 < *(unsigned __int16 *)(a1 + 154) )
      return 87i64;
  }
  v9 = *(_QWORD *)(a1 + 32);
  v13 = 0;
  result = (*(__int64 (__fastcall **)(__int64, __int64, char *, __int64))(*(_QWORD *)v9 + 32i64))(v9, 1i64, &v13, v7);
  if ( !(_DWORD)result )
  {
    v10 = *(_QWORD *)(a1 + 32);
    v14 = __ROR2__(v5, 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v10 + 32i64))(v10, 2i64, &v14);
    if ( !(_DWORD)result )
    {
      if ( !v6
        || (result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)(a1 + 32) + 32i64))(
                       *(_QWORD *)(a1 + 32),
                       v5,
                       v6),
            !(_DWORD)result) )
      {
        if ( a3 )
        {
          return CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateEntryExtensions(a1);
        }
        else
        {
          v11 = *(_QWORD *)(a1 + 32);
          v12[0] = 0;
          return (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v11 + 32i64))(v11, 2i64, v12);
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180065FEC: using guessed type __int16 var_28[20];
