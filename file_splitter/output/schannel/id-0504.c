// File count: 504
// Total lines: 30
-----------------------------------------
void __fastcall CCipherMill::ClearCipherMill(CCipherMill *this, char a2)
{
  if ( a2 )
  {
    CCipherMill::DeleteProviderList(this);
    if ( hProvider )
    {
      NCryptFreeObject(hProvider);
      hProvider = 0i64;
    }
  }
  if ( xmmword_1800925B0 )
  {
    CMasterCipherInfo::Dereference(xmmword_1800925B0);
    xmmword_1800925B0 = 0i64;
  }
  if ( *(&xmmword_1800925B0 + 1) )
  {
    CMasterCipherInfo::Dereference(*(&xmmword_1800925B0 + 1));
    *(&xmmword_1800925B0 + 1) = 0i64;
  }
  if ( qword_1800925C8 )
  {
    CMasterEccCurveInfo::Dereference(qword_1800925C8);
    qword_1800925C8 = 0i64;
  }
  word_1800925D0 = 0;
}
// 1800925D0: using guessed type __int16 word_1800925D0;
