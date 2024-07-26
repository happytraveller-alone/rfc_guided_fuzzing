//----- (0000000180069E18) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::ParseServerHello(
        CTls13ClientHandshake *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  __int64 v4; // rax
  __int64 v5; // rcx
  unsigned int v6; // r15d
  unsigned __int8 v7; // r9
  int v8; // edx
  unsigned int v9; // ebx
  int v10; // r8d
  __int64 result; // rax
  unsigned int v12; // esi
  unsigned __int8 *v13; // r14
  bool v14; // zf
  __int64 v15; // rax
  void *v16; // rcx
  __int64 v17; // r12
  unsigned int v18; // esi
  char *v19; // r14
  __int64 v20; // rcx
  SIZE_T v21; // rax
  unsigned __int8 *v22; // r14
  unsigned int v23; // esi
  int v24; // r12d
  unsigned int v25; // esi
  unsigned __int8 v26; // r8
  unsigned int v27; // esi
  unsigned int v28; // esi
  char v29; // r13
  unsigned int v30; // eax
  int v31; // eax
  __int64 v32; // r10
  __int64 v33; // rdx
  int v34; // eax
  __int16 v35; // ax
  __int64 v36; // r10
  __int64 v37; // rax
  int v38; // eax
  char v39; // r14
  unsigned int v40; // eax
  __int64 v41; // r11
  __int64 v42; // rsi
  unsigned int PrfHashDetails; // eax
  struct _RTL_RESOURCE *v44; // rcx
  unsigned int v45; // esi
  __int64 v46; // rax
  struct hsel *HashInfo; // rax
  int v48; // r8d
  __int64 v49; // rcx
  __int64 v50; // rcx
  __int64 v51; // rdx
  __int64 v52; // rcx
  __int64 v53; // rax
  unsigned int v54; // r8d
  __int64 v55; // rdx
  unsigned int v56; // eax
  unsigned __int8 v57; // [rsp+30h] [rbp-48h]
  int v58; // [rsp+34h] [rbp-44h]
  enum _eTlsHashAlgorithm v59; // [rsp+88h] [rbp+10h] BYREF
  __int64 v60; // [rsp+98h] [rbp+20h] BYREF

  if ( !a2 || !a3 )
    return 87i64;
  v4 = *((_QWORD *)this + 1);
  *(_WORD *)(v4 + 1838) = 0;
  *(_QWORD *)(v4 + 1840) = 0i64;
  *(_WORD *)(v4 + 1848) = 0;
  v5 = *((_QWORD *)this + 1);
  v58 = *(_DWORD *)(v5 + 68);
  if ( a3 < 2 )
    goto LABEL_92;
  v6 = a2[1] | (*a2 << 8);
  if ( v6 < 0x300 )
  {
LABEL_7:
    v7 = 70;
LABEL_8:
    v8 = 100;
LABEL_9:
    v9 = -2146893048;
LABEL_10:
    v10 = v9;
LABEL_11:
    CSslContext::SetErrorAndFatalAlert(v5, v8, v10, v7);
    return v9;
  }
  if ( *(_BYTE *)(v5 + 233) )
  {
    if ( v6 < 0xFEFD )
      goto LABEL_7;
  }
  else if ( v6 > 0x303 )
  {
    goto LABEL_7;
  }
  if ( a3 - 2 < 0x20 )
  {
LABEL_92:
    v7 = 50;
    goto LABEL_8;
  }
  v12 = a3 - 34;
  *(_OWORD *)(v5 + 304) = *(_OWORD *)(a2 + 2);
  v13 = a2 + 34;
  *(_OWORD *)(v5 + 320) = *(_OWORD *)(a2 + 18);
  v14 = RtlCompareMemory((const void *)(*((_QWORD *)this + 1) + 304i64), &unk_1800858B0, 0x20ui64) == 32;
  v15 = *((_QWORD *)this + 1);
  LOBYTE(v60) = v14;
  if ( v14 )
  {
    *(_DWORD *)(v15 + 68) = 100;
    CSslContext::SetEphemeralKey(*((CSslContext **)this + 1), 0i64);
    v16 = (void *)*((_QWORD *)this + 7);
    if ( v16 )
    {
      SPExternalFree(v16);
      *((_QWORD *)this + 7) = 0i64;
    }
  }
  else
  {
    *(_DWORD *)(v15 + 68) = 70;
  }
  if ( !v12 )
    goto LABEL_20;
  v17 = *v13;
  v18 = v12 - 1;
  v19 = (char *)(v13 + 1);
  if ( v18 < (unsigned int)v17 || (unsigned __int8)v17 > 0x20u )
    goto LABEL_20;
  v20 = *((_QWORD *)this + 1);
  if ( (_BYTE)v17 != *(_BYTE *)(v20 + 1649)
    || (v21 = RtlCompareMemory((const void *)(v20 + 1617), v19, (unsigned int)v17), LOBYTE(v59) = 1, v21 != v17) )
  {
    LOBYTE(v59) = 0;
  }
  v22 = (unsigned __int8 *)&v19[v17];
  v23 = v18 - v17;
  if ( v23 < 2 || (v24 = v22[1] | (*v22 << 8), (v25 = v23 - 2) == 0) )
  {
LABEL_20:
    v8 = 100;
LABEL_21:
    v5 = *((_QWORD *)this + 1);
    v7 = 50;
    goto LABEL_9;
  }
  v26 = v22[2];
  v27 = v25 - 1;
  v57 = v26;
  if ( v27 < 2 )
  {
    v29 = 0;
  }
  else
  {
    v28 = v27 - 2;
    v29 = 1;
    if ( v28 != (v22[4] | (v22[3] << 8)) )
    {
      v8 = 106;
      goto LABEL_21;
    }
    v30 = CTlsExt::ParseTlsExtensions(*((_QWORD *)this + 2), v22 + 5, v28, 2);
    v9 = v30;
    if ( v30 )
    {
      if ( v30 == -2146893007 )
        return v9;
      v5 = *((_QWORD *)this + 1);
      v7 = 50;
      v8 = 106;
      goto LABEL_10;
    }
    v26 = v57;
  }
  if ( !*(_BYTE *)(*((_QWORD *)this + 2) + 27i64) )
  {
    if ( !*(_QWORD *)(*((_QWORD *)this + 1) + 80i64) )
      return 2148074244i64;
    v31 = ConvertSslVersionToSchannelProtocol(v6);
    v34 = *(_DWORD *)(v33 + 152) & v31 & 0xA2AA0;
    if ( !v34 )
    {
      CSslContext::SetErrorAndFatalAlert(v32, 105, -2146893007, 0x46u);
      return 2148074289i64;
    }
    *(_DWORD *)(v32 + 64) = v34;
    v35 = ConvertSchannelProtocolToSsl(v34);
    *(_WORD *)(v36 + 34) = v35;
  }
  v5 = *((_QWORD *)this + 1);
  if ( *(_DWORD *)(v5 + 64) == 0x2000 )
  {
    if ( !v29 )
    {
      v7 = 50;
      v8 = 106;
      goto LABEL_9;
    }
    if ( v26 )
    {
      v7 = 30;
      v9 = -2146893018;
      v8 = 104;
      goto LABEL_10;
    }
    if ( !(_BYTE)v59 )
    {
      v7 = 47;
      v9 = -2146893018;
      v8 = 103;
      goto LABEL_10;
    }
    if ( v58 == 71 )
    {
      if ( (_BYTE)v60 )
      {
        v7 = 10;
        v9 = -2146893018;
        v8 = 109;
        goto LABEL_10;
      }
      if ( (*(_BYTE *)(v5 + 32) & 1) != 0 && (v37 = *(_QWORD *)(v5 + 8)) != 0 )
        v38 = *(_DWORD *)(v37 + 28);
      else
        v38 = 0;
      if ( v38 != v24 )
      {
LABEL_61:
        v7 = 47;
        v9 = -2146893018;
        v8 = 100;
        goto LABEL_10;
      }
LABEL_90:
      v56 = CTls13ClientContext::SetServerKeyShare(*((CTls13ClientContext **)this + 1));
      v9 = v56;
      if ( !v56 )
        return v9;
      v5 = *((_QWORD *)this + 1);
      v7 = 50;
      v10 = v56;
      v8 = 106;
      goto LABEL_11;
    }
    v39 = v60;
    if ( (_BYTE)v60 && *(_WORD *)(v5 + 1836) == *((_WORD *)this + 22) )
      goto LABEL_61;
    v40 = CCipherMill::SetServerHelloCipher((CCipherMill *)v5, *((struct CSsl3TlsClientContext **)this + 1), v24);
    v41 = *((_QWORD *)this + 1);
    v9 = v40;
    if ( v40 )
    {
      v7 = 40;
      v8 = 107;
LABEL_66:
      v5 = v41;
      goto LABEL_10;
    }
    if ( (*(_DWORD *)(v41 + 136) & 0x8000i64) == 0 )
    {
      v42 = *(_QWORD *)(v41 + 88);
      if ( !v42 )
        return 2148074244i64;
      RtlAcquireResourceShared((PRTL_RESOURCE)(v42 + 72), 1u);
      v59 = TlsHashAlgorithm_None;
      PrfHashDetails = CSessionCacheItem::GetPrfHashDetails((CSessionCacheItem *)v42, 0i64, &v59);
      v44 = (struct _RTL_RESOURCE *)(v42 + 72);
      v45 = PrfHashDetails;
      RtlReleaseResource(v44);
      if ( v45 )
        return v45;
      if ( v59 == TlsHashAlgorithm_None )
        return 2148074244i64;
      v46 = *(_QWORD *)(*((_QWORD *)this + 1) + 8i64);
      if ( !v46 )
        return 2148074244i64;
      HashInfo = GetHashInfo(*(_DWORD *)(v46 + 44));
      if ( !HashInfo )
        return 2148074244i64;
      if ( v48 != *((_DWORD *)HashInfo + 8) )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
          v41 = *((_QWORD *)this + 1);
        }
        v7 = 47;
        v9 = -2146893018;
        v8 = 100;
        goto LABEL_66;
      }
    }
    v60 = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v41 + 224i64))(v41, &v60);
    CSessionCacheManager::AcquireCacheTableLock(v49, *(const unsigned __int16 **)(v60 + 368), 0i64);
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v60 + 72), 1u);
    *(_DWORD *)(v60 + 168) = *(_DWORD *)(*((_QWORD *)this + 1) + 64i64);
    RtlReleaseResource((PRTL_RESOURCE)(v60 + 72));
    CSessionCacheManager::ReleaseCacheTableLock(v50, *(const unsigned __int16 **)(v60 + 368), 0i64);
    *(_BYTE *)(*((_QWORD *)this + 1) + 340i64) = 0;
    if ( !v39 )
    {
LABEL_88:
      LOBYTE(v51) = 1;
      result = (*(__int64 (__fastcall **)(_QWORD, __int64))(**((_QWORD **)this + 1) + 496i64))(
                 *((_QWORD *)this + 1),
                 v51);
      v9 = result;
      if ( (_DWORD)result )
        return result;
      if ( v39 )
        return v9;
      goto LABEL_90;
    }
    v52 = *((_QWORD *)this + 1);
    if ( (*(_BYTE *)(v52 + 32) & 1) != 0 && (v53 = *(_QWORD *)(v52 + 8)) != 0 )
    {
      v54 = *(_DWORD *)(v53 + 28);
    }
    else
    {
      v53 = *(_QWORD *)(v52 + 8);
      v54 = 0;
      if ( !v53 )
      {
        v55 = 0i64;
LABEL_87:
        result = CTls13Context::GenerateClientHelloHash(
                   (CTls13Context *)v52,
                   v55,
                   v54,
                   *(unsigned __int8 **)(v52 + 880),
                   (unsigned int *)(v52 + 872));
        if ( (_DWORD)result )
          return result;
        goto LABEL_88;
      }
    }
    v55 = *(_QWORD *)v53;
    goto LABEL_87;
  }
  if ( v58 != 71 )
    return 0i64;
  CSslContext::SetErrorAndFatalAlert(v5, 11, -2146893007, 0x46u);
  return 2148074289i64;
}
// 18006A084: variable 'v33' is possibly undefined
// 18006A0A0: variable 'v32' is possibly undefined
// 18006A0BA: variable 'v36' is possibly undefined
// 18006A10E: variable 'v26' is possibly undefined
// 18006A1C7: variable 'v41' is possibly undefined
// 18006A264: variable 'v48' is possibly undefined
// 18006A2F0: variable 'v49' is possibly undefined
// 18006A34E: variable 'v50' is possibly undefined
// 18006A3C6: variable 'v51' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];

