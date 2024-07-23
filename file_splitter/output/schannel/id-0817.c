// File count: 817
// Total lines: 26
-----------------------------------------
__int64 __fastcall WPP_SF_s(__int64 a1, unsigned __int16 a2, __int64 a3, const char *a4)
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
    v5 = v4 + 1;
  }
  else
  {
    v5 = 5i64;
  }
  if ( !a4 )
    a4 = "NULL";
  return EtwTraceMessage(a1, 43i64, a3, a2, a4, v5, 0i64, v7, v8);
}
// 1800433CC: variable 'v7' is possibly undefined
// 1800433CC: variable 'v8' is possibly undefined
