//----- (0000000180020590) ----------------------------------------------------
struct CSessionCacheItem **__fastcall CSsl3TlsServerContext::`vector deleting destructor'(
        struct CSessionCacheItem **this)
{
  struct CSessionCacheItem *v2; // rcx
  struct CSessionCacheItem *v3; // rcx
  struct CSessionCacheItem *v4; // rdx
  struct CSessionCacheItem *v5; // rdx
  struct CSessionCacheItem *v6; // rdi
  struct CSessionCacheItem *v7; // rdi
  struct CSessionCacheItem *v8; // rdx
  struct CSessionCacheItem *v9; // rdx
  struct CSessionCacheItem *v10; // rdx
  struct CSessionCacheItem *v11; // rdx
  struct CSessionCacheItem *v12; // rdx
  void **v13; // rcx
  struct CSessionCacheItem *v14; // rdx
  struct CSessionCacheItem *v15; // rdx
  struct CSessionCacheItem *v16; // rdx
  struct CSessionCacheItem *v17; // rcx
  struct CSessionCacheItem *v18; // rcx
  struct CSessionCacheItem *v19; // rcx
  struct CSessionCacheItem *v20; // rcx
  struct CSessionCacheItem *v21; // rcx
  struct CSessionCacheItem *v22; // rdi
  __int64 v23; // rcx
  CSslServerKey *v24; // rcx
  int v25; // ecx
  struct CCredentialGroup *v26; // rdx
  struct CSessionCacheItem *v27; // rcx
  volatile signed __int32 *v28; // rcx
  struct CSessionCacheItem *v30; // rdi
  struct CSessionCacheItem *v31; // rdx
  struct CSessionCacheItem *v32; // rax

  *this = (struct CSessionCacheItem *)&CSsl3TlsServerContext::`vftable';
  CSsl3TlsServerContext::CleanupConnectedState((CSsl3TlsServerContext *)this);
  v2 = this[116];
  if ( v2 )
    SPExternalFree(v2);
  v3 = this[117];
  if ( v3 )
    SPExternalFree(v3);
  v4 = this[118];
  if ( v4 )
    CSslContext::FreeMemory((CSslContext *)this, v4);
  *this = (struct CSessionCacheItem *)&CSsl3TlsContext::`vftable';
  if ( *((_BYTE *)this + 233) )
  {
    v5 = this[71];
    if ( v5 )
      CSslContext::FreeMemory((CSslContext *)this, v5);
    v6 = this[73];
    if ( v6 )
    {
      DTlsHandshakeQueue::~DTlsHandshakeQueue(this[73]);
      operator delete(v6);
      this[73] = 0i64;
    }
    v7 = this[72];
    if ( v7 )
    {
      DTlsMsgMgr::~DTlsMsgMgr(this[72]);
      operator delete(v7);
      this[72] = 0i64;
    }
    CSsl3TlsContext::FreeSavedWriteCipherState((CSsl3TlsContext *)this);
  }
  else
  {
    v30 = this[58];
    if ( v30 )
    {
      v31 = this[58];
      if ( *(_QWORD *)v30 && *((_QWORD *)v30 + 3) )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)v30 + 16i64))(*(_QWORD *)v30, *((_QWORD *)v30 + 3));
        *((_QWORD *)v30 + 3) = 0i64;
        *((_DWORD *)v30 + 4) = 0;
        v31 = this[58];
      }
      CSslContext::FreeMemory((CSslContext *)this, v31);
    }
  }
  v8 = this[98];
  if ( v8 )
    CSslContext::FreeMemory((CSslContext *)this, v8);
  v9 = this[99];
  if ( v9 )
    CSslContext::FreeMemory((CSslContext *)this, v9);
  v10 = this[100];
  if ( v10 )
    CSslContext::FreeMemory((CSslContext *)this, v10);
  CSsl3TlsContext::FreeSelectedSrtpParameters((CSsl3TlsContext *)this);
  v11 = this[102];
  if ( v11 )
    CSslContext::FreeMemory((CSslContext *)this, v11);
  CSsl3TlsContext::FreeSelectedTBParameters((CSsl3TlsContext *)this);
  v12 = this[104];
  if ( v12 )
  {
    if ( *((_QWORD *)v12 + 1) )
      (*((void (__fastcall **)(struct CSessionCacheItem **, _QWORD))*this + 2))(this, *((_QWORD *)v12 + 1));
    (*((void (__fastcall **)(struct CSessionCacheItem **))*this + 2))(this);
    this[104] = 0i64;
  }
  v13 = (void **)this[105];
  if ( v13 )
  {
    if ( v13[1] )
    {
      SPExternalFree(v13[1]);
      v13 = (void **)this[105];
    }
    if ( v13[3] )
    {
      SPExternalFree(v13[3]);
      v13 = (void **)this[105];
    }
    SPExternalFree(v13);
    this[105] = 0i64;
  }
  v14 = this[106];
  if ( v14 )
    CSslContext::FreeMemory((CSslContext *)this, v14);
  v15 = this[107];
  if ( v15 )
    CSslContext::FreeMemory((CSslContext *)this, v15);
  v16 = this[108];
  if ( v16 )
    CSslContext::FreeMemory((CSslContext *)this, v16);
  CSsl3TlsContext::FreeHandshakeHash((CSsl3TlsContext *)this);
  v17 = this[18];
  *this = (struct CSessionCacheItem *)&CSslContext::`vftable';
  if ( v17 )
    SslFreeObject(v17, 0i64);
  v18 = this[19];
  if ( v18 )
    SslFreeObject(v18, 0i64);
  v19 = this[20];
  if ( v19 )
    SslFreeObject(v19, 0i64);
  v20 = this[21];
  if ( v20 )
    SslFreeObject(v20, 0i64);
  v21 = this[14];
  if ( v21 )
    SslFreeObject(v21, 0i64);
  v22 = this[1];
  if ( v22 )
  {
    v23 = *((_QWORD *)v22 + 106);
    if ( v23 )
      CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v23 + 16));
    CMasterCipherInfo::Dereference(*((CMasterCipherInfo **)v22 + 107));
  }
  v24 = this[3];
  if ( v24 )
    CSslServerKey::Dereference(v24);
  v25 = *((_DWORD *)this + 17);
  if ( (unsigned int)(v25 - 3) > 1 && v25 != 79 && ((_DWORD)this[17] & 0x40000) == 0 )
  {
    v32 = this[11];
    if ( v32 )
      *((_BYTE *)v32 + 236) = 0;
  }
  v26 = this[10];
  if ( v26 )
    CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, v26);
  v27 = this[11];
  if ( v27 )
    CSessionCacheTable::DereferenceCacheItemInternal(*((CSessionCacheTable **)v27 + 28), this[11], 1, 0);
  v28 = (volatile signed __int32 *)this[15];
  if ( v28 && _InterlockedExchangeAdd(v28 + 5, 0xFFFFFFFF) == 1 )
    (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v28 + 8i64))(v28, 1i64);
  *this = (struct CSessionCacheItem *)&ISslSerialize::`vftable';
  return this;
}
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
// 18007CBA8: using guessed type void *CSsl3TlsContext::`vftable';
// 18007CDB8: using guessed type void *CSslContext::`vftable';
// 18007CFB8: using guessed type void *ISslSerialize::`vftable';
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

