//----- (000000018006DBE0) ----------------------------------------------------
__int64 __fastcall CTls13ClientContext::ProcessHandshake(
        CTls13ClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        struct CSessionCacheClientItem *a4)
{
  unsigned __int8 *v5; // r12
  unsigned int v6; // r13d
  __int64 v7; // r9
  unsigned int updated; // ebx
  unsigned int v9; // eax
  __int64 *v10; // rax
  __int64 v11; // rcx
  unsigned int v12; // eax
  int v13; // r8d
  int v14; // edx
  __int64 v15; // rdx
  __int64 v16; // rcx
  CCipherMill *v17; // rcx
  __int64 v18; // rdx
  int v19; // r15d
  __int64 v21; // rcx
  char v22; // bl
  __int64 v23; // rax
  __int64 v24; // rax
  const unsigned __int16 *v25; // r12
  struct CSessionCacheManager *v26; // rdx
  __int64 v27; // rcx
  struct CSessionCacheClientItem *v28; // r13
  __int64 v29; // rcx
  __int64 **v30; // r12
  __int64 *v31; // rax
  unsigned int v32; // ecx
  __int64 v33; // rdx
  _QWORD *v34; // r13
  unsigned int v35; // eax
  __int64 v36; // rcx
  char v37; // dl
  __int64 v38; // rcx
  __int64 v39; // rax
  __int64 *v40; // rax
  __int64 v41; // rdx
  __int64 *v43; // rax
  __int64 v44; // rdx
  _QWORD *v45; // rax
  __int64 v46; // rcx
  const char *v47; // r9
  __int64 *v48; // rax
  __int64 v49; // rdx
  _QWORD *v50; // r15
  unsigned int v51; // eax
  __int64 v52; // rcx
  CCipherMill *v53; // rcx
  CCipherMill *v54; // rcx
  unsigned __int8 v55; // r9
  int v56; // edx
  unsigned __int8 v57; // bl
  unsigned __int16 v58; // ax
  int v59; // ecx
  __int64 v60; // r10
  unsigned int v61; // edx
  unsigned int v62; // eax
  unsigned int v64; // [rsp+A0h] [rbp+50h] BYREF
  struct CSessionCacheClientItem *v65; // [rsp+A8h] [rbp+58h] BYREF

  v65 = a4;
  v64 = a3;
  *(_DWORD *)a4 = 0;
  *((_BYTE *)this + 1650) = 0;
  if ( !a3 || !a2 )
    return 87i64;
  v5 = a2 + 4;
  v6 = a3 - 4;
  v7 = *a2 << 8;
  updated = 0;
  v9 = v7 | *((unsigned __int8 *)this + 68);
  if ( v9 > 0xD35 )
  {
    if ( v9 != 3406 )
    {
      if ( v9 == 3407 )
      {
        v53 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
            v53 = WPP_GLOBAL_Control;
          }
          if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
            WPP_SF_(*((_QWORD *)v53 + 2), 32i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        }
        return updated;
      }
      if ( v9 == 3881 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        updated = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseCertificateVerify(
                    (__int64)this + 1656,
                    (__int64)v5,
                    v6);
        if ( !updated )
          *((_DWORD *)this + 17) = 54;
        return updated;
      }
      if ( v9 <= 0x1435 )
      {
LABEL_151:
        *((_WORD *)this + 48) = 2562;
        *((_DWORD *)this + 17) = 96;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_DD(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x2Au,
            (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
            v7,
            96);
        return (unsigned int)-2146893018;
      }
      if ( v9 > 0x1437 )
      {
        if ( v9 != 6148 && v9 - 6222 > 1 )
          goto LABEL_151;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        updated = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseKeyUpdate((__int64)this + 1656, v5, v6);
        if ( updated )
          return updated;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 41i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        v45 = (_QWORD *)*((_QWORD *)this + 1);
        v46 = v45 ? *v45 : 0i64;
        updated = UpdateTrafficSecretAndDeriveNewKey(
                    v46,
                    (unsigned __int64 *)this + 182,
                    (unsigned __int64 *)this + 18,
                    (unsigned __int64 *)this + 22);
        if ( updated )
          return updated;
        goto LABEL_43;
      }
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v47 = "full";
        if ( *((_DWORD *)this + 17) != 54 )
          v47 = "resumption";
        WPP_SF_s(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x26u,
          (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
          v47);
      }
      updated = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ParseFinished((__int64)this + 1656, v5, v6);
      if ( updated )
        return updated;
      updated = (*(__int64 (__fastcall **)(CTls13ClientContext *, unsigned __int8 *, _QWORD, _QWORD))(*(_QWORD *)this + 504i64))(
                  this,
                  a2,
                  v64,
                  0i64);
      if ( updated )
        return updated;
      v64 = 903;
      *(_DWORD *)v65 = 1;
      v48 = (__int64 *)*((_QWORD *)this + 1);
      if ( v48 )
        v49 = *v48;
      else
        v49 = 0i64;
      v50 = (_QWORD *)((char *)this + 160);
      v51 = CTls13Context::GenerateApplicationWriteKeys(
              (CTls13ClientContext *)((char *)this + 1368),
              v49,
              *((_QWORD *)this + 74),
              (unsigned __int64 *)this + 21,
              (unsigned __int64 *)this + 20,
              (enum eSslErrorState *)&v64);
      updated = v51;
      if ( !v51 )
      {
        *((_WORD *)this + 16) |= 0xAu;
        v52 = *((_QWORD *)this + 18);
        if ( v52 )
          SslFreeObject(v52, 0i64);
        *((_QWORD *)this + 18) = *v50;
        *v50 = 0i64;
        if ( !*((_BYTE *)this + 233) )
          *((_QWORD *)this + 22) = 0i64;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        goto LABEL_196;
      }
      v13 = v51;
LABEL_82:
      v14 = v64;
      goto LABEL_105;
    }
  }
  else if ( v9 != 3381 )
  {
    if ( v9 != 552 && v9 != 583 )
    {
      if ( v9 != 1028 )
      {
        if ( v9 <= 0x44D )
          goto LABEL_151;
        if ( v9 > 0x44F )
        {
          if ( v9 == 2118 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
            }
            updated = CTls13ClientHandshake::ParseEncryptedExtensionsMsg(
                        (CTls13ClientContext *)((char *)this + 1656),
                        v5,
                        v6,
                        v7);
            if ( !updated )
              *((_DWORD *)this + 17) = ~(unsigned __int8)((unsigned __int64)*((unsigned int *)this + 34) >> 14) & 2 | 0x35;
            return updated;
          }
          if ( v9 == 2860 || v9 == 2869 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
            }
            updated = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ParseCertificateMsg(
                        (__int64)this + 1656,
                        v5,
                        v6);
            if ( !updated )
            {
              if ( (*((_DWORD *)this + 34) & 0x20000000) == 0
                || (RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u),
                    updated = CSessionCacheClientItem::UpdateRemoteEndpointBindings(*((CSessionCacheClientItem **)this
                                                                                    + 165)),
                    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64)),
                    !updated) )
              {
                CreateServerCertificateSerialChainProperty(this);
                updated = AutoVerifyServerCertificate(this);
                if ( !updated )
                  *((_DWORD *)this + 17) = 41;
              }
            }
            return updated;
          }
          goto LABEL_151;
        }
      }
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 39i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
      updated = CTls13ClientHandshake::ParseNewSessionTicket((CTls13ClientContext *)((char *)this + 1656), v5, v6);
      if ( updated )
        return updated;
      if ( *((_BYTE *)this + 1850) )
      {
        if ( !*((_QWORD *)this + 11) )
          return 1359;
        v10 = (__int64 *)*((_QWORD *)this + 1);
        v65 = 0i64;
        if ( v10 )
          v11 = *v10;
        else
          v11 = 0i64;
        v12 = SslExpandResumptionMasterKey(v11, *((_QWORD *)this + 180), *((_QWORD *)this + 74), &v65, 0i64, 0);
        updated = v12;
        if ( v12 )
        {
          v13 = v12;
          v14 = 613;
LABEL_105:
          CSslContext::SetError((__int64)this, v14, v13);
          return updated;
        }
        RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
        v15 = *((_QWORD *)this + 11);
        v16 = *(_QWORD *)(v15 + 16);
        if ( v16 )
        {
          SslFreeObject(v16, 0i64);
          v15 = *((_QWORD *)this + 11);
        }
        *(_QWORD *)(v15 + 16) = v65;
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
        if ( (*((_DWORD *)this + 34) & 0x8000i64) != 0 )
          CSessionCacheManager::FinishCacheAddItem(CSessionCacheManager::m_pSessionCacheManager, this);
        *((_BYTE *)this + 1850) = 0;
      }
