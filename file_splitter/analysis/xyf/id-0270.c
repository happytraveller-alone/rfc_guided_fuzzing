//----- (0000000180015484) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::ValidateApplicationProtocolList(
        enum _SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT a1,
        unsigned __int8 *const a2,
        unsigned __int16 a3,
        int a4)
{
  unsigned __int8 *v4; // rcx
  unsigned __int8 *v5; // rdx
  CCipherMill *v7; // rcx
  __int64 v8; // rdx

  if ( !a2 || a1 != SecApplicationProtocolNegotiationExt_ALPN )
    return 87i64;
  if ( (unsigned __int16)(a3 - 2) > 0xFFFBu )
  {
    v7 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v8 = 74i64;
  }
  else if ( a4 || (unsigned int)*a2 + 1 >= a3 )
  {
    v4 = &a2[a3];
    while ( 1 )
    {
      if ( a2 >= v4 )
        return 0i64;
      if ( !*a2 )
        break;
      v5 = &a2[*a2];
      if ( v5 >= v4 )
        break;
      a2 = v5 + 1;
    }
    v7 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v8 = 76i64;
  }
  else
  {
    v7 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v8 = 75i64;
  }
  WPP_SF_(*((_QWORD *)v7 + 2), v8, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  return 2148074278i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

