//----- (0000000180014940) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetPMTU(CSsl3TlsContext *this, struct _SecBuffer *const a2)
{
  unsigned __int16 *pvBuffer; // rax
  int v4; // r10d
  unsigned __int16 v5; // ax
  __int64 v6; // rcx
  __int16 v7; // r10

  if ( !*((_BYTE *)this + 233) || !a2 )
    return 0i64;
  if ( a2->BufferType == 24 && a2->cbBuffer == 2 && (pvBuffer = (unsigned __int16 *)a2->pvBuffer) != 0i64 )
  {
    v4 = *pvBuffer;
    if ( (unsigned __int16)v4 >= 0xC8u )
    {
      v5 = CSslContext::computeMaxPayload(this, v4);
      if ( v5 )
      {
        *(_WORD *)(v6 + 216) = v7;
        *(_WORD *)(v6 + 218) = v5;
        return 0i64;
      }
    }
    return 87i64;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 97i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    return 2148074278i64;
  }
}
// 18003D982: variable 'v7' is possibly undefined
// 18003D982: variable 'v6' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

