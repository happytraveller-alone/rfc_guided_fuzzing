//----- (000000018007AF10) ----------------------------------------------------
PVOID __fastcall SafeAllocaAllocateFromHeap(SIZE_T a1)
{
  return RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, a1);
}

