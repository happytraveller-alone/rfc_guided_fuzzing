// File count: 468
// Total lines: 41
-----------------------------------------
struct _SLIST_ENTRY *__fastcall CSslLookaside::Allocate(CSslLookaside *this)
{
  SIZE_T v2; // rcx
  struct _SLIST_ENTRY *result; // rax
  PSLIST_ENTRY v4; // rax
  unsigned int v5; // ecx
  PSLIST_ENTRY v6; // rdi

  if ( *((_BYTE *)this + 32) )
  {
    v4 = InterlockedPopEntrySList((PSLIST_HEADER)this + 1);
    v5 = *((_DWORD *)this + 9);
    v6 = v4;
    if ( v4 )
    {
      memset_0(&v4[1], 0, v5);
      _InterlockedDecrement((volatile signed __int32 *)this + 13);
    }
    else
    {
      result = (struct _SLIST_ENTRY *)SPExternalAlloc(v5 + 16);
      v6 = result;
      if ( !result )
        return result;
      _InterlockedIncrement((volatile signed __int32 *)this + 17);
    }
    _InterlockedIncrement((volatile signed __int32 *)this + 15);
    return v6 + 1;
  }
  else
  {
    v2 = *((unsigned int *)this + 9);
    if ( LsaTable )
      return (struct _SLIST_ENTRY *)(*(__int64 (__fastcall **)(SIZE_T))(LsaTable + 40))(v2);
    else
      return (struct _SLIST_ENTRY *)LocalAlloc(0x40u, v2);
  }
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
