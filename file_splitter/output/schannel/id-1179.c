// File count: 1179
// Total lines: 8
-----------------------------------------
CSslLookaside *__fastcall CSslLookaside::`vector deleting destructor'(CSslLookaside *this, char a2)
{
  CSslLookaside::~CSslLookaside(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
