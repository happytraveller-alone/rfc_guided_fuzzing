// File count: 93
// Total lines: 219
-----------------------------------------
__int64 __fastcall CCipherMill::BuildCipherSuiteList(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        char a4,
        __int64 a5,
        unsigned int a6,
        __int64 a7,
        _DWORD *a8,
        _QWORD *a9,
        _WORD *a10)
{
  __int64 v11; // rbx
  __int64 v12; // r12
  unsigned int v13; // r13d
  struct _TLS_PARAMETERS *v14; // rdi
  unsigned int v15; // ebp
  _QWORD *v16; // r15
  HLOCAL v17; // rax
  CMasterCipherInfo *v18; // rax
  __int64 v19; // rsi
  __int64 v20; // rdi
  __int64 v21; // rcx
  __int64 v22; // r12
  unsigned int v23; // r15d
  __int64 v24; // rbp
  _WORD *v25; // rax
  unsigned int v26; // ecx
  __int64 v28; // r8
  unsigned int v29; // edx
  char v30; // [rsp+70h] [rbp-68h]
  int v31; // [rsp+74h] [rbp-64h]
  unsigned int v32; // [rsp+78h] [rbp-60h]
  struct _TLS_PARAMETERS *v33; // [rsp+80h] [rbp-58h]
  __int64 v34; // [rsp+88h] [rbp-50h]
  char v35; // [rsp+E0h] [rbp+8h]
  unsigned int v39; // [rsp+100h] [rbp+28h]

  v11 = 0i64;
  v12 = 0i64;
  v30 = 0;
  v13 = 0;
  v34 = 0i64;
  if ( !a5 )
    goto LABEL_57;
  v14 = *(struct _TLS_PARAMETERS **)(a5 + 200);
  v15 = *(_DWORD *)(a5 + 196);
  v33 = v14;
  v39 = v15;
  RtlAcquireResourceShared(&Resource, 1u);
  v16 = a9;
  if ( a9 )
  {
    v17 = SPExternalAlloc(2 * (unsigned int)(unsigned __int16)word_1800925D0);
    *a9 = v17;
    if ( !v17 )
    {
      v13 = 14;
      goto LABEL_46;
    }
  }
  if ( !v15 || (v35 = 1, !IsEcdsaAlgorithmBlacklisted(v14, v15, 0i64, 0, 0, 0i64, 1)) )
    v35 = 0;
  v18 = xmmword_1800925B0;
  if ( *(_BYTE *)(a5 + 172) )
    v18 = *(&xmmword_1800925B0 + 1);
  v19 = 0i64;
  if ( v18 )
  {
    v20 = *(_QWORD *)v18;
    v31 = 0;
    v32 = *((_DWORD *)v18 + 2);
    if ( v32 )
    {
      while ( (unsigned int)v11 < *a8 )
      {
        if ( CCipherMill::IsCipherSuiteAllowed(
               (__int64)g_cCipherMill,
               a2,
               a3,
               a4,
               (*(_DWORD *)(a5 + 156) >> 12) & 1,
               *(_DWORD *)(a5 + 156) & 0x800,
               *(_DWORD *)(a5 + 168),
               *(_DWORD *)(a5 + 164),
               a6,
               v20,
               0i64,
               (unsigned __int64)v33,
               v15,
               1) )
        {
          if ( !v16 || *(_DWORD *)(v20 + 48) != 3 && (*(_DWORD *)(v20 + 8) & 0x3000) == 0 || v12 == *(_QWORD *)v20 )
            goto LABEL_16;
          v22 = *(_QWORD *)(v20 + 848);
          if ( !v22 )
            goto LABEL_22;
          if ( !v30 )
          {
            v23 = 0;
            if ( *(_DWORD *)(v22 + 8) )
            {
              while ( 1 )
              {
                v24 = *(_QWORD *)v22 + 780i64 * v23;
                v25 = (_WORD *)*a9;
                if ( *a9 && (v26 = 0, (_DWORD)v19) )
                {
                  while ( (unsigned __int16)*(_DWORD *)(v24 + 772) != *v25 )
                  {
                    ++v26;
                    ++v25;
                    if ( v26 >= (unsigned int)v19 )
                      goto LABEL_35;
                  }
                }
                else
                {
LABEL_35:
                  if ( (unsigned int)v19 >= (unsigned __int16)word_1800925D0 )
                  {
                    v13 = 1359;
                    goto LABEL_46;
                  }
                  if ( !v39
                    || !IsEcdheAlgorithmBlacklisted(
                          v33,
                          v39,
                          (struct CEccCurveInfo *)(*(_QWORD *)v22 + 780i64 * v23),
                          0i64,
                          1u)
                    && (v35
                     || !IsEcdsaAlgorithmBlacklisted(
                           v33,
                           v39,
                           (const unsigned __int16 *)v24,
                           *(_DWORD *)(v24 + 772),
                           *(_DWORD *)(v24 + 768),
                           0i64,
                           1)) )
                  {
                    *(_WORD *)(*a9 + 2 * v19) = *(_WORD *)(v24 + 772);
                    v19 = (unsigned int)(v19 + 1);
                  }
                }
                if ( ++v23 >= *(_DWORD *)(v22 + 8) )
                {
                  v15 = v39;
                  break;
                }
              }
            }
            v16 = a9;
            v34 = *(_QWORD *)v20;
            v30 = 1;
LABEL_16:
            v21 = 0i64;
            if ( (_DWORD)v11 )
            {
              while ( *(_DWORD *)(v20 + 28) != *(_DWORD *)(a7 + 4 * v21) )
              {
                v21 = (unsigned int)(v21 + 1);
                if ( (unsigned int)v21 >= (unsigned int)v11 )
                  goto LABEL_19;
              }
            }
            else
            {
LABEL_19:
              if ( *(_DWORD *)(v20 + 48) != 3 && (*(_DWORD *)(v20 + 8) & 0x3000) == 0 || (_DWORD)v19 )
              {
                *(_DWORD *)(a7 + 4 * v11) = *(_DWORD *)(v20 + 28);
                v11 = (unsigned int)(v11 + 1);
              }
            }
            goto LABEL_22;
          }
          v28 = 0i64;
          if ( !(_DWORD)v19 )
            goto LABEL_16;
          while ( 1 )
          {
            v29 = 0;
            if ( !*(_DWORD *)(v22 + 8) )
              break;
            while ( *(unsigned __int16 *)(*v16 + 2 * v28) != *(_DWORD *)(780i64 * v29 + *(_QWORD *)v22 + 772) )
            {
              if ( ++v29 >= *(_DWORD *)(v22 + 8) )
                goto LABEL_22;
            }
            v28 = (unsigned int)(v28 + 1);
            if ( (unsigned int)v28 >= (unsigned int)v19 )
              goto LABEL_16;
          }
        }
LABEL_22:
        v20 += 864i64;
        if ( ++v31 >= v32 )
          break;
        v12 = v34;
      }
    }
  }
  *a8 = v11;
  if ( a10 )
    *a10 = v19;
LABEL_46:
  RtlReleaseResource(&Resource);
  if ( !(_DWORD)v11 )
  {
LABEL_57:
    v13 = -2146893007;
    LogCipherMismatchEvent(*(_DWORD *)(a5 + 212), (const unsigned __int16 *)(a5 + 216), a6);
  }
  return v13;
}
// 1800925D0: using guessed type __int16 word_1800925D0;
// 18000706C: using guessed type __int64 arg_20;
