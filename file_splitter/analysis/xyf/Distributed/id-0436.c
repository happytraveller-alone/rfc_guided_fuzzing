//----- (000000018001B0B0) ----------------------------------------------------
__int64 __fastcall CCipherMill::ChooseServerCipher(
        CCipherMill *this,
        struct CSsl3TlsServerContext *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned __int8 a6)
{
  __int64 v6; // rdi
  __int64 v8; // r13
  unsigned __int64 v9; // rsi
  __int64 v10; // rax
  unsigned __int8 *v11; // r14
  CCipherMill *v12; // rdi
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // r8
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // rsi
  __int64 v18; // rdx
  __int64 v19; // r8
  unsigned int AcceptableCipherSuiteAndCred; // r15d
  struct CCipherSuiteInfo *v21; // r13
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // r8
  __int64 v25; // rdi
  __int64 v26; // rsi
  CSslServerKey *v27; // rcx
  struct CCipherSuiteInfo *v28; // rdi
  __int64 v29; // r12
  unsigned int v30; // r9d
  unsigned int v31; // r8d
  __int64 v32; // rax
  int v33; // eax
  unsigned int v34; // r9d
  __int16 v35; // r10
  unsigned __int8 v36; // si
  unsigned __int8 *v37; // rdx
  CCipherMill *v38; // rcx
  struct CCipherSuiteInfo *v40; // rax
  struct CSslCredential *v41; // r8
  unsigned __int8 *v42; // r9
  unsigned __int8 v43; // cl
  int v44; // r10d
  struct CSslCredential *v45; // rsi
  unsigned int v46; // edi
  unsigned int v47; // edx
  NTSTATUS v48; // eax
  __int64 v49; // r9
  __int64 v50; // rdx
  __int16 v51; // ax
  __int64 v52; // rax
  unsigned __int16 v53; // ax
  unsigned __int8 *v54; // rcx
  unsigned __int64 v55; // r15
  __int64 v56; // rax
  unsigned __int8 *v57; // rcx
  __int64 v58; // rax
  unsigned __int8 *v59; // r14
  unsigned __int8 *v60; // r12
  unsigned __int8 *v61; // r13
  __int64 v62; // rcx
  SIZE_T v63; // rax
  _DWORD *v64; // rax
  __int64 *v65; // r10
  unsigned int v66; // ecx
  __int64 v67; // r10
  __int64 v68; // rdx
  __int64 v69; // rax
  __int64 v70; // rcx
  const char *v71; // r9
  unsigned __int8 v72; // al
  const char *v73; // r9
  __int64 v74; // rax
  __int64 v75; // rdx
  __int64 v76; // rcx
  unsigned int v77; // ecx
  int v78; // eax
  CCipherMill *v79; // rcx
  __int64 v80; // rdx
  unsigned __int16 v81; // dx
  struct _UNICODE_STRING *v82; // [rsp+28h] [rbp-D8h]
  bool v83; // [rsp+60h] [rbp-A0h]
  unsigned __int8 v84; // [rsp+61h] [rbp-9Fh]
  unsigned __int8 v85[2]; // [rsp+62h] [rbp-9Eh] BYREF
  unsigned int v86; // [rsp+64h] [rbp-9Ch]
  unsigned __int8 *v87; // [rsp+68h] [rbp-98h] BYREF
  unsigned int v88; // [rsp+70h] [rbp-90h]
  unsigned int v89; // [rsp+74h] [rbp-8Ch] BYREF
  struct CCipherSuiteInfo *v90; // [rsp+78h] [rbp-88h] BYREF
  struct CCipherSuiteInfo *v91; // [rsp+80h] [rbp-80h]
  struct CSslCredential *v92; // [rsp+88h] [rbp-78h]
  struct CSslCredential *v93; // [rsp+90h] [rbp-70h] BYREF
  unsigned __int8 *v94; // [rsp+98h] [rbp-68h]
  unsigned int v95; // [rsp+A0h] [rbp-60h]
  struct _UNICODE_STRING *p_DestinationString; // [rsp+A8h] [rbp-58h]
  unsigned __int64 v97; // [rsp+B0h] [rbp-50h]
  struct _UNICODE_STRING DestinationString; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v99; // [rsp+C8h] [rbp-38h]
  struct _STRING SourceString; // [rsp+D0h] [rbp-30h] BYREF
  unsigned int *v101; // [rsp+E0h] [rbp-20h]
  _BYTE Source1[20]; // [rsp+E8h] [rbp-18h] BYREF
  __int64 v103; // [rsp+100h] [rbp+0h] BYREF
  int v104; // [rsp+108h] [rbp+8h]
  wchar_t v105; // [rsp+10Ch] [rbp+Ch]
  char v106[498]; // [rsp+10Eh] [rbp+Eh] BYREF
  char v107[512]; // [rsp+300h] [rbp+200h] BYREF

