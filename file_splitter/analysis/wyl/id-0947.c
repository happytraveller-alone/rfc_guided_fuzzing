//----- (000000018004E4E8) ----------------------------------------------------
__int64 __fastcall SpQueryConnectionInfoEx(struct CSslUserContext *a1, struct _SecPkgContext_ConnectionInfoEx *a2)
{
  unsigned __int16 v4; // ax
  unsigned int v5; // esi
  char v7[140]; // [rsp+30h] [rbp-2D8h] BYREF
  wchar_t Source[64]; // [rsp+BCh] [rbp-24Ch] BYREF
  DWORD v9; // [rsp+13Ch] [rbp-1CCh]
  wchar_t v10[64]; // [rsp+144h] [rbp-1C4h] BYREF
  DWORD v11; // [rsp+1C4h] [rbp-144h]
  wchar_t v12[140]; // [rsp+1C8h] [rbp-140h] BYREF

  memset_0(v7, 0, 0x2A4ui64);
  v4 = ConvertSchannelProtocolToSsl(*((_DWORD *)a1 + 6));
  v5 = SslLookupCipherSuiteInfo(*((_QWORD *)a1 + 11), v4, *((unsigned int *)a1 + 14), *((unsigned int *)a1 + 15), v7, 0);
  if ( !v5 )
  {
    a2->dwVersion = 1;
    a2->dwProtocol = *((_DWORD *)a1 + 6);
    wcscpy_s(a2->szCipher, 0x40ui64, Source);
    a2->dwCipherStrength = v9;
    wcscpy_s(a2->szHash, 0x40ui64, v10);
    a2->dwHashStrength = v11;
    wcscpy_s(a2->szExchange, 0x40ui64, v12);
    a2->dwExchStrength = *((_DWORD *)a1 + 7);
  }
  return v5;
}
// 180098510: using guessed type __int64 __fastcall SslLookupCipherSuiteInfo(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 18004E4E8: using guessed type wchar_t Source[64];
// 18004E4E8: using guessed type wchar_t var_1C4[64];
// 18004E4E8: using guessed type wchar_t var_140[140];

