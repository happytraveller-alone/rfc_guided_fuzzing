//----- (000000018006F874) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::DtlsGetOutgoingRecord(
        CSsl3TlsContext *this,
        struct SPBuffer *a2,
        struct SPBuffer *a3)
{
  unsigned int v6; // esi

  if ( !*((_BYTE *)this + 233) || !a2 || !*((_QWORD *)a2 + 1) || !a3 )
    return 87i64;
  v6 = CSsl3TlsContext::FragmentOutgoingBuffer(this, a2);
  (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(this, *((_QWORD *)a2 + 1));
  *((_QWORD *)a2 + 1) = 0i64;
  *(_DWORD *)a2 = 0;
  *((_DWORD *)a2 + 1) = 0;
  if ( !v6 )
    return (unsigned int)CSsl3TlsContext::PrepareNextOutgoingRecord(this, a3);
  return v6;
}

