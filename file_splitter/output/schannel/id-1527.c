// File count: 1527
// Total lines: 5
-----------------------------------------
BOOLEAN __fastcall SafeAllocaFreeToHeap(void *a1)
{
  return RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, a1);
}
