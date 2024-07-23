//----- (000000018005E120) ----------------------------------------------------
struct _SLIST_ENTRY *__fastcall CSslLookasidePreallocate::Allocate(CSslLookasidePreallocate *this)
{
  PSLIST_ENTRY v3; // rdi
  unsigned __int32 v4; // edx
  int v5; // ecx

  if ( !*((_QWORD *)this + 12) )
    return 0i64;
  v3 = InterlockedPopEntrySList((PSLIST_HEADER)this + 5);
  if ( !v3 )
  {
    v4 = _InterlockedExchangeAdd((volatile signed __int32 *)this + 28, *((_DWORD *)this + 27));
    v5 = *((_DWORD *)this + 27);
    if ( v5 + v4 > *((_DWORD *)this + 26) )
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)this + 28, -v5);
      return CSslLookaside::Allocate(this);
    }
    v3 = (PSLIST_ENTRY)(*((_QWORD *)this + 12) + v4);
  }
  memset_0(&v3[1], 0, *((unsigned int *)this + 27) - 16i64);
  return v3 + 1;
}

