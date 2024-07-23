// File count: 440
// Total lines: 317
----------------------------------------
__int64 __fastcall CCipherMill::FindAcceptableCredential(
        CCipherMill *this,
        struct CSsl3TlsServerContext *a2,
        struct CCipherSuiteInfo *a3,
        char a4,
        struct _UNICODE_STRING *a5,
        unsigned __int8 a6,
        struct CSslCredential **a7)
{
  struct CSslCredential **v7; // r14
  int v10; // eax
  unsigned int v11; // esi
  __int64 v12; // rbp
  char v13; // r12
  int v14; // eax
  bool v15; // zf
  struct CSessionCacheServerItem *v16; // r13
  __int64 v17; // rbx
  __int64 v18; // r12
  __int64 v19; // rax
  _QWORD *v20; // r12
  void *v21; // r14
  _QWORD *v22; // rax
  int v23; // r13d
  __int64 v24; // rbp
  int IsServerCredApplicable; // eax
  char v26; // al
  char v27; // cl
  unsigned int v28; // ebp
  unsigned int *v30; // rax
  unsigned __int64 v31; // rdx
  int v32; // edx
  unsigned int v33; // r10d
  struct _TLS_PARAMETERS *v34; // r11
  const struct CTlsSignatureSuiteList *v35; // r8
  int v36; // r9d
  CCredentialGroup *v37; // rcx
  unsigned int v38; // eax
  SIZE_T v39; // rax
  unsigned int v40; // eax
  CCipherMill *v41; // rcx
  __int64 v42; // rdx
  __int64 v43; // rax
  _QWORD *v44; // [rsp+60h] [rbp-88h]
  struct CSessionCacheServerItem *v45; // [rsp+68h] [rbp-80h] BYREF
  const struct CTlsSignatureSuiteList *v46; // [rsp+70h] [rbp-78h]
  void *Source1; // [rsp+78h] [rbp-70h]
  unsigned int v48; // [rsp+80h] [rbp-68h]
  int v49; // [rsp+84h] [rbp-64h]
  __int64 v50; // [rsp+88h] [rbp-60h]
  struct _TLS_PARAMETERS *v51; // [rsp+90h] [rbp-58h]
  struct CSessionCacheServerItem *v52; // [rsp+98h] [rbp-50h]
  PRTL_RESOURCE Resource; // [rsp+A0h] [rbp-48h]
  char v54; // [rsp+F0h] [rbp+8h]
  struct CEccCurveInfo *v55; // [rsp+F0h] [rbp+8h]
  SIZE_T Length; // [rsp+F8h] [rbp+10h] BYREF

