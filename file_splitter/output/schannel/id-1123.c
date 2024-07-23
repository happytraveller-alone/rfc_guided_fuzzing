// File count: 1123
// Total lines: 22
----------------------------------------
unsigned __int16 __fastcall CSslContext::computeMaxPayload(CSslContext *this, int a2)
{
  unsigned __int16 result; // ax
  int v3; // r9d
  int v4; // r8d
  int v5; // edx

  result = 0;
  if ( (*((_BYTE *)this + 32) & 2) != 0 )
    v3 = *((_DWORD *)this + 12);
  else
    v3 = 0;
  if ( (*((_BYTE *)this + 32) & 4) != 0 )
    v4 = *((_DWORD *)this + 11);
  else
    v4 = 0;
  v5 = a2 - *((_DWORD *)this + 13) - v4 - v3 - *((_DWORD *)this + 15);
  if ( v5 >= 0 )
    return v5;
  return result;
}
