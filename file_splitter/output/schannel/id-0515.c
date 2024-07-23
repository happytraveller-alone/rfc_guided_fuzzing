// File count: 515
// Total lines: 31
-----------------------------------------
__int64 __fastcall _DbgpControlTracingThroughRegistry(struct _DBG_TRACE_CONTROL_BLOCK *a1, int a2)
{
  LSTATUS v4; // eax
  unsigned int v5; // edi
  DWORD v7; // [rsp+50h] [rbp+8h] BYREF
  DWORD v8; // [rsp+60h] [rbp+18h] BYREF
  unsigned int v9; // [rsp+68h] [rbp+20h] BYREF

  v7 = 4;
  v4 = RegQueryValueExW(*((HKEY *)a1 + 21), *((LPCWSTR *)a1 + 23), 0i64, &v8, (LPBYTE)&v9, &v7);
  v5 = v4;
  if ( v4 == 2 )
  {
    return 0;
  }
  else if ( !v4 )
  {
    if ( v7 >= 4 && v8 == 4 )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)((char *)a1 + 192));
      v5 = _DbgpControlTracing(a1, v9, a2);
      LeaveCriticalSection((LPCRITICAL_SECTION)((char *)a1 + 192));
    }
    else
    {
      return 1169;
    }
  }
  return v5;
}
