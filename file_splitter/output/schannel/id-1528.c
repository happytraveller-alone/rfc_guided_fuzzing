// File count: 1528
// Total lines: 47
----------------------------------------
_BOOL8 resetstkoflw_static()
{
  char *AllocationBase; // r15
  __int64 dwPageSize; // rdi
  ULONG v2; // ebx
  ULONG v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // esi
  char *v8; // rbx
  char Address[16]; // [rsp+10h] [rbp-10h] BYREF
  ULONG StackSizeInBytes; // [rsp+20h] [rbp+0h] BYREF
  DWORD flOldProtect; // [rsp+24h] [rbp+4h] BYREF
  struct _MEMORY_BASIC_INFORMATION Buffer; // [rsp+28h] [rbp+8h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [rsp+58h] [rbp+38h] BYREF

  StackSizeInBytes = 0;
  if ( !VirtualQuery(Address, &Buffer, 0x30ui64) )
    return 0i64;
  AllocationBase = (char *)Buffer.AllocationBase;
  GetSystemInfo(&SystemInfo);
  dwPageSize = SystemInfo.dwPageSize;
  v2 = 0;
  if ( SetThreadStackGuarantee(&StackSizeInBytes) && StackSizeInBytes )
    v2 = StackSizeInBytes;
  v3 = v2 + dwPageSize - 1;
  v4 = dwPageSize - 1;
  if ( v3 < v2 )
    return 0i64;
  v5 = ~v4 & v3;
  if ( v5 )
  {
    if ( v5 + (unsigned int)dwPageSize < v5 )
      return 0i64;
    v5 += dwPageSize;
  }
  v6 = 3 * dwPageSize;
  if ( v5 >= 3 * (int)dwPageSize )
    v6 = v5;
  v7 = v6;
  v8 = (char *)(((unsigned __int64)Address & ~(unsigned __int64)v4) - v6);
  return v8 >= &AllocationBase[dwPageSize]
      && VirtualAlloc(v8, v6, 0x1000u, 4u)
      && VirtualProtect(v8, v7, 0x104u, &flOldProtect);
}
