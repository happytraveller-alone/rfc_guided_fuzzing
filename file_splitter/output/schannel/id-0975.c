// File count: 975
// Total lines: 354
----------------------------------------
__int64 __fastcall SignHashCallback(NCRYPT_HANDLE a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // r14d
  unsigned int v7; // esi
  __int64 v8; // r13
  CCipherMill *v9; // rcx
  unsigned int v10; // r14d
  unsigned int *v11; // rdx
  __int64 v13; // r9
  DWORD v14; // r8d
  DWORD v15; // ebx
  __int64 v16; // rsi
  __int64 v17; // r12
  __int64 v18; // r15
  unsigned int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // eax
  DWORD v22; // ebx
  const wchar_t *v23; // r9
  DWORD v24; // r12d
  BYTE *v25; // r14
  __int64 *v26; // rsi
  DWORD v27; // r15d
  NCRYPT_KEY_HANDLE v28; // r13
  unsigned int v29; // eax
  BYTE *pbSignature; // rax
  CCipherMill *v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // r9
  HCRYPTPROV v34; // r13
  DWORD LastError; // eax
  DWORD v36; // eax
  DWORD v37; // esi
  BYTE *v38; // rax
  void *v39; // rcx
  DWORD cbSignature; // [rsp+28h] [rbp-58h]
  DWORD dwKeySpec; // [rsp+40h] [rbp-40h] BYREF
  HCRYPTHASH phHash; // [rsp+48h] [rbp-38h] BYREF
  DWORD dwFlags; // [rsp+50h] [rbp-30h]
  __int64 v44; // [rsp+58h] [rbp-28h] BYREF
  BYTE pbInput[8]; // [rsp+60h] [rbp-20h] BYREF
  DWORD cbHashValue; // [rsp+68h] [rbp-18h]
  ALG_ID Algid; // [rsp+6Ch] [rbp-14h]
  __int128 v48; // [rsp+70h] [rbp-10h] BYREF

  v4 = a1;
  phHash = 0i64;
  v7 = a2;
  v8 = 0i64;
  if ( (unsigned int)SchannelInit(1) && a3 && a4 )
  {
    *(_QWORD *)a4 = 0i64;
    *(_QWORD *)(a4 + 8) = 0i64;
    v9 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
        v9 = WPP_GLOBAL_Control;
      }
      if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)v9 + 2), 11i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v4);
          v9 = WPP_GLOBAL_Control;
        }
        if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)v9 + 2), 12i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v7);
          v9 = WPP_GLOBAL_Control;
        }
      }
    }
    v10 = *(_DWORD *)a3;
    v11 = *(unsigned int **)(a3 + 8);
    if ( *(_DWORD *)a3 < 0x24u )
      return 2148074264i64;
    v13 = *v11;
    v14 = v11[2];
    dwFlags = v11[1];
    *(_QWORD *)pbInput = *(_QWORD *)(v11 + 3);
    v15 = v11[8];
    v16 = v11[6];
    v17 = v11[7];
    LODWORD(v44) = v11[5];
    *(_QWORD *)&v48 = v11 + 9;
    v18 = (__int64)(v11 + 9);
    Algid = v13;
    dwKeySpec = v14;
    cbHashValue = v15;
    if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
      {
        WPP_SF_D(*((_QWORD *)v9 + 2), 13i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v13);
        v9 = WPP_GLOBAL_Control;
        v14 = dwKeySpec;
      }
      if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
      {
        WPP_SF_D(*((_QWORD *)v9 + 2), 14i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v14);
        v9 = WPP_GLOBAL_Control;
      }
    }
    v19 = v16 + 24;
    if ( (unsigned int)v16 >= 0xFFFFFFE8 )
      return 534i64;
    v20 = v19 + v17;
    if ( v19 + (unsigned int)v17 < v19 )
      return 534i64;
    v21 = v20 + v15;
    if ( v20 + v15 < v20 )
      return 534i64;
    v22 = 0;
    if ( v10 >= v21 )
    {
      if ( (_DWORD)v16 )
        v18 += v16;
      v23 = (const wchar_t *)(v48 & -(__int64)((_DWORD)v16 != 0));
      if ( !(_DWORD)v17 )
      {
LABEL_30:
        v24 = cbHashValue;
        v25 = (BYTE *)(v18 & -(__int64)(cbHashValue != 0));
        if ( a2 )
        {
          dwKeySpec = 0;
          v44 = 0i64;
          v26 = 0i64;
          v48 = 0i64;
          if ( v23 && v25 )
          {
            v27 = dwFlags;
            if ( wcsncmp(v23, L"RSA", 3ui64) )
              goto LABEL_38;
            if ( dwFlags == 8 )
            {
              v26 = (__int64 *)&v48;
              *(_QWORD *)&v48 = v8;
              DWORD2(v48) = cbHashValue;
              goto LABEL_38;
            }
            if ( dwFlags == 2 )
            {
              v26 = &v44;
              v44 = v8;
LABEL_38:
              if ( *(_QWORD *)pbInput )
              {
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  WPP_SF_q(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    0xFu,
                    (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
                }
                v28 = a1;
                v29 = NCryptSetProperty(a1, L"HWND Handle", pbInput, 8u, 0);
                if ( v29
                  && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                {
                  WPP_SF_D(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    16i64,
                    &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids,
                    v29);
                }
              }
              else
              {
                v28 = a1;
              }
              v22 = NCryptSignHash(v28, v26, v25, v24, 0i64, dwKeySpec, &dwKeySpec, dwFlags);
              if ( v22 )
              {
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                {
                  WPP_SF_D(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    17i64,
                    &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids,
                    v22);
                }
                return v22;
              }
              pbSignature = (BYTE *)SPExternalAlloc(dwKeySpec);
              *(_QWORD *)(a4 + 8) = pbSignature;
              if ( !pbSignature )
                return 14i64;
              cbSignature = dwKeySpec;
              *(_DWORD *)a4 = dwKeySpec;
              v22 = NCryptSignHash(v28, v26, v25, v24, pbSignature, cbSignature, &dwKeySpec, v27);
              if ( v22 )
              {
                v31 = WPP_GLOBAL_Control;
                if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
                  || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
                {
                  goto LABEL_99;
                }
                v32 = 18i64;
                goto LABEL_58;
              }
LABEL_96:
              *(_DWORD *)(a4 + 4) = 1;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
              }
              goto LABEL_99;
            }
          }
          return 1359i64;
        }
        if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)v9 + 2), 19i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
          v9 = WPP_GLOBAL_Control;
        }
        if ( *(_QWORD *)pbInput )
        {
          if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
            WPP_SF_q(*((_QWORD *)v9 + 2), 0x14u, (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
          v34 = a1;
          if ( !CryptSetProvParam(a1, 1u, pbInput, 0)
            && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            LastError = GetLastError();
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              21i64,
              &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids,
              LastError);
          }
        }
        else
        {
          v34 = a1;
        }
        if ( !CryptCreateHash(v34, Algid, 0i64, 0, &phHash) )
        {
          v36 = GetLastError();
          v22 = v36;
          v31 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_99;
          }
          v32 = 22i64;
          goto LABEL_76;
        }
        if ( (_DWORD)v44 )
        {
          if ( !CryptHashData(phHash, v25, v24, 0) )
          {
            v36 = GetLastError();
            v22 = v36;
            v31 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
            {
              goto LABEL_99;
            }
            v32 = 24i64;
LABEL_76:
            v33 = v36;
            goto LABEL_59;
          }
        }
        else if ( !CryptSetHashParam(phHash, 2u, v25, 0) )
        {
          v36 = GetLastError();
          v22 = v36;
          v31 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_99;
          }
          v32 = 23i64;
          goto LABEL_76;
        }
        v37 = dwKeySpec;
        if ( CryptSignHashW(phHash, dwKeySpec, 0i64, 0, 0i64, (DWORD *)a4) )
        {
          v38 = (BYTE *)SPExternalAlloc(*(_DWORD *)a4);
          *(_QWORD *)(a4 + 8) = v38;
          if ( !v38 )
          {
            v22 = 14;
            goto LABEL_99;
          }
          if ( CryptSignHashW(phHash, v37, 0i64, 0, v38, (DWORD *)a4) )
            goto LABEL_96;
          v22 = GetLastError();
          v31 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_99;
          }
          v32 = 26i64;
        }
        else
        {
          v22 = GetLastError();
          v31 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_99;
          }
          v32 = 25i64;
        }
LABEL_58:
        v33 = v22;
LABEL_59:
        WPP_SF_D(*((_QWORD *)v31 + 2), v32, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v33);
LABEL_99:
        if ( phHash )
          CryptDestroyHash(phHash);
        if ( v22 )
        {
          v39 = *(void **)(a4 + 8);
          if ( v39 )
          {
            SPExternalFree(v39);
            *(_QWORD *)(a4 + 8) = 0i64;
          }
          *(_DWORD *)a4 = 0;
        }
        return v22;
      }
      if ( (v16 & 1) == 0 )
      {
        v8 = v18;
        v18 += v17;
        goto LABEL_30;
      }
    }
  }
  return 1359i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
