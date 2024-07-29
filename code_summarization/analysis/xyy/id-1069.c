//----- (0000000180059940) ----------------------------------------------------
__int64 __fastcall BuildLegacySupportedAlgsList(struct CCredentialGroup *a1, unsigned int **a2, unsigned int *a3)
{
  int v3; // ebp
  int v4; // r15d
  unsigned int *v9; // rax
  __int64 v10; // rdx
  __int64 v11; // r9
  __int64 v12; // r13
  __int64 v13; // r12
  unsigned int v14; // esi
  _DWORD *v15; // rax
  int v16; // r8d
  unsigned int v17; // ecx
  int v18; // eax
  _DWORD *v19; // rcx
  __int64 v20; // rdx
  struct hsel *HashInfo; // rax
  struct kexch *KeyExchangeInfo; // rax
  _DWORD *v23; // r15
  unsigned __int8 v24; // al
  int v25; // edx
  _DWORD *v26; // rsi
  unsigned int v27; // eax
  _DWORD *v28; // r15
  int v29; // edx
  int v30; // r8d
  int *v31; // rsi
  __int64 v32; // rbp
  _DWORD *v33; // r15
  int v34; // edx
  int v35; // r8d
  int *v36; // rsi
  __int64 v37; // rbp
  _DWORD *v38; // r15
  int v39; // edx
  int v40; // r8d
  unsigned int v41; // [rsp+20h] [rbp-48h]
  __int64 v42; // [rsp+28h] [rbp-40h]
  int v43; // [rsp+70h] [rbp+8h]
  int v44; // [rsp+88h] [rbp+20h]

  v3 = 0;
  v4 = 0;
  v44 = 0;
  v43 = 0;
  if ( !a1 )
    return 87i64;
  *a3 = 0;
  v9 = (unsigned int *)SPExternalAlloc(0x58u);
  *a2 = v9;
  if ( !v9 )
    return 14i64;
  v10 = *((_QWORD *)a1 + 23);
  v42 = v10;
  v11 = 4i64;
  v12 = 8i64;
  if ( v10 )
  {
    v13 = 0i64;
    v41 = *((_DWORD *)a1 + 44);
    if ( v41 )
    {
      while ( 2 )
      {
        v14 = *(_DWORD *)(v10 + 4 * v13);
        v15 = &unk_180085640;
        v16 = 0;
        v17 = 0;
        while ( v14 != *v15 )
        {
          ++v17;
          v15 = (_DWORD *)((char *)v15 + v11);
          if ( v17 >= 0x11 )
          {
            if ( v17 == 17 )
            {
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  10i64,
                  &WPP_f57d92ef57843aa8f0882fb6fd501a9b_Traceguids,
                  v14);
              }
              SPExternalFree(*a2);
              *a2 = 0i64;
              return 87i64;
            }
            break;
          }
        }
        v18 = *(_DWORD *)(v10 + 4 * v13) & 0xE000;
        switch ( v18 )
        {
          case 24576:
            v19 = &unk_180091108;
            v20 = 8i64;
            do
            {
              if ( *(v19 - 2) == v14
                && *v19 >= *((_DWORD *)a1 + 41)
                && *v19 <= *((_DWORD *)a1 + 42)
                && (*((_DWORD *)a1 + 38) & *(v19 - 10)) != 0 )
              {
                v16 = 1;
              }
              v19 += 14;
              --v20;
            }
            while ( v20 );
            v43 = v4;
            v3 = 1;
            if ( !v16 )
              goto LABEL_24;
            break;
          case 32768:
            v44 = 1;
            HashInfo = GetHashInfo(v14);
            if ( !HashInfo || (*(_DWORD *)HashInfo & *((_DWORD *)a1 + 38)) == 0 )
              goto LABEL_24;
            break;
          case 40960:
            v4 = 1;
            v43 = 1;
            KeyExchangeInfo = GetKeyExchangeInfo(v14);
            if ( !KeyExchangeInfo || (*((_DWORD *)KeyExchangeInfo + 1) & *((_DWORD *)a1 + 38)) == 0 )
            {
LABEL_24:
              v10 = v42;
              goto LABEL_25;
            }
            break;
          default:
LABEL_25:
            v13 = (unsigned int)(v13 + 1);
            if ( (unsigned int)v13 < v41 )
              continue;
            if ( v3 )
              goto LABEL_46;
            goto LABEL_39;
        }
        break;
      }
      v23 = *a2;
      v24 = DoesCredAllowAlgId(*a2, *a3, v14);
      v11 = 4i64;
      if ( !v24 )
      {
        v23[v25] = v14;
        ++*a3;
      }
      v4 = v43;
      goto LABEL_24;
    }
  }
LABEL_39:
  v26 = &g_AvailableCiphers;
  do
  {
    v27 = v26[10];
    if ( v27 >= *((_DWORD *)a1 + 41) && v27 <= *((_DWORD *)a1 + 42) && (*((_DWORD *)a1 + 38) & *v26) != 0 )
    {
      v28 = *a2;
      if ( !DoesCredAllowAlgId(*a2, *a3, v26[8]) )
      {
        v28[v29] = v30;
        ++*a3;
      }
    }
    v26 += 14;
    --v12;
  }
  while ( v12 );
LABEL_46:
  if ( !v44 )
  {
    v31 = (int *)&unk_180091028;
    v32 = 5i64;
    do
    {
      if ( (*(v31 - 6) & *((_DWORD *)a1 + 38)) != 0 )
      {
        v33 = *a2;
        if ( !DoesCredAllowAlgId(*a2, *a3, *v31) )
        {
          v33[v34] = v35;
          ++*a3;
        }
      }
      v31 += 10;
      --v32;
    }
    while ( v32 );
  }
  if ( !v43 )
  {
    v36 = (int *)&g_AvailableExch;
    v37 = 4i64;
    do
    {
      if ( (v36[1] & *((_DWORD *)a1 + 38)) != 0 )
      {
        v38 = *a2;
        if ( !DoesCredAllowAlgId(*a2, *a3, *v36) )
        {
          v38[v39] = v40;
          ++*a3;
        }
      }
      v36 += 16;
      --v37;
    }
    while ( v37 );
    (*a2)[(*a3)++] = 8704;
    (*a2)[(*a3)++] = 8707;
  }
  return 0i64;
}
// 1800599F1: variable 'v11' is possibly undefined
// 180059AEF: variable 'v25' is possibly undefined
// 180059B8E: variable 'v30' is possibly undefined
// 180059B8C: variable 'v29' is possibly undefined
// 180059BD5: variable 'v35' is possibly undefined
// 180059BD3: variable 'v34' is possibly undefined
// 180059C19: variable 'v40' is possibly undefined
// 180059C17: variable 'v39' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
