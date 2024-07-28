//----- (000000018004835C) ----------------------------------------------------
__int64 __fastcall SslDoClientRequest(
        void **a1,
        void *a2,
        size_t a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  int v7; // edi
  void *v8; // r13
  struct _MSV1_0_PASSTHROUGH_RESPONSE *v9; // r14
  void **v12; // r12
  unsigned int v13; // eax
  int v14; // ebx
  const wchar_t *v15; // rsi
  unsigned int v16; // ecx
  SIZE_T v17; // rdx
  _DWORD *v18; // rax
  _DWORD *v19; // rbx
  int v20; // edx
  __int64 v21; // rcx
  unsigned int *v22; // rax
  unsigned int v23; // ebx
  int v25; // eax
  PUCHAR ValidationData; // rdi
  wchar_t *v27; // rax
  struct _MSV1_0_PASSTHROUGH_RESPONSE *v28; // [rsp+48h] [rbp-41h] BYREF
  void *v29; // [rsp+50h] [rbp-39h] BYREF
  PCWSTR SourceString; // [rsp+58h] [rbp-31h] BYREF
  void *v31; // [rsp+60h] [rbp-29h]
  struct _UNICODE_STRING DestinationString; // [rsp+68h] [rbp-21h] BYREF
  char v33[80]; // [rsp+78h] [rbp-11h] BYREF
  void **v34; // [rsp+D8h] [rbp+4Fh] BYREF
  void *Src; // [rsp+E0h] [rbp+57h] BYREF
  size_t Size; // [rsp+E8h] [rbp+5Fh] BYREF

  Size = a3;
  v34 = a1;
  v7 = 0;
  Src = 0i64;
  v8 = 0i64;
  v31 = 0i64;
  v9 = 0i64;
  v29 = 0i64;
  SourceString = 0i64;
  DestinationString = 0i64;
  v28 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 51i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
  v12 = a5;
  if ( a5 )
    *a5 = 0i64;
  v13 = SslMapCertToUserPac(
          (struct _SSL_CERT_LOGON_REQ *)a2,
          a4,
          (unsigned __int8 **)&Src,
          (unsigned int *)&Size,
          (unsigned __int16 **)&SourceString);
  v14 = v13;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 52i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v13);
  v15 = SourceString;
  if ( v14 >= 0 )
  {
    v8 = Src;
LABEL_11:
    DestinationString = SslDomainName;
    goto LABEL_12;
  }
  if ( !SourceString )
    goto LABEL_11;
  RtlInitUnicodeString(&DestinationString, SourceString);
  RtlAcquireResourceShared(&SslGlobalLock, 1u);
  if ( RtlEqualUnicodeString(&DestinationString, &SslGlobalDnsDomainName, 1u)
    || RtlEqualUnicodeString(&DestinationString, &SslDomainName, 1u) )
  {
    v7 = 1;
  }
  RtlReleaseResource(&SslGlobalLock);
  if ( v7 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 53i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
    v14 = -1073741715;
    goto LABEL_27;
  }
  if ( (*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v33) && (v33[8] & 8) != 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 54i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
    goto LABEL_27;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_S(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x37u, (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v15);
  v25 = SslMapCertAtDC(
          &DestinationString,
          a2,
          *((_DWORD *)a2 + 1),
          1,
          0,
          (unsigned __int8 **)&Src,
          (unsigned int *)&Size,
          &v28);
  v9 = v28;
  v14 = v25;
  if ( v25 < 0 )
    goto LABEL_27;
  ValidationData = v28->ValidationData;
  v31 = Src;
  v27 = wcschr(v15, 0x2Eu);
  if ( v27 )
  {
    *v27 = 0;
    RtlInitUnicodeString(&DestinationString, v15);
  }
  if ( (unsigned int)(*((_DWORD *)ValidationData + 1) - *((_DWORD *)ValidationData + 3)) <= 0x20
    || *((_DWORD *)ValidationData + 6) >= 0x10000u )
  {
    goto LABEL_13;
  }
  DestinationString.Length = *((_WORD *)ValidationData + 12);
  DestinationString.MaximumLength = DestinationString.Length;
  DestinationString.Buffer = (PWSTR)&ValidationData[*((unsigned int *)ValidationData + 5)];
LABEL_12:
  if ( v14 < 0 )
  {
LABEL_27:
    *a6 = 0;
    *a7 = v14;
    goto LABEL_28;
  }
LABEL_13:
  v14 = (*(__int64 (__fastcall **)(void *, _QWORD, _QWORD, void **, void ***))(LsaTable + 376))(
          Src,
          (unsigned int)Size,
          0i64,
          &v29,
          &v34);
  if ( v14 < 0 )
    goto LABEL_27;
  Src = v29;
  LODWORD(Size) = (_DWORD)v34;
  v16 = (_DWORD)v34 + 32;
  if ( (unsigned int)v34 >= 0xFFFFFFE0 || (v17 = v16 + DestinationString.Length, (unsigned int)v17 < v16) )
  {
    v23 = -1073741675;
  }
  else
  {
    v18 = VirtualAlloc(0i64, v17, 0x1000u, 4u);
    v19 = v18;
    if ( v18 )
    {
      *v18 = 2;
      v20 = Size + 32 + DestinationString.Length;
      v18[2] = 32;
      v18[1] = v20;
      v18[3] = Size;
      memcpy_0(v18 + 8, Src, (unsigned int)Size);
      v21 = (unsigned int)(Size + 32);
      v19[5] = v21;
      v19[6] = DestinationString.Length;
      memcpy_0((char *)v19 + v21, DestinationString.Buffer, DestinationString.Length);
      v22 = a6;
      *v12 = v19;
      *v22 = v19[1];
      *a7 = 0;
LABEL_28:
      v23 = 0;
      goto LABEL_29;
    }
    v23 = -1073741801;
  }
LABEL_29:
  if ( v9 )
    (*(void (__fastcall **)(struct _MSV1_0_PASSTHROUGH_RESPONSE *))(LsaTable + 184))(v9);
  if ( v8 )
    (*(void (__fastcall **)(void *))(LsaTable + 48))(v8);
  if ( v31 )
    (*(void (**)(void))(LsaTable + 48))();
  if ( v29 )
    (*(void (**)(void))(LsaTable + 48))();
  if ( v15 )
    (*(void (__fastcall **)(const wchar_t *))(LsaTable + 48))(v15);
  return v23;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
