// File count: 1118
// Total lines: 41
----------------------------------------
__int64 __fastcall WPP_SF_Ss(__int64 a1, __int64 a2, __int64 a3, const wchar_t *a4, const char *a5)
{
  const char *v5; // r8
  __int64 v6; // rdx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdx

  v5 = a5;
  v6 = -1i64;
  if ( a5 )
  {
    v7 = -1i64;
    do
      ++v7;
    while ( a5[v7] );
    v8 = v7 + 1;
  }
  else
  {
    v8 = 5i64;
  }
  if ( !a5 )
    v5 = "NULL";
  if ( a4 )
  {
    do
      ++v6;
    while ( a4[v6] );
    v9 = 2 * v6 + 2;
  }
  else
  {
    v9 = 10i64;
  }
  if ( !a4 )
    a4 = L"NULL";
  return EtwTraceMessage(a1, 43i64, &WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids, 10i64, a4, v9, v5, v8, 0i64);
}
// 180083C60: using guessed type wchar_t aNull_0[5];
