// File count: 986
// Total lines: 62
-----------------------------------------
DWORD __fastcall SpQueryRemoteCred(struct CSslUserContext *a1, _OWORD *a2)
{
  unsigned __int8 *v4; // rcx
  DWORD result; // eax
  PCCERT_CONTEXT v6; // rbx
  HLOCAL v7; // rax
  HLOCAL v8; // rsi
  DWORD cbCertEncoded; // eax
  struct _PUBLICKEY *v10; // rcx
  PCCERT_CONTEXT pCertContext; // [rsp+30h] [rbp+8h] BYREF
  struct _PUBLICKEY *v12; // [rsp+38h] [rbp+10h] BYREF

  pCertContext = 0i64;
  v12 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
  *a2 = 0i64;
  a2[1] = 0i64;
  v4 = (unsigned __int8 *)*((_QWORD *)a1 + 19);
  if ( v4 )
  {
    result = SPLoadCertificate(v4, *((_DWORD *)a1 + 40), &pCertContext);
    if ( result )
      return result;
    v6 = pCertContext;
    if ( pCertContext )
    {
      v7 = LocalAlloc(0x40u, pCertContext->cbCertEncoded);
      v8 = v7;
      if ( !v7 )
      {
        CertFreeCertificateContext(v6);
        return -2146893056;
      }
      memcpy_0(v7, v6->pbCertEncoded, v6->cbCertEncoded);
      *((_DWORD *)a2 + 5) |= 1u;
      *((_QWORD *)a2 + 1) = v8;
      cbCertEncoded = v6->cbCertEncoded;
      *((_DWORD *)a2 + 6) = 0;
      *(_DWORD *)a2 = cbCertEncoded;
      *((_DWORD *)a2 + 4) = 1;
      if ( !GetPublicKeyFromCert(v6, &v12, 0i64) )
      {
        v10 = v12;
        if ( v12 )
        {
          if ( *(_QWORD *)v12 != -8i64 )
            *((_DWORD *)a2 + 6) = *(_DWORD *)(*(_QWORD *)v12 + 12i64);
          SPExternalFree(v10);
        }
        else
        {
          *((_DWORD *)a2 + 6) = CertGetPublicKeyLength(1u, &v6->pCertInfo->SubjectPublicKeyInfo);
        }
      }
      CertFreeCertificateContext(v6);
    }
  }
  return 0;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
