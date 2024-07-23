// File count: 1451
// Total lines: 21
----------------------------------------
__int64 WPP_SF_P(__int64 a1, unsigned __int16 a2, __int64 a3, ...)
{
  __int64 v4; // [rsp+38h] [rbp-10h]
  __int64 v5; // [rsp+40h] [rbp-8h]
  va_list va; // [rsp+68h] [rbp+20h] BYREF

  va_start(va, a3);
  return EtwTraceMessage(
           a1,
           43i64,
           &WPP_7c40084571853895c7781ddf48bb701c_Traceguids,
           a2,
           (__int64 *)va,
           8i64,
           0i64,
           v4,
           v5);
}
// 180073B9C: variable 'v4' is possibly undefined
// 180073B9C: variable 'v5' is possibly undefined
