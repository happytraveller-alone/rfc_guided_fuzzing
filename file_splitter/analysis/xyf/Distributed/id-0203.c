//----- (0000000180011434) ----------------------------------------------------
void __fastcall CleanupAppModeInfo(void *a1)
{
  char v1; // [rsp+20h] [rbp-18h]

  if ( a1 )
    (*(void (**)(void))(LsaTable + 392))();
  v1 = 0;
  (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, char))(LsaTable + 496))(0i64, 0i64, 0i64, 0i64, v1);
}
// 180092620: using guessed type __int64 LsaTable;

