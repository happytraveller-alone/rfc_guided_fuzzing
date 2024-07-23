// File count: 184
// Total lines: 62
-----------------------------------------
DWORD __fastcall SpQueryRemoteCertContext(struct CSslUserContext *a1, const CERT_CONTEXT **a2)
{
  unsigned __int8 *v4; // rcx
  DWORD result; // eax
  const CERT_CONTEXT *v6; // rdi
  __int64 v7; // rax
  DWORD LastError; // eax
  DWORD v9; // eax
  int pvData; // [rsp+20h] [rbp-18h] BYREF
  __int64 v11; // [rsp+28h] [rbp-10h]
  PCCERT_CONTEXT pCertContext; // [rsp+40h] [rbp+8h] BYREF

  pCertContext = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
  v4 = (unsigned __int8 *)*((_QWORD *)a1 + 19);
  if ( !v4 )
    return -2146893042;
  result = SPLoadCertificate(v4, *((_DWORD *)a1 + 40), &pCertContext);
  if ( !result )
  {
    v6 = pCertContext;
    if ( *((_QWORD *)a1 + 25) )
    {
      v11 = *((_QWORD *)a1 + 25);
      pvData = *((_DWORD *)a1 + 52);
      if ( !CertSetCertificateContextProperty(pCertContext, 0x46u, 0, &pvData)
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      {
        LastError = GetLastError();
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          13i64,
          &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids,
          LastError);
      }
    }
    v7 = *((_QWORD *)a1 + 27);
    if ( v7 )
    {
      if ( *((_DWORD *)a1 + 56) )
      {
        pvData = *((_DWORD *)a1 + 56);
        v11 = v7;
        if ( !CertSetCertificateContextProperty(v6, 0x77u, 0, &pvData)
          && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        {
          v9 = GetLastError();
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids, v9);
        }
      }
    }
    *a2 = v6;
    return 0;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
