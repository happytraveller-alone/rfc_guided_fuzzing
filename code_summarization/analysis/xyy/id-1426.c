//----- (0000000180071FC4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::ParseRsaServerKeyExchange(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        NCRYPT_KEY_HANDLE a4,
        unsigned __int64 *a5)
{
  CSsl3TlsClientContext *v7; // rsi
  unsigned __int8 v9; // r9
  int v10; // ecx
  unsigned __int8 *v11; // rax
  unsigned __int8 v12; // dl
  unsigned int v13; // r9d
  unsigned __int8 *v14; // rcx
  unsigned int v15; // ebx
  unsigned int v16; // ebx
  unsigned __int8 *v17; // rdx
  __int64 v18; // rcx
  unsigned int v19; // ebx
  __int64 v20; // r8
  unsigned __int8 *v21; // r15
  int v22; // r12d
  __int64 v23; // rcx
  int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  __int64 v27; // rcx
  unsigned int v28; // ebx
  DWORD cbSignature; // r14d
  int v30; // eax
  unsigned int v31; // edi
  unsigned __int8 v32; // r9
  int v33; // edx
  int v34; // r14d
  unsigned int *p_pPaddingInfo; // rbx
  DWORD v36; // edi
  unsigned __int64 v37; // rcx
  unsigned __int64 v38; // rax
  void *v39; // rsp
  _DWORD *v40; // rax
  unsigned __int8 *v41; // rdx
  int v42; // eax
  __int64 v43; // [rsp+0h] [rbp-40h] BYREF
  unsigned int v44; // [rsp+40h] [rbp+0h] BYREF
  __int64 pPaddingInfo; // [rsp+48h] [rbp+8h] BYREF
  NCRYPT_KEY_HANDLE hKey; // [rsp+50h] [rbp+10h]
  unsigned __int8 *v47; // [rsp+58h] [rbp+18h]
  NCRYPT_KEY_HANDLE *phKey; // [rsp+60h] [rbp+20h]
  BYTE pbHashValue[40]; // [rsp+68h] [rbp+28h] BYREF

  hKey = a4;
  phKey = a5;
  pPaddingInfo = 0i64;
  v7 = this;
  if ( !a2 )
  {
    *a5 = 0i64;
    return 0i64;
  }
  if ( a3 >= 3 )
  {
    v10 = a2[1] | (*a2 << 8);
    v11 = a2 + 2;
    v12 = a2[2];
    v13 = v10 - 1;
    if ( v12 )
      v13 = v10;
    v14 = v11 + 1;
    if ( v12 )
      v14 = v11;
    v44 = v13;
    v47 = v14;
    v15 = v13 + 3 - (v12 != 0);
    if ( v13 - 64 > 0x40 )
      goto LABEL_51;
    if ( a3 < v15 )
      goto LABEL_51;
    v16 = v15 + 2;
    v17 = &v14[v13];
    if ( a3 < v16 )
      goto LABEL_51;
    v18 = v17[1] | (*v17 << 8);
    v19 = v18 + v16;
    if ( (unsigned int)(v18 - 1) > 3 || a3 < v19 )
      goto LABEL_51;
    v20 = (unsigned int)v18;
    v21 = &v17[v18];
    v22 = 0;
    if ( !(_DWORD)v18 )
      goto LABEL_23;
    v23 = 0i64;
    do
    {
      v24 = v17[v23++ + 2];
      v25 = (v22 << 8) | v24;
      v22 = v25;
      --v20;
    }
    while ( v20 );
    if ( v25 == 1 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && ((unsigned __int8)v25 & *((_BYTE *)WPP_GLOBAL_Control + 28)) != 0 )
      {
        WPP_SF_(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          (unsigned int)(v25 + 15),
          &WPP_ef2bc8f963c43ddcdfece7ee9e95f200_Traceguids);
      }
      v26 = 0;
      if ( !g_fIgnoreExponentOfOne )
        return 2148074281i64;
    }
    else
    {
LABEL_23:
      v26 = 8 * v13;
    }
    v27 = *((_QWORD *)v7 + 165);
    if ( v26 < *(_DWORD *)(v27 + 8) )
      *(_DWORD *)(v27 + 8) = v26;
    v28 = v19 + 2;
    if ( a3 < v28 || (cbSignature = v21[3] + (v21[2] << 8), a3 < cbSignature + v28) )
    {
LABEL_51:
      v9 = 47;
      this = v7;
      goto LABEL_52;
    }
    v30 = CSsl3TlsContext::ComputeRsaServerExchangeHashes((UCHAR *)v7, a2, (_DWORD)v21 + 2 - (_DWORD)a2, pbHashValue);
    v31 = v30;
    if ( v30 )
    {
      v32 = 80;
      v33 = 815;
LABEL_30:
      CSslContext::SetErrorAndFatalAlert((__int64)v7, v33, v30, v32);
      return v31;
    }
    v30 = NCryptVerifySignature(hKey, &pPaddingInfo, pbHashValue, 0x24u, v21 + 4, cbSignature, 2u);
    v31 = v30;
    if ( v30 )
    {
      v32 = 51;
      v33 = 816;
      goto LABEL_30;
    }
    v34 = v44;
    p_pPaddingInfo = 0i64;
    v36 = v44 + 20;
    if ( v44 == -20 )
      goto LABEL_41;
    if ( v36 > (unsigned __int64)g_ulMaxStackAllocSize )
      goto LABEL_41;
    v37 = v36 + g_ulAdditionalProbeSize + 8;
    if ( v37 < v36 || !(unsigned int)VerifyStackAvailable(v37) )
      goto LABEL_41;
    v38 = v44 + 28 + 15i64;
    if ( v38 <= v44 + 28 )
      v38 = 0xFFFFFFFFFFFFFF0i64;
    v39 = alloca(v38 & 0xFFFFFFFFFFFFFFF0ui64);
    p_pPaddingInfo = &v44;
    if ( &v43 == (__int64 *)-64i64 || (v44 = 1801679955, (p_pPaddingInfo = (unsigned int *)&pPaddingInfo) == 0i64) )
    {
LABEL_41:
      if ( v36 + 8 >= v36 )
      {
        v40 = (_DWORD *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)(v36 + 8);
        if ( !v40 )
          return 14i64;
        *v40 = 1885431112;
        p_pPaddingInfo = v40 + 2;
      }
      if ( !p_pPaddingInfo )
        return 14i64;
    }
    v41 = v47;
    p_pPaddingInfo[3] = 8 * v34;
    *p_pPaddingInfo = 518;
    p_pPaddingInfo[1] = 41984;
    p_pPaddingInfo[2] = 826364754;
    p_pPaddingInfo[4] = v22;
    ReverseMemCopy((unsigned __int8 *)p_pPaddingInfo + 20, v41, v34);
    v42 = NCryptImportKey(hProvider, 0i64, L"CAPIPUBLICBLOB", 0i64, phKey, (PBYTE)p_pPaddingInfo, v36, 0);
    v31 = v42;
    if ( v42 )
      CSslContext::SetErrorAndFatalAlert((__int64)v7, 817, v42, 0x33u);
    if ( *(p_pPaddingInfo - 2) == 1885431112 )
      ((void (__fastcall *)(unsigned int *))g_pfnFree)(p_pPaddingInfo - 2);
    return v31;
  }
  v9 = 50;
LABEL_52:
  CSslContext::SetErrorAndFatalAlert((__int64)this, 811, -2146893048, v9);
  return 2148074248i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180092F1C: using guessed type int g_fIgnoreExponentOfOne;

