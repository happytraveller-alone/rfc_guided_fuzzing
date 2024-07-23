// File count: 1427
// Total lines: 16
----------------------------------------
__int64 __fastcall CSslContext::RsaGenerateClientExchangeValue(
        CSslContext *this,
        unsigned __int8 *a2,
        unsigned int *a3,
        unsigned __int8 *a4)
{
  unsigned __int8 *v4; // r9

  v4 = (unsigned __int8 *)*(unsigned int *)(*((_QWORD *)this + 1) + 52i64);
  if ( (_DWORD)v4 == 2 )
    return CSslContext::I_RsaGenerateClientExchangeValue(this, a2, a3, v4);
  if ( (_DWORD)v4 == 4 )
    return CSslContext::I_RsaGenerateEcdsaSignClientExchangeValue(this, a2, a3);
  return 2148074248i64;
}
