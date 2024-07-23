//----- (0000000180017CCC) ----------------------------------------------------
void DeleteDebugTracing()
{
  struct _DBG_TRACE_CONTROL_BLOCK *v0; // rdi
  struct _RTL_CRITICAL_SECTION *SharedMem; // rax
  struct _RTL_CRITICAL_SECTION *v2; // rbx
  __int64 v3; // rcx
  struct _DBG_TRACE_CONTROL_BLOCK **v4; // rax
  HANDLE LockSemaphore; // rcx
  int v6; // eax
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo; // r8
  int SpinCount; // eax
  void (__stdcall *v9)(PVOID, BOOLEAN); // r8
  unsigned int OwningThread_high; // esi
  int v11; // ecx
  void *v12; // rdx

  v0 = SchannelGlobalTraceControlBlock;
  if ( (NtCurrentPeb()->BitField & 2) == 0 )
  {
    if ( SchannelGlobalTraceControlBlock )
    {
      SharedMem = (struct _RTL_CRITICAL_SECTION *)_DbgpOpenOrCreateSharedMem();
      v2 = SharedMem;
      if ( SharedMem )
      {
        EnterCriticalSection(SharedMem + 2);
        v3 = *(_QWORD *)v0;
        if ( *(struct _DBG_TRACE_CONTROL_BLOCK **)(*(_QWORD *)v0 + 8i64) != v0
          || (v4 = (struct _DBG_TRACE_CONTROL_BLOCK **)*((_QWORD *)v0 + 1), *v4 != v0) )
        {
          __fastfail(3u);
        }
        *v4 = (struct _DBG_TRACE_CONTROL_BLOCK *)v3;
        *(_QWORD *)(v3 + 8) = v4;
        LockSemaphore = v2[1].LockSemaphore;
        v6 = LODWORD(v2->SpinCount) - 1;
        LODWORD(v2->SpinCount) = v6;
        if ( LockSemaphore == *((HANDLE *)v0 + 18) )
        {
          DeleteTimerQueueTimer(0i64, (HANDLE)v2[1].SpinCount, (HANDLE)0xFFFFFFFFFFFFFFFFi64);
          v2[1].SpinCount = 0i64;
          v2[1].LockSemaphore = 0i64;
          DebugInfo = v2[1].DebugInfo;
          if ( DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)&v2[1] )
          {
            SpinCount = v2->SpinCount;
            HIDWORD(v2[1].OwningThread) = 10 * (SpinCount + 6);
            v9 = *(void (__stdcall **)(PVOID, BOOLEAN))&DebugInfo[3].Type;
            v2[1].LockSemaphore = v9;
            if ( !CreateTimerQueueTimer(
                    (PHANDLE)&v2[1].SpinCount,
                    0i64,
                    v9,
                    v2,
                    10000 * (SpinCount + 6),
                    10000 * (SpinCount + 6),
                    0) )
              v2[1].LockSemaphore = 0i64;
          }
        }
        else if ( LockSemaphore )
        {
          OwningThread_high = HIDWORD(v2[1].OwningThread);
          v11 = 10 * v6;
          if ( OwningThread_high > 10 * v6 + 120 )
          {
            v12 = (void *)v2[1].SpinCount;
            HIDWORD(v2[1].OwningThread) = v11 + 60;
            if ( !ChangeTimerQueueTimer(0i64, v12, 1000 * (v11 + 60), 1000 * (v11 + 60)) )
              HIDWORD(v2[1].OwningThread) = OwningThread_high;
          }
        }
        LeaveCriticalSection(v2 + 2);
        _DbgpDeleteTraceControl(v0);
        SchannelGlobalTraceControlBlock = 0i64;
      }
    }
  }
}

