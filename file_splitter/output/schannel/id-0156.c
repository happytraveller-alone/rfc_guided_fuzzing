//----- (000000018000D7D0) ----------------------------------------------------
__int64 __fastcall AscIscPostProcessing(
        int a1,
        struct CSslContext *a2,
        struct CSslParentContext *a3,
        struct _SecBuffer *a4,
        struct _SecBuffer *a5,
        struct _SecBuffer *a6,
        struct SPBuffer *a7,
        struct _SecBuffer *a8,
        struct SPBuffer *a9,
        unsigned __int64 a10,
        unsigned __int8 *a11,
        union _LARGE_INTEGER *a12)
{
  int v12; // r8d
  unsigned int v13; // r13d
  unsigned int v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // edi
  __int64 v19; // rax
  int v20; // eax
  const WCHAR *v21; // rdi
  WCHAR *v22; // r14
  __int64 v23; // rsi
  __int64 v24; // r12
  const WCHAR *v25; // rsi
  __int64 v26; // r15
  const WCHAR *v27; // r15
  __int64 v28; // rax
  int v29; // r12d
  int v30; // ecx
  unsigned int v31; // r9d
  __int64 v33; // rbx
  __int64 v34; // rax
  struct _RTL_RESOURCE *v35; // rcx
  DWORD v36; // eax
  WCHAR *v37; // rax
  __int64 v38; // rcx
  CCipherMill *v39; // rcx
  unsigned int v40; // edi
  const WCHAR *v41; // rdx
  __int64 v42; // rdx
  __int64 csz; // [rsp+20h] [rbp-A1h]
  const WCHAR *SourceString; // [rsp+50h] [rbp-71h]
  struct _UNICODE_STRING v45; // [rsp+58h] [rbp-69h] BYREF
  struct _UNICODE_STRING v46; // [rsp+68h] [rbp-59h] BYREF
  struct _UNICODE_STRING v47; // [rsp+78h] [rbp-49h] BYREF
  struct _UNICODE_STRING v48; // [rsp+88h] [rbp-39h] BYREF
  char DestinationString[24]; // [rsp+98h] [rbp-29h] BYREF
  __int64 v50; // [rsp+B0h] [rbp-11h]
  DWORD v51; // [rsp+118h] [rbp+57h]
  DWORD v52; // [rsp+118h] [rbp+57h]

