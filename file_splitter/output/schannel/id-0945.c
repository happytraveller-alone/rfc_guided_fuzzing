// File count: 945
// Total lines: 41
-----------------------------------------
__int64 __fastcall SetMtuCallback(struct CSslUserContext *a1, char a2, struct _SecBuffer *a3)
{
  unsigned int cbBuffer; // r9d
  _WORD *pvBuffer; // rax
  char v6; // si
  _WORD *v7; // r8
  unsigned int v8; // eax
  unsigned int v9; // edi

  cbBuffer = a3->cbBuffer;
  pvBuffer = a3->pvBuffer;
  v6 = a2 & 8;
  v7 = pvBuffer + 4;
  if ( cbBuffer <= 4 )
    v7 = pvBuffer;
  v8 = cbBuffer - 8;
  if ( cbBuffer <= 4 )
    v8 = cbBuffer;
  if ( v8 == 4 )
  {
    v9 = 0;
    *((_WORD *)a1 + 68) = *v7;
    *((_WORD *)a1 + 69) = v7[1];
  }
  else
  {
    v9 = -2146892963;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 136i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  }
  if ( v6 )
  {
    SPExternalFree(a3->pvBuffer);
    a3->pvBuffer = 0i64;
    a3->cbBuffer = 0;
    a3->BufferType = 0;
  }
  return v9;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
