// File count: 150
// Total lines: 143
----------------------------------------
__int64 __fastcall SpQueryStreamSizes(struct CSslUserContext *a1, struct _SecPkgContext_StreamSizes *a2)
{
  int v4; // ebp
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // r10d
  unsigned int v10; // r11d
  __int64 v11; // r8
  __int64 v12; // rdx
  unsigned int v13; // r9d
  unsigned int v14; // eax
  CCipherMill *v15; // rcx
  CCipherMill *v17; // rcx
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  bool v24; // zf
  unsigned int *v25; // [rsp+20h] [rbp-48h]
  unsigned int *v26; // [rsp+28h] [rbp-40h]
  unsigned int *v27; // [rsp+30h] [rbp-38h]
  unsigned int v28; // [rsp+70h] [rbp+8h] BYREF
  unsigned int v29; // [rsp+80h] [rbp+18h] BYREF
  unsigned int v30; // [rsp+88h] [rbp+20h] BYREF

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 98i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  v4 = *((_DWORD *)a1 + 6) & 0xF0000;
  v5 = QueryStreamSizes(
         *((_QWORD *)a1 + 11),
         *((_DWORD *)a1 + 14),
         *((_DWORD *)a1 + 6),
         *((_DWORD *)a1 + 15),
         &v30,
         &v28,
         &v29);
  v6 = v5;
  if ( !v5 )
  {
    a2->cbHeader = 0;
    v7 = *((_DWORD *)a1 + 6);
    v8 = 0;
    if ( v7 > 0x800 )
    {
      if ( v7 == 4096 || v7 == 0x2000 || v7 == 0x10000 || v7 == 0x20000 || v7 == 0x40000 )
        goto LABEL_7;
      v24 = v7 == 0x80000;
    }
    else
    {
      if ( v7 == 2048 )
        goto LABEL_7;
      v18 = v7 - 16;
      if ( !v18 || (v19 = v18 - 16) == 0 || (v20 = v19 - 32) == 0 || (v21 = v20 - 64) == 0 )
      {
        v8 = *((_DWORD *)a1 + 18);
        a2->cbHeader = v8;
        goto LABEL_7;
      }
      v22 = v21 - 128;
      if ( !v22 )
        goto LABEL_7;
      v23 = v22 - 256;
      if ( !v23 )
        goto LABEL_7;
      v24 = v23 == 512;
    }
    if ( !v24 )
    {
      a2->cbTrailer = 0;
      v12 = 0x4000i64;
      v11 = 0i64;
      a2->cbMaximumMessage = 0x4000;
      v13 = 0;
LABEL_11:
      v14 = v30;
      a2->cbBlockSize = v30;
      a2->cBuffers = 4;
      v15 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LODWORD(v27) = 4;
          LODWORD(v26) = v12;
          LODWORD(v25) = v11;
          WPP_SF_DDDDD(*((_QWORD *)WPP_GLOBAL_Control + 2), v12, v11, v13, v25, v26, v27, v14);
          v15 = WPP_GLOBAL_Control;
        }
        if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
        {
          LODWORD(v25) = 0;
          WPP_SF_DD(*((_QWORD *)v15 + 2), 0x66u, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, 0, v25);
        }
      }
      return 0i64;
    }
LABEL_7:
    v9 = v28;
    v10 = v29;
    v11 = v28 + v29;
    a2->cbTrailer = v11;
    if ( v4 )
      v12 = *((unsigned __int16 *)a1 + 68);
    else
      v12 = 0x4000i64;
    a2->cbMaximumMessage = v12;
    v13 = v8 + *((_DWORD *)a1 + 16) + *((_DWORD *)a1 + 17);
    a2->cbHeader = v13;
    if ( (*((_DWORD *)a1 + 6) & 0x3000) != 0 )
    {
      v11 = v9 + (_DWORD)v11 + v13 + v10 + 7;
      a2->cbTrailer = v11;
    }
    goto LABEL_11;
  }
  v17 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 99i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v5);
      v17 = WPP_GLOBAL_Control;
    }
    if ( v17 != (CCipherMill *)&WPP_GLOBAL_Control
      && ((*((_BYTE *)v17 + 28) & 1) != 0 || (*((_BYTE *)v17 + 28) & 4) != 0) )
    {
      LODWORD(v25) = v6;
      WPP_SF_DD(*((_QWORD *)v17 + 2), 0x64u, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v6, v25);
    }
  }
  return v6;
}
// 180037DF4: variable 'v25' is possibly undefined
// 180037DF4: variable 'v26' is possibly undefined
// 180037DF4: variable 'v27' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
