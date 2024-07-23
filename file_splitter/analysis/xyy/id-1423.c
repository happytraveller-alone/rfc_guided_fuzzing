//----- (00000001800714C4) ----------------------------------------------------
__int64 __fastcall CSslContext::I_RsaGenerateEcdsaSignClientExchangeValue(
        CSslContext *this,
        unsigned __int8 *a2,
        unsigned int *a3)
{
  int v3; // eax
  int v7; // r15d
  _DWORD *v8; // rax
  unsigned int SessionKeys; // ebx
  int v10; // edx
  unsigned int v11; // eax
  __int64 v12; // r8
  __int64 v13; // r9
  __int64 v14; // rcx
  unsigned __int8 v15; // r9
  int v16; // ebx
  unsigned int v17; // edx
  unsigned __int8 *v18; // rcx
  __int64 *v19; // rax
  int v20; // r8d
  __int64 v21; // r10
  unsigned int v22; // eax
  int v23; // r8d
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned __int8 *v26; // rcx
  __int64 *v27; // rax
  int v28; // r8d
  __int64 v29; // r10
  __int64 v30; // rcx
  __int64 v31; // r8
  __int64 v32; // r9
  unsigned int v33; // ecx
  unsigned int v35; // [rsp+60h] [rbp-69h] BYREF
  int v36[2]; // [rsp+68h] [rbp-61h] BYREF
  NCRYPT_KEY_HANDLE hObject; // [rsp+70h] [rbp-59h] BYREF
  __int64 v38; // [rsp+78h] [rbp-51h] BYREF
  int v39; // [rsp+80h] [rbp-49h] BYREF
  unsigned __int64 v40; // [rsp+88h] [rbp-41h] BYREF
  __int128 v41; // [rsp+90h] [rbp-39h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v42; // [rsp+A0h] [rbp-29h] BYREF
  char v43[64]; // [rsp+B0h] [rbp-19h] BYREF

  v3 = *((_DWORD *)this + 9);
  hObject = 0i64;
  v40 = 0i64;
  v38 = 0i64;
  *(_QWORD *)v36 = 0i64;
  v35 = 0;
  v39 = v3;
  v41 = 0i64;
  memset_0(v43, 0, sizeof(v43));
  v7 = *((_DWORD *)this + 16) & 0xA2A80;
  (*(void (__fastcall **)(CSslContext *, int *))(*(_QWORD *)this + 224i64))(this, v36);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(*(_QWORD *)v36 + 72i64), 1u);
  v8 = *(_DWORD **)(*(_QWORD *)v36 + 40i64);
  if ( !v8 || !*(_QWORD *)v8 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v36 + 72i64));
    v10 = 825;
    SessionKeys = 1359;
    goto LABEL_52;
  }
  SessionKeys = NCryptImportKey(
                  *(_QWORD *)(*((_QWORD *)this + 1) + 64i64),
                  0i64,
                  L"ECCPUBLICBLOB",
                  0i64,
                  &hObject,
                  (PBYTE)(*(_QWORD *)v8 + 8i64),
                  v8[2] - 8,
                  0);
  if ( SessionKeys )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v36 + 72i64));
    v10 = 813;
LABEL_52:
    v15 = 80;
    goto LABEL_53;
  }
  DWORD1(v41) = 4;
  *((_QWORD *)&v41 + 1) = v43;
  v11 = (*(__int64 (__fastcall **)(CSslContext *, __int128 *, _QWORD, _QWORD, int *, NCRYPT_KEY_HANDLE *))(*(_QWORD *)this + 136i64))(
          this,
          &v41,
          0i64,
          0i64,
          &v39,
          &hObject);
  v14 = *(_QWORD *)v36;
  SessionKeys = v11;
  if ( v11 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v36 + 72i64));
    v15 = 51;
    v10 = 826;
