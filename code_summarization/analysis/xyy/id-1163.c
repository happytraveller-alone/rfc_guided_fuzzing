//----- (000000018005D630) ----------------------------------------------------
__int64 __fastcall CSessionCacheItem::Serialize(
        CSessionCacheItem *this,
        struct CSslContext *a2,
        unsigned __int8 *a3,
        unsigned int a4,
        unsigned int *a5)
{
  __int64 v8; // rax
  int v9; // ecx
  unsigned __int8 *v10; // r15
  __int64 result; // rax
  __int64 v12; // rdx
  __int64 v13; // rdx
  __int64 v14; // rdx

  if ( !a2 || !a3 || !a5 )
    return 87i64;
  if ( a4 < 0x44 )
    return 122i64;
  *(_DWORD *)a3 = 1;
  *((_DWORD *)a3 + 1) = *((_DWORD *)this + 2);
  *((_DWORD *)a3 + 8) = *((_DWORD *)this + 42);
  if ( (*((_BYTE *)a2 + 32) & 8) != 0 && (v8 = *((_QWORD *)a2 + 1)) != 0 )
    v9 = *(_DWORD *)(v8 + 28);
  else
    v9 = 0;
  *((_DWORD *)a3 + 9) = v9;
  v10 = a3 + 12;
  *((_DWORD *)a3 + 10) = *((_DWORD *)a2 + 4);
  *(_QWORD *)(a3 + 52) = *(_QWORD *)((char *)this + 188);
  *((_DWORD *)a3 + 11) = *((_DWORD *)this + 54);
  *((_DWORD *)a3 + 12) = *((_DWORD *)this + 55);
  *((_DWORD *)a3 + 2) = 65;
  result = CSessionCacheItem::SerializeNcryptMasterKey(this, a2, a3 + 65, a4 - 65, (unsigned int *)a3 + 3);
  if ( !(_DWORD)result )
  {
    v12 = (unsigned int)(*((_DWORD *)a3 + 2) + *(_DWORD *)v10);
    *((_DWORD *)a3 + 4) = v12;
    if ( a4 >= (unsigned int)v12 )
    {
      result = CSessionCacheItem::SerializeRemoteChain(this, &a3[v12], a4 - (unsigned int)v12, (unsigned int *)a3 + 5);
      if ( (_DWORD)result )
        return result;
      v13 = (unsigned int)(*((_DWORD *)a3 + 4) + *((_DWORD *)a3 + 5));
      *((_DWORD *)a3 + 6) = v13;
      if ( a4 >= (unsigned int)v13 )
      {
        result = CSessionCacheItem::SerializeAppData(this, &a3[v13], a4 - (unsigned int)v13, (unsigned int *)a3 + 7);
        if ( (_DWORD)result )
          return result;
        v14 = (unsigned int)(*((_DWORD *)a3 + 6) + *((_DWORD *)a3 + 7));
        *((_DWORD *)a3 + 15) = v14;
        if ( a4 >= (unsigned int)v14 )
        {
          result = CSessionCacheItem::SerializeTicketNonce(this, &a3[v14], a4 - (unsigned int)v14, a3 + 64);
          if ( !(_DWORD)result )
          {
            *a5 = *((_DWORD *)a3 + 15) + a3[64];
            return 0i64;
          }
          return result;
        }
      }
    }
    return 122i64;
  }
  return result;
}
