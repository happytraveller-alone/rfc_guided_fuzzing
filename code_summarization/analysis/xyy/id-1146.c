//----- (000000018005CB48) ----------------------------------------------------
__int64 WPP_SF_SSd(__int64 a1, __int64 a2, __int64 a3, const wchar_t *a4, const wchar_t *a5, ...)
{
  const wchar_t *v5; // r8
  __int64 v6; // rax
  __int64 v7; // r10
  __int64 v8; // rdx
  __int64 v9; // rdx
  bool v10; // zf
  va_list va; // [rsp+98h] [rbp+30h] BYREF

  va_start(va, a5);
  v5 = a5;
  v6 = -1i64;
  v7 = 10i64;
  if ( a5 )
  {
    v8 = -1i64;
    do
      ++v8;
    while ( a5[v8] );
    v9 = 2 * v8 + 2;
  }
  else
  {
    v9 = 10i64;
  }
  if ( !a5 )
    v5 = L"NULL";
  v10 = a4 == 0i64;
  if ( a4 )
  {
    do
      ++v6;
    while ( a4[v6] );
    v7 = 2 * v6 + 2;
    v10 = a4 == 0i64;
  }
  if ( v10 )
    a4 = L"NULL";
  return EtwTraceMessage(a1, 43i64, &WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids, 13i64, a4, v7, v5, v9, va);
}
// 180083C60: using guessed type wchar_t aNull_0[5];

