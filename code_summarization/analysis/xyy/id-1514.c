//----- (000000018007A134) ----------------------------------------------------
void __fastcall _DbgpDeleteTraceControl(struct _DBG_TRACE_CONTROL_BLOCK *a1)
{
  void *v2; // rcx
  void *v3; // rcx
  HKEY v4; // rcx

  if ( a1 )
  {
    v2 = (void *)*((_QWORD *)a1 + 20);
    if ( v2 )
    {
      UnregisterWaitEx(v2, 0i64);
      *((_QWORD *)a1 + 20) = 0i64;
    }
    v3 = (void *)*((_QWORD *)a1 + 19);
    if ( v3 )
    {
      CloseHandle(v3);
      *((_QWORD *)a1 + 19) = 0i64;
    }
    v4 = (HKEY)*((_QWORD *)a1 + 21);
    if ( v4 )
    {
      RegCloseKey(v4);
      *((_QWORD *)a1 + 21) = 0i64;
    }
    _DbgpStopTracing(a1);
    if ( *((_QWORD *)a1 + 16) )
    {
      EtwUnregisterTraceGuids();
      *((_QWORD *)a1 + 16) = 0i64;
    }
    RtlFreeUnicodeString((PUNICODE_STRING)((char *)a1 + 56));
    RtlFreeUnicodeString((PUNICODE_STRING)((char *)a1 + 40));
    DeleteCriticalSection((LPCRITICAL_SECTION)((char *)a1 + 192));
    memset_0(a1, 0, 0xF0ui64);
    RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, a1);
  }
}
// 180080E08: using guessed type __int64 EtwUnregisterTraceGuids(void);
