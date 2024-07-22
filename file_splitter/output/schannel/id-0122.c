//----- (000000018000A1F4) ----------------------------------------------------
HLOCAL __fastcall SPExternalAlloc(unsigned int a1)
{
  if ( LsaTable )
    return (HLOCAL)(*(__int64 (**)(void))(LsaTable + 40))();
  else
    return LocalAlloc(0x40u, a1);
}
// 180092620: using guessed type __int64 LsaTable;

