//----- (000000018001DB80) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::DigestClientHello(
        CTls13ServerContext *this,
        unsigned __int8 *Src,
        SIZE_T uBytes)
{
  unsigned int v3; // ebx
  SIZE_T v4; // rdi
  __int64 v7; // r14
  __int64 v8; // r8
  __int64 v9; // rdx
  __int64 v10; // rax
  __int64 v11; // rcx
  HLOCAL v12; // rax
  unsigned __int8 *v13; // rbp
  unsigned int v14; // edi
  unsigned int v15; // ecx
  __int64 v16; // rax
  unsigned __int64 v17; // r13
  unsigned int v18; // r12d
  const wchar_t **v19; // rsi
  unsigned __int8 v20; // bl
  int v21; // eax
  __int64 v22; // r8
  __int16 v23; // ax
  __int64 v24; // rax
  unsigned int v25; // eax
  unsigned int RandomBits; // ebx
  __int64 v27; // rax
  int v28; // ecx
  __int64 v29; // rax
  __int64 v30; // rbx
  __int64 v31; // rdi
  __int64 v32; // rbp
  __int64 v33; // rsi
  __int64 v34; // rbx
  _WORD *v36; // rax
  int v37; // r14d
  CSessionCacheManager *v38; // rbp
  __int64 *v39; // rdi
  unsigned __int8 v40; // si
  __int64 v41; // rax
  __int64 v42; // rcx
  __int64 v43; // rcx
  unsigned int v44; // r9d
  unsigned int *v45; // r8
  int v46; // r14d
  unsigned int v47; // eax
  __int64 v48; // rax
  __int64 v49; // rax
  unsigned int v50; // [rsp+40h] [rbp-198h] BYREF
  unsigned int v51; // [rsp+44h] [rbp-194h] BYREF
  unsigned int v52; // [rsp+48h] [rbp-190h]
  unsigned int *v53; // [rsp+50h] [rbp-188h] BYREF
  unsigned __int8 *v54; // [rsp+58h] [rbp-180h]
  char v55[272]; // [rsp+60h] [rbp-178h] BYREF
  UCHAR pbBuffer[16]; // [rsp+170h] [rbp-68h] BYREF
  __int128 v57; // [rsp+180h] [rbp-58h]

  v3 = 4;
  v4 = (unsigned int)uBytes;
  v7 = 12i64;
  if ( *((_BYTE *)this + 233) )
    v3 = 12;
  if ( !Src || (unsigned int)uBytes < v3 || !*((_QWORD *)this + 10) )
    return 87i64;
  v50 = 0;
  memset_0(v55, 0, sizeof(v55));
  v9 = *((_QWORD *)this + 110);
  v53 = (unsigned int *)v55;
  v51 = 68;
  if ( v9 )
  {
    (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 110) = 0i64;
  }
  v10 = *((_QWORD *)this + 16);
  *((_DWORD *)this + 218) = v4;
  v11 = *(_QWORD *)(v10 + 24);
  if ( v11 )
  {
    LOBYTE(v8) = 1;
    v12 = (HLOCAL)(*(__int64 (__fastcall **)(__int64, SIZE_T, __int64))(*(_QWORD *)v11 + 48i64))(v11, v4, v8);
  }
  else if ( LsaTable )
  {
    v12 = (HLOCAL)(*(__int64 (__fastcall **)(_QWORD))(LsaTable + 40))((unsigned int)v4);
  }
  else
  {
    v12 = LocalAlloc(0x40u, v4);
  }
  *((_QWORD *)this + 110) = v12;
  if ( !v12 )
    return 14i64;
  memcpy_0(v12, Src, *((unsigned int *)this + 218));
  v13 = &Src[v3];
  v14 = v4 - v3;
  v54 = v13;
  v52 = v14;
  RtlAcquireResourceShared(&Resource, 1u);
  *((_WORD *)this + 237) = 0;
  *((_WORD *)this + 254) = 0;
  v15 = (unsigned __int16)word_1800925E8;
  if ( (unsigned __int16)word_1800925E8 <= 0x10u )
  {
    *((_WORD *)this + 237) = word_1800925E8;
    *((_WORD *)this + 254) = word_18009260A;
    memcpy_0((char *)this + 476, &xmmword_1800925EA, 2i64 * v15);
  }
  RtlReleaseResource(&Resource);
  v16 = *((_QWORD *)this + 10);
  v17 = *(_QWORD *)(v16 + 200);
  if ( v17 )
  {
    v18 = *(_DWORD *)(v16 + 196);
    if ( v18 )
    {
      v19 = (const wchar_t **)&off_18007C3B0;
      *((_WORD *)this + 237) = 0;
      v20 = 0;
      do
      {
        if ( v20 < 0xCu )
        {
          v21 = *((unsigned __int16 *)this + 254);
          if ( ((1 << v20) & v21) != 0 )
          {
            *((_WORD *)this + 254) = v21 & ~(1 << v20);
            if ( !IsCngAlgorithmBlacklisted(v17, v18, 4, v19[2], 0i64, 0, 0i64, 1)
              && !IsCngAlgorithmBlacklisted(v17, v18, 4, *v19, 0i64, 0, 0i64, 1)
              && (*((unsigned __int16 *)this + 254) & (1 << v20)) == 0 )
            {
              v22 = *((unsigned __int16 *)this + 237);
              if ( (unsigned int)v22 < 0x10 )
              {
                *((_WORD *)this + v22 + 238) = __ROR2__(*((_WORD *)&unk_18007C390 + 36 * v20), 8);
                v23 = *((_WORD *)this + 254);
                ++*((_WORD *)this + 237);
                *((_WORD *)this + 254) = v23 | (1 << v20);
              }
            }
          }
        }
        v19 += 9;
        ++v20;
        --v7;
      }
      while ( v7 );
      if ( !*((_WORD *)this + 237) )
        return 2148074289i64;
      v14 = v52;
      v13 = v54;
    }
  }
  v24 = *(_QWORD *)this;
  *((_BYTE *)this + 925) = 0;
  v25 = (*(__int64 (__fastcall **)(CTls13ServerContext *, unsigned __int8 *, _QWORD, char *, unsigned int *, unsigned int **, unsigned int *))(v24 + 528))(
          this,
          v13,
          v14,
          (char *)this + 1249,
          &v50,
          &v53,
          &v51);
  RandomBits = v25;
  if ( v25 )
  {
    if ( v25 != -2146892986 && v25 != -2146892953 )
    {
      RandomBits = -2146893048;
      CSslContext::SetErrorAndFatalAlert((__int64)this, 1200, -2146893048, 0xAu);
    }
    goto LABEL_36;
  }
  v27 = *((_QWORD *)this + 10);
  if ( !v27 )
  {
LABEL_46:
    RandomBits = 1359;
    goto LABEL_36;
  }
  v28 = *((_DWORD *)this + 16);
  if ( (v28 & *(_DWORD *)(v27 + 152) & 0x51550) == 0 )
    goto LABEL_47;
  if ( (v28 & 0x1000) != 0 )
  {
    if ( v50 <= 0x20 )
    {
      v38 = CSessionCacheManager::m_pSessionCacheManager;
      *((_BYTE *)this + 1281) = v50;
      if ( v38 )
      {
        while ( 1 )
        {
          if ( (*((_DWORD *)this + 34) & 0x8000i64) != 0 )
          {
            v40 = 0;
            *(_OWORD *)pbBuffer = 0i64;
            v57 = 0i64;
            RandomBits = GenerateRandomBits(pbBuffer, 0x20u);
            if ( RandomBits )
              goto LABEL_36;
            CSessionCacheManager::AcquireCacheTableLock(v42, 0i64, pbBuffer);
            v39 = (__int64 *)((char *)this + 992);
            RandomBits = CSessionCacheManager::CacheRetrieveNewServerItem(
                           v38,
                           *((_DWORD *)this + 16),
                           pbBuffer,
                           (struct CSessionCacheServerItem **)this + 124);
            CSessionCacheManager::ReleaseCacheTableLock(v43, 0i64, pbBuffer);
            if ( RandomBits )
              goto LABEL_36;
            v41 = *((_QWORD *)this + 124);
          }
          else
          {
            v39 = (__int64 *)((char *)this + 992);
            v40 = 1;
            v41 = *((_QWORD *)this + 124);
            if ( !v41 )
              goto LABEL_46;
          }
          v44 = v51;
          v45 = v53;
          v46 = *((_DWORD *)this + 17);
          *((_QWORD *)this + 11) = v41;
          v47 = CCipherMill::ChooseServerCipher(
                  (CCipherMill *)g_cCipherMill,
                  this,
                  v45,
                  v44,
                  *((_DWORD *)this + 16),
                  v40);
          RandomBits = v47;
          if ( !v40 )
            goto LABEL_36;
          if ( !v47 )
            break;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 65i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          }
          v48 = *v39;
          *((_WORD *)this + 48) = 0;
          *((_DWORD *)this + 17) = v46;
          *(_BYTE *)(v48 + 236) = 0;
          *((_QWORD *)this + 17) |= 0x8000ui64;
          (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 240i64))(this);
          *((_QWORD *)this + 11) = 0i64;
        }
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 64i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        v49 = *((_QWORD *)this + 15);
        if ( v49 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        {
          *(_WORD *)(v49 + 64) |= 4u;
          *(_DWORD *)(v49 + 24) = 1;
        }
      }
      else
      {
        RandomBits = 1359;
      }
    }
    else
    {
      RandomBits = 1359;
    }
    goto LABEL_36;
  }
  if ( *((_DWORD *)this + 17) == 71 )
  {
LABEL_47:
    RandomBits = -2146893007;
    CSslContext::SetErrorAndFatalAlert((__int64)this, 11, -2146893007, 0x46u);
    goto LABEL_36;
  }
  *((_QWORD *)this + 17) &= ~0x8000ui64;
  v29 = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)xmmword_180092DD0 + 16i64))(xmmword_180092DD0);
  v30 = v29;
  if ( !v29 )
  {
    RandomBits = 14;
    goto LABEL_36;
  }
  *(_QWORD *)(v29 + 8) = 0i64;
  v31 = v29;
  v32 = v29;
  CSsl3TlsContext::CSsl3TlsContext((CSsl3TlsContext *)(v29 + 40), (__int64)this);
  *(_QWORD *)(v30 + 40) = &CSsl3TlsServerContext::`vftable';
  v33 = v30 + 40;
  *(_QWORD *)(v30 + 968) = *((_QWORD *)this + 116);
  *(_QWORD *)(v30 + 976) = *((_QWORD *)this + 117);
  *(_QWORD *)(v30 + 984) = *((_QWORD *)this + 118);
  *(_WORD *)(v30 + 992) = *((_WORD *)this + 476);
  *(_QWORD *)(v30 + 1000) = *((_QWORD *)this + 120);
  *(_QWORD *)(v30 + 1008) = *((_QWORD *)this + 121);
  *(_QWORD *)(v30 + 1016) = *((_QWORD *)this + 122);
  *(_DWORD *)(v30 + 1024) = *((_DWORD *)this + 246);
  *(_BYTE *)(v30 + 1028) = *((_BYTE *)this + 988);
  *(_QWORD *)(v30 + 1032) = *((_QWORD *)this + 124);
  v34 = v30 + 1040;
  *((_QWORD *)this + 116) = 0i64;
  *((_QWORD *)this + 117) = 0i64;
  *((_QWORD *)this + 118) = 0i64;
  *((_WORD *)this + 476) = 0;
  *((_QWORD *)this + 120) = 0i64;
  *((_QWORD *)this + 121) = 0i64;
  *((_QWORD *)this + 122) = 0i64;
  *((_DWORD *)this + 246) = 0;
  *((_BYTE *)this + 988) = 0;
  *((_QWORD *)this + 124) = 0i64;
  if ( *((_QWORD *)&xmmword_180092DD0 + 1) )
  {
    v36 = (_WORD *)(*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)&xmmword_180092DD0 + 1) + 16i64))(*((_QWORD *)&xmmword_180092DD0 + 1));
    v37 = qword_180092DC0;
LABEL_51:
    if ( v36 && v37 )
    {
      *(_QWORD *)(v34 + 8) = 0i64;
      *(_QWORD *)v34 = &CSslScratchAllocator::`vftable';
      *(_WORD *)(v34 + 16) = v37;
      *(_DWORD *)(v34 + 18) = 0;
      if ( (unsigned __int16)v37 > 4u )
      {
        *(_QWORD *)(v34 + 8) = v36;
        *v36 = 0;
        *(_WORD *)(*(_QWORD *)(v34 + 8) + 2i64) = v37 - 4;
      }
      *(_QWORD *)(v31 + 24) = v34;
    }
    goto LABEL_35;
  }
  if ( byte_180092DE4 )
  {
    v37 = 2048;
    v36 = SPExternalAlloc(0x800u);
    *(_BYTE *)(v31 + 32) = 1;
    goto LABEL_51;
  }
LABEL_35:
  *(_QWORD *)(v31 + 8) = v33;
  RandomBits = 1359;
  *(_QWORD *)(v33 + 128) = v31;
  *(_QWORD *)(*((_QWORD *)this + 16) + 16i64) = *(_QWORD *)(v32 + 8);
  *((_QWORD *)this + 17) |= 0x40000ui64;
LABEL_36:
  if ( v53 != (unsigned int *)v55 )
    (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 16i64))(this);
  return RandomBits;
}
// 18003154B: variable 'v8' is possibly undefined
// 180031708: variable 'v42' is possibly undefined
// 180031737: variable 'v43' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18007C3B0: using guessed type wchar_t *off_18007C3B0;
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
// 18007D508: using guessed type void *CSslScratchAllocator::`vftable';
// 1800925E8: using guessed type __int16 word_1800925E8;
// 1800925EA: using guessed type __int128 xmmword_1800925EA;
// 18009260A: using guessed type __int16 word_18009260A;
// 180092620: using guessed type __int64 LsaTable;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 180092DC0: using guessed type __int64 qword_180092DC0;
// 180092DD0: using guessed type __int128 xmmword_180092DD0;
// 180092DE4: using guessed type char byte_180092DE4;

