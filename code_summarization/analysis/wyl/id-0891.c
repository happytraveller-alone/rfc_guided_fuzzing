//----- (000000018004A500) ----------------------------------------------------
_BOOL8 __fastcall SslRelocateToken(__int64 a1, unsigned __int64 *a2)
{
  return (*(int (__fastcall **)(__int64, unsigned __int64 *))(LsaTable + 104))(a1, a2) >= 0;
}
// 180092620: using guessed type __int64 LsaTable;

