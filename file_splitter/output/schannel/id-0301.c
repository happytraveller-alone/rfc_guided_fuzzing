// File count: 301
// Total lines: 55
-----------------------------------------
__int64 __fastcall SpLsaQueryContextAttributes(__int64 a1, unsigned int a2, __int64 a3)
{
  CCipherMill *v6; // rcx
  _QWORD *v7; // rdi
  __int64 v8; // rbx
  unsigned int v9; // eax

  v6 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids);
      v6 = WPP_GLOBAL_Control;
    }
    if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v6 + 28) & 4) != 0 )
      {
        WPP_SF_q(*((_QWORD *)v6 + 2), 0x15u, (__int64)&WPP_dd5b111c8476393ce65badbe3d423765_Traceguids, a1);
        v6 = WPP_GLOBAL_Control;
      }
      if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 4) != 0 )
      {
        WPP_SF_d(*((_QWORD *)v6 + 2), 0x16u, (__int64)&WPP_dd5b111c8476393ce65badbe3d423765_Traceguids, a2);
        v6 = WPP_GLOBAL_Control;
      }
    }
  }
  v7 = *(_QWORD **)(a1 + 8);
  v8 = v7[10];
  if ( v8 && v6 != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)v6 + 28) & 4) != 0 )
    {
      WPP_SF_D(
        *((_QWORD *)v6 + 2),
        23i64,
        &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids,
        *(unsigned int *)(v8 + 212));
      v6 = WPP_GLOBAL_Control;
    }
    if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 4) != 0 )
      WPP_SF_S(
        *((_QWORD *)v6 + 2),
        0x18u,
        (__int64)&WPP_dd5b111c8476393ce65badbe3d423765_Traceguids,
        (const wchar_t *)(v8 + 216));
  }
  v9 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD, __int64))(*v7 + 200i64))(v7, a2, a3);
  return TranslateToSecurityStatus(v9);
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
