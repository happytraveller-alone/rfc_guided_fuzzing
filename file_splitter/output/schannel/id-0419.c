// File count: 419
// Total lines: 26
-----------------------------------------
void __fastcall _DbgpTraceTimerCallback(struct _DBG_TRACE_CONTROL_BLOCK *a1)
{
  union _LARGE_INTEGER *v2; // rbx
  union _LARGE_INTEGER *v3; // rcx
  struct _RTL_CRITICAL_SECTION *v4; // rdi

  if ( !*((_DWORD *)a1 + 7) )
  {
    v2 = (union _LARGE_INTEGER *)((char *)a1 + 24);
    RegSetValueExW(*((HKEY *)a1 + 21), *((LPCWSTR *)a1 + 23), 0, 4u, (const BYTE *)a1 + 24, 4u);
    v3 = v2;
LABEL_6:
    NtQuerySystemTime(v3);
    return;
  }
  if ( *((_DWORD *)a1 + 7) == -1 )
  {
    v4 = (struct _RTL_CRITICAL_SECTION *)((char *)a1 + 192);
    EnterCriticalSection((LPCRITICAL_SECTION)((char *)a1 + 192));
    _DbgpControlTracing(a1, *((_DWORD *)a1 + 6), 0);
    LeaveCriticalSection(v4);
    v3 = (union _LARGE_INTEGER *)((char *)a1 + 24);
    goto LABEL_6;
  }
}
