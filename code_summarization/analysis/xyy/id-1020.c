//----- (0000000180055318) ----------------------------------------------------
void __fastcall CCredentialGroup::CheckForCertificateStoreChange(CCredentialGroup *this)
{
  void *v2; // rdx
  void *v3; // r8
  DWORD v4; // eax
  void *v5; // rdx
  void *v6; // r8
  DWORD v7; // eax
  void *v8; // rdx
  void *v9; // r8
  DWORD v10; // eax
  ULONG v11; // eax
  DWORD v12; // eax
  int v13; // [rsp+30h] [rbp+8h] BYREF

  v13 = 0;
  if ( _InterlockedIncrement((volatile signed __int32 *)this + 37) <= 1 )
  {
    if ( (*((_DWORD *)this + 38) & 0x40051555) != 0 )
      CCredentialGroup::InitializeCertificateStoreChange(this);
    v2 = (void *)*((_QWORD *)this + 96);
    if ( v2 )
    {
      v3 = (void *)*((_QWORD *)this + 97);
      if ( v3 )
      {
        v4 = CCredentialGroup::CheckCertStoreChangeNotification(this, v2, v3);
        if ( v4 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v4);
          }
        }
      }
    }
    v5 = (void *)*((_QWORD *)this + 102);
    if ( v5 )
    {
      v6 = (void *)*((_QWORD *)this + 103);
      if ( v6 )
      {
        v7 = CCredentialGroup::CheckCertStoreChangeNotification(this, v5, v6);
        if ( v7 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v7);
          }
        }
      }
    }
    v8 = (void *)*((_QWORD *)this + 104);
    if ( v8 )
    {
      v9 = (void *)*((_QWORD *)this + 105);
      if ( v9 )
      {
        v10 = CCredentialGroup::CheckCertStoreChangeNotification(this, v8, v9);
        if ( v10 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v10);
          }
        }
      }
    }
    if ( *((_QWORD *)this + 98) && *((_QWORD *)this + 99) )
    {
      v11 = SslImpersonateClient(*((_QWORD *)this + 94), &v13);
      if ( v11 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v11);
      }
      else
      {
        v12 = CCredentialGroup::CheckCertStoreChangeNotification(this, *((void **)this + 98), *((void **)this + 99));
        if ( v12
          && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 33i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v12);
        }
        if ( v13 )
          RevertToSelf();
      }
    }
  }
  _InterlockedDecrement((volatile signed __int32 *)this + 37);
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
