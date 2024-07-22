//----- (0000000180046E2C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::QuerySupportedMTU(CSsl3TlsContext *this, void *a2)
{
  bool v2; // zf
  unsigned int v3; // ebx
  int v5; // [rsp+40h] [rbp+8h] BYREF

  v2 = *((_BYTE *)this + 233) == 0;
  v3 = 1359;
  v5 = *((unsigned __int16 *)this + 108);
  if ( v2 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids);
  }
  else
  {
    return (*(unsigned int (__fastcall **)(_QWORD, __int64, void *, int *))(LsaTable + 72))(0i64, 4i64, a2, &v5);
  }
  return v3;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

