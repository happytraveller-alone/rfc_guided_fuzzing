// File count: 1196
// Total lines: 8
-----------------------------------------
CSslCredential *__fastcall CSslCredential::`vector deleting destructor'(CSslCredential *this, char a2)
{
  CSslCredential::~CSslCredential(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}
