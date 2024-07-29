//----- (000000018005E0A0) ----------------------------------------------------
CSslLookaside *__fastcall CSslLookaside::`vector deleting destructor'(CSslLookaside *this, char a2)
{
  CSslLookaside::~CSslLookaside(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

