// File count: 863
// Total lines: 33
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::QueryCertificateValidationResult(CSsl3TlsContext *this, void *a2)
{
  __int64 v2; // rax
  int v3; // r8d
  int v4; // r9d
  __int64 result; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  int v7; // [rsp+44h] [rbp+Ch]

  v2 = *((_QWORD *)this + 11);
  v3 = *(_DWORD *)(v2 + 216);
  v4 = *(_DWORD *)(v2 + 220);
  if ( (*((_DWORD *)this + 34) & 0x4000i64) != 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 114i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    return 2148074241i64;
  }
  else
  {
    result = 2148074254i64;
    if ( v3 != -2146893042 )
    {
      v6 = v4;
      v7 = v3;
      return (*(__int64 (__fastcall **)(_QWORD, __int64, void *, int *))(LsaTable + 72))(0i64, 8i64, a2, &v6);
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
