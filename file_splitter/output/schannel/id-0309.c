// File count: 309
// Total lines: 39
-----------------------------------------
__int64 __fastcall CacheClientSideSslProv(struct CACHED_SSL_PROVIDER *a1)
{
  unsigned int v2; // ebx
  CCipherMill *v3; // rcx
  unsigned int v5; // [rsp+20h] [rbp-18h]

  v2 = 0;
  v3 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids);
    v3 = WPP_GLOBAL_Control;
  }
  if ( g_cCachedPagedSslProvs >= 0x20 )
  {
    if ( v3 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v3 + 28) & 1) != 0 )
    {
      WPP_SF_(*((_QWORD *)v3 + 2), 21i64, &WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids);
      v3 = WPP_GLOBAL_Control;
    }
    v2 = -2146893052;
  }
  else
  {
    *((_QWORD *)&g_rgCachedPagedSslProvs + 2 * g_cCachedPagedSslProvs) = *(_QWORD *)a1;
    *((_QWORD *)&g_rgCachedPagedSslProvs + 2 * g_cCachedPagedSslProvs++ + 1) = *((_QWORD *)a1 + 1);
    v3 = WPP_GLOBAL_Control;
  }
  if ( v3 != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)v3 + 28) & 1) != 0 && v2 || (*((_BYTE *)v3 + 28) & 4) != 0) )
  {
    v5 = v2;
    WPP_SF_DD(*((_QWORD *)v3 + 2), 0x16u, (__int64)&WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids, v2, v5);
  }
  return v2;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092A90: using guessed type unsigned int g_cCachedPagedSslProvs;
