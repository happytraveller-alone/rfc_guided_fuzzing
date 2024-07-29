//----- (000000018005E830) ----------------------------------------------------
CSslCredential *__fastcall CSslCredential::`vector deleting destructor'(CSslCredential *this, char a2)
{
  CSslCredential::~CSslCredential(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}

