//----- (0000000180019550) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::GenerateRestart(CSsl3TlsServerContext *this, struct SPBuffer *a2)
{
  char v4; // di
  int v5; // ecx
  __int64 v6; // rax
  int v7; // edx
  __int64 v8; // rax
  __int64 v9; // rax
  unsigned int v10; // edx
  char v11; // r9
  int v12; // eax
  __int16 v13; // di
  unsigned int v14; // r10d
  int v15; // r11d
  int v16; // r8d
  int v17; // ecx
  int v18; // eax
  _BYTE *v19; // r13
  unsigned int v20; // edx
  __int64 v21; // rcx
  int v22; // eax
  __int64 v23; // rax
  int v24; // edx
  int v25; // r8d
  const unsigned __int8 near *v26; // rax
  __int64 v27; // rax
  __int64 v28; // rcx
  __int64 v29; // r15
  __int64 v30; // rcx
  __int64 v31; // rax
  __int64 v32; // rax
  int SessionKeys; // eax
  unsigned int v34; // edi
  __int64 *v35; // rax
  __int64 v36; // rcx
  __int64 v37; // rax
  __int64 v38; // r9
  unsigned int v39; // r14d
  unsigned int v41; // ecx
  unsigned int v42; // r8d
  unsigned int v43; // ecx
  unsigned int v44; // r8d
  unsigned int v45; // ecx
  unsigned int v46; // r9d
  _BYTE *Memory; // rax
  int v48; // edx
  CCipherMill *v49; // rcx
  __int64 v50; // rdx
  int v51; // edx
  __int16 v52; // cx
  unsigned int v53; // [rsp+40h] [rbp-79h]
  int v54; // [rsp+44h] [rbp-75h]
  unsigned int v55; // [rsp+48h] [rbp-71h] BYREF
  void **v56; // [rsp+50h] [rbp-69h] BYREF
  CSsl3TlsServerContext *v57; // [rsp+58h] [rbp-61h]
  __int64 v58; // [rsp+60h] [rbp-59h]
  int v59; // [rsp+68h] [rbp-51h]
  CSsl3TlsServerContext *v60; // [rsp+70h] [rbp-49h]
  __time32_t Time; // [rsp+78h] [rbp-41h] BYREF
  int v62[2]; // [rsp+80h] [rbp-39h] BYREF
  char *v63; // [rsp+88h] [rbp-31h]
  char v64; // [rsp+90h] [rbp-29h] BYREF

  if ( (*((_BYTE *)this + 32) & 4) != 0 )
    v54 = *((_DWORD *)this + 11);
  else
    v54 = 0;
  v53 = 5;
  if ( *((_BYTE *)this + 233) )
    v53 = 13;
  v4 = *((_BYTE *)this + 553);
  v56 = &CTlsExtServer::`vftable';
  v5 = 0;
  v57 = this;
  v58 = 0i64;
  v59 = 0;
  v60 = this;
  if ( *((_BYTE *)this + 922) )
  {
    v5 = 6;
    BYTE1(v59) = 1;
    HIDWORD(v58) = 6;
  }
  if ( (*((_DWORD *)this + 34) & 0x400000) != 0 )
    HIDWORD(v58) = v5 + 4;
  v6 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 88i64))(this);
  if ( v6 && *(_DWORD *)v6 == 1 && *(_DWORD *)(v6 + 4) == 2 )
  {
    v7 = HIDWORD(v58) + 7 + *(unsigned __int8 *)(v6 + 8);
    HIDWORD(v58) = v7;
  }
  else
  {
    v7 = HIDWORD(v58);
  }
  if ( (*((_DWORD *)v57 + 34) & 0x8000000) != 0 )
    HIDWORD(v58) = v7 + 4;
  v8 = (*(__int64 (**)(void))(*(_QWORD *)v57 + 96i64))();
  if ( v8 )
    HIDWORD(v58) += 9 + *(unsigned __int8 *)(v8 + 2);
  v9 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)v57 + 104i64))(v57);
  if ( v9 )
  {
    v10 = HIDWORD(v58) + 7 + *(unsigned __int8 *)(v9 + 2);
    HIDWORD(v58) = v10;
  }
  else
  {
    v10 = HIDWORD(v58);
  }
  if ( v4 )
  {
    BYTE2(v59) = 1;
    v10 += *((_DWORD *)v57 + 104) + *((_DWORD *)v57 + 114) + 5;
    HIDWORD(v58) = v10;
  }
  if ( (*((_DWORD *)v57 + 34) & 0x200000) != 0 )
  {
    v10 += 4;
    HIDWORD(v58) = v10;
  }
  if ( v10 )
  {
    v10 += 2;
    HIDWORD(v58) = v10;
  }
  if ( v10 > 0xFFFF )
  {
    v49 = WPP_GLOBAL_Control;
    v34 = 1359;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return v34;
    v50 = 43i64;
    goto LABEL_110;
  }
  v11 = *((_BYTE *)this + 233);
  v12 = 4;
  if ( v11 )
    v12 = 12;
  v13 = *((_WORD *)this + 16);
  v14 = (unsigned __int16)v10 + v12 + 70;
  v55 = v14;
  if ( (v13 & 4) != 0 )
  {
    v41 = *((_DWORD *)this + 13);
    v42 = v14 + *((_DWORD *)this + 12);
    if ( v41 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v41 -= v42 % v41;
      v42 += v41;
    }
    v43 = *((_DWORD *)this + 13);
    v14 = v42 + *((_DWORD *)this + 11);
    v15 = *((_DWORD *)this + 15);
    v44 = *((_DWORD *)this + 12) + 1;
    if ( v43 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v43 -= v44 % v43;
      v44 += v43;
    }
    v16 = *((_DWORD *)this + 11) + v44;
  }
  else
  {
    v15 = *((_DWORD *)this + 15);
    v16 = 1;
  }
  if ( (*((_BYTE *)this + 64) & 0x30) != 0 )
  {
    v17 = 48;
    v18 = 40;
  }
  else
  {
    v17 = 24;
    v18 = 16;
  }
  if ( !v11 )
    v17 = v18;
  if ( (v13 & 1) != 0 )
  {
    v45 = *((_DWORD *)this + 12) + v17;
    v46 = *((_DWORD *)this + 13);
    if ( v46 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v46 -= v45 % v46;
      v45 += v46;
    }
    v17 = *((_DWORD *)this + 11) + v45;
  }
  v19 = (_BYTE *)*((_QWORD *)a2 + 1);
  v20 = v14 + v17 + v15 + v16 + 2 * v15;
  if ( v19 )
  {
    if ( *(_DWORD *)a2 < v20 )
    {
      *((_DWORD *)a2 + 1) = v20;
      return (unsigned int)-2146893023;
    }
  }
  else
  {
    *(_DWORD *)a2 = v20;
    Memory = CSslContext::GetMemory(this, v20);
    *((_QWORD *)a2 + 1) = Memory;
    v19 = Memory;
    if ( !Memory )
      return 14;
  }
  *((_DWORD *)a2 + 1) = 0;
  time32_0(&Time);
  v21 = 304i64;
  if ( (*((_DWORD *)this + 16) & 0xA2AA0) != 0 )
    v21 = 272i64;
  *(_DWORD *)((char *)this + v21) = _byteswap_ulong(Time);
  v22 = BCryptGenRandom(0i64, (PUCHAR)this + v21 + 4, 0x1Cu, 2u);
  if ( v22 < 0 )
  {
    v34 = RtlNtStatusToDosError(v22);
    if ( v34 )
      return v34;
  }
  v23 = *((_QWORD *)this + 10);
  if ( v23 )
  {
    v24 = *(_DWORD *)(v23 + 152);
    v25 = *((_DWORD *)this + 16);
    if ( (v24 & 0x1000) != 0 && (v25 & 0x400) != 0 )
    {
      v26 = CSsl3TlsContext::m_rgbTls12Downgrade;
LABEL_44:
      *((_QWORD *)this + 41) = v26;
      goto LABEL_45;
    }
    if ( *((_BYTE *)this + 233) )
    {
      if ( (v24 & 0x40000) == 0 || (v25 & 0x40000) != 0 )
        goto LABEL_45;
    }
    else if ( (v24 & 0x1400) == 0 || (v25 & 0x1400) != 0 )
    {
      goto LABEL_45;
    }
    v26 = CSsl3TlsContext::m_rgbTls11OrBelowDowngrade;
    goto LABEL_44;
  }
LABEL_45:
  RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 124) + 72i64), 1u);
  v27 = *((_QWORD *)this + 124);
  v28 = *((_QWORD *)this + 20);
  Time = 0;
  v29 = *(_QWORD *)(v27 + 16);
  if ( v28 )
  {
    SslFreeObject(v28, 0i64);
    *((_QWORD *)this + 20) = 0i64;
  }
  v30 = *((_QWORD *)this + 21);
  if ( v30 )
  {
    SslFreeObject(v30, 0i64);
    v30 = 0i64;
    *((_QWORD *)this + 21) = 0i64;
  }
  if ( (*((_BYTE *)this + 32) & 1) != 0 )
  {
    v31 = *((_QWORD *)this + 1);
    if ( v31 )
    {
      if ( *(_DWORD *)(v31 + 28) )
      {
        v62[0] = v30;
        v63 = &v64;
        v32 = *(_QWORD *)this;
        v62[1] = 4;
        SessionKeys = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, _QWORD, __time32_t *, int *, __int64, __int64))(v32 + 128))(
                        this,
                        0i64,
                        &Time,
                        v62,
                        v30,
                        v30);
        v34 = SessionKeys;
        if ( SessionKeys )
        {
          v48 = 601;
        }
        else
        {
          v35 = (__int64 *)*((_QWORD *)this + 1);
          if ( v35 )
            v36 = *v35;
          else
            v36 = 0i64;
          SessionKeys = SslGenerateSessionKeys(v36, v29, (char *)this + 160, (char *)this + 168, v62, 0);
          v34 = SessionKeys;
          if ( !SessionKeys )
            goto LABEL_56;
          v48 = 600;
        }
        CSslContext::SetErrorAndFatalAlert((__int64)this, v48, SessionKeys, 0x33u);
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 124) + 72i64));
        v49 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return v34;
        v50 = 44i64;
LABEL_110:
        WPP_SF_D(*((_QWORD *)v49 + 2), v50, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids, v34);
        return v34;
      }
    }
  }
LABEL_56:
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 124) + 72i64));
  v34 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, _QWORD))(*(_QWORD *)this + 496i64))(this, 0i64);
  if ( v34 )
    return v34;
  v37 = *(_QWORD *)this;
  *((_BYTE *)this + 340) = 0;
  v34 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, _QWORD, _QWORD, _QWORD))(v37 + 504))(
          this,
          *((_QWORD *)this + 110),
          *((unsigned int *)this + 218),
          0i64);
  if ( *((_QWORD *)this + 110) )
  {
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 110) = 0i64;
  }
  *((_DWORD *)this + 218) = 0;
  if ( v34 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 1007, v34, 0x50u);
    return v34;
  }
  v34 = CSsl3TlsServerContext::GenerateServerHello(this, &v19[v53 + v54], &v55, (struct CTlsExtServer *)&v56);
  if ( v34 )
  {
    v49 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return v34;
    v50 = 45i64;
    goto LABEL_110;
  }
  v39 = v55;
  LOBYTE(v38) = 1;
  v34 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, _BYTE *, _QWORD, __int64))(*(_QWORD *)this + 504i64))(
          this,
          &v19[v53 + v54],
          v55,
          v38);
  if ( v34 )
  {
    v51 = 1006;
  }
  else
  {
    if ( *((_BYTE *)this + 233) )
      goto LABEL_106;
    v34 = CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, 22, v39);
    if ( !v34 )
    {
      if ( !*((_BYTE *)this + 233) )
        return CSsl3TlsContext::GenerateCcsAndFinishMessage(this, a2);
LABEL_106:
      *((_DWORD *)a2 + 1) += v39 + v54 + v53;
      v52 = *((_WORD *)this + 17);
      v19[12] = v39;
      v19[11] = BYTE1(v39);
      v19[1] = HIBYTE(v52);
      v19[2] = v52;
      *v19 = 22;
      return CSsl3TlsContext::GenerateCcsAndFinishMessage(this, a2);
    }
    v51 = 954;
  }
  CSslContext::SetErrorAndFatalAlert((__int64)this, v51, v34, 0x50u);
  return v34;
}
// 1800199E7: variable 'v38' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18007C320: using guessed type void *CTlsExtServer::`vftable';
// 180082BB8: using guessed type const unsigned __int8 near *const CSsl3TlsContext::m_rgbTls11OrBelowDowngrade;
// 180082BC0: using guessed type const unsigned __int8 near *const CSsl3TlsContext::m_rgbTls12Downgrade;
// 180098428: using guessed type __int64 __fastcall SslGenerateSessionKeys(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

