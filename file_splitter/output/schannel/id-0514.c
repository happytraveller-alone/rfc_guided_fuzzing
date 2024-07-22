//----- (00000001800260E0) ----------------------------------------------------
void __fastcall _DbgpRegistryChangeNotifycationCallback(void *a1, unsigned __int8 a2)
{
  int v2; // r14d
  struct _RTL_CRITICAL_SECTION *SharedMem; // rax
  struct _RTL_CRITICAL_SECTION *v5; // rbx
  struct _RTL_CRITICAL_SECTION *v6; // rsi
  struct _RTL_CRITICAL_SECTION *v7; // rbx
  PRTL_CRITICAL_SECTION_DEBUG i; // rdi

  v2 = a2;
  SharedMem = (struct _RTL_CRITICAL_SECTION *)_DbgpOpenOrCreateSharedMem();
  v5 = SharedMem;
  if ( SharedMem )
  {
    v6 = SharedMem + 2;
    EnterCriticalSection(SharedMem + 2);
    v7 = v5 + 1;
    for ( i = v7->DebugInfo; i != (PRTL_CRITICAL_SECTION_DEBUG)v7; i = *(PRTL_CRITICAL_SECTION_DEBUG *)&i->Type )
    {
      if ( *(void **)&i[4].Flags == a1 )
      {
        EnterCriticalSection((LPCRITICAL_SECTION)&i[4]);
        _DbgpControlTracingThroughRegistry((struct _DBG_TRACE_CONTROL_BLOCK *)i, v2);
        RegNotifyChangeKeyValue((HKEY)i[3].ProcessLocksList.Blink, 0, 4u, i[3].CriticalSection, 1);
        LeaveCriticalSection((LPCRITICAL_SECTION)&i[4]);
        break;
      }
    }
    LeaveCriticalSection(v6);
  }
}

