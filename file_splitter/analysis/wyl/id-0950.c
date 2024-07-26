//----- (000000018004E80C) ----------------------------------------------------
__int64 __fastcall SpQuerySizes(struct CSslUserContext *a1, struct _SecPkgContext_Sizes *a2)
{
  CCipherMill *v4; // rcx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  bool v14; // zf
  unsigned int v15; // eax
  unsigned int *v16; // [rsp+20h] [rbp-38h]
  unsigned int v17; // [rsp+60h] [rbp+8h] BYREF
  unsigned int v18; // [rsp+70h] [rbp+18h] BYREF
  unsigned int v19; // [rsp+78h] [rbp+20h] BYREF

  v19 = 0;
  v18 = 0;
  v17 = 0;
  v4 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 95i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
      v4 = WPP_GLOBAL_Control;
    }
    if ( v4 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v4 + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)v4 + 2), 96i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  }
  if ( (unsigned int)QueryStreamSizes(
                       *((_QWORD *)a1 + 11),
                       *((_DWORD *)a1 + 14),
                       *((_DWORD *)a1 + 6),
                       *((_DWORD *)a1 + 15),
                       &v19,
                       &v18,
                       &v17) )
    return 2148074244i64;
  v6 = *((_DWORD *)a1 + 6);
  v7 = v18;
  if ( v6 > 0x800 )
  {
    if ( v6 == 4096 || v6 == 0x2000 || v6 == 0x10000 || v6 == 0x20000 || v6 == 0x40000 )
      goto LABEL_26;
    v14 = v6 == 0x80000;
  }
  else
  {
    if ( v6 == 2048 )
      goto LABEL_26;
    v8 = v6 - 16;
    if ( !v8 )
      goto LABEL_26;
    v9 = v8 - 16;
    if ( !v9 )
      goto LABEL_26;
    v10 = v9 - 32;
    if ( !v10 )
      goto LABEL_26;
    v11 = v10 - 64;
    if ( !v11 )
      goto LABEL_26;
    v12 = v11 - 128;
    if ( !v12 )
      goto LABEL_26;
    v13 = v12 - 256;
    if ( !v13 )
      goto LABEL_26;
    v14 = v13 == 512;
  }
  if ( v14 )
  {
LABEL_26:
    a2->cbMaxToken = 0x4000 - v17 - v18;
    v15 = v7 + v17 + *((_DWORD *)a1 + 16) + *((_DWORD *)a1 + 17) + ((*((_DWORD *)a1 + 6) & 0x3000) != 0);
    goto LABEL_27;
  }
  a2->cbMaxToken = 0x4000;
  v15 = 0;
LABEL_27:
  a2->cbSecurityTrailer = v15;
  a2->cbBlockSize = v19;
  a2->cbMaxSignature = v7;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    LODWORD(v16) = 0;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x61u,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      0,
      v16);
  }
  return 0i64;
}
// 18004E98D: variable 'v16' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

