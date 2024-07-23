// File count: 1330
// Total lines: 42
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateSupportedVersionsExtension(CTls13ClientHandshake *this)
{
  __int64 result; // rax
  __int64 v3; // rcx
  _WORD *v4; // rbx
  __int64 v5; // rcx
  char v6; // [rsp+30h] [rbp+8h] BYREF
  __int16 v7; // [rsp+38h] [rbp+10h] BYREF

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
             (__int64)this,
             43,
             *((unsigned __int8 *)this + 54));
  if ( !(_DWORD)result )
  {
    v3 = *((_QWORD *)this + 4);
    v6 = *((_BYTE *)this + 54) - 1;
    result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v3 + 32i64))(v3, 1i64, &v6);
    if ( !(_DWORD)result )
    {
      v4 = &TlsVersions;
      while ( 1 )
      {
        if ( (*(_DWORD *)(*((_QWORD *)this + 1) + 64i64) & *(_DWORD *)v4) != 0 )
        {
          v5 = *((_QWORD *)this + 4);
          v7 = __ROR2__(v4[2], 8);
          result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v5 + 32i64))(v5, 2i64, &v7);
          if ( (_DWORD)result )
            break;
        }
        v4 += 4;
        if ( v4 >= (_WORD *)WPP_922678f99ae534148d3bb024010f1556_Traceguids )
          return 0i64;
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
