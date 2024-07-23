//----- (00000001800432A8) ----------------------------------------------------
__int64 __fastcall WPP_SF_L(__int64 a1, unsigned __int16 a2, __int64 a3, int a4)
{
  __int64 v5; // [rsp+38h] [rbp-10h]
  __int64 v6; // [rsp+40h] [rbp-8h]
  int v7; // [rsp+68h] [rbp+20h] BYREF

  v7 = a4;
  return EtwTraceMessage(a1, 43i64, a3, a2, &v7, 4i64, 0i64, v5, v6);
}
// 1800432D1: variable 'v5' is possibly undefined
// 1800432D1: variable 'v6' is possibly undefined

