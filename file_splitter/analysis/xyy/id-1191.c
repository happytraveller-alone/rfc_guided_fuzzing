//----- (000000018005E624) ----------------------------------------------------
void __fastcall CTlsSignatureSuiteList::SetDefaultClientHello(CTlsSignatureSuiteList *this)
{
  unsigned __int8 v1; // r11
  void **v2; // r10

  v1 = 0;
  v2 = (void **)&unk_18007C390;
  *(_WORD *)this = 0;
  *((_WORD *)this + 17) = 0;
  do
  {
    if ( *((_DWORD *)v2 + 10) == 2 )
      CTlsSignatureSuiteList::AddSignatureSuite(this, v1);
    v2 += 9;
    ++v1;
  }
  while ( v2 < &CSsl3TlsServerContext::`vftable' );
}
// 18005E652: variable 'v2' is possibly undefined
// 18005E65D: variable 'v1' is possibly undefined
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';

