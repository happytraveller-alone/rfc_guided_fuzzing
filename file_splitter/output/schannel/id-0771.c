// File count: 771
// Total lines: 9
------------------------------------------
int Init_thread_notify()
{
  if ( qword_1800920C0 )
    return qword_1800920C0(&unk_180092080);
  SetEvent(hHandle);
  return ResetEvent(hHandle);
}
// 1800920C0: using guessed type __int64 (__fastcall *qword_1800920C0)(_QWORD);
