//----- (000000018005DF3C) ----------------------------------------------------
__int64 __fastcall CSslLookasidePreallocate::CSslLookasidePreallocate(__int64 a1, int a2, int a3)
{
  SIZE_T v6; // rdx
  struct _SYSTEM_INFO SystemInfo; // [rsp+40h] [rbp-38h] BYREF

  CSslLookaside::CSslLookaside(a1, a2, 1);
  *(_QWORD *)(a1 + 96) = 0i64;
  *(_DWORD *)(a1 + 112) = 0;
  *(_QWORD *)a1 = &CSslLookasidePreallocate::`vftable';
  GetSystemInfo(&SystemInfo);
  InitializeSListHead((PSLIST_HEADER)(a1 + 80));
  v6 = ~(SystemInfo.dwPageSize - 1) & (a3 * a2 + SystemInfo.dwPageSize - 1);
  *(_DWORD *)(a1 + 104) = v6;
  *(_DWORD *)(a1 + 108) = (a2 + 23) & 0xFFFFFFF8;
  *(_QWORD *)(a1 + 96) = VirtualAlloc(0i64, v6, 0x3000u, 4u);
  return a1;
}
// 18007FCF8: using guessed type void *CSslLookasidePreallocate::`vftable';

