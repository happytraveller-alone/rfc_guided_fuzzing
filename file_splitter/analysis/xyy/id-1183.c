//----- (000000018005E240) ----------------------------------------------------
void __fastcall CSslLookasidePreallocate::Deallocate(union _SLIST_HEADER *this, struct _SLIST_ENTRY *a2)
{
  if ( a2
    && (unsigned __int64)a2 >= this[6].Alignment
    && (unsigned __int64)a2 < this[6].Alignment + *((unsigned int *)&this[6].HeaderX64 + 2) )
  {
    InterlockedPushEntrySList(this + 5, a2 - 1);
  }
  else
  {
    CSslLookaside::Deallocate((CSslLookaside *)this, a2);
  }
}
