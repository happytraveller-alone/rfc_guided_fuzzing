//----- (000000018002516C) ----------------------------------------------------
__int64 __fastcall NotifyWNFConfigChangeEvent(struct _WNF_STATE_NAME a1)
{
  if ( g_fEnableConfigChangeNtf )
    ((void (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))RtlPublishWnfStateData)(a1, 0i64, 0i64, 0i64, 0i64);
  return 0i64;
}
// 180080E30: using guessed type __int64 __fastcall RtlPublishWnfStateData(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD);
// 18009278C: using guessed type int g_fEnableConfigChangeNtf;
