// File count: 359
// Total lines: 12
-----------------------------------------
void __fastcall CSsl3TlsClientContext::GetCertOcspInfo(
        CSsl3TlsClientContext *this,
        unsigned __int8 **a2,
        unsigned int *a3)
{
  __int64 v3; // r9

  v3 = *((_QWORD *)this + 165);
  *a3 = *(_DWORD *)(v3 + 344);
  *a2 = *(unsigned __int8 **)(v3 + 336);
}
