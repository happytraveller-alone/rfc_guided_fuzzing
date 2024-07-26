//----- (000000018002623C) ----------------------------------------------------
struct _DBG_TCB_HEADER *_DbgpOpenOrCreateSharedMem(void)
{
  HANDLE FileMappingW; // rdi
  struct _DBG_TCB_HEADER **v1; // rbx
  wchar_t *TraceMappingName; // rax
  const WCHAR *v3; // rsi
  HANDLE v5; // rax
  struct _DBG_TCB_HEADER **v6; // rax
  struct _DBG_TCB_HEADER *v7; // rcx
  wchar_t *lpName; // rax
  struct _DBG_TCB_HEADER **v9; // rax
  struct _RTL_CRITICAL_SECTION *v10; // rax
  struct _RTL_CRITICAL_SECTION *v11; // rsi
  struct _SYSTEM_INFO SystemInfo; // [rsp+30h] [rbp-30h] BYREF
  int v13; // [rsp+80h] [rbp+20h] BYREF
  LONG PreviousState; // [rsp+88h] [rbp+28h] BYREF
  HANDLE Handle; // [rsp+90h] [rbp+30h] BYREF

  FileMappingW = 0i64;
  v1 = 0i64;
  Handle = 0i64;
  TraceMappingName = _DbgpGetTraceMappingName();
  v13 = 0;
  v3 = TraceMappingName;
  if ( !DbgpGlobalControllerHeader )
  {
    if ( _DbgpWaitForControllerEvent(&v13, &Handle) >= 0 )
    {
      GetSystemInfo(&SystemInfo);
      if ( v13 )
      {
        v5 = OpenFileMappingW(0xF001Fu, 0, v3);
        FileMappingW = v5;
        if ( v5 )
        {
          v6 = (struct _DBG_TCB_HEADER **)MapViewOfFileEx(v5, 6u, 0, 0, SystemInfo.dwAllocationGranularity, 0i64);
          v1 = v6;
          if ( v6 )
          {
            v7 = (struct _DBG_TCB_HEADER *)v6;
            if ( v6 != (struct _DBG_TCB_HEADER **)v6[1] )
              v7 = v6[1];
            DbgpGlobalControllerHeader = v7;
          }
        }
      }
      else
      {
        lpName = _DbgpGetTraceMappingName();
        FileMappingW = CreateFileMappingW(
                         (HANDLE)0xFFFFFFFFFFFFFFFFi64,
                         0i64,
                         0x4000004u,
                         0,
                         SystemInfo.dwAllocationGranularity,
                         lpName);
        if ( FileMappingW )
        {
          v9 = (struct _DBG_TCB_HEADER **)MapViewOfFileEx(
                                            FileMappingW,
                                            6u,
                                            0,
                                            0,
                                            SystemInfo.dwAllocationGranularity,
                                            0i64);
          v1 = v9;
          if ( v9 )
          {
            v10 = (struct _RTL_CRITICAL_SECTION *)VirtualAlloc(v9, SystemInfo.dwPageSize, 0x1000u, 4u);
            v11 = v10;
            if ( v10 )
            {
              memset_0(v10, 0, 0x80ui64);
              LODWORD(v11->DebugInfo) = 1819440227;
              *(_QWORD *)&v11[1].LockCount = v11 + 1;
              v11[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)&v11[1];
              *(_QWORD *)&v11->LockCount = v11;
              NtQuerySystemInformation(SystemKernelDebuggerInformation, &v11[1].OwningThread, 2u, 0i64);
              InitializeCriticalSection(v11 + 2);
              if ( NtSetEvent(Handle, &PreviousState) >= 0 )
              {
                v1 = 0i64;
                v11->LockSemaphore = Handle;
                Handle = 0i64;
                v11->OwningThread = FileMappingW;
                FileMappingW = 0i64;
                v11[1].SpinCount = 0i64;
                DbgpGlobalControllerHeader = (struct _DBG_TCB_HEADER *)v11;
              }
            }
          }
        }
      }
    }
    if ( Handle )
      NtClose(Handle);
    if ( v1 )
      UnmapViewOfFile(v1);
    if ( FileMappingW )
      CloseHandle(FileMappingW);
  }
  return DbgpGlobalControllerHeader;
}
// 180092810: using guessed type struct _DBG_TCB_HEADER *DbgpGlobalControllerHeader;