  v7 = a7;
  if ( a2 && a3 && a7 )
  {
    v10 = *((_DWORD *)a3 + 13);
    v11 = -2146893007;
    if ( v10 == 4 || *((_DWORD *)a2 + 16) == 4096 )
    {
      v12 = *((_QWORD *)a2 + 10);
      v45 = 0i64;
      v13 = 1;
      *a7 = 0i64;
      if ( v10 == 4 && !*(_BYTE *)(v12 + 900) )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 53i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
        return v11;
      }
    }
    else
    {
      v12 = *((_QWORD *)a2 + 10);
      v13 = 0;
      v45 = 0i64;
      *a7 = 0i64;
    }
    if ( a4 )
    {
      (*(void (__fastcall **)(struct CSsl3TlsServerContext *, struct CSessionCacheServerItem **))(*(_QWORD *)a2 + 232i64))(
        a2,
        &v45);
      if ( !v45 )
        return (unsigned int)-2146893052;
    }
    v14 = *((_DWORD *)a2 + 16);
    v46 = 0i64;
    v49 = v14;
    if ( (v14 & 0x41400) != 0 )
      v46 = (struct CSsl3TlsServerContext *)((char *)a2 + 510);
    if ( *(_BYTE *)(v12 + 900) && v13 )
    {
      v30 = (unsigned int *)*((_QWORD *)a3 + 106);
      Source1 = v30;
      if ( !v30 )
        return (unsigned int)-2146893052;
      v31 = *(_QWORD *)v30;
      v55 = *(struct CEccCurveInfo **)v30;
      if ( *(_QWORD *)v30 < *(_QWORD *)v30 + 780 * (unsigned __int64)v30[2] )
      {
        v18 = 0i64;
        while ( 1 )
        {
          v11 = CSsl3TlsServerContext::LookupEccCurveType(a2, *(_DWORD *)(v31 + 772));
          if ( !v11 )
          {
            v32 = *((_DWORD *)a2 + 34);
            v33 = *(_DWORD *)(v12 + 196);
            v34 = *(struct _TLS_PARAMETERS **)(v12 + 200);
            v35 = v46;
            v36 = *((_DWORD *)a2 + 16);
            if ( !*((_BYTE *)a2 + 925) )
              v35 = 0i64;
            v37 = (CCredentialGroup *)*((_QWORD *)a2 + 10);
            Length = 0i64;
            v38 = CCredentialGroup::PickServerCredential(
                    v37,
                    a3,
                    v55,
                    v36,
                    (v32 & 0x8000000) != 0i64,
                    v35,
                    v34,
                    v33,
                    a5,
                    a6,
                    v45,
                    (struct CSslCredential **)&Length);
            v11 = v38;
            if ( !v38 )
            {
              *v7 = (struct CSslCredential *)Length;
              return v11;
            }
            if ( v38 == -2146893007 && !v18 && (v39 = Length) != 0 )
            {
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  56i64,
                  &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
                  *((unsigned int *)v55 + 193));
                v39 = Length;
              }
              v18 = v39;
            }
            else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                   && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                57i64,
                &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
                *((unsigned int *)v55 + 193));
            }
          }
          v31 = (unsigned __int64)v55 + 780;
          v55 = (struct CEccCurveInfo *)v31;
          if ( v31 >= *(_QWORD *)Source1 + 780 * (unsigned __int64)*((unsigned int *)Source1 + 2) )
            goto LABEL_89;
        }
      }
      return v11;
    }
    v15 = *((_BYTE *)a2 + 925) == 0;
    v16 = v45;
    v48 = *(_DWORD *)(v12 + 196);
    v51 = *(struct _TLS_PARAMETERS **)(v12 + 200);
    v52 = v45;
    if ( v15 )
      v46 = 0i64;
    v54 = (*((_DWORD *)a2 + 34) & 0x8000000) != 0i64;
    v15 = *(_DWORD *)(v12 + 28) == 0;
    v17 = 0i64;
    v50 = 0i64;
    v18 = 0i64;
    Source1 = 0i64;
    LODWORD(Length) = 0;
    if ( v15 )
      goto LABEL_85;
    if ( (*(_BYTE *)(v12 + 156) & 0x40) != 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids);
      v40 = CCredentialGroup::CheckForCredentialRenewal((CCredentialGroup *)v12);
      if ( v40 )
      {
        v28 = v40;
        v11 = v40;
        goto LABEL_70;
      }
    }
    Resource = (PRTL_RESOURCE)(v12 + 48);
    RtlAcquireResourceShared((PRTL_RESOURCE)(v12 + 48), 1u);
    if ( v16 )
    {
      RtlAcquireResourceShared((PRTL_RESOURCE)((char *)v16 + 72), 1u);
      v19 = *((_QWORD *)v16 + 42);
      if ( v19 )
      {
        LODWORD(Length) = 20;
        Source1 = (void *)(v19 + 40);
      }
    }
    v20 = *(_QWORD **)(v12 + 32);
    v44 = (_QWORD *)(v12 + 32);
    if ( v20 == (_QWORD *)(v12 + 32) )
    {
LABEL_30:
      v28 = v11;
      if ( v16 )
        RtlReleaseResource((PRTL_RESOURCE)((char *)v16 + 72));
      RtlReleaseResource(Resource);
      if ( v17 )
        v18 = v17;
      else
        v18 = v50;
      if ( !v11 )
        goto LABEL_35;
LABEL_70:
      if ( v28 == -2146893007 && v18 )
      {
        v41 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          v42 = 54i64;
LABEL_88:
          WPP_SF_(*((_QWORD *)v41 + 2), v42, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
          goto LABEL_89;
        }
        goto LABEL_89;
      }
LABEL_85:
      v41 = WPP_GLOBAL_Control;
      v18 = 0i64;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v42 = 55i64;
        goto LABEL_88;
      }
LABEL_89:
      if ( v11 && v18 )
      {
        v11 = -2146893007;
LABEL_35:
        *v7 = (struct CSslCredential *)v18;
      }
      return v11;
    }
    v21 = Source1;
    v22 = (_QWORD *)(v12 + 32);
    v23 = Length;
    while ( 1 )
    {
      v24 = (__int64)(v20 - 1);
      v20 = (_QWORD *)*v20;
      if ( !v21 )
        goto LABEL_25;
      if ( v24 == -40 || v23 != 20 )
        goto LABEL_82;
      if ( RtlCompareMemory(v21, (const void *)(v24 + 40), 0x14ui64) == 20 )
      {
LABEL_25:
        IsServerCredApplicable = CSslCredential::IsServerCredApplicable(
                                   v24,
                                   (__int64)a3,
                                   0i64,
                                   v49,
                                   (__int64)v46,
                                   v51,
                                   v48,
                                   a5,
                                   a6);
        if ( IsServerCredApplicable == 1 )
        {
          if ( !v17 || (v26 = *(_BYTE *)(v24 + 80), v27 = v54, v26 != v54) )
          {
            v26 = *(_BYTE *)(v24 + 80);
            v17 = v24;
            v11 = 0;
            v27 = v54;
          }
          if ( v26 != v27 )
          {
LABEL_29:
            v7 = a7;
            v16 = v52;
            goto LABEL_30;
          }
        }
        else if ( IsServerCredApplicable == 2 )
        {
          v43 = v50;
          if ( !v50 )
            v43 = v24;
          v50 = v43;
        }
      }
      v22 = v44;
LABEL_82:
      if ( v20 == v22 )
        goto LABEL_29;
    }
  }
  return 2148074333i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
