//----- (0000000180029FA0) ----------------------------------------------------
__int64 _scrt_initialize_thread_safe_statics()
{
  HMODULE ModuleHandleW; // rbx
  FARPROC ProcAddress; // rdi
  FARPROC v2; // rax

  InitializeCriticalSectionAndSpinCount(&CriticalSection, 0xFA0u);
  ModuleHandleW = GetModuleHandleW(L"api-ms-win-core-synch-l1-2-0.dll");
  if ( !ModuleHandleW )
  {
    ModuleHandleW = GetModuleHandleW(L"kernel32.dll");
    if ( !ModuleHandleW )
      goto LABEL_9;
  }
  ProcAddress = GetProcAddress(ModuleHandleW, "SleepConditionVariableCS");
  v2 = GetProcAddress(ModuleHandleW, "WakeAllConditionVariable");
  if ( ProcAddress && v2 )
  {
    qword_1800920B8 = (__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))ProcAddress;
    qword_1800920C0 = (__int64 (__fastcall *)(_QWORD))v2;
    goto LABEL_7;
  }
  hHandle = CreateEventW(0i64, 1, 0, 0i64);
  if ( !hHandle )
  {
LABEL_9:
    _scrt_fastfail(7u);
    JUMPOUT(0x18002A06Fi64);
  }
LABEL_7:
  if ( !_scrt_initialize_onexit_tables(0) )
    goto LABEL_9;
  atexit(_scrt_uninitialize_thread_safe_statics);
  return 0i64;
}
// 18002A06A: control flows out of bounds to 18002A06F
// 1800920B8: using guessed type __int64 (__fastcall *qword_1800920B8)(_QWORD, _QWORD, _QWORD);
// 1800920C0: using guessed type __int64 (__fastcall *qword_1800920C0)(_QWORD);

