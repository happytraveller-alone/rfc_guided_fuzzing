//----- (00000001800511B0) ----------------------------------------------------
__int64 __fastcall OpenClientKeyHandleCallback(unsigned __int64 a1, char a2, int *a3, __int64 a4)
{
  unsigned int v4; // ebx
  char v8; // r14
  CCipherMill *v9; // rcx
  int v10; // r12d
  unsigned int v11; // ecx
  int v12; // r14d
  _QWORD *v13; // rax
  _QWORD *v14; // r15
  int v15; // r10d
  __int64 v16; // r14
  int v17; // r10d
  int v18; // eax
  unsigned int v19; // r10d
  __int64 v20; // rcx
  __int128 v21; // xmm0
  DWORD v22; // r13d
  unsigned int v23; // esi
  DWORD v24; // ebx
  __int64 v25; // rdx
  const WCHAR *v26; // r9
  unsigned int v27; // eax
  const WCHAR *v28; // r8
  bool v29; // zf
  CCipherMill *v30; // rcx
  CCipherMill *v31; // rcx
  int v32; // eax
  unsigned __int64 v33; // r8
  unsigned __int64 *v34; // r15
  void *v35; // rcx
  int v37; // [rsp+48h] [rbp-29h] BYREF
  LPCWSTR pszProviderName; // [rsp+50h] [rbp-21h]
  LPCWSTR pszKeyName; // [rsp+58h] [rbp-19h]
  NCRYPT_KEY_HANDLE phKey; // [rsp+60h] [rbp-11h] BYREF
  int v41; // [rsp+68h] [rbp-9h]
  int v42; // [rsp+6Ch] [rbp-5h]
  unsigned __int64 v43; // [rsp+70h] [rbp-1h] BYREF
  __int64 v44; // [rsp+78h] [rbp+7h]
  __int128 v45; // [rsp+80h] [rbp+Fh]

  pszKeyName = 0i64;
  v4 = 0;
  pszProviderName = 0i64;
  v37 = 0;
  phKey = 0i64;
  v43 = 0i64;
  v8 = a2;
  if ( !(unsigned int)SchannelInit(1) || !a3 || !a4 )
    return 1359i64;
  *(_DWORD *)a4 = 0;
  *(_QWORD *)(a4 + 8) = 0i64;
  *(_DWORD *)(a4 + 4) = 0;
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
    v9 = WPP_GLOBAL_Control;
  }
  v10 = 8;
  if ( *((_QWORD *)a3 + 1) )
  {
    *(_DWORD *)(a4 + 4) = 1;
    v11 = 36 * a1;
    *(_DWORD *)a4 = 36 * a1;
    v12 = v8 & 4;
    if ( v12 )
    {
      v11 += 8;
      *(_DWORD *)a4 = v11;
    }
    v13 = SPExternalAlloc(v11);
    *(_QWORD *)(a4 + 8) = v13;
    v14 = v13;
    if ( v13 )
    {
      if ( v12 )
      {
        *v13 = **((_QWORD **)a3 + 1);
        v14 = v13 + 1;
      }
      v15 = *a3;
      v16 = *((_QWORD *)a3 + 1) + 8i64;
      v44 = 0i64;
      v17 = v15 - 8;
      if ( a1 )
      {
        while ( 1 )
        {
          v18 = *(_DWORD *)(v16 + 20);
          v19 = v17 - *(_DWORD *)v16;
          v20 = *(unsigned int *)(v16 + 36);
          v21 = *(_OWORD *)(v16 + 4);
          v22 = *(_DWORD *)(v16 + 24);
          v23 = *(_DWORD *)(v16 + 28);
          v24 = *(_DWORD *)(v16 + 32);
          v25 = *(unsigned int *)(v16 + 40);
          v16 += 44i64;
          v41 = v18;
          v26 = (const WCHAR *)v16;
          v27 = v20 + 44;
          v42 = v19;
          v45 = v21;
          if ( (unsigned int)v20 >= 0xFFFFFFD4 || (unsigned int)v25 + v27 < v27 )
            break;
          if ( v19 < (unsigned int)v25 + v27 )
          {
            v4 = 1359;
            goto LABEL_66;
          }
          if ( (_DWORD)v20 )
            v16 += v20;
          v28 = (const WCHAR *)v16;
          if ( !(_DWORD)v20 )
            v26 = pszKeyName;
          pszKeyName = v26;
          v29 = (_DWORD)v25 == 0;
          if ( (_DWORD)v25 )
          {
            v16 += v25;
            v29 = (_DWORD)v25 == 0;
          }
          if ( v29 )
            v28 = pszProviderName;
          v30 = WPP_GLOBAL_Control;
          pszProviderName = v28;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_S(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0x25u,
                (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids,
                v26);
              v30 = WPP_GLOBAL_Control;
              v28 = pszProviderName;
            }
            if ( v30 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v30 + 28) & 4) != 0 )
              {
                WPP_SF_S(*((_QWORD *)v30 + 2), 0x26u, (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v28);
                v30 = WPP_GLOBAL_Control;
              }
              if ( v30 != (CCipherMill *)&WPP_GLOBAL_Control )
              {
                if ( (*((_BYTE *)v30 + 28) & 4) != 0 )
                {
                  WPP_SF_D(*((_QWORD *)v30 + 2), 39i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v24);
                  v30 = WPP_GLOBAL_Control;
                }
                if ( v30 != (CCipherMill *)&WPP_GLOBAL_Control )
                {
                  if ( (*((_BYTE *)v30 + 28) & 4) != 0 )
                  {
                    WPP_SF_D(*((_QWORD *)v30 + 2), 40i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v22);
                    v30 = WPP_GLOBAL_Control;
                  }
                  if ( v30 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v30 + 28) & 4) != 0 )
                    WPP_SF_D(*((_QWORD *)v30 + 2), 41i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v23);
                }
              }
            }
          }
          v4 = OpenKeyUsingCng(&phKey, pszKeyName, pszProviderName, v24, v23, 1, &v37);
          if ( v4 )
          {
            if ( v37 )
            {
              v9 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 42i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
LABEL_59:
                v9 = WPP_GLOBAL_Control;
              }
LABEL_60:
              v4 = -2146893043;
              goto LABEL_67;
            }
            phKey = 0i64;
            v4 = OpenKeyUsingCAPI(&v43, pszKeyName, pszProviderName, v22, v23);
            if ( v4 )
            {
              v9 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  43i64,
                  &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids,
                  v4);
                goto LABEL_59;
              }
              goto LABEL_60;
            }
          }
          v31 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 44i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
              v31 = WPP_GLOBAL_Control;
            }
            if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v31 + 28) & 4) != 0 )
              {
                WPP_SF_q(*((_QWORD *)v31 + 2), 0x2Du, (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, phKey);
                v31 = WPP_GLOBAL_Control;
              }
              if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
                WPP_SF_q(*((_QWORD *)v31 + 2), 0x2Eu, (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v43);
            }
          }
          v32 = v41;
          v33 = ++v44;
          *(_OWORD *)v14 = v45;
          *((_DWORD *)v14 + 4) = v32;
          v34 = (_QWORD *)((char *)v14 + 20);
          *v34++ = phKey;
          *v34 = v43;
          v14 = v34 + 1;
          if ( v33 >= a1 )
            goto LABEL_66;
          v17 = v42;
        }
        v4 = 534;
      }
    }
    else
    {
      v4 = 14;
    }
LABEL_66:
    v9 = WPP_GLOBAL_Control;
LABEL_67:
    v8 = a2;
  }
  else
  {
    v4 = 1359;
  }
  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)v9 + 2), 47i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  if ( v4 )
  {
    if ( (v8 & 4) == 0 )
    {
      v35 = *(void **)(a4 + 8);
      if ( v35 )
        SPExternalFree(v35);
      *(_QWORD *)(a4 + 8) = 0i64;
      *(_DWORD *)(a4 + 4) = 0;
      v10 = 0;
    }
    *(_DWORD *)a4 = v10;
    return 0;
  }
  return v4;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

