//----- (000000018000C91C) ----------------------------------------------------
__int64 __fastcall TlsDecryptHandler(
        struct CSslUserContext *a1,
        struct SPBuffer *a2,
        struct SPBuffer *a3,
        unsigned __int8 *a4)
{
  int v4; // eax
  int v5; // r14d
  unsigned __int8 *v10; // r8
  int v11; // edx
  bool v12; // zf
  int v13; // ecx
  unsigned int v14; // ebp
  int v15; // ecx
  int v16; // ecx
  CCipherMill *v17; // rcx
  unsigned int v18; // eax
  CCipherMill *v19; // rcx
  unsigned __int64 v21; // r14
  unsigned int v22; // eax
  unsigned int v23; // r15d
  int v24; // eax
  unsigned int v25; // esi
  CCipherMill *v26; // rcx
  unsigned __int16 v27; // dx
  unsigned __int16 v28; // dx
  CCipherMill *v29; // r10
  int v30; // r14d
  int v31; // r8d
  unsigned int v32; // eax
  unsigned int v33; // r12d
  CCipherMill *v34; // rcx
  unsigned int v35; // r12d
  unsigned __int8 *v36; // r8
  unsigned __int64 v37; // r14
  unsigned int v38; // eax
  unsigned int v39; // r15d
  CCipherMill *v40; // rcx
  CCipherMill *v41; // rcx
  unsigned __int16 v42; // dx
  _BYTE *v43; // rax
  unsigned __int8 *v44; // rcx
  unsigned __int64 v45; // rbp
  __int64 v46; // rcx
  int v47; // r9d
  _BYTE *v48; // r14
  unsigned int v49; // eax
  unsigned int v50; // ebp
  CCipherMill *v51; // rcx
  unsigned __int64 *v52; // [rsp+20h] [rbp-78h]
  struct SPBuffer *v53; // [rsp+28h] [rbp-70h]
  unsigned int v54; // [rsp+28h] [rbp-70h]
  struct SPBuffer *v55; // [rsp+30h] [rbp-68h]
  unsigned __int8 *v56; // [rsp+38h] [rbp-60h]
  unsigned __int8 *v57; // [rsp+38h] [rbp-60h]
  __int64 v58; // [rsp+40h] [rbp-58h]
  unsigned int v59; // [rsp+50h] [rbp-48h] BYREF
  unsigned int v60; // [rsp+54h] [rbp-44h] BYREF
  int v61; // [rsp+58h] [rbp-40h]
  unsigned int v62; // [rsp+A0h] [rbp+8h] BYREF
  int v63; // [rsp+A8h] [rbp+10h]
  unsigned __int8 *v64; // [rsp+B8h] [rbp+20h]

  v64 = a4;
  v4 = 4;
  v5 = *((_DWORD *)a1 + 17) + *((_DWORD *)a1 + 16);
  v61 = v5;
  v10 = (unsigned __int8 *)*((_QWORD *)a2 + 1);
  v11 = *((_DWORD *)a1 + 6) & 0xF0000;
  v62 = v11;
  if ( v11 )
    v4 = 12;
  v12 = *((_DWORD *)a1 + 2) == 4;
  v63 = v4;
  if ( !v12 )
  {
    v26 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return 2148074248i64;
    v27 = 34;
    goto LABEL_102;
  }
  v13 = *v10;
  if ( ((v13 - 20) & 0xFFFFFFFC) == 0 && v13 != 21 )
    *((_BYTE *)a1 + 112) = 0;
  v14 = -2146893008;
  v15 = v13 - 21;
  if ( v15 )
  {
    v16 = v15 - 1;
    if ( v16 )
    {
      if ( v16 == 1 )
      {
        v17 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 35i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            v17 = WPP_GLOBAL_Control;
          }
          if ( v17 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v17 + 28) & 4) != 0 )
            WPP_SF_(*((_QWORD *)v17 + 2), 36i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
        }
        v18 = TlsDecryptMessage(
                *((_QWORD *)a1 + 11),
                *((_QWORD *)a1 + 5),
                v5 - *((_DWORD *)a1 + 17),
                *((_DWORD *)a1 + 17),
                (unsigned __int64 *)a1 + 12,
                a2,
                a3,
                a4);
        v14 = v18;
        v19 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v18);
            v19 = WPP_GLOBAL_Control;
          }
          if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v19 + 28) & 4) != 0 )
          {
            WPP_SF_i(
              *((_QWORD *)v19 + 2),
              0x26u,
              (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
              *((_QWORD *)a1 + 12));
            v19 = WPP_GLOBAL_Control;
          }
        }
        if ( v62 && !*((_BYTE *)a1 + 140) )
        {
          *((_BYTE *)a1 + 140) = 1;
          v19 = WPP_GLOBAL_Control;
        }
        if ( v19 == (CCipherMill *)&WPP_GLOBAL_Control
          || ((*((_BYTE *)v19 + 28) & 1) == 0 || !v14) && (*((_BYTE *)v19 + 28) & 4) == 0 )
        {
          return v14;
        }
        v28 = 39;
