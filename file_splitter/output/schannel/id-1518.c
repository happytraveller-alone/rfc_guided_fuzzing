// File count: 1518
// Total lines: 26
----------------------------------------
void __fastcall _DbgpTraceControllerTimerCallback(struct _RTL_CRITICAL_SECTION *a1, char a2)
{
  struct _RTL_CRITICAL_SECTION *v2; // rbp
  struct _RTL_CRITICAL_SECTION *v4; // rdi
  PRTL_CRITICAL_SECTION_DEBUG i; // rbx
  __int64 v6; // rdx
  void (__fastcall *v7)(PRTL_CRITICAL_SECTION_DEBUG, __int64); // rax

  v2 = a1 + 2;
  v4 = a1 + 1;
  EnterCriticalSection(a1 + 2);
  for ( i = v4->DebugInfo; i != (PRTL_CRITICAL_SECTION_DEBUG)v4; i = *(PRTL_CRITICAL_SECTION_DEBUG *)&i->Type )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&i[4]);
    v7 = *(void (__fastcall **)(PRTL_CRITICAL_SECTION_DEBUG, __int64))&i[2].Flags;
    if ( v7 )
    {
      LOBYTE(v6) = a2;
      v7(i, v6);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&i[4]);
  }
  LeaveCriticalSection(v2);
}
// 18007A62A: variable 'v6' is possibly undefined
