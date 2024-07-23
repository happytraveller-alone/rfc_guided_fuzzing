// File count: 958
// Total lines: 25
-----------------------------------------
ULONG WPP_SF_ddd(TRACEHANDLE a1, __int64 a2, __int64 a3, int a4, ...)
{
  int v5; // [rsp+88h] [rbp+20h] BYREF
  __int64 v6; // [rsp+90h] [rbp+28h] BYREF
  va_list va; // [rsp+90h] [rbp+28h]
  va_list va1; // [rsp+98h] [rbp+30h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v6 = va_arg(va1, _QWORD);
  v5 = a4;
  return TraceMessage(
           a1,
           0x2Bu,
           &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
           0x51u,
           &v5,
           4i64,
           va,
           4i64,
           va1,
           4i64,
           0i64);
}
