//----- (0000000180077330) ----------------------------------------------------
__int64 __fastcall CTls13Record::HashFragment(CTls13Record *this)
{
  __int64 v2; // r9
  unsigned __int64 v3; // r8
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // r11
  __int64 v6; // rcx
  __int64 v7; // r9
  __int64 v8; // r8
  unsigned __int64 v9; // r11

  if ( !*((_WORD *)this + 8) )
    return 87i64;
  v2 = *((_QWORD *)this + 3);
  if ( !v2 )
    return 87i64;
  v3 = *((_QWORD *)this + 4);
  if ( !v3 )
    return 87i64;
  if ( v3 >= v2 + 12 * (unsigned __int64)*((unsigned __int16 *)this + 8) )
    return 87i64;
  if ( (*(_BYTE *)(v3 + 8) & 1) == 0 )
    return 87i64;
  v4 = *((_QWORD *)this + 7);
  if ( !v4 )
    return 87i64;
  v5 = *((_QWORD *)this + 8);
  if ( v5 < v4 )
    return 87i64;
  v6 = v5 - v4;
  if ( *((unsigned __int16 *)this + 45) + 5i64 < (__int64)(v5 - v4) || v6 <= 5 || !*((_DWORD *)this + 18) )
    return 87i64;
  if ( v6 - 5 >= *((unsigned int *)this + 18) )
  {
    v7 = *((unsigned __int16 *)this + 36);
  }
  else
  {
    v7 = (unsigned __int16)v5;
    LOWORD(v7) = v5 - *((_WORD *)this + 28) - 5;
  }
  v8 = (unsigned __int16)v7;
  v9 = v5 - (unsigned __int16)v7;
  LOBYTE(v7) = 1;
  return (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, __int64, __int64))(**((_QWORD **)this + 1) + 504i64))(
           *((_QWORD *)this + 1),
           v9,
           v8,
           v7);
}
