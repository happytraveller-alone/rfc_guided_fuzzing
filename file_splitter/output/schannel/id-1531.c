// File count: 1531
// Total lines: 12
----------------------------------------
void __fastcall DestroyAggregateSession(LPVOID lpMem)
{
  HANDLE ProcessHeap; // rax

  if ( lpMem )
  {
    CancelTimerCallbacksAndDeleteTimer((__int64)lpMem);
    ProcessHeap = GetProcessHeap();
    HeapFree(ProcessHeap, 0, lpMem);
  }
}
