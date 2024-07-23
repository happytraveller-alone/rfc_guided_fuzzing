//----- (000000018005C9B4) ----------------------------------------------------
__int64 __fastcall OpenKeyUsingCAPI(
        unsigned __int64 *a1,
        const unsigned __int16 *a2,
        const unsigned __int16 *a3,
        DWORD a4,
        unsigned int a5)
{
  unsigned int LastError; // ebx
  unsigned int CurrentProcessId; // eax

  LastError = 0;
  if ( !CryptAcquireContextW(a1, a2, a3, a4, a5 & 0xFFFFFFFE) )
  {
    LastError = GetLastError();
    CurrentProcessId = GetCurrentProcessId();
    LogCredAcquireContextFailedEvent(CurrentProcessId, L"<UNKNOWN>", 0, LastError, 10014);
  }
  return LastError;
}
// 180085488: using guessed type wchar_t aUnknown_0[10];

