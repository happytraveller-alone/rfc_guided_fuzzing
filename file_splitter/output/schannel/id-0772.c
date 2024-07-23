// File count: 772
// Total lines: 15
-----------------------------------------
void __fastcall Init_thread_wait(DWORD dwMilliseconds)
{
  if ( qword_1800920B8 )
  {
    qword_1800920B8(&unk_180092080, &CriticalSection, dwMilliseconds);
  }
  else
  {
    LeaveCriticalSection(&CriticalSection);
    WaitForSingleObjectEx(hHandle, dwMilliseconds, 0);
    EnterCriticalSection(&CriticalSection);
  }
}
// 1800920B8: using guessed type __int64 (__fastcall *qword_1800920B8)(_QWORD, _QWORD, _QWORD);
