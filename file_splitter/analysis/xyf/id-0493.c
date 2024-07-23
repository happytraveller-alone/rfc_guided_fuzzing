//----- (00000001800236B0) ----------------------------------------------------
void __fastcall DefaultEccCurveWatchParamKey(void *a1, char a2)
{
  BYTE *lpData; // rbx
  CCipherMill *v5; // rcx
  HLOCAL v6; // rdi
  DWORD cbData; // [rsp+40h] [rbp+8h] BYREF
  DWORD Type; // [rsp+50h] [rbp+18h] BYREF

  cbData = 0;
  if ( WatchParamKeyHelper((char *)a1) )
    goto LABEL_10;
  if ( RegQueryValueExW(*((HKEY *)a1 + 2), L"EccCurves", 0i64, &Type, 0i64, &cbData) )
    goto LABEL_10;
  if ( !cbData )
    goto LABEL_10;
  if ( Type != 7 )
    goto LABEL_10;
  lpData = (BYTE *)LocalAlloc(0x40u, cbData);
  if ( !lpData )
    goto LABEL_10;
  if ( RegQueryValueExW(*((HKEY *)a1 + 2), L"EccCurves", 0i64, &Type, lpData, &cbData) )
    goto LABEL_15;
  v6 = g_pbDefaultEccCurveList;
  if ( g_pbDefaultEccCurveList && g_cbDefaultEccCurveList )
  {
    if ( g_cbDefaultEccCurveList != cbData || memcmp_0(g_pbDefaultEccCurveList, lpData, cbData) )
    {
      LocalFree(v6);
      goto LABEL_8;
    }
LABEL_15:
    LocalFree(lpData);
    goto LABEL_10;
  }
LABEL_8:
  g_cbDefaultEccCurveList = cbData;
  g_pbDefaultEccCurveList = lpData;
  if ( !a2 )
    CCipherMill::BuildCipherMill(v5);
LABEL_10:
  NotifyWNFConfigChangeEvent(WNF_SCH_ECC_RELOAD);
}
// 1800237B1: variable 'v5' is possibly undefined
// 180092790: using guessed type unsigned int g_cbDefaultEccCurveList;

