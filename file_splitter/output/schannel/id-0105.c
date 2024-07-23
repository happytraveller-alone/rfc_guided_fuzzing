// File count: 105
// Total lines: 70
-----------------------------------------
__int64 __fastcall CCipherMill::SetServerHelloCipher(CCipherMill *this, struct CSsl3TlsClientContext *a2, int a3)
{
  __int64 v3; // rdi
  unsigned int v4; // ebp
  unsigned int *v7; // r15
  unsigned int v8; // r12d
  int v9; // r13d
  CMasterCipherInfo *v10; // rax
  unsigned int v11; // ecx
  __int64 v12; // rbx
  unsigned int v13; // eax
  __int64 v14; // rax
  unsigned int v15; // ebx

  v3 = *((_QWORD *)a2 + 10);
  v4 = *((_DWORD *)a2 + 16);
  v7 = *(unsigned int **)(v3 + 184);
  v8 = *(_DWORD *)(v3 + 176);
  v9 = *(_DWORD *)(v3 + 192);
  RtlAcquireResourceShared(&Resource, 1u);
  v10 = xmmword_1800925B0;
  if ( (*((_DWORD *)a2 + 34) & 0x20000000) != 0 )
    v10 = *(&xmmword_1800925B0 + 1);
  if ( !v10 )
    goto LABEL_15;
  v11 = *((_DWORD *)v10 + 2);
  v12 = *(_QWORD *)v10;
  v13 = 0;
  if ( !v11 )
    goto LABEL_15;
  while ( *(_DWORD *)(v12 + 28) != a3 )
  {
    ++v13;
    v12 += 864i64;
    if ( v13 >= v11 )
      goto LABEL_15;
  }
  if ( !CCipherMill::IsCipherSuiteAllowed(
          (__int64)g_cCipherMill,
          v7,
          v8,
          v9,
          (*(_DWORD *)(v3 + 156) >> 12) & 1,
          *(_DWORD *)(v3 + 156) & 0x800,
          *(_DWORD *)(v3 + 168),
          *(_DWORD *)(v3 + 164),
          v4,
          v12,
          0i64,
          0i64,
          0,
          1) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 58i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
LABEL_15:
    RtlReleaseResource(&Resource);
    LogCipherMismatchEvent(*(_DWORD *)(v3 + 212), (const unsigned __int16 *)(v3 + 216), v4);
    return 2148074289i64;
  }
  v14 = *(_QWORD *)(v12 + 848);
  if ( v14 )
    _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v14 + 16) + 12i64));
  _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v12 + 856) + 12i64));
  v15 = CSslContext::SetCipherState(a2, (struct CCipherSuiteInfo *)v12);
  RtlReleaseResource(&Resource);
  return v15;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
