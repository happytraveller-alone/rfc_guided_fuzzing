//----- (0000000180071C4C) ----------------------------------------------------
__int64 __fastcall CSslContext::I_RsaGenerateServerMasterKey(CSslContext *this, unsigned __int8 *a2, unsigned int a3)
{
  __int64 v6; // rax
  __int64 v7; // r15
  unsigned int RsaKeyModulus; // ebx
  __int64 v9; // rax
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  int v12; // ecx
  unsigned __int8 v13; // r9
  int v14; // edx
  __int64 v15; // rax
  __int64 *v16; // rax
  int v17; // edx
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v21; // [rsp+50h] [rbp-B0h] BYREF
  int v22; // [rsp+58h] [rbp-A8h] BYREF
  unsigned int v23; // [rsp+5Ch] [rbp-A4h] BYREF
  int v24; // [rsp+60h] [rbp-A0h] BYREF
  int v25; // [rsp+64h] [rbp-9Ch] BYREF
  unsigned __int64 v26; // [rsp+68h] [rbp-98h] BYREF
  int v27[2]; // [rsp+70h] [rbp-90h] BYREF
  char *v28; // [rsp+78h] [rbp-88h]
  char v29; // [rsp+80h] [rbp-80h] BYREF
  char v30[64]; // [rsp+D0h] [rbp-30h] BYREF

  v26 = 0i64;
  v22 = 0;
  memset_0(v30, 0, sizeof(v30));
  v6 = *(_QWORD *)this;
  v25 = 0;
  v24 = 64;
  (*(void (__fastcall **)(CSslContext *, __int64 *))(v6 + 232))(this, &v21);
  v7 = *((_QWORD *)this + 14);
  if ( !v7 )
  {
    RsaKeyModulus = CSslContext::ImpersonateNonLsNs(this, &v22);
    if ( RsaKeyModulus )
      goto LABEL_37;
    v9 = *((_QWORD *)this + 3);
    if ( !v9 )
    {
      RsaKeyModulus = -2146893043;
      goto LABEL_37;
    }
    v7 = *(_QWORD *)(v9 + 8);
  }
  RsaKeyModulus = GetRsaKeyModulus(v7, &v23);
  if ( !RsaKeyModulus )
  {
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v21 + 72), 1u);
    v10 = 8 * v23;
    *(_DWORD *)(v21 + 8) = 8 * v23;
    v11 = (v10 + 7) >> 3;
    if ( a3 < 2 )
    {
      RtlReleaseResource((PRTL_RESOURCE)(v21 + 72));
      RsaKeyModulus = -2146893048;
      goto LABEL_37;
    }
    if ( (*((_DWORD *)this + 16) & 0x51550) != 0 )
    {
      v12 = a2[1] | (*a2 << 8);
      if ( v12 == v11 && v12 + 2 == a3 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_ef2bc8f963c43ddcdfece7ee9e95f200_Traceguids);
        a2 += 2;
        a3 -= 2;
      }
    }
    if ( a3 < v11 )
    {
      RtlReleaseResource((PRTL_RESOURCE)(v21 + 72));
      v13 = 50;
      v14 = 700;
      RsaKeyModulus = -2146893048;
LABEL_18:
      CSslContext::SetErrorAndFatalAlert((__int64)this, v14, RsaKeyModulus, v13);
      goto LABEL_37;
    }
    v27[0] = 0;
    v28 = &v29;
    v15 = *(_QWORD *)this;
    v27[1] = 5;
    RsaKeyModulus = (*(__int64 (__fastcall **)(CSslContext *, __int64, int *, int *, char *, int *))(v15 + 128))(
                      this,
                      1i64,
                      &v25,
                      v27,
                      v30,
                      &v24);
    if ( RsaKeyModulus )
    {
      RtlReleaseResource((PRTL_RESOURCE)(v21 + 72));
      v13 = 51;
      v14 = 707;
      goto LABEL_18;
    }
    if ( (*((_BYTE *)this + 32) & 1) != 0 && (v16 = (__int64 *)*((_QWORD *)this + 1)) != 0i64 )
    {
      v17 = *((_DWORD *)v16 + 7);
    }
    else
    {
      v16 = (__int64 *)*((_QWORD *)this + 1);
      v17 = 0;
    }
    if ( v16 )
      v18 = *v16;
    else
      v18 = 0i64;
    RsaKeyModulus = SslImportMasterKey(v18, v7, &v26, *((unsigned __int16 *)this + 17), v17, v27, a2, a3, 2);
    if ( RsaKeyModulus )
    {
      RtlReleaseResource((PRTL_RESOURCE)(v21 + 72));
      v13 = 51;
      v14 = 701;
      goto LABEL_18;
    }
    *(_QWORD *)(v21 + 16) = v26;
    v19 = *((_QWORD *)this + 14);
    if ( v19 )
    {
      SslFreeObject(v19, 0i64);
      *((_QWORD *)this + 14) = 0i64;
    }
    RsaKeyModulus = CSslContext::MakeSessionKeys(this, v26);
    RtlReleaseResource((PRTL_RESOURCE)(v21 + 72));
    if ( RsaKeyModulus )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          15i64,
          &WPP_ef2bc8f963c43ddcdfece7ee9e95f200_Traceguids,
          RsaKeyModulus);
    }
    else
    {
      LsaIModifyPerformanceCounter(8i64);
    }
  }
LABEL_37:
  if ( v22 )
    RevertToSelf();
  return RsaKeyModulus;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 180098410: using guessed type __int64 __fastcall SslImportMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

