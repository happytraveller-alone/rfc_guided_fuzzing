//----- (000000018002763C) ----------------------------------------------------
__int64 __fastcall SchGetMessageString(LPCVOID lpSource, DWORD dwMessageId, WCHAR *a3)
{
  DWORD v4; // eax

  *(_QWORD *)a3 = 0i64;
  v4 = FormatMessageW(0x900u, lpSource, dwMessageId, 0, a3, 0, 0i64);
  if ( !v4 || !*(_QWORD *)a3 )
    return 1812i64;
  *(_WORD *)(*(_QWORD *)a3 + 2i64 * (v4 - 2)) = 0;
  return 0i64;
}
