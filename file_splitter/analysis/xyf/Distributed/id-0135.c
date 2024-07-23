//----- (000000018000B190) ----------------------------------------------------
__int64 __fastcall SslAddUserContext(__int64 a1, void *a2, struct _SecBuffer *a3, int a4)
{
  CCipherMill *v8; // rcx
  struct CSslUserContext *v9; // rdi
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  __int64 v12; // rsi
  char *v13; // rax
  char *v14; // rcx
  char **v15; // rdx
  __int64 v17; // [rsp+20h] [rbp-48h]
  __int128 v18; // [rsp+30h] [rbp-38h] BYREF
  __int64 v19; // [rsp+40h] [rbp-28h]
  int v20; // [rsp+48h] [rbp-20h]
  int v21; // [rsp+4Ch] [rbp-1Ch]
  struct CSslUserContext *v22; // [rsp+80h] [rbp+18h] BYREF

  v19 = 0i64;
  v20 = 0;
  v21 = 0;
  v18 = 0i64;
  v8 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_ba773d91511536867a821af0ee22c47a_Traceguids);
      v8 = WPP_GLOBAL_Control;
    }
    if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
      WPP_SF_q(*((_QWORD *)v8 + 2), 0xCu, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, a1);
  }
  if ( !a4 )
    SslDeleteUserContext(a1);
  if ( (unsigned int)CSslSerializeHelper::DeserializeContext(
                       (CSslSerializeHelper *)&v18,
                       (unsigned __int8 *)a3->pvBuffer,
                       a3->cbBuffer,
                       &v22) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xDu,
        (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids,
        -2146893008,
        -2146893008);
    return 2148074288i64;
  }
  else
  {
    v9 = v22;
    if ( a2 || a4 )
      *((_QWORD *)v22 + 33) = a2;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_qq(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xEu,
        (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids,
        v9,
        a1);
    *((_QWORD *)v9 + 36) = a1;
    v10 = BYTE3(a1) + a1 + WORD1(a1) + ((unsigned int)a1 >> 8);
    v11 = (dwSslContextListCount - 1) & ((v10 >> 4) + v10);
    v12 = 96i64 * (v11 & (dwSslContextLockCount - 1));
    RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)SslContextLock + v12), 1u);
    v13 = (char *)v9 + 304;
    v14 = (char *)SslContextList + 16 * v11;
    v15 = (char **)*((_QWORD *)v14 + 1);
    if ( *v15 != v14 )
      __fastfail(3u);
    *(_QWORD *)v13 = v14;
    *((_QWORD *)v9 + 39) = v15;
    *v15 = v13;
    *((_QWORD *)v14 + 1) = v13;
    RtlReleaseResource((PRTL_RESOURCE)((char *)SslContextLock + v12));
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LODWORD(v17) = 0;
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xFu,
        (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids,
        0,
        v17);
    }
    return 0i64;
  }
}
// 180035A1F: variable 'v17' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800919E0: using guessed type unsigned int dwSslContextListCount;
// 1800919E4: using guessed type unsigned int dwSslContextLockCount;

