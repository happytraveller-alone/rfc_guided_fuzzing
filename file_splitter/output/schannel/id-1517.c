// File count: 1517
// Total lines: 25
----------------------------------------
void __fastcall _DbgpStopTracing(struct _DBG_TRACE_CONTROL_BLOCK *a1)
{
  TRACEHANDLE v2; // rcx
  struct _EVENT_TRACE_PROPERTIES *v3; // r8
  void *v4; // r8

  v2 = *((_QWORD *)a1 + 9);
  if ( v2 )
  {
    v3 = (struct _EVENT_TRACE_PROPERTIES *)*((_QWORD *)a1 + 11);
    if ( v3 )
      ControlTraceW(v2, *((LPCWSTR *)a1 + 8), v3, 1u);
  }
  *((_QWORD *)a1 + 9) = 0i64;
  v4 = (void *)*((_QWORD *)a1 + 11);
  if ( v4 )
  {
    RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v4);
    *((_QWORD *)a1 + 11) = 0i64;
  }
  *((_DWORD *)a1 + 20) = 0;
  *((_DWORD *)a1 + 26) = 0;
  *((_DWORD *)a1 + 27) = 0;
}
