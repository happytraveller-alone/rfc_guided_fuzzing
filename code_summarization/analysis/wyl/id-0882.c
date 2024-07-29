//----- (00000001800481B0) ----------------------------------------------------
__int64 __fastcall SslCreateTokenFromPac(
        unsigned __int8 *a1,
        __int64 a2,
        struct _UNICODE_STRING *a3,
        struct _LUID *a4,
        void **a5)
{
  unsigned int v7; // ebx
  __int64 v8; // rcx
  struct _LUID v10; // [rsp+60h] [rbp-71h] BYREF
  void *v11; // [rsp+68h] [rbp-69h] BYREF
  char v12[8]; // [rsp+70h] [rbp-61h] BYREF
  char v13[8]; // [rsp+78h] [rbp-59h] BYREF
  __int64 v14; // [rsp+80h] [rbp-51h]
  unsigned __int8 v15[80]; // [rsp+90h] [rbp-41h] BYREF

  v14 = 0i64;
  v7 = (*(__int64 (__fastcall **)(unsigned __int8 *, __int64, __int64, struct _TOKEN_SOURCE *, int, struct _UNICODE_STRING *, void **, struct _LUID *, char *, char *))(LsaTable + 272))(
         a1,
         a2,
         2i64,
         &SslTokenSource,
         3,
         a3,
         &v11,
         &v10,
         v13,
         v12);
  if ( (v7 & 0x80000000) != 0 )
  {
    (*(void (__fastcall **)(_QWORD, _QWORD, void *, void *, _QWORD, _QWORD, int, struct _TOKEN_SOURCE *, struct _LUID *))(LsaTable + 168))(
      v7,
      v7,
      &SslNullString,
      &SslNullString,
      0i64,
      0i64,
      3,
      &SslTokenSource,
      &v10);
  }
  else
  {
    if ( (unsigned int)GetTokenUserSid(v11, v15) )
      (*(void (__fastcall **)(_QWORD, _QWORD, char *, struct _UNICODE_STRING *, _QWORD, unsigned __int8 *, int, int, struct _TOKEN_SOURCE *, struct _LUID *))(LsaTable + 464))(
        0i64,
        0i64,
        v13,
        a3,
        0i64,
        v15,
        3,
        2,
        &SslTokenSource,
        &v10);
    v8 = v14;
    *a5 = v11;
    *a4 = v10;
    if ( v8 )
      (*(void (**)(void))(LsaTable + 48))();
  }
  return v7;
}
// 180092620: using guessed type __int64 LsaTable;
// 1800481B0: using guessed type char var_B0[8];
// 1800481B0: using guessed type char var_A8[8];

