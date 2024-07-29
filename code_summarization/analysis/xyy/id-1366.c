//----- (000000018006C430) ----------------------------------------------------
__int64 __fastcall CTls13Context::GenerateHandshakeWriteKeys(
        CTls13Context *this,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int16 a5,
        unsigned int a6,
        char a7,
        unsigned __int64 *a8,
        unsigned __int64 *a9,
        enum eSslErrorState *a10)
{
  __int64 *v14; // r15
  __int64 result; // rax
  unsigned int HandshakeKey; // r12d

  if ( !a2 )
    return 87i64;
  if ( !a3 )
    return 87i64;
  if ( !a4 )
    return 87i64;
  if ( !a8 )
    return 87i64;
  if ( !a9 )
    return 87i64;
  if ( *a8 )
    return 87i64;
  if ( *a9 )
    return 87i64;
  if ( !a10 )
    return 87i64;
  if ( !*((_QWORD *)this + 5) )
    return 87i64;
  v14 = (__int64 *)((char *)this + 48);
  if ( *((_QWORD *)this + 6) )
    return 87i64;
  if ( a7
    || (CTls13Context::FreeEarlyKey(this),
        result = SslExtractEarlyKey(a2, 0i64, (char *)this + 104, a5, a6, 0i64, 0),
        !(_DWORD)result) )
  {
    HandshakeKey = SslExtractHandshakeKey(a2, a3, *((_QWORD *)this + 5), *((_QWORD *)this + 13), v14, 0i64, 0);
    CTls13Context::FreeEarlyKey(this);
    SslFreeObject(*((_QWORD *)this + 5), 0i64);
    *((_QWORD *)this + 5) = 0i64;
    if ( HandshakeKey )
    {
      *(_DWORD *)a10 = 710;
      return HandshakeKey;
    }
    else
    {
      return CTls13Context::ExpandTrafficAndWriteKeys(
               this,
               a2,
               *v14,
               a4,
               (unsigned __int64 *)this + 7,
               (unsigned __int64 *)this + 8,
               a8,
               a9,
               a10);
    }
  }
  else
  {
    *(_DWORD *)a10 = 709;
  }
  return result;
}
// 1800984B0: using guessed type __int64 __fastcall SslExtractHandshakeKey(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 1800984B8: using guessed type __int64 __fastcall SslExtractEarlyKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

