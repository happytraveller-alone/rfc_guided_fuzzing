//----- (00000001800567A8) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::PickServerCredential(
        CCredentialGroup *this,
        struct CCipherSuiteInfo *a2,
        struct CEccCurveInfo *a3,
        int a4,
        char a5,
        const struct CTlsSignatureSuiteList *a6,
        struct _TLS_PARAMETERS *a7,
        unsigned int a8,
        struct _UNICODE_STRING *a9,
        unsigned __int8 a10,
        struct CSessionCacheServerItem *a11,
        struct CSslCredential **a12)
{
  struct CSslCredential **v12; // r15
  struct CSslCredential *v14; // rdi
  __int64 v15; // r12
  __int64 result; // rax
  unsigned int v17; // ebp
  struct CSessionCacheServerItem *v18; // rsi
  __int64 v19; // rax
  CCredentialGroup *v20; // r13
  CCredentialGroup *v21; // r14
  __int64 v22; // rbx
  int IsServerCredApplicable; // eax
  int Length; // [rsp+50h] [rbp-58h]
  void *Source1; // [rsp+58h] [rbp-50h]
  struct _RTL_RESOURCE *Resource; // [rsp+60h] [rbp-48h]

  v12 = a12;
  Source1 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  Length = 0;
  if ( !a12 )
    return 87i64;
  *a12 = 0i64;
  if ( !*((_DWORD *)this + 7) )
    return 2148074289i64;
  if ( (*((_BYTE *)this + 156) & 0x40) == 0 )
    goto LABEL_10;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids);
  result = CCredentialGroup::CheckForCredentialRenewal(this);
  if ( !(_DWORD)result )
  {
LABEL_10:
    Resource = (struct _RTL_RESOURCE *)((char *)this + 48);
    v17 = -2146893007;
    RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
    v18 = a11;
    if ( a11 )
    {
      RtlAcquireResourceShared((PRTL_RESOURCE)((char *)a11 + 72), 1u);
      v19 = *((_QWORD *)a11 + 42);
      if ( v19 )
      {
        Length = 20;
        Source1 = (void *)(v19 + 40);
      }
    }
    v20 = (CCredentialGroup *)((char *)this + 32);
    v21 = (CCredentialGroup *)*((_QWORD *)this + 4);
    if ( v21 != (CCredentialGroup *)((char *)this + 32) )
    {
      while ( 1 )
      {
        v22 = (__int64)v21 - 8;
        v21 = *(CCredentialGroup **)v21;
        if ( !Source1
          || v22 != -40 && Length == 20 && RtlCompareMemory(Source1, (const void *)(v22 + 40), 0x14ui64) == 20 )
        {
          IsServerCredApplicable = CSslCredential::IsServerCredApplicable(
                                     v22,
                                     (__int64)a2,
                                     (__int64)a3,
                                     a4,
                                     (__int64)a6,
                                     a7,
                                     a8,
                                     a9,
                                     a10);
          if ( IsServerCredApplicable == 1 )
          {
            if ( !v14 || *(_BYTE *)(v22 + 80) != a5 )
            {
              v17 = 0;
              v14 = (struct CSslCredential *)v22;
              if ( *(_BYTE *)(v22 + 80) != a5 )
              {
LABEL_27:
                v18 = a11;
                v12 = a12;
                break;
              }
            }
          }
          else if ( IsServerCredApplicable == 2 && !v15 )
          {
            v15 = v22;
          }
        }
        if ( v21 == v20 )
          goto LABEL_27;
      }
    }
    if ( v18 )
      RtlReleaseResource((PRTL_RESOURCE)((char *)v18 + 72));
    RtlReleaseResource(Resource);
    result = v17;
    if ( !v14 )
      v14 = (struct CSslCredential *)v15;
    *v12 = v14;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;

