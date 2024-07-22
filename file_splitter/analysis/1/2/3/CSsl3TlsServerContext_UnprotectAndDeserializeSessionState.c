bool __fastcall CSsl3TlsServerContext::UnprotectAndDeserializeSessionState(
    CSsl3TlsServerContext *this, unsigned __int8 *const a2, unsigned int a3,
    unsigned __int8 *const a4, size_t Size) {
  CCredentialGroup *v9;      // rcx
  unsigned int KeyFilePath;  // ebx
  CCipherMill *v11;          // rcx
  CSessionCacheManager *v12; // rbx
  _QWORD *v13;               // r14
  __int64 v14;               // rcx
  unsigned int v15;          // eax
  __int64 v16;               // rcx
  unsigned int v17;          // eax
  bool v18;                  // zf
  unsigned int v20;          // [rsp+30h] [rbp-20h] BYREF
  HLOCAL hMem;               // [rsp+38h] [rbp-18h] BYREF
  unsigned __int16 *v22;     // [rsp+40h] [rbp-10h] BYREF
  int v23;                   // [rsp+88h] [rbp+38h] BYREF

  if (!a2 || !a3 || !a4 || (*((_DWORD *)this + 34) & 0x800i64) == 0)
    return 0;
  v9 = (CCredentialGroup *)*((_QWORD *)this + 10);
  hMem = 0i64;
  v20 = 0;
  v22 = 0i64;
  KeyFilePath = CCredentialGroup::GetKeyFilePath(v9, &v22);
  if (!KeyFilePath) {
    v23 = 0;
    KeyFilePath = SslImpersonateClient(
        *(_QWORD *)(*((_QWORD *)this + 10) + 752i64), &v23);
    if (!KeyFilePath) {
      if (!g_pKeyFileUnprotectSessionTicket) {
        KeyFilePath = 1157;
      LABEL_11:
        v11 = WPP_GLOBAL_Control;
        if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
            (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0)
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 46i64,
                   &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids,
                   KeyFilePath);
        goto LABEL_14;
      }
      KeyFilePath = g_pKeyFileUnprotectSessionTicket(
          a2, a3, v22, (unsigned __int8 **)&hMem, &v20);
      if (KeyFilePath)
        goto LABEL_11;
    }
  LABEL_14:
    if (v23)
      RevertToSelf();
    if (!KeyFilePath) {
      v12 = CSessionCacheManager::m_pSessionCacheManager;
      CSessionCacheManager::AcquireCacheTableLock((__int64)v11, 0i64, a4);
      v13 = (_QWORD *)((char *)this + 992);
      KeyFilePath = CSessionCacheManager::CacheRetrieveNewServerItem(
          v12, *((_DWORD *)this + 16), a4,
          (struct CSessionCacheServerItem **)this + 124);
      CSessionCacheManager::ReleaseCacheTableLock(v14, 0i64, a4);
      if (!KeyFilePath) {
        v15 = (*(__int64(__fastcall **)(_QWORD, CSsl3TlsServerContext *, HLOCAL,
                                        _QWORD))(*(_QWORD *)*v13 + 56i64))(
            *v13, this, hMem, v20);
        v16 = *v13;
        KeyFilePath = v15;
        if (v15) {
          *(_BYTE *)(v16 + 236) = 0;
          (*(void(__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this +
                                                           240i64))(this);
        } else {
          v17 = Size;
          *(_WORD *)(v16 + 238) = Size;
          memcpy_0((void *)(v16 + 240), a4, v17);
        }
      }
    }
  }
  if (hMem)
    LocalFree(hMem);
  v18 = KeyFilePath == 0;
  if (KeyFilePath) {
    if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
        (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0)
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 47i64,
               &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids, KeyFilePath);
    return KeyFilePath == 0;
  }
  return v18;
}