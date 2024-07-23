//----- (000000018004C0AC) ----------------------------------------------------
__int64 __fastcall SslPurgeSessionCache(
        void **a1,
        char *a2,
        unsigned __int64 a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  unsigned __int64 v7; // r14
  int *v8; // rsi
  int v11; // ebx
  int *v12; // rdi
  __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  struct _LUID *v16; // r14
  __int64 v17; // r8
  __int64 v18; // rdx
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rcx
  signed __int64 v23; // rcx
  void *v24; // rsp
  void *v25; // rsp
  _DWORD *v26; // rax
  unsigned int v27; // eax
  unsigned __int16 *v28; // rcx
  __int64 v29; // [rsp+0h] [rbp-30h] BYREF
  int v30; // [rsp+30h] [rbp+0h] BYREF
  __int64 v31; // [rsp+34h] [rbp+4h] BYREF
  int v32; // [rsp+3Ch] [rbp+Ch]
  __int16 v33; // [rsp+40h] [rbp+10h]
  __int16 v34; // [rsp+42h] [rbp+12h]
  int v35; // [rsp+44h] [rbp+14h]
  __int64 v36; // [rsp+48h] [rbp+18h]
  int v37; // [rsp+50h] [rbp+20h]
  int v38; // [rsp+54h] [rbp+24h]
  char v39[8]; // [rsp+58h] [rbp+28h] BYREF
  unsigned int v40; // [rsp+60h] [rbp+30h]
  char v41; // [rsp+68h] [rbp+38h]
  char v42[24]; // [rsp+78h] [rbp+48h] BYREF

  v7 = a4;
  v8 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_6672ee5dd6af34547aa752f96a369f0c_Traceguids);
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v42) )
    goto LABEL_5;
  if ( (v42[8] & 0x40) != 0 )
  {
    if ( (unsigned int)v7 >= 0x18 )
    {
      v12 = &v30;
      v30 = *(_DWORD *)a2;
      v31 = *(_QWORD *)(a2 + 4);
      v37 = *((_DWORD *)a2 + 5);
      v33 = *((_WORD *)a2 + 6);
      v34 = *((_WORD *)a2 + 7);
      v36 = *((unsigned int *)a2 + 4);
      v32 = 0;
      v35 = 0;
      v38 = 0;
      goto LABEL_11;
    }
LABEL_14:
    v11 = -1073741811;
    goto LABEL_15;
  }
  if ( (unsigned int)v7 < 0x28 )
    goto LABEL_14;
  v12 = (int *)a2;
LABEL_11:
  v13 = *((unsigned __int16 *)v12 + 8);
  if ( (v13 & 1) != 0 )
    goto LABEL_14;
  v14 = *((_QWORD *)v12 + 3);
  if ( v14 )
  {
    if ( (_WORD)v13 )
    {
      if ( v14 >= a3 )
        v14 -= a3;
      if ( !v14 || v14 > v7 || v14 + v13 > v7 || v14 < 0x28 || (v14 & 1) != 0 )
        goto LABEL_14;
      *((_WORD *)v12 + 9) = v13;
      *((_QWORD *)v12 + 3) = &a2[v14];
    }
    else
    {
      *((_QWORD *)v12 + 3) = 0i64;
    }
  }
  else if ( (_WORD)v13 )
  {
    goto LABEL_14;
  }
  v11 = (*(__int64 (__fastcall **)(char *))(LsaTable + 128))(v39);
  if ( v11 < 0 )
    goto LABEL_15;
  v16 = (struct _LUID *)(v12 + 1);
  if ( !*(_QWORD *)(v12 + 1) && (v12[8] & 0x30000) == 0 )
    goto LABEL_32;
  if ( !v41 )
  {
    v11 = -1073741727;
    goto LABEL_15;
  }
  if ( !*(_QWORD *)(v12 + 1) )
