// File count: 20
// Total lines: 208
-----------------------------------------
__int64 __fastcall MakeEccDhPskSessionKeysHelper(struct CSsl3TlsContext *a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v8; // rcx
  _WORD *v9; // r9
  int v10; // eax
  unsigned int v11; // edi
  __int64 v12; // rax
  __int64 *v13; // rcx
  __int64 v14; // rcx
  int v15; // eax
  unsigned int v16; // edi
  __int64 v17; // r8
  __int64 *v18; // rdx
  int v19; // r8d
  int v20; // r9d
  __int64 v21; // rcx
  __int64 v22; // rcx
  unsigned int v23; // edi
  __int64 v24; // r8
  __int64 v25; // r9
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // r15
  __int64 v29; // rcx
  __int64 v30; // rax
  int v31; // eax
  unsigned int v32; // esi
  __int64 *v33; // rax
  __int64 v34; // rcx
  __int64 v35; // rcx
  int v37; // edx
  unsigned int v38; // [rsp+60h] [rbp-A0h] BYREF
  int v39; // [rsp+64h] [rbp-9Ch] BYREF
  __int64 v40; // [rsp+68h] [rbp-98h] BYREF
  int v41; // [rsp+70h] [rbp-90h] BYREF
  int v42; // [rsp+74h] [rbp-8Ch]
  __int128 *v43; // [rsp+78h] [rbp-88h]
  struct _EVENT_DATA_DESCRIPTOR v44; // [rsp+80h] [rbp-80h] BYREF
  __int128 v45; // [rsp+90h] [rbp-70h] BYREF
  __int128 v46; // [rsp+A0h] [rbp-60h]
  __int128 v47; // [rsp+B0h] [rbp-50h]
  char v48; // [rsp+C0h] [rbp-40h] BYREF
  char v49[64]; // [rsp+100h] [rbp+0h] BYREF

  v40 = 0i64;
  v42 = 0;
  v45 = 0i64;
  v46 = 0i64;
  v47 = 0i64;
  memset_0(v49, 0, sizeof(v49));
  v38 = 0;
  if ( !a1 )
    return 87i64;
  v43 = &v45;
  v10 = *((_DWORD *)a1 + 34);
  v41 = 0;
  if ( (v10 & 0x8000000) != 0 )
  {
    v11 = *((unsigned __int16 *)a1 + 17);
    v12 = (*(__int64 (__fastcall **)(struct CSsl3TlsContext *, _QWORD))(*(_QWORD *)a1 + 512i64))(a1, 0i64);
    v13 = (__int64 *)*((_QWORD *)a1 + 1);
    if ( v13 )
      v14 = *v13;
    else
      v14 = 0i64;
    v15 = SslComputeSessionHash(v14, v12, v11, v49, 64, &v38, 0);
    v16 = v15;
    if ( v15 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)a1, 604, v15, 0x33u);
      return v16;
    }
    v17 = 1i64;
    *(_QWORD *)&v45 = v38 | 0x1900000000i64;
    *((_QWORD *)&v45 + 1) = v49;
  }
  else
  {
    *((_QWORD *)&v45 + 1) = (char *)a1 + 272;
    v17 = 2i64;
    *(_QWORD *)&v45 = 0x1400000020i64;
    *((_QWORD *)&v46 + 1) = (char *)a1 + 304;
    *(_QWORD *)&v46 = 0x1500000020i64;
  }
  v18 = (__int64 *)*((_QWORD *)a1 + 1);
  v42 = v17;
  if ( *((_DWORD *)v18 + 12) == 4 )
  {
    v9 = (_WORD *)*((_QWORD *)a1 + 106);
    if ( !v9 )
      return 590624i64;
    if ( !*v9 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)a1, 602, 87, 0x73u);
      return 87i64;
    }
    v8 = 2i64 * (unsigned int)v17;
    v17 = (unsigned int)(v17 + 1);
    *((_DWORD *)&v45 + 2 * v8 + 1) = 23;
    *((_DWORD *)&v45 + 2 * v8) = (unsigned __int16)*v9;
    *((_QWORD *)&v45 + v8 + 1) = v9 + 1;
    v42 = v17;
  }
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
  {
    McGenEventWrite_EventWriteTransfer(v8, &GenerateMasterKeyStart, v17, (__int64)v9, &v44);
    v18 = (__int64 *)*((_QWORD *)a1 + 1);
  }
  if ( (*((_BYTE *)a1 + 32) & 1) != 0 )
  {
    v18 = (__int64 *)*((_QWORD *)a1 + 1);
    if ( v18 )
    {
      v19 = *((_DWORD *)v18 + 7);
      v20 = *((unsigned __int16 *)a1 + 17);
LABEL_13:
      v21 = *v18;
      goto LABEL_14;
    }
  }
  v20 = *((unsigned __int16 *)a1 + 17);
  v19 = 0;
  if ( v18 )
    goto LABEL_13;
  v21 = 0i64;
