//----- (000000018004E694) ----------------------------------------------------
__int64 __fastcall SpQueryNegotiatedTlsExtensions(
        struct CSslUserContext *a1,
        struct _SecPkgContext_NegotiatedTlsExtensions *a2)
{
  __int64 v4; // rax
  bool v5; // zf
  __int64 v6; // rax
  unsigned int v7; // ebx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  unsigned __int16 *v12; // rax
  unsigned __int16 *v13; // rdi
  __int64 Src; // [rsp+20h] [rbp-28h] BYREF
  int v16; // [rsp+28h] [rbp-20h]

  Src = 0i64;
  v16 = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 113i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  v4 = *((_QWORD *)a1 + 2) & 0x20000i64;
  if ( (*((_QWORD *)a1 + 2) & 0x20000) != 0 )
    LOWORD(Src) = 5;
  v5 = v4 == 0;
  v6 = *((_QWORD *)a1 + 49);
  v7 = !v5;
  if ( v6 && *(_DWORD *)(v6 + 4) == 2 )
  {
    v7 = !v5 + 1;
    *((_WORD *)&Src + !v5) = 16;
  }
  if ( *((_QWORD *)a1 + 50) )
  {
    v8 = v7++;
    *((_WORD *)&Src + v8) = 14;
  }
  if ( *((_QWORD *)a1 + 51) )
  {
    v9 = v7++;
    *((_WORD *)&Src + v9) = 24;
  }
  if ( (*((_QWORD *)a1 + 2) & 0x8000000i64) != 0 )
  {
    v10 = v7++;
    *((_WORD *)&Src + v10) = 23;
  }
  if ( *((_BYTE *)a1 + 32) )
  {
    v11 = v7++;
    *((_WORD *)&Src + v11) = -255;
  }
  if ( v7 )
  {
    v12 = (unsigned __int16 *)LocalAlloc(0x40u, 2 * v7);
    v13 = v12;
    if ( !v12 )
      return 2148074240i64;
    memcpy_0(v12, &Src, 2 * v7);
    a2->Extensions = v13;
    a2->ExtensionsCount = v7;
  }
  else
  {
    *a2 = 0i64;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
