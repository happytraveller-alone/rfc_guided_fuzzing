// File count: 933
// Total lines: 37
-----------------------------------------
__int64 __fastcall CSslSerializeHelper::SerializeEncryptionKey(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  _DWORD *v4; // rdi
  __int64 result; // rax
  unsigned int v8; // edx
  int v9; // [rsp+50h] [rbp+8h]

  v4 = *(_DWORD **)(a1 + 16);
  if ( *(_QWORD *)(a1 + 8) )
  {
    *(_DWORD *)(a1 + 28) -= 16;
    *(_QWORD *)(a1 + 16) = v4 + 4;
  }
  v9 = *(_DWORD *)(a1 + 28);
  result = SslExportKey(a3, a4, L"OpaqueKeyBlob");
  if ( !(_DWORD)result || (_DWORD)result == -2146893784 )
  {
    v8 = (v9 + 23) & 0xFFFFFFF8;
    if ( *(_QWORD *)(a1 + 8) )
    {
      *v4 = a2;
      v4[1] = v8 - 16;
      v4[2] = v9;
      *(_QWORD *)(a1 + 16) += v8 - 16;
      *(_DWORD *)(a1 + 28) += 16 - v8;
    }
    else
    {
      *(_DWORD *)(a1 + 24) += v8;
    }
    return 0i64;
  }
  return result;
}
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180098528: using guessed type __int64 __fastcall SslExportKey(_QWORD, _QWORD, _QWORD);
