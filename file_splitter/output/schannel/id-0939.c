//----- (000000018004E0FC) ----------------------------------------------------
__int64 __fastcall GetAppDataStatusCallback(
        struct CSslUserContext *a1,
        void *(__stdcall *a2)(unsigned int),
        void (__stdcall *a3)(void *),
        char a4,
        struct _SecBuffer *a5)
{
  _BYTE *v6; // rax
  unsigned int v7; // ebx
  _BYTE *v8; // rdx
  unsigned int v9; // esi
  char v10; // al
  __int64 result; // rax

  if ( (a4 & 8) != 0 )
    v6 = SPExternalAlloc(1u);
  else
    v6 = PvExtVirtualAlloc(1u);
  v7 = 0;
  v8 = v6;
  if ( v6 )
  {
    v10 = *((_BYTE *)a1 + 140);
    v9 = 0;
    *v8 = v10;
    a5->pvBuffer = v8;
    v7 = 1;
  }
  else
  {
    v9 = -2146893056;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 137i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  }
  a5->BufferType = v7;
  result = v9;
  a5->cbBuffer = v7;
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

