//----- (0000000180076330) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::DigestSupplementalDataMsg(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  CCipherMill *v6; // rcx
  unsigned __int16 v7; // dx
  unsigned int v8; // ebp
  unsigned __int8 *v9; // r15
  unsigned int v10; // ebp
  int v11; // edx
  int v12; // r9d
  int v13; // eax
  unsigned __int8 *v14; // r15
  unsigned int v15; // r9d
  unsigned __int8 *v16; // rbx
  int v17; // r8d
  unsigned int v18; // r14d
  int v19; // eax
  unsigned __int8 *v20; // rbx
  unsigned int v21; // r8d
  int v22; // esi
  unsigned int v23; // r14d
  int v24; // eax
  __int64 v25; // r9
  unsigned __int8 *v26; // rbx
  unsigned int v27; // esi
  int v28; // r14d
  unsigned int v29; // esi
  int v30; // eax
  const CHAR *v31; // rbx
  unsigned int v32; // r14d
  unsigned int v33; // eax
  __int64 cchWideChar; // r12
  void *v35; // rcx
  WCHAR *v36; // rax
  unsigned int v37; // r14d
  unsigned int v38; // eax
  __int64 v39; // rsi
  void *v40; // rcx
  WCHAR *v41; // rax
  unsigned __int16 v42; // dx
  CCipherMill *v43; // rcx
  unsigned __int16 v44; // dx
  LPWSTR lpWideCharStr; // [rsp+20h] [rbp-38h]

  v6 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xFu, (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids, a3);
    v6 = WPP_GLOBAL_Control;
  }
  if ( (*((_DWORD *)this + 34) & 0x100i64) == 0 || !*((_BYTE *)this + 922) )
  {
    if ( v6 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v6 + 28) & 5) == 0 )
      return 2148074278i64;
    v7 = 16;
    goto LABEL_129;
  }
  if ( *((_QWORD *)this + 116) )
  {
    SPExternalFree(*((void **)this + 116));
    *((_QWORD *)this + 116) = 0i64;
    v6 = WPP_GLOBAL_Control;
  }
  if ( *((_QWORD *)this + 117) )
  {
    SPExternalFree(*((void **)this + 117));
    *((_QWORD *)this + 117) = 0i64;
    v6 = WPP_GLOBAL_Control;
  }
  if ( a3 < 3 )
  {
    if ( v6 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v6 + 28) & 5) == 0 )
      return 2148074278i64;
    v7 = 17;
