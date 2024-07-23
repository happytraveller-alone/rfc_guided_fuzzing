// File count: 34
// Total lines: 10
------------------------------------------
CSessionCacheClientItem *__fastcall CSessionCacheClientItem::`vector deleting destructor'(
        CSessionCacheClientItem *this,
        char a2)
{
  CSessionCacheClientItem::~CSessionCacheClientItem(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}
