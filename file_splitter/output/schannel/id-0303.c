// File count: 303
// Total lines: 52
-----------------------------------------
__int64 __fastcall CreateCachedSslProv(struct CACHED_SSL_PROVIDER *a1, const unsigned __int16 *a2)
{
  unsigned int v4; // ebx
  __int64 v5; // rdi
  rsize_t v6; // rdi
  wchar_t *v7; // rax
  wchar_t *v8; // rbp
  __int64 v9; // rcx
  __int64 v11; // [rsp+60h] [rbp+18h] BYREF

  v11 = 0i64;
  v4 = SslOpenProvider(&v11, a2, (unsigned int)dword_180092F58);
  if ( !v4 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( a2[v5] );
    v6 = v5 + 1;
    v7 = (wchar_t *)LocalAlloc(0x40u, 2 * v6);
    v8 = v7;
    if ( v7 )
    {
      wcscpy_s(v7, v6, a2);
      v9 = 0i64;
      *(_QWORD *)a1 = v11;
      v11 = 0i64;
      *((_QWORD *)a1 + 1) = v8;
      goto LABEL_6;
    }
    v4 = -2146893056;
  }
  v9 = v11;
LABEL_6:
  if ( v9 )
    SslFreeObject(v9, 0i64);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v4 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0xFu,
      (__int64)&WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids,
      v4,
      v4);
  }
  return v4;
}
// 180092F58: using guessed type int dword_180092F58;
// 1800984F8: using guessed type __int64 __fastcall SslOpenProvider(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
