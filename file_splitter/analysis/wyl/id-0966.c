//----- (0000000180050148) ----------------------------------------------------
__int64 __fastcall Tls13DecryptHandler(
        struct CSslUserContext *a1,
        struct SPBuffer *a2,
        struct SPBuffer *a3,
        unsigned __int8 *a4)
{
  _BYTE *v8; // r14
  CCipherMill *v10; // rcx
  unsigned __int16 v11; // dx
  unsigned int v12; // r8d
  int v13; // r9d
  unsigned int v14; // edx
  CCipherMill *v15; // rcx
  unsigned __int16 v16; // dx
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // r12d
  int v20; // r8d
  __int64 v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rcx
  unsigned int v24; // eax
  CCipherMill *v25; // rcx
  CCipherMill *v26; // rcx
  __int64 v27; // rcx
  unsigned __int8 *v28; // rdx
  bool v29; // zf
  int v30; // ecx
  CCipherMill *v31; // rcx
  int v32; // r9d
  int v33; // r12d
  int v34; // ecx
  int v35; // ecx
  unsigned __int8 *v36; // rcx
  CCipherMill *v37; // rcx
  __int16 v38; // ax
  CCipherMill *v39; // rcx
  unsigned int v40; // esi
  unsigned __int16 v41; // dx
  unsigned int v42; // eax
  _BYTE *v43; // [rsp+20h] [rbp-68h]
  int v44; // [rsp+28h] [rbp-60h]
  __int64 v45; // [rsp+38h] [rbp-50h]
  unsigned int v46; // [rsp+50h] [rbp-38h]
  unsigned int v47; // [rsp+54h] [rbp-34h]
  unsigned __int8 *Src; // [rsp+58h] [rbp-30h]
  size_t Size; // [rsp+90h] [rbp+8h] BYREF

  if ( !a1 || !a2 || (v8 = (_BYTE *)*((_QWORD *)a2 + 1)) == 0i64 || !a3 || !*((_QWORD *)a3 + 1) || !a4 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xAu,
        (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
        -2146892963,
        -2146892963);
    return 2148074333i64;
  }
  if ( (*((_DWORD *)a1 + 6) & 0x3000) == 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xBu,
        (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
        -2146893055,
        -2146893055);
    return 2148074241i64;
  }
  if ( *((_DWORD *)a1 + 2) != 4 && *((_DWORD *)a1 + 2) != 79 )
  {
    v10 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return 2148074248i64;
    v11 = 12;
LABEL_96:
    LODWORD(v43) = -2146893048;
    WPP_SF_DD(*((_QWORD *)v10 + 2), v11, (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, -2146893048, v43);
    return 2148074248i64;
  }
  v12 = *((_DWORD *)a2 + 1);
  v13 = *((_DWORD *)a1 + 17);
  v14 = v13 + *((_DWORD *)a1 + 16);
  *((_DWORD *)a2 + 1) = 0;
  if ( v12 < v14 )
  {
    *((_DWORD *)a2 + 1) = v14;
    v15 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return 2148074264i64;
    v16 = 13;
LABEL_29:
    WPP_SF_DD(
      *((_QWORD *)v15 + 2),
      v16,
      (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
      -2146893032,
      -2146893032);
    return 2148074264i64;
  }
  if ( v8[1] == 0xFE && ((unsigned __int8)v8[2] | ((unsigned __int8)v8[1] << 8)) <= 0xFEFFu )
  {
    v17 = (unsigned __int8)v8[11];
    v18 = (unsigned __int8)v8[12];
  }
  else
  {
    v17 = (unsigned __int8)v8[3];
    v18 = (unsigned __int8)v8[4];
  }
  v19 = (v18 | (v17 << 8)) + v13;
  v47 = v19;
  if ( v12 < v19 )
  {
    *((_DWORD *)a2 + 1) = v19;
    v15 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return 2148074264i64;
    v16 = 14;
    goto LABEL_29;
  }
  v20 = v12 - v14;
  v45 = *((_QWORD *)a1 + 12);
  v21 = v14;
  v22 = *((_QWORD *)a1 + 5);
  v44 = v20;
  v43 = &v8[v21];
  Src = &v8[v21];
  v23 = *((_QWORD *)a1 + 11);
  LODWORD(Size) = v20;
  v24 = SslDecryptPacket(v23, v22, v8);
  v46 = v24;
  v25 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v24);
      v25 = WPP_GLOBAL_Control;
    }
    if ( v25 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v25 + 28) & 4) != 0 )
      {
        WPP_SF_D(*((_QWORD *)v25 + 2), 16i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, (unsigned int)Size);
        v25 = WPP_GLOBAL_Control;
      }
      if ( v25 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v25 + 28) & 4) != 0 )
        WPP_SF_i(
          *((_QWORD *)v25 + 2),
          0x11u,
          (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
          *((_QWORD *)a1 + 12),
          v43,
          v44,
          &Size,
          v45,
          0);
    }
  }
  *((_DWORD *)a2 + 1) += v19;
  ++*((_QWORD *)a1 + 12);
  if ( v46 )
  {
    v26 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v46);
      v26 = WPP_GLOBAL_Control;
    }
    *a4 = 20;
    if ( v26 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v26 + 28) & 5) != 0 )
    {
      LODWORD(v43) = -2146893008;
      WPP_SF_Dd(
        *((_QWORD *)v26 + 2),
        0x13u,
        (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
        -2146893008,
        v43);
    }
    return 2148074288i64;
  }
  LODWORD(v27) = Size;
  v28 = Src;
  do
  {
    v29 = (_DWORD)v27 == 1;
    v27 = (unsigned int)(v27 - 1);
    LODWORD(Size) = v27;
  }
  while ( !v29 && !Src[v27] );
  v30 = Src[v27];
  if ( !(_BYTE)v30 )
  {
    v31 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
      v31 = WPP_GLOBAL_Control;
    }
    *a4 = 10;
    if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 5) != 0 )
    {
      LODWORD(v43) = -2146893048;
      WPP_SF_Dd(
        *((_QWORD *)v31 + 2),
        0x15u,
        (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
        -2146893048,
        v43);
    }
    return 2148074248i64;
  }
  *v8 = v30;
  v32 = v30;
  v33 = *Src;
  v34 = v30 - 21;
  if ( !v34 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
    v42 = TlsParseAlertMessage(Src, Size, (unsigned __int8 *)a1 + 112, 0i64);
    *((_DWORD *)a3 + 1) = 0;
    v40 = v42;
    v39 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
      || ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 || !v42) && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
    {
      return v40;
    }
    v41 = 31;
    goto LABEL_101;
  }
  v35 = v34 - 1;
  if ( !v35 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
    *((_BYTE *)a1 + 112) = 0;
    *((_DWORD *)a3 + 1) = 0;
    if ( v33 != 4 && (_BYTE)v33 != 11 && (_BYTE)v33 != 13 && (_BYTE)v33 != 24 )
    {
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x18u,
          (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
          v33);
        v10 = WPP_GLOBAL_Control;
      }
      *a4 = 10;
      if ( v10 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v10 + 28) & 5) == 0 )
        return 2148074248i64;
      v11 = 25;
      goto LABEL_96;
    }
    v38 = Size;
    *((_DWORD *)a2 + 1) -= v47;
    *(_WORD *)&v8[v47 - 2] = v38;
    *((_DWORD *)a1 + 2) = 78;
    v39 = WPP_GLOBAL_Control;
    v40 = 590625;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return v40;
    v41 = 23;
