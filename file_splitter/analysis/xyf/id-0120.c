//----- (0000000180009F90) ----------------------------------------------------
__int64 __fastcall CSslContextManager::InstantiateClientContext(
        CSslContextManager *this,
        const unsigned __int16 *a2,
        struct CCredentialGroup *a3,
        struct CSslParentContext **a4,
        __int64 a5)
{
  CSessionCacheManager *v5; // rbx
  unsigned __int16 *v8; // rdi
  unsigned int v9; // eax
  __int64 v10; // r8
  struct CSessionCacheItem *v11; // rsi
  char v12; // r15
  CCipherMill *v13; // rcx
  unsigned int v14; // ebx
  __int64 v15; // rcx
  int v16; // ebx
  unsigned __int64 v17; // r12
  __int64 v18; // rbp
  unsigned int v19; // ebp
  wchar_t *v20; // rax
  CSsl3TlsClientContext *v21; // rax
  CTls13ClientContext *v22; // rax
  CTls13ClientContext *v23; // rdi
  unsigned int v24; // esi
  _QWORD *v25; // rax
  int v26; // ecx
  struct CSslParentContext **v27; // rax
  struct CSslParentContext *v28; // r8
  const char *v30; // rax
  unsigned __int8 *v31; // rax
  CTls13ClientContext *v32; // rbp
  struct CTlsRecord *Record; // rax
  void *v34; // rcx
  struct CSessionCacheItem *v35; // [rsp+60h] [rbp+8h] BYREF
  struct CSslParentContext **v36; // [rsp+78h] [rbp+20h]

  v36 = a4;
  v35 = this;
  v5 = CSessionCacheManager::m_pSessionCacheManager;
  v8 = 0i64;
  v9 = CSessionCacheManager::ComputeClientCacheIndex(CSessionCacheManager::m_pSessionCacheManager, a2);
  if ( CSessionCacheTable::LookupCacheByName(
         (CSessionCacheTable *)(*((_QWORD *)v5 + 5) + 152i64 * (v9 / *((_DWORD *)v5 + 13))),
         v9 % *((_DWORD *)v5 + 13),
         a2,
         a3,
         &v35) )
  {
    v11 = v35;
    v12 = 1;
  }
  else
  {
    v11 = 0i64;
    v35 = 0i64;
    v12 = 0;
  }
  v13 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v30 = "FOUND";
    if ( !v12 )
      v30 = "NO ENTRY";
    WPP_SF_Ss(*((_QWORD *)WPP_GLOBAL_Control + 2), (__int64)"NO ENTRY", v10, a2, v30);
  }
  if ( !v12 )
  {
    CSessionCacheManager::AcquireCacheTableLock((__int64)v13, a2, 0i64);
    v14 = CSessionCacheManager::CacheRetrieveNewClientItem(CSessionCacheManager::m_pSessionCacheManager, a2, &v35);
    CSessionCacheManager::ReleaseCacheTableLock(v15, a2, 0i64);
    if ( v14 )
      return v14;
    v11 = v35;
  }
  v16 = *((_DWORD *)a3 + 38) & 0x800A2AAA;
  v17 = a5 & 0x100000000i64;
  if ( (a5 & 0x100000000i64) != 0 && (*((_DWORD *)a3 + 38) & 0x800A0AAA) != 0 )
    return 2148074333i64;
  if ( (*((_DWORD *)a3 + 38) & 0xA2AA0) == 0 )
    return 2148074289i64;
  if ( a2 )
  {
    v18 = -1i64;
    do
      ++v18;
    while ( a2[v18] );
    v19 = v18 + 1;
    v20 = (wchar_t *)SPExternalAlloc(2 * v19);
    v8 = v20;
    if ( !v20 )
      return 14i64;
    wcscpy_s(v20, v19, a2);
  }
  if ( (v16 & 0x2AA0) != 0 && (v16 & 0xA0000) != 0 )
  {
    if ( (a5 & 0x400) != 0 )
      v16 &= 0xF0000u;
    else
      v16 &= 0xFFF0FFFF;
  }
  if ( v12 && (*((_DWORD *)v11 + 42) & 0x2000) == 0 )
    v16 &= 0xFFFFCFFF;
  if ( (v16 & 0x2000) != 0 )
  {
    v31 = (unsigned __int8 *)SPExternalAlloc(v17 != 0 ? 1936 : 1952);
    v32 = (CTls13ClientContext *)v31;
    if ( v31 )
    {
      Record = CTlsRecord::MakeRecord(a5, v31 + 1856, (struct CSsl3TlsContext *)v31);
      if ( Record )
      {
        v22 = CTls13ClientContext::CTls13ClientContext(v32, Record, v11, v16, v8);
        goto LABEL_20;
      }
      if ( v8 )
        SPExternalFree(v8);
      v34 = v32;
      goto LABEL_40;
    }
LABEL_43:
    if ( !v8 )
      return 14i64;
    v34 = v8;
LABEL_40:
    SPExternalFree(v34);
    return 14i64;
  }
  v21 = (CSsl3TlsClientContext *)SPExternalAlloc(0x558u);
  if ( !v21 )
    goto LABEL_43;
  v22 = CSsl3TlsClientContext::CSsl3TlsClientContext(v21, v11, v16, v8);
LABEL_20:
  v23 = v22;
  v24 = (*(__int64 (__fastcall **)(CTls13ClientContext *))(*(_QWORD *)v22 + 184i64))(v22);
  if ( !v24 )
  {
    v25 = SPExternalAlloc(0x28u);
    if ( v25 )
    {
      v25[1] = v23;
      *((_QWORD *)v23 + 16) = v25;
      v26 = (unsigned __int16)ConvertSchannelProtocolToSsl(v16);
      v27 = v36;
      *((_DWORD *)v23 + 9) = v26;
      *v27 = v28;
      return 0i64;
    }
    (**(void (__fastcall ***)(void *, _QWORD))v23)(v23, 0i64);
    v24 = 14;
  }
  SPExternalFree(v23);
  return v24;
}
// 18000A02C: variable 'v13' is possibly undefined
// 18000A04D: variable 'v15' is possibly undefined
// 18000A17D: variable 'v28' is possibly undefined
// 180034E7F: variable 'v10' is possibly undefined

