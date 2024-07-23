// File count: 1329
// Total lines: 48
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateSupportedGroupsExtension(CTls13ClientHandshake *this)
{
  __int64 result; // rax
  __int64 v3; // rcx
  __int64 v4; // rax
  _WORD *v5; // rdi
  _WORD *v6; // rsi
  __int64 v7; // rcx
  __int16 v8; // [rsp+40h] [rbp+8h] BYREF
  __int16 v9; // [rsp+48h] [rbp+10h] BYREF

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             10,
             *((_WORD *)this + 21));
  if ( !(_DWORD)result )
  {
    v3 = *((_QWORD *)this + 4);
    v8 = __ROR2__(*((_WORD *)this + 21) - 2, 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v8);
    if ( !(_DWORD)result )
    {
      v4 = *((_QWORD *)this + 1);
      v5 = *(_WORD **)(v4 + 912);
      v6 = v5;
      if ( v5 >= &v5[*(unsigned __int16 *)(v4 + 920)] )
      {
        return 0i64;
      }
      else
      {
        while ( 1 )
        {
          v7 = *((_QWORD *)this + 4);
          v9 = __ROR2__(*v6, 8);
          result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v7 + 32i64))(v7, 2i64, &v9);
          if ( (_DWORD)result )
            break;
          if ( ++v6 >= &v5[*(unsigned __int16 *)(*((_QWORD *)this + 1) + 920i64)] )
            return 0i64;
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
