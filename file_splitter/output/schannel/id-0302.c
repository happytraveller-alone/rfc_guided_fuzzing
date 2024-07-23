// File count: 302
// Total lines: 40
-----------------------------------------
BOOLEAN (__fastcall *SafeAllocaInitialize())(void *a1)
{
  PIMAGE_NT_HEADERS v0; // rax
  __int64 SizeOfStackCommit; // rcx
  __int64 GuaranteedStackBytes; // rax
  BOOLEAN (__fastcall *result)(void *); // rax

  v0 = RtlImageNtHeader(NtCurrentPeb()->ImageBaseAddress);
  if ( NtCurrentPeb()->BeingDebugged
    || !v0
    || (SizeOfStackCommit = v0->OptionalHeader.SizeOfStackCommit,
        v0->OptionalHeader.SizeOfStackReserve - SizeOfStackCommit < 0x3000) )
  {
    SizeOfStackCommit = 0i64;
  }
  g_ulMaxStackAllocSize = SizeOfStackCommit;
  if ( !v0 )
    goto LABEL_11;
  GuaranteedStackBytes = NtCurrentTeb()->GuaranteedStackBytes;
  g_ulAdditionalProbeSize = GuaranteedStackBytes;
  if ( GuaranteedStackBytes )
  {
    if ( (unsigned __int64)(GuaranteedStackBytes + 8) >= 8 )
      goto LABEL_7;
LABEL_11:
    g_ulAdditionalProbeSize = -9i64;
    goto LABEL_7;
  }
  g_ulAdditionalProbeSize = 12288i64;
LABEL_7:
  g_pfnAllocate = (__int64)SafeAllocaAllocateFromHeap;
  result = SafeAllocaFreeToHeap;
  g_pfnFree = (__int64)SafeAllocaFreeToHeap;
  return result;
}
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
