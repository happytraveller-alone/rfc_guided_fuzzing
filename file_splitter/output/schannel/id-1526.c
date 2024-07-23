// File count: 1526
// Total lines: 5
-----------------------------------------
PVOID __fastcall SafeAllocaAllocateFromHeap(SIZE_T a1)
{
  return RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, a1);
}
