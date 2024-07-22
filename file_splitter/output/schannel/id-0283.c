//----- (0000000180015EE0) ----------------------------------------------------
__int64 __fastcall SpSetContextAttributes(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  CCipherMill *v8; // rcx
  _QWORD *v9; // rdi
  __int64 v10; // rbx
  unsigned int v11; // eax

  v8 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids);
      v8 = WPP_GLOBAL_Control;
    }
    if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v8 + 28) & 4) != 0 )
      {
        WPP_SF_q(*((_QWORD *)v8 + 2), 0x1Au, (__int64)&WPP_dd5b111c8476393ce65badbe3d423765_Traceguids, a1);
        v8 = WPP_GLOBAL_Control;
      }
      if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
      {
        WPP_SF_d(*((_QWORD *)v8 + 2), 0x1Bu, (__int64)&WPP_dd5b111c8476393ce65badbe3d423765_Traceguids, a2);
        v8 = WPP_GLOBAL_Control;
      }
    }
  }
  v9 = *(_QWORD **)(a1 + 8);
  v10 = v9[10];
  if ( v10 && v8 != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)v8 + 28) & 4) != 0 )
    {
      WPP_SF_D(
        *((_QWORD *)v8 + 2),
        28i64,
        &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids,
        *(unsigned int *)(v10 + 212));
      v8 = WPP_GLOBAL_Control;
    }
    if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
      WPP_SF_S(
        *((_QWORD *)v8 + 2),
        0x1Du,
        (__int64)&WPP_dd5b111c8476393ce65badbe3d423765_Traceguids,
        (const wchar_t *)(v10 + 216));
  }
  v11 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD, __int64, _QWORD))(*v9 + 208i64))(v9, a2, a3, a4);
  return TranslateToSecurityStatus(v11);
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

