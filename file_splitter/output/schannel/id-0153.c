//----- (000000018000D37C) ----------------------------------------------------
void __fastcall CSslContext::SetCredentialGroup(CSslContext *this, struct CCredentialGroup *a2)
{
  struct CCredentialGroup *v4; // rdx
  int v5; // eax
  __int64 v6; // rcx

  v4 = (struct CCredentialGroup *)*((_QWORD *)this + 10);
  if ( v4 != a2 )
  {
    if ( v4 )
    {
      CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, v4);
      (*(void (__fastcall **)(CSslContext *, _QWORD))(*(_QWORD *)this + 256i64))(this, 0i64);
    }
    _InterlockedIncrement((volatile signed __int32 *)a2 + 6);
    *((_QWORD *)this + 10) = a2;
    v5 = *((_DWORD *)a2 + 39);
    if ( (v5 & 4) != 0 )
    {
      v6 = *((_QWORD *)this + 17);
      if ( (v6 & 0x100) == 0 )
      {
        *((_QWORD *)this + 17) = v6 | 0x4000;
        v5 = *((_DWORD *)a2 + 39);
      }
    }
    if ( (v5 & 0x4000) != 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_c955f13c15ab3d9e41a0e2d56db0bfe4_Traceguids);
      *((_QWORD *)this + 17) |= 0x200000000ui64;
    }
    if ( *((_DWORD *)this + 17) == 91 || *((_DWORD *)this + 17) == 101 )
    {
      if ( *((_BYTE *)this + 266) )
      {
        *((_BYTE *)this + 923) = 1;
        CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 0);
      }
      else
      {
        CSsl3TlsClientContext::CheckForClientCred(this);
      }
    }
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

