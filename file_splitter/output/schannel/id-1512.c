// File count: 1512
// Total lines: 38
----------------------------------------
int __fastcall GetSslStringFromRegistry(HANDLE KeyHandle, PCWSTR SourceString, char *a3)
{
  int result; // eax
  ULONG ResultLength; // [rsp+30h] [rbp-D8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-D0h] BYREF
  char KeyValueInformation[4]; // [rsp+50h] [rbp-B8h] BYREF
  int v10; // [rsp+54h] [rbp-B4h]
  unsigned int v11; // [rsp+58h] [rbp-B0h]
  unsigned __int16 v12[66]; // [rsp+5Ch] [rbp-ACh] BYREF

  ResultLength = 0;
  DestinationString = 0i64;
  memset_0(KeyValueInformation, 0, 0x90ui64);
  RtlInitUnicodeString(&DestinationString, SourceString);
  result = NtQueryValueKey(
             KeyHandle,
             &DestinationString,
             KeyValuePartialInformation,
             KeyValueInformation,
             0x90u,
             &ResultLength);
  if ( result >= 0 )
  {
    if ( v10 == 1 && v11 - 1 <= 0x7C )
    {
      result = RtlStringCchCopyNW(a3, 64i64, (char *)v12, (unsigned __int64)v11 >> 1);
      if ( result < 0 )
        return -1073741595;
    }
    else
    {
      return -1073739509;
    }
  }
  return result;
}
// 180079924: using guessed type unsigned __int16 var_AC[66];
