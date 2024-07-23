//----- (00000001800084B0) ----------------------------------------------------
char __fastcall CCipherMill::IsUserSpecifiedCipherAllowed(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        char a4,
        int a5,
        int a6,
        unsigned int a7,
        unsigned int a8,
        int a9,
        char a10,
        unsigned __int64 a11,
        unsigned int a12)
{
  char v12; // bl
  CMasterCipherInfo *v13; // rax
  unsigned int v14; // edi
  unsigned int v15; // esi
  __int64 i; // rbp
  char IsCipherSuiteAllowed; // al

  v12 = 0;
  RtlAcquireResourceShared(&Resource, 1u);
  v13 = xmmword_1800925B0;
  if ( a10 )
    v13 = *(&xmmword_1800925B0 + 1);
  if ( v13 )
  {
    v14 = *((_DWORD *)v13 + 2);
    v15 = 0;
    for ( i = *(_QWORD *)v13; v15 < v14; v12 = IsCipherSuiteAllowed )
    {
      if ( v12 )
        break;
      IsCipherSuiteAllowed = CCipherMill::IsCipherSuiteAllowed(
                               (__int64)g_cCipherMill,
                               a2,
                               a3,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               i + 864i64 * v15++,
                               0i64,
                               a11,
                               a12,
                               1);
    }
  }
  RtlReleaseResource(&Resource);
  return v12;
}

