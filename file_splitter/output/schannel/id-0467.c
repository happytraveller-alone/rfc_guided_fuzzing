// File count: 467
// Total lines: 386
----------------------------------------
__int64 __fastcall CTls13ServerContext::ProcessHandshake(
        CTls13ServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        int *a4)
{
  __int64 v4; // rsi
  unsigned int updated; // ebp
  __int64 v10; // r15
  unsigned __int8 *v11; // r10
  int v12; // ecx
  unsigned int v13; // r8d
  int v14; // r9d
  unsigned int v15; // edx
  bool v16; // r15
  __int64 v17; // rax
  __int64 v18; // r9
  unsigned int v20; // edx
  unsigned int v21; // edx
  CCipherMill *v22; // rcx
  __int64 v23; // rdx
  CCipherMill *v24; // rcx
  __int64 v25; // rdx
  unsigned int v26; // edx
  unsigned int v27; // edx
  __int64 *v28; // rax
  __int64 v29; // rcx
  int v30; // eax
  __int64 v31; // rdx
  __int64 v32; // rcx
  __int64 v33; // rax
  __int64 v34; // rcx
  __int64 v35; // rax
  __int64 *v36; // rax
  __int64 v37; // rdx
  int v38; // eax
  unsigned int v39; // edi
  __int64 *v40; // rax
  __int64 v41; // rdx
  int v42; // eax
  __int64 *v43; // rax
  __int64 v44; // rax
  int v45; // eax
  __int64 v46; // [rsp+80h] [rbp+8h] BYREF
  char v47; // [rsp+90h] [rbp+18h] BYREF
  unsigned __int8 *v48; // [rsp+98h] [rbp+20h]

  v4 = 0i64;
  *a4 = 0;
  *((_BYTE *)this + 1282) = 0;
  v47 = 0;
  if ( !a3 || !a2 )
    return 87i64;
  updated = 0;
  v10 = *((_QWORD *)this + 10);
  if ( !v10 )
    return 1359i64;
  v11 = a2 + 4;
  v12 = *((_DWORD *)this + 17);
  v13 = a3 - 4;
  v14 = *a2 << 8;
  v15 = v14 | (unsigned __int8)v12;
  v48 = v11;
  LODWORD(v46) = v13;
  if ( v15 == 256 )
    goto LABEL_5;
  if ( v15 > 0x143C )
  {
    if ( v15 > 0x144F )
    {
      if ( v15 == 6148 || v15 > 0x184D && v15 <= 0x184F )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 56i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          v11 = v48;
          v13 = v46;
        }
        updated = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseKeyUpdate((__int64)this + 1288, v11, v13);
        if ( !updated )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 57i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          }
          v43 = (__int64 *)*((_QWORD *)this + 1);
          if ( v43 )
            v4 = *v43;
          updated = UpdateTrafficSecretAndDeriveNewKey(
                      v4,
                      (unsigned __int64 *)this + 135,
                      (unsigned __int64 *)this + 18,
                      (unsigned __int64 *)this + 22);
          if ( !updated && *((_DWORD *)this + 17) != 79 )
            *((_DWORD *)this + 17) = 4;
        }
        return updated;
      }
      goto LABEL_113;
    }
    if ( v15 == 5199 )
    {
      v24 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
        return updated;
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 53i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        v24 = WPP_GLOBAL_Control;
      }
      if ( v24 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v24 + 28) & 4) == 0 )
        return updated;
      v25 = 54i64;
      goto LABEL_41;
    }
    v27 = v15 - 5182;
    if ( v27 && v27 != 8 )
      goto LABEL_113;
  }
  else if ( v15 != 5180 )
  {
    if ( v15 > 0xB4F )
    {
      v26 = v15 - 3900;
      if ( !v26 )
      {
        v22 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 51i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          v22 = WPP_GLOBAL_Control;
          v11 = v48;
          v13 = v46;
        }
        if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) != 4 )
        {
          updated = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseCertificateVerify(
                      (__int64)this + 1288,
                      (__int64)v11,
                      v13);
          if ( !updated )
          {
            updated = DoCertificateMapping(this);
            if ( !updated )
              *((_DWORD *)this + 17) = 62;
          }
          return updated;
        }
        if ( v22 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v22 + 28) & 1) == 0 )
          return (unsigned int)-2146893018;
        v23 = 52i64;
        goto LABEL_25;
      }
      if ( v26 != 19 )
      {
LABEL_113:
        *((_DWORD *)this + 17) = 96;
        *((_WORD *)this + 48) = 2562;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_DD(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x3Au,
            (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
            v14,
            96);
        return (unsigned int)-2146893018;
      }
      v24 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
        return updated;
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 49i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        v24 = WPP_GLOBAL_Control;
      }
      if ( v24 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v24 + 28) & 4) == 0 )
        return updated;
      v25 = 50i64;
    }
    else
    {
      if ( v15 != 2895 )
      {
        v20 = v15 - 327;
        if ( !v20 )
        {
LABEL_5:
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 43i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
            v12 = *((_DWORD *)this + 17);
          }
          v16 = v12 == 71;
          *((_QWORD *)this + 17) |= 0x8000ui64;
          (*(void (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 240i64))(this);
          v17 = *(_QWORD *)this;
          *((_QWORD *)this + 11) = 0i64;
          LOBYTE(v18) = 1;
          updated = (*(__int64 (__fastcall **)(CTls13ServerContext *, unsigned __int8 *, _QWORD, __int64, char *))(v17 + 536))(
                      this,
                      a2,
                      a3,
                      v18,
                      &v47);
          if ( !updated )
          {
            v44 = *((_QWORD *)this + 17);
            if ( (v44 & 0x40000) == 0 )
            {
              *((_BYTE *)this + 552) = 0;
              *((_QWORD *)this + 17) = v44 & 0xFFFFFFFFFFBFFFFFui64;
              if ( v16 )
              {
                *((_DWORD *)this + 17) = 99;
              }
              else
              {
                v45 = 93;
                if ( *((_DWORD *)this + 17) == 71 )
                  v45 = 98;
                *((_DWORD *)this + 17) = v45;
              }
            }
          }
          return updated;
        }
        v21 = v20 - 2559;
        if ( !v21 || v21 == 8 )
        {
          v22 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 46i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
            v22 = WPP_GLOBAL_Control;
            v11 = v48;
            v13 = v46;
          }
          if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4 )
          {
            if ( v22 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v22 + 28) & 1) == 0 )
              return (unsigned int)-2146893018;
            v23 = 47i64;
          }
          else
          {
            if ( (*((_DWORD *)this + 34) & 0x100i64) != 0 && (*((_DWORD *)this + 17) != 78 || *((_BYTE *)this + 1232)) )
            {
              updated = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseCertificateMsg(
                          (__int64)this + 1288,
                          v11,
                          v13);
              if ( !updated )
                *((_DWORD *)this + 17) = 60;
              return updated;
            }
            if ( v22 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v22 + 28) & 1) == 0 )
              return (unsigned int)-2146893018;
            v23 = 48i64;
          }
