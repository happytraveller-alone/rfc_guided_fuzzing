//----- (00000001800758BC) ----------------------------------------------------
__int64 __fastcall MakeRsaSessionKeysHelper(struct CSsl3TlsContext *this, __int64 a2)
{
  unsigned int v5; // edi
  __int64 v6; // rax
  _QWORD *v7; // rcx
  __int64 v8; // rcx
  unsigned int SessionKeys; // edi
  __int64 v10; // r8
  __int64 v11; // r9
  int v12; // edx
  __int64 *v13; // rax
  int v14; // edx
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // r8
  __int64 v18; // r9
  unsigned int v19; // [rsp+60h] [rbp-49h] BYREF
  unsigned __int64 v20; // [rsp+68h] [rbp-41h] BYREF
  __int128 v21; // [rsp+70h] [rbp-39h] BYREF
  int v22[2]; // [rsp+80h] [rbp-29h] BYREF
  __int128 *v23; // [rsp+88h] [rbp-21h]
  struct _EVENT_DATA_DESCRIPTOR v24; // [rsp+90h] [rbp-19h] BYREF
  char v25[64]; // [rsp+A0h] [rbp-9h] BYREF

  v20 = 0i64;
  memset((char *)&v21 + 4, 0, 12);
  memset_0(v25, 0, sizeof(v25));
  v19 = 0;
  if ( !this )
    return 87i64;
  if ( (*((_DWORD *)this + 16) & 0xA2A80) == 0 || (*((_DWORD *)this + 34) & 0x8000000) == 0 )
    return 1359i64;
  v5 = *((unsigned __int16 *)this + 17);
  v6 = (*(__int64 (__fastcall **)(struct CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 512i64))(this, 0i64);
  v7 = (_QWORD *)*((_QWORD *)this + 1);
  if ( v7 )
    v7 = (_QWORD *)*v7;
  SessionKeys = SslComputeSessionHash(v7, v6, v5, v25, 64, &v19, 0);
  if ( SessionKeys )
  {
    v12 = 604;
LABEL_9:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v12, SessionKeys, 0x33u);
    return SessionKeys;
  }
  v22[0] = 0;
  v23 = &v21;
  *(_QWORD *)&v21 = v19 | 0x1900000000i64;
  *((_QWORD *)&v21 + 1) = v25;
  v22[1] = 1;
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v8, &GenerateMasterKeyStart, v10, v11, &v24);
  if ( (*((_BYTE *)this + 32) & 1) != 0 && (v13 = (__int64 *)*((_QWORD *)this + 1)) != 0i64 )
  {
    v14 = *((_DWORD *)v13 + 7);
  }
  else
  {
    v13 = (__int64 *)*((_QWORD *)this + 1);
    v14 = 0;
  }
  if ( v13 )
    v15 = *v13;
  else
    v15 = 0i64;
  SessionKeys = SslGenerateMasterKey(v15, a2, 0i64, &v20, *((unsigned __int16 *)this + 17), v14, v22, 0i64, 0, &v19, 1);
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v16, &GenerateMasterKeyStop, v17, v18, &v24);
  if ( SessionKeys )
  {
    v12 = 706;
    goto LABEL_9;
  }
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
  *(_QWORD *)(*((_QWORD *)this + 11) + 16i64) = v20;
  SessionKeys = CSslContext::MakeSessionKeys(this, v20);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
  if ( SessionKeys )
    return SessionKeys;
  LsaIModifyPerformanceCounter(6i64);
  return 0i64;
}
// 1800759EC: variable 'v8' is possibly undefined
// 1800759EC: variable 'v10' is possibly undefined
// 1800759EC: variable 'v11' is possibly undefined
// 180075A7B: variable 'v16' is possibly undefined
// 180075A7B: variable 'v17' is possibly undefined
// 180075A7B: variable 'v18' is possibly undefined
// 180084BE0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStop;
// 180084BF0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 1800984A0: using guessed type __int64 __fastcall SslGenerateMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098530: using guessed type __int64 __fastcall SslComputeSessionHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);

