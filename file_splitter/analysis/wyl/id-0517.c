//----- (0000000180026354) ----------------------------------------------------
wchar_t *_DbgpGetTraceMappingName(void)
{
  DWORD CurrentProcessId; // [rsp+20h] [rbp-18h]

  if ( !Buffer )
  {
    word_180092A26 = 0;
    CurrentProcessId = GetCurrentProcessId();
    snwprintf_s(&Buffer, 0x104ui64, 0x103ui64, L"Debug.Trace.Memory.%x", CurrentProcessId);
  }
  return &Buffer;
}
// 180092A26: using guessed type __int16 word_180092A26;