LABEL_53:
    v23 = SessionKeys;
    goto LABEL_54;
  }
  if ( *(_QWORD *)(*(_QWORD *)v36 + 16i64) )
  {
    SslFreeObject(*(_QWORD *)(*(_QWORD *)v36 + 16i64), 0i64);
    *(_QWORD *)(*(_QWORD *)v36 + 16i64) = 0i64;
    v14 = *(_QWORD *)v36;
  }
  v16 = v7 != 0 ? 2 : 0;
  if ( v7 && (*((_DWORD *)this + 34) & 0x8000000) != 0 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(v14 + 72));
    if ( a2 )
    {
      v17 = *a3 - v16;
      v18 = &a2[v16];
    }
    else
    {
      v17 = 0;
      v18 = 0i64;
    }
    if ( (*((_BYTE *)this + 32) & 1) != 0 && (v19 = (__int64 *)*((_QWORD *)this + 1)) != 0i64 )
    {
      v20 = *((_DWORD *)v19 + 7);
    }
    else
    {
      v19 = (__int64 *)*((_QWORD *)this + 1);
      v20 = 0;
    }
    if ( v19 )
      v21 = *v19;
    else
      v21 = 0i64;
    v22 = SslGeneratePreMasterKey(v21, hObject, &v38, *((unsigned __int16 *)this + 17), v20, &v41, v18, v17, &v35, 1);
    SessionKeys = v22;
    if ( v22 )
    {
      v15 = 51;
      v23 = v22;
      v10 = 708;
LABEL_54:
      CSslContext::SetErrorAndFatalAlert((__int64)this, v10, v23, v15);
      goto LABEL_55;
    }
    v24 = (*(__int64 (__fastcall **)(CSslContext *, __int64))(*(_QWORD *)this + 168i64))(this, v38);
    v38 = 0i64;
    SessionKeys = v24;
LABEL_42:
    v33 = v35 + 2;
    v35 += 2;
    goto LABEL_44;
  }
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v14, &GenerateMasterKeyStart, v12, v13, &v42);
  if ( a2 )
  {
    v25 = *a3 - v16;
    v26 = &a2[v16];
  }
  else
  {
    v25 = 0;
    v26 = 0i64;
  }
  if ( (*((_BYTE *)this + 32) & 1) != 0 && (v27 = (__int64 *)*((_QWORD *)this + 1)) != 0i64 )
  {
    v28 = *((_DWORD *)v27 + 7);
  }
  else
  {
    v27 = (__int64 *)*((_QWORD *)this + 1);
    v28 = 0;
  }
  if ( v27 )
    v29 = *v27;
  else
    v29 = 0i64;
  SessionKeys = SslGenerateMasterKey(
                  v29,
                  0i64,
                  hObject,
                  &v40,
                  *((unsigned __int16 *)this + 17),
                  v28,
                  &v41,
                  v26,
                  v25,
                  &v35,
                  1);
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v30, &GenerateMasterKeyStop, v31, v32, &v42);
  if ( SessionKeys )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v36 + 72i64));
    v15 = 51;
    v10 = 706;
    goto LABEL_53;
  }
  *(_QWORD *)(*(_QWORD *)v36 + 16i64) = v40;
  SessionKeys = CSslContext::MakeSessionKeys(this, v40);
  RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)v36 + 72i64));
  if ( SessionKeys )
    goto LABEL_55;
  if ( v7 )
    goto LABEL_42;
  v33 = v35;
LABEL_44:
  if ( a2 )
  {
    if ( *a3 >= v33 )
    {
      if ( v7 )
      {
        *a2 = (unsigned __int16)(v33 - 2) >> 8;
        a2[1] = v33 - 2;
      }
      *a3 = v33;
      LsaIModifyPerformanceCounter(6i64);
    }
    else
    {
      *a3 = v33;
      SessionKeys = -2146893023;
    }
  }
  else
  {
    *a3 = v33;
    SessionKeys = 0;
  }
LABEL_55:
  if ( hObject )
    NCryptFreeObject(hObject);
  if ( v38 )
    SslFreeObject(v38, 0i64);
  return SessionKeys;
}
// 180071795: variable 'v12' is possibly undefined
// 180071795: variable 'v13' is possibly undefined
// 18007183E: variable 'v30' is possibly undefined
// 18007183E: variable 'v31' is possibly undefined
// 18007183E: variable 'v32' is possibly undefined
// 180084BE0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStop;
// 180084BF0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 1800984A0: using guessed type __int64 __fastcall SslGenerateMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 1800984A8: using guessed type __int64 __fastcall SslGeneratePreMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

