//----- (0000000180023480) ----------------------------------------------------
void __fastcall CCipherMill::DeferenceProvider(CCipherMill *this, unsigned __int64 *a2)
{
  if ( a2 )
  {
    if ( *a2 )
    {
      SslDecrementProviderReferenceCount();
      _InterlockedDecrement(&dword_1800925A0);
      *a2 = 0i64;
    }
  }
}
// 1800925A0: using guessed type int dword_1800925A0;
// 180098518: using guessed type __int64 SslDecrementProviderReferenceCount(void);

