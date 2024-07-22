//----- (000000018001588C) ----------------------------------------------------
__int64 __fastcall IsCertKeyUsageCompliant(int a1, int a2, const struct _CERT_CONTEXT *a3)
{
  unsigned int v3; // ebx
  int v4; // edi
  struct _CERT_INFO *pCertInfo; // rdx
  int pbKeyUsage; // [rsp+50h] [rbp+18h] BYREF

  v3 = 0;
  if ( !a3 )
    return 0i64;
  if ( a2 != 9216 )
    return 1i64;
  if ( a1 == 44550 )
    goto LABEL_4;
  if ( a1 != 41984 )
  {
    if ( a1 != 43522 )
      return 1i64;
LABEL_4:
    v4 = 128;
    goto LABEL_5;
  }
  v4 = 32;
LABEL_5:
  pCertInfo = a3->pCertInfo;
  pbKeyUsage = 0;
  if ( !CertGetIntendedKeyUsage(0x10001u, pCertInfo, (BYTE *)&pbKeyUsage, 4u) )
    return 1i64;
  LOBYTE(v3) = (pbKeyUsage & v4) != 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x14u,
      (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
      pbKeyUsage,
      v4);
  return v3;
}

