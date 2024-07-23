// File count: 1275
// Total lines: 112
---------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeKeyShareEntrySize(
        __int64 a1,
        _WORD *a2)
{
  __int64 v5; // rcx
  unsigned __int64 v6; // rdx
  unsigned int EphemBlobFromKey; // edi
  CCipherMill *v8; // rcx
  __int64 v9; // rdx
  __int64 *v10; // rsi
  __int64 v11; // rcx
  int v12; // edx
  __int64 v13; // rax
  unsigned __int64 v14; // rdx
  __int16 v15; // r8
  unsigned int v16; // ecx
  unsigned int v17; // [rsp+78h] [rbp+10h] BYREF
  unsigned __int64 v18; // [rsp+80h] [rbp+18h] BYREF

  if ( !a2 )
    return 87i64;
  v5 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)(v5 + 68) == 40 && g_fEnableHelloRetryRequest )
  {
    *a2 = 0;
    return 0i64;
  }
  v6 = *(_QWORD *)(v5 + 112);
  v18 = v6;
  if ( !v6 )
  {
    EphemBlobFromKey = SslCreateEphemeralKey(
                         *(_QWORD *)(a1 + 24),
                         &v18,
                         *(unsigned __int16 *)(v5 + 34),
                         4866i64,
                         *(unsigned __int16 *)(a1 + 44),
                         0,
                         0i64,
                         0,
                         0);
    if ( EphemBlobFromKey )
    {
      v8 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return EphemBlobFromKey;
      v9 = 10i64;
LABEL_12:
      WPP_SF_D(*((_QWORD *)v8 + 2), v9, WPP_922678f99ae534148d3bb024010f1556_Traceguids, EphemBlobFromKey);
      return EphemBlobFromKey;
    }
    CSslContext::SetEphemeralKey(*(CSslContext **)(a1 + 8), v18);
    v6 = v18;
  }
  v10 = (__int64 *)(a1 + 56);
  if ( !*(_QWORD *)(a1 + 56) )
  {
    v11 = *(_QWORD *)(a1 + 24);
    v17 = 0;
    EphemBlobFromKey = GetEphemBlobFromKey(v11, v6, L"ECCPUBLICBLOB", &v17, (unsigned __int8 **)(a1 + 56));
    if ( EphemBlobFromKey )
    {
      v8 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return EphemBlobFromKey;
      v9 = 11i64;
      goto LABEL_12;
    }
  }
  v12 = *(unsigned __int16 *)(a1 + 44);
  v17 = 0;
  EphemBlobFromKey = CCipherMill::GetEccCurveFlags((CCipherMill *)v5, v12, &v17);
  if ( EphemBlobFromKey )
  {
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return EphemBlobFromKey;
    v9 = 12i64;
    goto LABEL_12;
  }
  v13 = *v10;
  if ( *v10 )
  {
    if ( (v17 & 8) != 0 )
    {
      *(_BYTE *)(a1 + 46) = 0;
      v14 = 65531i64;
      v16 = *(_DWORD *)(v13 + 4);
      v15 = 4;
    }
    else
    {
      *(_BYTE *)(a1 + 46) = 1;
      v14 = 65530i64;
      v15 = 5;
      v16 = 2 * *(_DWORD *)(v13 + 4);
    }
    if ( v16 <= v14 )
    {
      *(_DWORD *)(a1 + 48) = (unsigned __int16)v16;
      *a2 = v15 + v16;
      return 0i64;
    }
  }
  return 1359i64;
}
// 180064BB5: variable 'v5' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
// 1800927A0: using guessed type int g_fEnableHelloRetryRequest;
// 180098548: using guessed type __int64 __fastcall SslCreateEphemeralKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _DWORD, _DWORD);
