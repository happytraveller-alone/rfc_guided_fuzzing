//----- (0000000180073C88) ----------------------------------------------------
__int64 __fastcall DoCertificateMapping(struct CSsl3TlsServerContext *a1)
{
  __int64 v1; // rax
  __int64 v3; // r12
  __int64 v4; // rsi
  CCipherMill *v5; // rcx
  CERT_CONTEXT *v6; // r14
  int v7; // r8d
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // r15d
  __int64 v14; // r8
  int v15; // eax
  int v16; // edi
  __int64 v18; // [rsp+20h] [rbp-30h]
  const struct _CERT_CONTEXT *v19; // [rsp+30h] [rbp-20h]
  unsigned __int64 v20; // [rsp+80h] [rbp+30h] BYREF
  __int64 v21; // [rsp+88h] [rbp+38h] BYREF
  PCCERT_CONTEXT pCertContext; // [rsp+90h] [rbp+40h] BYREF

  v1 = *((_QWORD *)a1 + 10);
  pCertContext = 0i64;
  LODWORD(v20) = -2146893019;
  v3 = *(_QWORD *)(v1 + 752);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids);
  (*(void (__fastcall **)(struct CSsl3TlsServerContext *, __int64 *))(*(_QWORD *)a1 + 232i64))(a1, &v21);
  v4 = *((_QWORD *)a1 + 10);
  if ( (*((_DWORD *)a1 + 34) & 0x10000i64) == 0 || v4 && *(_QWORD *)(v4 + 848) )
  {
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v21 + 72), 1u);
    if ( !SPLoadCertificate(*(unsigned __int8 **)(v21 + 24), *(_DWORD *)(v21 + 32), &pCertContext) )
    {
      v6 = (CERT_CONTEXT *)pCertContext;
      if ( v4 && *(_QWORD *)(v4 + 848) )
      {
        RunClientCertPolicy((struct CCredentialGroup *)v4, pCertContext, &v20);
        *(_QWORD *)(v21 + 216) = (unsigned int)v20;
      }
      if ( (*((_DWORD *)a1 + 34) & 0x10000) != 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids);
      }
      else
      {
        v7 = *(_DWORD *)(v4 + 160);
        v8 = ((v7 & 0x100) << 16) | 0x2000000;
        if ( (v7 & 0x200) == 0 )
          v8 = (*(_DWORD *)(v4 + 160) & 0x100) << 16;
        v9 = v8 | 0x4000000;
        if ( (v7 & 0x400) == 0 )
          v9 = v8;
        v10 = v9 | 0x8000000;
        if ( (v7 & 0x800) == 0 )
          v10 = v9;
        v11 = v10 | 0x10000000;
        if ( (v7 & 0x1000) == 0 )
          v11 = v10;
        v12 = v11 | 0x200000;
        if ( (v7 & 0x2000) == 0 )
          v12 = v11;
        v13 = v12 | 0x400000;
        v14 = v7 & 0x4000;
        if ( !(_DWORD)v14 )
          v13 = v12;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids);
        v15 = SslMapCredential(
                (struct CCredentialGroup *)v4,
                *((void **)a1 + 116),
                v14,
                v3,
                v13,
                v6,
                v19,
                *((unsigned __int16 **)a1 + 116),
                *((unsigned __int16 **)a1 + 117),
                &v20);
        v16 = v15;
        if ( v15 < 0 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              22i64,
              &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids,
              (unsigned int)v15);
          }
          *(_DWORD *)(v21 + 352) = v16;
        }
        else
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_q(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0x15u,
              (__int64)&WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids,
              *(_QWORD *)(v21 + 344));
          }
          *(_QWORD *)(v21 + 344) = v20;
          *(_DWORD *)(v21 + 352) = 0;
        }
      }
      CertFreeCertificateContext(v6);
    }
    RtlReleaseResource((PRTL_RESOURCE)(v21 + 72));
    goto LABEL_44;
  }
  v5 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
    return 0i64;
  if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids);
LABEL_44:
    v5 = WPP_GLOBAL_Control;
  }
  if ( v5 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
  {
    LODWORD(v18) = 0;
    WPP_SF_DD(*((_QWORD *)v5 + 2), 0x17u, (__int64)&WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids, 0, v18);
  }
  return 0i64;
}
// 180073EDC: variable 'v14' is possibly undefined
// 180073EDC: variable 'v19' is possibly undefined
// 180073FC4: variable 'v18' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
