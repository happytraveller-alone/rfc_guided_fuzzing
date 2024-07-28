//----- (0000000180049EF4) ----------------------------------------------------
__int64 __fastcall SslMapEncodedCredential(
        void **a1,
        unsigned int *a2,
        void *a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  const CERT_CONTEXT *CertificateContext; // r15
  void *v9; // rsi
  void **v11; // r14
  int v12; // ebx
  unsigned int *v13; // r12
  BYTE *v14; // rax
  BYTE *v15; // r13
  int v16; // eax
  CCipherMill *v17; // rcx
  __int64 v18; // rdx
  void **v19; // rcx
  void *v20; // r8
  int LastError; // eax
  __int64 v22; // rdx
  __int64 v23; // r8
  int v24; // eax
  int *v25; // rdi
  __int64 v26; // r9
  unsigned int v27; // edi
  int v28; // eax
  void *v30; // [rsp+40h] [rbp-30h] BYREF
  HANDLE hObject; // [rsp+48h] [rbp-28h]
  int v32[4]; // [rsp+50h] [rbp-20h] BYREF
  const CERT_CONTEXT *v33; // [rsp+60h] [rbp-10h]
  int v34; // [rsp+68h] [rbp-8h]
  int v35; // [rsp+6Ch] [rbp-4h]
  void *v36; // [rsp+B0h] [rbp+40h] BYREF
  unsigned int v37; // [rsp+C0h] [rbp+50h] BYREF
  int v38; // [rsp+C4h] [rbp+54h]

  v38 = HIDWORD(a3);
  CertificateContext = 0i64;
  v32[3] = 0;
  v35 = 0;
  v9 = 0i64;
  v30 = 0i64;
  v37 = 0;
  v36 = 0i64;
  hObject = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 65i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
  v11 = a5;
  if ( !a5 || (v13 = a6, *a5 = 0i64, *v13 = 0, a4 < 0x28) || a2[1] != 40 )
  {
    v12 = -1073741811;
    goto LABEL_47;
  }
  v14 = (BYTE *)SPExternalAlloc(a2[4]);
  v15 = v14;
  if ( !v14 )
  {
    v12 = -1073741801;
    goto LABEL_47;
  }
  v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, BYTE *, _QWORD))(LsaTable + 80))(
          0i64,
          a2[4],
          v14,
          *((_QWORD *)a2 + 3));
  v12 = v16;
  if ( v16 < 0 )
  {
    v17 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
      goto LABEL_41;
    v18 = 66i64;
    goto LABEL_15;
  }
  CertificateContext = CertCreateCertificateContext(a2[3], v15, a2[4]);
  if ( !CertificateContext )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      LastError = GetLastError();
      WPP_SF_l(*((_QWORD *)WPP_GLOBAL_Control + 2), v22, v23, LastError);
    }
    v12 = -1073741811;
    goto LABEL_41;
  }
  v32[2] = a2[2];
  v24 = a2[8];
  v25 = a7;
  v34 = v24;
  v32[0] = 6;
  v32[1] = 32;
  v33 = CertificateContext;
  v12 = SslMapExternalCredential(v19, v32, v20, 0x20u, &v30, &v37, a7);
  if ( v12 < 0 )
  {
LABEL_40:
    v9 = v30;
    goto LABEL_41;
  }
  v26 = (unsigned int)*v25;
  if ( (int)v26 < 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 68i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v26);
    goto LABEL_40;
  }
  v9 = v30;
  hObject = (HANDLE)*((_QWORD *)v30 + 1);
  v16 = (*(__int64 (**)(void))(LsaTable + 440))();
  v12 = v16;
  if ( v16 < 0 )
  {
    v17 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
      goto LABEL_41;
    v18 = 69i64;
    goto LABEL_15;
  }
  v27 = v37;
  v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, void **))(LsaTable + 56))(0i64, v37, &v36);
  v12 = v16;
  if ( v16 >= 0 )
  {
    v28 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, void *, void *))(LsaTable + 72))(0i64, v27, v36, v9);
    v12 = v28;
    if ( v28 >= 0 )
    {
      *v11 = v36;
      *v13 = v27;
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          71i64,
          &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
          (unsigned int)v28);
      }
      (*(void (__fastcall **)(_QWORD, void *))(LsaTable + 64))(0i64, v36);
    }
    goto LABEL_41;
  }
  v17 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
  {
    v18 = 70i64;
LABEL_15:
    WPP_SF_D(*((_QWORD *)v17 + 2), v18, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, (unsigned int)v16);
  }
LABEL_41:
  SPExternalFree(v15);
  if ( hObject )
    CloseHandle(hObject);
  if ( v9 )
    VirtualFree(v9, 0i64, 0x8000u);
  if ( CertificateContext )
    CertFreeCertificateContext(CertificateContext);
LABEL_47:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_D(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      72i64,
      &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
      (unsigned int)v12);
  return (unsigned int)v12;
}
// 18004A072: variable 'v22' is possibly undefined
// 18004A072: variable 'v23' is possibly undefined
// 18004A0C1: variable 'v19' is possibly undefined
// 18004A0C1: variable 'v20' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
