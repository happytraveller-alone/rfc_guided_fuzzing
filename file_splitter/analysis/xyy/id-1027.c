//----- (0000000180055DE0) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::GetFileFullPath(
        CCredentialGroup *this,
        const unsigned __int16 *a2,
        unsigned __int16 **a3)
{
  unsigned int v5; // ebx
  DWORD v6; // eax
  DWORD v7; // edi
  signed int v8; // eax
  WCHAR *v9; // rax
  unsigned __int16 *v10; // rsi
  signed int LastError; // eax
  unsigned int v12; // edi

  v5 = 0;
  v6 = ExpandEnvironmentStringsW(a2, 0i64, 0);
  v7 = v6;
  if ( v6 )
  {
    v9 = (WCHAR *)LocalAlloc(0x40u, 2i64 * v6);
    v10 = v9;
    if ( v9 )
    {
      if ( ExpandEnvironmentStringsW(a2, v9, v7) )
      {
        *a3 = v10;
      }
      else
      {
        LastError = GetLastError();
        v12 = LastError;
        if ( LastError > 0 )
          v12 = (unsigned __int16)LastError | 0x80070000;
        LocalFree(v10);
        return v12;
      }
    }
    else
    {
      return (unsigned int)-2146893810;
    }
  }
  else
  {
    v8 = GetLastError();
    if ( v8 > 0 )
      return (unsigned __int16)v8 | 0x80070000;
    else
      return (unsigned int)v8;
  }
  return v5;
}
