// File count: 539
// Total lines: 20
-----------------------------------------
__int64 __fastcall CSslLookaside::CSslLookaside(__int64 a1, int a2, char a3)
{
  __int64 result; // rax

  *(_BYTE *)(a1 + 32) = a3;
  *(_QWORD *)a1 = &CSslLookaside::`vftable';
  *(_DWORD *)(a1 + 36) = a2;
  *(_DWORD *)(a1 + 40) = 20;
  *(_QWORD *)(a1 + 48) = 20i64;
  *(_QWORD *)(a1 + 56) = 0i64;
  *(_QWORD *)(a1 + 64) = 0i64;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 44) = 0x100000;
  InitializeSListHead((PSLIST_HEADER)(a1 + 16));
  result = a1;
  *(_BYTE *)(a1 + 33) = 5;
  return result;
}
// 18007D428: using guessed type void *CSslLookaside::`vftable';
