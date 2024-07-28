//----- (0000000180055730) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::ConstructIssuersList(CCredentialGroup *this)
{
  unsigned int TrustedRoots; // ebx
  unsigned int v2; // r15d
  unsigned __int8 *v4; // rdi
  void *v5; // rcx
  void *v6; // rcx
  unsigned __int8 *v7; // rax
  void *v8; // rcx
  void *v9; // rcx
  const CERT_CONTEXT *v10; // rax
  void *v11; // r14
  unsigned int v12; // ebx
  unsigned __int8 *v13; // rax
  CCredentialGroup *v14; // rcx
  __int64 v15; // rbx
  bool v16; // zf
  unsigned __int8 *v17; // rax
  unsigned int v18; // ebx
  int v19; // edx
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-10h] BYREF
  SIZE_T uBytes; // [rsp+70h] [rbp+40h] BYREF
  SIZE_T Size; // [rsp+78h] [rbp+48h] BYREF
  void *v27; // [rsp+80h] [rbp+50h] BYREF
  void *Src; // [rsp+88h] [rbp+58h] BYREF

  TrustedRoots = 0;
  v2 = 0;
  Src = 0i64;
  LODWORD(Size) = 0;
  v4 = 0i64;
  v27 = 0i64;
  v5 = (void *)*((_QWORD *)this + 108);
  LODWORD(uBytes) = 0;
  if ( v5 )
  {
    if ( (*((_BYTE *)this + 156) & 0x10) == 0 )
      return TrustedRoots;
    LocalFree(v5);
    *((_QWORD *)this + 108) = 0i64;
    *((_DWORD *)this + 214) = 0;
  }
  *((_DWORD *)this + 39) &= ~0x10u;
  v6 = (void *)*((_QWORD *)this + 96);
  if ( v6 )
  {
    if ( (unsigned int)ExtractIssuerNamesFromStore(v6, 0i64, (unsigned int *)&uBytes, 0i64) )
      goto LABEL_10;
    v7 = (unsigned __int8 *)LocalAlloc(0x40u, (unsigned int)uBytes);
    v4 = v7;
    if ( !v7 )
      return 14;
    if ( !(unsigned int)ExtractIssuerNamesFromStore(*((void **)this + 96), v7, (unsigned int *)&uBytes, 0i64) )
    {
LABEL_10:
      v2 = uBytes;
    }
    else
    {
      LocalFree(v4);
      v4 = 0i64;
    }
  }
  v8 = (void *)*((_QWORD *)this + 102);
  if ( v8 )
  {
LABEL_15:
    v27 = CertDuplicateStore(v8);
    v11 = v27;
    if ( v27 )
      goto LABEL_22;
    goto LABEL_16;
  }
  v9 = (void *)*((_QWORD *)this + 104);
  if ( v9 )
  {
    v10 = CertEnumCertificatesInStore(v9, 0i64);
    if ( v10 )
    {
      CertFreeCertificateContext(v10);
      v8 = (void *)*((_QWORD *)this + 104);
      goto LABEL_15;
    }
  }
LABEL_16:
  TrustedRoots = SchGetTrustedRoots(&v27, *((_QWORD *)this + 94));
  if ( TrustedRoots )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        35i64,
        &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids,
        TrustedRoots);
    v11 = v27;
    goto LABEL_38;
  }
  v11 = v27;
LABEL_22:
  TrustedRoots = ConstructIssuersListFromStore(v11, (unsigned __int8 **)&Src, (unsigned int *)&Size);
  if ( !TrustedRoots )
  {
    if ( v4 )
    {
      v12 = Size;
      if ( (unsigned int)Size + v2 < v2 )
      {
LABEL_30:
        TrustedRoots = 534;
LABEL_42:
        LocalFree(v4);
        goto LABEL_52;
      }
      v13 = (unsigned __int8 *)LocalReAlloc(v4, (unsigned int)Size + v2, 2u);
      if ( !v13 )
      {
        TrustedRoots = 14;
        goto LABEL_42;
      }
      v4 = v13;
    }
    else
    {
      v12 = Size;
      v4 = (unsigned __int8 *)LocalAlloc(0x40u, (unsigned int)Size);
      if ( !v4 )
      {
        TrustedRoots = 14;
        goto LABEL_52;
      }
    }
    memcpy_0(&v4[v2], Src, v12);
    v15 = v2 + v12;
    v16 = (*((_BYTE *)this + 156) & 1) == 0;
    LODWORD(uBytes) = v15;
    if ( !v16 )
      goto LABEL_41;
    if ( (int)v15 + 27 >= (unsigned int)v15 )
    {
      v17 = (unsigned __int8 *)LocalReAlloc(v4, (unsigned int)(v15 + 27), 2u);
      if ( !v17 )
      {
        TrustedRoots = 14;
        goto LABEL_38;
      }
      v4 = v17;
      LODWORD(uBytes) = v15 + 27;
      *(_OWORD *)&v17[v15] = *(_OWORD *)&SslNtAuthorityName;
      qmemcpy(&v17[v15 + 16], "T AUTHORITY", 11);
LABEL_41:
      TrustedRoots = CCredentialGroup::RemoveDuplicateIssuers(v14, v4, (unsigned int *)&uBytes);
      if ( !TrustedRoots )
      {
        v18 = uBytes;
        *((_DWORD *)this + 214) = uBytes;
        *((_QWORD *)this + 108) = v4;
        if ( v18 > 0x3FD0 )
        {
          v19 = 0;
          while ( 1 )
          {
            v20 = v4[1] | (*v4 << 8);
            v21 = v20 + v19 + 2;
            if ( v21 > 0x3FD0 )
              break;
            v19 += v20 + 2;
            v4 += (unsigned int)(v20 + 2);
            if ( v21 >= v18 )
              goto LABEL_49;
          }
          *((_DWORD *)this + 214) = v19;
LABEL_49:
          v22 = *((_DWORD *)this + 53);
          if ( (g_dwEventLogging & 1) != 0 )
          {
            RtlInitUnicodeString(&DestinationString, (PCWSTR)this + 108);
            SchEventWrite(&SSLEVENT_ISSUER_LIST_OVERFLOW_FAILURE, L"du", v22, &DestinationString);
          }
        }
        TrustedRoots = 0;
        goto LABEL_52;
      }
      goto LABEL_42;
    }
    goto LABEL_30;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, TrustedRoots);
LABEL_38:
  if ( v4 )
    goto LABEL_42;
LABEL_52:
  if ( v11 )
    CertCloseStore(v11, 0);
  if ( Src )
    SPExternalFree(Src);
  return TrustedRoots;
}
// 180055A6E: conditional instruction was optimized away because ebx.4>=3FD1u
// 18005599E: conditional instruction was optimized away because rdi.8!=0
// 180055A22: conditional instruction was optimized away because rdi.8!=0
// 180055A5D: conditional instruction was optimized away because rdi.8!=0
// 180055A2B: variable 'v14' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
// 180091A00: using guessed type unsigned __int8 near *SslNtAuthorityName;
