//----- (0000000180010D8C) ----------------------------------------------------
__int64 __fastcall GetProcessImageName(unsigned __int16 *a1, struct _SECPKG_CALL_INFO *a2)
{
  unsigned int v2; // ebx
  DWORD ProcessId; // r15d
  HANDLE v5; // r13
  int v6; // eax
  __int64 v7; // rsi
  int v9; // eax
  HLOCAL v10; // r15
  int v11; // eax
  void *v12; // rcx
  const wchar_t *v13; // r8
  DWORD LastError; // eax
  DWORD v15; // eax
  CCipherMill *v16; // rcx
  __int64 v17; // rdx
  CCipherMill *v18; // rcx
  DWORD dwSize; // [rsp+50h] [rbp-B0h] BYREF
  _QWORD v20[3]; // [rsp+58h] [rbp-A8h] BYREF
  DWORD v21; // [rsp+70h] [rbp-90h] BYREF
  HLOCAL hMem; // [rsp+78h] [rbp-88h]
  __int128 v23; // [rsp+80h] [rbp-80h]
  wchar_t String1[256]; // [rsp+A0h] [rbp-60h] BYREF
  wchar_t v25[264]; // [rsp+2A0h] [rbp+1A0h] BYREF
  WCHAR ExeName[264]; // [rsp+4B0h] [rbp+3B0h] BYREF

  v2 = 0;
  if ( !a2 || !a1 )
    return 87i64;
  ProcessId = a2->ProcessId;
  if ( (a2->Attributes & 0x2000) != 0 )
  {
    v13 = L"SYSTEM";
  }
  else
  {
    if ( ProcessId )
    {
      v5 = OpenProcess(0x1000u, 0, ProcessId);
      if ( !v5 )
      {
        LastError = GetLastError();
        v2 = LastError;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            10i64,
            &WPP_0dcdb9265ec2314c20be99baf3bba51a_Traceguids,
            LastError);
        return v2;
      }
      memset_0(ExeName, 0, 0x208ui64);
      dwSize = 260;
      if ( !QueryFullProcessImageNameW(v5, 0, ExeName, &dwSize) )
      {
        v15 = GetLastError();
        v2 = v15;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_0dcdb9265ec2314c20be99baf3bba51a_Traceguids, v15);
        goto LABEL_14;
      }
      memset_0(String1, 0, sizeof(String1));
      v6 = wsplitpath_s(ExeName, 0i64, 0i64, 0i64, 0i64, String1, 0x100ui64, 0i64, 0i64);
      if ( v6 )
      {
        v16 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) == 0 )
          goto LABEL_57;
        v17 = 12i64;
        goto LABEL_56;
      }
      memset_0(v25, 0, 0x208ui64);
      v7 = -1i64;
      if ( wcsnicmp(String1, L"svchost", 7ui64) )
        goto LABEL_9;
      LODWORD(v20[0]) = ProcessId;
      memset((char *)v20 + 4, 0, 20);
      HIDWORD(v20[0]) = NtCurrentTeb()->SubProcessTag;
      if ( (unsigned int)I_QueryTagInformation(0i64, 1i64, v20) )
      {
        v21 = ProcessId;
        hMem = 0i64;
        v9 = I_QueryTagInformation(0i64, 3i64, &v21);
        if ( v9 )
        {
          if ( v9 < 0
            && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          {
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              13i64,
              &WPP_0dcdb9265ec2314c20be99baf3bba51a_Traceguids,
              (unsigned int)v9);
          }
          goto LABEL_9;
        }
        v10 = hMem;
        if ( !hMem )
        {
          do
LABEL_9:
            ++v7;
          while ( v25[v7] );
          if ( v7 )
            v6 = StringCchPrintfW(a1, 260i64, L"%ls[%ls]", String1, v25);
          else
            v6 = StringCchCopyW((char *)a1, 260i64, (char *)String1);
          if ( v6 == -2147024774 )
          {
            v18 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
              {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_0dcdb9265ec2314c20be99baf3bba51a_Traceguids);
                v18 = WPP_GLOBAL_Control;
              }
              if ( v18 != (CCipherMill *)&WPP_GLOBAL_Control )
              {
                if ( (*((_BYTE *)v18 + 28) & 2) != 0 )
                {
                  WPP_SF_S(
                    *((_QWORD *)v18 + 2),
                    0xFu,
                    (__int64)&WPP_0dcdb9265ec2314c20be99baf3bba51a_Traceguids,
                    String1);
                  v18 = WPP_GLOBAL_Control;
                }
                if ( v18 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v18 + 28) & 2) != 0 )
                  WPP_SF_S(*((_QWORD *)v18 + 2), 0x10u, (__int64)&WPP_0dcdb9265ec2314c20be99baf3bba51a_Traceguids, v25);
              }
            }
            goto LABEL_14;
          }
          if ( v6 >= 0 )
          {
LABEL_14:
            CloseHandle(v5);
            return v2;
          }
          v16 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
LABEL_57:
            v2 = 1359;
            goto LABEL_14;
          }
          v17 = 17i64;
LABEL_56:
          WPP_SF_D(*((_QWORD *)v16 + 2), v17, &WPP_0dcdb9265ec2314c20be99baf3bba51a_Traceguids, (unsigned int)v6);
          goto LABEL_57;
        }
        if ( *(_DWORD *)hMem == 1 )
        {
          v11 = _mm_cvtsi128_si32(*(__m128i *)*((_QWORD *)hMem + 1));
          v23 = *(_OWORD *)*((_QWORD *)hMem + 1);
          if ( v11 == 1 )
          {
            if ( *((_QWORD *)&v23 + 1) )
              o_wcsncpy_s_0(v25, 260i64, *((_QWORD *)&v23 + 1), -1i64);
          }
        }
        v12 = v10;
      }
      else
      {
        if ( !v20[2] )
          goto LABEL_9;
        o_wcsncpy_s_0(v25, 260i64, v20[2], -1i64);
        v12 = (void *)v20[2];
      }
      LocalFree(v12);
      goto LABEL_9;
    }
    v13 = L"<UNKNOWN>";
  }
  o_wcsncpy_s_0(a1, 260i64, v13, -1i64);
  return 0i64;
}
// 180028D84: using guessed type __int64 __fastcall o_wcsncpy_s_0(_QWORD, _QWORD, _QWORD, _QWORD);
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080DC0: using guessed type __int64 __fastcall I_QueryTagInformation(_QWORD, _QWORD, _QWORD);
// 180085478: using guessed type wchar_t aSystem[7];
// 180085488: using guessed type wchar_t aUnknown_0[10];
// 180010D8C: using guessed type wchar_t var_460[264];

