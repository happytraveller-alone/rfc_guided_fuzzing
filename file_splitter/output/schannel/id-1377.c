// File count: 1377
// Total lines: 15
----------------------------------------
__int64 __fastcall CTls13Context::ImportApplicationTrafficSecret(
        CTls13Context *this,
        __int64 a2,
        unsigned __int64 *a3,
        unsigned __int8 *a4,
        unsigned int a5)
{
  if ( a2 && a3 && a4 && a5 )
    return SslImportKey(a2, a3, L"OpaqueKeyBlob", a4, a5, 0);
  else
    return 87i64;
}
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
