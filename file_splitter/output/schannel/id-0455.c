// File count: 455
// Total lines: 112
----------------------------------------
void __fastcall CTls13ServerContext::CleanupConnectedState(CTls13ServerContext *this)
{
  const CERT_SERVER_OCSP_RESPONSE_CONTEXT *v2; // rcx
  __int64 v3; // rcx
  void *v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // rcx
  void *v10; // rcx
  __int64 v11; // rdx
  _QWORD *v12; // rbx
  CSslCredential *v13; // rcx

  v2 = (const CERT_SERVER_OCSP_RESPONSE_CONTEXT *)*((_QWORD *)this + 189);
  if ( v2 )
  {
    CertFreeServerOcspResponseContext(v2);
    *((_QWORD *)this + 189) = 0i64;
  }
  v3 = *((_QWORD *)this + 138);
  if ( v3 )
  {
    SslFreeObject(v3, 0i64);
    *((_QWORD *)this + 138) = 0i64;
  }
  v4 = (void *)*((_QWORD *)this + 153);
  if ( v4 )
  {
    SPExternalFree(v4);
    *((_QWORD *)this + 153) = 0i64;
  }
  v5 = *((_QWORD *)this + 130);
  *((_BYTE *)this + 1232) = 0;
  if ( v5 )
  {
    SslFreeObject(v5, 0i64);
    *((_QWORD *)this + 130) = 0i64;
  }
  v6 = *((_QWORD *)this + 131);
  if ( v6 )
  {
    SslFreeObject(v6, 0i64);
    *((_QWORD *)this + 131) = 0i64;
  }
  v7 = *((_QWORD *)this + 132);
  if ( v7 )
  {
    SslFreeObject(v7, 0i64);
    *((_QWORD *)this + 132) = 0i64;
  }
  v8 = *((_QWORD *)this + 133);
  if ( v8 )
  {
    SslFreeObject(v8, 0i64);
    *((_QWORD *)this + 133) = 0i64;
  }
  v9 = *((_QWORD *)this + 155);
  if ( v9 )
  {
    SslFreeObject(v9, 0i64);
    *((_QWORD *)this + 155) = 0i64;
  }
  if ( *((_QWORD *)this + 120) )
  {
    (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 248i64))(this);
    CSslCredential::ReleaseEphemeralKeyData(v13, *((struct CEphemKeyData **)this + 120));
    *((_QWORD *)this + 120) = 0i64;
  }
  if ( *((_QWORD *)this + 121) )
  {
    (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 121) = 0i64;
  }
  v10 = (void *)*((_QWORD *)this + 112);
  if ( v10 )
  {
    SPExternalFree(v10);
    *((_QWORD *)this + 112) = 0i64;
    *((_DWORD *)this + 222) = 0;
  }
  if ( *((_QWORD *)this + 110) )
  {
    (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 110) = 0i64;
  }
  v11 = *((_QWORD *)this + 114);
  *((_DWORD *)this + 218) = 0;
  if ( v11 )
  {
    (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 114) = 0i64;
    *((_WORD *)this + 460) = 0;
  }
  *(_WORD *)((char *)this + 923) = 0;
  *((_BYTE *)this + 472) = 0;
  v12 = (_QWORD *)*((_QWORD *)this + 58);
  if ( v12 && *v12 )
  {
    if ( v12[3] )
    {
      (*(void (__fastcall **)(_QWORD))(*(_QWORD *)*v12 + 16i64))(*v12);
      v12[3] = 0i64;
      *((_DWORD *)v12 + 4) = 0;
    }
  }
}
// 180033533: variable 'v13' is possibly undefined
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
