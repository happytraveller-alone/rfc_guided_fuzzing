//----- (000000018005DA48) ----------------------------------------------------
__int64 __fastcall CSessionCacheItem::SerializeTicketNonce(
        CSessionCacheItem *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *a4)
{
  const void *v8; // rdx

  if ( !a2 && a3 || !a4 )
    return 87i64;
  v8 = (const void *)*((_QWORD *)this + 25);
  if ( v8 )
  {
    if ( a3 < *((unsigned __int8 *)this + 208) )
      return 122i64;
    memcpy_0(a2, v8, *((unsigned __int8 *)this + 208));
    *a4 = *((_BYTE *)this + 208);
  }
  else
  {
    *a4 = 0;
  }
  return 0i64;
}

