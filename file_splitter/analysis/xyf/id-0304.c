//----- (0000000180016C58) ----------------------------------------------------
__int64 __fastcall SpQueryTokenBinding(struct CSslUserContext *a1, struct _SecPkgContext_TokenBinding *a2)
{
  struct _SecPkgContext_TokenBinding *v2; // rbx
  BYTE *v4; // rsi
  PBYTE KeyParameters; // rbp
  SIZE_T KeyParametersSize; // r14
  BYTE *v8; // rax

  v2 = (struct _SecPkgContext_TokenBinding *)*((_QWORD *)a1 + 51);
  v4 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 110i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  if ( !v2 )
  {
    *a2 = 0i64;
    return 0i64;
  }
  KeyParameters = v2->KeyParameters;
  if ( !KeyParameters )
  {
LABEL_11:
    *a2 = *v2;
    a2->KeyParameters = v4;
    return 0i64;
  }
  KeyParametersSize = v2->KeyParametersSize;
  v8 = (BYTE *)LocalAlloc(0x40u, KeyParametersSize);
  v4 = v8;
  if ( v8 )
  {
    memcpy_0(v8, KeyParameters, KeyParametersSize);
    goto LABEL_11;
  }
  return 2148074240i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

