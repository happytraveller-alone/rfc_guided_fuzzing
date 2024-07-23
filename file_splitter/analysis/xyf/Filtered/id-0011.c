//----- (0000000180001A64) ----------------------------------------------------
__int64 WppInitUm()
{
  CCipherMill *v0; // rbx
  __int64 *v1; // rdi
  __int64 result; // rax
  __int64 v3; // rsi
  HMODULE ModuleHandleW; // rax
  __int64 v5[2]; // [rsp+40h] [rbp-258h] BYREF
  __int128 v6; // [rsp+50h] [rbp-248h] BYREF
  WCHAR v7; // [rsp+60h] [rbp-238h]
  WCHAR Filename[264]; // [rsp+70h] [rbp-228h] BYREF

  v0 = WPP_GLOBAL_Control;
  v1 = &WPP_REGISTRATION_GUIDS;
  memset_0(Filename, 0, 0x208ui64);
  result = SourceString[8];
  v7 = SourceString[8];
  v6 = *(_OWORD *)L"schannel";
  while ( v0 )
  {
    v3 = *v1;
    v5[0] = v3;
    ++v1;
    v5[1] = 0i64;
    *((_QWORD *)v0 + 4) = v3;
    ModuleHandleW = GetModuleHandleW(L"schannel");
    if ( ModuleHandleW )
    {
      GetModuleFileNameW(ModuleHandleW, Filename, 0x104u);
      Filename[259] = 0;
    }
    result = EtwRegisterTraceGuidsW(WppControlCallback, v0, v3, 1i64, v5, Filename, &v6, (char *)v0 + 8);
    v0 = *(CCipherMill **)v0;
  }
  return result;
}
// 180080E10: using guessed type __int64 __fastcall EtwRegisterTraceGuidsW(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD);
// 180092A88: using guessed type __int64 WPP_REGISTRATION_GUIDS;

// 设置 Windows 性能跟踪和日志记录机制