// File count: 1376
// Total lines: 25
----------------------------------------
__int64 __fastcall CTls13Context::HashPostHandshakeMessage(
        CTls13Context *this,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        unsigned int a5)
{
  _QWORD *v7; // rbx
  __int64 result; // rax

  if ( !*((_BYTE *)this + 233) || !a2 || !a5 || !a4 || !a3 )
    return 1359i64;
  if ( ((*a4 - 11) & 0xF9) != 0 || *a4 == 17 )
    return 0i64;
  v7 = (_QWORD *)((char *)this + 240);
  if ( *((_QWORD *)this + 30) )
    return SslHashHandshake(a2, *v7, a4, a5, 0);
  result = SslDuplicateTranscriptHash(a2, a3, (char *)this + 240, 0i64);
  if ( !(_DWORD)result )
    return SslHashHandshake(a2, *v7, a4, a5, 0);
  return result;
}
// 180098420: using guessed type __int64 __fastcall SslHashHandshake(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098558: using guessed type __int64 __fastcall SslDuplicateTranscriptHash(_QWORD, _QWORD, _QWORD, _QWORD);
