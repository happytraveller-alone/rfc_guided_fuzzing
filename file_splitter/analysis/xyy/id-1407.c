//----- (000000018006FE4C) ----------------------------------------------------
void __fastcall CSsl3TlsContext::FreeSavedWriteCipherState(CSsl3TlsContext *this)
{
  if ( *((_BYTE *)this + 233) && *((_BYTE *)this + 264) )
  {
    if ( !*((_QWORD *)this + 30) )
      SslFreeObject(0i64, 0i64);
    *((_WORD *)this + 117) = 0;
    *((_QWORD *)this + 30) = 0i64;
    *((_QWORD *)this + 31) = 0i64;
    *((_QWORD *)this + 32) = 0i64;
    *((_BYTE *)this + 264) = 0;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

