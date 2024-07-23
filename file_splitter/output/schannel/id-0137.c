// File count: 137
// Total lines: 15
-----------------------------------------
void __fastcall SslDeleteUserContext(__int64 a1)
{
  struct CSslUserContext *v2; // rax

  v2 = SslReferenceUserContext(a1, 1u);
  if ( v2 )
  {
    DeleteUserContext(v2);
  }
  else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Bu, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, a1);
  }
}
