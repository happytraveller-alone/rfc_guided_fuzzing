// File count: 1079
// Total lines: 25
----------------------------------------
__int64 WPP_SF_Sd(__int64 a1, unsigned __int16 a2, __int64 a3, const wchar_t *a4, ...)
{
  __int64 v4; // rax
  __int64 v5; // rax
  va_list va; // [rsp+80h] [rbp+28h] BYREF

  va_start(va, a4);
  if ( a4 )
  {
    v4 = -1i64;
    do
      ++v4;
    while ( a4[v4] );
    v5 = 2 * v4 + 2;
  }
  else
  {
    v5 = 10i64;
  }
  if ( !a4 )
    a4 = L"NULL";
  return EtwTraceMessage(a1, 43i64, a3, a2, a4, v5, va, 4i64, 0i64);
}
// 180083C60: using guessed type wchar_t aNull_0[5];
