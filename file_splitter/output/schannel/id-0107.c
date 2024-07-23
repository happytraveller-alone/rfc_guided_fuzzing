// File count: 107
// Total lines: 238
----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::PackClientHello(
        CSsl3TlsClientContext *this,
        struct _Ssl2_Client_Hello *a2,
        struct SPBuffer *a3)
{
  unsigned int v6; // esi
  char v7; // al
  bool v8; // cf
  unsigned int v9; // eax
  __int64 v10; // rcx
  int v11; // r14d
  unsigned int ClientHelloExtensionsLength; // ebx
  char v13; // dl
  unsigned int v14; // r14d
  unsigned int v15; // r15d
  unsigned int v16; // ecx
  unsigned int v17; // r15d
  unsigned int v18; // r15d
  unsigned int v19; // esi
  _BYTE *v20; // rsi
  _BYTE *v21; // rsi
  __int64 v22; // rdx
  int v23; // ecx
  _BYTE *v24; // rsi
  _BYTE *i; // rsi
  _BYTE *v26; // rsi
  char v27; // al
  unsigned int v28; // eax
  __int64 v29; // rcx
  HLOCAL Memory; // rax
  __int64 v32; // rcx
  _BYTE *v33; // rsi
  __int16 v34; // cx
  _BYTE *v35; // rdx
  __int16 v36; // [rsp+20h] [rbp-60h]
  int v37; // [rsp+28h] [rbp-58h]
  unsigned int v38; // [rsp+30h] [rbp-50h]
  unsigned int Size; // [rsp+34h] [rbp-4Ch]
  unsigned int Size_4; // [rsp+38h] [rbp-48h]
  unsigned int v41; // [rsp+3Ch] [rbp-44h]
  __int64 v42[3]; // [rsp+40h] [rbp-40h] BYREF
  int v43; // [rsp+58h] [rbp-28h]
  char v44; // [rsp+60h] [rbp-20h]
  __int64 v45; // [rsp+68h] [rbp-18h]
  int v46; // [rsp+70h] [rbp-10h]
  char v47; // [rsp+74h] [rbp-Ch]
  CSsl3TlsClientContext *v48; // [rsp+78h] [rbp-8h]
  unsigned __int8 v49; // [rsp+C0h] [rbp+40h]
  unsigned int v50; // [rsp+D8h] [rbp+58h] BYREF

