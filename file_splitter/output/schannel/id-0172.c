//----- (000000018000ED60) ----------------------------------------------------
void __fastcall DeleteUserContext(struct CSslUserContext *a1)
{
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x7Eu, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, a1);
  (**(void (__fastcall ***)(struct CSslUserContext *, _QWORD))a1)(a1, 0i64);
  LocalFree(a1);
}

