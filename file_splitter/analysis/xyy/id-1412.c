//----- (0000000180070304) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::RestoreWriteCipherState(CSsl3TlsContext *this)
{
  __int16 v1; // ax

  if ( *((_BYTE *)this + 233) && *((_BYTE *)this + 264) )
  {
    v1 = *((_WORD *)this + 117);
    *((_WORD *)this + 16) &= 2u;
    *((_WORD *)this + 16) |= v1;
    *((_QWORD *)this + 19) = *((_QWORD *)this + 30);
    *((_QWORD *)this + 21) = *((_QWORD *)this + 31);
    *((_QWORD *)this + 23) = *((_QWORD *)this + 32);
    *((_WORD *)this + 117) = 0;
    *((_QWORD *)this + 30) = 0i64;
    *((_QWORD *)this + 31) = 0i64;
    *((_QWORD *)this + 32) = 0i64;
    *((_BYTE *)this + 264) = 0;
  }
  return 0i64;
}
