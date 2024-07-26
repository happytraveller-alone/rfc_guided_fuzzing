//----- (0000000180073BB4) ----------------------------------------------------
__int64 __fastcall CreateChainEngine(struct CCredentialGroup *a1)
{
  DWORD LastError; // eax
  struct _CERT_CHAIN_ENGINE_CONFIG pConfig; // [rsp+20h] [rbp-68h] BYREF
  int v5; // [rsp+70h] [rbp-18h]
  HCERTCHAINENGINE phChainEngine; // [rsp+98h] [rbp+10h] BYREF

  memset_0(&pConfig, 0, 0x58ui64);
  phChainEngine = 0i64;
  pConfig.cbSize = 88;
  pConfig.dwFlags = 56;
  if ( !g_eClientAuthMode )
    return 1i64;
  if ( g_eClientAuthMode != 1 )
  {
    if ( g_eClientAuthMode != 2 )
      goto LABEL_6;
    v5 |= 1u;
  }
  pConfig.hExclusiveRoot = (HCERTSTORE)*((_QWORD *)a1 + 102);
LABEL_6:
  if ( !CertCreateCertificateChainEngine(&pConfig, &phChainEngine) )
  {
    LastError = GetLastError();
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids, LastError);
    return 1i64;
  }
  return (__int64)phChainEngine;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

