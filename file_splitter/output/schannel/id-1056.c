//----- (0000000180058E94) ----------------------------------------------------
__int64 WPP_SF_dD(__int64 a1, unsigned __int16 a2, __int64 a3, int a4, ...)
{
  int v5; // [rsp+78h] [rbp+20h] BYREF
  va_list va; // [rsp+80h] [rbp+28h] BYREF

  va_start(va, a4);
  v5 = a4;
  return EtwTraceMessage(
           a1,
           43i64,
           &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids,
           a2,
           &v5,
           4i64,
           (__int64 *)va,
           4i64,
           0i64);
}

