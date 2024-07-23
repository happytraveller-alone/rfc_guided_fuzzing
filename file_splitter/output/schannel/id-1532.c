// File count: 1532
// Total lines: 56
----------------------------------------
void TlgUnregisterAggregateProvider()
{
  void *v0; // rdi
  __int64 v1; // rcx
  __int64 *v2; // rdx
  __int64 *v3; // rax
  REGHANDLE v4; // rcx
  REGHANDLE v5; // rcx
  REGHANDLE v6; // rcx

  if ( (void (__fastcall *)(const struct _GUID *, unsigned int, __int64, __int64, unsigned __int64, struct _EVENT_FILTER_DESCRIPTOR *, _QWORD *))qword_1800914A8 == TlgAggregateInternalRegisteredProviderEtwCallback )
  {
    v0 = 0i64;
    AcquireSRWLockExclusive(&SRWLock);
    v1 = qword_180092EE8;
    v2 = &qword_180092EE8;
    while ( v1 )
    {
      v3 = (__int64 *)(v1 + 336);
      if ( *(int **)(v1 + 328) == &dword_180091480 )
      {
        v0 = (void *)v1;
        *v2 = *v3;
        LookUpTableFlushComplete(v1);
        if ( !qword_180092EE8 )
        {
          v4 = qword_180091890;
          qword_180091890 = 0i64;
          dword_180091870 = 0;
          EventUnregister(v4);
        }
        break;
      }
      v1 = *v3;
      v2 = v3;
    }
    ReleaseSRWLockExclusive(&SRWLock);
    if ( v0 )
      CancelTimerCallbacksAndDeleteTimer((__int64)v0);
    v5 = RegHandle;
    RegHandle = 0i64;
    dword_180091480 = 0;
    EventUnregister(v5);
    qword_1800914A8 = 0i64;
    DestroyAggregateSession(v0);
  }
  else
  {
    v6 = RegHandle;
    RegHandle = 0i64;
    dword_180091480 = 0;
    EventUnregister(v6);
  }
}
// 1800914A8: using guessed type __int64 qword_1800914A8;
// 180092EE8: using guessed type __int64 qword_180092EE8;
