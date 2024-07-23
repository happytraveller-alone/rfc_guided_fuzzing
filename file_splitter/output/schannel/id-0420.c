// File count: 420
// Total lines: 252
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::ProcessHandshake(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        int *a4)
{
  int v8; // eax
  int v9; // esi
  unsigned int v10; // r13d
  int v11; // r9d
  unsigned __int8 *v12; // r12
  unsigned __int8 v13; // dl
  unsigned int v14; // eax
  unsigned int ServerMasterKey; // edi
  CCipherMill *v17; // rcx
  __int64 v18; // rcx
  int v19; // eax
  __int64 v20; // rdx
  CCipherMill *v21; // rcx
  int v22; // eax
  char v23; // [rsp+70h] [rbp+8h] BYREF
  unsigned __int8 v24; // [rsp+80h] [rbp+18h]

  v8 = 4;
  if ( *((_BYTE *)this + 233) )
    v8 = 12;
  v9 = 0;
  v10 = a3 - v8;
  v11 = *a2 << 16;
  *a4 = 0;
  v12 = &a2[v8];
  v13 = 1;
  v14 = v11 | *((unsigned __int16 *)this + 34);
  v23 = 0;
  v24 = 1;
  if ( v14 == 0x10000 )
  {
LABEL_10:
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      v13 = v24;
    }
    ServerMasterKey = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, unsigned __int8 *, _QWORD, _QWORD, char *))(*(_QWORD *)this + 536i64))(
                        this,
                        a2,
                        a3,
                        v13,
                        &v23);
    if ( !ServerMasterKey )
    {
      LOBYTE(v9) = v23 != 0;
      *((_DWORD *)this + 17) = v9 + 93;
    }
    *((_BYTE *)this + 552) = 0;
    return ServerMasterKey;
  }
  if ( v14 == 1310785 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 21i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
    ServerMasterKey = CSsl3TlsContext::DigestFinish(this, v12, v10);
    if ( !ServerMasterKey )
    {
      (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 448i64))(this);
      *a4 = 1;
    }
    return ServerMasterKey;
  }
  if ( v14 > 0x100046 )
  {
    switch ( v14 )
    {
      case 0x14003Fu:
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
        ServerMasterKey = CSsl3TlsContext::DigestFinish(this, v12, v10);
        if ( !ServerMasterKey )
          *((_DWORD *)this + 17) = 95;
        return ServerMasterKey;
      case 0x10004Bu:
        goto LABEL_19;
      case 0x170046u:
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
        return (unsigned int)CSsl3TlsServerContext::DigestSupplementalDataMsg(this, v12, v10);
    }
LABEL_40:
    if ( (*((_DWORD *)this + 16) & 0xF3FC0) != 0 )
    {
      *((_DWORD *)this + 17) = 96;
      *((_WORD *)this + 48) = 2562;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x17u,
        (__int64)&WPP_095c39149c3f336b5b94efe855075ae2_Traceguids,
        v11,
        *((unsigned __int16 *)this + 34));
    return (unsigned int)-2146893018;
  }
  if ( v14 == 1048646 )
  {
LABEL_19:
    v17 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      v17 = WPP_GLOBAL_Control;
    }
    if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) != 4 )
    {
      if ( *((_DWORD *)this + 17) != 70 || (*((_DWORD *)this + 34) & 0x100i64) == 0 )
        goto LABEL_25;
      if ( v17 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v17 + 28) & 1) == 0 )
        return (unsigned int)-2146893018;
      v20 = 14i64;
