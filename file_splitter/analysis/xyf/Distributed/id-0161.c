//----- (000000018000E714) ----------------------------------------------------
unsigned __int64 __fastcall FindSslProvHandleInCache(const unsigned __int16 *a1)
{
  __int64 v1; // rax
  _QWORD *i; // r8
  const unsigned __int16 *v4; // rdx
  int v5; // r11d
  int v6; // ecx

  v1 = 0i64;
  if ( !g_cCachedPagedSslProvs )
    return 0i64;
  for ( i = &unk_180092AA8; ; i += 2 )
  {
    v4 = a1;
    do
    {
      v5 = *(const unsigned __int16 *)((char *)v4 + *i - (_QWORD)a1);
      v6 = *v4 - v5;
      if ( v6 )
        break;
      ++v4;
    }
    while ( v5 );
    if ( !v6 )
      break;
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= g_cCachedPagedSslProvs )
      return 0i64;
  }
  return *((_QWORD *)&g_rgCachedPagedSslProvs + 2 * v1);
}
// 180092A90: using guessed type unsigned int g_cCachedPagedSslProvs;

