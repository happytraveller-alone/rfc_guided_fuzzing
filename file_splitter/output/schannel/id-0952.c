// File count: 952
// Total lines: 22
-----------------------------------------
__int64 __fastcall SpQueryTokenBindingEKM(struct CSslUserContext *a1, struct _SecPkgContext_KeyingMaterial *a2)
{
  BYTE *v4; // rax
  BYTE *v5; // rsi

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 111i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  *a2 = 0i64;
  if ( *((_QWORD *)a1 + 53) )
  {
    v4 = (BYTE *)LocalAlloc(0x40u, *((unsigned int *)a1 + 104));
    v5 = v4;
    if ( !v4 )
      return 2148074240i64;
    memcpy_0(v4, *((const void **)a1 + 53), *((unsigned int *)a1 + 104));
    a2->cbKeyingMaterial = *((_DWORD *)a1 + 104);
    a2->pbKeyingMaterial = v5;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
