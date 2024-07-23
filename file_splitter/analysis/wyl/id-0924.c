//----- (000000018004D5A4) ----------------------------------------------------
__int64 __fastcall ProcessRecord(
        const unsigned __int8 *a1,
        unsigned int a2,
        struct _SCH_EXTENSION_DATA *a3,
        unsigned __int8 a4,
        unsigned int *a5)
{
  unsigned int v5; // r10d
  unsigned __int64 v6; // rbx
  __int64 v8; // rdx

  v5 = 0;
  v6 = a2;
  if ( !a1 || !a3 || !a4 || !a5 )
    return 2148074333i64;
  if ( a2 < 4 )
  {
    *a5 = 4 - a2;
    return 2148074264i64;
  }
  v8 = a1[3] + ((a1[2] + (a1[1] << 8)) << 8);
  if ( v8 + 4 > v6 )
  {
    *a5 = v8 - v6 + 4;
    return 2148074264i64;
  }
  if ( *a1 == 1 )
    return (unsigned int)ParseClientHello(a1 + 4, v8, a3, a4);
  return v5;
}

