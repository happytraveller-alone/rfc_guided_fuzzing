// File count: 1006
// Total lines: 21
----------------------------------------
__int64 __fastcall GetPublicKeyAlgIdFromCert(const struct _CERT_CONTEXT *a1, unsigned int *a2)
{
  PCERT_INFO pCertInfo; // rax
  char **p_pszObjId; // rax
  unsigned int v5; // eax

  if ( !a1 || !a2 )
    return 2148074333i64;
  pCertInfo = a1->pCertInfo;
  if ( !pCertInfo )
    return 2148074244i64;
  p_pszObjId = &pCertInfo->SubjectPublicKeyInfo.Algorithm.pszObjId;
  if ( !p_pszObjId || !*p_pszObjId )
    return 2148074244i64;
  v5 = MapOidToKeyExch(*p_pszObjId);
  if ( !v5 )
    return 2148074253i64;
  *a2 = v5;
  return 0i64;
}
