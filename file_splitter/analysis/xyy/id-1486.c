//----- (0000000180077AE0) ----------------------------------------------------
__int64 __fastcall CNulRecord::HashFragment(CNulRecord *this)
{
  __int64 v1; // r9
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // r11
  __int64 v5; // r9
  __int64 v6; // r8
  unsigned __int64 v7; // r11

  if ( !*((_WORD *)this + 8) )
    return 87i64;
  v1 = *((_QWORD *)this + 3);
  if ( !v1 )
    return 87i64;
  v2 = *((_QWORD *)this + 4);
  if ( !v2 )
    return 87i64;
  if ( v2 >= v1 + 12 * (unsigned __int64)*((unsigned __int16 *)this + 8) )
    return 87i64;
  if ( (*(_BYTE *)(v2 + 8) & 1) == 0 )
    return 87i64;
  v3 = *((_QWORD *)this + 7);
  if ( !v3 )
    return 87i64;
  v4 = *((_QWORD *)this + 8);
  if ( v4 < v3 || !*((_DWORD *)this + 18) )
    return 87i64;
  if ( (__int64)(v4 - v3) >= *((unsigned int *)this + 18) )
  {
    v5 = *((unsigned __int16 *)this + 36);
  }
  else
  {
    v5 = (unsigned __int16)v4;
    LOWORD(v5) = v4 - *((_WORD *)this + 28);
  }
  v6 = (unsigned __int16)v5;
  v7 = v4 - (unsigned __int16)v5;
  LOBYTE(v5) = 1;
  return (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, __int64, __int64))(**((_QWORD **)this + 1) + 504i64))(
           *((_QWORD *)this + 1),
           v7,
           v6,
           v5);
}

