//----- (000000018004B59C) ----------------------------------------------------
__int64 __fastcall SslTryUpn(
        const struct _CERT_CONTEXT *a1,
        unsigned __int8 **a2,
        unsigned int *a3,
        unsigned __int16 **a4)
{
  const WCHAR *p_DestinationString; // rdi
  __int64 result; // rax
  int v7; // r13d
  wchar_t *v8; // rsi
  int v9; // ebx
  __int64 v10; // r15
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rcx
  __int64 v13; // rax
  void *v14; // rsp
  WCHAR *v15; // rax
  int v16; // ebx
  __int64 (__fastcall *v17)(struct _UNICODE_STRING *, __int64, _QWORD, unsigned __int8 **); // rax
  int v18; // eax
  __int64 v19; // rdx
  void (__fastcall *v20)(__int64, __int64, struct _UNICODE_STRING *, struct _UNICODE_STRING *); // rax
  __int64 (__fastcall *v21)(struct _UNICODE_STRING *, __int64, _QWORD, unsigned __int8 **); // rax
  int v22; // eax
  wchar_t *v23; // rax
  wchar_t *v24; // r13
  int v25; // ebx
  __int64 (__fastcall *v26)(struct _UNICODE_STRING *, _QWORD, _QWORD, unsigned __int8 **); // rax
  wchar_t *v27; // rax
  wchar_t *v28; // r13
  int v29; // ebx
  __int64 (__fastcall *v30)(struct _UNICODE_STRING *, _QWORD, _QWORD, unsigned __int8 **); // rax
  __int64 v31; // rdx
  unsigned int v32; // ecx
  PWSTR Buffer; // rbx
  __int64 v34; // [rsp+0h] [rbp-40h] BYREF
  unsigned int v35[2]; // [rsp+20h] [rbp-20h]
  struct _UNICODE_STRING *v36; // [rsp+28h] [rbp-18h]
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp+0h] BYREF
  wchar_t v38; // [rsp+50h] [rbp+10h]
  int v39; // [rsp+54h] [rbp+14h] BYREF
  unsigned int v40; // [rsp+58h] [rbp+18h] BYREF
  unsigned __int8 **v41; // [rsp+60h] [rbp+20h]
  unsigned int v42[4]; // [rsp+68h] [rbp+28h] BYREF
  struct _UNICODE_STRING lpString; // [rsp+78h] [rbp+38h] BYREF
  unsigned int *v44; // [rsp+88h] [rbp+48h]
  struct _UNICODE_STRING v45; // [rsp+90h] [rbp+50h] BYREF
  unsigned __int16 **v46; // [rsp+A0h] [rbp+60h]
  HLOCAL hMem[2]; // [rsp+A8h] [rbp+68h] BYREF

  v41 = a2;
  *(_DWORD *)&DestinationString.Length = 0;
  v44 = a3;
  DestinationString.Buffer = 0i64;
  *(_QWORD *)&lpString.Length = 0i64;
  *a4 = 0i64;
  *(_OWORD *)hMem = 0i64;
  p_DestinationString = 0i64;
  v46 = a4;
  v45 = 0i64;
  *(_OWORD *)v42 = 0i64;
  result = SslGetNameFromCertificate(a1, (unsigned __int16 **)&lpString, &v39);
  if ( (int)result < 0 )
    return result;
  v7 = v39;
  v8 = *(wchar_t **)&lpString.Length;
  if ( !v39 )
  {
    RtlInitUnicodeString(&DestinationString, *(PCWSTR *)&lpString.Length);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      WPP_SF_S(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xEu,
        (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
        DestinationString.Buffer);
    v21 = *(__int64 (__fastcall **)(struct _UNICODE_STRING *, __int64, _QWORD, unsigned __int8 **))(LsaTable + 296);
    v36 = (struct _UNICODE_STRING *)v42;
    *(_QWORD *)v35 = a3;
    v22 = v21(&DestinationString, 2i64, 0i64, v41);
    v19 = 0i64;
    v16 = v22;
    if ( LOWORD(v42[0]) )
    {
      LOBYTE(v19) = v22 >= 0;
      v20 = *(void (__fastcall **)(__int64, __int64, struct _UNICODE_STRING *, struct _UNICODE_STRING *))(LsaTable + 312);
      goto LABEL_26;
    }
LABEL_27:
    if ( v16 != -1073741275 )
      goto LABEL_60;
    if ( v7 )
    {
      v23 = wcschr(v8, 0x2Eu);
      v24 = v23;
      if ( !v23 )
        goto LABEL_42;
      RtlInitUnicodeString(&lpString, v23 + 1);
      RtlAcquireResourceShared(&SslGlobalLock, 1u);
      v25 = RtlEqualUnicodeString(&lpString, &SslGlobalDnsDomainName, 1u);
      RtlReleaseResource(&SslGlobalLock);
      if ( !v25 )
        goto LABEL_42;
      v38 = v24[1];
      *(_DWORD *)v24 = 36;
      RtlInitUnicodeString(&DestinationString, v8);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xFu,
          (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
          DestinationString.Buffer);
      }
      v26 = *(__int64 (__fastcall **)(struct _UNICODE_STRING *, _QWORD, _QWORD, unsigned __int8 **))(LsaTable + 296);
      v36 = 0i64;
      *(_QWORD *)v35 = v44;
      v16 = v26(&DestinationString, 0i64, 0i64, v41);
      *v24 = 46;
      v24[1] = v38;
    }
    else
    {
      v27 = wcschr(v8, 0x40u);
      v28 = v27;
      if ( !v27 )
        goto LABEL_47;
      RtlInitUnicodeString(&lpString, v27 + 1);
      RtlAcquireResourceShared(&SslGlobalLock, 1u);
      v29 = RtlEqualUnicodeString(&lpString, &SslGlobalDnsDomainName, 1u);
      RtlReleaseResource(&SslGlobalLock);
      if ( !v29 )
        goto LABEL_47;
      *v28 = 0;
      RtlInitUnicodeString(&DestinationString, v8);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x10u,
          (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
          DestinationString.Buffer);
      }
      v30 = *(__int64 (__fastcall **)(struct _UNICODE_STRING *, _QWORD, _QWORD, unsigned __int8 **))(LsaTable + 296);
      v36 = 0i64;
      *(_QWORD *)v35 = v44;
      v16 = v30(&DestinationString, 0i64, 0i64, v41);
      *v28 = 64;
    }
    if ( v16 != -1073741275 )
      goto LABEL_60;
