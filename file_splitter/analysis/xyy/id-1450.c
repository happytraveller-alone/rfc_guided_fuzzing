//----- (0000000180073B00) ----------------------------------------------------
__int64 WPP_SF_DDi(__int64 a1, __int64 a2, __int64 a3, int a4, ...)
{
  int v5; // [rsp+88h] [rbp+20h] BYREF
  __int64 v6; // [rsp+90h] [rbp+28h] BYREF
  va_list va; // [rsp+90h] [rbp+28h]
  va_list va1; // [rsp+98h] [rbp+30h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v6 = va_arg(va1, _QWORD);
  v5 = a4;
  return EtwTraceMessage(
           a1,
           43i64,
           &WPP_7c40084571853895c7781ddf48bb701c_Traceguids,
           33i64,
           &v5,
           4i64,
           (__int64 *)va,
           4i64,
           va1);
}