LABEL_56:
        LODWORD(v52) = v14;
        WPP_SF_DD(*((_QWORD *)v19 + 2), v28, (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v14, v52);
        return v14;
      }
      v26 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 62i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
        v26 = WPP_GLOBAL_Control;
      }
      *a4 = 10;
      if ( v26 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v26 + 28) & 5) == 0 )
        return 2148074248i64;
      v27 = 63;
      goto LABEL_102;
    }
    v29 = WPP_GLOBAL_Control;
    v30 = 40;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
      v29 = WPP_GLOBAL_Control;
      v11 = v62;
    }
    v31 = *((_DWORD *)a1 + 6);
    if ( (v31 & 0x800A2AAA) != 0 )
    {
      v32 = QueryStreamSizes(*((_QWORD *)a1 + 11), *((_DWORD *)a1 + 14), v31, *((_DWORD *)a1 + 15), 0i64, &v60, &v59);
      v33 = v32;
      if ( v32 )
      {
        v34 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 41i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v32);
            v34 = WPP_GLOBAL_Control;
          }
          if ( v34 != (CCipherMill *)&WPP_GLOBAL_Control
            && ((*((_BYTE *)v34 + 28) & 1) != 0 || (*((_BYTE *)v34 + 28) & 4) != 0) )
          {
            LODWORD(v52) = v33;
            WPP_SF_DD(*((_QWORD *)v34 + 2), 0x2Au, (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v33, v52);
          }
        }
        return v33;
      }
      if ( *(_DWORD *)a2 > v61 + v63 + v59 + v60 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 43i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
        goto LABEL_142;
      }
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 44i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
      v35 = v62;
      v36 = (unsigned __int8 *)*((_QWORD *)a2 + 1);
      if ( v62 )
        v37 = v36[10] | ((v36[9] | ((v36[8] | ((v36[7] | ((v36[6] | ((v36[5] | ((v36[4] | ((unsigned __int64)v36[3] << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) << 8);
      else
        v37 = *((_QWORD *)a1 + 12);
      LODWORD(v58) = 0;
      v56 = (unsigned __int8 *)v37;
      v55 = (struct SPBuffer *)((char *)a3 + 4);
      LODWORD(v53) = *(_DWORD *)a3;
      v52 = (unsigned __int64 *)*((_QWORD *)a3 + 1);
      v38 = SslDecryptPacket(*((_QWORD *)a1 + 11), *((_QWORD *)a1 + 5), v36);
      v39 = v38;
      v40 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 45i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v38);
          v40 = WPP_GLOBAL_Control;
        }
        if ( v40 != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)v40 + 28) & 4) != 0 )
          {
            WPP_SF_D(
              *((_QWORD *)v40 + 2),
              46i64,
              &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
              *((unsigned int *)a3 + 1));
            v40 = WPP_GLOBAL_Control;
          }
          if ( v40 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v40 + 28) & 4) != 0 )
            WPP_SF_i(
              *((_QWORD *)v40 + 2),
              0x2Fu,
              (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
              *((_QWORD *)a1 + 12),
              v52,
              v53,
              v55,
              v37,
              0);
        }
      }
      if ( v35 )
        *((_QWORD *)a1 + 12) = v37;
      else
        ++*((_QWORD *)a1 + 12);
      if ( !v39 )
      {
        if ( *((_DWORD *)a3 + 1) != v63 || (v43 = (_BYTE *)*((_QWORD *)a3 + 1), *v43) )
        {
          *v64 = 10;
          v26 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
          {
            return 2148074248i64;
          }
          v27 = 49;
LABEL_102:
          LODWORD(v52) = -2146893048;
          WPP_SF_DD(
            *((_QWORD *)v26 + 2),
            v27,
            (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
            -2146893048,
            v52);
          return 2148074248i64;
        }
        v30 = 76;
        *((_DWORD *)a1 + 36) = (unsigned __int8)v43[5] + 1 + ((unsigned __int8)v43[4] << 8);
LABEL_143:
        *((_DWORD *)a1 + 2) = v30;
        *((_DWORD *)a3 + 1) = 0;
        v19 = WPP_GLOBAL_Control;
        v14 = 590625;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
          return v14;
        v28 = 57;
        goto LABEL_56;
      }
      *v64 = 20;
      v41 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
        return v14;
      v42 = 48;
      goto LABEL_109;
    }
    if ( !v11 )
    {
      v30 = 76;
LABEL_142:
      *((_DWORD *)a2 + 1) = 0;
      goto LABEL_143;
    }
    v44 = (unsigned __int8 *)*((_QWORD *)a2 + 1);
    v45 = v44[10] | ((v44[9] | ((v44[8] | ((v44[7] | ((v44[6] | ((v44[5] | ((v44[4] | ((unsigned __int64)v44[3] << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) << 8);
    if ( HIWORD(v45) < (unsigned int)*((int *)a1 + 29) )
    {
      v14 = -2146893005;
      if ( v29 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v29 + 28) & 5) == 0 )
        return v14;
      v46 = *((_QWORD *)v29 + 2);
      v42 = 50;
      v47 = -2146893005;
      goto LABEL_110;
    }
    v62 = *((_DWORD *)a2 + 1);
    v48 = LocalAlloc(0x40u, v62);
    if ( !v48 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
        WPP_SF_DD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x33u,
          (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
          -2146893056,
          -2146893056);
      return 2148074240i64;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 52i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
    v57 = (unsigned __int8 *)v45;
    v54 = v62;
    HIDWORD(v52) = HIDWORD(v48);
    v49 = SslDecryptPacket(*((_QWORD *)a1 + 11), *((_QWORD *)a1 + 5), *((_QWORD *)a2 + 1));
    v50 = v49;
    v51 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 53i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v49);
        v51 = WPP_GLOBAL_Control;
      }
      if ( v51 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v51 + 28) & 4) != 0 )
        {
          WPP_SF_D(
            *((_QWORD *)v51 + 2),
            54i64,
            &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
            *((unsigned int *)a3 + 1));
          v51 = WPP_GLOBAL_Control;
        }
        if ( v51 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v51 + 28) & 4) != 0 )
          WPP_SF_i(
            *((_QWORD *)v51 + 2),
            0x37u,
            (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
            *((_QWORD *)a1 + 12),
            v48,
            v54,
            &v62,
            v57,
            0);
      }
    }
    if ( v50 )
    {
      *a4 = 20;
      v14 = -2146893008;
      goto LABEL_137;
    }
    if ( v62 >= 0xC )
    {
      if ( !*((_BYTE *)a1 + 140) )
      {
        if ( *v48 != 1 )
        {
          v14 = -2146893005;
          goto LABEL_137;
        }
        goto LABEL_135;
      }
      if ( *v48 == 1 )
      {
LABEL_135:
        v14 = 590625;
        *((_DWORD *)a1 + 36) = (unsigned __int8)v48[5] + ((unsigned __int8)v48[4] << 8);
        goto LABEL_137;
      }
    }
    v14 = -2146893048;
    *a4 = 10;
LABEL_137:
    LocalFree(v48);
    *((_DWORD *)a3 + 1) = 0;
    *((_DWORD *)a2 + 1) = 0;
    v19 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
    {
      return v14;
    }
    v28 = 56;
    goto LABEL_56;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 58i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
    v10 = (unsigned __int8 *)*((_QWORD *)a2 + 1);
  }
  if ( (*((_DWORD *)a1 + 6) & 0xF0000) != 0 )
    v21 = v10[10] | ((v10[9] | ((v10[8] | ((v10[7] | ((v10[6] | ((v10[5] | ((v10[4] | ((unsigned __int64)v10[3] << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) << 8);
  else
    v21 = *((_QWORD *)a1 + 12);
  LODWORD(v58) = 0;
  v56 = (unsigned __int8 *)v21;
  v55 = (struct SPBuffer *)((char *)a3 + 4);
  LODWORD(v53) = *(_DWORD *)a3;
  v52 = (unsigned __int64 *)*((_QWORD *)a3 + 1);
  v22 = SslDecryptPacket(*((_QWORD *)a1 + 11), *((_QWORD *)a1 + 5), v10);
  v23 = v22;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v22);
  if ( (*((_DWORD *)a1 + 6) & 0xF0000) != 0 )
    *((_QWORD *)a1 + 12) = v21;
  else
    ++*((_QWORD *)a1 + 12);
  if ( v23 )
  {
    *a4 = 20;
    v41 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return v14;
    v42 = 60;
LABEL_109:
    v46 = *((_QWORD *)v41 + 2);
    v47 = -2146893008;
LABEL_110:
    LODWORD(v52) = v14;
    WPP_SF_Dd(v46, v42, (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v47, v52, v53, v55, v56, v58);
    return v14;
  }
  v24 = TlsParseAlertMessage(*((unsigned __int8 **)a3 + 1), *((_DWORD *)a3 + 1), (unsigned __int8 *)a1 + 112, 0i64);
  *((_DWORD *)a3 + 1) = 0;
  v25 = v24;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v24 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(v52) = v24;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x3Du,
      (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
      v24,
      v52,
      (_DWORD)v53,
      v55,
      v21,
      0);
  }
  return v25;
}
// 180036B8D: variable 'v52' is possibly undefined
// 180036E06: variable 'v53' is possibly undefined
// 180036F74: variable 'v55' is possibly undefined
// 180036F74: variable 'v56' is possibly undefined
// 180036F74: variable 'v58' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800984E0: using guessed type __int64 __fastcall SslDecryptPacket(_QWORD, _QWORD, _QWORD);

