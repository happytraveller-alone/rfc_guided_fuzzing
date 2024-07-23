// File count: 1462
// Total lines: 59
----------------------------------------
__int64 __fastcall SignDssParams(
        struct CSsl3TlsServerContext *a1,
        unsigned __int8 *a2,
        ULONG a3,
        BYTE *pbEncoded,
        DWORD *pcbEncoded)
{
  bool v5; // zf
  DWORD Hash; // ebx
  int v10; // edx
  int v11; // r8d
  __int64 *v12; // rax
  __int64 v13; // rcx
  unsigned int v14; // edx
  int v15; // [rsp+40h] [rbp-78h] BYREF
  unsigned __int8 v16[24]; // [rsp+48h] [rbp-70h] BYREF
  unsigned __int8 pvStructInfo[20]; // [rsp+60h] [rbp-58h] BYREF
  unsigned __int8 v18[20]; // [rsp+74h] [rbp-44h] BYREF

  v5 = *((_QWORD *)a1 + 3) == 0i64;
  v15 = 40;
  if ( v5 )
    return 2148074253i64;
  Hash = GenerateHash(g_hSHAProvider, (UCHAR *)a1, a2, a3, v16, 0x14u);
  if ( Hash )
  {
    v10 = 1111;
LABEL_5:
    v11 = Hash;
LABEL_6:
    CSslContext::SetErrorAndFatalAlert((__int64)a1, v10, v11, 0x50u);
    return Hash;
  }
  v12 = (__int64 *)*((_QWORD *)a1 + 1);
  if ( v12 )
    v13 = *v12;
  else
    v13 = 0i64;
  Hash = SslSignHash(v13, *(_QWORD *)(*((_QWORD *)a1 + 3) + 8i64), v16, 20i64, pvStructInfo, v15, &v15, 0);
  if ( Hash )
  {
    v10 = 1112;
    goto LABEL_5;
  }
  ReverseInPlace(pvStructInfo, 0x14u);
  ReverseInPlace(v18, v14);
  if ( !CryptEncodeObject(1u, (LPCSTR)0x28, pvStructInfo, pbEncoded, pcbEncoded) )
  {
    Hash = GetLastError();
    v11 = Hash;
    v10 = 1113;
    goto LABEL_6;
  }
  return 0i64;
}
// 1800755F5: variable 'v14' is possibly undefined
// 180098540: using guessed type __int64 __fastcall SslSignHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 1800754F8: using guessed type unsigned __int8 var_44[20];
