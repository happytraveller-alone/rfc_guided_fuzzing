//----- (0000000180004900) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::DigestServerKeyX(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *a4)
{
  unsigned int *v7; // rdi
  int v8; // ecx
  __int64 result; // rax
  unsigned __int8 *v10; // rax
  unsigned __int8 *v11; // r9
  int v12; // ecx

  *((_QWORD *)this + 17) |= 0x8000ui64;
  v7 = (unsigned int *)((char *)this + 960);
  v8 = *(_DWORD *)(*((_QWORD *)this + 1) + 48i64);
  switch ( v8 )
  {
    case 3:
      result = CSsl3TlsClientContext::EccGenerateClientExchangeValue(this, a2, a3, 0i64, v7);
      break;
    case 2:
      result = CSsl3TlsClientContext::DhGenerateClientExchangeValue(this, a2, a3, 0i64, v7);
      break;
    case 4:
      result = CSsl3TlsClientContext::PskGenerateClientExchangeValue(this, a2, a3, 0i64, v7);
      break;
    default:
      result = CSslContext::RsaGenerateClientExchangeValue(this, 0i64, v7, a4);
      break;
  }
  if ( !(_DWORD)result )
  {
    v10 = (unsigned __int8 *)SPExternalAlloc(*v7);
    *((_QWORD *)this + 119) = v10;
    if ( v10 )
    {
      v12 = *(_DWORD *)(*((_QWORD *)this + 1) + 48i64);
      switch ( v12 )
      {
        case 3:
          return CSsl3TlsClientContext::EccGenerateClientExchangeValue(this, a2, a3, v10, v7);
        case 2:
          return CSsl3TlsClientContext::DhGenerateClientExchangeValue(this, a2, a3, v10, v7);
        case 4:
          return CSsl3TlsClientContext::PskGenerateClientExchangeValue(this, a2, a3, v10, v7);
        default:
          return CSslContext::RsaGenerateClientExchangeValue(this, v10, v7, v11);
      }
    }
    else
    {
      return 14i64;
    }
  }
  return result;
}
// 18002CF53: variable 'v11' is possibly undefined

