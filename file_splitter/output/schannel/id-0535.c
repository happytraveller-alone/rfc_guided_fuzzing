//----- (0000000180027078) ----------------------------------------------------
RTL_SRWLOCK *__fastcall CreateTlgAggregateSession(char a1)
{
  char v2; // di
  HANDLE ProcessHeap; // rax
  RTL_SRWLOCK *v4; // rax
  RTL_SRWLOCK *v5; // rbx

  v2 = 0;
  ProcessHeap = GetProcessHeap();
  v4 = (RTL_SRWLOCK *)HeapAlloc(ProcessHeap, 8u, 0x168ui64);
  v5 = v4;
  if ( v4 )
  {
    InitializeSRWLock(v4 + 33);
    if ( !a1
      || !dword_180092DE8
      && (v5[43].Ptr = CreateThreadpoolTimer((PTP_TIMER_CALLBACK)FlushTimerCallbackUserMode, v5, 0i64)) != 0i64 )
    {
      v2 = 1;
    }
  }
  if ( !v2 )
  {
    DestroyAggregateSession(v5);
    return 0i64;
  }
  return v5;
}
// 180092DE8: using guessed type int dword_180092DE8;

