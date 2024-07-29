//----- (000000018004E350) ----------------------------------------------------
unsigned __int8 __fastcall IsValidAlert(unsigned __int8 a1)
{
  bool v1; // zf

  if ( a1 > 0x47u )
  {
    if ( a1 == 80 || a1 == 90 || a1 == 100 || a1 == 110 || a1 == 115 )
      return 1;
    v1 = a1 == 120;
    goto LABEL_18;
  }
  if ( a1 >= 0x46u || !a1 || a1 == 10 )
    return 1;
  if ( a1 <= 0x13u )
    return 0;
  if ( a1 <= 0x16u || a1 == 30 || a1 == 40 )
    return 1;
  if ( a1 <= 0x29u )
    return 0;
  if ( a1 > 0x33u )
  {
    v1 = a1 == 60;
LABEL_18:
    if ( !v1 )
      return 0;
  }
  return 1;
}
