//----- (000000018005DDD0) ----------------------------------------------------
void SPPurgeIssuerCache(void)
{
  __int64 *v0; // rbx
  __int64 *v1; // r9
  __int64 *v2; // rcx
  __int64 v3; // rdx
  __int64 **v4; // r8
  __int64 v5; // rdx
  __int64 **v6; // rax

  if ( dword_180092778 && dword_180092704 )
  {
    RtlAcquireResourceExclusive(&stru_180092718, 1u);
    v0 = (__int64 *)qword_180092708;
    while ( v0 != &qword_180092708 )
    {
      v1 = v0 - 5;
      v2 = v0;
      v0 = (__int64 *)*v0;
      v3 = v1[3];
      if ( *(__int64 **)(v3 + 8) != v1 + 3
        || (v4 = (__int64 **)v1[4], *v4 != v1 + 3)
        || (*v4 = (__int64 *)v3, *(_QWORD *)(v3 + 8) = v4, v5 = *v2, *(__int64 **)(*v2 + 8) != v2)
        || (v6 = (__int64 **)v2[1], *v6 != v2) )
      {
        __fastfail(3u);
      }
      *v6 = (__int64 *)v5;
      *(_QWORD *)(v5 + 8) = v6;
      --dword_180092704;
      SPDeleteIssuerEntry((struct ISSUER_CACHE_ENTRY *)v1);
    }
    RtlReleaseResource(&stru_180092718);
  }
}
// 180092704: using guessed type int dword_180092704;
// 180092708: using guessed type __int64 qword_180092708;
// 180092778: using guessed type int dword_180092778;

