// File count: 1397
// Total lines: 149
---------------------------------------
__int64 __fastcall CTls13ServerContext::VerifyBinder(
        CTls13ServerContext *this,
        unsigned __int8 *a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        unsigned __int16 a5)
{
  int v5; // r14d
  __int64 v8; // rbx
  int v9; // r12d
  unsigned int PrfHashDetails; // esi
  SIZE_T v11; // rbx
  __int64 v12; // rcx
  unsigned int v13; // r15d
  __int64 v14; // r14
  __int64 v15; // rax
  unsigned int HandshakeHash; // eax
  unsigned __int16 v18; // [rsp+50h] [rbp-51h]
  _DWORD Length[3]; // [rsp+54h] [rbp-4Dh] BYREF
  unsigned __int8 Source1[64]; // [rsp+60h] [rbp-41h] BYREF

  v5 = a3;
  if ( !a2 )
    return 87i64;
  if ( !a3 )
    return 87i64;
  if ( !a4 )
    return 87i64;
  v8 = *((_QWORD *)this + 124);
  if ( !v8 )
    return 87i64;
  if ( !*((_QWORD *)this + 110) )
    return 87i64;
  v9 = a4;
  if ( *((_DWORD *)this + 218) < (unsigned int)a4 )
    return 87i64;
  v18 = *((_WORD *)this + 17);
  memset_0(Source1, 0, sizeof(Source1));
  memset(Length, 0, sizeof(Length));
  RtlAcquireResourceShared((PRTL_RESOURCE)(v8 + 72), 1u);
  PrfHashDetails = CSessionCacheItem::GetPrfHashDetails(
                     *((CSessionCacheItem **)this + 124),
                     (unsigned __int8 *)Length,
                     0i64);
  if ( !PrfHashDetails )
  {
    v11 = Length[0];
    if ( Length[0] <= 0x40u )
    {
      if ( Length[0] == v5 )
      {
        v12 = *(_QWORD *)(*((_QWORD *)this + 124) + 176i64);
        if ( v12 )
        {
          v13 = *(_DWORD *)(v12 + 28);
          v14 = *(_QWORD *)v12;
        }
        else
        {
          v13 = 0;
          v14 = 0i64;
        }
        v15 = (*(__int64 (__fastcall **)(CTls13ServerContext *, _QWORD))(*(_QWORD *)this + 512i64))(this, 0i64);
        if ( v15 )
          HandshakeHash = SslDuplicateTranscriptHash(v14, v15, &Length[1], 0i64);
        else
          HandshakeHash = SslCreateHandshakeHash(v14, &Length[1], v18, v13, 0);
        PrfHashDetails = HandshakeHash;
        if ( !HandshakeHash )
        {
          PrfHashDetails = SslHashHandshake(
                             v14,
                             *(_QWORD *)&Length[1],
                             *((_QWORD *)this + 110),
                             (unsigned int)(*((_DWORD *)this + 218) - v9),
                             0);
          if ( !PrfHashDetails )
          {
            PrfHashDetails = CTls13Context::GenerateBinderData(
                               (CTls13ServerContext *)((char *)this + 1000),
                               v14,
                               *(_QWORD *)(*((_QWORD *)this + 124) + 16i64),
                               *(__int64 *)&Length[1],
                               v18,
                               v13,
                               *(const unsigned __int8 **)(*((_QWORD *)this + 124) + 200i64),
                               *(unsigned __int8 *)(*((_QWORD *)this + 124) + 208i64),
                               Source1,
                               v11);
            if ( PrfHashDetails )
            {
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  69i64,
                  &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
                  PrfHashDetails);
              }
            }
            else if ( RtlCompareMemory(Source1, a2, v11) == v11 )
            {
              *((_WORD *)this + 738) = a5;
              *((_QWORD *)this + 17) &= ~0x8000ui64;
            }
            else
            {
              PrfHashDetails = -2146893048;
              CSslContext::SetErrorAndFatalAlert((__int64)this, 1210, -2146893048, 0x2Fu);
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 70i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
              }
            }
          }
        }
      }
      else
      {
        PrfHashDetails = -2146893048;
        CSslContext::SetErrorAndFatalAlert((__int64)this, 1210, -2146893048, 0x2Fu);
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_dd(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x44u,
            (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
            v5,
            v11);
      }
    }
    else
    {
      PrfHashDetails = 1359;
    }
  }
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 124) + 72i64));
  if ( *(_QWORD *)&Length[1] )
    SslFreeObject(*(_QWORD *)&Length[1], 0i64);
  return PrfHashDetails;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098420: using guessed type __int64 __fastcall SslHashHandshake(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098440: using guessed type __int64 __fastcall SslCreateHandshakeHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098558: using guessed type __int64 __fastcall SslDuplicateTranscriptHash(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
