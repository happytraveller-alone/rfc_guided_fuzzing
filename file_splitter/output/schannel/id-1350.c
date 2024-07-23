// File count: 1350
// Total lines: 16
----------------------------------------
unsigned int __fastcall CTls13ClientContext::DetermineClientCredentialStatus(CTls13ClientContext *this)
{
  unsigned int result; // eax

  result = 0;
  *((_BYTE *)this + 924) = 0;
  if ( *((_BYTE *)this + 1314) )
  {
    result = CSsl3TlsClientContext::CheckForClientCred(this);
    *((_BYTE *)this + 1314) = 0;
  }
  if ( *((_BYTE *)this + 1313) )
    return 590624;
  return result;
}
