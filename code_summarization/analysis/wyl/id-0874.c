//----- (0000000180047244) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetSupportedMTU(CSsl3TlsContext *this, void *a2, int a3)
{
  __int64 result; // rax
  unsigned __int16 v5; // ax
  struct CSslContext *v6; // rcx
  __int16 v7; // r10
  bool v8; // zf
  unsigned int v9; // [rsp+40h] [rbp+8h] BYREF

  if ( *((_BYTE *)this + 233) )
  {
    if ( a3 != 4 )
      return 87i64;
    result = (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned int *, void *))(LsaTable + 80))(0i64, 4i64, &v9, a2);
    if ( (int)result < 0 )
      return result;
    if ( v9 - 200 <= 0xFF38 && (v5 = CSslContext::computeMaxPayload(this, v9)) != 0 )
    {
      v8 = *((_DWORD *)this + 17) == 4;
      *((_WORD *)this + 108) = v7;
      *((_WORD *)this + 109) = v5;
      if ( !v8 )
        return 0i64;
      result = RemotelySetMtu(v6);
      if ( !(_DWORD)result )
        return 0i64;
    }
    else
    {
      return 87i64;
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids);
    return 1359i64;
  }
  return result;
}
// 1800472EA: variable 'v7' is possibly undefined
// 1800472FB: variable 'v6' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
