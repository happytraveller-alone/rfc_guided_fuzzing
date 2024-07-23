// File count: 953
// Total lines: 82
-----------------------------------------
__int64 __fastcall SpQueryUniqueBindings(struct CSslUserContext *a1, struct _SecPkgContext_Bindings *a2)
{
  unsigned int v5; // ebx
  SEC_CHANNEL_BINDINGS *v6; // rax
  SEC_CHANNEL_BINDINGS *Bindings; // rcx
  int v8; // [rsp+20h] [rbp-18h]
  int v9; // [rsp+20h] [rbp-18h]
  int v10; // [rsp+20h] [rbp-18h]
  int v11; // [rsp+20h] [rbp-18h]
  size_t Size; // [rsp+40h] [rbp+8h] BYREF
  void *Src; // [rsp+48h] [rbp+10h] BYREF

  (*(void (__fastcall **)(struct CSslUserContext *, void **, size_t *))(*(_QWORD *)a1 + 80i64))(a1, &Src, &Size);
  a2->BindingsLength = 0;
  a2->Bindings = 0i64;
  if ( (*((_BYTE *)a1 + 24) & 0xC) != 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
    {
      v8 = -2146893054;
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x68u,
        (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
        -2146893054,
        v8);
    }
    return 2148074242i64;
  }
  if ( Src && (_DWORD)Size )
  {
    v5 = Size + 43;
    if ( (int)Size + 43 < (unsigned int)Size )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      {
        v9 = -2146893052;
        WPP_SF_DD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x69u,
          (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
          -2146893052,
          v9);
      }
      return 2148074244i64;
    }
    v6 = (SEC_CHANNEL_BINDINGS *)LocalAlloc(0x40u, v5);
    a2->Bindings = v6;
    if ( !v6 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      {
        v10 = -2146893056;
        WPP_SF_DD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x6Au,
          (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
          -2146893056,
          v10);
      }
      return 2148074240i64;
    }
    v6->cbApplicationDataLength = Size + 11;
    a2->Bindings->dwApplicationDataOffset = 32;
    Bindings = a2->Bindings;
    qmemcpy(&Bindings[1], "tls-unique:", 11);
    memcpy_0((char *)&Bindings[1].dwInitiatorOffset + 3, Src, (unsigned int)Size);
    a2->BindingsLength = v5;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v11 = 0;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x6Bu,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      0,
      v11);
  }
  return 0i64;
}
