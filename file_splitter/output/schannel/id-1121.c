// File count: 1121
// Total lines: 9
-----------------------------------------
__int64 __fastcall CSslContext::SetContextAttributesA(CSslContext *this, int a2, void *a3, unsigned int a4)
{
  if ( a2 == 94 )
    return CSslContext::SetApplicationData(this, a3, a4);
  if ( a2 == 104 )
    return CSslContext::SetUiInformation(this, a3, a4);
  return 120i64;
}
