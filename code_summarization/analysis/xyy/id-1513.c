//----- (0000000180079A10) ----------------------------------------------------
__int64 __fastcall _DbgpControlTracing(struct _DBG_TRACE_CONTROL_BLOCK *a1, int a2, int a3)
{
  unsigned int v7; // r14d
  unsigned int v8; // r15d
  bool v9; // zf
  BOOL v10; // esi
  int v11; // edx
  int v12; // ebx
  ULONG started; // ebx
  __int64 v15; // r8
  int v16; // ecx
  int v17; // edx
  DWORD WindowsDirectoryW; // eax
  __int64 v19; // rdx
  __int64 v20; // rax
  __int64 v21; // rbx
  WCHAR *v22; // r15
  unsigned __int16 *v23; // r12
  DWORD CurrentDirectoryW; // eax
  PVOID Heap; // rax
  __int64 v26; // rbx
  __int64 v27; // rax
  wchar_t *v28; // rbx
  __int64 v29; // rcx
  int v30; // eax
  TRACEHANDLE *v31; // r14
  UCHAR v32; // r9
  TRACEHANDLE v33; // rcx
  ULONGLONG MatchAnyKeyword; // [rsp+20h] [rbp-E0h]
  int v35; // [rsp+80h] [rbp-80h]
  DWORD nSize; // [rsp+84h] [rbp-7Ch] BYREF
  int v37; // [rsp+88h] [rbp-78h]
  struct _ENABLE_TRACE_PARAMETERS EnableParameters; // [rsp+90h] [rbp-70h] BYREF
  struct _OSVERSIONINFOW VersionInformation; // [rsp+C0h] [rbp-40h] BYREF
  unsigned __int16 v40; // [rsp+1D4h] [rbp+D4h]
  unsigned __int16 v41; // [rsp+1D6h] [rbp+D6h]
  unsigned __int16 v42; // [rsp+1D8h] [rbp+D8h]
  unsigned __int8 v43; // [rsp+1DAh] [rbp+DAh]
  wchar_t Destination[264]; // [rsp+1E0h] [rbp+E0h] BYREF
  WCHAR Buffer[264]; // [rsp+3F0h] [rbp+2F0h] BYREF
  WCHAR PathName[264]; // [rsp+600h] [rbp+500h] BYREF
  WCHAR v47[264]; // [rsp+810h] [rbp+710h] BYREF
  WCHAR NewFileName[264]; // [rsp+A20h] [rbp+920h] BYREF
  WCHAR ExistingFileName[264]; // [rsp+C30h] [rbp+B30h] BYREF
  unsigned __int16 v50[264]; // [rsp+E40h] [rbp+D40h] BYREF

  memset_0(&VersionInformation, 0, 0x11Cui64);
  v7 = 10;
  v8 = (*((unsigned __int16 *)a1 + 28) >> 1) + 10;
  memset_0(PathName, 0, 0x208ui64);
  v9 = *((_QWORD *)a1 + 9) == 0i64;
  memset(&EnableParameters, 0, sizeof(EnableParameters));
  v10 = !v9 && *((_QWORD *)a1 + 11);
  v11 = a2;
  v35 = a2;
  v37 = a2;
  v12 = a2 & 0xFFFFFFF;
  if ( a3 )
  {
    *((_DWORD *)a1 + 27) = v12;
    if ( !v12 )
    {
LABEL_7:
      started = 0;
      goto LABEL_8;
    }
  }
  else
  {
    if ( v12 == *((_DWORD *)a1 + 27) )
    {
      if ( !v10 )
        goto LABEL_7;
      v15 = *((_QWORD *)a1 + 11);
      v16 = *(_DWORD *)(v15 + 64);
      if ( a2 >= 0 == ((v16 & 0x80000) == 0) || !*((_BYTE *)DbgpGlobalControllerHeader + 56) )
      {
        v17 = v11 & 0x40000000;
        if ( (v17 == 0) == ((v16 & 0x100) == 0) )
        {
          if ( v17 )
          {
            if ( *((_DWORD *)a1 + 8) == *(_DWORD *)(v15 + 68) )
              goto LABEL_7;
          }
          else if ( !*(_DWORD *)(v15 + 68) )
          {
            goto LABEL_7;
          }
        }
        v11 = v35;
      }
    }
    *((_DWORD *)a1 + 27) = v12;
    if ( !v12 )
    {
      if ( v10 )
      {
        _DbgpStopTracing(a1);
        goto LABEL_7;
      }
      goto LABEL_25;
    }
  }
  if ( v10 )
  {
LABEL_51:
    Destination[0] = 0;
LABEL_52:
    if ( !v10 )
    {
      *((_DWORD *)a1 + 20) = 1160;
      Heap = RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x488ui64);
      *((_QWORD *)a1 + 11) = Heap;
      if ( !Heap )
      {
        started = 14;
        goto LABEL_8;
      }
      memset_0(Heap, 0, *((unsigned int *)a1 + 20));
      **((_DWORD **)a1 + 11) = *((_DWORD *)a1 + 20);
      *(_DWORD *)(*((_QWORD *)a1 + 11) + 44i64) = 0x20000;
      *(_DWORD *)(*((_QWORD *)a1 + 11) + 116i64) = 120;
      v26 = *((_QWORD *)a1 + 11) + *(unsigned int *)(*((_QWORD *)a1 + 11) + 116i64);
      o_wcsncpy_s_0(v26, 260i64, *((_QWORD *)a1 + 8), 259i64);
      *(_WORD *)(v26 + 518) = 0;
      v27 = *((_QWORD *)a1 + 11);
      if ( Destination[0] )
      {
        *(_DWORD *)(v27 + 60) = 1;
        *(_DWORD *)(*((_QWORD *)a1 + 11) + 112i64) = 640;
        v28 = (wchar_t *)(*((_QWORD *)a1 + 11) + *(unsigned int *)(*((_QWORD *)a1 + 11) + 112i64));
        snwprintf_s(v28, 0x103ui64, 0x103ui64, L"%s\\%s", Buffer, Destination);
        v28[259] = 0;
        *(_DWORD *)(*((_QWORD *)a1 + 11) + 64i64) |= 0x4002u;
      }
      else
      {
        *(_DWORD *)(v27 + 64) |= 0x8400u;
      }
    }
    if ( v37 < 0 && *((_BYTE *)DbgpGlobalControllerHeader + 56) )
      *(_DWORD *)(*((_QWORD *)a1 + 11) + 64i64) |= 0x80000u;
    else
      *(_DWORD *)(*((_QWORD *)a1 + 11) + 64i64) &= ~0x80000u;
    v29 = *((_QWORD *)a1 + 11);
    v30 = *(_DWORD *)(v29 + 64);
    if ( (v35 & 0x40000000) != 0 )
    {
      *(_DWORD *)(v29 + 64) = v30 | 0x100;
      *(_DWORD *)(*((_QWORD *)a1 + 11) + 68i64) = *((_DWORD *)a1 + 8);
    }
    else
    {
      *(_DWORD *)(v29 + 64) = v30 & 0xFFFFFEFF;
      *(_DWORD *)(*((_QWORD *)a1 + 11) + 68i64) = 0;
    }
    if ( v10 )
    {
      v31 = (TRACEHANDLE *)((char *)a1 + 72);
    }
    else
    {
      started = ControlTraceW(0i64, *((LPCWSTR *)a1 + 8), *((PEVENT_TRACE_PROPERTIES *)a1 + 11), 0);
      if ( started != 4201 )
        goto LABEL_67;
      v31 = (TRACEHANDLE *)((char *)a1 + 72);
      *(_DWORD *)(*((_QWORD *)a1 + 11) + 72i64) = *((_DWORD *)a1 + 27);
      started = StartTraceW((PTRACEHANDLE)a1 + 9, *((LPCWSTR *)a1 + 8), *((PEVENT_TRACE_PROPERTIES *)a1 + 11));
      if ( started )
        goto LABEL_67;
    }
    v32 = *((_BYTE *)a1 + 104);
    v33 = *v31;
    MatchAnyKeyword = *((unsigned int *)a1 + 27);
    EnableParameters.Version = 1;
    started = EnableTraceEx2(v33, (LPCGUID)a1 + 7, 1u, v32, MatchAnyKeyword, 0i64, 0, &EnableParameters);
    if ( !started )
      goto LABEL_7;
    if ( v10 )
      goto LABEL_8;
LABEL_67:
    _DbgpStopTracing(a1);
    goto LABEL_8;
  }
