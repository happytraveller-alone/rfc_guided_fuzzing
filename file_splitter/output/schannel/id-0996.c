// File count: 996
// Total lines: 12
-----------------------------------------
__int64 __fastcall GetElapsedTime(DWORD a1)
{
  DWORD TickCount; // eax
  DWORD v3; // ecx

  TickCount = GetTickCount();
  v3 = TickCount - a1;
  if ( a1 > TickCount )
    --v3;
  return v3;
}
