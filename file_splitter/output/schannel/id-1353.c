// File count: 1353
// Total lines: 31
----------------------------------------
__int64 __fastcall CTls13Context::ExportRawSecretBytes(
        CTls13Context *this,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        unsigned int Size)
{
  __int64 result; // rax
  char v9[512]; // [rsp+50h] [rbp-228h] BYREF

  if ( !a2 || !a3 || !a4 || Size - 32 > 0x10 )
    return 2148074333i64;
  memset_0(v9, 0, sizeof(v9));
  result = SslExportKey(a2, a3, L"OpaqueKeyBlob");
  if ( !(_DWORD)result )
  {
    if ( Size )
    {
      return 2148074244i64;
    }
    else
    {
      memcpy_0(a4, v9, 0i64);
      return 0i64;
    }
  }
  return result;
}
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180098528: using guessed type __int64 __fastcall SslExportKey(_QWORD, _QWORD, _QWORD);
