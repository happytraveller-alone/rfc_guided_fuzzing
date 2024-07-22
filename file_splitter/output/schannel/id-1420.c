//----- (0000000180070D50) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::GenerateRsaCkeParameterList(
        CSsl3TlsClientContext *this,
        struct _BCryptBufferDesc *a2,
        unsigned __int8 *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned __int64 *a6)
{
  unsigned int v6; // ebp
  unsigned int *v7; // rsi
  NCRYPT_HANDLE *v10; // r14
  unsigned int v11; // r8d
  PBCryptBuffer pBuffers; // rbx
  ULONG cBuffers; // r12d
  unsigned __int8 *v14; // rdx
  unsigned int v15; // r15d
  __int64 result; // rax
  char v17; // al
  __int64 v18; // rax
  NCRYPT_HANDLE v19; // [rsp+68h] [rbp+10h] BYREF

  v19 = 0i64;
  v6 = 0;
  v7 = a5;
  if ( !a2 )
    return 87i64;
  if ( !a5 )
    return 87i64;
  v10 = a6;
  if ( !a6 )
    return 87i64;
  v11 = *((_DWORD *)this + 244);
  pBuffers = a2->pBuffers;
  cBuffers = a2->cBuffers;
  if ( !v11 || (v14 = (unsigned __int8 *)*((_QWORD *)this + 121)) == 0i64 )
  {
LABEL_12:
    if ( (*((_DWORD *)this + 34) & 0x8000000) == 0 )
    {
      v6 = 2;
      if ( cBuffers < 2 )
        return 87i64;
      pBuffers->BufferType = 20;
      pBuffers->pvBuffer = (char *)this + 272;
      pBuffers->cbBuffer = 32;
      pBuffers[1].pvBuffer = (char *)this + 304;
      pBuffers[1].BufferType = 21;
      pBuffers[1].cbBuffer = 32;
    }
    if ( cBuffers >= v6 + 1 )
    {
      v17 = *((_BYTE *)this + 233);
      if ( v17 )
      {
        if ( *v7 >= 0xFEFD )
          goto LABEL_21;
      }
      else if ( *v7 <= 0x303 )
      {
LABEL_21:
        v18 = v6;
        pBuffers[v18].BufferType = 22;
        pBuffers[v18].cbBuffer = 4;
        pBuffers[v18].pvBuffer = v7;
        result = 0i64;
        a2->cBuffers = v6 + 1;
        return result;
      }
      *v7 = v17 != 0 ? 65277 : 771;
      goto LABEL_21;
    }
    return 87i64;
  }
  v15 = CSsl3TlsClientContext::ParseRsaServerKeyExchange(this, v14, v11, *a6, &v19);
  if ( !v15 )
  {
    NCryptFreeObject(*v10);
    *v10 = v19;
    goto LABEL_12;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_ef2bc8f963c43ddcdfece7ee9e95f200_Traceguids, v15);
  return v15;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

