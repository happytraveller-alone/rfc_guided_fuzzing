//----- (0000000180070690) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetSelectedTBParameters(
        CSsl3TlsContext *this,
        char a2,
        char a3,
        unsigned __int8 *const a4,
        unsigned __int16 a5)
{
  __int64 v5; // rax

  v5 = *((_QWORD *)this + 103);
  if ( v5 )
  {
    if ( *(_QWORD *)(v5 + 8) )
    {
      (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
      v5 = *((_QWORD *)this + 103);
    }
  }
  else
  {
    v5 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(this, 16i64);
    *((_QWORD *)this + 103) = v5;
    if ( !v5 )
      return 14i64;
  }
  *(_BYTE *)v5 = a2;
  *(_BYTE *)(*((_QWORD *)this + 103) + 1i64) = a3;
  *(_WORD *)(*((_QWORD *)this + 103) + 2i64) = a5;
  *(_QWORD *)(*((_QWORD *)this + 103) + 8i64) = a4;
  return 0i64;
}

