//----- (000000018004F8F0) ----------------------------------------------------
ULONG WPP_SF_DDDDD(TRACEHANDLE a1, __int64 a2, __int64 a3, int a4, ...)
{
  int v5; // [rsp+A8h] [rbp+20h] BYREF
  __int64 v6; // [rsp+B0h] [rbp+28h] BYREF
  va_list va; // [rsp+B0h] [rbp+28h]
  __int64 v8; // [rsp+B8h] [rbp+30h] BYREF
  va_list va1; // [rsp+B8h] [rbp+30h]
  __int64 v10; // [rsp+C0h] [rbp+38h] BYREF
  va_list va2; // [rsp+C0h] [rbp+38h]
  va_list va3; // [rsp+C8h] [rbp+40h] BYREF

  va_start(va3, a4);
  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v6 = va_arg(va1, _QWORD);
  va_copy(va2, va1);
  v8 = va_arg(va2, _QWORD);
  va_copy(va3, va2);
  v10 = va_arg(va3, _QWORD);
  v5 = a4;
  return TraceMessage(
           a1,
           0x2Bu,
           &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
           0x65u,
           &v5,
           4i64,
           va,
           4i64,
           va1,
           4i64,
           va2,
           4i64,
           va3,
           4i64,
           0i64);
}

