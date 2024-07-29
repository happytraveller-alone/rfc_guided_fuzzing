//----- (000000018005D7B0) ----------------------------------------------------
__int64 __fastcall CSessionCacheServerItem::Serialize(
        CSessionCacheServerItem *this,
        struct CSslContext *a2,
        unsigned __int8 *a3,
        unsigned int a4,
        unsigned int *a5)
{
  unsigned int v10; // ebx
  __int64 v11; // rdx
  unsigned int v12; // esi
  unsigned __int8 *v13; // rcx
  unsigned __int8 *v14; // rdx
  __int64 v15; // rax

  if ( !a2 || !a3 || !a5 )
    return 87i64;
  if ( a4 < 0x28 )
    return 122i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 72), 1u);
  *(_DWORD *)a3 = 0;
  GetSystemTimeAsFileTime((LPFILETIME)a3 + 3);
  *((_DWORD *)a3 + 1) = 32;
  v10 = CSessionCacheItem::Serialize(this, a2, a3 + 32, a4 - 32, (unsigned int *)a3 + 2);
  if ( !v10 )
  {
    v11 = (unsigned int)(*((_DWORD *)a3 + 1) + *((_DWORD *)a3 + 2));
    *((_DWORD *)a3 + 3) = v11;
    if ( a4 < (unsigned int)v11 )
    {
LABEL_8:
      v10 = 122;
      goto LABEL_18;
    }
    v12 = a4 - v11;
    v13 = a3 + 16;
    v14 = &a3[v11];
    if ( !v14 && v12 || a3 == (unsigned __int8 *)-16i64 )
    {
      v10 = 87;
      goto LABEL_18;
    }
    v15 = *((_QWORD *)this + 42);
    if ( v15 )
    {
      if ( v12 < 0x14 )
        goto LABEL_8;
      *(_OWORD *)v14 = *(_OWORD *)(v15 + 40);
      *((_DWORD *)v14 + 4) = *(_DWORD *)(v15 + 56);
      *(_DWORD *)v13 = 20;
    }
    else
    {
      *(_DWORD *)v13 = 0;
    }
    v10 = 0;
  }
LABEL_18:
  RtlReleaseResource((PRTL_RESOURCE)((char *)this + 72));
  if ( !v10 )
    *a5 = *((_DWORD *)a3 + 3) + *((_DWORD *)a3 + 4);
  return v10;
}

