// File count: 1472
// Total lines: 15
----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::PskGenerateClientExchangeValue(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned int *a5)
{
  __int64 result; // rax

  result = CSsl3TlsContext::SetPSKExchangeValue(this, a2, a3, 1);
  if ( !(_DWORD)result )
    return PskGenerateExchangeValue(this, 1, a4, a5);
  return result;
}
