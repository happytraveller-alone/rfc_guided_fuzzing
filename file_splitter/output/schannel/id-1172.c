// File count: 1172
// Total lines: 13
----------------------------------------
void __fastcall SPDeleteIssuerEntry(struct ISSUER_CACHE_ENTRY *a1)
{
  void *v2; // rcx

  if ( a1 )
  {
    v2 = (void *)*((_QWORD *)a1 + 1);
    if ( v2 )
      SPExternalFree(v2);
    SPExternalFree(a1);
  }
}
