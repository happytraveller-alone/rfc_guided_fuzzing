// File count: 33
// Total lines: 17
------------------------------------------
unsigned __int8 __fastcall HasTimeElapsed(unsigned int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax

  v3 = a2 - a1;
  if ( a2 <= a1 )
  {
    if ( a2 >= a1 || v3 - 1 < a3 )
      return 0;
  }
  else if ( v3 <= a3 )
  {
    return 0;
  }
  return 1;
}
