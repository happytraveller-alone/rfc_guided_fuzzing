// File count: 200
// Total lines: 90
-----------------------------------------
__int64 __fastcall SpUniAcquireCredentialsHandle(
        struct _UNICODE_STRING *a1,
        __int64 a2,
        struct _LUID *a3,
        struct _SCHANNEL_CRED *a4,
        int a5,
        int a6,
        unsigned __int64 *a7,
        union _LARGE_INTEGER *a8)
{
  unsigned int v10; // ebx
  CCipherMill *v12; // rcx
  char v13; // al
  unsigned int v14; // edx
  __int64 v15; // rdx
  unsigned int v16; // ebx
  CCipherMill *v17; // rcx
  unsigned __int64 *v19; // [rsp+20h] [rbp-68h]
  char v20[16]; // [rsp+30h] [rbp-58h] BYREF

  v10 = a2;
  v12 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 62i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
      v12 = WPP_GLOBAL_Control;
    }
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v12 + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)v12 + 2), 63i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
        v12 = WPP_GLOBAL_Control;
      }
      if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
      {
        WPP_SF_D(*((_QWORD *)v12 + 2), 64i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, v10);
        v12 = WPP_GLOBAL_Control;
      }
    }
  }
  v13 = Microsoft_Windows_Schannel_EventsEnableBits;
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
  {
    McGenEventWrite_EtwEventWriteTransfer((__int64)v12, (__int64)&AchStart, (__int64)a3, 1, (__int64)v20);
    v12 = WPP_GLOBAL_Control;
    v13 = Microsoft_Windows_Schannel_EventsEnableBits;
  }
  if ( (v10 & 1) != 0 )
  {
    v14 = 0x40000000;
LABEL_15:
    v16 = SpCommonAcquireCredentialsHandle(a1, v14, a3, a4, a7, a8);
    v17 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 66i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McTemplateU0d_EtwEventWriteTransfer((__int64)v17, v15, v16);
    return v16;
  }
  if ( (v10 & 2) != 0 )
  {
    v14 = 0x80000000;
    goto LABEL_15;
  }
  v16 = -2146893042;
  if ( (v13 & 1) != 0 )
  {
    McTemplateU0d_EtwEventWriteTransfer((__int64)v12, a2, 2148074254i64);
    v12 = WPP_GLOBAL_Control;
  }
  if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 5) != 0 )
  {
    LODWORD(v19) = -2146893042;
    WPP_SF_DD(*((_QWORD *)v12 + 2), 0x41u, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, -2146893042, v19);
  }
  return v16;
}
// 180039FDF: variable 'a3' is possibly undefined
// 18003A014: variable 'v17' is possibly undefined
// 18003A014: variable 'v15' is possibly undefined
// 18003A02B: variable 'a2' is possibly undefined
// 18003A06C: variable 'v19' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180011040: using guessed type char var_58[16];
