// File count: 550
// Total lines: 78
-----------------------------------------
__int64 __fastcall LookUpTableFlushComplete(__int64 a1)
{
  unsigned int v1; // edx
  unsigned int v2; // edi
  __int64 v4; // rcx
  __int64 v5; // r9
  __int64 v6; // rdx
  __int64 v7; // rcx
  __int128 v8; // xmm0
  __int64 result; // rax
  int v10; // [rsp+70h] [rbp-29h] BYREF
  int v11; // [rsp+74h] [rbp-25h] BYREF
  int v12; // [rsp+78h] [rbp-21h] BYREF
  int v13; // [rsp+7Ch] [rbp-1Dh] BYREF
  int v14; // [rsp+80h] [rbp-19h] BYREF
  __int64 v15; // [rsp+88h] [rbp-11h] BYREF
  __int64 v16; // [rsp+90h] [rbp-9h] BYREF
  __int64 v17; // [rsp+98h] [rbp-1h] BYREF
  __int128 *v18; // [rsp+A0h] [rbp+7h] BYREF
  __int64 v19; // [rsp+C8h] [rbp+2Fh]
  __int128 v20; // [rsp+D0h] [rbp+37h] BYREF

  v1 = *(_DWORD *)(a1 + 256);
  v2 = 0;
  if ( v1 )
  {
    UpdateInternalStatsOnFlush(a1, v1);
    v6 = *(_QWORD *)(v4 + 272);
    if ( v6 )
    {
      if ( (unsigned int)dword_180091870 > 5
        && (qword_180091880 & 0x200000000000i64) != 0
        && (qword_180091888 & 0x200000000000i64) == qword_180091888 )
      {
        v7 = *(_QWORD *)(*(_QWORD *)(v4 + 328) + 8i64);
        v8 = *(_OWORD *)(v7 - 16);
        v10 = *(_DWORD *)(a1 + 308);
        v11 = *(_DWORD *)(a1 + 304);
        v12 = *(_DWORD *)(a1 + 300);
        v13 = *(_DWORD *)(a1 + 296);
        v14 = *(_DWORD *)(a1 + 292);
        v16 = *(unsigned int *)(a1 + 288);
        v17 = *(_QWORD *)(a1 + 280);
        v18 = &v20;
        v15 = v6;
        v20 = v8;
        _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EventWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>>(
          v7,
          byte_1800849D8,
          0x200000000000i64,
          v5,
          (__int64 *)&v18,
          (__int64)&v17,
          (__int64)&v16,
          (__int64)&v15,
          (__int64)&v14,
          (__int64)&v13,
          (__int64)&v12,
          (__int64)&v11,
          (__int64)&v10);
      }
      *(_OWORD *)(a1 + 272) = 0i64;
      v19 = 0i64;
      *(_OWORD *)(a1 + 288) = 0i64;
      *(_QWORD *)(a1 + 304) = v19;
    }
    do
      result = FlushLookUpTableBucket(a1, v2++);
    while ( v2 < 0x20 );
  }
  return result;
}
// 180040D57: variable 'v4' is possibly undefined
// 180040E5C: variable 'v5' is possibly undefined
// 1800849D8: using guessed type unsigned __int8 byte_1800849D8[219];
// 180091880: using guessed type __int64 qword_180091880;
// 180091888: using guessed type __int64 qword_180091888;
