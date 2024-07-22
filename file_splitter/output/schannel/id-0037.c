//----- (0000000180003400) ----------------------------------------------------
void __fastcall CSsl3TlsClientContext::~CSsl3TlsClientContext(struct CSessionCacheItem **this)
{
  struct CSessionCacheItem *v2; // rcx
  struct CSessionCacheItem *v3; // rdx
  bool v4; // zf
  struct CSessionCacheItem *v5; // rdi
  struct CSessionCacheItem *v6; // rdx
  struct CSessionCacheItem *v7; // rdx
  struct CSessionCacheItem *v8; // rdx
  struct CSessionCacheItem *v9; // rdx
  struct CSessionCacheItem *v10; // rdx
  void **v11; // rcx
  struct CSessionCacheItem *v12; // rdx
  struct CSessionCacheItem *v13; // rdx
  struct CSessionCacheItem *v14; // rdx
  struct CSessionCacheItem *v15; // rcx
  struct CSessionCacheItem *v16; // rcx
  struct CSessionCacheItem *v17; // rcx
  struct CSessionCacheItem *v18; // rcx
  struct CSessionCacheItem *v19; // rcx
  struct CSessionCacheItem *v20; // rdi
  __int64 v21; // rcx
  CSslServerKey *v22; // rcx
  int v23; // ecx
  struct CCredentialGroup *v24; // rdx
  struct CSessionCacheItem *v25; // rcx
  volatile signed __int32 *v26; // rcx
  struct CSessionCacheItem *v27; // rax
  struct CSessionCacheItem *v28; // rcx
  struct CSessionCacheItem *v29; // rdx
  struct CSessionCacheItem *v30; // rdi
  DTlsMsgMgr *v31; // rcx
  struct CSessionCacheItem *v32; // rdx

  *this = (struct CSessionCacheItem *)&CSsl3TlsClientContext::`vftable';
  CSsl3TlsClientContext::CleanupConnectedState((CSsl3TlsClientContext *)this);
  v2 = this[166];
  if ( v2 )
    SPExternalFree(v2);
  if ( ((_DWORD)this[17] & 0x80000) != 0 )
  {
    v28 = this[116];
    if ( v28 )
      (*(void (__fastcall **)(struct CSessionCacheItem *, __int64))(*(_QWORD *)v28 + 8i64))(v28, 1i64);
  }
  v3 = this[167];
  if ( v3 )
    CSslContext::FreeMemory((CSslContext *)this, v3);
  v4 = *((_BYTE *)this + 233) == 0;
  *this = (struct CSessionCacheItem *)&CSsl3TlsContext::`vftable';
  if ( v4 )
  {
    v5 = this[58];
    if ( v5 )
    {
      v32 = this[58];
      if ( *(_QWORD *)v5 && *((_QWORD *)v5 + 3) )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)v5 + 16i64))(*(_QWORD *)v5, *((_QWORD *)v5 + 3));
        *((_QWORD *)v5 + 3) = 0i64;
        *((_DWORD *)v5 + 4) = 0;
        v32 = this[58];
      }
      CSslContext::FreeMemory((CSslContext *)this, v32);
    }
  }
  else
  {
    v29 = this[71];
    if ( v29 )
      CSslContext::FreeMemory((CSslContext *)this, v29);
    v30 = this[73];
    if ( v30 )
    {
      DTlsHandshakeQueue::~DTlsHandshakeQueue(this[73]);
      operator delete(v30);
      this[73] = 0i64;
    }
    v31 = this[72];
    if ( v31 )
    {
      DTlsMsgMgr::`scalar deleting destructor'(v31);
      this[72] = 0i64;
    }
    CSsl3TlsContext::FreeSavedWriteCipherState((CSsl3TlsContext *)this);
  }
  v6 = this[98];
  if ( v6 )
    CSslContext::FreeMemory((CSslContext *)this, v6);
  v7 = this[99];
  if ( v7 )
    CSslContext::FreeMemory((CSslContext *)this, v7);
  v8 = this[100];
  if ( v8 )
    CSslContext::FreeMemory((CSslContext *)this, v8);
  CSsl3TlsContext::FreeSelectedSrtpParameters((CSsl3TlsContext *)this);
  v9 = this[102];
  if ( v9 )
    CSslContext::FreeMemory((CSslContext *)this, v9);
  CSsl3TlsContext::FreeSelectedTBParameters((CSsl3TlsContext *)this);
  v10 = this[104];
  if ( v10 )
  {
    if ( *((_QWORD *)v10 + 1) )
    {
      (*((void (__fastcall **)(struct CSessionCacheItem **, _QWORD))*this + 2))(this, *((_QWORD *)v10 + 1));
      v10 = this[104];
    }
    (*((void (__fastcall **)(struct CSessionCacheItem **, struct CSessionCacheItem *))*this + 2))(this, v10);
    this[104] = 0i64;
  }
  v11 = (void **)this[105];
  if ( v11 )
  {
    if ( v11[1] )
    {
      SPExternalFree(v11[1]);
      v11 = (void **)this[105];
    }
    if ( v11[3] )
    {
      SPExternalFree(v11[3]);
      v11 = (void **)this[105];
    }
    SPExternalFree(v11);
    this[105] = 0i64;
  }
  v12 = this[106];
  if ( v12 )
    CSslContext::FreeMemory((CSslContext *)this, v12);
  v13 = this[107];
  if ( v13 )
    CSslContext::FreeMemory((CSslContext *)this, v13);
  v14 = this[108];
  if ( v14 )
    CSslContext::FreeMemory((CSslContext *)this, v14);
  CSsl3TlsContext::FreeHandshakeHash((CSsl3TlsContext *)this);
  v15 = this[18];
  *this = (struct CSessionCacheItem *)&CSslContext::`vftable';
  if ( v15 )
    SslFreeObject(v15, 0i64);
  v16 = this[19];
  if ( v16 )
    SslFreeObject(v16, 0i64);
  v17 = this[20];
  if ( v17 )
    SslFreeObject(v17, 0i64);
  v18 = this[21];
  if ( v18 )
    SslFreeObject(v18, 0i64);
  v19 = this[14];
  if ( v19 )
    SslFreeObject(v19, 0i64);
  v20 = this[1];
  if ( v20 )
  {
    v21 = *((_QWORD *)v20 + 106);
    if ( v21 )
      CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v21 + 16));
    CMasterCipherInfo::Dereference(*((CMasterCipherInfo **)v20 + 107));
  }
  v22 = this[3];
  if ( v22 )
    CSslServerKey::Dereference(v22);
  v23 = *((_DWORD *)this + 17);
  if ( (unsigned int)(v23 - 3) > 1 && v23 != 79 && ((_DWORD)this[17] & 0x40000) == 0 )
  {
    v27 = this[11];
    if ( v27 )
      *((_BYTE *)v27 + 236) = 0;
  }
  v24 = this[10];
  if ( v24 )
    CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, v24);
  v25 = this[11];
  if ( v25 )
    CSessionCacheTable::DereferenceCacheItemInternal(*((CSessionCacheTable **)v25 + 28), this[11], 1, 0);
  v26 = (volatile signed __int32 *)this[15];
  if ( v26 && _InterlockedExchangeAdd(v26 + 5, 0xFFFFFFFF) == 1 )
    (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v26 + 8i64))(v26, 1i64);
  *this = (struct CSessionCacheItem *)&ISslSerialize::`vftable';
}
// 18007C000: using guessed type void *CSsl3TlsClientContext::`vftable';
// 18007CBA8: using guessed type void *CSsl3TlsContext::`vftable';
// 18007CDB8: using guessed type void *CSslContext::`vftable';
// 18007CFB8: using guessed type void *ISslSerialize::`vftable';
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

