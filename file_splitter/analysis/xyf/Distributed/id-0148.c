//----- (000000018000CB70) ----------------------------------------------------
__int64 __fastcall TlsDecryptMessage(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        unsigned __int64 *a5,
        struct SPBuffer *a6,
        struct SPBuffer *a7,
        unsigned __int8 *a8)
{
  int v9; // r14d
  CCipherMill *v12; // rcx
  unsigned __int8 *v13; // r8
  unsigned int v14; // edi
  int v15; // edx
  int v16; // eax
  unsigned __int8 *v17; // r10
  int v18; // r9d
  unsigned int v19; // edx
  unsigned __int8 *v20; // rax
  unsigned int v21; // eax
  unsigned int v22; // ebx
  __int64 v24; // [rsp+20h] [rbp-68h]
  unsigned int Size; // [rsp+54h] [rbp-34h]
  unsigned __int8 *Size_4; // [rsp+58h] [rbp-30h]

  v9 = a3 + a4;
  v12 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 64i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
    v12 = WPP_GLOBAL_Control;
  }
  v13 = (unsigned __int8 *)*((_QWORD *)a6 + 1);
  *((_DWORD *)a6 + 1) = a4;
  v14 = v13[2] | (v13[1] << 8);
  if ( v14 - 768 > 3 && v14 != 65277 && v14 != 65279 )
  {
    v22 = -2146893048;
    *a8 = 70;
    goto LABEL_21;
  }
  if ( BYTE1(v14) == 0xFE && v14 <= 0xFEFF )
  {
    v15 = v13[11];
    v16 = v13[12];
  }
  else
  {
    v15 = v13[3];
    v16 = v13[4];
  }
  v17 = &v13[v9];
  Size_4 = v17;
  v18 = (v16 | (v15 << 8)) + a4;
  v19 = *(_DWORD *)a6 - v9;
  *((_DWORD *)a6 + 1) = v18;
  Size = v19;
  v20 = v13;
  if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)v12 + 2), 65i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
    v13 = (unsigned __int8 *)*((_QWORD *)a6 + 1);
    v20 = v13;
    HIDWORD(v17) = HIDWORD(Size_4);
  }
  if ( BYTE1(v14) != 0xFE || v14 > 0xFEFF )
    v13 = v20;
  HIDWORD(v24) = HIDWORD(v17);
  v21 = SslDecryptPacket(a1, a2, v13);
  v22 = v21;
  v12 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 66i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v21);
    v12 = WPP_GLOBAL_Control;
  }
  if ( v22 )
  {
    if ( v12 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v12 + 28) & 1) == 0 )
      goto LABEL_38;
    WPP_SF_D(*((_QWORD *)v12 + 2), 67i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v22);
    goto LABEL_37;
  }
  if ( BYTE1(v14) != 0xFE || v14 > 0xFEFF )
  {
    ++*a5;
    v12 = WPP_GLOBAL_Control;
  }
  if ( *((unsigned __int8 **)a7 + 1) == Size_4 )
    goto LABEL_20;
  if ( *(_DWORD *)a7 >= Size )
  {
    memcpy_0(*((void **)a7 + 1), Size_4, Size);
LABEL_20:
    *((_DWORD *)a7 + 1) = Size;
    v12 = WPP_GLOBAL_Control;
    goto LABEL_21;
  }
  if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 1) != 0 )
  {
    WPP_SF_(*((_QWORD *)v12 + 2), 68i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
LABEL_37:
    v12 = WPP_GLOBAL_Control;
  }
LABEL_38:
  v22 = -2146893008;
  *a8 = 20;
LABEL_21:
  if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)v12 + 28) & 4) != 0 )
    {
      WPP_SF_D(*((_QWORD *)v12 + 2), 69i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v22);
      v12 = WPP_GLOBAL_Control;
    }
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control
      && ((*((_BYTE *)v12 + 28) & 1) != 0 && v22 || (*((_BYTE *)v12 + 28) & 4) != 0) )
    {
      LODWORD(v24) = v22;
      WPP_SF_DD(*((_QWORD *)v12 + 2), 0x46u, (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, v22, v24);
    }
  }
  return v22;
}
// 18003743D: variable 'v24' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800984E0: using guessed type __int64 __fastcall SslDecryptPacket(_QWORD, _QWORD, _QWORD);

