//----- (000000018004BD20) ----------------------------------------------------
BOOL __stdcall SslEmptyCacheA(LPSTR pszTargetName, DWORD dwFlags)
{
  WCHAR *Buffer; // rcx
  BOOL v6; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-28h] BYREF
  struct _STRING SourceString; // [rsp+30h] [rbp-18h] BYREF

  *(_DWORD *)&DestinationString.Length = 0;
  Buffer = 0i64;
  DestinationString.Buffer = 0i64;
  if ( pszTargetName )
  {
    RtlInitAnsiString(&SourceString, pszTargetName);
    if ( RtlAnsiStringToUnicodeString(&DestinationString, &SourceString, 1u) < 0 )
    {
      SetLastError(0x80090300);
      return 0;
    }
    Buffer = DestinationString.Buffer;
  }
  v6 = SslEmptyCacheW(Buffer, dwFlags);
  if ( DestinationString.Buffer )
    RtlFreeUnicodeString(&DestinationString);
  return v6;
}