LABEL_32:
    v16 = (struct _LUID *)v39;
  v17 = *((_QWORD *)v12 + 3);
  if ( v17 )
  {
    v18 = *((unsigned __int16 *)v12 + 8);
    if ( (_WORD)v18 )
    {
      v19 = *((unsigned __int16 *)v12 + 8);
      if ( *(_WORD *)(v17 + 2 * ((unsigned __int64)(v18 - 2) >> 1)) )
      {
        if ( (unsigned __int16)v18 > 0xFFFDu )
          goto LABEL_14;
        v20 = v18 + 2;
        if ( *((unsigned __int16 *)v12 + 9) >= v20 )
        {
          *(_WORD *)(v17 + 2 * (v19 >> 1)) = 0;
          *((_WORD *)v12 + 8) += 2;
          goto LABEL_51;
        }
        if ( v20 <= g_ulMaxStackAllocSize )
        {
          v21 = g_ulAdditionalProbeSize + 10 + v19;
          if ( v21 >= v20 )
          {
            if ( (unsigned int)VerifyStackAvailable(v21) )
            {
              v22 = *((unsigned __int16 *)v12 + 8) + 25i64;
              if ( v22 <= (unsigned __int64)*((unsigned __int16 *)v12 + 8) + 10 )
                v22 = 0xFFFFFFFFFFFFFF0i64;
              v23 = v22 & 0xFFFFFFFFFFFFFFF0ui64;
              v24 = alloca(v23);
              v25 = alloca(v23);
              v8 = &v30;
              if ( &v29 != (__int64 *)-48i64 )
              {
                v30 = 1801679955;
                v8 = (int *)&v31 + 1;
                if ( &v31 != (__int64 *)-4i64 )
                {
LABEL_50:
                  _o_wcsncpy_s(
                    v8,
                    ((unsigned __int64)*((unsigned __int16 *)v12 + 8) + 2) >> 1,
                    *((_QWORD *)v12 + 3),
                    (unsigned __int64)*((unsigned __int16 *)v12 + 8) >> 1);
                  *((_WORD *)v8 + ((unsigned __int64)*((unsigned __int16 *)v12 + 8) >> 1)) = 0;
                  goto LABEL_51;
                }
              }
            }
          }
        }
        if ( (unsigned __int64)*((unsigned __int16 *)v12 + 8) + 10 >= (unsigned __int64)*((unsigned __int16 *)v12 + 8)
                                                                    + 2 )
        {
          v26 = (_DWORD *)((__int64 (*)(void))g_pfnAllocate)();
          if ( !v26 )
            goto LABEL_5;
          *v26 = 1885431112;
          v8 = v26 + 2;
        }
        if ( v8 )
          goto LABEL_50;
LABEL_5:
        v11 = -1073741595;
        goto LABEL_15;
      }
    }
  }
LABEL_51:
  v27 = v12[8];
  if ( (v27 & 0xFFF7FFFF) != 0 )
  {
    v28 = (unsigned __int16 *)v8;
    if ( !v8 )
      v28 = (unsigned __int16 *)*((_QWORD *)v12 + 3);
    v11 = CSessionCacheManager::PurgeCacheEntries(CSessionCacheManager::m_pSessionCacheManager, v27, v16, v40, v28);
    v27 = v12[8];
    if ( (v27 & 2) != 0 )
    {
      SPPurgeIssuerCache();
      v27 = v12[8];
    }
  }
  if ( (v27 & 0x80000) != 0 )
  {
    CertFreeCertificateChainEngine(0i64);
    CertFreeCertificateChainEngine((HCERTCHAINENGINE)1);
  }
  *a5 = 0i64;
  *a6 = 0;
  if ( v8 && *(v8 - 2) == 1885431112 )
    ((void (*)(void))g_pfnFree)();
LABEL_15:
  *a7 = v11;
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080C78: using guessed type __int64 __fastcall _o_wcsncpy_s(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180092620: using guessed type __int64 LsaTable;
// 18004C0AC: using guessed type char var_58[8];

