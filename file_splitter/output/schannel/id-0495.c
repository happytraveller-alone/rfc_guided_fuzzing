// File count: 495
// Total lines: 859
----------------------------------------
__int64 __fastcall CCipherMill::LoadCipherTables(CCipherMill *this)
{
  __int64 v1; // r14
  unsigned int v2; // ebx
  struct CCipherSuiteInfo *v3; // r13
  wchar_t *v4; // r15
  unsigned int v5; // r12d
  struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *v6; // rax
  unsigned int v7; // ebx
  unsigned int v8; // esi
  __int64 v9; // r15
  char *v10; // rdi
  char *v11; // rax
  __int64 v12; // rdx
  _OWORD *v13; // rcx
  _OWORD *v14; // rax
  __int128 v15; // xmm1
  __int64 v16; // rcx
  unsigned __int16 *v17; // rdi
  unsigned __int8 v18; // r10
  char v19; // r10
  int v20; // eax
  ULONG v21; // eax
  unsigned __int16 *v22; // rdi
  unsigned int v23; // r15d
  unsigned __int16 *v24; // rsi
  int *v25; // rax
  __int64 v26; // rcx
  wchar_t *v27; // rax
  __int64 v28; // rbx
  unsigned int v29; // r12d
  int *v30; // rdi
  unsigned int v31; // esi
  __int64 v32; // r15
  int v33; // ecx
  __int64 v34; // rcx
  unsigned int v35; // ebx
  void **v36; // r8
  unsigned int v37; // ebx
  wchar_t *v38; // rdi
  __int64 v39; // rsi
  unsigned int i; // r11d
  __int64 v41; // rcx
  __int64 v42; // rdx
  __int64 v43; // r9
  char *v44; // r10
  __int64 v45; // rax
  __int128 v46; // xmm0
  __int128 v47; // xmm1
  __int128 v48; // xmm0
  __int128 v49; // xmm1
  __int128 v50; // xmm0
  __int128 v51; // xmm1
  __int128 v52; // xmm0
  __int128 v53; // xmm1
  int v54; // eax
  __int64 v55; // r9
  __int64 v56; // rax
  __int128 v57; // xmm1
  char *v58; // rdx
  __int64 v59; // rax
  __int128 v60; // xmm1
  __int128 v61; // xmm0
  __int128 v62; // xmm1
  __int128 v63; // xmm0
  __int128 v64; // xmm1
  __int128 v65; // xmm0
  __int128 v66; // xmm1
  unsigned int j; // edi
  void *v68; // rcx
  int v69; // ecx
  int *v70; // rax
  __int64 v71; // rdx
  char *v72; // rax
  unsigned int v73; // eax
  PCRYPT_CONTEXT_FUNCTIONS v74; // rdx
  int v75; // r12d
  __int64 v76; // rbx
  const wchar_t **v77; // rsi
  unsigned int v78; // edi
  int v79; // eax
  CCipherMill *v80; // rcx
  __int16 v81; // cx
  __int64 v82; // rdx
  __int64 v83; // r8
  __int64 v84; // rax
  wchar_t *v85; // rdi
  __int64 v86; // rsi
  unsigned int v87; // ebx
  struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *v88; // r15
  unsigned int v89; // edi
  CCipherMill *v90; // rcx
  unsigned int v91; // esi
  unsigned __int8 *v92; // rbx
  int SupportedProvider; // eax
  struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *v94; // rdi
  __int64 v95; // rsi
  void *v96; // rcx
  unsigned int k; // edi
  void *v98; // rcx
  BOOLEAN pfEnabled[4]; // [rsp+48h] [rbp-C0h] BYREF
  unsigned int v101; // [rsp+4Ch] [rbp-BCh]
  unsigned int v102; // [rsp+50h] [rbp-B8h] BYREF
  unsigned int v103; // [rsp+54h] [rbp-B4h] BYREF
  ULONG v104; // [rsp+58h] [rbp-B0h] BYREF
  unsigned int v105; // [rsp+5Ch] [rbp-ACh]
  unsigned int v106[2]; // [rsp+60h] [rbp-A8h]
  PVOID pvBuffer; // [rsp+68h] [rbp-A0h] BYREF
  PCRYPT_CONTEXT_FUNCTIONS v108; // [rsp+70h] [rbp-98h] BYREF
  wchar_t *v109; // [rsp+78h] [rbp-90h] BYREF
  wchar_t *String1; // [rsp+80h] [rbp-88h] BYREF
  unsigned __int16 *v111; // [rsp+88h] [rbp-80h] BYREF
  wchar_t *v112; // [rsp+90h] [rbp-78h]
  struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *v113; // [rsp+98h] [rbp-70h]
  _OWORD *v114; // [rsp+A0h] [rbp-68h] BYREF
  struct CCipherSuiteInfo *v115; // [rsp+A8h] [rbp-60h] BYREF
  struct CCipherSuiteInfo *v116; // [rsp+B0h] [rbp-58h] BYREF
  ULONG pcbBuffer; // [rsp+B8h] [rbp-50h] BYREF
  ULONG v118; // [rsp+BCh] [rbp-4Ch] BYREF
  CMasterCipherInfo *v119; // [rsp+C0h] [rbp-48h] BYREF
  CMasterCipherInfo *v120; // [rsp+C8h] [rbp-40h] BYREF
  PCRYPT_CONTEXT_FUNCTIONS ppBuffer; // [rsp+D0h] [rbp-38h] BYREF
  char v122[784]; // [rsp+D8h] [rbp-30h] BYREF
  void *v123; // [rsp+3E8h] [rbp+2E0h] BYREF
  int v124[187]; // [rsp+3F0h] [rbp+2E8h] BYREF
  wchar_t v125[5]; // [rsp+6DEh] [rbp+5D6h] BYREF
  wchar_t Destination[64]; // [rsp+6E8h] [rbp+5E0h] BYREF
  wchar_t v127[64]; // [rsp+768h] [rbp+660h] BYREF

  LODWORD(v1) = 0;
  v2 = 0;
  v118 = 0;
  v101 = 0;
  v108 = 0i64;
  v104 = 0;
  v3 = 0i64;
  pvBuffer = 0i64;
  v4 = 0i64;
  v115 = 0i64;
  v5 = 0;
  v116 = 0i64;
  v105 = 0;
  v106[0] = 0;
  v120 = 0i64;
  v119 = 0i64;
  pcbBuffer = 0;
  ppBuffer = 0i64;
  v111 = 0i64;
  v103 = 0;
  pfEnabled[0] = 0;
  v112 = 0i64;
  String1 = 0i64;
  v102 = 0;
  memset_0(&v123, 0, 0x300ui64);
  memset_0(Destination, 0, sizeof(Destination));
  memset_0(v127, 0, sizeof(v127));
  ++dword_180092488;
  v114 = 0i64;
  dword_1800925D4 = 13;
  v6 = (struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *)SPExternalAlloc(0xC800u);
  v113 = v6;
  if ( !v6 )
  {
    v7 = 14;
    goto LABEL_167;
  }
  v8 = 0;
  if ( !qword_180092498 )
    goto LABEL_30;
  while ( 2 )
  {
    v109 = 0i64;
    v9 = v2;
    if ( v2 >= 0xC80 )
      goto LABEL_20;
    v10 = (char *)v6 + 16 * v2;
    do
    {
      if ( !(_BYTE)v1 )
      {
        v7 = SslEnumCipherSuitesEx(*(_QWORD *)&g_cCipherMill[8 * v8 + 128], 0i64, v10, &v109, 0);
        if ( v7 != -2146893783 )
        {
          LOBYTE(v1) = 0;
          goto LABEL_10;
        }
        LOBYTE(v1) = 1;
      }
      v7 = SslEnumCipherSuites(*(_QWORD *)&g_cCipherMill[8 * v8 + 128], 0i64, &v114, &v109, 0);
LABEL_10:
      *((_DWORD *)v10 + 2) = v8;
      v10[12] = v1;
      if ( v7 == -2146893782 )
        break;
      if ( v7 )
      {
        v16 = (__int64)v109;
        *(_QWORD *)v10 = 0i64;
        *((_DWORD *)v10 + 2) = 0;
        SslFreeBuffer(v16);
        goto LABEL_28;
      }
      if ( (_BYTE)v1 )
      {
        v11 = (char *)SPExternalAlloc(0x328u);
        *(_QWORD *)v10 = v11;
        if ( !v11 )
        {
          v7 = -2146893056;
          goto LABEL_159;
        }
        v12 = 5i64;
        v13 = v11 + 4;
        v14 = v114;
        do
        {
          *v13 = *v14;
          v13[1] = v14[1];
          v13[2] = v14[2];
          v13[3] = v14[3];
          v13[4] = v14[4];
          v13[5] = v14[5];
          v13[6] = v14[6];
          v13 += 8;
          v15 = v14[7];
          v14 += 8;
          *(v13 - 1) = v15;
          --v12;
        }
        while ( v12 );
        *v13 = *v14;
        v13[1] = v14[1];
        *((_DWORD *)v13 + 8) = *((_DWORD *)v14 + 8);
        SslFreeBuffer(v114);
        v114 = 0i64;
      }
      v10 += 16;
      ++v101;
    }
    while ( v101 < 0xC80 );
    if ( v109 )
      SslFreeBuffer(v109);
LABEL_20:
    if ( (unsigned int)SslEnumEccCurves(*(_QWORD *)&g_cCipherMill[8 * v8 + 128], &v124[6 * v8], &v124[6 * v8 - 2], 0i64) )
    {
      LOBYTE(v124[6 * v8 + 2]) = 0;
      v2 = v101;
      CCipherMill::EnumEccCurvesFromCipherToProvTable(
        0i64,
        (struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *)((char *)v113 + 16 * v9),
        v101 - v9,
        (unsigned int *)&v124[6 * v8],
        (struct _NCRYPT_SSL_ECC_CURVE **)&v124[6 * v8 - 2]);
    }
    else
    {
      LOBYTE(v124[6 * v8 + 2]) = 1;
      v2 = v101;
    }
    ++v8;
    LODWORD(v1) = 0;
    if ( v8 < qword_180092498 )
    {
      v6 = v113;
      continue;
    }
    break;
  }
  v4 = v112;
LABEL_30:
  word_1800925E8 = 0;
  word_18009260A = 0;
  if ( BCryptEnumContextFunctions(1u, L"SSL", 0x10003u, &pcbBuffer, &ppBuffer) < 0
    || !CTlsSignatureSuiteList::AddBCryptSignatureSuites(
          (CTlsSignatureSuiteList *)&word_1800925E8,
          (const unsigned __int16 **const)ppBuffer->rgpszFunctions,
          ppBuffer->cFunctions,
          1) )
  {
    word_1800925E8 = 0;
    v18 = 0;
    word_18009260A = 0;
    do
    {
      CTlsSignatureSuiteList::AddSignatureSuite((CTlsSignatureSuiteList *)&word_1800925E8, v18);
      v18 = v19 + 1;
    }
    while ( v18 < 0xCu );
    CTlsSignatureSuiteList::SetRsaSignatureFlags();
  }
  v20 = BCryptEnumContextFunctions(1u, L"SSL", 0x10002u, &v118, &v108);
  if ( v20 < 0 )
  {
    v21 = RtlNtStatusToDosError(v20);
    goto LABEL_150;
  }
  if ( !(unsigned int)IsCipherSuiteGroupPolicyEnabled()
    || (unsigned int)IsEccCurveGroupPolicyEnabled()
    || (GetSslEccCurveTypeOrderFromCipherSuiteList((__int64)v108, &String1, &v102),
        v5 = v102,
        v4 = String1,
        v112 = String1,
        !v102) )
  {
    v111 = 0i64;
    GetSslEccCurveOrder((BYTE **)&v111, (unsigned __int16 *)&v103);
    v22 = v111;
    if ( v111 )
    {
      v23 = qword_180092498;
      v103 = qword_180092498;
      v24 = v111;
      String1 = v111;
      if ( qword_180092498 )
      {
        v25 = v124;
        v26 = qword_180092498;
        do
        {
          LODWORD(v3) = *v25 + (_DWORD)v3;
          v25 += 6;
          --v26;
        }
        while ( v26 );
      }
      v27 = (wchar_t *)SPExternalAlloc(4 * (int)v3);
      v109 = v27;
      if ( v27 )
      {
        v28 = -1i64;
        do
          ++v28;
        while ( v22[v28] );
        if ( v28 )
        {
          while ( 1 )
          {
            v29 = 0;
            if ( v23 )
              break;
LABEL_63:
            if ( (_DWORD)v1 != (_DWORD)v3 )
            {
              v24 += v28 + 1;
              String1 = v24;
              v28 = -1i64;
              do
                ++v28;
              while ( v24[v28] );
              if ( v28 )
                continue;
            }
            goto LABEL_67;
          }
          v30 = v124;
          while ( 1 )
          {
            if ( *((_QWORD *)v30 - 1) )
            {
              v31 = 0;
              if ( *v30 )
              {
                while ( 1 )
                {
                  v32 = *((_QWORD *)v30 - 1) + 780i64 * v31;
                  if ( !wcsicmp(String1, (const wchar_t *)v32) )
                    break;
                  if ( ++v31 >= *v30 )
                    goto LABEL_59;
                }
                v33 = 0;
                if ( (_DWORD)v1 )
                {
                  while ( *(_DWORD *)&v109[2 * v33] != *(_DWORD *)(v32 + 772) )
                  {
                    if ( ++v33 >= (unsigned int)v1 )
                      goto LABEL_58;
                  }
                }
                else
                {
LABEL_58:
                  v34 = (unsigned int)v1;
                  LODWORD(v1) = v1 + 1;
                  *(_DWORD *)&v109[2 * v34] = *(_DWORD *)(v32 + 772);
                }
LABEL_59:
                v23 = v103;
              }
              if ( (_DWORD)v1 == (_DWORD)v3 )
                break;
            }
            ++v29;
            v30 += 6;
            if ( v29 >= v23 )
            {
              v24 = String1;
              goto LABEL_63;
            }
          }
LABEL_67:
          v27 = v109;
          v22 = v111;
        }
        v4 = v27;
        v112 = v27;
        v5 = v1;
        v102 = v1;
      }
      else
      {
        v4 = v112;
      }
      SPExternalFree(v22);
      LODWORD(v1) = 0;
    }
  }
  if ( !v4 || !v5 )
    goto LABEL_97;
  if ( BCryptGetFipsAlgorithmMode(pfEnabled) >= 0 && pfEnabled[0] )
  {
    FilterFipsEccCurves((__int64)v4, &v102);
    v5 = v102;
  }
  if ( v5 )
  {
    v35 = qword_180092498;
    if ( qword_180092498 )
    {
      v36 = &v123;
      v1 = qword_180092498;
      do
      {
        if ( *v36 )
        {
          v37 = 0;
          v38 = v4;
          v39 = v5;
          do
          {
            for ( i = 0; i < *((_DWORD *)v36 + 2); ++i )
            {
              v41 = (__int64)*v36 + 780 * i;
              if ( *(_DWORD *)v38 == *(_DWORD *)(v41 + 772) )
              {
                v42 = (__int64)*v36 + 780 * v37;
                if ( v37 != i )
                {
                  v43 = (__int64)*v36 + 780 * v37;
                  v44 = v122;
                  v45 = 6i64;
                  do
                  {
                    v46 = *(_OWORD *)v43;
                    v47 = *(_OWORD *)(v43 + 16);
                    v43 += 128i64;
                    *(_OWORD *)v44 = v46;
                    v48 = *(_OWORD *)(v43 - 96);
                    *((_OWORD *)v44 + 1) = v47;
                    v49 = *(_OWORD *)(v43 - 80);
                    *((_OWORD *)v44 + 2) = v48;
                    v50 = *(_OWORD *)(v43 - 64);
                    *((_OWORD *)v44 + 3) = v49;
                    v51 = *(_OWORD *)(v43 - 48);
                    *((_OWORD *)v44 + 4) = v50;
                    v52 = *(_OWORD *)(v43 - 32);
                    *((_OWORD *)v44 + 5) = v51;
                    v53 = *(_OWORD *)(v43 - 16);
                    *((_OWORD *)v44 + 6) = v52;
                    v44 += 128;
                    *((_OWORD *)v44 - 1) = v53;
                    --v45;
                  }
                  while ( v45 );
                  *(_QWORD *)v44 = *(_QWORD *)v43;
                  v54 = *(_DWORD *)(v43 + 8);
                  v55 = v41;
                  *((_DWORD *)v44 + 2) = v54;
                  v56 = 6i64;
                  do
                  {
                    *(_OWORD *)v42 = *(_OWORD *)v55;
                    *(_OWORD *)(v42 + 16) = *(_OWORD *)(v55 + 16);
                    *(_OWORD *)(v42 + 32) = *(_OWORD *)(v55 + 32);
                    *(_OWORD *)(v42 + 48) = *(_OWORD *)(v55 + 48);
                    *(_OWORD *)(v42 + 64) = *(_OWORD *)(v55 + 64);
                    *(_OWORD *)(v42 + 80) = *(_OWORD *)(v55 + 80);
                    *(_OWORD *)(v42 + 96) = *(_OWORD *)(v55 + 96);
                    v42 += 128i64;
                    v57 = *(_OWORD *)(v55 + 112);
                    v55 += 128i64;
                    *(_OWORD *)(v42 - 16) = v57;
                    --v56;
                  }
                  while ( v56 );
                  *(_QWORD *)v42 = *(_QWORD *)v55;
                  *(_DWORD *)(v42 + 8) = *(_DWORD *)(v55 + 8);
                  v58 = v122;
                  v59 = 6i64;
                  do
                  {
                    v60 = *((_OWORD *)v58 + 1);
                    *(_OWORD *)v41 = *(_OWORD *)v58;
                    v61 = *((_OWORD *)v58 + 2);
                    *(_OWORD *)(v41 + 16) = v60;
                    v62 = *((_OWORD *)v58 + 3);
                    *(_OWORD *)(v41 + 32) = v61;
                    v63 = *((_OWORD *)v58 + 4);
                    *(_OWORD *)(v41 + 48) = v62;
                    v64 = *((_OWORD *)v58 + 5);
                    *(_OWORD *)(v41 + 64) = v63;
                    v65 = *((_OWORD *)v58 + 6);
                    *(_OWORD *)(v41 + 80) = v64;
                    v66 = *((_OWORD *)v58 + 7);
                    v58 += 128;
                    *(_OWORD *)(v41 + 96) = v65;
                    v41 += 128i64;
                    *(_OWORD *)(v41 - 16) = v66;
                    --v59;
                  }
                  while ( v59 );
                  *(_QWORD *)v41 = *(_QWORD *)v58;
                  *(_DWORD *)(v41 + 8) = *((_DWORD *)v58 + 2);
                }
                ++v37;
              }
            }
            v38 += 2;
            --v39;
          }
          while ( v39 );
          *((_DWORD *)v36 + 2) = v37;
        }
        v36 += 3;
        --v1;
      }
      while ( v1 );
      v35 = qword_180092498;
    }
  }
  else
  {
LABEL_97:
    v35 = qword_180092498;
    for ( j = 0; j < v35; ++j )
    {
      v68 = *(void **)&v124[6 * j - 2];
      v124[6 * j] = 0;
      if ( v68 )
      {
        if ( LOBYTE(v124[6 * j + 2]) )
          SslFreeBuffer(v68);
        else
          SPExternalFree(v68);
        v35 = qword_180092498;
        *(_QWORD *)&v124[6 * j - 2] = 0i64;
      }
    }
  }
  v69 = 0;
  if ( v35 )
  {
    v70 = v124;
    v71 = v35;
    do
    {
      v69 += *v70;
      v70 += 6;
      --v71;
    }
    while ( v71 );
  }
  v72 = (char *)SPExternalAlloc(32 * v35 + 16 + 780 * v69);
  v17 = (unsigned __int16 *)v72;
  if ( !v72 )
  {
    v7 = 14;
    goto LABEL_157;
  }
  qword_1800925C8 = CMasterEccCurveInfo::CMasterEccCurveInfo(
                      (CMasterEccCurveInfo *)v72,
                      (struct ProviderEccCurves *)(v72 + 16),
                      (struct CEccCurveInfo *)&v72[32 * v35 + 16],
                      (struct PROVIDER_TO_ECC_CURVES *)&v123,
                      qword_180092498);
  v17 = 0i64;
  v111 = 0i64;
  v7 = AllocateCipherSuiteData(v108->cFunctions, (unsigned __int8 **)&v119, &v115);
  if ( v7 )
  {
    v3 = v115;
    goto LABEL_153;
  }
  v73 = AllocateCipherSuiteData(v108->cFunctions, (unsigned __int8 **)&v120, &v116);
  v3 = v115;
  v7 = v73;
  if ( v73 )
  {
LABEL_153:
    if ( v119 )
      FreeCipherSuiteData(v105, (NCRYPT_HANDLE *)v3, v119);
    if ( !v120 )
      goto LABEL_159;
    FreeCipherSuiteData(v106[0], (NCRYPT_HANDLE *)v116, v120);
LABEL_157:
    if ( v17 )
      SPExternalFree(v17);
    goto LABEL_159;
  }
  v74 = v108;
  v75 = 0;
  qword_1800925C0 = 0i64;
  if ( !v108->cFunctions )
  {
LABEL_132:
    xmmword_1800925B0 = CMasterCipherInfo::CMasterCipherInfo(v119, v3, v105);
    *(&xmmword_1800925B0 + 1) = CMasterCipherInfo::CMasterCipherInfo(v120, v116, v106[0]);
    v81 = 0;
    word_1800925D0 = 0;
    if ( qword_180092498 )
    {
      v82 = 0i64;
      v83 = qword_180092498;
      do
      {
        v82 += 32i64;
        v81 += *(_WORD *)(*(_QWORD *)qword_1800925C8 + v82 - 24);
        word_1800925D0 = v81;
        --v83;
      }
      while ( v83 );
    }
    v7 = 0;
    goto LABEL_159;
  }
  while ( 2 )
  {
    if ( pvBuffer )
    {
      BCryptFreeBuffer(pvBuffer);
      v74 = v108;
      pvBuffer = 0i64;
    }
    wcscpy_s(Destination, 0x40ui64, v74->rgpszFunctions[v75]);
    v76 = -1i64;
    do
      ++v76;
    while ( Destination[v76] );
    if ( (unsigned int)v76 > 5 )
    {
      v77 = (const wchar_t **)&off_18007F170;
      v78 = 0;
      while ( wcsicmp(&v125[(unsigned int)v76], *v77) )
      {
        ++v78;
        v77 += 99;
        if ( v78 >= 3 )
          goto LABEL_122;
      }
      LODWORD(v1) = 1;
    }
LABEL_122:
    v79 = BCryptEnumContextFunctionProviders(
            1u,
            0i64,
            0x10002u,
            Destination,
            &v104,
            (PCRYPT_CONTEXT_FUNCTION_PROVIDERS *)&pvBuffer);
    if ( v79 == -1073741275 )
    {
      v79 = BCryptEnumContextFunctionProviders(
              1u,
              L"SSL",
              0x10002u,
              Destination,
              &v104,
              (PCRYPT_CONTEXT_FUNCTION_PROVIDERS *)&pvBuffer);
      if ( v79 == -1073741275 )
      {
        if ( (_DWORD)v1 )
        {
          v80 = (CCipherMill *)(2i64 * (unsigned int)(v76 - 5));
          if ( (unsigned __int64)v80 >= 0x80 )
            goto LABEL_184;
          Destination[(unsigned int)(v76 - 5)] = 0;
          LODWORD(v1) = 0;
          v79 = BCryptEnumContextFunctionProviders(
                  1u,
                  0i64,
                  0x10002u,
                  Destination,
                  &v104,
                  (PCRYPT_CONTEXT_FUNCTION_PROVIDERS *)&pvBuffer);
          if ( v79 == -1073741275 )
            v79 = BCryptEnumContextFunctionProviders(
                    1u,
                    L"SSL",
                    0x10002u,
                    Destination,
                    &v104,
                    (PCRYPT_CONTEXT_FUNCTION_PROVIDERS *)&pvBuffer);
          goto LABEL_128;
        }
LABEL_130:
        LODWORD(v1) = 0;
        goto LABEL_131;
      }
    }
LABEL_128:
    if ( v79 >= 0 )
    {
      if ( (_DWORD)v1 )
      {
        wcscpy_s(v127, 0x40ui64, Destination);
        v84 = -1i64;
        do
          ++v84;
        while ( v127[v84] );
        v80 = (CCipherMill *)(2i64 * (unsigned int)(v84 - 5));
        if ( (unsigned __int64)v80 >= 0x80 )
LABEL_184:
          _report_rangecheckfailure(v80);
        v127[(unsigned int)(v84 - 5)] = 0;
        v85 = v127;
      }
      else
      {
        v85 = Destination;
      }
      v86 = v105;
      v87 = 0;
      if ( v105 )
      {
        while ( wcsicmp(v85, (const wchar_t *)v3 + 432 * v87 + 37) )
        {
          if ( ++v87 >= (unsigned int)v86 )
            goto LABEL_145;
        }
        goto LABEL_130;
      }
LABEL_145:
      v88 = v113;
      v89 = v101;
      if ( !(unsigned int)CCipherMill::FindSupportedProvider(
                            v80,
                            (struct _CRYPT_CONTEXT_FUNCTION_PROVIDERS *)pvBuffer,
                            1u,
                            v113,
                            v101,
                            (unsigned __int8 *)v3 + 864 * v86,
                            Destination,
                            v1) )
      {
        LODWORD(qword_1800925C0) = *((_DWORD *)v3 + 216 * v86 + 2) | qword_1800925C0;
        v105 = v86 + 1;
      }
      v91 = v106[0];
      v92 = (unsigned __int8 *)v116 + 864 * v106[0];
      SupportedProvider = CCipherMill::FindSupportedProvider(
                            v90,
                            (struct _CRYPT_CONTEXT_FUNCTION_PROVIDERS *)pvBuffer,
                            2u,
                            v88,
                            v89,
                            v92,
                            Destination,
                            v1);
      LODWORD(v1) = 0;
      if ( !SupportedProvider )
      {
        HIDWORD(qword_1800925C0) |= *((_DWORD *)v92 + 2);
        v106[0] = v91 + 1;
      }
LABEL_131:
      v74 = v108;
      if ( ++v75 >= v108->cFunctions )
        goto LABEL_132;
      continue;
    }
    break;
  }
  if ( v79 == -1073741275 )
    goto LABEL_130;
  v21 = RtlNtStatusToDosError(v79);
LABEL_150:
  v7 = v21;
  if ( v21 )
  {
LABEL_28:
    v17 = v111;
    goto LABEL_153;
  }
LABEL_159:
  if ( v101 )
  {
    v94 = v113;
    v95 = v101;
    do
    {
      v96 = *(void **)v94;
      if ( *(_QWORD *)v94 )
      {
        if ( *((_BYTE *)v94 + 12) )
          SPExternalFree(v96);
        else
          SslFreeBuffer(v96);
      }
      v94 = (struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *)((char *)v94 + 16);
      --v95;
    }
    while ( v95 );
  }
  SPExternalFree(v113);
  v4 = v112;
LABEL_167:
  for ( k = 0; k < qword_180092498; ++k )
  {
    v98 = *(void **)&v124[6 * k - 2];
    if ( v98 )
    {
      if ( LOBYTE(v124[6 * k + 2]) )
        SslFreeBuffer(v98);
      else
        SPExternalFree(v98);
    }
  }
  if ( v4 )
    SPExternalFree(v4);
  if ( pvBuffer )
    BCryptFreeBuffer(pvBuffer);
  if ( v108 )
    BCryptFreeBuffer(v108);
  if ( ppBuffer )
    BCryptFreeBuffer(ppBuffer);
  if ( v114 )
    SslFreeBuffer(v114);
  return v7;
}
// 180023F0A: conditional instruction was optimized away because r12d.4!=0
// 180023C92: variable 'v19' is possibly undefined
// 180024504: variable 'v80' is possibly undefined
// 180024553: variable 'v90' is possibly undefined
// 1800281B8: using guessed type void __fastcall __noreturn _report_rangecheckfailure(_QWORD);
// 18007F170: using guessed type wchar_t *off_18007F170;
// 180092488: using guessed type int dword_180092488;
// 1800925C0: using guessed type __int64 qword_1800925C0;
// 1800925D0: using guessed type __int16 word_1800925D0;
// 1800925D4: using guessed type int dword_1800925D4;
// 1800925E8: using guessed type __int16 word_1800925E8;
// 18009260A: using guessed type __int16 word_18009260A;
// 180098458: using guessed type __int64 __fastcall SslEnumEccCurves(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098468: using guessed type __int64 __fastcall SslEnumCipherSuitesEx(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098480: using guessed type __int64 __fastcall SslFreeBuffer(_QWORD);
// 180098590: using guessed type __int64 __fastcall SslEnumCipherSuites(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 1800238AC: using guessed type wchar_t Destination[64];
// 1800238AC: using guessed type wchar_t var_B0[64];
// 1800238AC: using guessed type wchar_t var_13A[5];
