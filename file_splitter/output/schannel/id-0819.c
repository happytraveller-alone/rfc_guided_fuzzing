//----- (0000000180043554) ----------------------------------------------------
__int64 __fastcall InitializeClientCertPolicy(struct _SecPkgCred_ClientCertPolicy *a1, struct CLIENT_CERT_POLICY *a2)
{
  BOOL fOmitUsageCheck; // eax
  const unsigned __int16 *pwszSslCtlIdentifier; // rdx
  LPWSTR pwszSslCtlStoreName; // rax
  PCCTL_CONTEXT CtlInStore; // rax
  HCERTSTORE v9; // rax
  void *pvPara; // [rsp+20h] [rbp-18h]

  *((_DWORD *)a2 + 4) = a1->dwCertFlags;
  *((_DWORD *)a2 + 5) = a1->dwUrlRetrievalTimeout;
  *((_DWORD *)a2 + 6) = a1->fCheckRevocationFreshnessTime;
  *((_DWORD *)a2 + 7) = a1->dwRevocationFreshnessTime;
  *(GUID *)a2 = a1->guidPolicyId;
  fOmitUsageCheck = a1->fOmitUsageCheck;
  *((_QWORD *)a2 + 5) = 0i64;
  *((_DWORD *)a2 + 8) = fOmitUsageCheck;
  pwszSslCtlIdentifier = a1->pwszSslCtlIdentifier;
  pwszSslCtlStoreName = a1->pwszSslCtlStoreName;
  if ( pwszSslCtlIdentifier )
  {
    if ( pwszSslCtlStoreName )
    {
      CtlInStore = FindCtlInStore(a1->pwszSslCtlStoreName, pwszSslCtlIdentifier);
      *((_QWORD *)a2 + 5) = CtlInStore;
      if ( CtlInStore )
        return 0i64;
    }
  }
  else
  {
    if ( !pwszSslCtlStoreName )
      return 0i64;
    v9 = CertOpenStore((LPCSTR)0xA, 0, 0i64, 0x24000u, a1->pwszSslCtlStoreName);
    *((_QWORD *)a2 + 6) = v9;
    if ( v9 )
      return 0i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      LODWORD(pvPara) = GetLastError();
      WPP_SF_SD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xCu,
        (__int64)&WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids,
        a1->pwszSslCtlStoreName,
        pvPara);
    }
  }
  return 2148074253i64;
}
// 180043639: variable 'pvPara' is possibly undefined

