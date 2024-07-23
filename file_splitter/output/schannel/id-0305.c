// File count: 305
// Total lines: 22
-----------------------------------------
char __fastcall CSessionCacheItem::DoesAppAllowCipher(CSessionCacheItem *this, struct CCredentialGroup *a2)
{
  if ( a2 )
    return CCipherMill::IsCipherSuiteAllowed(
             (__int64)g_cCipherMill,
             *((unsigned int **)a2 + 23),
             *((_DWORD *)a2 + 44),
             *((_DWORD *)a2 + 48),
             (*((_DWORD *)a2 + 39) >> 12) & 1,
             *((_DWORD *)a2 + 39) & 0x800,
             *((_DWORD *)a2 + 42),
             *((_DWORD *)a2 + 41),
             *((_DWORD *)a2 + 38),
             *((_QWORD *)this + 22),
             0i64,
             *((_QWORD *)a2 + 25),
             *((_DWORD *)a2 + 49),
             0);
  else
    return 0;
}
