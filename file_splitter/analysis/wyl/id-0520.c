//----- (000000018002647C) ----------------------------------------------------
LSTATUS __fastcall WatchParamKeyHelper(char *pvContext)
{
  HKEY *v2; // rdi
  LSTATUS result; // eax
  LSTATUS v4; // edi
  NTSTATUS v5; // eax
  DWORD v6; // [rsp+60h] [rbp+8h] BYREF

  if ( !pvContext )
    return 0;
  v2 = (HKEY *)(pvContext + 16);
  if ( *((_QWORD *)pvContext + 2)
    || (result = RegCreateKeyExW(
                   HKEY_LOCAL_MACHINE,
                   *((LPCWSTR *)pvContext + 3),
                   0,
                   (LPWSTR)&Class,
                   0,
                   0x20019u,
                   0i64,
                   v2,
                   &v6)) == 0 )
  {
    v4 = RegNotifyChangeKeyValue(*v2, 1, 0x10000005u, *((HANDLE *)pvContext + 1), 1);
    if ( !*(_QWORD *)pvContext || (v5 = RtlDeregisterWait(*(HANDLE *)pvContext), *(_QWORD *)pvContext = 0i64, v5 >= 0) )
    {
      if ( !v4 )
        RtlRegisterWait(
          (PHANDLE)pvContext,
          *((HANDLE *)pvContext + 1),
          *((WAITORTIMERCALLBACKFUNC *)pvContext + 4),
          pvContext,
          0xFFFFFFFF,
          0x48u);
    }
    return 0;
  }
  return result;
}

