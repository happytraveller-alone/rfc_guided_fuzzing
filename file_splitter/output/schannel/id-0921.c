// File count: 921
// Total lines: 39
-----------------------------------------
__int64 __fastcall WppControlCallback(int a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  int v5; // ecx
  __int64 result; // rax
  __int64 TraceLoggerHandle; // rdi
  int TraceEnableFlags; // eax
  char TraceEnableLevel; // si

  *a3 = 0;
  v5 = a1 - 4;
  if ( v5 )
  {
    if ( v5 != 1 )
      return 87i64;
    TraceLoggerHandle = 0i64;
    TraceEnableFlags = 0;
    TraceEnableLevel = 0;
  }
  else
  {
    TraceLoggerHandle = EtwGetTraceLoggerHandle(a4);
    TraceEnableLevel = EtwGetTraceEnableLevel(TraceLoggerHandle);
    TraceEnableFlags = EtwGetTraceEnableFlags(TraceLoggerHandle);
  }
  if ( (*(_BYTE *)(a2 + 26) & 2) != 0 )
  {
    if ( *(_QWORD *)(a2 + 16) )
      a2 = *(_QWORD *)(a2 + 16);
  }
  *(_DWORD *)(a2 + 28) = TraceEnableFlags;
  result = 0i64;
  *(_QWORD *)(a2 + 16) = TraceLoggerHandle;
  *(_BYTE *)(a2 + 25) = TraceEnableLevel;
  return result;
}
// 180080E18: using guessed type __int64 __fastcall EtwGetTraceEnableFlags(_QWORD);
// 180080E20: using guessed type __int64 __fastcall EtwGetTraceEnableLevel(_QWORD);
// 180080E28: using guessed type __int64 __fastcall EtwGetTraceLoggerHandle(_QWORD);
