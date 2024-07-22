//----- (0000000180070F40) ----------------------------------------------------
__int64 __fastcall CSslContext::I_RsaGenerateClientExchangeValue(
        CSslContext *this,
        unsigned __int8 *a2,
        unsigned int *a3,
        unsigned __int8 *a4)
{
  unsigned int SessionKeys; // ebx
  int v8; // r15d
  __int64 *v9; // rax
  __int64 pbData; // rsi
  DWORD cbData; // r9d
  unsigned int v12; // edx
  int v13; // r14d
  bool v14; // zf
  struct kexch *KeyExchangeInfo; // rax
  unsigned int v16; // ecx
  int v17; // edx
  unsigned int v18; // eax
  __int64 v19; // r8
  __int64 v20; // r9
  __int64 v21; // rcx
  unsigned __int8 v22; // r9
  __int64 *v23; // rax
  int v24; // edx
  __int64 v25; // r10
  unsigned int v26; // eax
  int v27; // r8d
  unsigned int v28; // eax
  __int64 *v29; // rax
  int v30; // edx
  __int64 v31; // r10
  __int64 v32; // rcx
  __int64 v33; // r8
  __int64 v34; // r9
  unsigned int v35; // ecx
  unsigned int v37; // [rsp+60h] [rbp-81h] BYREF
  int v38[2]; // [rsp+68h] [rbp-79h] BYREF
  NCRYPT_KEY_HANDLE hObject; // [rsp+70h] [rbp-71h] BYREF
  __int64 v40; // [rsp+78h] [rbp-69h] BYREF
  int v41; // [rsp+80h] [rbp-61h] BYREF
  unsigned __int64 v42; // [rsp+88h] [rbp-59h] BYREF
  __int128 v43; // [rsp+90h] [rbp-51h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v44; // [rsp+A0h] [rbp-41h] BYREF
  char v45[64]; // [rsp+B0h] [rbp-31h] BYREF

  SessionKeys = 0;
  v41 = *((_DWORD *)this + 9);
  hObject = 0i64;
  v42 = 0i64;
  v40 = 0i64;
  *(_QWORD *)v38 = 0i64;
  v37 = 0;
  v43 = 0i64;
  memset_0(v45, 0, sizeof(v45));
  v8 = *((_DWORD *)this + 16) & 0xA2A80;
  (*(void (__fastcall **)(CSslContext *, int *))(*(_QWORD *)this + 224i64))(this, v38);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64), 1u);
  v9 = *(__int64 **)(*(_QWORD *)v38 + 40i64);
  if ( !v9 || (pbData = *v9) == 0 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
    v17 = 812;
    SessionKeys = 1359;
    goto LABEL_55;
  }
  cbData = *((_DWORD *)v9 + 2);
  v12 = cbData;
  v37 = cbData;
  if ( v8 )
  {
    v12 = cbData + 2;
    v37 = cbData + 2;
  }
  v13 = v8 != 0 ? 2 : 0;
  if ( !a2 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
    *a3 = v37;
    goto LABEL_58;
  }
  if ( *a3 < v12 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
    SessionKeys = -2146893023;
    *a3 = v37;
    goto LABEL_58;
  }
  if ( *(_DWORD *)(pbData + 16) == 1 )
  {
    v14 = g_fIgnoreExponentOfOne == 0;
    *(_DWORD *)(*(_QWORD *)v38 + 8i64) = 0;
    if ( v14 )
    {
      RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
      SessionKeys = -2146893015;
      goto LABEL_58;
    }
  }
  else
  {
    *(_DWORD *)(*(_QWORD *)v38 + 8i64) = *(_DWORD *)(pbData + 12);
    KeyExchangeInfo = GetKeyExchangeInfo(41984);
    v16 = *(_DWORD *)(pbData + 12);
    if ( v16 < *((_DWORD *)KeyExchangeInfo + 8) || v16 > *((_DWORD *)KeyExchangeInfo + 10) )
    {
      RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
      SessionKeys = 87;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xBu,
          (__int64)&WPP_ef2bc8f963c43ddcdfece7ee9e95f200_Traceguids,
          *(_DWORD *)(pbData + 12));
      v22 = 40;
      v17 = 813;
      goto LABEL_56;
    }
  }
  SessionKeys = NCryptImportKey(hProvider, 0i64, L"CAPIPUBLICBLOB", 0i64, &hObject, (PBYTE)pbData, cbData, 0);
  if ( SessionKeys )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
    v17 = 813;
