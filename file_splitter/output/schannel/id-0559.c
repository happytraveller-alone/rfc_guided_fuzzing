// File count: 559
// Total lines: 31
-----------------------------------------
_BOOL8 __fastcall dllmain_crt_process_detach(char a1)
{
  char v3; // bl
  __int64 v4; // rcx
  BOOL v5; // ebx

  if ( dword_180091A30 <= 0 )
    return 0i64;
  --dword_180091A30;
  v3 = _scrt_acquire_startup_lock();
  if ( _scrt_current_native_startup_state != 2 )
  {
    _scrt_fastfail(7u);
    __debugbreak();
    JUMPOUT(0x180027EB4i64);
  }
  _scrt_dllmain_uninitialize_c();
  __scrt_uninitialize_type_info();
  RTC_Terminate();
  _scrt_current_native_startup_state = 0;
  _scrt_release_startup_lock(v3);
  LOBYTE(v4) = a1;
  v5 = _scrt_uninitialize_crt(v4, 0) != 0;
  _scrt_dllmain_uninitialize_critical();
  return v5;
}
// 180027EB3: control flows out of bounds to 180027EB4
// 180027E92: variable 'v4' is possibly undefined
// 180091A30: using guessed type int dword_180091A30;
// 180091FC0: using guessed type int _scrt_current_native_startup_state;