LABEL_25:
  if ( (v11 & 0x20000000) != 0 )
    goto LABEL_51;
  WindowsDirectoryW = GetWindowsDirectoryW(Buffer, 260 - v8);
  nSize = WindowsDirectoryW;
  if ( !WindowsDirectoryW )
  {
LABEL_27:
    started = GetLastError();
    goto LABEL_8;
  }
  if ( WindowsDirectoryW <= 260 - (unsigned __int64)v8 )
  {
    wcscat_s(Buffer, 0x104ui64, L"\\tracing");
    if ( !CreateDirectoryW(Buffer, 0i64) )
    {
      started = GetLastError();
      if ( started != 183 )
        goto LABEL_8;
    }
    wcscat_s(Buffer, 0x103ui64, L"\\");
    wcscat_s(Buffer, 0x103ui64, *((const wchar_t **)a1 + 8));
    Buffer[259] = 0;
    if ( !CreateDirectoryW(Buffer, 0i64) )
    {
      started = GetLastError();
      if ( started != 183 )
        goto LABEL_8;
    }
    VersionInformation.dwOSVersionInfoSize = 284;
    if ( GetVersionExW(&VersionInformation) )
    {
      _DbgpGetFileVersionString(*((LPCWSTR *)a1 + 6), v19, v50);
      nSize = 259;
      v47[259] = 0;
      if ( GetComputerNameExW(ComputerNameNetBIOS, v47, &nSize) )
      {
        Destination[259] = 0;
        snwprintf_s(
          Destination,
          0x103ui64,
          0xFFui64,
          L"%s_%wZ_%d_%d_%d_%d_%d_%d_%s_%x_%s",
          v47,
          (char *)a1 + 56,
          v43,
          VersionInformation.dwMajorVersion,
          VersionInformation.dwMinorVersion,
          VersionInformation.dwBuildNumber,
          v40,
          v41,
          VersionInformation.szCSDVersion,
          v42,
          v50);
        wcscat_s(Destination, 0x103ui64, L".etl");
        v20 = -1i64;
        do
          ++v20;
        while ( Destination[v20] );
        v21 = (unsigned int)(v20 - 4);
        v22 = &ExistingFileName[v21];
        v23 = &NewFileName[v21];
        CurrentDirectoryW = GetCurrentDirectoryW(0x103u, PathName);
        if ( !CurrentDirectoryW )
          return GetLastError();
        if ( CurrentDirectoryW >= 0x103 )
          return 122;
        if ( SetCurrentDirectoryW(Buffer) )
        {
          memcpy_0(ExistingFileName, Destination, v21 * 2);
          memcpy_0(NewFileName, Destination, v21 * 2);
          while ( 1 )
          {
            _DbgpSetExt(v7, v23);
            if ( v7 == 1 )
            {
              *(_QWORD *)v22 = *(_QWORD *)L".etl";
              v22[4] = aEtl[4];
            }
            else
            {
              _DbgpSetExt(v7 - 1, v22);
            }
            if ( !MoveFileExW(ExistingFileName, NewFileName, 1u) )
            {
              started = GetLastError();
              if ( started != 2 )
                goto LABEL_8;
            }
            if ( !--v7 )
              goto LABEL_52;
          }
        }
      }
    }
    goto LABEL_27;
  }
  started = 122;
LABEL_8:
  if ( PathName[0] )
    SetCurrentDirectoryW(PathName);
  return started;
}
// 180079CEF: variable 'v19' is possibly undefined
// 180028D84: using guessed type __int64 __fastcall o_wcsncpy_s_0(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092810: using guessed type struct _DBG_TCB_HEADER *DbgpGlobalControllerHeader;
