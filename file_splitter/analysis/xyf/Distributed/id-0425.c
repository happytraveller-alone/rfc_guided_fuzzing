//----- (0000000180018F20) ----------------------------------------------------
CEphemKeyData *__fastcall CEphemKeyData::`vector deleting destructor'(CEphemKeyData *this, char a2)
{
  CEphemKeyData::~CEphemKeyData(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}

