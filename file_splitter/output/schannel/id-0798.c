//----- (0000000180041D70) ----------------------------------------------------
__int64 __fastcall WPP_SF_S(__int64 a1, unsigned __int16 a2, __int64 a3, const wchar_t *a4)
{
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v7; // [rsp+38h] [rbp-10h]
  __int64 v8; // [rsp+40h] [rbp-8h]

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
  return EtwTraceMessage(a1, 43i64, a3, a2, a4, v5, 0i64, v7, v8);
}
// 180041DBF: variable 'v7' is possibly undefined
// 180041DBF: variable 'v8' is possibly undefined
// 180083C60: using guessed type wchar_t aNull_0[5];