  v12 = 0;
  v13 = 590610;
  v15 = a1;
  if ( a1 == 590610 && a2 && *((_DWORD *)a2 + 17) == 77 )
  {
    v16 = 1;
  }
  else
  {
    v16 = 0;
    if ( a1 == -2146893032 )
    {
      if ( a5 && a6 )
      {
        a5->BufferType = 1073741828;
        v31 = *((_DWORD *)a7 + 1) - a6->cbBuffer;
        a5->cbBuffer = v31;
        a5->pvBuffer = 0i64;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_8;
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x10u,
          (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
          v31);
      }
      else
      {
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_8;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
      }
      v12 = 0;
      goto LABEL_8;
    }
  }
  if ( (a10 & 0x100) != 0 || !v16 )
  {
    a8->pvBuffer = (void *)*((_QWORD *)a9 + 1);
    a8->cbBuffer = *((_DWORD *)a9 + 1);
  }
  if ( a1 != -2146893023 )
  {
    if ( !a1 )
      goto LABEL_8;
    if ( a1 < 0 )
    {
      if ( a1 != -2146892950 && a1 != -2146892949 )
        goto LABEL_64;
LABEL_8:
      if ( a8->cbBuffer && !v16 )
        goto LABEL_10;
      goto LABEL_64;
    }
    if ( (a1 & 0x1FFF0000) == 589824 )
      goto LABEL_8;
  }
LABEL_64:
  if ( (a10 & 0x100) != 0 && a8->pvBuffer )
  {
    if ( !a2 )
      return v15;
    (*(void (__fastcall **)(struct CSslContext *, void *))(*(_QWORD *)a2 + 16i64))(a2, a8->pvBuffer);
    v12 = 0;
    *(_QWORD *)&a8->cbBuffer = 0i64;
    a8->pvBuffer = 0i64;
    goto LABEL_11;
  }
LABEL_10:
  if ( !a2 )
    return v15;
LABEL_11:
  if ( !v16 )
  {
    if ( !v15 || v15 == 590614 || v15 == -2146892950 )
    {
      if ( a6 )
      {
        if ( *((_DWORD *)a7 + 1) < a6->cbBuffer )
        {
          if ( a5 )
          {
            a5->BufferType = 1073741829;
            a5->cbBuffer = a6->cbBuffer - *((_DWORD *)a7 + 1);
            a5->pvBuffer = 0i64;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
              v12 = 0;
            }
          }
        }
      }
      if ( !v15 )
      {
        v17 = *((_DWORD *)a2 + 17);
        if ( v17 != 4 && v17 != 51 && v17 != 79 || (*((_DWORD *)a2 + 34) & 0x40000000) != 0 )
          goto LABEL_44;
        *(_QWORD *)DestinationString = a2;
        *(_OWORD *)&DestinationString[8] = 0i64;
        v50 = 0i64;
        *a11 = 1;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
        v15 = CSslSerializeHelper::SerializeContextWorker(
                (CSslSerializeHelper *)DestinationString,
                (void (__fastcall *)(__int64, __int64 *))SslRelocateToken);
        if ( !v15 )
        {
          v18 = v50;
          v19 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)DestinationString + 8i64))(
                  *(_QWORD *)DestinationString,
                  (unsigned int)v50);
          *(_QWORD *)&DestinationString[8] = v19;
          if ( v19 )
          {
            HIDWORD(v50) = v18;
            *(_QWORD *)&DestinationString[16] = v19;
            v15 = CSslSerializeHelper::SerializeContextWorker(
                    (CSslSerializeHelper *)DestinationString,
                    (void (__fastcall *)(__int64, __int64 *))SslRelocateToken);
            if ( !v15 )
            {
              a4->pvBuffer = *(void **)&DestinationString[8];
              a4->cbBuffer = v50;
              *((_QWORD *)a2 + 17) |= 0x40000000ui64;
              v20 = *((_DWORD *)a2 + 17);
              if ( v20 != 4 && v20 != 79 )
              {
                v38 = *((_QWORD *)a2 + 19);
                if ( v38 )
                {
                  SslFreeObject(v38, 0i64);
                  *((_QWORD *)a2 + 19) = 0i64;
                }
                v12 = 1;
LABEL_44:
                v30 = *((_DWORD *)a2 + 17);
                if ( (unsigned int)(v30 - 3) <= 1 || v30 == 79 )
                {
                  v13 = 0;
                  goto LABEL_58;
                }
                if ( v12 )
                {
                  v39 = WPP_GLOBAL_Control;
                  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
                    || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
                  {
                    goto LABEL_82;
                  }
                  v42 = 21i64;
                }
                else
                {
                  if ( (*(unsigned __int8 (__fastcall **)(struct CSslContext *, CCipherMill **))(*(_QWORD *)a2 + 384i64))(
                         a2,
                         &WPP_GLOBAL_Control)
                    || (*((_DWORD *)a2 + 16) & 0x1000) == 0
                    || *((_DWORD *)a2 + 17) != 70 )
                  {
LABEL_58:
                    if ( a12 )
                    {
                      v33 = *((_QWORD *)a2 + 11);
                      if ( v33 )
                      {
                        RtlAcquireResourceShared((PRTL_RESOURCE)(v33 + 72), 1u);
                        v34 = *(_QWORD *)(v33 + 48);
                        v35 = (struct _RTL_RESOURCE *)(v33 + 72);
                        if ( v34 )
                        {
                          *a12 = *(union _LARGE_INTEGER *)(*(_QWORD *)(v34 + 24) + 72i64);
                          RtlReleaseResource(v35);
                          return v13;
                        }
                        RtlReleaseResource(v35);
                      }
                      a12->QuadPart = 0x7FFFFF36D5969FFFi64;
                    }
                    return v13;
                  }
                  v39 = WPP_GLOBAL_Control;
                  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
                    || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
                  {
LABEL_82:
                    v13 = 590694;
                    goto LABEL_58;
                  }
                  v42 = 22i64;
                }
                WPP_SF_(*((_QWORD *)v39 + 2), v42, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
                goto LABEL_82;
              }
              (*(void (__fastcall **)(struct CSslContext *))(*(_QWORD *)a2 + 264i64))(a2);
              if ( *((_BYTE *)a2 + 265) )
              {
                *((_BYTE *)a2 + 265) = 0;
LABEL_43:
                v12 = 0;
                goto LABEL_44;
              }
              v21 = 0i64;
              v22 = 0i64;
              v23 = (*(__int64 (__fastcall **)(struct CSslContext *))(*(_QWORD *)a2 + 248i64))(a2);
              v24 = (*(__int64 (__fastcall **)(struct CSslContext *))(*(_QWORD *)a2 + 320i64))(a2);
              if ( v23 )
                v21 = *(const WCHAR **)(v23 + 400);
              RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)a2 + 11) + 72i64), 1u);
              v25 = &Class;
              v26 = *(_QWORD *)(*((_QWORD *)a2 + 11) + 48i64);
              if ( v26
                && (v36 = CertNameToStrW(
                            *(_DWORD *)v26,
                            (PCERT_NAME_BLOB)(*(_QWORD *)(v26 + 24) + 80i64),
                            0x20000003u,
                            0i64,
                            0),
                    (v52 = v36) != 0)
                && (v37 = (WCHAR *)SPExternalAlloc(2 * v36), (v22 = v37) != 0i64) )
              {
                CertNameToStrW(*(_DWORD *)v26, (PCERT_NAME_BLOB)(*(_QWORD *)(v26 + 24) + 80i64), 0x20000003u, v37, v52);
                RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a2 + 11) + 72i64));
              }
              else
              {
                RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a2 + 11) + 72i64));
                if ( !v22 )
                {
                  SourceString = &Class;
LABEL_33:
                  v27 = &Class;
                  if ( v21 )
                    v27 = v21;
                  if ( v24 )
                    v25 = (const WCHAR *)v24;
                  v51 = *(_DWORD *)(*((_QWORD *)a2 + 11) + 8i64);
                  if ( (*((_BYTE *)a2 + 32) & 8) != 0 && (v28 = *((_QWORD *)a2 + 1)) != 0 )
                    v29 = *(_DWORD *)(v28 + 28);
                  else
                    v29 = 0;
                  if ( (g_dwEventLogging & 4) != 0 )
                  {
                    v40 = *((_DWORD *)a2 + 16);
                    MapProtocolToString(v40, &v48);
                    v41 = (const WCHAR *)pszClientString;
                    if ( (v40 & 0x40051555) != 0 )
                      v41 = pszServerString;
                    RtlInitUnicodeString((PUNICODE_STRING)DestinationString, v41);
                    RtlInitUnicodeString(&v47, v25);
                    RtlInitUnicodeString(&v46, v27);
                    RtlInitUnicodeString(&v45, SourceString);
                    LODWORD(csz) = v29;
                    SchEventWrite(
                      &SSLEVENT_HANDSHAKE_INFO,
                      L"uuddpuuu",
                      (__int64)DestinationString,
                      &v48,
                      csz,
                      v51,
                      a3,
                      &v47,
                      &v46,
                      &v45);
                  }
                  if ( v22 )
                    SPExternalFree(v22);
                  goto LABEL_43;
                }
              }
              SourceString = v22;
              goto LABEL_33;
            }
            (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)DestinationString + 16i64))(
              *(_QWORD *)DestinationString,
              *(_QWORD *)&DestinationString[8]);
          }
          else
          {
            return 14;
          }
        }
      }
    }
    return v15;
  }
  return 0i64;
}
// 18000DD53: conditional instruction was optimized away because ecx.4 is in (<-7FF6FCE8|80090319..80090320|>=80090322u)
// 1800382AA: variable 'csz' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

