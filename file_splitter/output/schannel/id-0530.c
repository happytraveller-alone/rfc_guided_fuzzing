// File count: 530
// Total lines: 16
-----------------------------------------
void __fastcall CCipherSuiteInfo::~CCipherSuiteInfo(NCRYPT_HANDLE *this)
{
  NCRYPT_HANDLE v2; // rcx

  CCipherMill::DeferenceProvider((CCipherMill *)this, this);
  if ( *((_BYTE *)this + 56) )
  {
    v2 = this[8];
    if ( v2 )
    {
      NCryptFreeObject(v2);
      this[8] = 0i64;
    }
  }
}
