// File count: 111
// Total lines: 9
------------------------------------------
void __fastcall SPExternalFree(void *a1)
{
  if ( LsaTable )
    (*(void (__fastcall **)(void *))(LsaTable + 48))(a1);
  else
    LocalFree(a1);
}
// 180092620: using guessed type __int64 LsaTable;
