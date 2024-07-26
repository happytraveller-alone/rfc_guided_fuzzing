//----- (000000018004D070) ----------------------------------------------------
void __fastcall WatchBcryptEvent(PVOID a1)
{
  CCipherMill *v1; // rcx

  if ( !_InterlockedCompareExchange(&g_fBuildingCiphers, 1, 0) )
  {
    Sleep(0x64u);
    _InterlockedExchange(&g_fBuildingCiphers, 0);
    CCipherMill::BuildCipherMill(v1);
    NotifyWNFConfigChangeEvent(WNF_SCH_BCRYPT_RELOAD);
  }
}
// 18004D09E: variable 'v1' is possibly undefined
// 180092F44: using guessed type int g_fBuildingCiphers;

