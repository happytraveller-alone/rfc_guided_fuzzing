// File count: 1485
// Total lines: 53
----------------------------------------
__int64 __fastcall CNulRecord::EndOfMessage(CNulRecord *this)
{
  __int64 v2; // rdx
  unsigned __int64 v3; // r8
  __int64 v4; // rax
  unsigned __int64 v5; // rax
  __int64 result; // rax
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rax

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
  v4 = *((_QWORD *)this + 6);
  if ( !v4 )
    return 87i64;
  if ( !*(_QWORD *)(v4 + 8) )
    return 87i64;
  v5 = *((_QWORD *)this + 7);
  if ( !v5 || *((_QWORD *)this + 8) < v5 || !*((_DWORD *)this + 18) )
    return 87i64;
  if ( (*(_BYTE *)(v3 + 8) & 1) == 0
    || (result = (*(__int64 (__fastcall **)(CNulRecord *))(*(_QWORD *)this + 48i64))(this), !(_DWORD)result) )
  {
    v7 = *((_QWORD *)this + 4);
    if ( v7 < *((_QWORD *)this + 3) + 4 * (3 * (unsigned __int64)*((unsigned __int16 *)this + 8) - 3) )
    {
      v8 = v7 + 12;
    }
    else
    {
      *((_WORD *)this + 8) = 0;
      v8 = 0i64;
      *((_QWORD *)this + 3) = 0i64;
      *((_DWORD *)this + 10) = 0;
      *((_QWORD *)this + 6) = 0i64;
      *((_QWORD *)this + 7) = 0i64;
      *((_QWORD *)this + 8) = 0i64;
    }
    *((_QWORD *)this + 4) = v8;
    result = 0i64;
    *((_DWORD *)this + 18) = 0;
  }
  return result;
}
