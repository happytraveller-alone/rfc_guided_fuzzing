//----- (00000001800569FC) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::RemoveDuplicateIssuers(
        CCredentialGroup *this,
        unsigned __int8 *a2,
        unsigned int *a3)
{
  unsigned __int8 *v4; // rbx
  unsigned __int8 *v5; // r13
  int v6; // ecx
  unsigned __int8 *v7; // r9
  unsigned __int8 *v8; // rax
  const void **v9; // rbp
  unsigned int v11; // r15d
  unsigned __int8 *v12; // rdx
  __int64 v13; // rax
  unsigned int v14; // ecx
  __int64 v15; // rax
  const void **v16; // r14
  unsigned int v17; // esi
  const void **v18; // rbx
  __int64 v19; // r12
  unsigned int v20; // eax
  unsigned int *v21; // rsi
  unsigned __int8 *v22; // r14
  unsigned __int8 *v23; // rbx
  unsigned int v24; // r12d
  size_t v25; // r8
  __int64 v26; // [rsp+60h] [rbp+8h]

  if ( !a2 || *a3 < 2 )
    return 0i64;
  v4 = a2 + 1;
  v5 = &a2[*a3];
  v6 = 0;
  v7 = a2;
  if ( a2 + 1 < v5 )
  {
    v8 = a2 + 1;
    do
    {
      ++v6;
      v7 += (*v8 | ((unsigned __int64)*v7 << 8)) + 2;
      v8 = v7 + 1;
    }
    while ( v7 + 1 < v5 );
  }
  v9 = (const void **)SPExternalAlloc(16 * v6);
  if ( !v9 )
    return 14i64;
  v11 = 0;
  v12 = a2;
  if ( v4 >= v5 )
    goto LABEL_34;
  do
  {
    v13 = 2i64 * v11;
    v14 = (*v4 | (*v12 << 8)) + 2;
    ++v11;
    v9[v13 + 1] = v12;
    LODWORD(v9[v13]) = v14;
    v12 += v14;
    v4 = v12 + 1;
  }
  while ( v12 + 1 < v5 );
  if ( !v11 )
  {
LABEL_34:
    LODWORD(v23) = (_DWORD)a2;
LABEL_35:
    *a3 = (_DWORD)v23 - (_DWORD)a2;
    SPExternalFree(v9);
    return 0i64;
  }
  v15 = v11;
  v16 = v9 + 1;
  v26 = v11;
  v17 = 1;
  do
  {
    if ( *v16 && v17 < v11 )
    {
      v18 = &v9[2 * v17 + 1];
      v19 = v11 - v17;
      do
      {
        if ( *v18 )
        {
          v20 = *((_DWORD *)v18 - 2);
          if ( *((_DWORD *)v16 - 2) == v20 && !memcmp_0(*v16, *v18, v20) )
            *v18 = 0i64;
        }
        v18 += 2;
        --v19;
      }
      while ( v19 );
      v15 = v26;
    }
    ++v17;
    v16 += 2;
    v26 = --v15;
  }
  while ( v15 );
  v21 = (unsigned int *)v9;
  v22 = a2;
  v23 = a2;
  v24 = 0;
  while ( !*((_QWORD *)v21 + 1) )
  {
LABEL_28:
    ++v24;
    v22 += *v21;
    v21 += 4;
    if ( v24 >= v11 )
      goto LABEL_35;
  }
  if ( v23 == v22 )
  {
LABEL_27:
    v23 += *v21;
    goto LABEL_28;
  }
  v25 = *v21;
  if ( &v22[v25] <= v5 )
  {
    memmove_0(v23, v22, v25);
    goto LABEL_27;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids);
  SPExternalFree(v9);
  return 1359i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;

