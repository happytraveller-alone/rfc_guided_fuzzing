//----- (000000018005B3A0) ----------------------------------------------------
signed int __fastcall CSslContext::QueryContextAttributesA(CSslContext *this, int a2, void *a3)
{
  __int64 v5; // rax

  switch ( a2 )
  {
    case 6:
      return CSslContext::QueryAuthority(this, a3);
    case 82:
      return CSslContext::QueryLocalCred(this, a3);
    case 84:
      v5 = (*(__int64 (__fastcall **)(CSslContext *))(*(_QWORD *)this + 248i64))(this);
      if ( v5 )
        return SslTransferCertChainToClientProcess((PCCERT_CONTEXT *)a3, *(const struct _CERT_CONTEXT **)(v5 + 32));
      else
        return -2146893042;
    case 94:
      return CSslContext::QueryAppData(this, a3);
    default:
      return 120;
  }
}

