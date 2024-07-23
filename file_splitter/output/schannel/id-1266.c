// File count: 1266
// Total lines: 73
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeCertificateRequestSize(
        CTls13ServerHandshake *this,
        unsigned __int16 *a2)
{
  __int64 v2; // rsi
  CCredentialGroup *v5; // rsi
  unsigned int updated; // eax
  unsigned int v7; // edi
  __int64 result; // rax
  void *v9; // rcx
  unsigned int v10; // edx
  unsigned int v11; // [rsp+40h] [rbp+8h] BYREF

  v2 = *((_QWORD *)this + 1);
  if ( v2 == -474 )
    return 1359i64;
  *((_QWORD *)this + 16) = v2 + 476;
  *((_WORD *)this + 63) = *(_WORD *)(v2 + 474);
  v5 = *(CCredentialGroup **)(v2 + 80);
  if ( !v5 )
    return 1359i64;
  updated = CCredentialGroup::UpdateIssuerList(v5);
  v7 = updated;
  if ( updated )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids, updated);
    CSslContext::SetError(*((_QWORD *)this + 1), 1251, v7);
    return v7;
  }
  if ( !g_fSendIssuerList )
  {
LABEL_18:
    result = CTls13ServerHandshake::ComputeCertificateRequestExtensionsSize(this);
    if ( (_DWORD)result )
      return result;
    v10 = *(unsigned __int8 *)(*((_QWORD *)this + 1) + 1232i64) + *((unsigned __int16 *)this + 84) + 7;
    if ( v10 <= 0xFFFF )
    {
      *((_WORD *)this + 85) = v10;
      result = 0i64;
      *a2 = v10;
      return result;
    }
    return 1359i64;
  }
  v9 = (void *)*((_QWORD *)this + 22);
  if ( v9 )
  {
    SPExternalFree(v9);
    *((_QWORD *)this + 22) = 0i64;
  }
  v11 = 0;
  *((_WORD *)this + 92) = 0;
  result = CCredentialGroup::DuplicateIssuerList(v5, (unsigned __int8 **)this + 22, &v11);
  if ( !(_DWORD)result )
  {
    if ( v11 > 0xFFFD )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 35i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
      return 87i64;
    }
    *((_WORD *)this + 92) = v11;
    goto LABEL_18;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
// 180092F08: using guessed type int g_fSendIssuerList;
