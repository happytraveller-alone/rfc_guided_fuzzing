//----- (0000000180053180) ----------------------------------------------------
ULONG WPP_SF_SSSdiiDDDDDddiDDd(
        TRACEHANDLE LoggerHandle,
        __int64 a2,
        __int64 a3,
        const wchar_t *a4,
        const wchar_t *a5,
        const wchar_t *a6,
        char a7,
        char a8,
        char a9,
        char a10,
        char a11,
        char a12,
        char a13,
        char a14,
        char a15,
        char a16,
        ...)
{
  const wchar_t *v16; // r8
  __int64 v17; // rax
  __int64 v19; // rdx
  __int64 v20; // r10
  const wchar_t *v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rdx
  __int64 v24; // rax
  __int64 v26; // [rsp+1D8h] [rbp+10h] BYREF
  va_list va; // [rsp+1D8h] [rbp+10h]
  __int64 v28; // [rsp+1E0h] [rbp+18h] BYREF
  va_list va1; // [rsp+1E0h] [rbp+18h]
  __int64 v30; // [rsp+1E8h] [rbp+20h] BYREF
  va_list va2; // [rsp+1E8h] [rbp+20h]
  va_list va3; // [rsp+1F0h] [rbp+28h] BYREF

  va_start(va3, a16);
  va_start(va2, a16);
  va_start(va1, a16);
  va_start(va, a16);
  v26 = va_arg(va1, _QWORD);
  va_copy(va2, va1);
  v28 = va_arg(va2, _QWORD);
  va_copy(va3, va2);
  v30 = va_arg(va3, _QWORD);
  v16 = a6;
  v17 = -1i64;
  if ( a6 )
  {
    v19 = -1i64;
    do
      ++v19;
    while ( a6[v19] );
    v20 = 2 * v19 + 2;
  }
  else
  {
    v20 = 10i64;
  }
  v21 = a5;
  if ( !a6 )
    v16 = L"NULL";
  if ( a5 )
  {
    v22 = -1i64;
    do
      ++v22;
    while ( a5[v22] );
    v23 = 2 * v22 + 2;
  }
  else
  {
    v23 = 10i64;
  }
  if ( !a5 )
    v21 = L"NULL";
  if ( a4 )
  {
    do
      ++v17;
    while ( a4[v17] );
    v24 = 2 * v17 + 2;
  }
  else
  {
    v24 = 10i64;
  }
  if ( !a4 )
    a4 = L"NULL";
  return TraceMessage(
           LoggerHandle,
           0x2Bu,
           &WPP_809cf5b92bc53f9217359848f5040da5_Traceguids,
           0xAu,
           a4,
           v24,
           v21,
           v23,
           v16,
           v20,
           &a7,
           4i64,
           &a8,
           8i64,
           &a9,
           8i64,
           &a10,
           4i64,
           &a11,
           4i64,
           &a12,
           4i64,
           &a13,
           4i64,
           &a14,
           4i64,
           &a15,
           4i64,
           &a16,
           4i64,
           va,
           8i64,
           va1,
           4i64,
           va2,
           4i64,
           va3,
           4i64,
           0i64);
}
// 180083C60: using guessed type wchar_t aNull_0[5];
