//----- (000000018007AF40) ----------------------------------------------------
BOOLEAN __fastcall SafeAllocaFreeToHeap(void *a1)
{
  return RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, a1);
}

