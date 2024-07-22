//----- (0000000180022DB0) ----------------------------------------------------
void __fastcall CSsl3TlsServerContext::GetEndpointBindings(
        CSsl3TlsServerContext *this,
        unsigned __int8 **a2,
        unsigned int *a3)
{
  __int64 v6; // rax

  *a2 = 0i64;
  *a3 = 0;
  if ( (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 248i64))(this) )
  {
    v6 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 248i64))(this);
    *a2 = *(unsigned __int8 **)(v6 + 464);
    *a3 = *(_DWORD *)(v6 + 472);
  }
}

