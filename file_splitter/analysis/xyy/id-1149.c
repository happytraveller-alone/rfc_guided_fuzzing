//----- (000000018005CCE0) ----------------------------------------------------
bool __fastcall CSessionCacheClientItem::CanEntryBePurged(
        CSessionCacheClientItem *this,
        struct _LUID *a2,
        char *a3,
        int a4)
{
  return (a4 & 0x10001) != 0
      && ((a4 & 0x10000) != 0 || a2 && *((_DWORD *)this + 94) == a2->LowPart && *((_DWORD *)this + 95) == a2->HighPart)
      && (!a3 || CSessionCacheClientItem::IsSameTargetName(this, a3));
}

