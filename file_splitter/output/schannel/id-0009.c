// File count: 9
// Total lines: 18
-------------------------------------------
__int64 __fastcall SpUserModeInitialize(int a1, _DWORD *a2, _QWORD *a3, _DWORD *a4)
{
  if ( a2 && a3 && a4 )
  {
    if ( a1 == 0x10000 )
    {
      *a2 = 0x10000;
      *a3 = &SslTable;
      *a4 = 2;
      return (unsigned int)SslInitContextManager() == 0 ? 0xC000009A : 0;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, a1);
  }
  return 3221225485i64;
}
// 1800912A0: using guessed type struct _SECPKG_USER_FUNCTION_TABLE near *SslTable;
