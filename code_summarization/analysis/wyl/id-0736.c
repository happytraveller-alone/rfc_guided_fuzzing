//----- (0000000180029BC4) ----------------------------------------------------
char IsCrackSingleNamePresent()
{
  char result; // al
  char v1; // [rsp+30h] [rbp+8h] BYREF

  if ( dword_180092058 == 1 )
    return 1;
  if ( dword_180092058 == 2 )
    return 0;
  v1 = 0;
  if ( (int)ApiSetQueryApiSetPresence_0(L"Z\\", &v1) < 0 )
    return 0;
  result = v1;
  dword_180092058 = 2 - (v1 != 0);
  return result;
}
// 18002A3E0: using guessed type __int64 __fastcall ApiSetQueryApiSetPresence_0(_QWORD, _QWORD);
// 18007D4B0: using guessed type wchar_t aZ[3];
// 180092058: using guessed type int dword_180092058;
