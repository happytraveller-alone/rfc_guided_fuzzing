// File count: 1058
// Total lines: 16
----------------------------------------
__int64 __fastcall WPP_SF_dDDs(__int64 a1, __int64 a2, __int64 a3, int a4, char a5, char a6, __int64 a7)
{
  __int64 v7; // rax
  int v9; // [rsp+98h] [rbp+20h] BYREF

  v9 = a4;
  if ( a7 )
  {
    v7 = -1i64;
    do
      ++v7;
    while ( *(_BYTE *)(a7 + v7) );
  }
  return EtwTraceMessage(a1, 43i64, &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids, 12i64, &v9, 4i64, &a5, 4i64, &a6);
}
