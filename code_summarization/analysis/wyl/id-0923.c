//----- (000000018004D4E4) ----------------------------------------------------
__int64 __fastcall ParseTlsHelloExtensions(
        const unsigned __int8 *a1,
        unsigned int a2,
        struct _SCH_EXTENSION_DATA *a3,
        unsigned __int8 a4)
{
  unsigned int v4; // esi
  const unsigned __int8 *v6; // r10
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // r8d
  int v10; // eax
  const unsigned __int8 *v11; // r10
  unsigned int v12; // r8d
  __int64 v13; // rcx
  struct _SCH_EXTENSION_DATA *v14; // r9
  __int64 v15; // rcx

  v4 = a4;
  v6 = a1;
  if ( !a1 || !a3 || !a4 )
    return 2148074333i64;
  if ( !a2 )
    return 0i64;
  while ( a2 >= 4 )
  {
    v7 = a2 - 4;
    v8 = v6[1] | (*v6 << 8);
    v9 = v6[2] << 8;
    v10 = v6[3];
    v11 = v6 + 4;
    v12 = v10 | v9;
    if ( v7 < v12 )
      break;
    v13 = 0i64;
    if ( (_BYTE)v4 )
    {
      v14 = a3;
      while ( v8 != *(unsigned __int16 *)v14 )
      {
        v13 = (unsigned int)(v13 + 1);
        v14 = (struct _SCH_EXTENSION_DATA *)((char *)v14 + 24);
        if ( (unsigned int)v13 >= v4 )
          goto LABEL_13;
      }
      v15 = 3 * v13;
      *((_QWORD *)a3 + v15 + 1) = v11;
      *((_DWORD *)a3 + 2 * v15 + 4) = v12;
    }
LABEL_13:
    v6 = &v11[v12];
    a2 = v7 - v12;
    if ( !a2 )
      return 0i64;
  }
  return 2148074278i64;
}

