//----- (0000000180054298) ----------------------------------------------------
__int64 __fastcall LoadCertificatesFromLocator(void *a1, struct LSA_SCHANNEL_CRED *a2, __int64 a3, __int64 a4)
{
  __int64 v6; // rcx
  void *Content; // rdi
  __int64 v8; // r8
  __int64 v9; // r9
  DWORD LastError; // eax
  unsigned int v11; // ebx
  CCipherMill *v12; // rcx
  unsigned int EndpointCerts; // eax
  __int64 v14; // rdx
  __int64 v15; // r9
  struct LSA_SCHANNEL_SUB_CRED *v16; // rax
  PEVENT_DATA_DESCRIPTOR v18; // [rsp+20h] [rbp-58h]
  unsigned int v19; // [rsp+30h] [rbp-48h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v20; // [rsp+38h] [rbp-40h] BYREF

  v19 = 0;
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer((__int64)a1, &LocatorGetContentStart, a3, a4, &v20);
  Content = CryptObjectLocatorGetContent(a1);
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v6, &LocatorGetContentStop, v8, v9, &v20);
  if ( !Content )
  {
    LastError = GetLastError();
    v11 = LastError;
    v12 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, LastError);
      v12 = WPP_GLOBAL_Control;
    }
    if ( !v11 )
      goto LABEL_34;
    goto LABEL_28;
  }
  EndpointCerts = GetEndpointCerts(Content, 0i64, &v19);
  v11 = EndpointCerts;
  if ( EndpointCerts )
  {
    v12 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v14 = 33i64;
LABEL_25:
      v15 = EndpointCerts;
      goto LABEL_26;
    }
  }
  else
  {
    if ( v19 )
    {
      v16 = (struct LSA_SCHANNEL_SUB_CRED *)SPExternalAlloc(56 * v19);
      *((_QWORD *)a2 + 1) = v16;
      if ( !v16 )
      {
        v11 = 14;
LABEL_27:
        v12 = WPP_GLOBAL_Control;
        goto LABEL_28;
      }
      EndpointCerts = GetEndpointCerts(Content, v16, &v19);
      v11 = EndpointCerts;
      if ( !EndpointCerts )
      {
        *((_DWORD *)a2 + 1) = v19;
        *((_QWORD *)a2 + 3) = a1;
        *((_QWORD *)a2 + 4) = Content;
        goto LABEL_33;
      }
      v12 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_28;
      v14 = 35i64;
      goto LABEL_25;
    }
    v11 = -2146893042;
    v12 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v14 = v19 + 34;
      v15 = 2148074254i64;
LABEL_26:
      WPP_SF_D(*((_QWORD *)v12 + 2), v14, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v15);
      goto LABEL_27;
    }
  }
LABEL_28:
  if ( *((_QWORD *)a2 + 1) )
  {
    SPExternalFree(*((void **)a2 + 1));
    v12 = WPP_GLOBAL_Control;
  }
  if ( Content )
  {
    CertCloseStore(Content, 0);
LABEL_33:
    v12 = WPP_GLOBAL_Control;
  }
LABEL_34:
  if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 0x20) != 0 )
  {
    LODWORD(v18) = v11;
    WPP_SF_DD(*((_QWORD *)v12 + 2), 0x24u, (__int64)&WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v11, v18);
  }
  return v11;
}
// 18005430D: variable 'v6' is possibly undefined
// 18005430D: variable 'v8' is possibly undefined
// 18005430D: variable 'v9' is possibly undefined
// 180054484: variable 'v18' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C20: using guessed type EVENT_DESCRIPTOR LocatorGetContentStop;
// 180084C30: using guessed type EVENT_DESCRIPTOR LocatorGetContentStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180098168: using guessed type void *__stdcall CryptObjectLocatorGetContent(void *);

