//----- (000000018000C3A8) ----------------------------------------------------
__int64 __fastcall TranslateToSecurityStatus(unsigned int a1)
{
  if ( (a1 & 0x1FFF0000) == 589824 )
  {
    if ( a1 + 2146893823 <= 0x2E )
      return 2148074244i64;
    if ( a1 + 2146889727 > 0x100E && a1 + 2146885612 > 0xFEC && a1 != -2146885615 )
      return a1;
  }
  else if ( !a1 )
  {
    return 0i64;
  }
  if ( a1 > 0x80092004 )
  {
    switch ( a1 )
    {
      case 0x800B0101:
      case 0x800B0102:
        return 2148074280i64;
      case 0x800B0109:
        return 2148074277i64;
      case 0x800B010C:
        return 2148081680i64;
      case 0x800B010F:
        return 2148074274i64;
      default:
        return 2148074244i64;
    }
  }
  else
  {
    switch ( a1 )
    {
      case 0x80092004:
        return 2148074253i64;
      case 0xEu:
        return 2148074240i64;
      case 0x57u:
        return 2148074333i64;
      case 0x78u:
        return 2148074242i64;
      case 0x7Au:
        return 2148074273i64;
      default:
        return 2148074244i64;
    }
  }
}

