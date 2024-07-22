//----- (000000018001C410) ----------------------------------------------------
__int64 __fastcall CCipherMill::FindAcceptableCipherSuiteAndCred(
        CCipherMill *this,
        struct CSsl3TlsServerContext *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned __int8 a5,
        struct _UNICODE_STRING *a6,
        unsigned __int8 a7,
        struct CCipherSuiteInfo **a8,
        struct CSslCredential **a9,
        unsigned int *a10,
        unsigned __int8 *a11)
{
  __int64 v11; // rbp
  struct CCipherSuiteInfo **v14; // r13
  struct CSslCredential **v15; // rax
  unsigned __int8 *v16; // rbx
  unsigned int *v17; // rcx
  unsigned int AcceptableCipherSuite; // ebx
  unsigned __int64 v19; // rsi
  __int64 v20; // rdi
  char v21; // r12
  enum _eTlsHashAlgorithm v22; // r9d
  int v23; // r11d
  __int64 v24; // rax
  CSessionCacheItem *v25; // rcx
  __int64 v26; // rax
  int v27; // edx
  CCipherMill *v28; // r10
  __int64 v29; // r8
  unsigned int *v30; // rdx
  unsigned int *v31; // rax
  unsigned int AcceptableCredential; // eax
  struct CSslCredential **v33; // rcx
  struct CSslCredential *v34; // rax
  struct CSslCredential **v36; // rcx
  unsigned int PrfHashDetails; // eax
  struct CSslCredential **v38; // rcx
  struct _UNICODE_STRING *v39; // [rsp+20h] [rbp-A8h]
  __int64 v40; // [rsp+28h] [rbp-A0h]
  unsigned __int8 v41; // [rsp+50h] [rbp-78h]
  int v42; // [rsp+54h] [rbp-74h]
  enum _eTlsHashAlgorithm v43; // [rsp+58h] [rbp-70h] BYREF
  unsigned int v44; // [rsp+5Ch] [rbp-6Ch] BYREF
  unsigned int v45; // [rsp+60h] [rbp-68h]
  struct CSslCredential *v46; // [rsp+68h] [rbp-60h] BYREF
  struct CCipherSuiteInfo *v47; // [rsp+70h] [rbp-58h]
  struct CSslCredential *v48; // [rsp+78h] [rbp-50h]
  unsigned __int64 v49; // [rsp+80h] [rbp-48h]
  bool v50; // [rsp+D0h] [rbp+8h]
  CSessionCacheItem *v51; // [rsp+D8h] [rbp+10h] BYREF

  v11 = a4;
  if ( !a2 )
    return 2148074333i64;
  if ( !a3 )
    return 2148074333i64;
  if ( !a4 )
    return 2148074333i64;
  v14 = a8;
  if ( !a8 )
    return 2148074333i64;
  v15 = a9;
  if ( !a9 )
    return 2148074333i64;
  if ( !a10 )
    return 2148074333i64;
  v16 = a11;
  if ( !a11 )
    return 2148074333i64;
  *a10 = 0;
  v17 = (unsigned int *)xmmword_1800925B0;
  *v15 = 0i64;
  if ( (*((_DWORD *)a2 + 34) & 0x20000000) != 0 )
    v17 = (unsigned int *)*(&xmmword_1800925B0 + 1);
  *v16 = 0;
  AcceptableCipherSuite = -2146893007;
  *v14 = 0i64;
  v47 = 0i64;
  v48 = 0i64;
  v45 = 0;
  v41 = 0;
  if ( !v17 || (v19 = *(_QWORD *)v17, v20 = v17[2], !*(_QWORD *)v17) || !(_DWORD)v20 )
  {
    AcceptableCipherSuite = -2146893052;
    goto LABEL_45;
  }
  v50 = (*((_DWORD *)a2 + 16) & 0x1000) != 0;
  v21 = a5;
  v22 = TlsHashAlgorithm_None;
  v43 = TlsHashAlgorithm_None;
  v23 = 0;
  v42 = 0;
  if ( a5 )
  {
    v24 = *(_QWORD *)a2;
    v51 = 0i64;
    (*(void (__fastcall **)(struct CSsl3TlsServerContext *, CSessionCacheItem **, unsigned int *, _QWORD))(v24 + 232))(
      a2,
      &v51,
      a3,
      0i64);
    if ( !v51 )
    {
      AcceptableCipherSuite = -2146893052;
      goto LABEL_45;
    }
    RtlAcquireResourceShared((PRTL_RESOURCE)((char *)v51 + 72), 1u);
    v25 = v51;
    if ( v50 )
    {
      PrfHashDetails = CSessionCacheItem::GetPrfHashDetails(v51, 0i64, &v43);
      v25 = v51;
      if ( PrfHashDetails )
      {
        AcceptableCipherSuite = PrfHashDetails;
        RtlReleaseResource((PRTL_RESOURCE)((char *)v51 + 72));
        goto LABEL_45;
      }
    }
    else
    {
      v26 = *((_QWORD *)v51 + 22);
      if ( v26 )
        v27 = *(_DWORD *)(v26 + 28);
      else
        v27 = 0;
      v42 = v27;
    }
    RtlReleaseResource((PRTL_RESOURCE)((char *)v25 + 72));
    v22 = v43;
    v23 = v42;
  }
  v49 = v19 + 864 * v20;
  if ( v19 >= v49 )
  {
LABEL_45:
    v36 = a9;
    *v14 = 0i64;
    *v36 = 0i64;
    *a10 = 0;
    *a11 = 0;
    return AcceptableCipherSuite;
  }
  v28 = WPP_GLOBAL_Control;
  while ( 1 )
  {
    v29 = *(unsigned int *)(v19 + 28);
    v46 = 0i64;
    v44 = 0;
    LOBYTE(v51) = 0;
    if ( !(_DWORD)v29 || (v30 = &a3[v11], v31 = a3, a3 >= v30) )
    {
LABEL_26:
      if ( v28 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v28 + 28) & 4) != 0 )
      {
        WPP_SF_S(
          *((_QWORD *)v28 + 2),
          0x26u,
          (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
          (const wchar_t *)(v19 + 74));
LABEL_57:
        v28 = WPP_GLOBAL_Control;
      }
LABEL_28:
      AcceptableCipherSuite = -2146893007;
      goto LABEL_29;
    }
    while ( (_DWORD)v29 != *v31 )
    {
      if ( ++v31 >= v30 )
        goto LABEL_26;
    }
    if ( v21 && v23 != (_DWORD)v29 && !v50 )
    {
      if ( v28 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v28 + 28) & 4) != 0 )
      {
        LODWORD(v40) = v23;
        LODWORD(v39) = v29;
        WPP_SF_SDD(*((_QWORD *)v28 + 2), 0x27u, v29, (const wchar_t *)(v19 + 74), v39, v40);
        goto LABEL_57;
      }
      goto LABEL_28;
    }
    AcceptableCipherSuite = CCipherMill::FindAcceptableCipherSuite(
                              (CCipherMill *)v17,
                              a2,
                              (struct CCipherSuiteInfo *)v19,
                              v21,
                              a6,
                              a7,
                              v22,
                              &v44,
                              (unsigned __int8 *)&v51);
    if ( AcceptableCipherSuite )
      goto LABEL_55;
    if ( *(_DWORD *)(v19 + 48) == 4 )
    {
      *v14 = (struct CCipherSuiteInfo *)v19;
      return AcceptableCipherSuite;
    }
    AcceptableCredential = CCipherMill::FindAcceptableCredential(
                             (CCipherMill *)v17,
                             a2,
                             (struct CCipherSuiteInfo *)v19,
                             v21,
                             a6,
                             a7,
                             &v46);
    AcceptableCipherSuite = AcceptableCredential;
    if ( !AcceptableCredential )
    {
      v33 = a9;
      v34 = v46;
      *v14 = (struct CCipherSuiteInfo *)v19;
      *v33 = v34;
      *a10 = v44;
      *a11 = (unsigned __int8)v51;
      return AcceptableCipherSuite;
    }
    if ( AcceptableCredential == -2146893007 && v46 && !v47 )
    {
      v48 = v46;
      v45 = v44;
      v41 = (unsigned __int8)v51;
      v47 = (struct CCipherSuiteInfo *)v19;
LABEL_55:
      v28 = WPP_GLOBAL_Control;
      goto LABEL_29;
    }
    v28 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_S(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x28u,
        (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
        (const wchar_t *)(v19 + 74));
      v28 = WPP_GLOBAL_Control;
    }
LABEL_29:
    v19 += 864i64;
    if ( v19 >= v49 )
      break;
    v22 = v43;
    v23 = v42;
  }
  if ( !AcceptableCipherSuite )
    return AcceptableCipherSuite;
  if ( !v47 )
    goto LABEL_45;
  v38 = a9;
  AcceptableCipherSuite = 0;
  *v14 = v47;
  *v38 = v48;
  *a10 = v45;
  *a11 = v41;
  return AcceptableCipherSuite;
}
// 18001C6A4: variable 'v17' is possibly undefined
// 180030A87: variable 'v39' is possibly undefined
// 180030A87: variable 'v40' is possibly undefined

