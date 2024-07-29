//----- (000000018004DE38) ----------------------------------------------------
char __fastcall CSslUserContext::DTLSCheckRecordValidity(CSslUserContext *this, unsigned __int64 a2)
{
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // r10
  char v5; // cl
  __int64 v6; // rax
  unsigned __int64 v7; // r8
  __int64 v8; // rax

  v2 = *((_QWORD *)this + 16) + 63i64;
  v3 = a2 & 0xFFFFFFFFFFFFi64;
  if ( *((_DWORD *)this + 29) == -1 )
    return 1;
  if ( HIWORD(a2) != *((_DWORD *)this + 29) )
    return 0;
  if ( v3 <= v2 )
  {
    v7 = v2 - v3;
    if ( v7 >= 0x40 )
      return 0;
    v8 = *((_QWORD *)this + 15);
    if ( _bittest64(&v8, v7) )
      return 0;
    *((_QWORD *)this + 15) = v8 | (1i64 << v7);
    return 1;
  }
  v5 = 1;
  if ( v3 - v2 >= 0x40 )
    v6 = 1i64;
  else
    v6 = (*((_QWORD *)this + 15) << ((unsigned __int8)a2 - (unsigned __int8)v2)) | 1i64;
  *((_QWORD *)this + 15) = v6;
  *((_QWORD *)this + 16) = v3 - 63;
  return v5;
}

