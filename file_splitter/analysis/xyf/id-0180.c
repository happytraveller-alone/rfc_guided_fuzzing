//----- (000000018000F484) ----------------------------------------------------
DWORD __fastcall GetCertEndpointBindings(const struct _CERT_CONTEXT *a1, unsigned __int8 **a2, unsigned int *a3)
{
  PCCRYPT_OID_INFO OIDInfo; // rax
  const wchar_t *v7; // rbx
  unsigned __int8 *pbComputedHash; // rdi
  DWORD v9; // eax
  DWORD LastError; // ebx
  DWORD pcbComputedHash; // [rsp+60h] [rbp+8h] BYREF

  pcbComputedHash = 0;
  OIDInfo = CryptFindOIDInfo(1u, a1->pCertInfo->SignatureAlgorithm.pszObjId, 0x40000004u);
  if ( !OIDInfo
    || OIDInfo->dwValue != -1
    || (v7 = *(const wchar_t **)&OIDInfo[1].cbSize) == 0i64
    || !wcscmp_0(*(const wchar_t **)&OIDInfo[1].cbSize, L"SHA1")
    || !wcscmp_0(v7, L"MD5") )
  {
    v7 = L"SHA256";
  }
  if ( !CryptHashCertificate2(v7, 0, 0i64, a1->pbCertEncoded, a1->cbCertEncoded, 0i64, &pcbComputedHash) )
    return GetLastError();
  pbComputedHash = (unsigned __int8 *)SPExternalAlloc(pcbComputedHash);
  if ( !pbComputedHash )
    return -2146893056;
  if ( CryptHashCertificate2(v7, 0, 0i64, a1->pbCertEncoded, a1->cbCertEncoded, pbComputedHash, &pcbComputedHash) )
  {
    v9 = pcbComputedHash;
    *a2 = pbComputedHash;
    *a3 = v9;
    return 0;
  }
  else
  {
    LastError = GetLastError();
    SPExternalFree(pbComputedHash);
    return LastError;
  }
}

