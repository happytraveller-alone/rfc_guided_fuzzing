//----- (00000001800433E4) ----------------------------------------------------
PCCTL_CONTEXT __fastcall FindCtlInStore(const unsigned __int16 *a1, const unsigned __int16 *a2)
{
  HCERTSTORE v4; // rdi
  __int64 v6; // rax
  PCCTL_CONTEXT CTLInStore; // rsi
  void *pvFindPara; // [rsp+20h] [rbp-48h]
  void *pvFindParaa; // [rsp+20h] [rbp-48h]
  __int128 v10; // [rsp+30h] [rbp-38h] BYREF
  __int128 v11; // [rsp+40h] [rbp-28h]
  __int128 v12; // [rsp+50h] [rbp-18h]

  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v4 = CertOpenStore((LPCSTR)0xA, 0, 0i64, 0x20000u, a1);
  if ( v4 )
  {
    LODWORD(v10) = 48;
    v6 = -1i64;
    do
      ++v6;
    while ( a2[v6] );
    DWORD2(v11) = 2 * v6 + 2;
    *(_QWORD *)&v12 = a2;
    CTLInStore = CertFindCTLInStore(v4, 0x10001u, 0, 3u, &v10, 0i64);
    if ( !CTLInStore
      && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    {
      LODWORD(pvFindParaa) = GetLastError();
      WPP_SF_SD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xBu,
        (__int64)&WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids,
        a2,
        pvFindParaa);
    }
    CertCloseStore(v4, 0);
    return CTLInStore;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      LODWORD(pvFindPara) = GetLastError();
      WPP_SF_SD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xAu,
        (__int64)&WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids,
        a1,
        pvFindPara);
    }
    return 0i64;
  }
}
// 180043476: variable 'pvFindPara' is possibly undefined
// 18004351C: variable 'pvFindParaa' is possibly undefined

