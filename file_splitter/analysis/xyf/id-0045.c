//----- (0000000180003E7C) ----------------------------------------------------
void __fastcall CSsl3TlsContext::FreeSelectedTBParameters(CSsl3TlsContext *this)
{
  __int64 v1; // rdx

  v1 = *((_QWORD *)this + 103);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 8) )
    {
      (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(this, *(_QWORD *)(v1 + 8));
      v1 = *((_QWORD *)this + 103);
    }
    (*(void (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 16i64))(this, v1);
    *((_QWORD *)this + 103) = 0i64;
  }
}

