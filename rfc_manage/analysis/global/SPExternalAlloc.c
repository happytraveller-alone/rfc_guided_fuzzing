HLOCAL __fastcall SPExternalAlloc(unsigned int a1)
{
  if ( LsaTable )
    return (HLOCAL)(*(__int64 (**)(void))(LsaTable + 40))();
  else
    return LocalAlloc(0x40u, a1);
}