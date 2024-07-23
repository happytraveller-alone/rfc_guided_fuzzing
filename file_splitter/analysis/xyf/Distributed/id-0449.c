//----- (0000000180020110) ----------------------------------------------------
CTls13ServerContext *__fastcall CTls13ServerContext::`scalar deleting destructor'(CTls13ServerContext *this)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rdx
  void *v6; // rdx
  void *v7; // rdi
  void *v8; // rdi
  void *v9; // rdx
  void *v10; // rdx
  void *v11; // rdx
  void *v12; // rdx
  __int64 v13; // rdx
  void **v14; // rcx
  void *v15; // rdx
  void *v16; // rdx
  void *v17; // rdx
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rcx
  __int64 v21; // rcx
  __int64 v22; // rcx
  __int64 v23; // rdi
  __int64 v24; // rcx
  CSslServerKey *v25; // rcx
  int v26; // ecx
  struct CCredentialGroup *v27; // rdx
  __int64 v28; // rcx
  volatile signed __int32 *v29; // rcx
  _QWORD *v31; // rdi
  void *v32; // rdx
  __int64 v33; // rax

  *(_QWORD *)this = &CTls13ServerContext::`vftable'{for `CSsl3TlsServerContext'};
  *((_QWORD *)this + 125) = &CTls13ServerContext::`vftable'{for `CTls13Context'};
  v2 = (void *)*((_QWORD *)this + 187);
  if ( v2 )
    SPExternalFree(v2);
  CTls13ServerContext::CleanupConnectedState(this);
  CTls13ServerHandshake::~CTls13ServerHandshake((CTls13ServerContext *)((char *)this + 1288));
  CTls13Context::~CTls13Context((CTls13ServerContext *)((char *)this + 1000));
  *(_QWORD *)this = &CSsl3TlsServerContext::`vftable';
  CSsl3TlsServerContext::CleanupConnectedState(this);
  v3 = (void *)*((_QWORD *)this + 116);
  if ( v3 )
    SPExternalFree(v3);
  v4 = (void *)*((_QWORD *)this + 117);
  if ( v4 )
    SPExternalFree(v4);
  v5 = (void *)*((_QWORD *)this + 118);
  if ( v5 )
    CSslContext::FreeMemory(this, v5);
  *(_QWORD *)this = &CSsl3TlsContext::`vftable';
  if ( *((_BYTE *)this + 233) )
  {
    v6 = (void *)*((_QWORD *)this + 71);
    if ( v6 )
      CSslContext::FreeMemory(this, v6);
    v7 = (void *)*((_QWORD *)this + 73);
    if ( v7 )
    {
      DTlsHandshakeQueue::~DTlsHandshakeQueue(*((DTlsHandshakeQueue **)this + 73));
      operator delete(v7);
      *((_QWORD *)this + 73) = 0i64;
    }
    v8 = (void *)*((_QWORD *)this + 72);
    if ( v8 )
    {
      DTlsMsgMgr::~DTlsMsgMgr(*((DTlsMsgMgr **)this + 72));
      operator delete(v8);
      *((_QWORD *)this + 72) = 0i64;
    }
    CSsl3TlsContext::FreeSavedWriteCipherState(this);
  }
  else
  {
    v31 = (_QWORD *)*((_QWORD *)this + 58);
    if ( v31 )
    {
      v32 = (void *)*((_QWORD *)this + 58);
      if ( *v31 && v31[3] )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)*v31 + 16i64))(*v31, v31[3]);
        v31[3] = 0i64;
        *((_DWORD *)v31 + 4) = 0;
        v32 = (void *)*((_QWORD *)this + 58);
      }
      CSslContext::FreeMemory(this, v32);
    }
  }
  v9 = (void *)*((_QWORD *)this + 98);
  if ( v9 )
    CSslContext::FreeMemory(this, v9);
  v10 = (void *)*((_QWORD *)this + 99);
  if ( v10 )
    CSslContext::FreeMemory(this, v10);
  v11 = (void *)*((_QWORD *)this + 100);
  if ( v11 )
    CSslContext::FreeMemory(this, v11);
  CSsl3TlsContext::FreeSelectedSrtpParameters(this);
  v12 = (void *)*((_QWORD *)this + 102);
  if ( v12 )
    CSslContext::FreeMemory(this, v12);
  CSsl3TlsContext::FreeSelectedTBParameters(this);
  v13 = *((_QWORD *)this + 104);
  if ( v13 )
  {
    if ( *(_QWORD *)(v13 + 8) )
      (*(void (__fastcall **)(CTls13ServerContext *, _QWORD))(*(_QWORD *)this + 16i64))(this, *(_QWORD *)(v13 + 8));
    (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 104) = 0i64;
  }
  v14 = (void **)*((_QWORD *)this + 105);
  if ( v14 )
  {
    if ( v14[1] )
    {
      SPExternalFree(v14[1]);
      v14 = (void **)*((_QWORD *)this + 105);
    }
    if ( v14[3] )
    {
      SPExternalFree(v14[3]);
      v14 = (void **)*((_QWORD *)this + 105);
    }
    SPExternalFree(v14);
    *((_QWORD *)this + 105) = 0i64;
  }
  v15 = (void *)*((_QWORD *)this + 106);
  if ( v15 )
    CSslContext::FreeMemory(this, v15);
  v16 = (void *)*((_QWORD *)this + 107);
  if ( v16 )
    CSslContext::FreeMemory(this, v16);
  v17 = (void *)*((_QWORD *)this + 108);
  if ( v17 )
    CSslContext::FreeMemory(this, v17);
  CSsl3TlsContext::FreeHandshakeHash(this);
  v18 = *((_QWORD *)this + 18);
  *(_QWORD *)this = &CSslContext::`vftable';
  if ( v18 )
    SslFreeObject(v18, 0i64);
  v19 = *((_QWORD *)this + 19);
  if ( v19 )
    SslFreeObject(v19, 0i64);
  v20 = *((_QWORD *)this + 20);
  if ( v20 )
    SslFreeObject(v20, 0i64);
  v21 = *((_QWORD *)this + 21);
  if ( v21 )
    SslFreeObject(v21, 0i64);
  v22 = *((_QWORD *)this + 14);
  if ( v22 )
    SslFreeObject(v22, 0i64);
  v23 = *((_QWORD *)this + 1);
  if ( v23 )
  {
    v24 = *(_QWORD *)(v23 + 848);
    if ( v24 )
      CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v24 + 16));
    CMasterCipherInfo::Dereference(*(CMasterCipherInfo **)(v23 + 856));
  }
  v25 = (CSslServerKey *)*((_QWORD *)this + 3);
  if ( v25 )
    CSslServerKey::Dereference(v25);
  v26 = *((_DWORD *)this + 17);
  if ( (unsigned int)(v26 - 3) > 1 && v26 != 79 && (*((_DWORD *)this + 34) & 0x40000) == 0 )
  {
    v33 = *((_QWORD *)this + 11);
    if ( v33 )
      *(_BYTE *)(v33 + 236) = 0;
  }
  v27 = (struct CCredentialGroup *)*((_QWORD *)this + 10);
  if ( v27 )
    CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, v27);
  v28 = *((_QWORD *)this + 11);
  if ( v28 )
    CSessionCacheTable::DereferenceCacheItemInternal(
      *(CSessionCacheTable **)(v28 + 224),
      *((struct CSessionCacheItem **)this + 11),
      1,
      0);
  v29 = (volatile signed __int32 *)*((_QWORD *)this + 15);
  if ( v29 && _InterlockedExchangeAdd(v29 + 5, 0xFFFFFFFF) == 1 )
    (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v29 + 8i64))(v29, 1i64);
  *(_QWORD *)this = &ISslSerialize::`vftable';
  return this;
}
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
// 18007C920: using guessed type void *CTls13ServerContext::`vftable'{for `CTls13Context'};
// 18007C928: using guessed type void *CTls13ServerContext::`vftable'{for `CSsl3TlsServerContext'};
// 18007CBA8: using guessed type void *CSsl3TlsContext::`vftable';
// 18007CDB8: using guessed type void *CSslContext::`vftable';
// 18007CFB8: using guessed type void *ISslSerialize::`vftable';
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

