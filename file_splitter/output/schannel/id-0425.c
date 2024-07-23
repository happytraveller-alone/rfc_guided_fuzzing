// File count: 425
// Total lines: 8
------------------------------------------
CEphemKeyData *__fastcall CEphemKeyData::`vector deleting destructor'(CEphemKeyData *this, char a2)
{
  CEphemKeyData::~CEphemKeyData(this);
  if ( (a2 & 1) != 0 )
    SPExternalFree(this);
  return this;
}
