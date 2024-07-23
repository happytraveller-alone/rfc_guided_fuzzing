// File count: 1497
// Total lines: 53
----------------------------------------
__int64 __fastcall CTls13ExtServer::ParsePskKeyExchangeModesExtension(
        CTls13ExtServer *this,
        unsigned __int8 *a2,
        __int16 a3,
        __int64 a4)
{
  __int16 v5; // ax
  unsigned __int16 v6; // r8
  unsigned __int8 *v7; // rdx
  unsigned __int8 *v8; // rcx
  unsigned __int8 v9; // al
  __int64 v11; // rcx

  if ( !a2 || !a3 )
  {
    v11 = *((_QWORD *)this + 1);
    goto LABEL_19;
  }
  v5 = *a2;
  v6 = a3 - 1;
  v7 = a2 + 1;
  if ( !(_BYTE)v5 || v5 != v6 )
  {
    v11 = *((_QWORD *)this + 1);
LABEL_19:
    LOBYTE(a4) = 50;
    CSslContext::SetErrorAndFatalAlert(v11, 1202i64, 2148074248i64, a4);
    return 2148074248i64;
  }
  v8 = &v7[v6];
  if ( v7 >= v8 )
  {
LABEL_9:
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_5635b40337ae3cd6626e599d778a0aa6_Traceguids);
  }
  else
  {
    v9 = *v7;
    while ( v9 != 1 )
    {
      if ( ++v7 >= v8 )
        goto LABEL_9;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_5635b40337ae3cd6626e599d778a0aa6_Traceguids);
    *(_QWORD *)(*((_QWORD *)this + 1) + 136i64) |= 0x2000000ui64;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18005B470: using guessed type __int64 __fastcall CSslContext::SetErrorAndFatalAlert(_QWORD, _QWORD, _QWORD, _QWORD);