LABEL_14:
  v23 = SslGenerateMasterKey(v21, a2, a3, &v40, v20, v19, &v41, 0i64, 0, &v38, (unsigned int)(a4 != 0) + 1);
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v22, &GenerateMasterKeyStop, v24, v25, &v44);
  if ( v23 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)a1, 602, v23, 0x33u);
    return v23;
  }
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64), 1u);
  v26 = *((_QWORD *)a1 + 11);
  v39 = 0;
  *(_QWORD *)(v26 + 16) = v40;
  v27 = *((_QWORD *)a1 + 20);
  v28 = v40;
  if ( v27 )
  {
    SslFreeObject(v27, 0i64);
    *((_QWORD *)a1 + 20) = 0i64;
  }
  v29 = *((_QWORD *)a1 + 21);
  if ( v29 )
  {
    SslFreeObject(v29, 0i64);
    *((_QWORD *)a1 + 21) = 0i64;
  }
  if ( (*((_BYTE *)a1 + 32) & 1) == 0 )
    goto LABEL_28;
  v30 = *((_QWORD *)a1 + 1);
  if ( !v30 || !*(_DWORD *)(v30 + 28) )
    goto LABEL_28;
  v44.Ptr = 0x400000000i64;
  *(_QWORD *)&v44.Size = &v48;
  v31 = (*(__int64 (__fastcall **)(struct CSsl3TlsContext *, _QWORD, int *, struct _EVENT_DATA_DESCRIPTOR *, _QWORD, _QWORD))(*(_QWORD *)a1 + 128i64))(
          a1,
          0i64,
          &v39,
          &v44,
          0i64,
          0i64);
  v32 = v31;
  if ( v31 )
  {
    v37 = 601;
LABEL_46:
    CSslContext::SetErrorAndFatalAlert((__int64)a1, v37, v31, 0x33u);
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64));
    return v32;
  }
  v33 = (__int64 *)*((_QWORD *)a1 + 1);
  if ( v33 )
    v34 = *v33;
  else
    v34 = 0i64;
  v31 = SslGenerateSessionKeys(v34, v28, (char *)a1 + 160, (char *)a1 + 168, &v44, 0);
  v32 = v31;
  if ( v31 )
  {
    v37 = 600;
    goto LABEL_46;
  }
LABEL_28:
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64));
  v35 = 8i64;
  if ( !a4 )
    v35 = 6i64;
  LsaIModifyPerformanceCounter(v35);
  return 0i64;
}
// 18002C76C: variable 'v8' is possibly undefined
// 18002C76C: variable 'v9' is possibly undefined
// 18002C78A: variable 'v22' is possibly undefined
// 18002C78A: variable 'v24' is possibly undefined
// 18002C78A: variable 'v25' is possibly undefined
// 180084BE0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStop;
// 180084BF0: using guessed type EVENT_DESCRIPTOR GenerateMasterKeyStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 180098428: using guessed type __int64 __fastcall SslGenerateSessionKeys(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 1800984A0: using guessed type __int64 __fastcall SslGenerateMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098530: using guessed type __int64 __fastcall SslComputeSessionHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
