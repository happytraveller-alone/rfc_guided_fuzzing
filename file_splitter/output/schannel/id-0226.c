//----- (0000000180013210) ----------------------------------------------------
CCredentialGroup *__fastcall CCredentialGroup::`vector deleting destructor'(CCredentialGroup *this, char a2)
{
  CCredentialGroup::~CCredentialGroup(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}

