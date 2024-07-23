// File count: 825
// Total lines: 157
----------------------------------------
ULONG __fastcall CheckInitialDTLSHelloCookie(
        unsigned int a1,
        const unsigned __int16 *a2,
        struct _SecBuffer *a3,
        struct SPBuffer *a4,
        struct SPBuffer *a5)
{
  int DTLSHelloVerify; // edi
  unsigned __int64 v8; // r9
  _BYTE *v9; // r8
  __int64 v10; // rdx
  __int64 v11; // rbx
  unsigned __int8 *v12; // r15
  unsigned int v13; // ebx
  unsigned int v14; // ebx
  __int64 v15; // rdx
  unsigned int v16; // ebx
  int v17; // ebx
  unsigned __int8 *v18; // r8
  ULONG v19; // ebp
  __int64 v20; // rsi
  unsigned int v21; // ebx
  unsigned int v22; // ebx
  unsigned __int8 *v23; // r12
  NTSTATUS DTlsCookieManager; // eax
  unsigned int cbBuffer; // esi
  unsigned __int8 *pvBuffer; // r14
  ULONGLONG TickCount64; // rax
  DTLSCookieManager *v29; // rdi
  NTSTATUS v30; // eax
  DTLSCookieManager *v32; // [rsp+48h] [rbp-80h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+50h] [rbp-78h] BYREF
  __int128 v34; // [rsp+60h] [rbp-68h]

  DTLSHelloVerify = 0;
  v32 = 0i64;
  *(_QWORD *)&DestinationString.Length = a2;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 57i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
  if ( !a3 || !a4 || !a5 )
    return -2146892963;
  v8 = *((unsigned int *)a4 + 1);
  if ( (unsigned int)v8 < 0xD )
    return -2146893032;
  v9 = (_BYTE *)*((_QWORD *)a4 + 1);
  if ( !v9 )
    return -2146892963;
  if ( *v9 != 22 || v9[1] != 0xFE || ((unsigned __int8)v9[2] | ((unsigned __int8)v9[1] << 8)) > 0xFEFFu )
    return -2146893048;
  v10 = (unsigned __int8)v9[12] | ((unsigned __int8)v9[11] << 8);
  if ( v8 < v10 + 13 )
    return -2146893032;
  if ( (unsigned int)v10 < 0xC
    || v9[13] != 1
    || (unsigned __int8)v9[21] + (((unsigned __int8)v9[20] + ((unsigned __int8)v9[19] << 8)) << 8) )
  {
    return -2146893048;
  }
  v11 = (unsigned __int8)v9[24] + (((unsigned __int8)v9[23] + ((unsigned __int8)v9[22] << 8)) << 8);
  if ( (unsigned int)(v8 - 13) < (unsigned __int64)(v11 + 12) )
    return -2146893032;
  v12 = v9 + 25;
  if ( (unsigned int)v11 < 2 )
    return -2146893048;
  if ( *v12 != 0xFE )
    return -2146893048;
  if ( ((unsigned __int8)v9[26] | ((unsigned __int8)v9[25] << 8)) > 0xFEFFu )
    return -2146893048;
  v13 = v11 - 2;
  if ( v13 < 0x20 )
    return -2146893048;
  v14 = v13 - 32;
  if ( !v14 )
    return -2146893048;
  v15 = (unsigned __int8)v9[59];
  if ( (unsigned int)v15 > 0x20 )
    return -2146893048;
  v16 = v14 - 1;
  if ( v16 < (unsigned int)v15 )
    return -2146893048;
  v17 = v16 - v15;
  v18 = &v9[v15 + 60];
  v19 = v15 + 35;
  if ( !v17 )
    return -2146893048;
  v20 = *v18;
  if ( (v20 & 0xFFFFFFDF) != 0 )
    return -2146893048;
  v21 = v17 - 1;
  if ( v21 < (unsigned int)v20 )
    return -2146893048;
  v22 = v21 - v20;
  v23 = &v18[v20];
  DTlsCookieManager = DTLSCookieManager::getDTlsCookieManager(&v32);
  if ( DTlsCookieManager < 0 )
    return RtlNtStatusToDosError(DTlsCookieManager);
  if ( (_DWORD)v20 )
  {
    if ( !(unsigned int)DTLSCookieManager::ValidateCookie(
                          v32,
                          v12,
                          v19,
                          v23 + 1,
                          v22,
                          (unsigned __int8 *const)a3->pvBuffer,
                          a3->cbBuffer) )
    {
      DTLSHelloVerify = -2146893024;
      if ( (g_dwEventLogging & 2) != 0 )
      {
        RtlInitUnicodeString(&DestinationString, *(PCWSTR *)&DestinationString.Length);
        SchEventWrite(&SSLEVENT_DTLS_COOKIE_VERIFY_FAILED, L"du", a1, &DestinationString);
      }
    }
  }
  else
  {
    DestinationString = 0i64;
    v34 = 0i64;
    if ( g_fEnableHelloVerifyRequest )
    {
      cbBuffer = a3->cbBuffer;
      pvBuffer = (unsigned __int8 *)a3->pvBuffer;
      TickCount64 = GetTickCount64();
      v29 = v32;
      if ( *((_QWORD *)v32 + 6) + *((_QWORD *)v32 + 7) < TickCount64 )
        DTLSCookieManager::ResetSecret((PUCHAR *)v32);
      v30 = DTLSCookieManager::ComputeCookie(
              v29,
              v12,
              v19,
              v23 + 1,
              v22,
              pvBuffer,
              cbBuffer,
              (unsigned __int8 *)&DestinationString);
      if ( v30 >= 0 )
      {
        DTLSHelloVerify = GenerateDTLSHelloVerify(a5, (unsigned __int8 *)&DestinationString);
        if ( !DTLSHelloVerify )
          return 590610;
      }
      else
      {
        return SspNtStatusToSecStatus(v30);
      }
    }
    else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 58i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
    }
  }
  return DTLSHelloVerify;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800919A4: using guessed type int g_fEnableHelloVerifyRequest;
