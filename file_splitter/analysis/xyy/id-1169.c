//----- (000000018005DABC) ----------------------------------------------------
DWORD __fastcall CSessionCacheClientItem::UpdateRemoteEndpointBindings(CSessionCacheClientItem *this)
{
  unsigned __int8 **v2; // rdi
  void *v3; // rcx
  const struct _CERT_CONTEXT *v4; // rcx

  v2 = (unsigned __int8 **)((char *)this + 400);
  v3 = (void *)*((_QWORD *)this + 50);
  if ( v3 )
  {
    SPExternalFree(v3);
    *v2 = 0i64;
    *((_DWORD *)this + 102) = 0;
  }
  v4 = (const struct _CERT_CONTEXT *)*((_QWORD *)this + 6);
  if ( v4 )
    return GetCertEndpointBindings(v4, v2, (unsigned int *)this + 102);
  else
    return 0;
}

