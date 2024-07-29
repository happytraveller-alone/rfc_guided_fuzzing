//----- (00000001800607B4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::DigestCertificateRequest(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        int a3)
{
  CSsl3TlsClientContext *v3; // rdi
  __int64 v4; // rbx
  unsigned __int8 *v5; // r14
  int v6; // esi
  unsigned __int8 v7; // r15
  unsigned __int8 v8; // bp
  unsigned __int16 v9; // dx
  int v10; // r8d
  __int64 v11; // rcx
  unsigned int v12; // eax
  unsigned __int8 *v13; // r14
  unsigned int v14; // esi
  unsigned int v15; // ebx
  unsigned __int8 v16; // r9
  int v17; // edx
  unsigned int v19; // [rsp+30h] [rbp-78h] BYREF
  __int16 v20; // [rsp+38h] [rbp-70h] BYREF
  __int128 v21; // [rsp+3Ah] [rbp-6Eh]
  __int128 v22; // [rsp+4Ah] [rbp-5Eh]
  __int16 v23; // [rsp+5Ah] [rbp-4Eh]

  v3 = this;
  if ( !a3 || (v4 = *a2, v5 = a2 + 1, v6 = a3 - 1, (unsigned int)v4 > a3 - 1) )
  {
    v16 = 50;
    v15 = -2146893018;
    v17 = 400;
    goto LABEL_27;
  }
  *((_WORD *)this + 673) = 0;
  v7 = 0;
  if ( !(_BYTE)v4 )
    goto LABEL_23;
  do
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = *((_WORD *)v3 + 673);
      if ( v9 >= 4u )
        break;
      v10 = g_Ssl3CertTypes[v8];
      if ( v10 == v5[v7] )
      {
        v11 = *((_QWORD *)v3 + 10);
        v12 = *(_DWORD *)(v11 + 196);
        if ( !v12 )
          goto LABEL_10;
        if ( !IsSignatureTypeBlacklisted(*(_QWORD *)(v11 + 200), v12, v10, 0i64) )
        {
          v9 = *((_WORD *)v3 + 673);
          v10 = g_Ssl3CertTypes[v8];
LABEL_10:
          *((_DWORD *)v3 + v9 + 337) = v10;
          ++*((_WORD *)v3 + 673);
        }
      }
      if ( ++v8 >= 3u )
      {
        v9 = *((_WORD *)v3 + 673);
        break;
      }
    }
    ++v7;
  }
  while ( v7 < (unsigned __int8)v4 );
  if ( !v9 )
  {
LABEL_23:
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 41i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    goto LABEL_19;
  }
  v13 = &v5[v4];
  v14 = v6 - v4;
  if ( (*((_DWORD *)v3 + 16) & 0x80800) == 0 )
    return CSsl3TlsClientContext::ParseDistinguishedNameList(v3, v13, v14);
  v20 = 0;
  v23 = 0;
  v19 = 0;
  v21 = 0i64;
  v22 = 0i64;
  v15 = CTlsSignatureSuiteList::ParseSupportedSignatureAlgorithmsAndSet((CTlsSignatureSuiteList *)&v20, v13, v14, &v19);
  if ( v15 )
  {
    v16 = 47;
    goto LABEL_20;
  }
  CTlsSignatureSuiteList::SetSignatureSuiteList(
    (CSsl3TlsClientContext *)((char *)v3 + 510),
    (CSsl3TlsClientContext *)((char *)v3 + 474));
  if ( CTlsSignatureSuiteList::Restrict(
         (CSsl3TlsClientContext *)((char *)v3 + 510),
         (const struct CTlsSignatureSuiteList *)&v20,
         *((_DWORD *)v3 + 16)) )
  {
    v13 += v19;
    v14 -= v19;
    return CSsl3TlsClientContext::ParseDistinguishedNameList(v3, v13, v14);
  }
LABEL_19:
  v16 = 40;
  v15 = -2146893007;
LABEL_20:
  v17 = 402;
  this = v3;
LABEL_27:
  CSslContext::SetErrorAndFatalAlert((__int64)this, v17, v15, v16);
  return v15;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800858E8: using guessed type _DWORD g_Ssl3CertTypes[4];

