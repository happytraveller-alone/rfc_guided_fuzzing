//----- (000000018005BBC8) ----------------------------------------------------
int __fastcall DTLSCookieManager::init(DTLSCookieManager *this, const unsigned __int16 *a2)
{
  UCHAR *v3; // rax
  int result; // eax
  BCRYPT_HANDLE *v5; // rdi

  v3 = (UCHAR *)SPExternalAlloc(*(_DWORD *)this);
  *((_QWORD *)this + 1) = v3;
  if ( !v3 )
    return -1073741670;
  result = GenerateRandomBits(v3, *(_DWORD *)this);
  if ( result >= 0 )
  {
    v5 = (BCRYPT_HANDLE *)((char *)this + 24);
    result = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)this + 3, L"SHA256", 0i64, 8u);
    if ( result >= 0 )
    {
      result = BCryptGetProperty(*v5, L"HashDigestLength", (PUCHAR)this + 32, 4u, (ULONG *)this + 9, 0);
      if ( result >= 0 )
      {
        result = BCryptGetProperty(*v5, L"ObjectLength", (PUCHAR)this + 40, 4u, (ULONG *)this + 9, 0);
        if ( result >= 0 )
        {
          *((_DWORD *)this + 4) = 1;
          return 0;
        }
      }
    }
  }
  return result;
}