LABEL_101:
    LODWORD(v43) = v40;
    WPP_SF_DD(*((_QWORD *)v39 + 2), v41, (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v40, v43);
    return v40;
  }
  if ( v35 != 1 )
  {
    v10 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_d(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x20u,
        (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
        v32);
      v10 = WPP_GLOBAL_Control;
    }
    *a4 = 10;
    if ( v10 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v10 + 28) & 5) == 0 )
      return 2148074248i64;
    v11 = 33;
    goto LABEL_96;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 26i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
    v28 = Src;
  }
  *((_BYTE *)a1 + 112) = 0;
  v36 = (unsigned __int8 *)*((_QWORD *)a3 + 1);
  if ( v36 != v28 )
  {
    if ( *(_DWORD *)a3 < (unsigned int)Size )
    {
      v37 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
        v37 = WPP_GLOBAL_Control;
      }
      *a4 = 20;
      if ( v37 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v37 + 28) & 5) != 0 )
      {
        LODWORD(v43) = -2146893008;
        WPP_SF_DD(
          *((_QWORD *)v37 + 2),
          0x1Cu,
          (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
          -2146893008,
          v43);
      }
      return 2148074288i64;
    }
    memcpy_0(v36, v28, (unsigned int)Size);
  }
  *((_DWORD *)a3 + 1) = Size;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    LODWORD(v43) = 0;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x1Du,
      (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
      0,
      v43);
  }
  return 0i64;
}
// 180050454: variable 'v43' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800984E0: using guessed type __int64 __fastcall SslDecryptPacket(_QWORD, _QWORD, _QWORD);

