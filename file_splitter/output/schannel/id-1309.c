//----- (000000018006728C) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateFinished(__int64 a1)
{
  __int64 result; // rax
  unsigned __int64 FinishedMessageKey; // rdi
  __int64 v4; // r8
  int v5; // esi
  __int64 v6; // rax
  _QWORD *v7; // rcx
  int v8; // eax
  unsigned int v9; // edi
  char v10[64]; // [rsp+30h] [rbp-58h] BYREF

  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(a1, 20, *(_WORD *)(a1 + 82));
  if ( !(_DWORD)result )
  {
    FinishedMessageKey = CTls13Context::GetFinishedMessageKey(
                           (CTls13Context *)(*(_QWORD *)(a1 + 8) + 1000i64),
                           (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 64i64) & 0x800A2AAA) != 0);
    if ( FinishedMessageKey )
    {
      v5 = *(unsigned __int8 *)(a1 + 81);
      v6 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 512i64))(v4, 0i64);
      v7 = *(_QWORD **)(*(_QWORD *)(a1 + 8) + 8i64);
      if ( v7 )
        v7 = (_QWORD *)*v7;
      v8 = SslComputeFinishedHash(v7, FinishedMessageKey, v6, v10, v5, 0);
      v9 = v8;
      if ( v8 )
      {
        CSslContext::SetError(*(_QWORD *)(a1 + 8), 901, v8);
        return v9;
      }
      else
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
        result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, char *))(**(_QWORD **)(a1 + 32) + 32i64))(
                   *(_QWORD *)(a1 + 32),
                   *(unsigned __int8 *)(a1 + 81),
                   v10);
        if ( !(_DWORD)result )
          return (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(a1 + 32) + 40i64))(*(_QWORD *)(a1 + 32));
      }
    }
    else
    {
      return 1359i64;
    }
  }
  return result;
}
// 1800672F8: variable 'v4' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
// 180098538: using guessed type __int64 __fastcall SslComputeFinishedHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);

