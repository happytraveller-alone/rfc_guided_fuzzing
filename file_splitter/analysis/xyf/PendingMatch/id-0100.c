//----- (0000000180007EF4) ----------------------------------------------------
char __fastcall CTlsSignatureSuiteList::AddCertificateSignatureSuite(
        CTlsSignatureSuiteList *this,
        PCCERT_CONTEXT pCertContext)
{
  BOOL CertificateContextProperty; // eax
  DWORD v4; // edx
  unsigned __int64 v5; // rdx
  DWORD pcbData; // [rsp+20h] [rbp-A8h] BYREF
  unsigned __int16 *v8; // [rsp+28h] [rbp-A0h] BYREF
  __int16 pvData[64]; // [rsp+30h] [rbp-98h] BYREF

  pcbData = 128;
  v8 = (unsigned __int16 *)pvData;
  CertificateContextProperty = CertGetCertificateContextProperty(pCertContext, 0x59u, pvData, &pcbData);
  v4 = pcbData >> 1;
  if ( !CertificateContextProperty || v4 - 1 > 0x3F )
    return 0;
  v5 = v4 - 1;
  if ( v5 >= 64 )
    _report_rangecheckfailure(0i64);
  pvData[v5] = 0;
  return CTlsSignatureSuiteList::AddBCryptSignatureSuites(this, (const unsigned __int16 **const)&v8, 1u, 0);
}
// 1800281B8: using guessed type void __fastcall __noreturn _report_rangecheckfailure(_QWORD);

