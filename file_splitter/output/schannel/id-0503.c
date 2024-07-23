// File count: 503
// Total lines: 112
----------------------------------------
__int64 __fastcall CCipherMill::LoadProviderList(CCipherMill *this, unsigned __int8 *a2)
{
  char j; // si
  CCipherMill *v4; // rcx
  unsigned int v5; // ebx
  unsigned int i; // r8d
  unsigned int v7; // r11d
  unsigned __int16 *v8; // r9
  __int64 v9; // r14
  int v10; // eax
  int v11; // ebp
  __int64 v13; // rdx
  __int64 v14; // rdi
  __int64 v15; // rdx
  unsigned int v16; // [rsp+50h] [rbp+8h] BYREF
  int v17; // [rsp+54h] [rbp+Ch]
  CCipherMill *v18; // [rsp+58h] [rbp+10h] BYREF

  v17 = HIDWORD(this);
  v16 = 0;
  v18 = 0i64;
  *a2 = 0;
  j = 1;
  v5 = SslEnumProtocolProviders(&v16, &v18, 0i64);
  if ( !v5 )
  {
    if ( v16 - 1 <= 0x1F )
    {
      if ( v16 != qword_180092498 )
        goto LABEL_21;
      v4 = v18;
      for ( i = 0; i < v16; ++i )
      {
        if ( !j )
          break;
        v7 = 0;
        for ( j = 0; v7 < qword_180092498; ++v7 )
        {
          if ( j )
            break;
          v8 = (unsigned __int16 *)*((_QWORD *)v18 + 2 * i);
          v9 = *(_QWORD *)(qword_180092490 + 16i64 * v7) - (_QWORD)v8;
          do
          {
            v10 = *(unsigned __int16 *)((char *)v8 + v9);
            v11 = *v8 - v10;
            if ( v11 )
              break;
            ++v8;
          }
          while ( v10 );
          if ( !v11 )
            j = 1;
        }
      }
      if ( i == v16 )
      {
        if ( !*a2 )
        {
LABEL_17:
          v5 = 0;
          goto LABEL_18;
        }
      }
      else
      {
LABEL_21:
        *a2 = 1;
      }
      CCipherMill::DeleteProviderList(v4);
      v13 = (__int64)v18;
      v4 = 0i64;
      v14 = 0i64;
      qword_180092490 = (__int64)v18;
      qword_180092498 = v16;
      v18 = 0i64;
      if ( !v16 )
        goto LABEL_17;
      while ( 1 )
      {
        v15 = *(_QWORD *)(v13 + 16i64 * (unsigned int)v14);
        if ( !v15 )
          break;
        v5 = SslOpenProvider(&qword_1800924A0[v14], v15, 0i64);
        if ( v5 )
          goto LABEL_29;
        v14 = (unsigned int)(v14 + 1);
        if ( (unsigned int)v14 >= qword_180092498 )
        {
          v4 = v18;
          goto LABEL_17;
        }
        v13 = qword_180092490;
      }
    }
    v5 = 1359;
  }
LABEL_29:
  CCipherMill::DeleteProviderList(v4);
  v4 = v18;
LABEL_18:
  if ( v4 )
    SslFreeBuffer(v4);
  return v5;
}
// 180024EE0: variable 'v4' is possibly undefined
// 180092490: using guessed type __int64 qword_180092490;
// 1800924A0: using guessed type unsigned __int64 qword_1800924A0[32];
// 180098478: using guessed type __int64 __fastcall SslEnumProtocolProviders(_QWORD, _QWORD, _QWORD);
// 180098480: using guessed type __int64 __fastcall SslFreeBuffer(_QWORD);
// 1800984F8: using guessed type __int64 __fastcall SslOpenProvider(_QWORD, _QWORD, _QWORD);
