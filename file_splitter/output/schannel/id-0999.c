// File count: 999
// Total lines: 12
-----------------------------------------
void __fastcall ReverseMemCopy(unsigned __int8 *a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 *i; // r8
  unsigned __int8 v4; // al

  for ( i = &a1[a3 - 1]; i >= a1; --i )
  {
    v4 = *a2++;
    *i = v4;
  }
}
