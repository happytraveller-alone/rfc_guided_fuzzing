//----- (000000018004D0F8) ----------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__fastcall sub_18004D0F8(CSslBasicAllocator *a1, unsigned int a2)
{
  char v2; // cf
  char v3; // of

  if ( !v3 )
    JUMPOUT(0x18004D11Bi64);
  if ( !v2 )
    JUMPOUT(0x18004D085i64);
  return CSslBasicAllocator::`vector deleting destructor'(a1, a2);
}
// 18004D0FB: positive sp value 8 has been found
// 18004D0F8: control flows out of bounds to 18004D11B
// 18004D0FC: control flows out of bounds to 18004D085
// 18004D0F8: variable 'v3' is possibly undefined
// 18004D0FC: variable 'v2' is possibly undefined