LABEL_43:
      if ( *((_DWORD *)this + 17) != 79 )
        *((_DWORD *)this + 17) = 4;
      return updated;
    }
    if ( *((_DWORD *)this + 17) == 40 )
    {
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        goto LABEL_53;
      v18 = 27i64;
    }
    else
    {
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        goto LABEL_53;
      v18 = 28i64;
    }
    WPP_SF_(*((_QWORD *)v17 + 2), v18, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
LABEL_53:
    *((_QWORD *)this + 17) |= 0x8000ui64;
    v19 = *((_DWORD *)this + 17);
    updated = CTls13ClientHandshake::ParseServerHello((CTls13ClientContext *)((char *)this + 1656), v5, v6);
    if ( updated )
    {
      *((_DWORD *)this + 17) = v19;
      return updated;
    }
    if ( (*((_DWORD *)this + 16) & 0x2000) == 0 )
    {
      *((_QWORD *)this + 17) &= ~0x8000ui64;
      *((_DWORD *)this + 17) = v19;
      return (unsigned int)CTls13ClientContext::DowngradeClientToSsl3Tls(this);
    }
    if ( *((_DWORD *)this + 17) == 70 )
    {
      updated = (*(__int64 (__fastcall **)(CTls13ClientContext *, unsigned __int8 *, _QWORD, _QWORD))(*(_QWORD *)this + 504i64))(
                  this,
                  a2,
                  v64,
                  0i64);
      if ( updated )
        return updated;
      *(_DWORD *)v65 = 1;
      if ( (*((_DWORD *)this + 34) & 0x8000i64) != 0 )
      {
        v24 = *((_QWORD *)this + 165);
        v22 = 0;
        LOBYTE(v64) = 0;
        if ( v24 && *(_DWORD *)(v24 + 432) )
        {
          v25 = *(const unsigned __int16 **)(v24 + 368);
          v65 = 0i64;
          CSessionCacheManager::AcquireCacheTableLock(v21, v25, 0i64);
          RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u);
          v26 = CSessionCacheManager::m_pSessionCacheManager;
          *(_BYTE *)(*((_QWORD *)this + 165) + 236i64) = 0;
          updated = CSessionCacheClientItem::CloneCacheElement(*((CSessionCacheClientItem **)this + 165), v26, &v65);
          RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
          if ( updated )
          {
            CSessionCacheManager::ReleaseCacheTableLock(v27, v25, 0i64);
            return updated;
          }
          v28 = v65;
          if ( !v65 )
            return (unsigned int)-2146893052;
          RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)v65 + 72), 1u);
          *((_QWORD *)this + 165) = v28;
          *((_QWORD *)this + 11) = v28;
          RtlReleaseResource((PRTL_RESOURCE)((char *)v28 + 72));
          CSessionCacheManager::ReleaseCacheTableLock(v29, v25, 0i64);
          v22 = v64;
        }
      }
      else
      {
        v22 = 1;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        v23 = *((_QWORD *)this + 15);
        if ( v23 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        {
          *(_WORD *)(v23 + 64) |= 4u;
          *(_DWORD *)(v23 + 24) = 1;
        }
      }
      v30 = (__int64 **)((char *)this + 8);
      v64 = 100;
      if ( (*((_BYTE *)this + 32) & 1) != 0 && (v31 = *v30) != 0i64 )
      {
        v32 = *((_DWORD *)v31 + 7);
      }
      else
      {
        v31 = *v30;
        v32 = 0;
      }
      if ( v31 )
        v33 = *v31;
      else
        v33 = 0i64;
      v34 = (_QWORD *)((char *)this + 160);
      v35 = CTls13Context::GenerateHandshakeWriteKeys(
              (CTls13ClientContext *)((char *)this + 1368),
              v33,
              *((_QWORD *)this + 14),
              *((_QWORD *)this + 74),
              *((_WORD *)this + 17),
              v32,
              v22,
              (unsigned __int64 *)this + 21,
              (unsigned __int64 *)this + 20,
              (enum eSslErrorState *)&v64);
      updated = v35;
      if ( v35 )
      {
        v13 = v35;
        goto LABEL_82;
      }
      *((_WORD *)this + 16) |= 0xAu;
      v36 = *((_QWORD *)this + 18);
      if ( v36 )
        SslFreeObject(v36, 0i64);
      v37 = *((_BYTE *)this + 233);
      *((_QWORD *)this + 18) = *v34;
      *v34 = 0i64;
      if ( !v37 )
        *((_QWORD *)this + 22) = 0i64;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        v37 = *((_BYTE *)this + 233);
      }
      *((_WORD *)this + 16) |= 0xCu;
      if ( !v37 )
      {
        v38 = *((_QWORD *)this + 19);
        v37 = 0;
        if ( v38 )
        {
          SslFreeObject(v38, 0i64);
          v37 = *((_BYTE *)this + 233);
        }
      }
      *((_QWORD *)this + 19) = *((_QWORD *)this + 21);
      *((_QWORD *)this + 21) = 0i64;
      if ( !v37 )
        *((_QWORD *)this + 23) = 0i64;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
      v39 = *(_QWORD *)this;
      updated = 0;
      *((_BYTE *)this + 1584) = 2;
      if ( !(*(unsigned __int8 (__fastcall **)(CTls13ClientContext *))(v39 + 384))(this) )
      {
        v40 = *v30;
        if ( *v30 )
          v41 = *v40;
        else
          v41 = 0i64;
        updated = CTls13Context::PopulateSecTrafficSecret((__int64)this + 1368, v41, 1, 2u, (__int64)v40, 0, 0);
        if ( updated )
        {
          v14 = 610;
LABEL_104:
          v13 = updated;
          goto LABEL_105;
        }
        v43 = *v30;
        if ( *v30 )
          v44 = *v43;
        else
          v44 = 0i64;
        updated = CTls13Context::PopulateSecTrafficSecret((__int64)this + 1368, v44, 0, 2u, (__int64)v43, 0, 0);
        if ( updated )
        {
          v14 = 609;
          goto LABEL_104;
        }
      }
    }
    *((_BYTE *)this + 1315) = 0;
    return updated;
  }
  v54 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 33i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
    v54 = WPP_GLOBAL_Control;
  }
  if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4 )
  {
    if ( v54 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v54 + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)v54 + 2), 34i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
    v55 = 10;
    updated = -2146893018;
    v56 = 400;
    goto LABEL_189;
  }
  updated = CTls13ClientHandshake::ParseCertificateRequest((CTls13ClientContext *)((char *)this + 1656), v5, v6);
  if ( !updated )
  {
    *((_WORD *)this + 673) = 0;
    v57 = 0;
    while ( 1 )
    {
      v58 = *((_WORD *)this + 673);
      if ( v58 >= 4u )
      {
LABEL_184:
        if ( !v58 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 35i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          }
          v55 = 40;
          updated = -2146893007;
          v56 = 402;
LABEL_189:
          CSslContext::SetErrorAndFatalAlert((__int64)this, v56, updated, v55);
          return updated;
        }
        v62 = CSsl3TlsClientContext::CheckForClientCred(this);
        updated = v62;
        if ( v62 == -2146893024 )
        {
          *((_BYTE *)this + 1313) = 1;
          goto LABEL_193;
        }
        if ( v62 == 590624 )
        {
LABEL_193:
          updated = 0;
        }
        else if ( v62 )
        {
          return updated;
        }
        *((_BYTE *)this + 1315) = 1;
        if ( !*((_BYTE *)this + 1601) )
        {
          *((_DWORD *)this + 17) = 44;
          return updated;
        }
LABEL_196:
        *((_DWORD *)this + 17) = 101;
        return CTls13ClientContext::DetermineClientCredentialStatus(this);
      }
      v59 = g_Ssl3CertTypes[v57];
      if ( v59 != 2 )
      {
        v60 = *((_QWORD *)this + 10);
        v61 = *(_DWORD *)(v60 + 196);
        if ( !v61 )
          goto LABEL_181;
        if ( !IsSignatureTypeBlacklisted(*(_QWORD *)(v60 + 200), v61, v59, 0i64) )
          break;
      }
LABEL_182:
      if ( ++v57 >= 3u )
      {
        v58 = *((_WORD *)this + 673);
        goto LABEL_184;
      }
    }
    v58 = *((_WORD *)this + 673);
    v59 = g_Ssl3CertTypes[v57];
LABEL_181:
    *((_DWORD *)this + v58 + 337) = v59;
    ++*((_WORD *)this + 673);
    goto LABEL_182;
  }
  return updated;
}
// 18006DDB3: variable 'v7' is possibly undefined
// 18006E0A3: variable 'v21' is possibly undefined
// 18006E10A: variable 'v27' is possibly undefined
// 18006E15B: variable 'v29' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 1800858E8: using guessed type _DWORD g_Ssl3CertTypes[4];
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 180098450: using guessed type __int64 __fastcall SslExpandResumptionMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