LABEL_84:
      WPP_SF_(*((_QWORD *)v17 + 2), v20, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      return (unsigned int)-2146893018;
    }
    if ( *((_QWORD *)this + 106) )
    {
LABEL_25:
      ServerMasterKey = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, unsigned __int8 *, _QWORD, _QWORD))(*(_QWORD *)this + 504i64))(
                          this,
                          a2,
                          a3,
                          0i64);
      if ( !ServerMasterKey )
      {
        *a4 = 1;
        *((_QWORD *)this + 17) |= 0x8000ui64;
        v18 = *((_QWORD *)this + 1);
        v19 = *(_DWORD *)(v18 + 48);
        switch ( v19 )
        {
          case 3:
            ServerMasterKey = CSsl3TlsServerContext::EccGenerateServerMasterKey(this, v12, v10);
            break;
          case 2:
            ServerMasterKey = CSsl3TlsServerContext::DhGenerateServerMasterKey(this, v12, v10);
            break;
          case 4:
            ServerMasterKey = MakeEccDhPskSessionKeysHelper(this, 0i64, 0i64, 1);
            break;
          default:
            v22 = *(_DWORD *)(v18 + 52);
            if ( v22 == 2 )
              ServerMasterKey = CSslContext::I_RsaGenerateServerMasterKey(this, v12, v10);
            else
              ServerMasterKey = v22 == 4
                              ? CSslContext::I_RsaGenerateEcdsaSignServerMasterKey(this, v12, v10)
                              : -2146893048;
            break;
        }
        if ( !ServerMasterKey )
          *((_DWORD *)this + 17) = 61;
      }
      return ServerMasterKey;
    }
    ServerMasterKey = CSsl3TlsContext::SetPSKExchangeValue(this, v12, v10, 0);
    if ( !ServerMasterKey )
    {
      if ( *((_BYTE *)this + 233) )
        *((_BYTE *)this + 232) = 1;
      ServerMasterKey = 590624;
      *a4 = 1;
    }
    return ServerMasterKey;
  }
  if ( v14 == 65612 )
  {
    v21 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      v21 = WPP_GLOBAL_Control;
    }
    if ( CSslGlobals::m_fDisableRenegoOnServer )
    {
      ServerMasterKey = -2146893018;
      if ( v21 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v21 + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)v21 + 2), 11i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      return ServerMasterKey;
    }
    CSchannelTelemetryContext::LogRenegoStart(*((_QWORD *)this + 15), 1, *((_QWORD *)this + 17));
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 240i64))(this);
    *((_QWORD *)this + 17) &= ~0x40000000ui64;
    v13 = 0;
    *((_QWORD *)this + 11) = 0i64;
    v24 = 0;
    goto LABEL_10;
  }
  if ( v14 != 720966 )
  {
    if ( v14 == 983101 )
    {
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
        v17 = WPP_GLOBAL_Control;
      }
      if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4 )
      {
        if ( v17 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v17 + 28) & 1) == 0 )
          return (unsigned int)-2146893018;
        v20 = 20i64;
        goto LABEL_84;
      }
      ServerMasterKey = CSsl3TlsServerContext::DigestCertVerify(this, v12, v10);
      if ( !ServerMasterKey )
      {
        ServerMasterKey = DoCertificateMapping(this);
        *((_DWORD *)this + 17) = 62;
      }
      return ServerMasterKey;
    }
    if ( v14 == 1048636 )
      goto LABEL_19;
    goto LABEL_40;
  }
  v17 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
    v17 = WPP_GLOBAL_Control;
  }
  if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4 )
  {
    if ( v17 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v17 + 28) & 1) == 0 )
      return (unsigned int)-2146893018;
    v20 = 17i64;
    goto LABEL_84;
  }
  if ( (*((_DWORD *)this + 34) & 0x100i64) == 0 )
  {
    if ( v17 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v17 + 28) & 1) == 0 )
      return (unsigned int)-2146893018;
    v20 = 18i64;
    goto LABEL_84;
  }
  ServerMasterKey = CSsl3TlsContext::DigestRemoteCertificate(this, v12, v10);
  if ( !ServerMasterKey )
    *((_DWORD *)this + 17) = 60;
  return ServerMasterKey;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800927C0: using guessed type int CSslGlobals::m_fDisableRenegoOnServer;
