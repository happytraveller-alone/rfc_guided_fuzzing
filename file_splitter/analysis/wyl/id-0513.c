//----- (0000000180025F94) ----------------------------------------------------
NTSTATUS __fastcall _DbgpWaitForControllerEvent(int *a1, void **a2)
{
  wchar_t *TraceMappingName; // rax
  NTSTATUS result; // eax
  void *v6; // rcx
  union _LARGE_INTEGER Timeout; // [rsp+30h] [rbp-D0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-C8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+48h] [rbp-B8h] BYREF
  wchar_t Buffer[264]; // [rsp+80h] [rbp-80h] BYREF

  DestinationString = 0i64;
  *a1 = 0;
  Buffer[259] = 0;
  TraceMappingName = _DbgpGetTraceMappingName();
  snwprintf_s(Buffer, 0x104ui64, 0x103ui64, L"\\DSYSDBG.%s", TraceMappingName);
  RtlInitUnicodeString(&DestinationString, Buffer);
  ObjectAttributes.Length = 48;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.RootDirectory = 0i64;
  ObjectAttributes.Attributes = 0;
  *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0i64;
  result = NtCreateEvent(a2, 0x100002u, &ObjectAttributes, NotificationEvent, 0);
  if ( result == -1073741771 || result == 0x40000000 )
  {
    result = NtOpenEvent(a2, 0x100000u, &ObjectAttributes);
    if ( result >= 0 )
    {
      v6 = *a2;
      Timeout.QuadPart = -600000000i64;
      result = NtWaitForSingleObject(v6, 0, &Timeout);
      if ( result )
      {
        if ( result >= 0 )
          return -1073741823;
      }
      else
      {
        *a1 = 1;
      }
    }
  }
  return result;
}
