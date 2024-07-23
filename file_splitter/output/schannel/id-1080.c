// File count: 1080
// Total lines: 41
----------------------------------------
__int64 __fastcall WPP_SF_sS(__int64 a1, __int64 a2, __int64 a3, const char *a4, const wchar_t *a5)
{
  const wchar_t *v5; // rdx
  __int64 v6; // rax
  __int64 v7; // r8
  __int64 v8; // r8
  __int64 v9; // rax

  v5 = a5;
  v6 = -1i64;
  if ( a5 )
  {
    v7 = -1i64;
    do
      ++v7;
    while ( a5[v7] );
    v8 = 2 * v7 + 2;
  }
  else
  {
    v8 = 10i64;
  }
  if ( !a5 )
    v5 = L"NULL";
  if ( a4 )
  {
    do
      ++v6;
    while ( a4[v6] );
    v9 = v6 + 1;
  }
  else
  {
    v9 = 5i64;
  }
  if ( !a4 )
    a4 = "NULL";
  return EtwTraceMessage(a1, 43i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids, 28i64, a4, v9, v5, v8, 0i64);
}
// 180083C60: using guessed type wchar_t aNull_0[5];
