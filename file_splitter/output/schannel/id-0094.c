//----- (0000000180007410) ----------------------------------------------------
char __fastcall CCipherMill::IsCipherSuiteAllowed(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        char a4,
        int a5,
        int a6,
        unsigned int a7,
        unsigned int a8,
        int a9,
        __int64 a10,
        const UNICODE_STRING *a11,
        unsigned __int64 a12,
        unsigned int a13,
        char a14)
{
  const wchar_t *v17; // r13
  int v18; // r8d
  _DWORD *v19; // rax
  unsigned int v20; // ecx
  char *v21; // rax
  int v22; // edi
  _DWORD *v23; // rax
  unsigned int v24; // ecx
  _DWORD *v25; // rax
  int v26; // ebp
  _DWORD *v27; // rax
  unsigned int v28; // ecx
  _DWORD *v29; // rcx
  int v30; // esi
  _DWORD *v31; // rcx
  unsigned int v32; // eax
  _DWORD *v33; // rcx
  unsigned int v35; // eax
  CCipherMill *v36; // rcx
  unsigned int v37; // eax
  CCipherMill *v38; // rcx
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned __int16 v41; // dx
  __int64 v42; // rcx
  unsigned __int16 v43; // dx
  bool v44; // bl
  int v45; // r8d
  int v46; // [rsp+20h] [rbp-48h]

  if ( !a10 )
  {
    v17 = L"<NULL>";
LABEL_46:
    v36 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v43 = 10;
    v46 = a9;
    goto LABEL_116;
  }
  v17 = (const wchar_t *)(a10 + 74);
  if ( (*(_DWORD *)(a10 + 8) & a9) == 0 )
    goto LABEL_46;
  if ( (*(_DWORD *)(a10 + 48) == 4) != a5 )
    return 0;
  if ( a6 )
  {
    v35 = *(_DWORD *)(a10 + 40);
    if ( v35 < 0x6604 || v35 >= 0x6801 )
    {
      v37 = v35 - 24576;
      if ( !v37 || (v39 = v37 - 1537) == 0 || (v40 = v39 - 2) == 0 || v40 == 510 )
      {
        v38 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          return 0;
        v41 = 11;
        goto LABEL_113;
      }
    }
    if ( *(_BYTE *)(a10 + 72) || *(_DWORD *)(a10 + 44) == 32771 )
      return 0;
  }
  if ( a8 )
  {
    if ( !a7 )
    {
LABEL_9:
      if ( *(_DWORD *)(a10 + 20) >= a8 )
        goto LABEL_10;
      v36 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        return 0;
      v43 = 14;
      v46 = a8;
LABEL_116:
      v42 = *((_QWORD *)v36 + 2);
LABEL_117:
      WPP_SF_SD(v42, v43, (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids, v17, v46);
      return 0;
    }
  }
  else if ( !a7 )
  {
    if ( *(_DWORD *)(a10 + 40) != 24576 )
    {
      v38 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        return 0;
      v41 = 12;
      goto LABEL_113;
    }
    goto LABEL_10;
  }
  if ( *(_DWORD *)(a10 + 20) > a7 )
  {
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v46 = a7;
    v43 = 13;
    v42 = *((_QWORD *)WPP_GLOBAL_Control + 2);
    goto LABEL_117;
  }
  if ( a8 )
    goto LABEL_9;
LABEL_10:
  v18 = *(_DWORD *)(a10 + 32);
  v19 = &g_AvailableExch;
  v20 = 0;
  while ( *v19 != v18 )
  {
    ++v20;
    v19 += 16;
    if ( v20 >= 4 )
      goto LABEL_16;
  }
  v21 = (char *)&g_AvailableExch + 64 * (unsigned __int64)v20;
  if ( v21 && (a9 & *((_DWORD *)v21 + 1)) == 0 )
  {
    v38 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v41 = 15;
    goto LABEL_113;
  }
LABEL_16:
  v22 = *(_DWORD *)(a10 + 44);
  v23 = &unk_180091028;
  v24 = 0;
  while ( *v23 != v22 )
  {
    ++v24;
    v23 += 10;
    if ( v24 >= 5 )
      goto LABEL_22;
  }
  v25 = (_DWORD *)((char *)&g_AvailableHashes + 40 * v24);
  if ( v25 && (a9 & *v25) == 0 )
  {
    v38 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v41 = 16;
    goto LABEL_113;
  }
LABEL_22:
  v26 = *(_DWORD *)(a10 + 40);
  v27 = &unk_180091100;
  v28 = 0;
  while ( *v27 != v26 )
  {
    ++v28;
    v27 += 14;
    if ( v28 >= 8 )
      goto LABEL_26;
  }
  v29 = (_DWORD *)((char *)&g_AvailableCiphers + 56 * v28);
  if ( v29 && (a9 & 0xF3FFFu & *v29) <= (a9 & 0xF3FFFu) >> 1 )
  {
    v36 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v43 = 17;
    v46 = a9 & 0xF3FFF;
    goto LABEL_116;
  }
LABEL_26:
  v30 = *(_DWORD *)(a10 + 36);
  v31 = &unk_1800913EC;
  v32 = 0;
  while ( *v31 != v30 )
  {
    ++v32;
    v31 += 8;
    if ( v32 >= 5 )
      goto LABEL_32;
  }
  v33 = (_DWORD *)((char *)&g_AvailableSigs + 32 * v32);
  if ( v33 && (a9 & *v33) == 0 )
  {
    v36 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v43 = 18;
    v46 = a9 & 0xF3FFF;
    goto LABEL_116;
  }
LABEL_32:
  if ( a3 )
  {
    v44 = (*(_DWORD *)(a10 + 8) & 0x3000) == 0;
    if ( (a4 & 4) == 0 || !v44 || DoesCredAllowAlgId(a2, a3, v18) )
    {
      if ( (a4 & 1) == 0 || !v44 || DoesCredAllowAlgId(a2, a3, v30) )
      {
        if ( (a4 & 8) == 0 || DoesCredAllowAlgId(a2, a3, v26) )
        {
          if ( (a4 & 2) == 0 || DoesCredAllowAlgId(a2, a3, v22) )
            return 1;
          v36 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          {
            return 0;
          }
          v43 = 22;
          v46 = v22;
        }
        else
        {
          v36 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          {
            return 0;
          }
          v43 = 21;
          v46 = v26;
        }
      }
      else
      {
        v36 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          return 0;
        v43 = 20;
        v46 = v30;
      }
    }
    else
    {
      v36 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        return 0;
      v43 = 19;
      v46 = v45;
    }
    goto LABEL_116;
  }
  if ( !a13 )
    return 1;
  if ( IsCngAlgorithmBlacklisted(a12, a13, 0, (const wchar_t *)(a10 + 330), 0i64, 0, a11, a14) )
  {
    v38 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v41 = 23;
    goto LABEL_113;
  }
  if ( IsCngAlgorithmBlacklisted(a12, a13, 1, (const wchar_t *)(a10 + 458), 0i64, 0, a11, a14) )
  {
    v38 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v41 = 24;
    goto LABEL_113;
  }
  if ( IsCngAlgorithmBlacklisted(
         a12,
         a13,
         2,
         (const wchar_t *)(a10 + 202),
         (wchar_t *)(a10 + 714),
         *(_DWORD *)(a10 + 20),
         a11,
         a14) )
  {
    v38 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 0;
    v41 = 25;
    goto LABEL_113;
  }
  if ( !IsCngAlgorithmBlacklisted(a12, a13, 3, (const wchar_t *)(a10 + 586), 0i64, 0, a11, a14) )
    return 1;
  v38 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v41 = 26;
LABEL_113:
    WPP_SF_S(
      *((_QWORD *)v38 + 2),
      v41,
      (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
      (const wchar_t *)(a10 + 74));
  }
  return 0;
}
// 18003384F: variable 'v45' is possibly undefined
// 1800856E0: using guessed type wchar_t aNull_1[7];

