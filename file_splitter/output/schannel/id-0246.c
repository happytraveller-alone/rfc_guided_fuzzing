// File count: 246
// Total lines: 77
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::SetTBParameters(CSsl3TlsContext *this, struct _SecBuffer *const a2)
{
  void *v3; // rdi
  __int64 v4; // rdx
  struct _SEC_TOKEN_BINDING *pvBuffer; // rsi
  unsigned int TBParametersSize; // eax
  unsigned int v8; // r8d
  __int64 v9; // rbp
  __int64 (__fastcall *v10)(CSsl3TlsContext *, __int64); // r9
  void *v11; // rax
  CCipherMill *v12; // rcx
  __int64 v13; // rdx

  if ( a2 )
  {
    if ( a2->BufferType == 21 && a2->cbBuffer >= 6 && (pvBuffer = (struct _SEC_TOKEN_BINDING *)a2->pvBuffer) != 0i64 )
    {
      TBParametersSize = CSsl3TlsContext::GetTBParametersSize((struct _SEC_TOKEN_BINDING *const)a2->pvBuffer);
      if ( v8 < TBParametersSize )
      {
        v12 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v13 = 92i64;
      }
      else
      {
        if ( pvBuffer == (struct _SEC_TOKEN_BINDING *)-4i64 )
          return 87i64;
        if ( (unsigned __int16)(pvBuffer->KeyParametersSize - 1) <= 0xFEu )
        {
          v9 = (unsigned int)CSsl3TlsContext::GetTBParametersSize(pvBuffer);
          v11 = (void *)v10(this, v9);
          v3 = v11;
          if ( !v11 )
            return 14i64;
          memcpy_0(v11, pvBuffer, (unsigned int)v9);
          goto LABEL_3;
        }
        v12 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v13 = 90i64;
      }
    }
    else
    {
      v12 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v13 = 91i64;
    }
    WPP_SF_(*((_QWORD *)v12 + 2), v13, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    return 2148074278i64;
  }
  v3 = 0i64;
LABEL_3:
  if ( *((_QWORD *)this + 102) )
    (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
  v4 = *((_QWORD *)this + 103);
  *((_QWORD *)this + 102) = v3;
  if ( v4 )
  {
    if ( *(_QWORD *)(v4 + 8) )
    {
      (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(this, *(_QWORD *)(v4 + 8));
      v4 = *((_QWORD *)this + 103);
    }
    (*(void (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 16i64))(this, v4);
    *((_QWORD *)this + 103) = 0i64;
  }
  return 0i64;
}
// 1800146BC: variable 'v8' is possibly undefined
// 180014707: variable 'v10' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
