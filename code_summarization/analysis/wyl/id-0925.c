//----- (000000018004D660) ----------------------------------------------------
__int64 __fastcall SslGetExtensions(
        __int64 a1,
        unsigned int a2,
        struct _SCH_EXTENSION_DATA *a3,
        unsigned __int8 a4,
        unsigned int *a5,
        int a6)
{
  __int64 v6; // rdi
  unsigned int v8; // r9d
  unsigned __int16 v10; // r8
  _DWORD *v11; // rax
  __int64 v12; // rcx

  v6 = a4;
  v8 = 0;
  if ( a1 && a3 && (_BYTE)v6 && a5 )
  {
    if ( !a6 )
    {
      if ( a2 < 5 )
      {
        *a5 = 5 - a2;
        return 2148074264i64;
      }
      if ( ((((*(unsigned __int8 *)(a1 + 1) << 8) | *(unsigned __int8 *)(a1 + 2)) - 65277) & 0xFFFFFFFD) == 0 )
        return 2148074278i64;
      v10 = _byteswap_ushort(*(_WORD *)(a1 + 3));
      if ( (unsigned __int64)v10 + 5 > a2 )
      {
        *a5 = v10 - a2 + 5;
        return 2148074264i64;
      }
      if ( *(_BYTE *)a1 != 22 )
        goto LABEL_19;
      v8 = ProcessRecord((const unsigned __int8 *)(a1 + 5), v10, a3, v6, a5);
      if ( !v8 )
        goto LABEL_19;
      goto LABEL_18;
    }
    if ( (a6 & 1) != 0 )
    {
      v8 = ProcessRecord((const unsigned __int8 *)a1, a2, a3, v6, a5);
LABEL_18:
      if ( v8 )
      {
        v11 = (_DWORD *)((char *)a3 + 16);
        v12 = v6;
        do
        {
          *((_QWORD *)v11 - 1) = 0i64;
          *v11 = 0;
          v11 += 6;
          --v12;
        }
        while ( v12 );
        return v8;
      }
LABEL_19:
      *a5 = 0;
      return v8;
    }
  }
  return 2148074333i64;
}
// 18004D763: conditional instruction was optimized away because di.1!=0
