// File count: 289
// Total lines: 21
-----------------------------------------
bool __fastcall CSessionCacheClientItem::IsEntryAMatch(
        CSessionCacheClientItem *this,
        struct _LUID *a2,
        char *a3,
        struct CRED_THUMBPRINT *a4,
        unsigned int a5)
{
  struct _LUID *v5; // r11
  CSessionCacheClientItem *v6; // r10

  v5 = a2;
  v6 = this;
  return (*((_DWORD *)this + 42) & a5) != 0
      && *(_DWORD *)a4 == *((_DWORD *)this + 47)
      && *((_DWORD *)a4 + 1) == *((_DWORD *)this + 48)
      && (!a3 || CSessionCacheClientItem::IsSameTargetName(this, a3))
      && (!v5 || *((_DWORD *)v6 + 94) == v5->LowPart && *((_DWORD *)v6 + 95) == v5->HighPart);
}
// 180016361: variable 'v5' is possibly undefined
// 180016366: variable 'v6' is possibly undefined
