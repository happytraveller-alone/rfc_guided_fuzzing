//----- (00000001800509D0) ----------------------------------------------------
PVOID __fastcall PvExtVirtualAlloc(unsigned int a1)
{
  HANDLE CurrentProcess; // rax
  NTSTATUS v2; // eax
  PVOID v3; // rcx
  PVOID BaseAddress; // [rsp+48h] [rbp+10h] BYREF
  ULONG_PTR RegionSize; // [rsp+50h] [rbp+18h] BYREF

  BaseAddress = 0i64;
  RegionSize = a1;
  CurrentProcess = GetCurrentProcess();
  v2 = NtAllocateVirtualMemory(CurrentProcess, &BaseAddress, 0i64, &RegionSize, 0x1000u, 4u);
  v3 = BaseAddress;
  if ( v2 < 0 )
    return 0i64;
  return v3;
}

