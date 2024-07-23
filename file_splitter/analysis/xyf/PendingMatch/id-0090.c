//----- (0000000180006DA4) ----------------------------------------------------
unsigned __int8 __fastcall CTlsSignatureSuiteList::AddSignatureSuite(CTlsSignatureSuiteList *this, unsigned __int8 a2)
{
  int v2; // eax
  __int16 v3; // ax

  if ( a2 < 0xCu )
  {
    v2 = *((unsigned __int16 *)this + 17);
    if ( _bittest(&v2, a2) )
      return 1;
    if ( *(_WORD *)this < 0x10u )
    {
      *((_WORD *)this + *(unsigned __int16 *)this + 1) = __ROR2__(*((_WORD *)&unk_18007C390 + 36 * a2), 8);
      v3 = *((_WORD *)this + 17);
      ++*(_WORD *)this;
      *((_WORD *)this + 17) = v3 | (1 << a2);
      return 1;
    }
  }
  return 0;
}

