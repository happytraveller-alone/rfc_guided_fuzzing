//----- (000000018006FEBC) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::GetHashAlgorithmSize(
        CSsl3TlsContext *this,
        enum _eTlsSignatureAlgorithm a2,
        enum _eTlsHashAlgorithm a3,
        unsigned int *a4)
{
  unsigned int v4; // r10d
  unsigned int v6; // edx
  int v7; // eax
  __int64 *i; // rcx
  __int64 v9; // r11

  v4 = 0;
  if ( !a4 )
    return 87i64;
  if ( (*((_DWORD *)this + 16) & 0x43C00) != 0 )
  {
    v6 = g_dwHashInfoTotalCount;
    v7 = 0;
    *a4 = 0;
    if ( v6 )
    {
      for ( i = g_pHashInfo; ; ++i )
      {
        v9 = *i;
        if ( *i )
        {
          if ( *(_DWORD *)(v9 + 20) == a3 )
            break;
        }
        if ( ++v7 >= v6 )
          return 1168;
      }
      return (unsigned int)I_GetHashDetailsFromHashInfo(v9, 0i64, a4, (__int64)a4, 0i64, 0i64);
    }
    else
    {
      return 1168;
    }
  }
  else if ( a2 == TlsSignatureAlgorithm_Rsa )
  {
    *a4 = 36;
  }
  else if ( (unsigned int)(a2 - 2) <= 1 )
  {
    *a4 = 20;
  }
  else
  {
    *a4 = 0;
    return 87;
  }
  return v4;
}
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];

