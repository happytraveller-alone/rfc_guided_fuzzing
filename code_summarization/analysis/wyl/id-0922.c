//----- (000000018004D388) ----------------------------------------------------
__int64 __fastcall ParseClientHello(
        const unsigned __int8 *a1,
        unsigned int a2,
        struct _SCH_EXTENSION_DATA *a3,
        unsigned __int8 a4)
{
  unsigned int v4; // r10d
  unsigned int v7; // edx
  const unsigned __int8 *v8; // r11
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned __int16 *v13; // r9
  unsigned __int16 v14; // cx
  unsigned int v15; // edx
  unsigned int v16; // edx
  _BYTE *v17; // rcx
  unsigned int v18; // eax
  unsigned int v19; // edx
  __int64 v20; // r8
  unsigned int v21; // edx
  unsigned int v22; // r11d

  v4 = 0;
  if ( !a1 || !a2 || !a3 || !a4 )
    return 2148074333i64;
  if ( a2 < 2 )
    return (unsigned int)-2146893018;
  if ( ((*a1 << 8) | (unsigned int)a1[1]) - 769 > 0xFBFB )
    return (unsigned int)-2146893018;
  v7 = a2 - 2;
  if ( v7 < 0x20 )
    return (unsigned int)-2146893018;
  v8 = a1 + 34;
  v9 = v7 - 32;
  if ( !v9 )
    return (unsigned int)-2146893018;
  if ( *v8 > 0x20u )
    return (unsigned int)-2146893018;
  v10 = *v8;
  v11 = v9 - 1;
  if ( v11 < v10 )
    return (unsigned int)-2146893018;
  v12 = v11 - v10;
  v13 = (unsigned __int16 *)&v8[*v8 + 1];
  if ( v12 < 2 )
    return (unsigned int)-2146893018;
  v14 = _byteswap_ushort(*v13);
  if ( v14 >= 2u
    && (v14 & 1) == 0
    && (v15 = v12 - 2, v15 >= v14)
    && (v16 = v15 - v14, v17 = (char *)v13 + v14 + 2, v16)
    && *v17
    && (v18 = (unsigned __int8)*v17, v19 = v16 - 1, v19 >= v18) )
  {
    v20 = (unsigned __int8)*v17;
    v21 = v19 - v18;
    if ( v21 >= 2 )
    {
      v22 = (unsigned __int8)v17[v20 + 2] | ((unsigned __int8)v17[v20 + 1] << 8);
      if ( v21 >= v22 )
        return (unsigned int)ParseTlsHelloExtensions(&v17[v20 + 3], v22, a3, a4);
    }
  }
  else
  {
    return (unsigned int)-2146893018;
  }
  return v4;
}

