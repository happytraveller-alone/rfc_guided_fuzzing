// File count: 1383
// Total lines: 28
----------------------------------------
__int64 __fastcall CTls13Context::PreparseMessage(
        CTls13Context *this,
        struct SPBuffer *a2,
        struct CSsl3TlsContext *a3,
        char a4)
{
  const char *v6; // r9

  if ( !a2 || !a3 )
    return 2148074333i64;
  if ( *((_DWORD *)a3 + 17) == 4 && *((_DWORD *)a2 + 1) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v6 = "server";
      if ( !a4 )
        v6 = "client";
      WPP_SF_s(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x12u,
        (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
        v6);
    }
    *((_DWORD *)a3 + 17) = 78;
  }
  return 0i64;
}