  v42[1] = (__int64)this;
  v42[2] = 0i64;
  v42[0] = (__int64)&CTlsExtClient::`vftable';
  v43 = 0;
  v44 = 0;
  v45 = 0i64;
  v6 = 0;
  v46 = 0;
  v48 = this;
  v47 = *((_BYTE *)this + 922);
  v7 = *((_BYTE *)this + 233);
  Size = 0;
  v50 = 0;
  if ( !v7 && (*((_BYTE *)this + 32) & 4) != 0 )
    v38 = *((_DWORD *)this + 11);
  else
    v38 = 0;
  v8 = v7 != 0;
  v49 = 0;
  v9 = *((_DWORD *)this + 15);
  v10 = *((_QWORD *)this + 165);
  Size_4 = v9;
  v11 = v8 ? 12 : 4;
  v41 = v11;
  if ( v10 )
    RtlAcquireResourceShared((PRTL_RESOURCE)(v10 + 72), 1u);
  ClientHelloExtensionsLength = CTlsExtClient::GetClientHelloExtensionsLength((CTlsExtClient *)v42, &v50);
  if ( ClientHelloExtensionsLength )
    goto LABEL_42;
  v13 = *((_BYTE *)this + 233);
  if ( v13 )
  {
    if ( *((_DWORD *)this + 327) )
    {
      v6 = *((unsigned __int8 *)this + 1312);
      Size = v6;
    }
    else
    {
      Size = 0;
    }
  }
  v14 = v50 + v11 + 2 * *((_DWORD *)a2 + 1) + *((_DWORD *)a2 + 2) + 39;
  if ( v13 )
    v14 += v6 + 1;
  if ( (*((_DWORD *)this + 16) & 0x2A88) == 0 && (*((_BYTE *)this + 64) & 0x20) != 0 && !v50 )
  {
    v14 += 2;
    v49 = 1;
  }
  v15 = v14;
  if ( v13 )
  {
    v19 = Size_4;
    v18 = v14 + Size_4;
  }
  else
  {
    if ( (*((_BYTE *)this + 32) & 4) != 0 )
    {
      v16 = *((_DWORD *)this + 13);
      v17 = v14 + *((_DWORD *)this + 12);
      if ( v16 )
      {
        if ( (*((_BYTE *)this + 56) & 1) != 0 )
          v16 -= v17 % v16;
        v17 += v16;
      }
      v15 = *((_DWORD *)this + 11) + v17;
    }
    v18 = *((_DWORD *)this + 15) + v15;
    v19 = Size_4;
  }
  ClientHelloExtensionsLength = CSsl3TlsContext::AllocateOutputBuffer(this, a3, v18);
  if ( ClientHelloExtensionsLength )
  {
LABEL_42:
    v32 = *((_QWORD *)this + 165);
    if ( v32 )
      RtlReleaseResource((PRTL_RESOURCE)(v32 + 72));
  }
  else
  {
    v20 = (_BYTE *)(*((_QWORD *)a3 + 1) + v19 + v38 + (unsigned __int64)v41);
    *v20++ = *((_BYTE *)a2 + 1);
    *v20++ = *(_BYTE *)a2;
    *(_OWORD *)v20 = *((_OWORD *)a2 + 3);
    *((_OWORD *)v20 + 1) = *((_OWORD *)a2 + 4);
    v20 += 32;
    *v20++ = *((_BYTE *)a2 + 8);
    memcpy_0(v20, (char *)a2 + 16, *((unsigned int *)a2 + 2));
    v21 = &v20[*((unsigned int *)a2 + 2)];
    if ( *((_BYTE *)this + 233) )
    {
      *v21++ = Size;
      if ( *((_DWORD *)this + 327) && Size )
      {
        memcpy_0(v21, (char *)this + 1052, Size);
        v21 += Size;
      }
      else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
             && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_13477250810f3961702f89c94d47ffd6_Traceguids);
      }
    }
    v22 = 0i64;
    v23 = 2 * (*((_DWORD *)a2 + 1) + v49);
    *v21 = (unsigned __int16)(*((_WORD *)a2 + 2) + v49) >> 7;
    v24 = v21 + 1;
    *v24 = v23;
    for ( i = v24 + 1; (unsigned int)v22 < *((_DWORD *)a2 + 1); i = v26 + 1 )
    {
      *i = *((_BYTE *)a2 + 4 * v22 + 81);
      v26 = i + 1;
      v27 = *((_BYTE *)a2 + 4 * v22 + 80);
      v22 = (unsigned int)(v22 + 1);
      *v26 = v27;
    }
    if ( v49 )
    {
      *i = 0;
      v33 = i + 1;
      *v33 = -1;
      i = v33 + 1;
    }
    *i = 1;
    i[1] = 0;
    v28 = CTlsExtClient::BuildClientHelloExtension((CTlsExtClient *)v42, v50, i + 2, &v50);
    v29 = *((_QWORD *)this + 165);
    ClientHelloExtensionsLength = v28;
    if ( v29 )
      RtlReleaseResource((PRTL_RESOURCE)(v29 + 72));
    if ( !ClientHelloExtensionsLength )
    {
      v37 = *((unsigned __int8 *)this + 233);
      v36 = *((_WORD *)this + 110);
      *((_WORD *)this + 110) = v36 + 1;
      SetHandshakeHeader(
        *((_QWORD *)a3 + 1) + v38 + (unsigned __int64)Size_4,
        1,
        0i64,
        (unsigned __int16)(v14 - v41),
        v36,
        v37);
      if ( *((_QWORD *)this + 110) )
      {
        (*(void (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)this + 16i64))(this);
        *((_QWORD *)this + 110) = 0i64;
      }
      *((_DWORD *)this + 218) = v14;
      Memory = CSslContext::GetMemory(this, v14);
      *((_QWORD *)this + 110) = Memory;
      if ( Memory )
      {
        memcpy_0(
          Memory,
          (const void *)(*((_QWORD *)a3 + 1) + v38 + (unsigned __int64)Size_4),
          *((unsigned int *)this + 218));
        if ( *((_BYTE *)this + 233) )
        {
          v34 = *((_WORD *)this + 17);
          ClientHelloExtensionsLength = 0;
          v35 = (_BYTE *)*((_QWORD *)a3 + 1);
          v35[12] = v14;
          v35[11] = BYTE1(v14);
          v35[1] = HIBYTE(v34);
          v35[2] = v34;
          *v35 = 22;
          *((_DWORD *)a3 + 1) += v18;
        }
        else
        {
          ClientHelloExtensionsLength = CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a3, 22, v14);
        }
      }
      else
      {
        ClientHelloExtensionsLength = 14;
      }
    }
  }
  CTlsExtClient::~CTlsExtClient((CTlsExtClient *)v42);
  return ClientHelloExtensionsLength;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18007D048: using guessed type void *CTlsExtClient::`vftable';
