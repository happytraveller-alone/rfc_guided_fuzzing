//----- (0000000180017E08) ----------------------------------------------------
void __fastcall CCipherMill::~CCipherMill(CCipherMill *this)
{
  if ( *(_BYTE *)this )
    RtlDeleteResource((PRTL_RESOURCE)((char *)this + 8));
}

