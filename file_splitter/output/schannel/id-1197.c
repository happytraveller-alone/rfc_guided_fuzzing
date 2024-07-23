// File count: 1197
// Total lines: 8
-----------------------------------------
CSslServerKey *__fastcall CSslServerKey::`vector deleting destructor'(CSslServerKey *this, char a2)
{
  CSslServerKey::~CSslServerKey(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}
