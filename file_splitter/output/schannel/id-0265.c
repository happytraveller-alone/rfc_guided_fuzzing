// File count: 265
// Total lines: 40
-----------------------------------------
__int64 __fastcall GetAlgIdFromEccTypeCertParameters(
        BYTE *pbEncoded,
        DWORD cbEncoded,
        PCCRYPT_OID_INFO *a3,
        _DWORD *a4)
{
  PCCRYPT_OID_INFO OIDInfo; // rax
  __int64 v7; // rdx
  int LastError; // eax
  unsigned int v9; // ebx
  DWORD v11; // [rsp+40h] [rbp-18h] BYREF
  HLOCAL hMem[2]; // [rsp+48h] [rbp-10h] BYREF

  hMem[0] = 0i64;
  v11 = 8;
  if ( !CryptDecodeObjectEx(1u, (LPCSTR)0x49, pbEncoded, cbEncoded, 0x8000u, 0i64, hMem, &v11) )
  {
    LastError = GetLastError();
LABEL_5:
    v9 = LastError;
    goto LABEL_6;
  }
  OIDInfo = CryptFindOIDInfo(1u, *(void **)hMem[0], 3u);
  *a3 = OIDInfo;
  if ( OIDInfo )
  {
    LastError = I_GetSignatureDetailsFromAlgorithmName(*(wchar_t **)&OIDInfo[1].cbSize, v7, a4);
    if ( LastError )
      LastError = -2146893043;
    goto LABEL_5;
  }
  v9 = -2146893043;
LABEL_6:
  if ( hMem[0] )
    LocalFree(hMem[0]);
  return v9;
}
// 1800151AB: variable 'v7' is possibly undefined
// 180015120: using guessed type HLOCAL hMem[2];
