//----- (00000001800148D0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetSrtpParameters(
        CSsl3TlsContext *this,
        struct _SecBuffer *const a2,
        struct _SecBuffer *const a3)
{
  struct _SEC_SRTP_PROTECTION_PROFILES *pvBuffer; // rsi
  _BYTE *v4; // r14
  __int64 result; // rax
  CCipherMill *v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rax
  int ProfilesSize; // edx
  int v13; // ecx
  int v14; // eax

  pvBuffer = 0i64;
  v4 = 0i64;
  if ( !*((_BYTE *)this + 233) )
  {
    if ( !a2 && !a3 )
      return 0i64;
    v9 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v10 = 84i64;
LABEL_46:
    WPP_SF_(*((_QWORD *)v9 + 2), v10, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    return 2148074278i64;
  }
  v11 = *((_QWORD *)this + 72);
  if ( v11 && *(_QWORD *)(v11 + 56) != v11 + 56 )
    return 0i64;
  if ( !a2 )
    goto LABEL_20;
  if ( a2->BufferType != 19
    || a2->cbBuffer < 4
    || (pvBuffer = (struct _SEC_SRTP_PROTECTION_PROFILES *)a2->pvBuffer) == 0i64 )
  {
    v9 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v10 = 85i64;
    goto LABEL_46;
  }
  ProfilesSize = pvBuffer->ProfilesSize;
  if ( a2->cbBuffer < ProfilesSize + 2 )
  {
    v9 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v10 = 86i64;
    goto LABEL_46;
  }
  result = CSsl3TlsContext::ValidateProtectionProfiles(pvBuffer->ProfilesList, ProfilesSize, 1);
  if ( !(_DWORD)result )
  {
LABEL_20:
    if ( a3 )
    {
      if ( !a2 || a3->BufferType != 20 || a3->cbBuffer < 2 || (v4 = a3->pvBuffer) == 0i64 )
      {
        v9 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v10 = 87i64;
        goto LABEL_46;
      }
      if ( !*v4 || a3->cbBuffer < (unsigned int)(unsigned __int8)*v4 + 1 )
      {
        v9 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v10 = 88i64;
        goto LABEL_46;
      }
    }
    if ( pvBuffer )
      v13 = pvBuffer->ProfilesSize + 2;
    else
      v13 = 0;
    if ( v4 )
      v14 = (unsigned __int8)*v4 + 1;
    else
      v14 = 1;
    if ( (unsigned int)(v13 + v14) > 0xFFFF )
    {
      v9 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v10 = 89i64;
      goto LABEL_46;
    }
    result = CSsl3TlsContext::SetSrtpProtectionProfiles(this, pvBuffer);
    if ( !(_DWORD)result )
    {
      result = (*(__int64 (__fastcall **)(CSsl3TlsContext *, _BYTE *))(*(_QWORD *)this + 440i64))(this, v4);
      if ( !(_DWORD)result )
      {
        CSsl3TlsContext::FreeSelectedSrtpParameters(this);
        return 0i64;
      }
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

