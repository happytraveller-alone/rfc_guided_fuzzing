//----- (00000001800445A4) ----------------------------------------------------
__int64 McTemplateU0pp_EtwEventWriteTransfer(__int64 a1, __int64 a2, ...)
{
  _QWORD v3[3]; // [rsp+30h] [rbp-48h] BYREF
  int v4; // [rsp+48h] [rbp-30h]
  int v5; // [rsp+4Ch] [rbp-2Ch]
  va_list v6; // [rsp+50h] [rbp-28h]
  int v7; // [rsp+58h] [rbp-20h]
  int v8; // [rsp+5Ch] [rbp-1Ch]
  va_list va; // [rsp+90h] [rbp+18h]
  __int64 v10; // [rsp+90h] [rbp+18h] BYREF
  va_list va1; // [rsp+98h] [rbp+20h] BYREF

  va_start(va1, a2);
  va_start(va, a2);
  v10 = va_arg(va1, _QWORD);
  va_copy((va_list)&v3[2], va);
  v5 = 0;
  v4 = 8;
  va_copy(v6, va1);
  v8 = 0;
  v7 = 8;
  return McGenEventWrite_EtwEventWriteTransfer(8i64, (__int64)&AscStart, v10, 3, (__int64)v3);
}

