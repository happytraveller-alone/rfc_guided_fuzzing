//----- (0000000180055C40) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::DuplicateIssuerList(
        CCredentialGroup *this,
        unsigned __int8 **a2,
        unsigned int *a3)
{
  struct _RTL_RESOURCE *v6; // rdi
  unsigned int v7; // ecx
  unsigned __int8 *v8; // rax

  if ( !a2 || !a3 )
    return 87i64;
  *a2 = 0i64;
  v6 = (struct _RTL_RESOURCE *)((char *)this + 48);
  *a3 = 0;
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
  if ( *((_QWORD *)this + 108) )
  {
    v7 = *((_DWORD *)this + 214);
    if ( v7 )
    {
      v8 = (unsigned __int8 *)SPExternalAlloc(v7);
      *a2 = v8;
      if ( !v8 )
      {
        RtlReleaseResource(v6);
        return 14i64;
      }
      memcpy_0(v8, *((const void **)this + 108), *((unsigned int *)this + 214));
      *a3 = *((_DWORD *)this + 214);
    }
  }
  RtlReleaseResource(v6);
  return 0i64;
}

