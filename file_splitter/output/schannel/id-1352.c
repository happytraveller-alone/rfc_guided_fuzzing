// File count: 1352
// Total lines: 40
----------------------------------------
__int64 __fastcall CTls13Context::ExpandTrafficAndWriteKeys(
        CTls13Context *this,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 *a5,
        unsigned __int64 *a6,
        unsigned __int64 *a7,
        unsigned __int64 *a8,
        enum eSslErrorState *a9)
{
  __int64 result; // rax

  if ( !a2 || !a3 || !a4 || !a5 || !a6 || *a5 || *a6 || !a7 || !a8 || *a7 || *a8 || !a9 )
    return 87i64;
  result = SslExpandTrafficKeys(a2, a3, a4, a5, a6, 0i64, 0);
  if ( (_DWORD)result )
  {
    *(_DWORD *)a9 = 605;
    return result;
  }
  if ( !*((_BYTE *)this + 201) )
    return 0i64;
  result = SslExpandWriteKey(a2, *a5, a7, 0i64, 0);
  if ( (_DWORD)result )
  {
    *(_DWORD *)a9 = 606;
  }
  else
  {
    result = SslExpandWriteKey(a2, *a6, a8, 0i64, 0);
    if ( !(_DWORD)result )
      return 0i64;
    *(_DWORD *)a9 = 607;
  }
  return result;
}
// 1800984C0: using guessed type __int64 __fastcall SslExpandTrafficKeys(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098520: using guessed type __int64 __fastcall SslExpandWriteKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
