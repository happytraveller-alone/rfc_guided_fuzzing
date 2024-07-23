// File count: 1358
// Total lines: 64
----------------------------------------
__int64 __fastcall CTls13Context::GenerateApplicationWriteKeys(
        CTls13Context *this,
        __int64 a2,
        __int64 a3,
        unsigned __int64 *a4,
        unsigned __int64 *a5,
        enum eSslErrorState *a6)
{
  __int64 v10; // rdx
  __int64 *v11; // r14
  __int64 result; // rax
  unsigned int MasterKey; // [rsp+88h] [rbp+10h]

  if ( !a2 )
    return 87i64;
  if ( !a3 )
    return 87i64;
  if ( !a4 )
    return 87i64;
  if ( !a5 )
    return 87i64;
  if ( *a4 )
    return 87i64;
  if ( *a5 )
    return 87i64;
  if ( !a6 )
    return 87i64;
  v10 = *((_QWORD *)this + 6);
  if ( !v10 )
    return 87i64;
  v11 = (__int64 *)((char *)this + 72);
  if ( *((_QWORD *)this + 9) || *((_QWORD *)this + 12) )
    return 87i64;
  MasterKey = SslExtractMasterKey(a2, v10, (char *)this + 72, 0i64, 0);
  SslFreeObject(*((_QWORD *)this + 6), 0i64);
  result = MasterKey;
  *((_QWORD *)this + 6) = 0i64;
  if ( MasterKey )
  {
    *(_DWORD *)a6 = 711;
  }
  else
  {
    result = SslExpandExporterMasterKey(a2, *v11, a3, (char *)this + 96, 0i64, 0);
    if ( (_DWORD)result )
      *(_DWORD *)a6 = 608;
    else
      return CTls13Context::ExpandTrafficAndWriteKeys(
               this,
               a2,
               *v11,
               a3,
               (unsigned __int64 *)this + 10,
               (unsigned __int64 *)this + 11,
               a4,
               a5,
               a6);
  }
  return result;
}
// 180098488: using guessed type __int64 __fastcall SslExpandExporterMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098498: using guessed type __int64 __fastcall SslExtractMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
