//----- (000000018005D370) ----------------------------------------------------
DWORD __fastcall CSessionCacheItem::DeserializeRemoteChain(
        CSessionCacheItem *this,
        struct CSslContext *a2,
        unsigned __int8 *a3,
        unsigned int a4)
{
  size_t v5; // rdi
  const struct _CERT_CONTEXT *CertificateContext; // rax
  const CERT_CONTEXT *v9; // rbp
  DWORD PublicKeyFromCert; // esi
  HLOCAL v11; // rax
  struct _PUBLICKEY *v12; // [rsp+40h] [rbp+8h] BYREF

  v5 = a4;
  if ( !*((_QWORD *)this + 3) && !*((_DWORD *)this + 8) && !*((_QWORD *)this + 5) && !*((_QWORD *)this + 6) )
  {
    if ( a2 )
    {
      if ( !a4 )
      {
        if ( (*((_DWORD *)a2 + 34) & 0x100i64) != 0 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_3f0b3b553bfa392717596024a0f8b3a2_Traceguids);
          }
          return 87;
        }
        return 0;
      }
      if ( a3 && a4 > 4 && (unsigned __int64)a4 - 4 >= *(unsigned int *)a3 )
      {
        CertificateContext = CertCreateCertificateContext(1u, a3 + 4, *(_DWORD *)a3);
        v9 = CertificateContext;
        if ( !CertificateContext )
          return GetLastError();
        v12 = 0i64;
        PublicKeyFromCert = GetPublicKeyFromCert(CertificateContext, &v12, 0i64);
        if ( !PublicKeyFromCert )
        {
          v11 = SPExternalAlloc(v5);
          *((_QWORD *)this + 3) = v11;
          if ( v11 )
          {
            *((_QWORD *)this + 5) = v12;
            *((_QWORD *)this + 6) = v9;
            memcpy_0(v11, a3, v5);
            *((_DWORD *)this + 8) = v5;
            return 0;
          }
          SPExternalFree(v12);
          PublicKeyFromCert = 14;
        }
        CertFreeCertificateContext(v9);
        return PublicKeyFromCert;
      }
    }
    return 87;
  }
  return 1359;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

