// File count: 532
// Total lines: 55
-----------------------------------------
__int64 TlgRegisterAggregateProviderEx()
{
  RTL_SRWLOCK *TlgAggregateSession; // rax
  RTL_SRWLOCK *v1; // rbx
  int v2; // esi
  __int64 v3; // rax
  __int64 *v4; // rcx

  TlgAggregateSession = CreateTlgAggregateSession(1);
  v1 = TlgAggregateSession;
  if ( !TlgAggregateSession )
    return TraceLoggingRegisterEx_EventRegister_EventSetInformation((ULONGLONG *)&dword_180091480, 0i64, 0i64);
  TlgAggregateSession[39].Ptr = 0i64;
  TlgAggregateSession[40].Ptr = 0i64;
  TlgAggregateSession[41].Ptr = &dword_180091480;
  LODWORD(TlgAggregateSession[44].Ptr) = ComputeFlushPeriod((unsigned __int64)TlgAggregateSession);
  v2 = TraceLoggingRegisterEx_EventRegister_EventSetInformation(
         (ULONGLONG *)&dword_180091480,
         (ULONGLONG)TlgAggregateInternalRegisteredProviderEtwCallback,
         (ULONGLONG)v1);
  if ( v2 < 0 )
  {
    qword_1800914A8 = 0i64;
    DestroyAggregateSession(v1);
    return (unsigned int)v2;
  }
  else
  {
    AcquireSRWLockExclusive(&SRWLock);
    v3 = qword_180092EE8;
    if ( !qword_180092EE8 )
    {
      TraceLoggingRegisterEx_EventRegister_EventSetInformation(
        (ULONGLONG *)&dword_180091870,
        (ULONGLONG)TlgAggregateInternalProviderCallback,
        0i64);
      v3 = qword_180092EE8;
    }
    v4 = &qword_180092EE8;
    while ( v3 )
    {
      if ( *(int **)(v3 + 328) == &dword_180091480 )
        goto LABEL_8;
      v4 = (__int64 *)(v3 + 336);
      v3 = *(_QWORD *)(v3 + 336);
    }
    *v4 = (__int64)v1;
LABEL_8:
    ReleaseSRWLockExclusive(&SRWLock);
    return 0i64;
  }
}
// 1800914A8: using guessed type __int64 qword_1800914A8;
// 180092EE8: using guessed type __int64 qword_180092EE8;
