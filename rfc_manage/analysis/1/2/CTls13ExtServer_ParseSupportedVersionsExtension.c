//----- (0000000180078668) ----------------------------------------------------
__int64 __fastcall CTls13ExtServer::ParseSupportedVersionsExtension(
    CTls13ExtServer *this, unsigned __int8 *a2, __int16 a3) {
  __int16 v4;           // ax
  unsigned __int16 v5;  // r8
  unsigned __int8 *v6;  // rdx
  __int64 v7;           // r11
  __int64 v8;           // rax
  unsigned int v9;      // ebx
  _DWORD *v10;          // rcx
  int v11;              // r9d
  unsigned __int8 *v12; // rbx
  unsigned __int8 *v13; // rsi
  unsigned int v14;     // ebp
  __int64 v15;          // rcx
  unsigned __int8 v16;  // r9
  __int16 v17;          // ax
  int v18;              // r10d
  __int64 v19;          // r11
  __int64 v20;          // rcx

  if (!a2 || !a3) {
    v15 = *((_QWORD *)this + 1);
  LABEL_28:
    v9 = -2146893048;
    v16 = 50;
  LABEL_29:
    CSslContext::SetErrorAndFatalAlert(v15, 1202, v9, v16);
    return v9;
  }
  v4 = *a2;
  v5 = a3 - 1;
  v6 = a2 + 1;
  if ((unsigned __int8)v4 < 2u || (v4 & 1) != 0 || v4 != v5) {
    v15 = *((_QWORD *)this + 1);
    goto LABEL_28;
  }
  v7 = *((_QWORD *)this + 1);
  v8 = *(_QWORD *)(v7 + 80);
  if (!v8) {
    v9 = 1359;
    CSslContext::SetError(*((_QWORD *)this + 1), 1202, 1359);
    return v9;
  }
  v10 = &TlsVersions;
  while (1) {
    v11 = *(_DWORD *)(v8 + 152) & *v10 & 0x40051555;
    if (v11) {
      v12 = v6;
      v13 = &v6[v5];
      if (v6 < v13)
        break;
    }
  LABEL_14:
    v10 += 2;
    if (v10 >= WPP_922678f99ae534148d3bb024010f1556_Traceguids) {
      if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
          (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0)
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64,
                &WPP_5635b40337ae3cd6626e599d778a0aa6_Traceguids);
      v15 = *((_QWORD *)this + 1);
      v16 = 70;
      v9 = -2146893007;
      goto LABEL_29;
    }
  }
  v14 = *((unsigned __int16 *)v10 + 2);
  while ((v12[1] | (*v12 << 8)) != v14) {
    v12 += 2;
    if (v12 >= v13)
      goto LABEL_14;
  }
  *(_DWORD *)(v7 + 64) = v11;
  v17 = ConvertSchannelProtocolToSsl(v11);
  *(_WORD *)(v19 + 34) = v17;
  *(_DWORD *)(*((_QWORD *)this + 1) + 36i64) = v18;
  v20 = *(_QWORD *)(*((_QWORD *)this + 1) + 120i64);
  if (v20 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
    *(_DWORD *)(v20 + 44) = v18;
  if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
      (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0)
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64,
             &WPP_5635b40337ae3cd6626e599d778a0aa6_Traceguids, v14);
  *((_BYTE *)this + 27) = 1;
  return 0i64;
}
// 18007878E: variable 'v19' is possibly undefined
// 180078797: variable 'v18' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD,
// _QWORD); 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD,
// _QWORD, _QWORD, _QWORD); 180082C10: using guessed type _DWORD
// WPP_922678f99ae534148d3bb024010f1556_Traceguids[4]; 1800927AC: using guessed
// type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;