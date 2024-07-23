// File count: 1414
// Total lines: 15
----------------------------------------
__int64 __fastcall CSsl3TlsContext::SaveWriteCipherState(CSsl3TlsContext *this)
{
  if ( *((_BYTE *)this + 233) )
  {
    if ( *((_BYTE *)this + 264) )
      CSsl3TlsContext::FreeSavedWriteCipherState(this);
    *((_WORD *)this + 117) = *((_WORD *)this + 16);
    *((_QWORD *)this + 30) = *((_QWORD *)this + 19);
    *((_QWORD *)this + 31) = *((_QWORD *)this + 21);
    *((_QWORD *)this + 32) = *((_QWORD *)this + 23);
    *((_BYTE *)this + 264) = 1;
  }
  return 0i64;
}
