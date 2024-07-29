//----- (000000018005B8DC) ----------------------------------------------------
__int64 __fastcall DTLSCookieManager::ComputeCookie(
        DTLSCookieManager *this,
        unsigned __int8 *const a2,
        ULONG a3,
        unsigned __int8 *const a4,
        ULONG cbInput,
        unsigned __int8 *const pbInput,
        ULONG a7,
        unsigned __int8 *pbOutput)
{
  void *v12; // rcx
  NTSTATUS v13; // ebx
  UCHAR *v15; // [rsp+20h] [rbp-38h]
  ULONG cbSecret; // [rsp+28h] [rbp-30h]
  BCRYPT_HASH_HANDLE hHash; // [rsp+60h] [rbp+8h] BYREF

  cbSecret = *(_DWORD *)this;
  v15 = (UCHAR *)*((_QWORD *)this + 1);
  v12 = (void *)*((_QWORD *)this + 3);
  hHash = 0i64;
  v13 = BCryptCreateHash(v12, &hHash, 0i64, 0, v15, cbSecret, 0);
  if ( v13 >= 0 )
  {
    v13 = BCryptHashData(hHash, a2, a3, 0);
    if ( v13 >= 0 )
    {
      v13 = BCryptHashData(hHash, a4, cbInput, 0);
      if ( v13 >= 0 )
      {
        v13 = BCryptHashData(hHash, pbInput, a7, 0);
        if ( v13 >= 0 )
        {
          v13 = BCryptFinishHash(hHash, pbOutput, *((_DWORD *)this + 8), 0);
          if ( v13 >= 0 )
            v13 = 0;
        }
      }
    }
  }
  if ( hHash )
    BCryptDestroyHash(hHash);
  return (unsigned int)v13;
}