  v6 = *((_QWORD *)a2 + 10);
  v101 = a3;
  v99 = v6;
  v93 = 0i64;
  v90 = 0i64;
  v89 = 0;
  v85[0] = 0;
  v94 = 0i64;
  v95 = a4;
  memset_0(v107, 0, 0x1FEui64);
  *(_DWORD *)&DestinationString.Length = 33423360;
  DestinationString.Buffer = (PWSTR)v107;
  v8 = *(unsigned int *)(v6 + 196);
  v9 = *(_QWORD *)(v6 + 200);
  p_DestinationString = 0i64;
  v97 = v9;
  v83 = (_DWORD)v8 != 0;
  v92 = 0i64;
  v91 = 0i64;
  v87 = 0i64;
  v86 = 0;
  v84 = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
  RtlAcquireResourceShared(&Resource, 1u);
  v10 = *((_QWORD *)a2 + 121);
  v11 = (unsigned __int8 *)(v10 + 6);
  if ( v10 )
  {
    v88 = *(unsigned __int16 *)(v10 + 4);
  }
  else
  {
    v11 = 0i64;
    v88 = 0;
  }
  v12 = WPP_GLOBAL_Control;
  while ( 1 )
  {
    v104 = *(_DWORD *)L"E>";
    v105 = aNone[6];
    v103 = *(_QWORD *)L"<NONE>";
    memset_0(v106, 0, sizeof(v106));
    if ( v91 && v83 )
    {
      LOBYTE(v13) = 0;
      v83 = 0;
    }
    else
    {
      if ( v11 && v88 )
      {
        v94 = v11;
        *(_DWORD *)(&SourceString.MaximumLength + 1) = 0;
        p_DestinationString = &DestinationString;
        if ( !DestinationString.Buffer )
        {
          AcceptableCipherSuiteAndCred = 87;
          goto LABEL_43;
        }
        v46 = v88;
        v47 = *v11;
        if ( v47 > v88 - 1 )
        {
          AcceptableCipherSuiteAndCred = 1359;
          goto LABEL_43;
        }
        SourceString.Length = *v11;
        SourceString.MaximumLength = v47;
        SourceString.Buffer = (PCHAR)(v11 + 1);
        v48 = RtlAnsiStringToUnicodeString(&DestinationString, &SourceString, 0);
        AcceptableCipherSuiteAndCred = RtlNtStatusToDosError(v48);
        if ( AcceptableCipherSuiteAndCred )
          goto LABEL_43;
        v14 = (__int64)&v103;
        v49 = DestinationString.Length - 512i64;
        v50 = 512i64;
        v15 = (char *)DestinationString.Buffer - (char *)&v103;
        while ( v49 + v50 )
        {
          v51 = *(_WORD *)(v15 + v14);
          if ( !v51 )
            break;
          *(_WORD *)v14 = v51;
          v14 += 2i64;
          if ( !--v50 )
          {
            v14 -= 2i64;
            break;
          }
        }
        *(_WORD *)v14 = 0;
        v52 = (unsigned int)*v11 + 1;
        if ( (unsigned int)v52 > v46 )
          goto LABEL_150;
        v88 = v46 - v52;
        v11 += v52;
        v12 = WPP_GLOBAL_Control;
      }
      v13 = v83;
    }
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
    {
      v71 = "strict";
      if ( !(_BYTE)v13 )
        v71 = "all";
      WPP_SF_sS(*((_QWORD *)v12 + 2), v13, v15, v71, (const wchar_t *)&v103);
      LOBYTE(v13) = v83;
    }
    if ( !(_DWORD)v8 || !v9 || (v16 = v9, v14 = 5 * v8, v17 = v9 + 40 * v8, v97 >= v17) )
    {
LABEL_17:
      AcceptableCipherSuiteAndCred = CCipherMill::FindAcceptableCipherSuiteAndCred(
                                       (CCipherMill *)v14,
                                       a2,
                                       v101,
                                       v95,
                                       a6,
                                       p_DestinationString,
                                       v13,
                                       &v90,
                                       &v93,
                                       &v89,
                                       v85);
      if ( AcceptableCipherSuiteAndCred )
      {
        v12 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_125;
        v73 = "strict";
        if ( !v83 )
          v73 = "all";
        LODWORD(v82) = AcceptableCipherSuiteAndCred;
        WPP_SF_sSD(*((_QWORD *)WPP_GLOBAL_Control + 2), v18, v19, v73, (const wchar_t *)&v103, v82);
      }
      else
      {
        if ( a6 )
          goto LABEL_19;
        LOBYTE(v13) = v83;
        if ( !v83 )
        {
          v43 = v85[0];
          v45 = v93;
          goto LABEL_96;
        }
        v40 = v91;
        if ( v91 )
        {
          v12 = WPP_GLOBAL_Control;
LABEL_126:
          v43 = v84;
          v41 = v92;
          v42 = v87;
          v44 = v86;
LABEL_50:
          v45 = 0i64;
          v90 = 0i64;
          v93 = 0i64;
          v89 = 0;
          v85[0] = 0;
          goto LABEL_51;
        }
        v40 = v90;
        v41 = v93;
        v42 = v94;
        v43 = v85[0];
        v44 = v89;
        v91 = v90;
        v92 = v93;
        v87 = v94;
        v84 = v85[0];
        v86 = v89;
        v12 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_50;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
      }
      v12 = WPP_GLOBAL_Control;
LABEL_125:
      v40 = v91;
      LOBYTE(v13) = v83;
      goto LABEL_126;
    }
    while ( 1 )
    {
      if ( (a5 & *(_DWORD *)(v16 + 16)) != 0 )
      {
        if ( !*(_DWORD *)v16
          || p_DestinationString
          && (v72 = DoesTlsParameterContainAlpnId((struct _TLS_PARAMETERS *)v16, p_DestinationString),
              LOBYTE(v13) = v83,
              v72) )
        {
          if ( !(_BYTE)v13 || (*(_BYTE *)(v16 + 32) & 1) == 0 )
            break;
        }
      }
      v16 += 40i64;
      if ( v16 >= v17 )
        goto LABEL_17;
    }
    v12 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xFu, (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids, a5);
      LOBYTE(v13) = v83;
      v12 = WPP_GLOBAL_Control;
    }
    v45 = v93;
    AcceptableCipherSuiteAndCred = -2146893007;
    v40 = v91;
    v43 = v84;
    v41 = v92;
    v42 = v87;
    v44 = v86;
LABEL_51:
    if ( !(_DWORD)v8 || !v88 && (!v40 || !(_BYTE)v13) )
      break;
    v9 = v97;
  }
  if ( !AcceptableCipherSuiteAndCred )
    goto LABEL_97;
  if ( !v40 )
  {
    v74 = *((_QWORD *)a2 + 121);
    if ( !v74 || !*(_WORD *)(v74 + 4) )
    {
      if ( AcceptableCipherSuiteAndCred == -2146893007 )
      {
        LogCipherMismatchEvent(*(_DWORD *)(v99 + 212), (const unsigned __int16 *)(v99 + 216), a5);
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
      }
      goto LABEL_43;
    }
    AcceptableCipherSuiteAndCred = -2146892953;
    if ( (_DWORD)v8 )
    {
      if ( v12 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v12 + 28) & 4) == 0 )
        goto LABEL_145;
      v75 = 32i64;
    }
    else
    {
      if ( v12 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v12 + 28) & 1) == 0 )
        goto LABEL_145;
      v75 = 33i64;
    }
    WPP_SF_(*((_QWORD *)v12 + 2), v75, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
LABEL_145:
    CSslContext::SetErrorAndFatalAlert((__int64)a2, 1208, -2146892953, 0x78u);
    *((_DWORD *)a2 + 17) = 96;
    *((_WORD *)a2 + 48) = 30722;
    goto LABEL_43;
  }
  v45 = v41;
  v93 = v41;
  v90 = v40;
  v94 = v42;
  v85[0] = v43;
  v89 = v44;
  if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)v12 + 2), 31i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
    v43 = v84;
  }
