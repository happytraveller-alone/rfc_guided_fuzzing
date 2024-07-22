//----- (0000000180059C68) ----------------------------------------------------
unsigned __int8 __fastcall DoesCredAllowAlgId(unsigned int *a1, unsigned int a2, int a3)
{
  unsigned int v3; // r9d
  int v5; // ecx
  bool v6; // zf

  v3 = 0;
  if ( !a2 )
    return 0;
  while ( 1 )
  {
    v5 = *a1;
    if ( ((*a1 - 9216) & 0xFFFF7FFF) != 0 )
    {
      if ( v5 == 43522 || v5 == 8704 )
      {
        if ( a3 == 43522 )
          return 1;
        v6 = a3 == 8704;
      }
      else
      {
        v6 = v5 == a3;
      }
    }
    else
    {
      v6 = ((a3 - 9216) & 0xFFFF7FFF) == 0;
    }
    if ( v6 )
      break;
    ++v3;
    ++a1;
    if ( v3 >= a2 )
      return 0;
  }
  return 1;
}

