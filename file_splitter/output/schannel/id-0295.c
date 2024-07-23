// File count: 295
// Total lines: 16
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::SetContextAttributesA(CSsl3TlsContext *this, int a2, void *a3, unsigned int a4)
{
  switch ( a2 )
  {
    case '"':
      return CSsl3TlsContext::SetSupportedMTU(this, a3, a4);
    case 'e':
      return CSsl3TlsContext::SetEapPrfType(this, a3, a4);
    case 'i':
      return CSsl3TlsContext::SetFalseStart(this, a3, a4);
    case 'j':
      return CSsl3TlsContext::SetKeyingMaterialInfo(this, a3, a4);
  }
  return CSslContext::SetContextAttributesA(this, a2, a3, a4);
}