LABEL_42:
    if ( v39 )
    {
      RtlInitUnicodeString(&DestinationString, p_DestinationString);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x11u,
          (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
          DestinationString.Buffer);
      }
      v32 = 10;
LABEL_51:
      v16 = SslCrackSingleName(v32, v31, &DestinationString, 0i64, v35[0], (struct _UNICODE_STRING *)hMem, &v45, &v40);
      if ( v16 >= 0 )
      {
        if ( v40 )
        {
          Buffer = v45.Buffer;
        }
        else
        {
          Buffer = 0i64;
          *v46 = v45.Buffer;
        }
        if ( hMem[1] )
          LocalFree(hMem[1]);
        if ( Buffer )
          LocalFree(Buffer);
        v16 = -1073741275;
      }
      goto LABEL_60;
    }
LABEL_47:
    RtlInitUnicodeString(&DestinationString, v8);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      WPP_SF_S(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x12u,
        (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
        DestinationString.Buffer);
    v32 = 8;
    goto LABEL_51;
  }
  v9 = lstrlenW(*(LPCWSTR *)&lpString.Length);
  v10 = (unsigned int)(lstrlenW(L"host/") + v9 + 1);
  v11 = 2 * v10;
  if ( 2 * v10 )
  {
    if ( v11 <= g_ulMaxStackAllocSize )
    {
      v12 = v11 + 8 + g_ulAdditionalProbeSize;
      if ( v12 >= v11 )
      {
        if ( (unsigned int)VerifyStackAvailable(v12) )
        {
          v13 = v11 + 23;
          if ( v11 + 23 <= v11 + 8 )
            v13 = 0xFFFFFFFFFFFFFF0i64;
          v14 = alloca(v13 & 0xFFFFFFFFFFFFFFF0ui64);
          p_DestinationString = (const WCHAR *)&DestinationString;
          if ( &v34 != (__int64 *)-64i64 )
          {
            *(_DWORD *)&DestinationString.Length = 1801679955;
            p_DestinationString = (const WCHAR *)&DestinationString.Buffer;
            if ( &DestinationString != (struct _UNICODE_STRING *)-8i64 )
            {
LABEL_16:
              _o_wcscpy_s(p_DestinationString, v10, L"host/");
              _o_wcscat_s(p_DestinationString, v10, v8);
              RtlInitUnicodeString(&DestinationString, p_DestinationString);
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
              {
                WPP_SF_S(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  0xDu,
                  (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                  DestinationString.Buffer);
              }
              v17 = *(__int64 (__fastcall **)(struct _UNICODE_STRING *, __int64, _QWORD, unsigned __int8 **))(LsaTable + 296);
              v36 = (struct _UNICODE_STRING *)v42;
              *(_QWORD *)v35 = v44;
              v18 = v17(&DestinationString, 4i64, 0i64, v41);
              v19 = 0i64;
              v16 = v18;
              if ( LOWORD(v42[0]) )
              {
                LOBYTE(v19) = v18 >= 0;
                v20 = *(void (__fastcall **)(__int64, __int64, struct _UNICODE_STRING *, struct _UNICODE_STRING *))(LsaTable + 312);
LABEL_26:
                LODWORD(v36) = v16;
                *(_QWORD *)v35 = v42;
                v20(678i64, v19, &SslPackageName, &DestinationString);
                (*(void (__fastcall **)(_QWORD))(LsaTable + 48))(*(_QWORD *)&v42[2]);
                goto LABEL_27;
              }
              goto LABEL_27;
            }
          }
        }
      }
    }
  }
  if ( v11 + 8 < v11 )
  {
LABEL_14:
    if ( !p_DestinationString )
      goto LABEL_15;
    goto LABEL_16;
  }
  v15 = (WCHAR *)((__int64 (*)(void))g_pfnAllocate)();
  p_DestinationString = v15;
  if ( v15 )
  {
    *(_DWORD *)v15 = 1885431112;
    p_DestinationString = v15 + 4;
    goto LABEL_14;
  }
LABEL_15:
  v16 = -1073741801;
LABEL_60:
  if ( v8 )
    LocalFree(v8);
  if ( p_DestinationString )
  {
    if ( *((_DWORD *)p_DestinationString - 2) == 1885431112 )
      ((void (*)(void))g_pfnFree)();
  }
  return (unsigned int)v16;
}
// 18004BBCE: variable 'v31' is possibly undefined
// 180080C68: using guessed type __int64 __fastcall _o_wcscat_s(_QWORD, _QWORD, _QWORD);
// 180080C70: using guessed type __int64 __fastcall _o_wcscpy_s(_QWORD, _QWORD, _QWORD);
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180092620: using guessed type __int64 LsaTable;
