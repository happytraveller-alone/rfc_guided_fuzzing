// File count: 1078
// Total lines: 38
----------------------------------------
__int64 WPP_SF_SDD(__int64 a1, unsigned __int16 a2, __int64 a3, const wchar_t *a4, ...)
{
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v7; // [rsp+90h] [rbp+28h] BYREF
  va_list va; // [rsp+90h] [rbp+28h]
  va_list va1; // [rsp+98h] [rbp+30h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v7 = va_arg(va1, _QWORD);
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
  return EtwTraceMessage(
           a1,
           43i64,
           &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
           a2,
           a4,
           v5,
           (__int64 *)va,
           4i64,
           va1);
}
// 180083C60: using guessed type wchar_t aNull_0[5];
