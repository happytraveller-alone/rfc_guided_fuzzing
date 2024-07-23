// File count: 361
// Total lines: 12
-----------------------------------------
void __fastcall CSsl3TlsClientContext::GetCertSerialChain(
        CSsl3TlsClientContext *this,
        const unsigned __int8 **a2,
        unsigned int *a3)
{
  __int64 v3; // r9

  v3 = *((_QWORD *)this + 165);
  *a3 = *(_DWORD *)(v3 + 360);
  *a2 = *(const unsigned __int8 **)(v3 + 352);
}
