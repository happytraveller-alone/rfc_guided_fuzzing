// File count: 884
// Total lines: 60
-----------------------------------------
void __fastcall SslDomainChangeCallback(enum _POLICY_NOTIFICATION_INFORMATION_CLASS a1)
{
  int v1; // eax
  struct _UNICODE_STRING v2; // xmm0
  struct _UNICODE_STRING v3; // [rsp+20h] [rbp-18h] BYREF
  struct _UNICODE_STRING *v4; // [rsp+48h] [rbp+10h] BYREF

  if ( a1 == PolicyNotifyDnsDomainInformation )
  {
    v4 = 0i64;
    v3 = 0i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 88i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
    v1 = LsaIQueryInformationPolicyTrusted(12i64, &v4);
    if ( v1 >= 0 )
    {
      if ( (int)SslDuplicateString(&v3, v4 + 1) >= 0 )
      {
        if ( RtlAcquireResourceExclusive(&SslGlobalLock, 1u) )
        {
          SslFreeString(&SslGlobalDnsDomainName);
          v2 = v3;
          v3.Buffer = 0i64;
          SslGlobalDnsDomainName = v2;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_S(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0x5Bu,
              (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
              SslGlobalDnsDomainName.Buffer);
          }
          RtlReleaseResource(&SslGlobalLock);
        }
        else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
               && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 90i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
        }
      }
    }
    else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        89i64,
        &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
        (unsigned int)v1);
    }
    if ( v4 )
      LsaIFree_LSAPR_POLICY_INFORMATION(12i64);
    SslFreeString(&v3);
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098220: using guessed type __int64 __fastcall LsaIFree_LSAPR_POLICY_INFORMATION(_QWORD);
// 180098228: using guessed type __int64 __fastcall LsaIQueryInformationPolicyTrusted(_QWORD, _QWORD);
