//----- (000000018000EABC) ----------------------------------------------------
void __fastcall CCipherMill::GetSignatureSuiteList(CCipherMill *this, struct CTlsSignatureSuiteList *a2)
{
  RtlAcquireResourceShared(&Resource, 1u);
  CTlsSignatureSuiteList::SetSignatureSuiteList(a2, (const struct CTlsSignatureSuiteList *)&word_1800925E8);
  RtlReleaseResource(&Resource);
}
// 1800925E8: using guessed type __int16 word_1800925E8;

