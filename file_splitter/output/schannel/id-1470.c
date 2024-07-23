// File count: 1470
// Total lines: 125
---------------------------------------
__int64 __fastcall CreateUserMappingDataMsg(
        unsigned __int8 *a1,
        unsigned int a2,
        unsigned __int16 *a3,
        unsigned __int16 *a4)
{
  __int64 v4; // rdi
  __int64 cbMultiByte; // rsi
  unsigned int v8; // eax
  __int16 v9; // r9
  __int16 v10; // r10
  __int16 v11; // r11
  int v12; // edx
  unsigned int v13; // r14d
  CCipherMill *v15; // rcx
  unsigned __int16 v16; // dx
  int v17; // ebp
  CHAR *v18; // rbx
  DWORD LastError; // eax
  __int64 v20; // rdx
  LPSTR lpMultiByteStr; // [rsp+20h] [rbp-38h]

  v4 = -1i64;
  if ( a3 )
  {
    cbMultiByte = -1i64;
    do
      ++cbMultiByte;
    while ( a3[cbMultiByte] );
  }
  else
  {
    LODWORD(cbMultiByte) = 0;
  }
  if ( a4 )
  {
    do
      ++v4;
    while ( a4[v4] );
  }
  else
  {
    LODWORD(v4) = 0;
  }
  v8 = v4 + cbMultiByte;
  v9 = v4 + cbMultiByte + 4;
  v10 = v4 + cbMultiByte + 7;
  v11 = v4 + cbMultiByte + 9;
  v12 = v4 + cbMultiByte + 13;
  v13 = v4 + cbMultiByte + 16;
  if ( (int)v4 + (int)cbMultiByte < (unsigned int)cbMultiByte || v8 + 13 < v8 || v8 + 13 > 0xFFFF )
    return 0i64;
  if ( a1 )
  {
    if ( a2 < v13 )
    {
      v15 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 0i64;
      v16 = 11;
      goto LABEL_22;
    }
    a1[2] = v12;
    v17 = 14;
    *a1 = BYTE2(v12);
    a1[1] = BYTE1(v12);
    a1[5] = HIBYTE(v11);
    a1[7] = HIBYTE(v10);
    a1[10] = HIBYTE(v9);
    a1[12] = BYTE1(cbMultiByte);
    *(_WORD *)(a1 + 3) = 0;
    a1[6] = v11;
    a1[8] = v10;
    a1[9] = 64;
    a1[11] = v9;
    a1[13] = cbMultiByte;
    v18 = (CHAR *)(a1 + 14);
    if ( (_DWORD)cbMultiByte )
    {
      if ( !WideCharToMultiByte(0xFDE9u, 0, a3, cbMultiByte, v18, cbMultiByte, 0i64, 0i64) )
      {
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 0i64;
        LastError = GetLastError();
        v20 = 12i64;
        goto LABEL_35;
      }
      v17 = cbMultiByte + 14;
      v18 += (unsigned int)cbMultiByte;
    }
    v18[1] = v4;
    a2 = v17 + 2;
    *v18 = BYTE1(v4);
    if ( (_DWORD)v4 )
    {
      if ( !WideCharToMultiByte(0xFDE9u, 0, a4, v4, v18 + 2, v4, 0i64, 0i64) )
      {
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 0i64;
        LastError = GetLastError();
        v20 = 13i64;
LABEL_35:
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), v20, &WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids, LastError);
        return 0i64;
      }
      a2 += v4;
    }
    if ( a2 == v13 )
      return a2;
    v15 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 0i64;
    v16 = 14;
LABEL_22:
    LODWORD(lpMultiByteStr) = v4 + cbMultiByte + 16;
    WPP_SF_dd(*((_QWORD *)v15 + 2), v16, (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids, a2, lpMultiByteStr);
    return 0i64;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, (__int64)&WPP_2a9f95ae24df3f59458f3cae84384e77_Traceguids, v13);
  return v13;
}
// 180076168: variable 'lpMultiByteStr' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
