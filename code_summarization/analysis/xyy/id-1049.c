//----- (0000000180058598) ----------------------------------------------------
void __fastcall GetImplementationType(PCCERT_CONTEXT pCertContext, unsigned int *a2)
{
  HLOCAL v4; // rax
  HLOCAL v5; // rbx
  DWORD pcbData; // [rsp+58h] [rbp+10h] BYREF
  unsigned int pbData; // [rsp+60h] [rbp+18h] BYREF
  HCRYPTPROV phProv; // [rsp+68h] [rbp+20h] BYREF

  phProv = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
  *a2 = 4;
  if ( CertGetCertificateContextProperty(pCertContext, 2u, 0i64, &pcbData) )
  {
    v4 = SPExternalAlloc(pcbData);
    v5 = v4;
    if ( v4 )
    {
      if ( CertGetCertificateContextProperty(pCertContext, 2u, v4, &pcbData) )
      {
        *((_DWORD *)v5 + 5) &= ~1u;
        if ( CryptAcquireContextW(
               &phProv,
               *(LPCWSTR *)v5,
               *((LPCWSTR *)v5 + 1),
               *((_DWORD *)v5 + 4),
               *((_DWORD *)v5 + 5) | 0x40) )
        {
          pcbData = 4;
          if ( CryptGetProvParam(phProv, 3u, (BYTE *)&pbData, &pcbData, 0) )
            *a2 = pbData;
        }
      }
      SPExternalFree(v5);
    }
  }
  if ( phProv )
    CryptReleaseContext(phProv, 0);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 41i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

