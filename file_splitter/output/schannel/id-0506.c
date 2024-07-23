// File count: 506
// Total lines: 85
-----------------------------------------
void __fastcall InitDebugTracingEx(
        const unsigned __int16 *a1,
        const unsigned __int16 *a2,
        struct _GUID *a3,
        const unsigned __int16 *a4)
{
  struct _RTL_CRITICAL_SECTION *SharedMem; // rax
  struct _RTL_CRITICAL_SECTION *v5; // rbx
  struct _DBG_TRACE_CONTROL_BLOCK **v6; // rcx
  struct _DBG_TRACE_CONTROL_BLOCK *v7; // rdi
  int SpinCount; // ecx
  unsigned int OwningThread_high; // esi
  struct _DBG_TRACE_CONTROL_BLOCK *v10; // rcx
  const unsigned __int16 *DueTime; // [rsp+20h] [rbp-28h]
  int Period; // [rsp+28h] [rbp-20h]
  struct _DBG_TRACE_CONTROL_BLOCK *v13; // [rsp+68h] [rbp+20h] BYREF

  v13 = 0i64;
  if ( (NtCurrentPeb()->BitField & 2) != 0 )
  {
    SchannelGlobalTraceControlBlock = 0i64;
    return;
  }
  if ( (((unsigned __int64)SchannelGlobalTraceControlBlock + 1) & 0xFFFFFFFFFFFFFFFEui64) == 0 )
  {
    if ( !(unsigned int)_DbgpCreateTraceControl(a1, a2, a3, a4, DueTime, Period, &v13)
      || (SharedMem = (struct _RTL_CRITICAL_SECTION *)_DbgpOpenOrCreateSharedMem(), (v5 = SharedMem) == 0i64) )
    {
      v10 = v13;
LABEL_9:
      if ( v10 )
        _DbgpDeleteTraceControl(v10);
      return;
    }
    EnterCriticalSection(SharedMem + 2);
    v6 = *(struct _DBG_TRACE_CONTROL_BLOCK ***)&v5[1].LockCount;
    if ( *v6 != (struct _DBG_TRACE_CONTROL_BLOCK *)&v5[1] )
      __fastfail(3u);
    v7 = v13;
    *(_QWORD *)v13 = v5 + 1;
    *((_QWORD *)v7 + 1) = v6;
    *v6 = v7;
    *(_QWORD *)&v5[1].LockCount = v7;
    ++LODWORD(v5->SpinCount);
    if ( v5[1].LockSemaphore )
      goto LABEL_7;
    if ( LOBYTE(v5[1].OwningThread) || IsDebuggerPresent() )
    {
      HIDWORD(v5[1].OwningThread) = 60;
      if ( CreateTimerQueueTimer(
             (PHANDLE)&v5[1].SpinCount,
             0i64,
             (WAITORTIMERCALLBACK)_DbgpTraceControllerTimerCallback,
             v5,
             0x2BF20u,
             0xEA60u,
             0) )
      {
        v5[1].LockSemaphore = _DbgpTraceControllerTimerCallback;
      }
      goto LABEL_8;
    }
    if ( v5[1].LockSemaphore )
    {
LABEL_7:
      SpinCount = v5->SpinCount;
      OwningThread_high = HIDWORD(v5[1].OwningThread);
      if ( OwningThread_high < 10 * SpinCount )
      {
        HIDWORD(v5[1].OwningThread) = 10 * (SpinCount + 6);
        if ( !ChangeTimerQueueTimer(0i64, (HANDLE)v5[1].SpinCount, 10000 * (SpinCount + 6), 10000 * (SpinCount + 6)) )
          HIDWORD(v5[1].OwningThread) = OwningThread_high;
      }
    }
LABEL_8:
    LeaveCriticalSection(v5 + 2);
    _DbgpRegistryChangeNotifycationCallback(*((void **)v7 + 29), 1u);
    v10 = 0i64;
    SchannelGlobalTraceControlBlock = v7;
    goto LABEL_9;
  }
}
// 18002506A: variable 'DueTime' is possibly undefined
// 18002506A: variable 'Period' is possibly undefined
