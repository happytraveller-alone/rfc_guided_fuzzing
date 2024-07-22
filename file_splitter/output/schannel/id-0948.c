//----- (000000018004E5F8) ----------------------------------------------------
__int64 __fastcall SpQueryKeyingMaterial(struct CSslUserContext *a1, struct _SecPkgContext_KeyingMaterial_Inproc *a2)
{
  WORD cbContextValue; // [rsp+30h] [rbp-28h]

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 112i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  cbContextValue = a2->cbContextValue;
  return SslExportKeyingMaterial(
           *((_QWORD *)a1 + 11),
           *((_QWORD *)a1 + 54),
           a2->pszLabel,
           0i64,
           0,
           a2->pbContextValue,
           cbContextValue,
           a2->pbKeyingMaterial,
           a2->cbKeyingMaterial,
           0);
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098560: using guessed type __int64 __fastcall SslExportKeyingMaterial(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD, _QWORD, _DWORD, _DWORD);

