// File count: 31
// Total lines: 29
------------------------------------------
void __fastcall CSessionCacheTable::ExpireItemsBoundToCred(CSessionCacheTable *this, struct CCredentialGroup *a2)
{
  struct _RTL_RESOURCE *v2; // r13
  _QWORD **v4; // r14
  _QWORD *v5; // rdi
  __int64 v6; // rbx
  _QWORD *v7; // rbp

  v2 = (struct _RTL_RESOURCE *)((char *)this + 48);
  v4 = (_QWORD **)((char *)this + 16);
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
  v5 = *v4;
  while ( v5 != v4 )
  {
    v6 = *((_QWORD *)a2 + 95);
    v7 = v5;
    v5 = (_QWORD *)*v5;
    RtlAcquireResourceShared((PRTL_RESOURCE)(v7 - 29), 1u);
    if ( v6 == *(_QWORD *)((char *)v7 - 116) )
    {
      RtlConvertSharedToExclusive((PRTL_RESOURCE)(v7 - 29));
      if ( v6 == *(_QWORD *)((char *)v7 - 116) )
        *((_WORD *)v7 - 34) = 0;
    }
    RtlReleaseResource((PRTL_RESOURCE)(v7 - 29));
  }
  RtlReleaseResource(v2);
}
