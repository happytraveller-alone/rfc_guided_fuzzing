// File count: 281
// Total lines: 341
----------------------------------------
__int64 __fastcall SpMarshallSupplementalCredsV5(__int64 a1, unsigned __int8 *a2, unsigned int *a3, void **a4)
{
  void **v4; // rax
  unsigned __int8 *v5; // rsi
  unsigned int v6; // edi
  CCipherMill *v7; // rcx
  SIZE_T v8; // r14
  __int64 v9; // rbp
  __int64 v10; // r15
  unsigned int v11; // r12d
  __int64 v12; // r8
  __int64 v13; // r11
  __int64 v14; // r13
  unsigned int v15; // ebx
  __int64 v16; // rcx
  unsigned __int16 v17; // dx
  __int64 v18; // r10
  _OWORD *v19; // rax
  _QWORD *v20; // rbp
  char *v21; // rbx
  __int64 v22; // rcx
  char *v23; // r15
  unsigned int v24; // r14d
  __int64 v25; // r13
  __int64 v26; // rbx
  __int64 v27; // r12
  __int64 v28; // rcx
  unsigned int v29; // esi
  __int64 v30; // rbp
  __int64 v31; // rbx
  __int64 v32; // r14
  __int64 v34; // r9
  unsigned int v35; // r11d
  __int64 v36; // rcx
  __int64 v37; // r8
  unsigned int v38; // r9d
  __int64 v39; // rcx
  unsigned int v40; // esi
  __int64 v41; // r14
  __int64 v42; // rbx
  unsigned int v43; // r14d
  __int64 v44; // rbp
  __int64 v45; // rbx
  int v46; // [rsp+28h] [rbp-80h]
  __int64 v47; // [rsp+30h] [rbp-78h]
  __int64 v48; // [rsp+38h] [rbp-70h]
  __int64 v49; // [rsp+40h] [rbp-68h]
  __int64 v50; // [rsp+48h] [rbp-60h]
  _OWORD *v51; // [rsp+50h] [rbp-58h]
  int v52; // [rsp+B0h] [rbp+8h]
  unsigned int *v54; // [rsp+C0h] [rbp+18h]

  v54 = a3;
  v4 = a4;
  v5 = a2;
  v6 = 0;
  v7 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
    v7 = WPP_GLOBAL_Control;
    v4 = a4;
    a3 = v54;
  }
  if ( v5 && v4 && a3 )
  {
    v8 = 72i64;
    v46 = 72;
    if ( *((_DWORD *)v5 + 2) )
    {
      v8 = 8i64 * *((unsigned int *)v5 + 2) + 72;
      v46 = 8 * *((_DWORD *)v5 + 2) + 72;
    }
    if ( *((_DWORD *)v5 + 8) )
    {
      v8 += 8i64 * *((unsigned int *)v5 + 8);
      v46 = v8;
    }
    v9 = *((unsigned int *)v5 + 14);
    if ( !(_DWORD)v9 )
    {
LABEL_28:
      v19 = LocalAlloc(0x40u, v8);
      v51 = v19;
      v20 = v19;
      if ( v19 )
      {
        v21 = (char *)v19 + 72;
        *v19 = *(_OWORD *)v5;
        v19[1] = *((_OWORD *)v5 + 1);
        v19[2] = *((_OWORD *)v5 + 2);
        v19[3] = *((_OWORD *)v5 + 3);
        *((_QWORD *)v19 + 8) = *((_QWORD *)v5 + 8);
        if ( *((_DWORD *)v5 + 2) )
        {
          memcpy_0((char *)v19 + 72, *((const void **)v5 + 2), 8i64 * *((unsigned int *)v5 + 2));
          v20[2] = v21;
          *((_DWORD *)v20 + 2) = *((_DWORD *)v5 + 2);
          v21 += 8 * *((unsigned int *)v5 + 2);
        }
        if ( *((_DWORD *)v5 + 8) )
        {
          memcpy_0(v21, *((const void **)v5 + 5), 8i64 * *((unsigned int *)v5 + 8));
          v20[5] = v21;
          *((_DWORD *)v20 + 8) = *((_DWORD *)v5 + 8);
          v21 += 8 * *((unsigned int *)v5 + 8);
        }
        if ( *((_DWORD *)v5 + 14) )
        {
          memcpy_0(v21, *((const void **)v5 + 8), 40i64 * *((unsigned int *)v5 + 14));
          v20[8] = v21;
          v22 = *((unsigned int *)v5 + 14);
          v52 = 0;
          v23 = &v21[40 * v22];
          if ( (_DWORD)v22 )
          {
            v24 = 0;
            do
            {
              v25 = *((_QWORD *)v5 + 8);
              v26 = v20[8];
              v50 = v25;
              v47 = v26;
              v27 = 5i64 * v24;
              if ( *(_DWORD *)(v25 + 40i64 * v24) )
              {
                memcpy_0(v23, *(const void **)(v25 + 40i64 * v24 + 8), 16i64 * *(unsigned int *)(v25 + 40i64 * v24));
                *(_QWORD *)(v26 + 40i64 * v24 + 8) = v23;
                v23 += 16 * *(unsigned int *)(v25 + 40i64 * v24);
                if ( *(_DWORD *)(v25 + 40i64 * v24) )
                {
                  v40 = 0;
                  v41 = v26;
                  do
                  {
                    v42 = 2i64 * v40;
                    memcpy_0(
                      v23,
                      *(const void **)(*(_QWORD *)(v25 + 8 * v27 + 8) + 16i64 * v40 + 8),
                      *(unsigned __int16 *)(*(_QWORD *)(v25 + 8 * v27 + 8) + 16i64 * v40 + 2));
                    ++v40;
                    *(_QWORD *)(*(_QWORD *)(v41 + 8 * v27 + 8) + 8 * v42 + 8) = v23;
                    v23 += *(unsigned __int16 *)(*(_QWORD *)(v25 + 8 * v27 + 8) + 8 * v42 + 2);
                  }
                  while ( v40 < *(_DWORD *)(v25 + 8 * v27) );
                  v5 = a2;
                  v24 = v52;
                  v26 = v47;
                }
              }
              if ( *(_DWORD *)(v25 + 8 * v27 + 20) )
              {
                memcpy_0(v23, *(const void **)(v25 + 8 * v27 + 24), 48i64 * *(unsigned int *)(v25 + 8 * v27 + 20));
                *(_QWORD *)(v26 + 8 * v27 + 24) = v23;
                v28 = *(unsigned int *)(v25 + 8 * v27 + 20);
                v23 += 48 * v28;
                if ( (_DWORD)v28 )
                {
                  v29 = 0;
                  do
                  {
                    v30 = *(_QWORD *)(v25 + 8 * v27 + 24);
                    v48 = v30;
                    v31 = 48i64 * v29;
                    v32 = *(_QWORD *)(v47 + 8 * v27 + 24);
                    v49 = v32;
                    memcpy_0(v23, *(const void **)(v31 + v30 + 16), *(unsigned __int16 *)(v31 + v30 + 10));
                    *(_QWORD *)(v31 + v32 + 16) = v23;
                    v23 += *(unsigned __int16 *)(v31 + v30 + 10);
                    if ( *(_DWORD *)(v31 + v30 + 24) )
                    {
                      memcpy_0(v23, *(const void **)(v31 + v30 + 32), 16i64 * *(unsigned int *)(v31 + v30 + 24));
                      *(_QWORD *)(v31 + v32 + 32) = v23;
                      v43 = 0;
                      v23 += 16 * *(unsigned int *)(v31 + v30 + 24);
                      if ( *(_DWORD *)(v31 + v30 + 24) )
                      {
                        v44 = 48i64 * v29;
                        do
                        {
                          v45 = 2i64 * v43;
                          memcpy_0(
                            v23,
                            *(const void **)(*(_QWORD *)(v48 + v44 + 32) + 16i64 * v43 + 8),
                            *(unsigned __int16 *)(*(_QWORD *)(v48 + v44 + 32) + 16i64 * v43 + 2));
                          ++v43;
                          *(_QWORD *)(*(_QWORD *)(v49 + v44 + 32) + 8 * v45 + 8) = v23;
                          v23 += *(unsigned __int16 *)(*(_QWORD *)(v48 + v44 + 32) + 8 * v45 + 2);
                        }
                        while ( v43 < *(_DWORD *)(v48 + v44 + 24) );
                        v25 = v50;
                        v6 = 0;
                      }
                    }
                    ++v29;
                  }
                  while ( v29 < *(_DWORD *)(v25 + 8 * v27 + 20) );
                  v5 = a2;
                  v20 = v51;
                  v24 = v52;
                }
              }
              v52 = ++v24;
            }
            while ( v24 < *((_DWORD *)v5 + 14) );
            LODWORD(v8) = v46;
          }
        }
        *((_DWORD *)v20 + 12) = *((_DWORD *)v5 + 12);
        *((_DWORD *)v20 + 13) = *((_DWORD *)v5 + 13);
        *((_DWORD *)v20 + 1) = *((_DWORD *)v5 + 1);
        *v54 = v8;
        *a4 = v20;
      }
      else
      {
        v6 = -1073741801;
      }
      v7 = WPP_GLOBAL_Control;
      goto LABEL_47;
    }
    if ( (unsigned int)v9 > 0x10 )
      return 3221225485i64;
    v10 = *((_QWORD *)v5 + 8);
    if ( v10 )
    {
      v11 = 0;
      v8 += 40 * v9;
      v46 = v8;
      while ( 1 )
      {
        v12 = *(unsigned int *)(v10 + 40i64 * v11);
        if ( (_DWORD)v12 )
          break;
LABEL_16:
        v13 = *(unsigned int *)(v10 + 40i64 * v11 + 20);
        if ( (_DWORD)v13 )
        {
          if ( (unsigned int)v13 <= 0x10 )
          {
            v14 = *(_QWORD *)(v10 + 40i64 * v11 + 24);
            if ( v14 )
            {
              v15 = 0;
              v8 += 48 * v13;
              while ( 1 )
              {
                v16 = v14 + 48i64 * v15;
                if ( !*(_WORD *)(v16 + 10) )
                  break;
                v17 = *(_WORD *)(v16 + 10);
                if ( ((*(_WORD *)(v16 + 8) | v17) & 1) != 0
                  || *(_WORD *)(v16 + 8) > v17
                  || v17 == 0xFFFF
                  || !*(_QWORD *)(v16 + 16) && (*(_WORD *)(v16 + 8) || v17) )
                {
                  break;
                }
                v18 = *(unsigned int *)(v16 + 24);
                v8 += *(unsigned __int16 *)(v16 + 10);
                v46 = v8;
                if ( (_DWORD)v18 )
                {
                  if ( (unsigned int)v18 <= 0x10 )
                  {
                    v37 = *(_QWORD *)(v16 + 32);
                    if ( v37 )
                    {
                      v38 = 0;
                      v8 += 16 * v18;
                      while ( 1 )
                      {
                        v39 = *(unsigned __int16 *)(v37 + 16i64 * v38 + 2);
                        if ( !(_WORD)v39
                          || (((unsigned __int16)v39 | *(_WORD *)(v37 + 16i64 * v38)) & 1) != 0
                          || *(_WORD *)(v37 + 16i64 * v38) > (unsigned __int16)v39
                          || (_WORD)v39 == 0xFFFF
                          || !*(_QWORD *)(v37 + 16i64 * v38 + 8) )
                        {
                          break;
                        }
                        v8 += v39;
                        ++v38;
                        v46 = v8;
                        if ( v38 >= (unsigned int)v18 )
                          goto LABEL_26;
                      }
                    }
                  }
                  return 3221225485i64;
                }
LABEL_26:
                if ( ++v15 >= (unsigned int)v13 )
                  goto LABEL_27;
              }
            }
          }
          return 3221225485i64;
        }
LABEL_27:
        if ( ++v11 >= (unsigned int)v9 )
          goto LABEL_28;
      }
      if ( (unsigned int)v12 <= 0x10 )
      {
        v34 = *(_QWORD *)(v10 + 40i64 * v11 + 8);
        if ( v34 )
        {
          v35 = 0;
          v8 += 16 * v12;
          while ( 1 )
          {
            v36 = *(unsigned __int16 *)(v34 + 16i64 * v35 + 2);
            if ( !(_WORD)v36
              || (((unsigned __int16)v36 | *(_WORD *)(v34 + 16i64 * v35)) & 1) != 0
              || *(_WORD *)(v34 + 16i64 * v35) > (unsigned __int16)v36
              || (_WORD)v36 == 0xFFFF
              || !*(_QWORD *)(v34 + 16i64 * v35 + 8) )
            {
              break;
            }
            v8 += v36;
            ++v35;
            v46 = v8;
            if ( v35 >= (unsigned int)v12 )
              goto LABEL_16;
          }
        }
      }
      return 3221225485i64;
    }
  }
  v6 = -1073741811;
LABEL_47:
  if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v7 + 2), 31i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, v6);
  return v6;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
