// File count: 373
// Total lines: 5
------------------------------------------
struct _SEC_PRESHAREDKEY_IDENTITY *__fastcall CSsl3TlsContext::GetPSKExchangeValue(CSsl3TlsContext *this)
{
  return (struct _SEC_PRESHAREDKEY_IDENTITY *)*((_QWORD *)this + 108);
}
