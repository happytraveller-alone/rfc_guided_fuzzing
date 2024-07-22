//----- (000000018000E5B4) ----------------------------------------------------
bool __fastcall IsFatalError(int a1)
{
  if ( !a1 )
    return 0;
  if ( a1 < 0 )
    return a1 != -2146893032 && a1 != -2146893023 && (unsigned int)(a1 + 2146892950) > 1;
  return (a1 & 0x1FFF0000) != 589824;
}

