// File count: 1277
// Total lines: 81
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeNewSessionTicketSize(
        CTls13ServerHandshake *this,
        unsigned __int16 *a2)
{
  HLOCAL *v2; // r14
  unsigned __int16 *v5; // rbp
  UCHAR *v6; // rax
  UCHAR *v7; // rsi
  ULONG RandomBits; // edi
  __int64 v10; // rcx
  __int64 v11; // rdi
  void *v12; // rcx
  CSsl3TlsServerContext *v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // eax
  __int64 v16; // [rsp+50h] [rbp+8h] BYREF

  v2 = (HLOCAL *)((char *)this + 192);
  if ( *((_QWORD *)this + 24) )
    return 1359i64;
  v5 = (unsigned __int16 *)((char *)this + 200);
  if ( *((_WORD *)this + 100) )
    return 1359i64;
  v6 = (UCHAR *)SPExternalAlloc(0x20u);
  v7 = v6;
  if ( !v6 )
    return 14i64;
  RandomBits = GenerateRandomBits(v6, 0x20u);
  if ( RandomBits )
    goto LABEL_8;
  v10 = *((_QWORD *)this + 1);
  v16 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 232i64))(v10, &v16);
  if ( !v16 )
  {
    RandomBits = 1359;
LABEL_8:
    SPExternalFree(v7);
    return RandomBits;
  }
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(v16 + 72), 1u);
  v11 = v16;
  v12 = *(void **)(v16 + 200);
  if ( v12 )
    SPExternalFree(v12);
  *(_BYTE *)(v11 + 208) = 32;
  *(_QWORD *)(v11 + 200) = v7;
  *(_WORD *)(v16 + 238) = 32;
  RtlReleaseResource((PRTL_RESOURCE)(v16 + 72));
  v13 = (CSsl3TlsServerContext *)*((_QWORD *)this + 1);
  if ( (*((_DWORD *)v13 + 34) & 0x800i64) != 0 )
  {
    v14 = CSsl3TlsServerContext::SerializeAndProtectSessionState(v13, v2, v5);
    if ( v14 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids, v14);
    }
    else
    {
      *(_QWORD *)(*((_QWORD *)this + 1) + 136i64) |= 0x400000ui64;
    }
  }
  if ( *v5 )
  {
    v15 = *v5 + 49;
    if ( v15 > 0xFFFF )
      return 1359i64;
  }
  else
  {
    LOWORD(v15) = 81;
  }
  *((_WORD *)this + 86) = v15;
  *a2 = v15;
  return 0i64;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
