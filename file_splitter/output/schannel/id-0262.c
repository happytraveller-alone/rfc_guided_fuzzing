// File count: 262
// Total lines: 11
-----------------------------------------
DWORD __fastcall RsaPublicKeyFromCert(
        struct _CERT_PUBLIC_KEY_INFO *a1,
        struct _PUBLICKEYSTRUC *pvStructInfo,
        unsigned int *pcbStructInfo)
{
  if ( CryptDecodeObject(1u, (LPCSTR)0x13, a1->PublicKey.pbData, a1->PublicKey.cbData, 0, pvStructInfo, pcbStructInfo) )
    return 0;
  else
    return GetLastError();
}
