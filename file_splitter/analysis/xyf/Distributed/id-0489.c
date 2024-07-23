//----- (0000000180023408) ----------------------------------------------------
void __fastcall CCipherMill::ReferenceProvider(CCipherMill *this, unsigned __int64 a2, unsigned __int64 *a3)
{
  CCipherMill *v5; // rcx

  RtlAcquireResourceShared(&Resource, 1u);
  if ( a2 )
  {
    if ( *a3 != a2 )
    {
      CCipherMill::DeferenceProvider(v5, a3);
      if ( (int)SslIncrementProviderReferenceCount(a2) >= 0 )
      {
        _InterlockedIncrement(&dword_1800925A0);
        *a3 = a2;
      }
    }
  }
  RtlReleaseResource(&Resource);
}
// 18002343A: variable 'v5' is possibly undefined
// 1800925A0: using guessed type int dword_1800925A0;
// 1800984E8: using guessed type __int64 __fastcall SslIncrementProviderReferenceCount(_QWORD);