LABEL_96:
  if ( v43 )
  {
LABEL_19:
    v21 = v90;
    v22 = *((_QWORD *)v90 + 106);
    if ( v22 )
      _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v22 + 16) + 12i64));
    _InterlockedIncrement((volatile signed __int32 *)(*((_QWORD *)v90 + 107) + 12i64));
    AcceptableCipherSuiteAndCred = 0;
    v23 = (*(__int64 (__fastcall **)(struct CSsl3TlsServerContext *))(*(_QWORD *)a2 + 248i64))(a2);
    v25 = *((_QWORD *)a2 + 1);
    v26 = v23;
    if ( v25 )
    {
      v76 = *(_QWORD *)(v25 + 848);
      if ( v76 )
        CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v76 + 16));
      CMasterCipherInfo::Dereference(*(CMasterCipherInfo **)(v25 + 856));
    }
    v27 = (CSslServerKey *)*((_QWORD *)a2 + 3);
    if ( v27 )
    {
      CSslServerKey::Dereference(v27);
      *((_QWORD *)a2 + 3) = 0i64;
    }
    v28 = v90;
    if ( v26 )
    {
      v29 = *(_QWORD *)v90;
      RtlAcquireResourceShared((PRTL_RESOURCE)(v26 + 552), 1u);
      v30 = *(_DWORD *)(v26 + 96);
      v31 = 0;
      if ( v30 )
      {
        while ( 1 )
        {
          v32 = *(_QWORD *)(*(_QWORD *)(v26 + 88) + 8i64 * v31);
          if ( *(_QWORD *)(v32 + 16) == v29 )
            break;
          if ( ++v31 >= v30 )
            goto LABEL_28;
        }
        _InterlockedIncrement((volatile signed __int32 *)(v32 + 24));
        v28 = v90;
        *((_QWORD *)a2 + 3) = *(_QWORD *)(*(_QWORD *)(v26 + 88) + 8i64 * v31);
      }
LABEL_28:
      RtlReleaseResource((PRTL_RESOURCE)(v26 + 552));
    }
    if ( (*((_DWORD *)a2 + 16) & 0xF3F00) != 0 )
    {
      AcceptableCipherSuiteAndCred = SslLookupCipherLengths(
                                       *(_QWORD *)v28,
                                       *((unsigned __int16 *)a2 + 17),
                                       *((unsigned int *)v28 + 7),
                                       *((unsigned int *)a2 + 4),
                                       Source1,
                                       20,
                                       0);
      if ( AcceptableCipherSuiteAndCred )
      {
LABEL_33:
        *((_WORD *)a2 + 16) |= 1u;
        *((_QWORD *)a2 + 1) = v28;
        if ( AcceptableCipherSuiteAndCred )
          goto LABEL_43;
        v34 = v89;
        if ( !a6 && *((_DWORD *)v28 + 12) == 3 || (v35 = a5, (a5 & 0x1000) != 0) )
        {
          *((_DWORD *)a2 + 4) = v89;
          v65 = (__int64 *)*((_QWORD *)v21 + 106);
          if ( v65 )
          {
            v24 = *((unsigned int *)v65 + 2);
            v66 = 0;
            if ( (_DWORD)v24 )
            {
              v67 = *v65;
              while ( 1 )
              {
                v68 = 780i64 * v66;
                if ( *(_DWORD *)(v68 + v67 + 772) == v34 )
                  break;
                if ( ++v66 >= (unsigned int)v24 )
                  goto LABEL_101;
              }
              if ( v68 + v67 )
                *((_DWORD *)a2 + 5) = *(_DWORD *)(v68 + v67 + 776);
            }
          }
LABEL_101:
          v35 = a5;
        }
        v36 = v85[0];
        if ( !v85[0] && (v35 & 0x1000) != 0 )
        {
          AcceptableCipherSuiteAndCred = (*(__int64 (__fastcall **)(struct CSsl3TlsServerContext *, _QWORD, _QWORD))(*(_QWORD *)a2 + 552i64))(
                                           a2,
                                           v34,
                                           *(_QWORD *)v28);
          if ( AcceptableCipherSuiteAndCred )
            goto LABEL_43;
        }
        v37 = v94;
        if ( !v94 )
        {
LABEL_39:
          if ( v36 )
          {
            *((_DWORD *)a2 + 17) = 71;
            v38 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
            {
              goto LABEL_43;
            }
            v81 = 35;
          }
          else if ( a6 )
          {
            v38 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
            {
              goto LABEL_43;
            }
            v81 = 36;
          }
          else
          {
            v38 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
            {
              goto LABEL_43;
            }
            v81 = 37;
          }
          WPP_SF_DS(*((_QWORD *)v38 + 2), v81, v24, *((_DWORD *)v28 + 7), (const wchar_t *)v28 + 37);
          goto LABEL_43;
        }
        v53 = *v94 + 1;
        if ( v53 < 2u )
        {
          v79 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_177;
          }
          v80 = 74i64;
LABEL_176:
          WPP_SF_(*((_QWORD *)v79 + 2), v80, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
LABEL_177:
          AcceptableCipherSuiteAndCred = -2146893018;
          goto LABEL_43;
        }
        v54 = v94;
        v55 = (unsigned __int64)&v94[v53];
        if ( (unsigned __int64)v94 < v55 )
        {
          while ( 1 )
          {
            v56 = *v54;
            if ( !(_BYTE)v56 )
              break;
            v57 = &v54[v56];
            if ( (unsigned __int64)v57 >= v55 )
              break;
            v54 = v57 + 1;
            if ( (unsigned __int64)v54 >= v55 )
              goto LABEL_73;
          }
          v79 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_177;
          }
          v80 = 76i64;
          goto LABEL_176;
        }
LABEL_73:
        v58 = *((_QWORD *)a2 + 98);
        if ( !v58 )
        {
          AcceptableCipherSuiteAndCred = 87;
          goto LABEL_43;
        }
        v59 = (unsigned __int8 *)(v58 + 6);
        if ( v58 != -6 )
        {
          v60 = &v59[*(unsigned __int16 *)(v58 + 4)];
          if ( v59 < v60 )
          {
            while ( 1 )
            {
              v61 = v37;
              if ( (unsigned __int64)v37 < v55 )
                break;
LABEL_168:
              v59 += *v59 + 1;
              if ( v59 >= v60 )
                goto LABEL_169;
            }
            LOBYTE(v62) = *v59;
            while ( 1 )
            {
              if ( (_BYTE)v62 == *v61 )
              {
                v63 = RtlCompareMemory(v59 + 1, v61 + 1, (unsigned __int8)v62);
                v62 = *v59;
                if ( v63 == v62 )
                  break;
              }
              v61 += *v61 + 1;
              if ( (unsigned __int64)v61 >= v55 )
              {
                v37 = v94;
                goto LABEL_168;
              }
            }
            v64 = (_DWORD *)*((_QWORD *)a2 + 99);
            if ( !v64 )
            {
              v64 = (_DWORD *)(*(__int64 (__fastcall **)(struct CSsl3TlsServerContext *, __int64))(*(_QWORD *)a2 + 8i64))(
                                a2,
                                264i64);
              *((_QWORD *)a2 + 99) = v64;
              if ( !v64 )
              {
                AcceptableCipherSuiteAndCred = 14;
                goto LABEL_43;
              }
            }
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 61i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
              v64 = (_DWORD *)*((_QWORD *)a2 + 99);
            }
            *v64 = 1;
            *(_DWORD *)(*((_QWORD *)a2 + 99) + 4i64) = 2;
            *(_BYTE *)(*((_QWORD *)a2 + 99) + 8i64) = *v59;
            memcpy_0((void *)(*((_QWORD *)a2 + 99) + 9i64), v59 + 1, *v59);
            AcceptableCipherSuiteAndCred = 0;
            goto LABEL_39;
          }
        }
