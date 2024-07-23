//----- (0000000180014D20) ----------------------------------------------------
unsigned __int64 __fastcall CSsl3TlsContext::GetHandshakeHash(CSsl3TlsContext *this, enum _eTlsHashAlgorithm a2)
{
  if ( a2 )
    return CSsl3TlsContext::FindTlsClientAuthHandshakeHash(this, a2);
  else
    return *((_QWORD *)this + 74);
}

