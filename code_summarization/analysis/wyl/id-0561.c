//----- (0000000180028370) ----------------------------------------------------
void __cdecl _security_init_cookie()
{
  uintptr_t v0; // rax
  unsigned __int64 v1; // [rsp+30h] [rbp+10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+38h] [rbp+18h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+40h] [rbp+20h] BYREF

  v0 = _security_cookie;
  if ( _security_cookie == 0x2B992DDFA232i64 )
  {
    SystemTimeAsFileTime = 0i64;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v1 = (unsigned __int64)SystemTimeAsFileTime;
    v1 ^= GetCurrentThreadId();
    v1 ^= GetCurrentProcessId();
    QueryPerformanceCounter(&PerformanceCount);
    v0 = ((unsigned __int64)&v1 ^ v1 ^ PerformanceCount.QuadPart ^ ((unsigned __int64)PerformanceCount.LowPart << 32)) & 0xFFFFFFFFFFFFi64;
    if ( v0 == 0x2B992DDFA232i64 )
      v0 = 0x2B992DDFA233i64;
    _security_cookie = v0;
  }
  _security_cookie_complement = ~v0;
}
// 180091978: using guessed type __int64 _security_cookie_complement;

