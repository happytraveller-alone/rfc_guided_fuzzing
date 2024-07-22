//----- (0000000180016064) ----------------------------------------------------
NTSTATUS __fastcall GetSslDWordFromRegistry(HANDLE KeyHandle, const WCHAR *a2, _DWORD *a3)
{
  NTSTATUS result; // eax
  ULONG ResultLength; // [rsp+30h] [rbp-48h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-40h] BYREF
  __int128 KeyValueInformation; // [rsp+48h] [rbp-30h] BYREF
  int v9; // [rsp+58h] [rbp-20h]

  ResultLength = 0;
  DestinationString = 0i64;
  v9 = 0;
  KeyValueInformation = 0i64;
  RtlInitUnicodeString(&DestinationString, a2);
  result = NtQueryValueKey(
             KeyHandle,
             &DestinationString,
             KeyValuePartialInformation,
             &KeyValueInformation,
             0x14u,
             &ResultLength);
  if ( result >= 0 )
  {
    if ( DWORD1(KeyValueInformation) == 4 )
      *a3 = HIDWORD(KeyValueInformation);
    else
      return -1073739509;
  }
  return result;
}

