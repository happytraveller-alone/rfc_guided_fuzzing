//----- (0000000180055B18) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::CreateRenewedCredential(CCredentialGroup *this, struct LSA_SCHANNEL_SUB_CRED *a2)
{
  CSslCredential *v4; // rax
  CSslCredential *v5; // rdi
  _QWORD *v6; // rax
  _QWORD *v7; // rdi
  __int64 v8; // rcx

  v4 = (CSslCredential *)SPExternalAlloc(0x498u);
  if ( !v4 )
    return 14i64;
  v5 = CSslCredential::CSslCredential(v4);
  if ( !v5 )
    return 14i64;
  if ( (unsigned int)CSslCredential::CreateCredential(
                       v5,
                       *((_DWORD *)this + 53),
                       (char *)this + 216,
                       *((_QWORD *)this + 94),
                       a2,
                       0,
                       0,
                       *((_QWORD *)this + 100) != 0i64,
                       *((struct _TLS_PARAMETERS **)this + 25),
                       *((_DWORD *)this + 49)) )
  {
    (*(void (__fastcall **)(CSslCredential *, __int64))(*(_QWORD *)v5 + 8i64))(v5, 1i64);
  }
  else
  {
    if ( *((_DWORD *)v5 + 35) )
      *((_BYTE *)this + 900) = 1;
    v6 = (_QWORD *)((char *)this + 32);
    v7 = (_QWORD *)((char *)v5 + 8);
    v8 = *((_QWORD *)this + 4);
    if ( *(CCredentialGroup **)(v8 + 8) != (CCredentialGroup *)((char *)this + 32) )
      __fastfail(3u);
    *v7 = v8;
    v7[1] = v6;
    *(_QWORD *)(v8 + 8) = v7;
    *v6 = v7;
    ++*((_DWORD *)this + 7);
  }
  return 0i64;
}