LABEL_25:
          WPP_SF_(*((_QWORD *)v22 + 2), v23, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          return (unsigned int)-2146893018;
        }
        goto LABEL_113;
      }
      v24 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
        return updated;
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 44i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
        v24 = WPP_GLOBAL_Control;
      }
      if ( v24 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v24 + 28) & 4) == 0 )
        return updated;
      v25 = 45i64;
    }
LABEL_41:
    WPP_SF_(*((_QWORD *)v24 + 2), v25, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
    return updated;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 55i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
    v12 = *((_DWORD *)this + 17);
    v11 = a2 + 4;
    v13 = a3 - 4;
  }
  if ( v12 == 60 && (*((_DWORD *)this + 34) & 0x100i64) != 0 && !*((_BYTE *)this + 552) )
    return (unsigned int)-2146893018;
  updated = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseFinished((__int64)this + 1288, v11, v13);
  if ( updated )
    return updated;
  updated = (*(__int64 (__fastcall **)(CTls13ServerContext *, unsigned __int8 *, _QWORD, _QWORD))(*(_QWORD *)this
                                                                                                + 504i64))(
              this,
              a2,
              a3,
              0i64);
  if ( updated )
    return updated;
  *a4 = 1;
  if ( (*((_DWORD *)this + 34) & 0x2008000) != 33587200i64 || (*(_BYTE *)(v10 + 156) & 0x20) != 0 )
  {
    v33 = *(_QWORD *)this;
    *((_BYTE *)this + 1216) = 3;
    (*(void (__fastcall **)(CTls13ServerContext *))(v33 + 448))(this);
  }
  else
  {
    if ( !*((_QWORD *)this + 11) )
      return 1359;
    v28 = (__int64 *)*((_QWORD *)this + 1);
    v46 = 0i64;
    if ( v28 )
      v29 = *v28;
    else
      v29 = 0i64;
    v30 = SslExpandResumptionMasterKey(v29, *((_QWORD *)this + 134), *((_QWORD *)this + 74), &v46, 0i64, 0);
    updated = v30;
    if ( v30 )
    {
      CSslContext::SetError((__int64)this, 613, v30);
      return updated;
    }
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
    v31 = *((_QWORD *)this + 11);
    v32 = *(_QWORD *)(v31 + 16);
    if ( v32 )
    {
      SslFreeObject(v32, 0i64);
      v31 = *((_QWORD *)this + 11);
    }
    *(_QWORD *)(v31 + 16) = v46;
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
    *((_DWORD *)this + 17) = 102;
  }
  if ( !*((_BYTE *)this + 1233) )
  {
    *((_WORD *)this + 16) |= 0xAu;
    v34 = *((_QWORD *)this + 18);
    if ( v34 )
      SslFreeObject(v34, 0i64);
    *((_QWORD *)this + 18) = *((_QWORD *)this + 20);
    *((_QWORD *)this + 20) = 0i64;
    if ( !*((_BYTE *)this + 233) )
      *((_QWORD *)this + 22) = 0i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  }
  v35 = *(_QWORD *)this;
  updated = 0;
  *((_BYTE *)this + 1233) = 1;
  if ( (*(unsigned __int8 (__fastcall **)(CTls13ServerContext *))(v35 + 384))(this) )
    return updated;
  v36 = (__int64 *)*((_QWORD *)this + 1);
  if ( v36 )
    v37 = *v36;
  else
    v37 = 0i64;
  v38 = CTls13Context::PopulateSecTrafficSecret((__int64)this + 1000, v37, 1, 3u, (__int64)v36, 0, 0);
  v39 = v38;
  if ( !v38 )
  {
    v40 = (__int64 *)*((_QWORD *)this + 1);
    if ( v40 )
      v41 = *v40;
    else
      v41 = 0i64;
    v42 = CTls13Context::PopulateSecTrafficSecret((__int64)this + 1000, v41, 0, 3u, (__int64)v40, 0, 0);
    updated = v42;
    if ( v42 )
      CSslContext::SetError((__int64)this, 611, v42);
    return updated;
  }
  CSslContext::SetError((__int64)this, 612, v38);
  return v39;
}
// 180022D1E: variable 'v18' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098450: using guessed type __int64 __fastcall SslExpandResumptionMasterKey(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
