//----- (000000018004206C) ----------------------------------------------------
__int64 __fastcall LoadCredentialsFromLocalStore(
        unsigned int a1,
        const struct _CERT_CONTEXT **a2,
        int a3,
        void *a4,
        struct LSA_SCHANNEL_CRED *a5)
{
  unsigned int v5; // ebx
  HLOCAL v9; // rax
  struct LSA_SCHANNEL_CRED *v10; // rcx
  unsigned int v11; // r13d
  char *v12; // r14
  __int64 v13; // rsi
  char *v14; // r15
  __int64 v15; // r12
  unsigned __int16 *v16; // rax
  unsigned __int8 *v17; // r10
  int v18; // edx
  int v19; // edi
  __int64 v20; // rcx
  int v21; // edi
  const struct _CERT_CONTEXT *CertificateByHash; // rax
  unsigned __int16 *v23; // [rsp+30h] [rbp-48h]
  __int64 v24; // [rsp+38h] [rbp-40h]

  v5 = 0;
  if ( a1 > 0x4924924 )
    return 2148074333i64;
  v9 = SPExternalAlloc(56 * a1);
  v10 = a5;
  *((_QWORD *)a5 + 1) = v9;
  if ( !v9 )
  {
    v5 = 14;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x2Du,
        (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
        14,
        14);
    return v5;
  }
  v11 = 0;
  if ( !a1 )
    return v5;
  v12 = (char *)a2 + 4;
  v13 = 0i64;
  v14 = v12;
  while ( 1 )
  {
    v15 = *((_QWORD *)v10 + 1);
    v16 = 0i64;
    v17 = 0i64;
    v23 = 0i64;
    v18 = 0;
    v24 = 0i64;
    v19 = 0;
    if ( a3 == 2 )
    {
      v20 = *(_QWORD *)(v14 + 4);
      v17 = (unsigned __int8 *)(v14 + 12);
      v21 = *(_DWORD *)v14;
      v16 = (unsigned __int16 *)(v14 + 32);
    }
    else
    {
      if ( a3 != 1 )
        goto LABEL_14;
      v20 = *(_QWORD *)(v12 + 4);
      v17 = (unsigned __int8 *)(v12 + 12);
      v21 = *(_DWORD *)v12;
      v16 = L"MY";
    }
    v19 = v21 & 1;
    v24 = v20;
    v23 = v16;
    v18 = 20;
LABEL_14:
    CertificateByHash = SslGetCertificateByHash(v17, v18, v19, v16, a4);
    *(_QWORD *)(v13 + v15) = CertificateByHash;
    if ( !CertificateByHash )
      break;
    if ( v19 && !(unsigned int)_o__wcsicmp(v23, L"MY") )
      *(_DWORD *)(v13 + v15 + 48) |= 1u;
    ++v11;
    v10 = a5;
    v14 += 296;
    *(_QWORD *)(v13 + v15 + 16) = v24;
    v12 += 40;
    v13 += 56i64;
    if ( v11 >= a1 )
      return v5;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 46i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
  return (unsigned int)-2146893042;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080C40: using guessed type __int64 __fastcall _o__wcsicmp(_QWORD, _QWORD);
// 18008275C: using guessed type wchar_t aMy[3];

