//----- (000000018005A04C) ----------------------------------------------------
__int64 __fastcall WPP_SF_DS(__int64 a1, unsigned __int16 a2, __int64 a3, int a4, const wchar_t *a5)
{
  const wchar_t *v5; // r8
  __int64 v6; // rax
  __int64 v7; // rax
  int v9; // [rsp+78h] [rbp+20h] BYREF

  v9 = a4;
  v5 = a5;
  if ( a5 )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( a5[v6] );
    v7 = 2 * v6 + 2;
  }
  else
  {
    v7 = 10i64;
  }
  if ( !a5 )
    v5 = L"NULL";
  return EtwTraceMessage(a1, 43i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids, a2, &v9, 4i64, v5, v7, 0i64);
}
// 180083C60: using guessed type wchar_t aNull_0[5];
