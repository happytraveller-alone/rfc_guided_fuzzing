//----- (0000000180022E40) ----------------------------------------------------
void __fastcall CSslLookaside::Deallocate(CSslLookaside *this, struct _SLIST_ENTRY *a2)
{
  if ( *((_BYTE *)this + 32) )
  {
    InterlockedPushEntrySList((PSLIST_HEADER)this + 1, a2 - 1);
    _InterlockedIncrement((volatile signed __int32 *)this + 13);
  }
  else if ( LsaTable )
  {
    (*(void (__fastcall **)(struct _SLIST_ENTRY *))(LsaTable + 48))(a2);
  }
  else
  {
    LocalFree(a2);
  }
}
// 180092620: using guessed type __int64 LsaTable;

