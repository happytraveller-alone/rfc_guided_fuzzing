//----- (0000000180062DB4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::SerializeAndProtectSessionState(
        CSsl3TlsServerContext *this,
        HLOCAL *a2,
        unsigned __int16 *a3)
{
  __int64 v6; // rcx
  __int64 result; // rax
  unsigned __int8 *v8; // r13
  __int64 v9; // rcx
  unsigned int KeyFilePath; // esi
  CCredentialGroup *v11; // rcx
  __int64 v12; // rax
  CCipherMill *v13; // rcx
  __int64 v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rdi
  int v17; // [rsp+30h] [rbp-20h] BYREF
  HLOCAL hMem; // [rsp+38h] [rbp-18h] BYREF
  unsigned __int16 *v19; // [rsp+40h] [rbp-10h] BYREF
  unsigned int v20; // [rsp+98h] [rbp+48h] BYREF
  unsigned int v21; // [rsp+A8h] [rbp+58h] BYREF

  if ( !a2 || *a2 || !a3 || *a3 )
    return 87i64;
  v6 = *((_QWORD *)this + 124);
  v20 = 0;
  result = (*(__int64 (__fastcall **)(__int64, CSsl3TlsServerContext *, unsigned int *))(*(_QWORD *)v6 + 40i64))(
             v6,
             this,
             &v20);
  if ( (_DWORD)result )
    return result;
  v8 = (unsigned __int8 *)(*(__int64 (__fastcall **)(CSsl3TlsServerContext *, _QWORD))(*(_QWORD *)this + 8i64))(
                            this,
                            v20);
  if ( !v8 )
    return 14i64;
  v9 = *((_QWORD *)this + 124);
  hMem = 0i64;
  KeyFilePath = (*(__int64 (__fastcall **)(__int64, CSsl3TlsServerContext *, unsigned __int8 *, _QWORD, unsigned int *))(*(_QWORD *)v9 + 48i64))(
                  v9,
                  this,
                  v8,
                  v20,
                  &v20);
  if ( !KeyFilePath )
  {
    v11 = (CCredentialGroup *)*((_QWORD *)this + 10);
    v21 = 0;
    v19 = 0i64;
    KeyFilePath = CCredentialGroup::GetKeyFilePath(v11, &v19);
    if ( KeyFilePath )
    {
LABEL_25:
      if ( KeyFilePath - 2 <= 1 )
      {
        v14 = *((_QWORD *)this + 10);
        if ( !*(_DWORD *)(v14 + 896) )
        {
          LogSessionTicketMisconfiguration(*(_DWORD *)(v14 + 212), (const unsigned __int16 *)(v14 + 216), v19);
          v15 = *((_QWORD *)this + 10);
          RtlAcquireResourceExclusive((PRTL_RESOURCE)(v15 + 48), 1u);
          *(_DWORD *)(v15 + 896) = 1;
          RtlReleaseResource((PRTL_RESOURCE)(v15 + 48));
        }
      }
      if ( !KeyFilePath )
      {
        v16 = *((_QWORD *)this + 10);
        if ( *(_DWORD *)(v16 + 896) )
        {
          RtlAcquireResourceExclusive((PRTL_RESOURCE)(v16 + 48), 1u);
          *(_DWORD *)(v16 + 896) = 0;
          RtlReleaseResource((PRTL_RESOURCE)(v16 + 48));
        }
        *a2 = hMem;
        *a3 = v21;
        hMem = 0i64;
      }
      goto LABEL_32;
    }
    v12 = *((_QWORD *)this + 10);
    v17 = 0;
    KeyFilePath = SslImpersonateClient(*(_QWORD *)(v12 + 752), &v17);
    if ( KeyFilePath )
    {
LABEL_23:
      if ( v17 )
        RevertToSelf();
      goto LABEL_25;
    }
    if ( g_pKeyFileProtectSessionTicket )
    {
      KeyFilePath = g_pKeyFileProtectSessionTicket(v8, v20, v19, (unsigned __int8 **)&hMem, &v21);
      if ( !KeyFilePath )
        goto LABEL_18;
    }
    else
    {
      KeyFilePath = 1157;
    }
    v13 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
    {
LABEL_19:
      if ( v21 > 0xFFFF )
      {
        KeyFilePath = 1359;
        if ( v13 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v13 + 28) & 1) != 0 )
          WPP_SF_D(*((_QWORD *)v13 + 2), 52i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids, v21);
      }
      goto LABEL_23;
    }
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 51i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids, KeyFilePath);
LABEL_18:
    v13 = WPP_GLOBAL_Control;
    goto LABEL_19;
  }
LABEL_32:
  (*(void (__fastcall **)(CSsl3TlsServerContext *, unsigned __int8 *))(*(_QWORD *)this + 16i64))(this, v8);
  if ( hMem )
    LocalFree(hMem);
  return KeyFilePath;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092188: using guessed type unsigned int (__stdcall *g_pKeyFileProtectSessionTicket)(unsigned __int8 *, unsigned int, const unsigned __int16 *, unsigned __int8 **, unsigned int *);
