// File count: 307
// Total lines: 21
-----------------------------------------
void LoadSecurityDll(void)
{
  HMODULE Library; // rax
  HMODULE v1; // rax

  Library = LoadLibraryExW(L"sspicli.dll", 0i64, 0);
  g_hSspicli = Library;
  if ( Library )
    g_pFreeContextBuffer = (int (__stdcall *)(void *))GetProcAddress(Library, "FreeContextBuffer");
  v1 = LoadLibraryExW(L"mskeyprotect.dll", 0i64, 0x800u);
  g_hMskeyprotect = v1;
  if ( v1 )
  {
    g_pKeyFileProtectSessionTicket = (unsigned int (__stdcall *)(unsigned __int8 *, unsigned int, const unsigned __int16 *, unsigned __int8 **, unsigned int *))GetProcAddress(v1, "KeyFileProtectSessionTicket");
    g_pKeyFileUnprotectSessionTicket = (unsigned int (__stdcall *)(unsigned __int8 *, unsigned int, const unsigned __int16 *, unsigned __int8 **, unsigned int *))GetProcAddress(g_hMskeyprotect, "KeyFileUnprotectSessionTicket");
  }
}
// 180092180: using guessed type unsigned int (__stdcall *g_pKeyFileUnprotectSessionTicket)(unsigned __int8 *, unsigned int, const unsigned __int16 *, unsigned __int8 **, unsigned int *);
// 180092188: using guessed type unsigned int (__stdcall *g_pKeyFileProtectSessionTicket)(unsigned __int8 *, unsigned int, const unsigned __int16 *, unsigned __int8 **, unsigned int *);
// 1800921A0: using guessed type int (__stdcall *g_pFreeContextBuffer)(void *);
