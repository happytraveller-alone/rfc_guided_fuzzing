//----- (0000000180050980) ----------------------------------------------------
void __fastcall FreeExtVirtualAlloc(void *a1)
{
  HANDLE CurrentProcess; // rax
  PVOID BaseAddress; // [rsp+30h] [rbp+8h] BYREF
  ULONG_PTR RegionSize; // [rsp+38h] [rbp+10h] BYREF

  BaseAddress = a1;
  RegionSize = 0i64;
  CurrentProcess = GetCurrentProcess();
  NtFreeVirtualMemory(CurrentProcess, &BaseAddress, &RegionSize, 0x8000u);
}

