//----- (0000000180026774) ----------------------------------------------------
__int64 __fastcall CSessionCacheManager::InitializeSessionCache(CSessionCacheManager *this)
{
  unsigned int v1; // esi
  HLOCAL v3; // rax
  CSessionCacheTable *v4; // rax
  CSessionCacheTable *v5; // rbx
  unsigned int v6; // eax
  unsigned int v7; // ebp
  struct _LIST_ENTRY *v8; // r14
  unsigned int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  ULONG v12; // ebx

  v1 = *((_DWORD *)this + 4);
  *((_DWORD *)this + 12) = (*((_DWORD *)this + 13) + v1 - 1) / *((_DWORD *)this + 13);
  v3 = SPExternalAlloc(16 * v1);
  *((_QWORD *)this + 1) = v3;
  if ( !v3
    || (v4 = (CSessionCacheTable *)SPExternalAlloc(152 * *((_DWORD *)this + 12)),
        *((_QWORD *)this + 5) = v4,
        (v5 = v4) == 0i64) )
  {
LABEL_15:
    v12 = 14;
LABEL_16:
    CSessionCacheManager::ShutdownSessionCache(this);
    CSessionCacheManager::m_pSessionCacheManager = 0i64;
    return v12;
  }
  v6 = *((_DWORD *)this + 12);
  v7 = 0;
  v8 = (struct _LIST_ENTRY *)*((_QWORD *)this + 1);
  if ( v6 )
  {
    v9 = *((_DWORD *)this + 13);
    do
    {
      if ( v1 <= v9 )
        v9 = v1;
      CSessionCacheTable::CSessionCacheTable(v5, v8, v9);
      v9 = *((_DWORD *)this + 13);
      ++v7;
      v5 = (CSessionCacheTable *)((char *)v5 + 152);
      v1 -= v9;
      v8 += v9;
      v6 = *((_DWORD *)this + 12);
    }
    while ( v7 < v6 );
  }
  v10 = 0;
  if ( v6 )
  {
    while ( *(_BYTE *)(152i64 * v10 + *((_QWORD *)this + 5) + 144) )
    {
      if ( ++v10 >= *((_DWORD *)this + 12) )
        goto LABEL_11;
    }
    goto LABEL_15;
  }
LABEL_11:
  v11 = RtlInitializeCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 56));
  v12 = v11;
  if ( v11 < 0 )
    v12 = RtlNtStatusToDosError(v11);
  else
    *((_BYTE *)this + 96) = 1;
  if ( v12 )
    goto LABEL_16;
  return v12;
}

