//----- (0000000180015E38) ----------------------------------------------------
__int64 __fastcall CTlsExt::BuildTBExtension(
        CTlsExt *this,
        char a2,
        char a3,
        unsigned __int8 *const a4,
        unsigned __int8 a5,
        unsigned __int8 *const a6,
        unsigned __int8 **a7)
{
  __int64 v8; // rdi
  unsigned __int16 v9; // dx
  char *v10; // rdi

  if ( !a4 )
    return 87i64;
  if ( !a5 )
    return 87i64;
  if ( !a7 )
    return 87i64;
  v8 = (__int64)*a7;
  if ( !*a7 )
    return 87i64;
  v9 = a5 + 3;
  if ( (unsigned __int64)v9 + v8 + 4 > (unsigned __int64)a6 )
    return 87i64;
  *(_WORD *)v8 = 6144;
  *(_BYTE *)(v8 + 3) = v9;
  *(_BYTE *)(v8 + 5) = a3;
  *(_BYTE *)(v8 + 2) = HIBYTE(v9);
  *(_BYTE *)(v8 + 4) = a2;
  *(_BYTE *)(v8 + 6) = a5;
  v10 = (char *)(v8 + 7);
  memcpy_0(v10, a4, a5);
  *a7 = (unsigned __int8 *)&v10[a5];
  return 0i64;
}

