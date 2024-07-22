//----- (000000018005D574) ----------------------------------------------------
__int64 __fastcall CSessionCacheItem::GetCacheAppData(CSessionCacheItem *this, unsigned __int8 **a2, unsigned int *a3)
{
  unsigned int v5; // ecx
  unsigned __int8 *v6; // rax

  if ( *((_QWORD *)this + 7) )
  {
    v5 = *((_DWORD *)this + 16);
    *a3 = v5;
    v6 = (unsigned __int8 *)SPExternalAlloc(v5);
    *a2 = v6;
    if ( !v6 )
      return 14i64;
    memcpy_0(v6, *((const void **)this + 7), *((unsigned int *)this + 16));
  }
  else
  {
    *a2 = 0i64;
    *a3 = 0;
  }
  return 0i64;
}

