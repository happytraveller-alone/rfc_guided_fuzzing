//----- (0000000180071978) ----------------------------------------------------
__int64 __fastcall CSslContext::I_RsaGenerateEcdsaSignServerMasterKey(
        CSslContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  __int64 v6; // rax
  __int64 v7; // r15
  unsigned int SessionKeys; // ebx
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // eax
  int v12; // edx
  __int64 *v13; // rax
  int v14; // edx
  __int64 v15; // rcx
  __int64 v16; // rcx
  int v18; // [rsp+50h] [rbp-B0h] BYREF
  int v19; // [rsp+54h] [rbp-ACh] BYREF
  int v20; // [rsp+58h] [rbp-A8h] BYREF
  unsigned __int64 v21; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v22; // [rsp+68h] [rbp-98h] BYREF
  int v23[2]; // [rsp+70h] [rbp-90h] BYREF
  char *v24; // [rsp+78h] [rbp-88h]
  char v25; // [rsp+80h] [rbp-80h] BYREF
  char v26[64]; // [rsp+D0h] [rbp-30h] BYREF

  v21 = 0i64;
  v18 = 0;
  memset_0(v26, 0, sizeof(v26));
  v6 = *(_QWORD *)this;
  v20 = 0;
  v19 = 64;
  (*(void (__fastcall **)(CSslContext *, __int64 *))(v6 + 232))(this, &v22);
  v7 = *((_QWORD *)this + 14);
  if ( !v7 )
  {
    SessionKeys = CSslContext::ImpersonateNonLsNs(this, &v18);
    if ( SessionKeys )
      goto LABEL_33;
    v9 = *((_QWORD *)this + 3);
    if ( !v9 )
    {
      SessionKeys = -2146893043;
      goto LABEL_33;
    }
    v7 = *(_QWORD *)(v9 + 8);
  }
  if ( a3 < 2 )
  {
    SessionKeys = -2146893048;
    goto LABEL_33;
  }
  if ( (*((_DWORD *)this + 16) & 0x51550) != 0 && ((*a2 << 8) | a2[1]) + 2 == a3 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_ef2bc8f963c43ddcdfece7ee9e95f200_Traceguids);
    a2 += 2;
    a3 -= 2;
  }
  v23[0] = 0;
  v24 = &v25;
  v10 = *(_QWORD *)this;
  v23[1] = 5;
  v11 = (*(__int64 (__fastcall **)(CSslContext *, __int64, int *, int *, char *, int *))(v10 + 128))(
          this,
          1i64,
          &v20,
          v23,
          v26,
          &v19);
  SessionKeys = v11;
  if ( v11 )
  {
    v12 = 707;
LABEL_16:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v12, v11, 0x33u);
    goto LABEL_33;
  }
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
  v11 = SslImportMasterKey(v15, v7, &v21, *((unsigned __int16 *)this + 17), v14, v23, a2, a3, 2);
  SessionKeys = v11;
  if ( v11 )
  {
    v12 = 701;
    goto LABEL_16;
  }
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(v22 + 72), 1u);
  *(_QWORD *)(v22 + 16) = v21;
  v16 = *((_QWORD *)this + 14);
  if ( v16 )
  {
    SslFreeObject(v16, 0i64);
    *((_QWORD *)this + 14) = 0i64;
  }
  SessionKeys = CSslContext::MakeSessionKeys(this, v21);
  RtlReleaseResource((PRTL_RESOURCE)(v22 + 72));
  if ( SessionKeys )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        13i64,
        &WPP_ef2bc8f963c43ddcdfece7ee9e95f200_Traceguids,
        SessionKeys);
  }
  else
  {
    LsaIModifyPerformanceCounter(8i64);
  }
LABEL_33:
  if ( v18 )
    RevertToSelf();
  return SessionKeys;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 180098410: using guessed type __int64 __fastcall SslImportMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
