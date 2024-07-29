//----- (000000018005D4E8) ----------------------------------------------------
__int64 __fastcall CSessionCacheItem::DeserializeTicketNonce(
        CSessionCacheItem *this,
        unsigned __int8 *a2,
        unsigned __int8 a3)
{
  size_t v4; // rbx
  HLOCAL v7; // rax

  v4 = a3;
  if ( *((_QWORD *)this + 25) || *((_BYTE *)this + 208) )
    return 1359i64;
  if ( !a3 )
    return 0i64;
  if ( !a2 )
    return 87i64;
  v7 = SPExternalAlloc(a3);
  *((_QWORD *)this + 25) = v7;
  if ( v7 )
  {
    memcpy_0(v7, a2, v4);
    *((_BYTE *)this + 208) = v4;
    return 0i64;
  }
  return 14i64;
}

