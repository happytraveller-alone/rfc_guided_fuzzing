//----- (0000000180065504) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateBinderEntry(CTls13ClientHandshake *this)
{
  __int64 v2; // rdi
  unsigned int PrfHashDetails; // ebx
  unsigned int v4; // r14d
  __int64 v6; // rcx
  __int64 v7; // rax
  unsigned __int16 v8; // r13
  unsigned int v9; // r12d
  __int64 v10; // r15
  __int64 v11; // rax
  unsigned int HandshakeHash; // eax
  __int64 v13; // rcx
  char v14[4]; // [rsp+58h] [rbp-39h] BYREF
  __int16 v15; // [rsp+5Ch] [rbp-35h] BYREF
  unsigned __int8 v16[4]; // [rsp+60h] [rbp-31h] BYREF
  unsigned __int64 v17[2]; // [rsp+68h] [rbp-29h] BYREF
  unsigned __int8 v18[64]; // [rsp+78h] [rbp-19h] BYREF

  v17[0] = 0i64;
  v2 = *(_QWORD *)(*((_QWORD *)this + 1) + 88i64);
  if ( !v2 )
    return 1359;
  RtlAcquireResourceShared((PRTL_RESOURCE)(v2 + 72), 1u);
  memset_0(v18, 0, sizeof(v18));
  *(_DWORD *)v16 = 0;
  PrfHashDetails = CSessionCacheItem::GetPrfHashDetails((CSessionCacheItem *)v2, v16, 0i64);
  if ( !PrfHashDetails )
  {
    v4 = *(_DWORD *)v16;
    if ( *(_DWORD *)v16 <= 0x40u )
    {
      v6 = *((_QWORD *)this + 1);
      v7 = *(_QWORD *)(v2 + 176);
      v8 = *(_WORD *)(v6 + 34);
      if ( v7 )
      {
        v9 = *(_DWORD *)(v7 + 28);
        v10 = *(_QWORD *)v7;
      }
      else
      {
        v9 = 0;
        v10 = 0i64;
      }
      if ( *(_DWORD *)(v6 + 68) == 100 )
      {
        v11 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 512i64))(v6, 0i64);
        HandshakeHash = SslDuplicateTranscriptHash(v10, v11, v17, 0i64);
      }
      else
      {
        HandshakeHash = SslCreateHandshakeHash(v10, v17, *(unsigned __int16 *)(v6 + 34), v9, 0);
      }
      PrfHashDetails = HandshakeHash;
      if ( !HandshakeHash )
      {
        PrfHashDetails = CTlsRecord::HashPskBinderTranscript(*((CTlsRecord **)this + 4), v17[0]);
        if ( !PrfHashDetails )
        {
          PrfHashDetails = CTls13Context::GenerateBinderData(
                             (CTls13Context *)(*((_QWORD *)this + 1) + 1368i64),
                             v10,
                             *(_QWORD *)(v2 + 16),
                             v17[0],
                             v8,
                             v9,
                             *(const unsigned __int8 **)(v2 + 200),
                             *(unsigned __int8 *)(v2 + 208),
                             v18,
                             v4);
          RtlReleaseResource((PRTL_RESOURCE)(v2 + 72));
          if ( PrfHashDetails )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                27i64,
                WPP_922678f99ae534148d3bb024010f1556_Traceguids,
                PrfHashDetails);
            }
          }
          else
          {
            v13 = *((_QWORD *)this + 4);
            v14[0] = v4;
            v15 = __ROR2__((unsigned __int8)v4 + 1, 8);
            PrfHashDetails = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v13 + 32i64))(
                               v13,
                               2i64,
                               &v15);
            if ( !PrfHashDetails )
            {
              PrfHashDetails = (*(__int64 (__fastcall **)(_QWORD, __int64, char *))(**((_QWORD **)this + 4) + 32i64))(
                                 *((_QWORD *)this + 4),
                                 1i64,
                                 v14);
              if ( !PrfHashDetails )
                PrfHashDetails = (*(__int64 (__fastcall **)(_QWORD, _QWORD, unsigned __int8 *))(**((_QWORD **)this + 4)
                                                                                              + 32i64))(
                                   *((_QWORD *)this + 4),
                                   (unsigned __int16)v4,
                                   v18);
            }
          }
          goto LABEL_7;
        }
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            26i64,
            WPP_922678f99ae534148d3bb024010f1556_Traceguids,
            PrfHashDetails);
      }
    }
    else
    {
      PrfHashDetails = 1359;
    }
  }
  RtlReleaseResource((PRTL_RESOURCE)(v2 + 72));
LABEL_7:
  if ( v17[0] )
    SslFreeObject(v17[0], 0i64);
  return PrfHashDetails;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
// 180098440: using guessed type __int64 __fastcall SslCreateHandshakeHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098558: using guessed type __int64 __fastcall SslDuplicateTranscriptHash(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 180065504: using guessed type char var_90[4];
