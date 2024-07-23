// File count: 895
// Total lines: 174
----------------------------------------
__int64 __fastcall SslTryS4U2Self(
        const struct _CERT_CHAIN_CONTEXT *a1,
        void **a2,
        int a3,
        const unsigned __int16 *a4,
        const unsigned __int16 *Src)
{
  bool v7; // zf
  _DWORD *AuthenticationInformation; // rdi
  unsigned __int16 v9; // si
  unsigned __int16 v10; // r15
  __int64 result; // rax
  PCCERT_CONTEXT pCertContext; // r14
  NTSTATUS v13; // ebx
  ULONG AuthenticationInformationLength; // r14d
  __int64 v15; // rcx
  __int64 v16; // rsi
  _DWORD *v17; // rax
  char *v18; // rbx
  __int64 v19; // rdx
  PHANDLE v20; // rsi
  HLOCAL hMem; // [rsp+70h] [rbp-51h] BYREF
  int v22; // [rsp+78h] [rbp-49h] BYREF
  int SubStatus; // [rsp+7Ch] [rbp-45h] BYREF
  PVOID Buffer; // [rsp+80h] [rbp-41h] BYREF
  ULONG ProfileBufferLength; // [rsp+88h] [rbp-39h] BYREF
  PCCERT_CONTEXT v26; // [rsp+90h] [rbp-31h]
  PHANDLE Token; // [rsp+98h] [rbp-29h]
  struct _LUID LogonId; // [rsp+A0h] [rbp-21h] BYREF
  struct _QUOTA_LIMITS Quotas; // [rsp+A8h] [rbp-19h] BYREF

  Token = a2;
  v7 = g_SslS4U2SelfInitialized == 0;
  AuthenticationInformation = 0i64;
  *a2 = 0i64;
  v9 = 0;
  hMem = 0i64;
  v10 = 0;
  Buffer = 0i64;
  LogonId = 0i64;
  if ( v7 )
    return 3221225659i64;
  pCertContext = (*(*a1->rgpChain)->rgpElement)->pCertContext;
  v26 = pCertContext;
  result = SslGetNameFromCertificate(pCertContext, (unsigned __int16 **)&hMem, &v22);
  if ( (int)result >= 0 )
  {
    if ( v22 )
    {
      v13 = -1073741275;
LABEL_35:
      if ( Buffer )
        LsaFreeReturnBuffer(Buffer);
      if ( AuthenticationInformation )
        LocalFree(AuthenticationInformation);
      if ( hMem )
        LocalFree(hMem);
      return (unsigned int)v13;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      WPP_SF_S(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xAu,
        (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
        (const wchar_t *)hMem);
    AuthenticationInformationLength = pCertContext->cbCertEncoded + 56;
    if ( AuthenticationInformationLength >= 0x38 )
    {
      v15 = -1i64;
      if ( a4 )
      {
        v16 = -1i64;
        do
          ++v16;
        while ( a4[v16] );
        v9 = 2 * (v16 + 1);
        if ( AuthenticationInformationLength + v9 < AuthenticationInformationLength )
          goto LABEL_34;
        AuthenticationInformationLength += v9;
      }
      if ( !Src )
        goto LABEL_19;
      do
        ++v15;
      while ( Src[v15] );
      v10 = 2 * (v15 + 1);
      if ( AuthenticationInformationLength + v10 >= AuthenticationInformationLength )
      {
        AuthenticationInformationLength += v10;
LABEL_19:
        v17 = LocalAlloc(0x40u, AuthenticationInformationLength);
        AuthenticationInformation = v17;
        if ( v17 )
        {
          *v17 = 14;
          v17[1] = a3 | 2;
          v18 = (char *)(v17 + 14);
          if ( a4 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
            {
              WPP_SF_S(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xBu,
                (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                a4);
            }
            *((_WORD *)AuthenticationInformation + 4) = v9 - 2;
            *((_QWORD *)AuthenticationInformation + 2) = v18;
            *((_WORD *)AuthenticationInformation + 5) = v9;
            memcpy_0(v18, a4, v9);
            v18 += *((unsigned __int16 *)AuthenticationInformation + 5);
          }
          if ( Src )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
            {
              WPP_SF_S(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xCu,
                (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                Src);
            }
            *((_WORD *)AuthenticationInformation + 12) = v10 - 2;
            *((_QWORD *)AuthenticationInformation + 4) = v18;
            *((_WORD *)AuthenticationInformation + 13) = v10;
            memcpy_0(v18, Src, v10);
            v18 += *((unsigned __int16 *)AuthenticationInformation + 13);
          }
          v19 = (__int64)v26;
          AuthenticationInformation[10] = v26->cbCertEncoded;
          *((_QWORD *)AuthenticationInformation + 6) = v18;
          memcpy_0(v18, *(const void **)(v19 + 8), *(unsigned int *)(v19 + 16));
          v20 = Token;
          v13 = LsaLogonUser(
                  SslLogonHandle,
                  (PLSA_STRING)&SslPackageNameA,
                  Network,
                  SslKerberosPackageId,
                  AuthenticationInformation,
                  AuthenticationInformationLength,
                  SslPackageSid,
                  &SslTokenSource,
                  &Buffer,
                  &ProfileBufferLength,
                  &LogonId,
                  Token,
                  &Quotas,
                  &SubStatus);
          if ( v13 >= 0 )
          {
            v13 = SubStatus;
            if ( SubStatus >= 0 )
              v13 = LsaISetTokenDacl(*v20);
          }
        }
        else
        {
          v13 = -1073741801;
        }
        goto LABEL_35;
      }
    }
LABEL_34:
    v13 = -1073741675;
    goto LABEL_35;
  }
  return result;
}
// 180092784: using guessed type int g_SslS4U2SelfInitialized;
// 180098248: using guessed type __int64 __fastcall LsaISetTokenDacl(_QWORD);
