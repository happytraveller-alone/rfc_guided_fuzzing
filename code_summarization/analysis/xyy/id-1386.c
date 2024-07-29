//----- (000000018006E940) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::QueryKeyingMaterial(CTls13ServerContext *this, void *a2)
{
  __int64 *v2; // rax
  __int64 v4; // rdx

  v2 = (__int64 *)*((_QWORD *)this + 1);
  if ( v2 )
    v4 = *v2;
  else
    v4 = 0i64;
  return CSsl3TlsContext::QueryKeyingMaterialCommon(this, v4, *((_QWORD *)this + 137), 0i64, 0, a2);
}

