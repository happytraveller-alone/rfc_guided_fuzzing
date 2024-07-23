// File count: 178
// Total lines: 75
-----------------------------------------
__int64 __fastcall SpQueryEndpointBindings(struct CSslUserContext *a1, struct _SecPkgContext_Bindings *a2)
{
  unsigned __int8 *v2; // rdi
  unsigned int v4; // ebx
  unsigned __int8 *v5; // rbp
  unsigned int v6; // ebx
  unsigned int v7; // r14d
  SEC_CHANNEL_BINDINGS *v8; // rax
  SEC_CHANNEL_BINDINGS *Bindings; // rcx
  unsigned int v11; // [rsp+50h] [rbp+8h] BYREF
  unsigned __int8 *v12; // [rsp+58h] [rbp+10h] BYREF

  v2 = 0i64;
  a2->BindingsLength = 0;
  a2->Bindings = 0i64;
  if ( (*((_BYTE *)a1 + 24) & 0xC) != 0 )
  {
    v6 = -2146893054;
    goto LABEL_13;
  }
  v4 = *((_DWORD *)a1 + 60);
  v5 = (unsigned __int8 *)*((_QWORD *)a1 + 29);
  v12 = v5;
  v11 = v4;
  if ( !v4 )
  {
    v6 = GenerateRemoteEndpointBindingsHash((__int64)a1, &v12, &v11);
    if ( v6 )
      goto LABEL_13;
    v2 = v12;
    v4 = v11;
    v5 = v12;
  }
  if ( !v5 || !v4 )
    goto LABEL_10;
  v7 = v4 + 53;
  if ( v4 + 53 < v4 )
  {
    v6 = -2146893052;
  }
  else
  {
    v8 = (SEC_CHANNEL_BINDINGS *)LocalAlloc(0x40u, v7);
    a2->Bindings = v8;
    if ( v8 )
    {
      v8->cbApplicationDataLength = v4 + 21;
      a2->Bindings->dwApplicationDataOffset = 32;
      Bindings = a2->Bindings;
      qmemcpy(&Bindings[1], "tls-server-end-point:", 21);
      memcpy_0((char *)&Bindings[1].dwAcceptorOffset + 1, v5, v4);
      a2->BindingsLength = v7;
LABEL_10:
      v6 = 0;
      goto LABEL_11;
    }
    v6 = -2146893056;
  }
LABEL_11:
  if ( v2 )
    SPExternalFree(v2);
LABEL_13:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v6 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x67u,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      v6,
      v6);
  }
  return v6;
}
