// File count: 1148
// Total lines: 8
-----------------------------------------
CSessionCacheItem *__fastcall CSessionCacheItem::`scalar deleting destructor'(CSessionCacheItem *this, char a2)
{
  CSessionCacheItem::~CSessionCacheItem(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}
