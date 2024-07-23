// File count: 88
// Total lines: 62
------------------------------------------
CSessionCacheItem *__fastcall CSessionCacheItem::CSessionCacheItem(
        CSessionCacheItem *this,
        int a2,
        unsigned __int8 *const a3)
{
  char v6; // al
  int v7; // ecx
  int v9[10]; // [rsp+20h] [rbp-28h] BYREF

  CSslBasicAllocator::CSslBasicAllocator(this);
  *(_QWORD *)this = &CSessionCacheItem::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_QWORD *)this + 2) = 0i64;
  *((_QWORD *)this + 3) = 0i64;
  *((_DWORD *)this + 8) = 0;
  *((_QWORD *)this + 5) = 0i64;
  *((_QWORD *)this + 6) = 0i64;
  *((_QWORD *)this + 7) = 0i64;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_QWORD *)this + 22) = 0i64;
  *((_DWORD *)this + 46) = 0;
  *((_QWORD *)this + 25) = 0i64;
  *((_BYTE *)this + 208) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = -2146893042;
  *((_DWORD *)this + 55) = 0;
  *((_DWORD *)this + 58) = 1;
  *((_BYTE *)this + 236) = 0;
  *((_DWORD *)this + 69) = GetTickCount();
  *((_DWORD *)this + 70) = a2;
  if ( a3 )
  {
    *((_OWORD *)this + 15) = *(_OWORD *)a3;
    *((_OWORD *)this + 16) = *((_OWORD *)a3 + 1);
  }
  else
  {
    *((_OWORD *)this + 15) = 0i64;
    *((_OWORD *)this + 16) = 0i64;
  }
  if ( LsaTable )
  {
    v6 = (*(__int64 (__fastcall **)(int *))(LsaTable + 192))(v9);
    v7 = -1;
    if ( v6 )
      v7 = v9[0];
    *((_DWORD *)this + 68) = v7;
  }
  else
  {
    *((_DWORD *)this + 68) = GetCurrentProcessId();
  }
  *(_QWORD *)((char *)this + 188) = 0i64;
  RtlInitializeResource((PRTL_RESOURCE)((char *)this + 72));
  *((_DWORD *)this + 17) = 0;
  return this;
}
// 18007C2C0: using guessed type void *CSessionCacheItem::`vftable';
// 180092620: using guessed type __int64 LsaTable;
// 180006B5C: using guessed type int var_28[10];
