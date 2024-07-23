// File count: 23
// Total lines: 30
------------------------------------------
void __fastcall CSessionCacheTable::ExpireItemsBoundToProcess(CSessionCacheTable *this, int a2)
{
  struct _RTL_RESOURCE *v2; // rbp
  _QWORD **v4; // r14
  _QWORD *v5; // rdi
  _QWORD *v6; // rbx

  v2 = (struct _RTL_RESOURCE *)((char *)this + 48);
  v4 = (_QWORD **)((char *)this + 16);
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
  v5 = *v4;
  while ( v5 != v4 )
  {
    v6 = v5;
    v5 = (_QWORD *)*v5;
    RtlAcquireResourceShared((PRTL_RESOURCE)(v6 - 29), 1u);
    if ( *((_DWORD *)v6 - 8) == a2 )
    {
      RtlConvertSharedToExclusive((PRTL_RESOURCE)(v6 - 29));
      if ( *((_DWORD *)v6 - 8) == a2 )
      {
        *((_DWORD *)v6 - 8) = 0;
        *((_WORD *)v6 - 34) = 0;
      }
    }
    RtlReleaseResource((PRTL_RESOURCE)(v6 - 29));
  }
  RtlReleaseResource(v2);
}
