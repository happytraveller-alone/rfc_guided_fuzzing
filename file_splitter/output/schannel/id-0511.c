// File count: 511
// Total lines: 116
----------------------------------------
__int64 __fastcall _DbgpCreateTraceControl(
        const unsigned __int16 *a1,
        const unsigned __int16 *a2,
        struct _GUID *a3,
        const unsigned __int16 *a4,
        const unsigned __int16 *a5,
        int a6,
        struct _DBG_TRACE_CONTROL_BLOCK **a7)
{
  char *Heap; // rax
  unsigned int v8; // esi
  char *v9; // rdi
  int v10; // eax
  HMODULE ModuleHandleW; // rax
  LSTATUS v12; // ebx
  struct _RTL_CRITICAL_SECTION *SharedMem; // rax
  struct _RTL_CRITICAL_SECTION *v14; // rbp
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo; // rdx
  HANDLE EventW; // rax
  __int64 v17; // rax
  DWORD LastError; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-238h] BYREF
  WCHAR Filename[264]; // [rsp+40h] [rbp-228h] BYREF

  Heap = (char *)RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0xF0ui64);
  v8 = 0;
  v9 = Heap;
  if ( !Heap )
  {
    v12 = 14;
    goto LABEL_14;
  }
  memset_0(Heap, 0, 0xF0ui64);
  InitializeCriticalSection((LPCRITICAL_SECTION)(v9 + 192));
  *((_DWORD *)v9 + 4) = 1937339236;
  *((_DWORD *)v9 + 5) = 1819440227;
  RtlInitUnicodeString(&DestinationString, L"schannel");
  if ( (DestinationString.Length & 0xFFFEu) >= 0x104 )
  {
    v12 = 87;
    goto LABEL_21;
  }
  v10 = RtlDuplicateUnicodeString(3u, &DestinationString, (PUNICODE_STRING)(v9 + 56));
  if ( v10 < 0 )
    goto LABEL_17;
  Filename[260] = 0;
  ModuleHandleW = GetModuleHandleW(L"schannel.dll");
  if ( !ModuleHandleW || !GetModuleFileNameW(ModuleHandleW, Filename, 0x104u) )
  {
LABEL_19:
    LastError = GetLastError();
    goto LABEL_20;
  }
  RtlInitUnicodeString(&DestinationString, Filename);
  v10 = RtlDuplicateUnicodeString(3u, &DestinationString, (PUNICODE_STRING)(v9 + 40));
  if ( v10 < 0 )
  {
LABEL_17:
    LastError = RtlNtStatusToDosError(v10);
LABEL_20:
    v12 = LastError;
    goto LABEL_21;
  }
  v12 = RegOpenKeyExW(
          HKEY_LOCAL_MACHINE,
          L"System\\CurrentControlSet\\Control\\SecurityProviders\\Schannel",
          0,
          0x2000000u,
          (PHKEY)v9 + 21);
  if ( v12 )
  {
LABEL_21:
    _DbgpDeleteTraceControl((struct _DBG_TRACE_CONTROL_BLOCK *)v9);
    goto LABEL_14;
  }
  RtlInitUnicodeString((PUNICODE_STRING)v9 + 11, L"LogLevel");
  *((_QWORD *)v9 + 18) = _DbgpTraceControllerTimerCallback;
  *((_OWORD *)v9 + 7) = SchannelTracingGuid;
  SharedMem = (struct _RTL_CRITICAL_SECTION *)_DbgpOpenOrCreateSharedMem();
  v14 = SharedMem;
  if ( !SharedMem )
  {
    v12 = 1168;
    goto LABEL_21;
  }
  EnterCriticalSection(SharedMem + 2);
  DebugInfo = v14[3].DebugInfo;
  v14[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)((char *)&DebugInfo->Type + 1);
  *((_QWORD *)v9 + 29) = DebugInfo;
  LeaveCriticalSection(v14 + 2);
  if ( LOBYTE(v14[1].OwningThread) )
    *((_DWORD *)v9 + 8) = 3;
  *((_QWORD *)v9 + 17) = _DbgpTraceTimerCallback;
  EventW = CreateEventW(0i64, 0, 0, 0i64);
  *((_QWORD *)v9 + 19) = EventW;
  if ( !EventW )
    goto LABEL_19;
  v17 = RegisterWaitForSingleObjectEx(
          EventW,
          _DbgpRegistryChangeNotifycationCallback,
          *((_QWORD *)v9 + 29),
          0xFFFFFFFFi64,
          128);
  *((_QWORD *)v9 + 20) = v17;
  if ( !v17 )
    goto LABEL_19;
  NtQuerySystemTime((PLARGE_INTEGER)v9 + 3);
  *a7 = (struct _DBG_TRACE_CONTROL_BLOCK *)v9;
  v12 = 0;
LABEL_14:
  LOBYTE(v8) = v12 == 0;
  return v8;
}
// 180080BC0: using guessed type __int64 __fastcall RegisterWaitForSingleObjectEx(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180081F98: using guessed type __int128 SchannelTracingGuid;
