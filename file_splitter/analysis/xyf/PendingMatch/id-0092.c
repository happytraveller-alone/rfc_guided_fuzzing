//----- (0000000180006F5C) ----------------------------------------------------
__int64 __fastcall CTlsSignatureSuiteList::Blacklist(
        CTlsSignatureSuiteList *this,
        struct _TLS_PARAMETERS *a2,
        unsigned int a3)
{
  unsigned int v3; // ebx
  const wchar_t **v7; // r14
  unsigned __int8 v8; // di
  __int64 v9; // r12
  int v10; // eax

  v3 = 0;
  if ( !a2 || !a3 )
    return 0i64;
  *(_WORD *)this = 0;
  v7 = (const wchar_t **)&off_18007C3B0;
  v8 = 0;
  v9 = 12i64;
  do
  {
    if ( v8 < 0xCu )
    {
      v10 = *((unsigned __int16 *)this + 17);
      if ( _bittest(&v10, v8) )
      {
        *((_WORD *)this + 17) = v10 & ~(1 << v8);
        if ( !IsCngAlgorithmBlacklisted((unsigned __int64)a2, a3, 4, v7[2], 0i64, 0, 0i64, 1)
          && !IsCngAlgorithmBlacklisted((unsigned __int64)a2, a3, 4, *v7, 0i64, 0, 0i64, 1) )
        {
          CTlsSignatureSuiteList::AddSignatureSuite(this, v8);
        }
      }
    }
    v7 += 9;
    ++v8;
    --v9;
  }
  while ( v9 );
  if ( !*(_WORD *)this )
    return (unsigned int)-2146893007;
  return v3;
}
// 18007C3B0: using guessed type wchar_t *off_18007C3B0;

