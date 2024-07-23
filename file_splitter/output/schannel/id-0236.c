// File count: 236
// Total lines: 36
-----------------------------------------
__int64 __fastcall CertGetEccCurveType(__int64 a1, unsigned int *a2)
{
  __int64 v2; // r8
  CCipherMill *v4; // rcx
  unsigned int EccCurveType; // eax
  unsigned int v6; // ebx
  DWORD v8; // [rsp+50h] [rbp+8h] BYREF
  HLOCAL hMem; // [rsp+58h] [rbp+10h] BYREF

  *a2 = 0;
  v2 = *(_QWORD *)(a1 + 24);
  hMem = 0i64;
  v8 = 8;
  if ( CryptDecodeObjectEx(
         1u,
         (LPCSTR)0x49,
         *(const BYTE **)(v2 + 112),
         *(_DWORD *)(v2 + 104),
         0x8000u,
         0i64,
         &hMem,
         &v8) )
  {
    EccCurveType = CCipherMill::GetEccCurveType(v4, *(char **)hMem, a2);
  }
  else
  {
    EccCurveType = GetLastError();
  }
  v6 = EccCurveType;
  if ( hMem )
    LocalFree(hMem);
  return v6;
}
// 180013C33: variable 'v4' is possibly undefined
