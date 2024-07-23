// File count: 1046
// Total lines: 25
----------------------------------------
_BOOL8 __fastcall DoesCertHaveBasicConstraintCA(const struct _CERT_CONTEXT *a1)
{
  PCERT_EXTENSION Extension; // rax
  DWORD cbData; // r9d
  const BYTE *pbData; // r8
  _BOOL8 result; // rax
  DWORD pcbStructInfo; // [rsp+40h] [rbp-28h] BYREF
  __int64 pvStructInfo; // [rsp+48h] [rbp-20h] BYREF
  int v7; // [rsp+50h] [rbp-18h]

  Extension = CertFindExtension("2.5.29.19", a1->pCertInfo->cExtension, a1->pCertInfo->rgExtension);
  result = 0;
  if ( Extension )
  {
    cbData = Extension->Value.cbData;
    pbData = Extension->Value.pbData;
    pvStructInfo = 0i64;
    v7 = 0;
    pcbStructInfo = 12;
    if ( CryptDecodeObject(1u, (LPCSTR)0xF, pbData, cbData, 0, &pvStructInfo, &pcbStructInfo) )
      return 1;
  }
  return result;
}
