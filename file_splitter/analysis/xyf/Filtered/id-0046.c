//----- (0000000180003EA4) ----------------------------------------------------
void __fastcall CSsl3TlsContext::FreeSelectedSrtpParameters(CSsl3TlsContext *this)
{
  __int64 v1; // rdx

  v1 = *((_QWORD *)this + 101);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 8) )
    {
      (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(this, *(_QWORD *)(v1 + 8));
      v1 = *((_QWORD *)this + 101);
    }
    (*(void (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 16i64))(this, v1);
    *((_QWORD *)this + 101) = 0i64;
  }
}

