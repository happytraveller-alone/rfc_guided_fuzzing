//----- (000000018005988C) ----------------------------------------------------
__int64 __fastcall CSessionCacheManager::ShutdownSessionCache(CSessionCacheManager *this)
{
  void *v3; // rcx
  unsigned int v4; // edi

  if ( !this )
    return 1359i64;
  if ( *((_QWORD *)this + 1) )
  {
    v3 = (void *)*((_QWORD *)this + 5);
    if ( v3 )
    {
      v4 = 0;
      if ( *((_DWORD *)this + 12) )
      {
        do
          CSessionCacheTable::~CSessionCacheTable((CSessionCacheTable *)(*((_QWORD *)this + 5) + 152i64 * v4++));
        while ( v4 < *((_DWORD *)this + 12) );
        v3 = (void *)*((_QWORD *)this + 5);
      }
      SPExternalFree(v3);
      *((_QWORD *)this + 5) = 0i64;
    }
    SPExternalFree(*((void **)this + 1));
    *((_QWORD *)this + 1) = 0i64;
  }
  if ( *((_BYTE *)this + 96) )
    RtlDeleteCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 56));
  (*(void (__fastcall **)(CSessionCacheManager *, __int64))(*(_QWORD *)this + 8i64))(this, 1i64);
  return 0i64;
}

