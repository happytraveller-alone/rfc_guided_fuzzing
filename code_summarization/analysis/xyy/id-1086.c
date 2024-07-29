//----- (000000018005A900) ----------------------------------------------------
CSslContext *__fastcall CSslContext::`vector deleting destructor'(CSslContext *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx
  __int64 v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // rdi
  __int64 v8; // rcx
  CSslServerKey *v9; // rcx
  int v10; // ecx
  __int64 v11; // rax
  struct CCredentialGroup *v12; // rdx
  __int64 v13; // rcx
  volatile signed __int32 *v14; // rcx

  *(_QWORD *)this = &CSslContext::`vftable';
  v2 = *((_QWORD *)this + 18);
  if ( v2 )
    SslFreeObject(v2, 0i64);
  v3 = *((_QWORD *)this + 19);
  if ( v3 )
    SslFreeObject(v3, 0i64);
  v4 = *((_QWORD *)this + 20);
  if ( v4 )
    SslFreeObject(v4, 0i64);
  v5 = *((_QWORD *)this + 21);
  if ( v5 )
    SslFreeObject(v5, 0i64);
  v6 = *((_QWORD *)this + 14);
  if ( v6 )
    SslFreeObject(v6, 0i64);
  v7 = *((_QWORD *)this + 1);
  if ( v7 )
  {
    v8 = *(_QWORD *)(v7 + 848);
    if ( v8 )
      CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v8 + 16));
    CMasterCipherInfo::Dereference(*(CMasterCipherInfo **)(v7 + 856));
  }
  v9 = (CSslServerKey *)*((_QWORD *)this + 3);
  if ( v9 )
    CSslServerKey::Dereference(v9);
  v10 = *((_DWORD *)this + 17);
  if ( (unsigned int)(v10 - 3) > 1 && v10 != 79 && (*((_DWORD *)this + 34) & 0x40000) == 0 )
  {
    v11 = *((_QWORD *)this + 11);
    if ( v11 )
      *(_BYTE *)(v11 + 236) = 0;
  }
  v12 = (struct CCredentialGroup *)*((_QWORD *)this + 10);
  if ( v12 )
    CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, v12);
  v13 = *((_QWORD *)this + 11);
  if ( v13 )
    CSessionCacheTable::DereferenceCacheItemInternal(
      *(CSessionCacheTable **)(v13 + 224),
      *((struct CSessionCacheItem **)this + 11),
      1,
      0);
  v14 = (volatile signed __int32 *)*((_QWORD *)this + 15);
  if ( v14 && _InterlockedExchangeAdd(v14 + 5, 0xFFFFFFFF) == 1 )
    (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v14 + 8i64))(v14, 1i64);
  *(_QWORD *)this = &ISslSerialize::`vftable';
  return this;
}
// 18007CDB8: using guessed type void *CSslContext::`vftable';
// 18007CFB8: using guessed type void *ISslSerialize::`vftable';
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

