// File count: 19
// Total lines: 33
------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::CheckForClientCertificatePrivateKeys(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2)
{
  __int64 result; // rax

  if ( !a2 )
    return 87i64;
  result = 0i64;
  *a2 = 0;
  if ( *((_BYTE *)this + 923) )
  {
    result = CSsl3TlsClientContext::CheckForClientCred(this);
    if ( *((_BYTE *)this + 923) )
    {
      *((_DWORD *)this + 18) = *((_DWORD *)this + 17);
      result = 590610i64;
      *((_DWORD *)this + 17) = 77;
    }
    else if ( *((_BYTE *)this + 924) || (_DWORD)result != -2146893024 )
    {
      if ( !(_DWORD)result || (_DWORD)result == 590624 || (_DWORD)result == -2146893024 )
        return result;
    }
    else
    {
      result = 590624i64;
    }
    *a2 = 1;
  }
  return result;
}
