//----- (000000018005F9A0) ----------------------------------------------------
__int64 __fastcall CSslCredential::GetPrivateFromCert(
        CSslCredential *this,
        __int64 a2,
        struct LSA_SCHANNEL_SUB_CRED *a3)
{
  struct _CRYPT_KEY_PROV_INFO *p_pcbData; // rbx
  unsigned int v4; // esi
  __int64 v8; // rax
  DWORD v9; // edx
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  void *v12; // rsp
  _DWORD *v13; // rax
  CCipherMill *v14; // rcx
  CCipherMill *v15; // rcx
  DWORD LastError; // eax
  ULONG LocalServerKeyFromProvider; // eax
  char v18; // r8
  const unsigned __int16 *v19; // rdx
  unsigned int v20; // ecx
  __int64 v22; // [rsp+0h] [rbp-30h] BYREF
  DWORD pcbData; // [rsp+30h] [rbp+0h] BYREF
  DWORD v24; // [rsp+34h] [rbp+4h] BYREF
  __int64 v25[3]; // [rsp+38h] [rbp+8h] BYREF

  p_pcbData = 0i64;
  v24 = 0;
  v4 = 0;
  pcbData = 0;
  if ( !*((_BYTE *)this + 79) && *((_QWORD *)a3 + 2) )
  {
    v8 = *((_QWORD *)a3 + 2);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Cu, (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
      v8 = *((_QWORD *)a3 + 2);
    }
    *((_QWORD *)this + 14) = v8;
    *((_BYTE *)this + 120) = 1;
  }
  if ( CertGetCertificateContextProperty(*((PCCERT_CONTEXT *)this + 4), 2u, 0i64, &pcbData) )
  {
    v9 = pcbData;
    if ( pcbData )
    {
      if ( pcbData <= (unsigned __int64)g_ulMaxStackAllocSize )
      {
        v10 = pcbData + g_ulAdditionalProbeSize + 8;
        if ( v10 >= pcbData )
        {
          if ( (unsigned int)VerifyStackAvailable(v10) )
          {
            v9 = pcbData;
            v11 = pcbData + 8 + 15i64;
            if ( v11 <= pcbData + 8 )
              v11 = 0xFFFFFFFFFFFFFF0i64;
            v12 = alloca(v11 & 0xFFFFFFFFFFFFFFF0ui64);
            p_pcbData = (struct _CRYPT_KEY_PROV_INFO *)&pcbData;
            if ( &v22 == (__int64 *)-48i64 )
              goto LABEL_17;
            pcbData = 1801679955;
            p_pcbData = (struct _CRYPT_KEY_PROV_INFO *)v25;
            if ( v25 )
            {
LABEL_22:
              if ( CertGetCertificateContextProperty(*((PCCERT_CONTEXT *)this + 4), 2u, p_pcbData, &pcbData) )
              {
                *((_DWORD *)this + 31) = p_pcbData->dwProvType;
                *((_DWORD *)this + 32) = p_pcbData->dwKeySpec;
                v14 = WPP_GLOBAL_Control;
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
                {
                  if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                  {
                    WPP_SF_S(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      0x1Du,
                      (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
                      p_pcbData->pwszContainerName);
                    v14 = WPP_GLOBAL_Control;
                  }
                  if ( v14 != (CCipherMill *)&WPP_GLOBAL_Control )
                  {
                    if ( (*((_BYTE *)v14 + 28) & 4) != 0 )
                    {
                      WPP_SF_S(
                        *((_QWORD *)v14 + 2),
                        0x1Eu,
                        (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
                        p_pcbData->pwszProvName);
                      v14 = WPP_GLOBAL_Control;
                    }
                    if ( v14 != (CCipherMill *)&WPP_GLOBAL_Control )
                    {
                      if ( (*((_BYTE *)v14 + 28) & 4) != 0 )
                      {
                        WPP_SF_D(
                          *((_QWORD *)v14 + 2),
                          31i64,
                          &WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
                          p_pcbData->dwProvType);
                        v14 = WPP_GLOBAL_Control;
                      }
                      if ( v14 != (CCipherMill *)&WPP_GLOBAL_Control )
                      {
                        if ( (*((_BYTE *)v14 + 28) & 4) != 0 )
                        {
                          WPP_SF_D(
                            *((_QWORD *)v14 + 2),
                            32i64,
                            &WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
                            p_pcbData->dwFlags);
                          v14 = WPP_GLOBAL_Control;
                        }
                        if ( v14 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v14 + 28) & 4) != 0 )
                          WPP_SF_d(
                            *((_QWORD *)v14 + 2),
                            0x21u,
                            (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
                            p_pcbData->dwKeySpec);
                      }
                    }
                  }
                }
                LogCredPropertiesEvent(*((_BYTE *)this + 79), p_pcbData, *((const struct _CERT_CONTEXT **)this + 4));
              }
              else
              {
                if ( p_pcbData[-1].dwKeySpec == 1885431112 )
                  ((void (*)(void))g_pfnFree)();
                p_pcbData = 0i64;
              }
              goto LABEL_46;
            }
          }
          v9 = pcbData;
        }
      }
    }
LABEL_17:
    if ( v9 + 8 >= v9 )
    {
      v13 = (_DWORD *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)(v9 + 8);
      p_pcbData = (struct _CRYPT_KEY_PROV_INFO *)v13;
      if ( !v13 )
      {
LABEL_21:
        v4 = 14;
LABEL_77:
        v18 = *((_BYTE *)this + 79);
        v19 = (const unsigned __int16 *)((char *)this + 656);
        v20 = *((_DWORD *)this + 163);
        if ( !p_pcbData )
        {
          LogNoPrivateKeyEvent(v20, v19, v18);
          return v4;
        }
        LogCreateCredFailedEvent(v20, v19, v18, *((_DWORD *)this + 18));
        goto LABEL_80;
      }
      *v13 = 1885431112;
      p_pcbData = (struct _CRYPT_KEY_PROV_INFO *)(v13 + 2);
    }
    if ( !p_pcbData )
      goto LABEL_21;
    goto LABEL_22;
  }
  if ( CertGetCertificateContextProperty(*((PCCERT_CONTEXT *)this + 4), 5u, 0i64, &v24) )
  {
LABEL_46:
    v15 = WPP_GLOBAL_Control;
    goto LABEL_47;
  }
  v15 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
  {
    LastError = GetLastError();
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, LastError);
    goto LABEL_46;
  }
LABEL_47:
  if ( *((_BYTE *)this + 120) )
  {
    if ( !p_pcbData )
      return v4;
    goto LABEL_80;
  }
  if ( p_pcbData )
  {
    if ( *((_BYTE *)this + 79) )
    {
      if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)v15 + 2), 35i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
      p_pcbData->dwFlags &= ~1u;
      p_pcbData->dwFlags |= 0x40u;
      LocalServerKeyFromProvider = CSslCredential::GetLocalServerKeyFromProvider(
                                     (const struct _CERT_CONTEXT **)this,
                                     a2);
    }
    else
    {
      if ( *((_BYTE *)this + 78) )
      {
        if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)v15 + 2), 37i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
        v4 = RemotelyOpenClientKeyHandle(
               p_pcbData->pwszContainerName,
               p_pcbData->pwszProvName,
               (unsigned __int8 *)this + 40,
               p_pcbData->dwKeySpec,
               p_pcbData->dwProvType,
               p_pcbData->dwFlags);
        if ( !v4 )
          goto LABEL_80;
        *((_DWORD *)this + 18) = 10003;
