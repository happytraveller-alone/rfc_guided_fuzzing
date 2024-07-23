// File count: 1340
// Total lines: 83
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseFinished(
        __int64 a1,
        const void *a2,
        int a3)
{
  __int64 v5; // rax
  struct hsel *HashInfo; // rax
  int v7; // r8d
  __int64 v8; // r11
  size_t v9; // rdi
  unsigned __int8 v10; // r9
  int v11; // edx
  __int64 v12; // rcx
  unsigned int v13; // ebx
  unsigned __int64 FinishedMessageKey; // rbx
  __int64 v16; // r11
  __int64 v17; // rax
  _QWORD *v18; // rcx
  int v19; // eax
  CCipherMill *v20; // rbx
  char Buf1[64]; // [rsp+30h] [rbp-68h] BYREF

  if ( !a2 || !a3 )
    return 87i64;
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8i64);
  if ( !v5 )
    return 1359i64;
  HashInfo = GetHashInfo(*(_DWORD *)(v5 + 44));
  if ( !HashInfo )
    return 1359i64;
  v9 = *((unsigned int *)HashInfo + 7);
  if ( (unsigned int)v9 > 0x40 )
    return 1359i64;
  if ( v7 != (_DWORD)v9 )
  {
    v10 = 50;
    v11 = 903;
    v12 = v8;
LABEL_8:
    v13 = -2146893048;
    CSslContext::SetErrorAndFatalAlert(v12, v11, -2146893048, v10);
    return v13;
  }
  FinishedMessageKey = CTls13Context::GetFinishedMessageKey(
                         (CTls13Context *)(v8 + 1000),
                         (*(_DWORD *)(v8 + 64) & 0x800A2AAA) == 0);
  if ( !FinishedMessageKey )
    return 1359i64;
  v17 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v16 + 512i64))(v16, 0i64);
  v18 = *(_QWORD **)(*(_QWORD *)(a1 + 8) + 8i64);
  if ( v18 )
    v18 = (_QWORD *)*v18;
  v19 = SslComputeFinishedHash(v18, FinishedMessageKey, v17, Buf1, v9, 0);
  v13 = v19;
  if ( v19 )
  {
    CSslContext::SetError(*(_QWORD *)(a1 + 8), 902, v19);
    return v13;
  }
  v20 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
    v20 = WPP_GLOBAL_Control;
  }
  if ( memcmp_0(Buf1, a2, v9) )
  {
    if ( v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v20 + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)v20 + 2), 20i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
    v12 = *(_QWORD *)(a1 + 8);
    v10 = 51;
    v11 = 900;
    goto LABEL_8;
  }
  return 0i64;
}
// 1800698E9: variable 'v7' is possibly undefined
// 1800698F3: variable 'v8' is possibly undefined
// 18006992D: variable 'v16' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
// 180098538: using guessed type __int64 __fastcall SslComputeFinishedHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