LABEL_169:
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
        AcceptableCipherSuiteAndCred = -2146892953;
        goto LABEL_145;
      }
    }
    else
    {
      v77 = *((_DWORD *)v28 + 3);
      v78 = *((_DWORD *)v28 + 4);
      *(_QWORD *)Source1 = 20i64;
      *(_QWORD *)&Source1[12] = 0i64;
      *(_DWORD *)&Source1[8] = v78;
      if ( v77 > 1 )
      {
        *(_DWORD *)&Source1[16] |= 1u;
        *(_DWORD *)&Source1[12] = v77;
      }
    }
    if ( (*((_BYTE *)a2 + 32) & 1) != 0 && RtlCompareMemory(Source1, (char *)a2 + 40, 0x14ui64) != 20 )
    {
      *((_WORD *)a2 + 16) |= 1u;
      AcceptableCipherSuiteAndCred = -2146893007;
      *((_QWORD *)a2 + 1) = v28;
      goto LABEL_43;
    }
    v33 = *(_DWORD *)&Source1[16];
    *(_OWORD *)((char *)a2 + 40) = *(_OWORD *)Source1;
    *((_DWORD *)a2 + 14) = v33;
    goto LABEL_33;
  }
LABEL_97:
  v69 = *(_QWORD *)a2;
  v87 = 0i64;
  (*(void (__fastcall **)(struct CSsl3TlsServerContext *, unsigned __int8 **))(v69 + 232))(a2, &v87);
  if ( v87 )
  {
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v87 + 72), 1u);
    v70 = v99;
    *((_QWORD *)v87 + 42) = v45;
    *(_QWORD *)(v87 + 188) = *(_QWORD *)(v70 + 760);
    RtlReleaseResource((PRTL_RESOURCE)(v87 + 72));
    goto LABEL_19;
  }
LABEL_150:
  AcceptableCipherSuiteAndCred = -2146893052;
LABEL_43:
  RtlReleaseResource(&Resource);
  if ( *((_QWORD *)a2 + 121) )
  {
    (*(void (__fastcall **)(struct CSsl3TlsServerContext *))(*(_QWORD *)a2 + 16i64))(a2);
    *((_QWORD *)a2 + 121) = 0i64;
  }
  return AcceptableCipherSuiteAndCred;
}
// 18001B672: conditional instruction was optimized away because rdx.8!=0
// 18001B2AC: variable 'v14' is possibly undefined
// 18002FE63: variable 'v13' is possibly undefined
// 18002FE63: variable 'v15' is possibly undefined
// 18002FF76: variable 'v18' is possibly undefined
// 18002FF76: variable 'v19' is possibly undefined
// 18002FF76: variable 'v82' is possibly undefined
// 18003031D: variable 'v24' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180083D10: using guessed type wchar_t aNone[7];
// 1800984F0: using guessed type __int64 __fastcall SslLookupCipherLengths(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
// 18001B0B0: using guessed type unsigned __int8 var_4DE[2];
// 18001B0B0: using guessed type char var_432[498];

