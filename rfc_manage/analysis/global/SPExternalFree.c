void __fastcall SPExternalFree(void *a1)
{
  if ( LsaTable )
    (*(void (__fastcall **)(void *))(LsaTable + 48))(a1);
  else
    LocalFree(a1);
}