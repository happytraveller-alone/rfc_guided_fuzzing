//----- (000000018006F7A0) ----------------------------------------------------
char __fastcall CSsl3TlsContext::CheckRecordValidity(CSsl3TlsContext *this, unsigned __int64 a2)
{
  unsigned __int64 v3; // r9
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rax
  char v6; // cl
  char v7; // al
  __int64 v8; // rax
  unsigned __int64 v9; // rcx
  __int64 v10; // rax

  v3 = a2 & 0xFFFFFFFFFFFFi64;
  v4 = *((_QWORD *)this + 26) + 63i64;
  v5 = *((int *)this + 48);
  if ( (_DWORD)v5 == -1 )
    return 1;
  if ( HIWORD(a2) < v5 )
    return 0;
  if ( v3 <= v4 )
  {
    v9 = v4 - v3;
    if ( v9 >= 0x40 )
      return 0;
    v10 = *((_QWORD *)this + 25);
    if ( _bittest64(&v10, v9) )
    {
      if ( !*((_BYTE *)this + 232) )
        return 0;
      --**((_DWORD **)this + 72);
      v10 = *((_QWORD *)this + 25);
      *((_BYTE *)this + 232) = 0;
    }
    *((_QWORD *)this + 25) = v10 | (1i64 << v9);
    return 1;
  }
  v7 = a2 - v4;
  if ( v3 - v4 >= 0x40 )
  {
    v6 = 1;
    v8 = 1i64;
  }
  else
  {
    v6 = 1;
    v8 = (*((_QWORD *)this + 25) << v7) | 1i64;
  }
  *((_QWORD *)this + 25) = v8;
  *((_QWORD *)this + 26) = v3 - 63;
  return v6;
}

