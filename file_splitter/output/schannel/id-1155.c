//----- (000000018005CEF0) ----------------------------------------------------
unsigned int __fastcall CSessionCacheItem::Deserialize(
        CSessionCacheItem *this,
        struct CSslContext *a2,
        unsigned __int8 *a3,
        unsigned int a4)
{
  CCipherMill *v8; // rcx
  unsigned int result; // eax
  int v10; // r8d
  __int64 v11; // rcx
  unsigned int v12; // r9d
  __int64 v13; // rcx
  unsigned int v14; // r8d

  if ( !a2 || !a3 || a4 < 0x44 || *(_DWORD *)a3 != 1 )
    return 87;
  *((_DWORD *)this + 2) = *((_DWORD *)a3 + 1);
  v8 = (CCipherMill *)*((unsigned int *)a3 + 8);
  *((_DWORD *)this + 42) = (_DWORD)v8;
  *((_DWORD *)this + 46) = *((_DWORD *)a3 + 10);
  if ( ((unsigned int)v8 & *((_DWORD *)a2 + 16)) == 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_3f0b3b553bfa392717596024a0f8b3a2_Traceguids);
    return 87;
  }
  result = CCipherMill::GetCipherState(
             v8,
             a2,
             (struct CCipherSuiteInfo **)this + 22,
             *((_DWORD *)a3 + 9),
             *((_DWORD *)a3 + 10));
  if ( !result )
  {
    *(_QWORD *)((char *)this + 188) = *(_QWORD *)(a3 + 52);
    *((_DWORD *)this + 54) = *((_DWORD *)a3 + 11);
    *((_DWORD *)this + 55) = *((_DWORD *)a3 + 12);
    if ( *((_DWORD *)a3 + 2) == 65 )
    {
      v10 = *((_DWORD *)a3 + 3);
      if ( v10 + 65 <= a4 )
      {
        result = CSessionCacheItem::DeserializeNcryptMasterKey(this, a3 + 65, v10);
        if ( result )
          return result;
        v11 = *((unsigned int *)a3 + 4);
        if ( (_DWORD)v11 == *((_DWORD *)a3 + 3) + *((_DWORD *)a3 + 2) )
        {
          v12 = *((_DWORD *)a3 + 5);
          if ( v12 + (unsigned int)v11 <= a4 )
          {
            result = CSessionCacheItem::DeserializeRemoteChain(this, a2, &a3[v11], v12);
            if ( result )
              return result;
            v13 = *((unsigned int *)a3 + 6);
            if ( (_DWORD)v13 == *((_DWORD *)a3 + 4) + *((_DWORD *)a3 + 5) )
            {
              v14 = *((_DWORD *)a3 + 7);
              if ( v14 + (unsigned int)v13 <= a4 )
              {
                result = CSessionCacheItem::DeserializeAppData(this, &a3[v13], v14);
                if ( !result )
                {
                  if ( *((_DWORD *)a3 + 15) == *((_DWORD *)a3 + 6) + *((_DWORD *)a3 + 7)
                    && *((_DWORD *)a3 + 15) + (unsigned int)a3[64] <= a4 )
                  {
                    return CSessionCacheItem::DeserializeTicketNonce(this, &a3[*((unsigned int *)a3 + 15)], a3[64]);
                  }
                  return 87;
                }
                return result;
              }
            }
          }
        }
      }
    }
    return 87;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

