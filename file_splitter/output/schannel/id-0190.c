// File count: 190
// Total lines: 101
----------------------------------------
__int64 __fastcall CCredentialGroup::InitializeEnabledProtocols(
        CCredentialGroup *this,
        unsigned int a2,
        int a3,
        int a4,
        unsigned int a5)
{
  __int64 v6; // r9
  CCipherMill *v10; // rcx
  unsigned int ProtocolsWithCipherSuitesEnabled; // eax
  __int64 v12; // rcx
  unsigned int v13; // esi
  int v14; // eax
  int v15; // ebp
  unsigned __int64 v16; // r8
  unsigned int v17; // edx
  __int64 v18; // rax
  unsigned __int64 v19; // r9
  int v20; // eax
  __int64 v21; // r9
  int v22; // eax

  v6 = CSslGlobals::m_ProtEnabled;
  if ( CSslGlobals::m_bFipsMode )
    v6 = CSslGlobals::m_ProtEnabled & 0xBFFFFFCF;
  *((_DWORD *)this + 38) = v6;
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v6);
    v10 = WPP_GLOBAL_Control;
  }
  ProtocolsWithCipherSuitesEnabled = CCipherMill::GetProtocolsWithCipherSuitesEnabled(v10, *((_BYTE *)this + 172));
  v13 = ProtocolsWithCipherSuitesEnabled;
  if ( (CCipherMill **)v12 != &WPP_GLOBAL_Control && (*(_BYTE *)(v12 + 28) & 4) != 0 )
    WPP_SF_D(
      *(_QWORD *)(v12 + 16),
      12i64,
      &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids,
      ProtocolsWithCipherSuitesEnabled);
  v14 = v13 & *((_DWORD *)this + 38);
  v15 = a4 & 0x1000000;
  if ( v15 )
    v14 &= 0xF0000u;
  if ( a3 )
  {
    v17 = a3 & v14;
  }
  else
  {
    v16 = *((_QWORD *)this + 25);
    v17 = v14 & ~CSslGlobals::m_ProtDisabledByDefault;
    v18 = *((unsigned int *)this + 49);
    *((_DWORD *)this + 38) = v17;
    v19 = v16 + 40 * v18;
    if ( v16 < v19 )
    {
      do
      {
        if ( !*(_DWORD *)v16 )
        {
          v20 = *(_DWORD *)(v16 + 16);
          if ( v20 )
          {
            if ( (*(_BYTE *)(v16 + 32) & 1) == 0 )
              *((_DWORD *)this + 38) &= ~v20;
          }
        }
        v16 += 40i64;
      }
      while ( v16 < v19 );
      v17 = *((_DWORD *)this + 38);
    }
  }
  if ( a2 >= 5 )
  {
    if ( !v15 )
      v17 &= 0x3FF0u;
  }
  else
  {
    v17 &= 0xFFFFCFFF;
  }
  if ( (v17 & 0x3000) != 0 )
    v17 &= 0xFFFFFFCF;
  v21 = v17 & ((a5 & 0x40051555) != 0 ? 1074074965 : -2146817366);
  *((_DWORD *)this + 38) = v21;
  v22 = v17 & ((a5 & 0x40051555) != 0 ? 1074074965 : -2146817366);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, v21);
    v22 = *((_DWORD *)this + 38);
  }
  return v22 == 0 ? 0x80090331 : 0;
}
// 1800101A3: variable 'v12' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800919F8: using guessed type unsigned int CSslGlobals::m_ProtEnabled;
// 1800919FC: using guessed type unsigned int CSslGlobals::m_ProtDisabledByDefault;
// 180092F18: using guessed type int CSslGlobals::m_bFipsMode;
