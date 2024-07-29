//----- (00000001800461E4) ----------------------------------------------------
__int64 __fastcall CSslContext::QueryAuthority(CSslContext *this, void *a2)
{
  WCHAR *v2; // r15
  signed int v5; // ebx
  int v6; // esi
  __int64 v7; // rcx
  unsigned __int8 *v8; // rax
  PCCERT_CONTEXT v9; // r14
  PCERT_INFO pCertInfo; // rax
  DWORD v11; // eax
  DWORD csz; // ebx
  ULONG LastError; // eax
  unsigned int v14; // r12d
  WCHAR *v15; // rax
  NTSTATUS v16; // eax
  PCCERT_CONTEXT pCertContext; // [rsp+30h] [rbp-20h] BYREF
  __int128 v19; // [rsp+38h] [rbp-18h] BYREF
  __int64 v20; // [rsp+48h] [rbp-8h]
  __int64 v21; // [rsp+A0h] [rbp+50h] BYREF
  __int64 v22; // [rsp+A8h] [rbp+58h] BYREF

  pCertContext = 0i64;
  v2 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v19 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(__int128 *))(LsaTable + 192))(&v19) )
    return 1359;
  v6 = BYTE8(v19) & 0x40;
  if ( !a2 )
    return 87;
  RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
  v7 = *((_QWORD *)this + 11);
  v8 = *(unsigned __int8 **)(v7 + 24);
  if ( !v8 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(v7 + 72));
    return 120;
  }
  v5 = SPLoadCertificate(v8, *(_DWORD *)(v7 + 32), &pCertContext);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
  v9 = pCertContext;
  if ( !v5 )
  {
    pCertInfo = pCertContext->pCertInfo;
    if ( !pCertInfo->Issuer.cbData || !pCertInfo->Issuer.pbData )
    {
      v5 = 120;
      goto LABEL_25;
    }
    v11 = CertNameToStrW(pCertContext->dwCertEncodingType, &pCertInfo->Issuer, 0x20000003u, 0i64, 0);
    csz = v11;
    if ( !v11 )
      goto LABEL_11;
    v14 = 2 * v11;
    v15 = (WCHAR *)SPExternalAlloc(2 * v11);
    v2 = v15;
    if ( !v15 )
    {
      v5 = 14;
      goto LABEL_25;
    }
    if ( CertNameToStrW(v9->dwCertEncodingType, &v9->pCertInfo->Issuer, 0x20000003u, v15, csz) )
    {
      v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(0i64, v14, &v21);
      if ( v16 >= 0 )
      {
        v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, WCHAR *))(LsaTable + 72))(0i64, v14, v21, v2);
        if ( v16 >= 0 )
        {
          if ( v6 )
            LODWORD(v22) = v21;
          else
            v22 = v21;
          v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, void *, __int64 *))(LsaTable + 72))(
                  0i64,
                  v6 != 0 ? 4 : 8,
                  a2,
                  &v22);
          v5 = v16;
          if ( v16 >= 0 )
            goto LABEL_25;
        }
      }
      LastError = RtlNtStatusToDosError(v16);
    }
    else
    {
LABEL_11:
      LastError = GetLastError();
    }
    v5 = LastError;
  }
LABEL_25:
  if ( v9 )
    CertFreeCertificateContext(v9);
  if ( v2 )
    SPExternalFree(v2);
  if ( v5 < 0 && v21 )
    (*(void (__fastcall **)(_QWORD))(LsaTable + 64))(0i64);
  return (unsigned int)v5;
}
// 180092620: using guessed type __int64 LsaTable;

