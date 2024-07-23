// File count: 576
// Total lines: 11
-----------------------------------------
_BOOL8 __fastcall _scrt_release_startup_lock(char a1)
{
  _BOOL8 result; // rax

  result = _scrt_is_ucrt_dll_in_use();
  if ( result && !a1 )
    _InterlockedExchange64(&_scrt_native_startup_lock, 0i64);
  return result;
}
// 180091FC8: using guessed type __int64 _scrt_native_startup_lock;
