// File count: 145
// Total lines: 15
-----------------------------------------
struct CSslUserContext *__fastcall SslFindUserContext(__int64 a1)
{
  struct CSslUserContext *v2; // rax
  struct CSslUserContext *v3; // rbx

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_ba773d91511536867a821af0ee22c47a_Traceguids);
  v2 = SslReferenceUserContext(a1, 0);
  v3 = v2;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x17u, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, v2);
  return v3;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
