//----- (000000018004BDC0) ----------------------------------------------------
BOOL __stdcall SslEmptyCacheW(LPWSTR pszTargetName, DWORD dwFlags)
{
  _QWORD *v3; // rdi
  signed int v4; // ebx
  unsigned int v5; // ebp
  int v6; // eax
  unsigned int v7; // r14d
  char *v8; // rax
  char *v9; // rbx
  __int64 v10; // rax
  void *LsaHandle; // [rsp+40h] [rbp-48h] BYREF
  struct _STRING DestinationString; // [rsp+48h] [rbp-40h] BYREF
  ULONG AuthenticationPackage; // [rsp+A0h] [rbp+18h] BYREF
  int ProtocolStatus; // [rsp+A8h] [rbp+20h] BYREF

  LsaHandle = 0i64;
  v3 = 0i64;
  v4 = LsaConnectUntrusted(&LsaHandle);
  if ( v4 >= 0 )
  {
    RtlInitAnsiString(&DestinationString, "Schannel");
    v4 = LsaLookupAuthenticationPackage(LsaHandle, (PLSA_STRING)&DestinationString, &AuthenticationPackage);
    if ( v4 >= 0 )
    {
      v5 = 40;
      if ( pszTargetName )
      {
        v6 = lstrlenW(pszTargetName);
        v7 = 2 * v6 + 2;
        v5 = 2 * v6 + 42;
        v8 = (char *)SPExternalAlloc(v5);
        v3 = v8;
        if ( !v8 )
          goto LABEL_5;
        v9 = v8 + 40;
        memcpy_0(v8 + 40, pszTargetName, v7);
        v10 = -1i64;
        v3[3] = v9;
        do
          ++v10;
        while ( pszTargetName[v10] );
        *((_WORD *)v3 + 9) = v7;
        *((_WORD *)v3 + 8) = 2 * v10;
      }
      else
      {
        v3 = SPExternalAlloc(0x28u);
        if ( !v3 )
        {
LABEL_5:
          v4 = -2146893056;
          goto LABEL_13;
        }
      }
      *(_DWORD *)v3 = 3;
      *((_DWORD *)v3 + 8) = 3;
      v4 = LsaCallAuthenticationPackage(LsaHandle, AuthenticationPackage, v3, v5, 0i64, 0i64, &ProtocolStatus);
      if ( v4 >= 0 && ProtocolStatus < 0 )
        v4 = ProtocolStatus;
    }
  }
LABEL_13:
  if ( LsaHandle )
    LsaDeregisterLogonProcess(LsaHandle);
  if ( v3 )
    SPExternalFree(v3);
  if ( v4 >= 0 )
    return 1;
  SetLastError(v4);
  return 0;
}
