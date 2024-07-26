//----- (000000018004492C) ----------------------------------------------------
__int64 WPP_SF_dd(__int64 a1, unsigned __int16 a2, __int64 a3, int a4, ...)
{
  int v5; // [rsp+78h] [rbp+20h] BYREF
  va_list va; // [rsp+80h] [rbp+28h] BYREF

  va_start(va, a4);
  v5 = a4;
  return EtwTraceMessage(a1, 43i64, a3, a2, &v5, 4i64, (__int64 *)va, 4i64, 0i64);
}

