// File count: 1207
// Total lines: 86
----------------------------------------
unsigned __int8 __fastcall CSslCredential::IsClientCredApplicable(
        CSslCredential *this,
        int a2,
        int a3,
        const struct CTlsSignatureSuiteList *a4,
        struct _TLS_PARAMETERS *a5,
        unsigned int a6)
{
  struct CEccCurveInfo *v6; // rbp
  _DWORD *v9; // rax
  int v10; // edi
  CCipherMill *v11; // rcx
  unsigned __int16 v12; // dx
  const wchar_t *v13; // r9
  __int64 v14; // rcx
  int v16; // r8d
  unsigned int v17; // r9d
  struct CEccCurveInfo *v18; // [rsp+70h] [rbp+8h] BYREF

  v6 = 0i64;
  v18 = 0i64;
  v9 = (_DWORD *)*((_QWORD *)this + 4);
  if ( !v9 || *v9 != 1 || !*((_QWORD *)this + 54) && !*((_DWORD *)this + 33) )
    return 0;
  v10 = *((_DWORD *)this + 33);
  if ( a2 != v10 || (a3 & 0xA2A80) == 0 && v10 == 8707 )
    return 0;
  if ( a4 )
  {
    if ( !CTlsSignatureSuiteList::IsSupportedSignatureKey(a4, v10, *((_DWORD *)this + 107), a3, *((_DWORD *)this + 35)) )
    {
      v11 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v12 = 40;
LABEL_17:
        v13 = &Class;
        v14 = *((_QWORD *)v11 + 2);
        if ( *((_QWORD *)this + 50) )
          v13 = (const wchar_t *)*((_QWORD *)this + 50);
        WPP_SF_S(v14, v12, (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v13);
        return 0;
      }
      return 0;
    }
    if ( !CTlsSignatureSuiteList::IsSupportedSignatureSuiteList(a4, (CSslCredential *)((char *)this + 512)) )
    {
      v11 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v12 = 41;
        goto LABEL_17;
      }
      return 0;
    }
  }
  if ( v10 == 8707 )
  {
    if ( (unsigned int)CCipherMill::GetCurveInfo(this, *((_DWORD *)this + 35), &v18) )
      return 0;
    v6 = v18;
  }
  if ( a6 )
  {
    v16 = *((_DWORD *)this + 33);
    v17 = v16 == 8707 ? *((_DWORD *)this + 34) : *((_DWORD *)this + 107);
    if ( IsCertificateBlacklisted(
           a5,
           a6,
           v16,
           v17,
           v6,
           0,
           0,
           (const unsigned __int16 *)this + 72,
           (const unsigned __int16 *)this + 136,
           0i64,
           1) )
    {
      return 0;
    }
  }
  return 1;
}
// 18006006B: variable 'this' is possibly undefined
