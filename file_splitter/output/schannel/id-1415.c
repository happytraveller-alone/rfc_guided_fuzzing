//----- (00000001800705D4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetSelectedSrtpParameters(
        CSsl3TlsContext *this,
        __int16 a2,
        unsigned __int8 *const a3,
        char a4)
{
  __int64 v4; // rax

  v4 = *((_QWORD *)this + 101);
  if ( v4 )
  {
    if ( *(_QWORD *)(v4 + 8) )
    {
      (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
      v4 = *((_QWORD *)this + 101);
    }
  }
  else
  {
    v4 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(this, 16i64);
    *((_QWORD *)this + 101) = v4;
    if ( !v4 )
      return 14i64;
  }
  *(_WORD *)v4 = a2;
  *(_BYTE *)(*((_QWORD *)this + 101) + 2i64) = a4;
  *(_QWORD *)(*((_QWORD *)this + 101) + 8i64) = a3;
  return 0i64;
}

