// File count: 832
// Total lines: 37
-----------------------------------------
__int64 __fastcall McTemplateU0pz_EtwEventWriteTransfer(__int64 a1, __int64 a2, __int64 a3, const wchar_t *a4)
{
  __int64 v4; // rax
  __int64 v5; // rcx
  char v7[16]; // [rsp+30h] [rbp-48h] BYREF
  __int64 *v8; // [rsp+40h] [rbp-38h]
  __int64 v9; // [rsp+48h] [rbp-30h]
  const wchar_t *v10; // [rsp+50h] [rbp-28h]
  int v11; // [rsp+58h] [rbp-20h]
  int v12; // [rsp+5Ch] [rbp-1Ch]
  __int64 v13; // [rsp+90h] [rbp+18h] BYREF

  v13 = a3;
  v9 = 8i64;
  v8 = &v13;
  if ( a4 )
  {
    v4 = -1i64;
    do
      ++v4;
    while ( a4[v4] );
    v5 = (unsigned int)(2 * v4 + 2);
  }
  else
  {
    v5 = 10i64;
  }
  v12 = 0;
  v11 = v5;
  if ( !a4 )
    a4 = L"NULL";
  v10 = a4;
  return McGenEventWrite_EtwEventWriteTransfer(v5, (__int64)&DscStart, a3, 3, (__int64)v7);
}
// 180083C60: using guessed type wchar_t aNull_0[5];
// 18004461C: using guessed type char var_48[16];
