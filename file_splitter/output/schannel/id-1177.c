// File count: 1177
// Total lines: 24
----------------------------------------
void __fastcall CSslLookaside::~CSslLookaside(CSslLookaside *this)
{
  bool v1; // zf
  union _SLIST_HEADER *i; // rcx
  PSLIST_ENTRY v4; // rax

  v1 = *((_BYTE *)this + 32) == 0;
  *(_QWORD *)this = &CSslLookaside::`vftable';
  if ( !v1 )
  {
    for ( i = (union _SLIST_HEADER *)((char *)this + 16); ; i = (union _SLIST_HEADER *)((char *)this + 16) )
    {
      v4 = InterlockedPopEntrySList(i);
      if ( !v4 )
        break;
      SPExternalFree(v4);
    }
  }
  InterlockedFlushSList((PSLIST_HEADER)this + 1);
  *(_QWORD *)this = &IAllocate::`vftable';
}
// 18007C298: using guessed type void *IAllocate::`vftable';
// 18007D428: using guessed type void *CSslLookaside::`vftable';
