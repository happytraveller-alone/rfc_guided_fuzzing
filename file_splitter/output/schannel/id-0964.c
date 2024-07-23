// File count: 964
// Total lines: 12
-----------------------------------------
ULONG WPP_SF_qD(TRACEHANDLE a1, USHORT a2, const GUID *a3, ...)
{
  __int64 v4; // [rsp+78h] [rbp+20h] BYREF
  va_list va; // [rsp+78h] [rbp+20h]
  va_list va1; // [rsp+80h] [rbp+28h] BYREF

  va_start(va1, a3);
  va_start(va, a3);
  v4 = va_arg(va1, _QWORD);
  return TraceMessage(a1, 0x2Bu, a3, a2, va, 8i64, va1, 4i64, 0i64);
}
