//----- (00000001800152C4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::SetSelectedApplicationProtocol(
        CSsl3TlsClientContext *this,
        unsigned __int8 *const a2,
        unsigned __int16 a3)
{
  __int64 result; // rax
  __int64 v7; // rax
  unsigned __int8 *MatchingApplicationProtocol; // rdi
  _DWORD *v9; // rax

  result = CSsl3TlsContext::ValidateApplicationProtocolList(SecApplicationProtocolNegotiationExt_ALPN, a2, a3, 0);
  if ( !(_DWORD)result )
  {
    v7 = *((_QWORD *)this + 98);
    if ( v7 )
    {
      MatchingApplicationProtocol = CSsl3TlsContext::FindMatchingApplicationProtocol(
                                      (unsigned __int8 *const)(v7 + 6),
                                      *(_WORD *)(v7 + 4),
                                      a2,
                                      a3);
      if ( MatchingApplicationProtocol )
      {
        v9 = (_DWORD *)*((_QWORD *)this + 99);
        if ( v9
          || (v9 = (_DWORD *)(*(__int64 (__fastcall **)(CSsl3TlsClientContext *, __int64))(*(_QWORD *)this + 8i64))(
                               this,
                               264i64),
              (*((_QWORD *)this + 99) = v9) != 0i64) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              69i64,
              &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
              *MatchingApplicationProtocol);
            v9 = (_DWORD *)*((_QWORD *)this + 99);
          }
          *v9 = 1;
          *(_DWORD *)(*((_QWORD *)this + 99) + 4i64) = 2;
          *(_BYTE *)(*((_QWORD *)this + 99) + 8i64) = *MatchingApplicationProtocol;
          memcpy_0(
            (void *)(*((_QWORD *)this + 99) + 9i64),
            MatchingApplicationProtocol + 1,
            *MatchingApplicationProtocol);
          return 0i64;
        }
        else
        {
          return 14i64;
        }
      }
      else
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 68i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        return 2148074343i64;
      }
    }
    else
    {
      return 87i64;
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

