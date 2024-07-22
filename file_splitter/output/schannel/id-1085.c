//----- (000000018005A570) ----------------------------------------------------
CSsl3TlsContext *__fastcall CSsl3TlsContext::`scalar deleting destructor'(CSsl3TlsContext *this)
{
  bool v1; // zf
  void *v3; // rdx
  void *v4; // rdi
  DTlsMsgMgr *v5; // rcx
  _QWORD *v6; // rdi
  void *v7; // rdx
  void *v8; // rdx
  void *v9; // rdx
  void *v10; // rdx
  void *v11; // rdx
  __int64 v12; // rdx
  void **v13; // rcx
  void *v14; // rdx
  void *v15; // rdx
  void *v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rcx
  __int64 v21; // rcx
  __int64 v22; // rdi
  __int64 v23; // rcx
  CSslServerKey *v24; // rcx
  int v25; // ecx
  __int64 v26; // rax
  struct CCredentialGroup *v27; // rdx
  __int64 v28; // rcx
  volatile signed __int32 *v29; // rcx

  v1 = *((_BYTE *)this + 233) == 0;
  *(_QWORD *)this = &CSsl3TlsContext::`vftable';
  if ( v1 )
  {
    v6 = (_QWORD *)*((_QWORD *)this + 58);
    if ( v6 )
    {
      v7 = (void *)*((_QWORD *)this + 58);
      if ( *v6 && v6[3] )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)*v6 + 16i64))(*v6, v6[3]);
        v6[3] = 0i64;
        *((_DWORD *)v6 + 4) = 0;
        v7 = (void *)*((_QWORD *)this + 58);
      }
      CSslContext::FreeMemory(this, v7);
    }
  }
  else
  {
    v3 = (void *)*((_QWORD *)this + 71);
    if ( v3 )
      CSslContext::FreeMemory(this, v3);
    v4 = (void *)*((_QWORD *)this + 73);
    if ( v4 )
    {
      DTlsHandshakeQueue::~DTlsHandshakeQueue(*((DTlsHandshakeQueue **)this + 73));
      operator delete(v4);
      *((_QWORD *)this + 73) = 0i64;
    }
    v5 = (DTlsMsgMgr *)*((_QWORD *)this + 72);
    if ( v5 )
    {
      DTlsMsgMgr::`scalar deleting destructor'(v5);
      *((_QWORD *)this + 72) = 0i64;
    }
    CSsl3TlsContext::FreeSavedWriteCipherState(this);
  }
  v8 = (void *)*((_QWORD *)this + 98);
  if ( v8 )
    CSslContext::FreeMemory(this, v8);
  v9 = (void *)*((_QWORD *)this + 99);
  if ( v9 )
    CSslContext::FreeMemory(this, v9);
  v10 = (void *)*((_QWORD *)this + 100);
  if ( v10 )
    CSslContext::FreeMemory(this, v10);
  CSsl3TlsContext::FreeSelectedSrtpParameters(this);
  v11 = (void *)*((_QWORD *)this + 102);
  if ( v11 )
    CSslContext::FreeMemory(this, v11);
  CSsl3TlsContext::FreeSelectedTBParameters(this);
  v12 = *((_QWORD *)this + 104);
  if ( v12 )
  {
    if ( *(_QWORD *)(v12 + 8) )
    {
      (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(this, *(_QWORD *)(v12 + 8));
      v12 = *((_QWORD *)this + 104);
    }
    (*(void (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 16i64))(this, v12);
    *((_QWORD *)this + 104) = 0i64;
  }
  v13 = (void **)*((_QWORD *)this + 105);
  if ( v13 )
  {
    if ( v13[1] )
    {
      SPExternalFree(v13[1]);
      v13 = (void **)*((_QWORD *)this + 105);
    }
    if ( v13[3] )
    {
      SPExternalFree(v13[3]);
      v13 = (void **)*((_QWORD *)this + 105);
    }
    SPExternalFree(v13);
    *((_QWORD *)this + 105) = 0i64;
  }
  v14 = (void *)*((_QWORD *)this + 106);
  if ( v14 )
    CSslContext::FreeMemory(this, v14);
  v15 = (void *)*((_QWORD *)this + 107);
  if ( v15 )
    CSslContext::FreeMemory(this, v15);
  v16 = (void *)*((_QWORD *)this + 108);
  if ( v16 )
    CSslContext::FreeMemory(this, v16);
  CSsl3TlsContext::FreeHandshakeHash(this);
  v17 = *((_QWORD *)this + 18);
  *(_QWORD *)this = &CSslContext::`vftable';
  if ( v17 )
    SslFreeObject(v17, 0i64);
  v18 = *((_QWORD *)this + 19);
  if ( v18 )
    SslFreeObject(v18, 0i64);
  v19 = *((_QWORD *)this + 20);
  if ( v19 )
    SslFreeObject(v19, 0i64);
  v20 = *((_QWORD *)this + 21);
  if ( v20 )
    SslFreeObject(v20, 0i64);
  v21 = *((_QWORD *)this + 14);
  if ( v21 )
    SslFreeObject(v21, 0i64);
  v22 = *((_QWORD *)this + 1);
  if ( v22 )
  {
    v23 = *(_QWORD *)(v22 + 848);
    if ( v23 )
      CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v23 + 16));
    CMasterCipherInfo::Dereference(*(CMasterCipherInfo **)(v22 + 856));
  }
  v24 = (CSslServerKey *)*((_QWORD *)this + 3);
  if ( v24 )
    CSslServerKey::Dereference(v24);
  v25 = *((_DWORD *)this + 17);
  if ( (unsigned int)(v25 - 3) > 1 && v25 != 79 && (*((_DWORD *)this + 34) & 0x40000) == 0 )
  {
    v26 = *((_QWORD *)this + 11);
    if ( v26 )
      *(_BYTE *)(v26 + 236) = 0;
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
// 18007CBA8: using guessed type void *CSsl3TlsContext::`vftable';
// 18007CDB8: using guessed type void *CSslContext::`vftable';
// 18007CFB8: using guessed type void *ISslSerialize::`vftable';
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