LABEL_68:
        LogCredAcquireContextFailedEvent(
          *((_DWORD *)this + 163),
          (const WCHAR *)this + 328,
          *((_BYTE *)this + 79),
          v4,
          *((_DWORD *)this + 18));
LABEL_80:
        if ( p_pcbData[-1].dwKeySpec == 1885431112 )
          ((void (*)(void))g_pfnFree)();
        return v4;
      }
      if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)v15 + 2), 36i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
      LocalServerKeyFromProvider = CSslCredential::GetLocalClientKeyFromProvider(
                                     (NCRYPT_KEY_HANDLE *)this,
                                     p_pcbData,
                                     a2);
    }
    v4 = LocalServerKeyFromProvider;
    if ( !LocalServerKeyFromProvider )
      goto LABEL_80;
    goto LABEL_68;
  }
  if ( !v24 )
  {
    v4 = -2146893042;
    goto LABEL_77;
  }
  if ( *((_BYTE *)this + 79) )
  {
    if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)v15 + 2), 38i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids);
    v4 = CSslCredential::GetLocalServerKeyFromProvider((const struct _CERT_CONTEXT **)this, a2);
    if ( v4 )
      LogCredAcquireContextFailedEvent(
        *((_DWORD *)this + 163),
        (const WCHAR *)this + 328,
        *((_BYTE *)this + 79),
        v4,
        *((_DWORD *)this + 18));
  }
  return v4;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;

