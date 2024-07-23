//----- (00000001800032F0) ----------------------------------------------------
CSessionCacheClientItem *__fastcall CSessionCacheClientItem::`vector deleting destructor'(
        CSessionCacheClientItem *this,
        char a2)
{
  CSessionCacheClientItem::~CSessionCacheClientItem(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}

