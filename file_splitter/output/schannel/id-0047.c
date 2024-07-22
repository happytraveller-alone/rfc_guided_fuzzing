//----- (0000000180003ED0) ----------------------------------------------------
void __fastcall CSsl3TlsClientContext::CleanupConnectedState(CSsl3TlsClientContext *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  __int64 v7; // rax
  CSslCredential *v8; // rax
  __int64 v9; // rdx
  int v10; // r8d

  v2 = *((_QWORD *)this + 128);
  if ( v2 )
    SslFreeObject(v2, 0i64);
  v3 = *((_QWORD *)this + 127);
  if ( v3 )
    SslFreeObject(v3, 0i64);
  v4 = (void *)*((_QWORD *)this + 119);
  if ( v4 )
  {
    SPExternalFree(v4);
    *((_QWORD *)this + 119) = 0i64;
  }
  v5 = (void *)*((_QWORD *)this + 121);
  if ( v5 )
  {
    SPExternalFree(v5);
    *((_QWORD *)this + 121) = 0i64;
  }
  v6 = (void *)*((_QWORD *)this + 117);
  if ( v6 )
  {
    SPExternalFree(v6);
    *((_QWORD *)this + 117) = 0i64;
  }
  *((_DWORD *)this + 236) = 0;
  CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 0);
  v7 = *(_QWORD *)this;
  *((_BYTE *)this + 1032) = 0;
  if ( (*(__int64 (__fastcall **)(CSsl3TlsClientContext *))(v7 + 248))(this) && (*((_DWORD *)this + 34) & 0x80000) != 0 )
  {
    v8 = (CSslCredential *)(*(__int64 (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)this + 248i64))(this);
    CSslCredential::RemoteCloseKeyHandle(v8, v9, v10);
  }
  *((_WORD *)this + 255) = 0;
  *((_WORD *)this + 272) = 0;
  *((_BYTE *)this + 1313) = 0;
  CSsl3TlsContext::CleanupConnectedState(this);
}
// 18002CD3F: variable 'v9' is possibly undefined
// 18002CD3F: variable 'v10' is possibly undefined
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

