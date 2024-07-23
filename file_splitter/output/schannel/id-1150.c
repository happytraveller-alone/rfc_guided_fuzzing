// File count: 1150
// Total lines: 9
-----------------------------------------
bool __fastcall CSessionCacheServerItem::CanEntryBePurged(
        CSessionCacheServerItem *this,
        struct _LUID *a2,
        const unsigned __int16 *a3,
        int a4)
{
  return (a4 & 0x20002) != 0;
}
