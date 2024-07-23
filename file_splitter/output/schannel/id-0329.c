// File count: 329
// Total lines: 6
------------------------------------------
void __fastcall CCipherMill::~CCipherMill(CCipherMill *this)
{
  if ( *(_BYTE *)this )
    RtlDeleteResource((PRTL_RESOURCE)((char *)this + 8));
}
