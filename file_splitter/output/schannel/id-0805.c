//----- (0000000180042648) ----------------------------------------------------
__int64 __fastcall MapKernelAuthDataV4(
        struct _SCHANNEL_CRED *a1,
        struct _UNICODE_STRING *a2,
        void *a3,
        struct LSA_SCHANNEL_CRED *a4)
{
  unsigned int ImplicitCredentials; // ebx
  unsigned int cCreds; // ecx
  DWORD cSupportedAlgs; // eax
  unsigned __int64 v11; // rbx
  HLOCAL v12; // rax
  DWORD grbitEnabledProtocols; // eax
  DWORD dwCredFormat; // eax
  struct LSA_SCHANNEL_CRED *v16; // [rsp+20h] [rbp-18h]

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 47i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
  memset_0(a4, 0, 0x70ui64);
  if ( !a1 || a1->dwVersion != 4 )
    return 2148074253i64;
  *(_DWORD *)a4 = 4;
  if ( a2 && a2->Buffer )
  {
    ImplicitCredentials = LoadImplicitCredentials(a2, (__int64)a3, a4);
    if ( !ImplicitCredentials )
    {
LABEL_13:
      cSupportedAlgs = a1->cSupportedAlgs;
      if ( cSupportedAlgs )
      {
        *((_DWORD *)a4 + 14) = cSupportedAlgs;
        v11 = 4i64 * cSupportedAlgs;
        if ( v11 > 0xFFFFFFFF )
        {
          ImplicitCredentials = 534;
          goto LABEL_28;
        }
        v12 = SPExternalAlloc(v11);
        *((_QWORD *)a4 + 8) = v12;
        if ( !v12 )
        {
          ImplicitCredentials = 14;
          goto LABEL_28;
        }
        memcpy_0(v12, a1->palgSupportedAlgs, (unsigned int)v11);
      }
      grbitEnabledProtocols = 0;
      if ( a1->grbitEnabledProtocols != -1 )
        grbitEnabledProtocols = a1->grbitEnabledProtocols;
      *((_DWORD *)a4 + 18) = grbitEnabledProtocols;
      *((_DWORD *)a4 + 19) = a1->dwMinimumCipherStrength;
      *((_DWORD *)a4 + 20) = a1->dwMaximumCipherStrength;
      *((_DWORD *)a4 + 21) = a1->dwSessionLifespan;
      *((_DWORD *)a4 + 22) = a1->dwFlags;
      dwCredFormat = a1->dwCredFormat;
      *((_DWORD *)a4 + 18) &= 0x3FFFFFFFu;
      ImplicitCredentials = 0;
      *((_DWORD *)a4 + 23) = dwCredFormat;
      goto LABEL_21;
    }
  }
  else
  {
    cCreds = a1->cCreds;
    if ( !cCreds )
      goto LABEL_13;
    ImplicitCredentials = LoadCredentialsFromLocalStore(cCreds, a1->paCred, a1->dwCredFormat, a3, a4);
    if ( !ImplicitCredentials )
    {
      *((_DWORD *)a4 + 1) = a1->cCreds;
      goto LABEL_13;
    }
  }
LABEL_28:
  FreeSchannelCred(a4, 1);
LABEL_21:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && ImplicitCredentials
     || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(v16) = ImplicitCredentials;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x30u,
      (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
      ImplicitCredentials,
      v16);
  }
  return ImplicitCredentials;
}
// 1800427BE: variable 'v16' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

