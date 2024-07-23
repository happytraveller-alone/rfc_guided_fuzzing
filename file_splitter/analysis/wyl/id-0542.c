//----- (0000000180027520) ----------------------------------------------------
__int64 SchInitializeEvents(void)
{
  unsigned int v0; // ecx
  HMODULE Library; // rax
  HMODULE v2; // rbx
  unsigned __int64 v3; // rax
  DWORD Data; // [rsp+60h] [rbp+8h] BYREF
  HKEY hKey; // [rsp+68h] [rbp+10h] BYREF

  v0 = RegCreateKeyExW(
         HKEY_LOCAL_MACHINE,
         L"System\\CurrentControlSet\\Services\\EventLog\\System\\Schannel",
         0,
         (LPWSTR)&Class,
         0,
         0x20006u,
         0i64,
         &hKey,
         &Data);
  if ( !v0 )
  {
    if ( Data == 1 )
    {
      RegSetValueExW(hKey, L"EventMessageFile", 0, 2u, L"%SystemRoot%\\system32\\lsasrv.dll", 0x42u);
      Data = 7;
      RegSetValueExW(hKey, L"TypesSupported", 0, 4u, (const BYTE *)&Data, 4u);
      RegFlushKey(hKey);
    }
    RegCloseKey(hKey);
    Library = LoadLibraryExW(L"lsasrv.dll", 0i64, 0);
    v2 = Library;
    if ( Library )
    {
      SchGetMessageString(Library, 0x80009080, (WCHAR *)&pszClientString);
      SchGetMessageString(v2, 0x80009081, (WCHAR *)&pszServerString);
      FreeLibrary(v2);
      v0 = EtwEventRegister(&S_Microsoft_Windows_Schannel, 0i64, 0i64, &g_RegistrationHandle);
      v3 = g_RegistrationHandle;
      if ( v0 )
        v3 = 0i64;
      g_RegistrationHandle = v3;
    }
    else
    {
      return GetLastError();
    }
  }
  return v0;
}
// 180080EA8: using guessed type __int64 __fastcall EtwEventRegister(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092D80: using guessed type unsigned __int64 g_RegistrationHandle;

