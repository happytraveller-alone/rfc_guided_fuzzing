//----- (000000018004E9A4) ----------------------------------------------------
__int64 __fastcall SpQuerySrtpParameters(struct CSslUserContext *a1, struct _SecPkgContext_SrtpParameters *a2)
{
  struct _SecPkgContext_SrtpParameters *v2; // rbx
  BYTE *v4; // rsi
  PBYTE MasterKeyIdentifier; // rbp
  SIZE_T MasterKeyIdentifierSize; // r14
  BYTE *v7; // rax

  v2 = (struct _SecPkgContext_SrtpParameters *)*((_QWORD *)a1 + 50);
  v4 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 109i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  if ( v2 )
  {
    MasterKeyIdentifier = v2->MasterKeyIdentifier;
    if ( MasterKeyIdentifier )
    {
      MasterKeyIdentifierSize = v2->MasterKeyIdentifierSize;
      v7 = (BYTE *)LocalAlloc(0x40u, MasterKeyIdentifierSize);
      v4 = v7;
      if ( !v7 )
        return 2148074240i64;
      memcpy_0(v7, MasterKeyIdentifier, MasterKeyIdentifierSize);
    }
    *a2 = *v2;
    a2->MasterKeyIdentifier = v4;
  }
  else
  {
    *a2 = 0i64;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
