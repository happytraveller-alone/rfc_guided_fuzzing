//----- (000000018005E870) ----------------------------------------------------
CSslServerKey *__fastcall CSslServerKey::`vector deleting destructor'(CSslServerKey *this, char a2)
{
  CSslServerKey::~CSslServerKey(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}

