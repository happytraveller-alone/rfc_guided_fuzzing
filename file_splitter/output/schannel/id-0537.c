// File count: 537
// Total lines: 45
-----------------------------------------
__int64 InitializeSslMemoryOptions(void)
{
  char v0; // bl
  char v1; // di
  int v2; // esi
  void *v3; // rax
  __int64 v4; // rax
  void *v6; // rax

  v0 = CSslGlobals::m_dwMemoryOptFlags;
  v1 = CSslGlobals::m_dwMemoryOptFlags & 1;
  v2 = CSslGlobals::m_dwContextPreallocateLength;
  if ( (_QWORD)xmmword_180092DD0 )
    (*(void (__fastcall **)(_QWORD, __int64))(*(_QWORD *)xmmword_180092DD0 + 8i64))(xmmword_180092DD0, 1i64);
  if ( !v1 || !v2 )
  {
    v3 = operator new(0x50ui64);
    if ( v3 )
    {
      v4 = CSslLookaside::CSslLookaside((__int64)v3, 1656, v1);
      goto LABEL_6;
    }
    goto LABEL_8;
  }
  dword_180092DE0 = v2;
  v6 = operator new(0x80ui64);
  if ( !v6 )
  {
LABEL_8:
    v4 = 0i64;
    goto LABEL_6;
  }
  v4 = CSslLookasidePreallocate::CSslLookasidePreallocate((__int64)v6, 1656, v2);
LABEL_6:
  *(_QWORD *)&xmmword_180092DD0 = v4;
  if ( v4 )
    return CSessionCacheServerItem::InitializeServerCacheLookAside((v0 & 4) != 0);
  else
    return 14i64;
}
// 180092DD0: using guessed type __int128 xmmword_180092DD0;
// 180092DE0: using guessed type int dword_180092DE0;
// 180092F70: using guessed type unsigned int CSslGlobals::m_dwContextPreallocateLength;
// 180092F74: using guessed type unsigned int CSslGlobals::m_dwMemoryOptFlags;
