//----- (000000018005425C) ----------------------------------------------------
_BOOL8 __fastcall IsCertSelfSigned(const struct _CERT_CONTEXT *a1)
{
  PCERT_INFO pCertInfo; // rcx
  DWORD cbData; // eax

  pCertInfo = a1->pCertInfo;
  cbData = pCertInfo->Issuer.cbData;
  return pCertInfo->Subject.cbData == cbData && !memcmp_0(pCertInfo->Subject.pbData, pCertInfo->Issuer.pbData, cbData);
}

