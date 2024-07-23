//----- (000000018000187C) ----------------------------------------------------
__int64 SslInitContextManager(void)
{
  unsigned int v0; // ebx
  DWORD v1; // edi
  _QWORD *v2; // rax
  int v4; // eax
  int v5; // eax
  DWORD i; // esi
  DWORD v7; // [rsp+50h] [rbp-28h] BYREF
  HKEY hKey; // [rsp+58h] [rbp-20h] BYREF
  DWORD cbData; // [rsp+80h] [rbp+8h] BYREF
  DWORD Type; // [rsp+88h] [rbp+10h] BYREF
  int Data; // [rsp+90h] [rbp+18h] BYREF
  int v12; // [rsp+98h] [rbp+20h] BYREF

  v0 = 0;
  v1 = 0;
  hKey = 0i64;
  if ( dword_1800921C0 )
    return 1i64;
  if ( !RegCreateKeyExW(
          HKEY_LOCAL_MACHINE,
          L"System\\CurrentControlSet\\Control\\SecurityProviders\\Schannel",
          0,
          (LPWSTR)&Class,
          0,
          0x20019u,
          0i64,
          &hKey,
          &v7) )
  {
    cbData = 4;
    if ( !RegQueryValueExW(hKey, L"UserContextLockCount", 0i64, &Type, (LPBYTE)&Data, &cbData)
      && Type == 4
      && (unsigned int)(Data - 1) <= 0x1FF )
    {
      v4 = dwSslContextLockCount;
      if ( ((Data - 1) & Data) == 0 )
        v4 = Data;
      dwSslContextLockCount = v4;
    }
    cbData = 4;
    if ( !RegQueryValueExW(hKey, L"UserContextListCount", 0i64, &Type, (LPBYTE)&v12, &cbData) && Type == 4 && v12 )
    {
      v5 = dwSslContextListCount;
      if ( ((v12 - 1) & v12) == 0 )
        v5 = v12;
      dwSslContextListCount = v5;
    }
    RegCloseKey(hKey);
    hKey = 0i64;
  }
  SslContextLock = SPExternalAlloc(96 * dwSslContextLockCount);
  if ( !SslContextLock )
    goto LABEL_25;
  while ( 1 )
  {
    cbData = v1;
    if ( v1 >= dwSslContextLockCount )
      break;
    RtlInitializeResource((PRTL_RESOURCE)SslContextLock + v1++);
  }
  SslContextList = SPExternalAlloc(16 * dwSslContextListCount);
  if ( SslContextList )
  {
    while ( v0 < dwSslContextListCount )
    {
      v2 = (char *)SslContextList + 16 * v0;
      v2[1] = v2;
      *v2 = v2;
      ++v0;
    }
    dword_1800921C0 = 1;
    return 1;
  }
  else
  {
LABEL_25:
    if ( SslContextList )
    {
      SPExternalFree(SslContextList);
      SslContextList = 0i64;
    }
    if ( SslContextLock )
    {
      for ( i = 0; i < v1; ++i )
        RtlDeleteResource((PRTL_RESOURCE)SslContextLock + i);
      SPExternalFree(SslContextLock);
      SslContextLock = 0i64;
    }
  }
  return v0;
}
// 1800019FE: conditional instruction was optimized away because esi.4==0
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800919E0: using guessed type unsigned int dwSslContextListCount;
// 1800919E4: using guessed type unsigned int dwSslContextLockCount;
// 1800921C0: using guessed type int dword_1800921C0;

// 底层资源的初始化，而不是直接实现TLS协议逻辑
// 为TLS实现提供了必要的基础设施，包括：
//    上下文锁：用于线程同步，确保并发访问的安全性。
//    上下文列表：可能用于管理多个TLS连接的上下文。

