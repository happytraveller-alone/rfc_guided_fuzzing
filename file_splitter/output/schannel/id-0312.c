//----- (00000001800171B8) ----------------------------------------------------
__int64 __fastcall SpQuerySessionInfo(struct CSslUserContext *a1, struct _SecPkgContext_SessionInfo *a2)
{
  DWORD dwFlags; // eax

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 94i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  a2->dwFlags = 0;
  dwFlags = a2->dwFlags;
  if ( (*((_DWORD *)a1 + 4) & 0x8000i64) == 0 )
    dwFlags = 1;
  a2->dwFlags = dwFlags;
  a2->cbSessionId = *((_DWORD *)a1 + 80);
  memcpy_0(a2->rgbSessionId, (char *)a1 + 324, *((unsigned int *)a1 + 80));
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