LABEL_55:
    v22 = 80;
    goto LABEL_56;
  }
  DWORD1(v43) = 4;
  *((_QWORD *)&v43 + 1) = v45;
  v18 = (*(__int64 (__fastcall **)(CSslContext *, __int128 *, _QWORD, _QWORD, int *, NCRYPT_KEY_HANDLE *))(*(_QWORD *)this + 136i64))(
          this,
          &v43,
          0i64,
          0i64,
          &v41,
          &hObject);
  v21 = *(_QWORD *)v38;
  SessionKeys = v18;
  if ( v18 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
    v22 = 51;
    v17 = 814;
LABEL_56:
    v27 = SessionKeys;
    goto LABEL_57;
  }
  if ( *(_QWORD *)(*(_QWORD *)v38 + 16i64) )
  {
    SslFreeObject(*(_QWORD *)(*(_QWORD *)v38 + 16i64), 0i64);
    *(_QWORD *)(*(_QWORD *)v38 + 16i64) = 0i64;
    v21 = *(_QWORD *)v38;
  }
  if ( !v8 || (*((_DWORD *)this + 34) & 0x8000000) == 0 )
  {
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v21, &GenerateMasterKeyStart, v19, v20, &v44);
    if ( (*((_BYTE *)this + 32) & 1) != 0 && (v29 = (__int64 *)*((_QWORD *)this + 1)) != 0i64 )
    {
      v30 = *((_DWORD *)v29 + 7);
    }
    else
    {
      v29 = (__int64 *)*((_QWORD *)this + 1);
      v30 = 0;
    }
    if ( v29 )
      v31 = *v29;
    else
      v31 = 0i64;
    SessionKeys = SslGenerateMasterKey(
                    v31,
                    0i64,
                    hObject,
                    &v42,
                    *((unsigned __int16 *)this + 17),
                    v30,
                    &v43,
                    &a2[v13],
                    v37 - v13,
                    &v37,
                    1);
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v32, &GenerateMasterKeyStop, v33, v34, &v44);
    if ( SessionKeys )
    {
      RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
      v22 = 51;
      v17 = 706;
      goto LABEL_56;
    }
    *(_QWORD *)(*(_QWORD *)v38 + 16i64) = v42;
    SessionKeys = CSslContext::MakeSessionKeys(this, v42);
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v38 + 72i64));
    if ( SessionKeys )
      goto LABEL_58;
    if ( !v8 )
    {
      v35 = v37;
      goto LABEL_49;
    }
LABEL_47:
    v35 = v37;
    *a2 = BYTE1(v37);
    a2[1] = v35;
LABEL_49:
    *a3 = v13 + v35;
    LsaIModifyPerformanceCounter(6i64);
    goto LABEL_58;
  }
  RtlReleaseResource((PRTL_RESOURCE)(v21 + 72));
  if ( (*((_BYTE *)this + 32) & 1) != 0 && (v23 = (__int64 *)*((_QWORD *)this + 1)) != 0i64 )
  {
    v24 = *((_DWORD *)v23 + 7);
  }
  else
  {
    v23 = (__int64 *)*((_QWORD *)this + 1);
    v24 = 0;
  }
  if ( v23 )
    v25 = *v23;
  else
    v25 = 0i64;
  v26 = SslGeneratePreMasterKey(
          v25,
          hObject,
          &v40,
          *((unsigned __int16 *)this + 17),
          v24,
          &v43,
          &a2[v13],
          v37 - v13,
          &v37,
          1);
  SessionKeys = v26;
  if ( !v26 )
  {
    v28 = (*(__int64 (__fastcall **)(CSslContext *, __int64))(*(_QWORD *)this + 168i64))(this, v40);
    v40 = 0i64;
    SessionKeys = v28;
    goto LABEL_47;
  }
  v22 = 51;
  v27 = v26;
  v17 = 708;
LABEL_57:
  CSslContext::SetErrorAndFatalAlert((__int64)this, v17, v27, v22);
LABEL_58:
  if ( hObject )
    NCryptFreeObject(hObject);
  if ( v40 )
    SslFreeObject(v40, 0i64);
  return SessionKeys;
}
// 1800710F2: variable 'cbData' is possibly undefined
// 1800712BB: variable 'v19' is possibly undefined
// 1800712BB: variable 'v20' is possibly undefined
// 180071356: variable 'v32' is possibly undefined
// 180071356: variable 'v33' is possibly undefined
// 180071356: variable 'v34' is possibly undefined
// 180084BE0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStop;
// 180084BF0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180092F1C: using guessed type int g_fIgnoreExponentOfOne;
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 1800984A0: using guessed type __int64 __fastcall SslGenerateMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 1800984A8: using guessed type __int64 __fastcall SslGeneratePreMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

