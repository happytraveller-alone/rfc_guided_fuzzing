//----- (000000018000A1D0) ----------------------------------------------------
HLOCAL __fastcall CSslContext::GetMemory(CSslContext *this, unsigned int a2)
{
  __int64 v2; // rcx

  v2 = *(_QWORD *)(*((_QWORD *)this + 16) + 24i64);
  if ( v2 )
    return (HLOCAL)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 48i64))(v2);
  else
    return SPExternalAlloc(a2);
}

