//----- (000000018000E5E4) ----------------------------------------------------
__int64 __fastcall GetSslProvHandle(const unsigned __int16 *a1, unsigned __int64 *a2)
{
  int v4; // ebp
  unsigned __int64 SslProvHandleInCache; // rdi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  CCipherMill *v8; // rcx
  unsigned int CachedSslProv; // eax
  __int64 v11; // rdx
  __int64 v12; // r8
  __int64 v13; // [rsp+20h] [rbp-38h]
  __int64 v14[5]; // [rsp+30h] [rbp-28h] BYREF

  v4 = 0;
  RtlAcquireResourceShared(g_pSslProvCacheRWLock, 1u);
  SslProvHandleInCache = FindSslProvHandleInCache(a1);
  RtlReleaseResource(g_pSslProvCacheRWLock);
  if ( SslProvHandleInCache )
    goto LABEL_2;
  CachedSslProv = CreateCachedSslProv((struct CACHED_SSL_PROVIDER *)v14, a1);
  v7 = CachedSslProv;
  if ( !CachedSslProv )
  {
    v4 = 1;
    RtlAcquireResourceExclusive(g_pSslProvCacheRWLock, 1u);
    SslProvHandleInCache = FindSslProvHandleInCache(a1);
    if ( SslProvHandleInCache )
    {
      DestroyCachedSslProv((struct CACHED_SSL_PROVIDER *)v14);
      v4 = 0;
    }
    else
    {
      SslProvHandleInCache = v14[0];
      CacheClientSideSslProv((struct CACHED_SSL_PROVIDER *)v14);
    }
    RtlReleaseResource(g_pSslProvCacheRWLock);
LABEL_2:
    v6 = SslIncrementProviderReferenceCount(SslProvHandleInCache);
    v7 = v6;
    if ( v6 )
    {
      v8 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_qD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x18u,
          &WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids,
          SslProvHandleInCache,
          v6);
        v8 = WPP_GLOBAL_Control;
      }
      if ( !v4 )
        goto LABEL_5;
      DestroyCachedSslProv((struct CACHED_SSL_PROVIDER *)v14);
    }
    else
    {
      *a2 = SslProvHandleInCache;
    }
    goto LABEL_4;
  }
  v8 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
    return v7;
  if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    WPP_SF_qSD(*((_QWORD *)WPP_GLOBAL_Control + 2), v11, v12, v14, a1, CachedSslProv);
LABEL_4:
    v8 = WPP_GLOBAL_Control;
  }
LABEL_5:
  if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)v8 + 28) & 1) != 0 && v7 || (*((_BYTE *)v8 + 28) & 4) != 0) )
  {
    LODWORD(v13) = v7;
    WPP_SF_DD(*((_QWORD *)v8 + 2), 0x19u, (__int64)&WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids, v7, v13);
  }
  return v7;
}
// 1800384E4: variable 'v11' is possibly undefined
// 1800384E4: variable 'v12' is possibly undefined
// 18003855B: variable 'v13' is possibly undefined
// 1800984E8: using guessed type __int64 __fastcall SslIncrementProviderReferenceCount(_QWORD);

