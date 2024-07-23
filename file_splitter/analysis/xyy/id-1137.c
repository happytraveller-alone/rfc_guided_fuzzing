//----- (000000018005C0F0) ----------------------------------------------------
ULONG __fastcall CreateUnicodeStringFromAlpnId(
        unsigned __int8 *a1,
        unsigned int a2,
        char a3,
        struct _UNICODE_STRING *a4)
{
  unsigned __int8 *v4; // r10
  unsigned int v5; // r8d
  NTSTATUS v7; // eax
  struct _STRING SourceString; // [rsp+20h] [rbp-18h] BYREF

  *(_DWORD *)(&SourceString.MaximumLength + 1) = 0;
  v4 = a1;
  if ( a1 && a4 && a4->Buffer && a2 )
  {
    if ( !a3 )
    {
      v5 = *a1;
      if ( v5 > a2 - 1 )
        return 1359;
      v4 = a1 + 1;
      goto LABEL_11;
    }
    if ( a2 <= 0xFF )
    {
      LOWORD(v5) = a2;
LABEL_11:
      SourceString.Length = v5;
      SourceString.MaximumLength = v5;
      SourceString.Buffer = (PCHAR)v4;
      v7 = RtlAnsiStringToUnicodeString(a4, &SourceString, 0);
      return RtlNtStatusToDosError(v7);
    }
  }
  return 87;
}

