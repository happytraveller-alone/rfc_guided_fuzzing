// File count: 1491
// Total lines: 32
----------------------------------------
__int64 __fastcall CTls13ExtClient::ParseCookieExtension(
        CTls13ExtClient *this,
        unsigned __int8 *a2,
        unsigned __int16 a3)
{
  unsigned int v3; // r9d
  __int16 v4; // r8
  __int64 v5; // rcx

  v3 = 0;
  if ( !a2 )
    return 2148074248i64;
  if ( a3 < 2u )
    return 2148074248i64;
  if ( *(_DWORD *)(*((_QWORD *)this + 1) + 68i64) != 100 )
    return 2148074248i64;
  v4 = a3 - 2;
  if ( !v4 )
    return 2148074248i64;
  v5 = *((_QWORD *)this + 8);
  if ( *(_QWORD *)(v5 + 1744) || *(_WORD *)(v5 + 1752) )
  {
    return 315;
  }
  else
  {
    *(_WORD *)(v5 + 1752) = v4;
    *(_QWORD *)(v5 + 1744) = a2 + 2;
  }
  return v3;
}
