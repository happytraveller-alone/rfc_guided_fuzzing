//----- (000000018005DE98) ----------------------------------------------------
void ShutdownIssuerCache(void)
{
  void *v0; // rcx
  __int64 *v1; // rbx
  struct ISSUER_CACHE_ENTRY *v2; // rcx

  if ( dword_180092778 )
    RtlAcquireResourceExclusive(&stru_180092718, 1u);
  v0 = IssuerCache;
  if ( IssuerCache )
  {
    v1 = (__int64 *)qword_180092708;
    if ( (__int64 *)qword_180092708 != &qword_180092708 )
    {
      do
      {
        v2 = (struct ISSUER_CACHE_ENTRY *)(v1 - 5);
        v1 = (__int64 *)*v1;
        SPDeleteIssuerEntry(v2);
      }
      while ( v1 != &qword_180092708 );
      v0 = IssuerCache;
    }
    SPExternalFree(v0);
    IssuerCache = 0i64;
  }
  if ( dword_180092778 )
  {
    RtlDeleteResource(&stru_180092718);
    dword_180092778 = 0;
  }
}
// 180092708: using guessed type __int64 qword_180092708;
// 180092778: using guessed type int dword_180092778;