LABEL_129:
    LODWORD(lpWideCharStr) = -2146893018;
    WPP_SF_DD(
      *((_QWORD *)v6 + 2),
      v7,
      (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids,
      -2146893018,
      lpWideCharStr);
    return 2148074278i64;
  }
  v8 = a2[2] + (*a2 << 16) + (a2[1] << 8);
  v9 = a2 + 3;
  if ( v8 > a3 - 3 )
  {
    if ( v6 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v6 + 28) & 5) == 0 )
      return 2148074278i64;
    v7 = 18;
    goto LABEL_129;
  }
  if ( v8 )
  {
    while ( v8 >= 4 )
    {
      v10 = v8 - 4;
      v11 = v9[1] + (*v9 << 8);
      v12 = v9[2] << 8;
      v13 = v9[3];
      v14 = v9 + 4;
      v15 = v13 + v12;
      if ( v10 < v15 )
      {
        if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
        {
          v7 = 21;
          goto LABEL_129;
        }
        return 2148074278i64;
      }
      v16 = v14;
      v9 = &v14[v15];
      v8 = v10 - v15;
      if ( !v11 )
      {
        if ( v15 < 2 )
        {
          if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_BYTE *)v6 + 28) & 1) != 0 )
            {
              WPP_SF_d(*((_QWORD *)v6 + 2), 0x16u, (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids, v15);
              v6 = WPP_GLOBAL_Control;
            }
            if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
            {
              v7 = 23;
              goto LABEL_129;
            }
          }
        }
        else
        {
          v17 = *v16;
          v18 = v15 - 2;
          v19 = v16[1];
          v20 = v16 + 2;
          v21 = v19 + (v17 << 8);
          if ( v21 > v15 - 2 )
          {
            if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v6 + 28) & 1) != 0 )
              {
                LODWORD(lpWideCharStr) = v15 - 2;
                WPP_SF_dd(
                  *((_QWORD *)v6 + 2),
                  0x18u,
                  (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids,
                  v21,
                  lpWideCharStr);
                v6 = WPP_GLOBAL_Control;
              }
              if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
              {
                v7 = 25;
                goto LABEL_129;
              }
            }
          }
          else
          {
            while ( v18 >= 3 )
            {
              v22 = v20[1];
              v23 = v18 - 3;
              v24 = v20[2];
              v25 = *v20;
              v26 = v20 + 3;
              v27 = v24 + (v22 << 8);
              if ( v27 > v23 )
              {
                if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
                {
                  v7 = 28;
                  goto LABEL_129;
                }
                return 2148074278i64;
              }
              if ( (_DWORD)v25 == 64 )
              {
                if ( v27 < 4 )
                {
                  if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
                  {
                    v7 = 30;
                    goto LABEL_129;
                  }
                }
                else
                {
                  v28 = *v26;
                  v29 = v27 - 2;
                  v30 = v26[1];
                  v31 = (const CHAR *)(v26 + 2);
                  v32 = v30 + (v28 << 8);
                  if ( v32 > v29 )
                  {
                    if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
                    {
                      v7 = 31;
                      goto LABEL_129;
                    }
                  }
                  else
                  {
                    if ( !v32 )
                      goto LABEL_42;
                    v33 = MultiByteToWideChar(0xFDE9u, 0, v31, v32, 0i64, 0);
                    cchWideChar = v33;
                    if ( !v33 )
                    {
                      v43 = WPP_GLOBAL_Control;
                      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
                      {
                        v44 = 32;
                        goto LABEL_80;
                      }
                      return 2148074244i64;
                    }
                    if ( v33 == v32 )
                    {
                      v35 = (void *)*((_QWORD *)this + 116);
                      if ( v35 )
                      {
                        SPExternalFree(v35);
                        *((_QWORD *)this + 116) = 0i64;
                      }
                      v36 = (WCHAR *)SPExternalAlloc(2 * (int)cchWideChar + 2);
                      *((_QWORD *)this + 116) = v36;
                      if ( !v36 )
                      {
                        v43 = WPP_GLOBAL_Control;
                        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
                        {
                          v44 = 34;
                          goto LABEL_80;
                        }
                        return 2148074244i64;
                      }
                      if ( !MultiByteToWideChar(0xFDE9u, 0, v31, cchWideChar, v36, cchWideChar) )
                      {
                        v43 = WPP_GLOBAL_Control;
                        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
                        {
                          v44 = 35;
                          goto LABEL_80;
                        }
                        return 2148074244i64;
                      }
                      v31 += cchWideChar;
                      v29 -= cchWideChar;
                      *(_WORD *)(*((_QWORD *)this + 116) + 2 * cchWideChar) = 0;
                      v6 = WPP_GLOBAL_Control;
LABEL_42:
                      if ( v29 < 2 )
                      {
                        if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
                        {
                          v7 = 36;
                          goto LABEL_129;
                        }
                      }
                      else
                      {
                        v37 = *((unsigned __int8 *)v31 + 1) + (*(unsigned __int8 *)v31 << 8);
                        if ( v37 > v29 - 2 )
                        {
                          if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
                          {
                            v7 = 37;
                            goto LABEL_129;
                          }
                        }
                        else
                        {
                          if ( !v37 )
                            goto LABEL_52;
                          v38 = MultiByteToWideChar(0xFDE9u, 0, v31 + 2, v37, 0i64, 0);
                          v39 = v38;
                          if ( !v38 )
                          {
                            v43 = WPP_GLOBAL_Control;
                            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
                              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
                            {
                              return 2148074244i64;
                            }
                            v44 = 38;
                            goto LABEL_80;
                          }
                          if ( v38 == v37 )
                          {
                            v40 = (void *)*((_QWORD *)this + 117);
                            if ( v40 )
                            {
                              SPExternalFree(v40);
                              *((_QWORD *)this + 117) = 0i64;
                            }
                            v41 = (WCHAR *)SPExternalAlloc(2 * (int)v39 + 2);
                            *((_QWORD *)this + 117) = v41;
                            if ( v41 )
                            {
                              if ( MultiByteToWideChar(0xFDE9u, 0, v31 + 2, v39, v41, v39) )
                              {
                                *(_WORD *)(*((_QWORD *)this + 117) + 2 * v39) = 0;
                                v6 = WPP_GLOBAL_Control;
                                goto LABEL_52;
                              }
                              v43 = WPP_GLOBAL_Control;
                              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
                              {
                                v44 = 41;
                                goto LABEL_80;
                              }
                              return 2148074244i64;
                            }
                            v43 = WPP_GLOBAL_Control;
                            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
                              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
                            {
                              return 2148074244i64;
                            }
                            v44 = 40;
LABEL_80:
                            LODWORD(lpWideCharStr) = -2146893052;
                            WPP_SF_DD(
                              *((_QWORD *)v43 + 2),
                              v44,
                              (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids,
                              -2146893052,
                              lpWideCharStr);
                            return 2148074244i64;
                          }
                          v6 = WPP_GLOBAL_Control;
                          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
                          {
                            v7 = 39;
                            goto LABEL_129;
                          }
                        }
                      }
                    }
                    else
                    {
                      v6 = WPP_GLOBAL_Control;
                      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
                      {
                        v7 = 33;
                        goto LABEL_129;
                      }
                    }
                  }
                }
                return 2148074278i64;
              }
              if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 4) != 0 )
              {
                WPP_SF_D(*((_QWORD *)v6 + 2), 29i64, &WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids, v25);
                v6 = WPP_GLOBAL_Control;
              }
              v20 = &v26[v27];
              v18 = v23 - v27;
              if ( !v18 )
                goto LABEL_52;
            }
            if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v6 + 28) & 1) != 0 )
              {
                WPP_SF_(*((_QWORD *)v6 + 2), 26i64, &WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids);
                v6 = WPP_GLOBAL_Control;
              }
              if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
              {
                v7 = 27;
                goto LABEL_129;
              }
            }
          }
        }
        return 2148074278i64;
      }
LABEL_52:
      if ( !v8 )
      {
        if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 4) != 0 )
        {
          v42 = 42;
          goto LABEL_124;
        }
        return 0i64;
      }
    }
    if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
    {
      v7 = 20;
      goto LABEL_129;
    }
    return 2148074278i64;
  }
  if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 4) != 0 )
  {
    v42 = 19;
LABEL_124:
    LODWORD(lpWideCharStr) = 0;
    WPP_SF_DD(*((_QWORD *)v6 + 2), v42, (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids, 0, lpWideCharStr);
  }
  return 0i64;
}
// 18007686C: variable 'lpWideCharStr' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
