// File count: 1036
// Total lines: 98
----------------------------------------
__int64 __fastcall CCredentialGroup::RenewImplicitCertificates(void **this)
{
  __int64 v2; // rcx
  __int64 v3; // r8
  __int64 v4; // r9
  __int64 v5; // rcx
  void *Updated; // rbx
  __int64 v7; // r8
  __int64 v8; // r9
  unsigned int LastError; // edi
  CCipherMill *v10; // rcx
  __int64 v11; // rdx
  __int64 v13; // r8
  __int64 v14; // r9
  struct LSA_SCHANNEL_SUB_CRED *v15; // rdi
  __int64 v16; // rbp
  unsigned int RenewedCredential; // eax
  char v18[4]; // [rsp+30h] [rbp-98h] BYREF
  unsigned int v19; // [rsp+34h] [rbp-94h]
  struct LSA_SCHANNEL_SUB_CRED *v20; // [rsp+38h] [rbp-90h]
  HCERTSTORE hCertStore; // [rsp+50h] [rbp-78h]
  struct _EVENT_DATA_DESCRIPTOR v22; // [rsp+A0h] [rbp-28h] BYREF

  memset_0(v18, 0, 0x70ui64);
  if ( CryptObjectLocatorIsChanged(this[100]) )
  {
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v2, &LocatorGetUpdatedStart, v3, v4, &v22);
    Updated = CryptObjectLocatorGetUpdated(this[100]);
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v5, &LocatorGetUpdatedStop, v7, v8, &v22);
    if ( !Updated )
    {
      LastError = GetLastError();
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return LastError;
      v11 = 25i64;
LABEL_10:
      WPP_SF_D(*((_QWORD *)v10 + 2), v11, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, LastError);
      return LastError;
    }
    CryptObjectLocatorFree(this[100]);
    this[100] = Updated;
    LastError = LoadCertificatesFromLocator(Updated, (struct LSA_SCHANNEL_CRED *)v18, v13, v14);
    if ( LastError )
    {
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return LastError;
      v11 = 26i64;
      goto LABEL_10;
    }
    if ( v19 )
    {
      v15 = v20;
      v16 = v19;
      do
      {
        RenewedCredential = CCredentialGroup::CreateRenewedCredential((CCredentialGroup *)this, v15);
        if ( RenewedCredential
          && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            27i64,
            &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids,
            RenewedCredential);
        }
        v15 = (struct LSA_SCHANNEL_SUB_CRED *)((char *)v15 + 56);
        --v16;
      }
      while ( v16 );
    }
    if ( hCertStore )
      CertCloseStore(hCertStore, 0);
    FreeSchannelCred((struct LSA_SCHANNEL_CRED *)v18, 0);
  }
  return 0i64;
}
// 180056C64: variable 'v2' is possibly undefined
// 180056C64: variable 'v3' is possibly undefined
// 180056C64: variable 'v4' is possibly undefined
// 180056C9C: variable 'v5' is possibly undefined
// 180056C9C: variable 'v7' is possibly undefined
// 180056C9C: variable 'v8' is possibly undefined
// 180056D0E: variable 'v13' is possibly undefined
// 180056D0E: variable 'v14' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
// 180084C00: using guessed type EVENT_DESCRIPTOR LocatorGetUpdatedStop;
// 180084C10: using guessed type EVENT_DESCRIPTOR LocatorGetUpdatedStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180098018: using guessed type void __stdcall CryptObjectLocatorFree(void *);
// 1800981A0: using guessed type _DWORD __stdcall CryptObjectLocatorIsChanged(void *);
// 1800981A8: using guessed type void *__stdcall CryptObjectLocatorGetUpdated(void *);
