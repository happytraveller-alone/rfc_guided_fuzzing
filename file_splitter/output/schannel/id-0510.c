//----- (0000000180025AD4) ----------------------------------------------------
__int64 __fastcall ReadRegistrySetting(HKEY a1, HKEY a2, const unsigned __int16 *a3, BYTE *lpData, unsigned int a5)
{
  int v5; // ebp
  unsigned int v9; // ebx
  DWORD v11[10]; // [rsp+30h] [rbp-28h] BYREF
  DWORD v12; // [rsp+78h] [rbp+20h] BYREF

  v5 = *(_DWORD *)lpData;
  v12 = 4;
  v9 = 0;
  if ( RegQueryValueExW(a1, a3, 0i64, v11, lpData, &v12) )
  {
    *(_DWORD *)lpData = a5;
    if ( a2 )
      RegSetValueExW(a2, a3, 0, 4u, lpData, 4u);
  }
  LOBYTE(v9) = v5 != *(_DWORD *)lpData;
  return v9;
}
// 180025AD4: using guessed type DWORD anonymous_0[10];

