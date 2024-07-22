//----- (000000018000909C) ----------------------------------------------------
void __fastcall SPExternalFree(void *a1)
{
  if ( LsaTable )
    (*(void (__fastcall **)(void *))(LsaTable + 48))(a1);
  else
    LocalFree(a1);
}
// 180092620: using guessed type __int64 LsaTable;

