// File count: 327
// Total lines: 14
-----------------------------------------
__int64 __fastcall CSslContextManager::RunBalancer(CSslContextManager *this, int a2)
{
  unsigned __int32 v3; // eax

  if ( a2 && *((_QWORD *)this + 7) && *((_DWORD *)this + 5) >= 0x64u )
  {
    v3 = *((_DWORD *)this + 6);
    if ( v3 > *((_DWORD *)this + 7) )
      _InterlockedExchange((volatile __int32 *)this + 7, v3);
    *((_DWORD *)this + 6) = 0;
  }
  return 0i64;
}
