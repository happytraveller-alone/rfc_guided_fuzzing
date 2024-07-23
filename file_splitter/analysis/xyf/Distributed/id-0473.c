//----- (0000000180022F30) ----------------------------------------------------
bool __fastcall CSessionCacheServerItem::IsEntryAMatch(
        CSessionCacheServerItem *this,
        struct _LUID *a2,
        const unsigned __int16 *a3,
        struct CRED_THUMBPRINT *a4,
        unsigned int a5)
{
  return (*((_DWORD *)this + 42) & a5) != 0
      && *(_DWORD *)a4 == *((_DWORD *)this + 47)
      && *((_DWORD *)a4 + 1) == *((_DWORD *)this + 48);
}

