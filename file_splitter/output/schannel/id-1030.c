// File count: 1030
// Total lines: 131
---------------------------------------
void __fastcall CCredentialGroup::InitializeCertificateStoreChange(CCredentialGroup *this)
{
  void *v1; // rdx
  CCredentialGroup *v2; // rbx
  DWORD v3; // eax
  void *v4; // rdx
  DWORD v5; // eax
  HCERTSTORE v6; // rax
  CCredentialGroup *v7; // rcx
  DWORD LastError; // eax
  CCipherMill *v9; // rcx
  __int64 v10; // rdx
  ULONG v11; // eax
  HCERTSTORE v12; // rax
  CCredentialGroup *v13; // rcx
  DWORD v14; // eax
  CCipherMill *v15; // rcx
  __int64 v16; // rdx
  int v17; // [rsp+40h] [rbp+8h] BYREF

  v17 = 0;
  v1 = (void *)*((_QWORD *)this + 96);
  v2 = this;
  if ( v1 )
  {
    if ( !*((_QWORD *)this + 97) )
    {
      v3 = CCredentialGroup::SubscribeCertStoreChangeNotification(this, v1, (void **)this + 97);
      if ( v3 )
      {
        this = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v3);
      }
    }
  }
  v4 = (void *)*((_QWORD *)v2 + 102);
  if ( v4 )
  {
    if ( !*((_QWORD *)v2 + 103) )
    {
      v5 = CCredentialGroup::SubscribeCertStoreChangeNotification(this, v4, (void **)v2 + 103);
      if ( v5 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v5);
      }
    }
  }
  if ( !*((_QWORD *)v2 + 104) )
  {
    v6 = CertOpenStore((LPCSTR)0xA, 0, 0i64, 0x20000u, L"ClientAuthIssuer");
    *((_QWORD *)v2 + 104) = v6;
    if ( v6 )
    {
      if ( !*((_QWORD *)v2 + 105) )
      {
        LastError = CCredentialGroup::SubscribeCertStoreChangeNotification(v7, v6, (void **)v2 + 105);
        if ( LastError )
        {
          v9 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            v10 = 17i64;
            goto LABEL_23;
          }
        }
      }
    }
    else
    {
      LastError = GetLastError();
      v9 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        v10 = 16i64;
LABEL_23:
        WPP_SF_D(*((_QWORD *)v9 + 2), v10, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, LastError);
      }
    }
  }
  if ( *((_QWORD *)v2 + 98) )
    return;
  v11 = SslImpersonateClient(*((_QWORD *)v2 + 94), &v17);
  if ( v11 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v11);
    return;
  }
  v12 = CertOpenStore((LPCSTR)0xA, 0, 0i64, 0x18001u, L"ROOT");
  *((_QWORD *)v2 + 98) = v12;
  if ( v12 )
  {
    if ( !*((_QWORD *)v2 + 99) )
    {
      v14 = CCredentialGroup::SubscribeCertStoreChangeNotification(v13, v12, (void **)v2 + 99);
      if ( v14 )
      {
        v15 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          v16 = 20i64;
          goto LABEL_38;
        }
      }
    }
  }
  else
  {
    v14 = GetLastError();
    v15 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v16 = 19i64;
LABEL_38:
      WPP_SF_D(*((_QWORD *)v15 + 2), v16, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v14);
    }
  }
  if ( v17 )
    RevertToSelf();
}
// 18005623B: variable 'this' is possibly undefined
// 1800562DF: variable 'v7' is possibly undefined
// 1800563CB: variable 'v13' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
// 1800854C0: using guessed type wchar_t aRoot[5];
// 180085538: using guessed type wchar_t aClientauthissu[17];
