// File count: 365
// Total lines: 12
-----------------------------------------
void __fastcall CSsl3TlsClientContext::GetEndpointBindings(
        CSsl3TlsClientContext *this,
        unsigned __int8 **a2,
        unsigned int *a3)
{
  __int64 v3; // r9

  v3 = *((_QWORD *)this + 165);
  *a2 = *(unsigned __int8 **)(v3 + 400);
  *a3 = *(_DWORD *)(v3 + 408);
}
