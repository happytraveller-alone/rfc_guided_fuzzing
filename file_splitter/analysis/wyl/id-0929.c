//----- (000000018004D9F8) ----------------------------------------------------
__int64 __fastcall ParseTlsHelloExtensions(unsigned __int8 *a1, unsigned int a2, struct SPBuffer *a3)
{
  unsigned int v4; // ebx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  int v8; // r8d
  int v9; // eax
  unsigned __int8 *v10; // rdi
  int v11; // r8d
  unsigned __int8 *v12; // rcx
  __int64 result; // rax

  v4 = a2;
  if ( !a2 )
    return 0i64;
  while ( v4 >= 4 )
  {
    v6 = v4 - 4;
    v7 = a1[3] | (a1[2] << 8);
    v8 = *a1 << 8;
    v9 = a1[1];
    v10 = a1 + 4;
    v11 = v9 | v8;
    if ( v6 < v7 )
      break;
    v12 = v10;
    a1 = &v10[v7];
    v4 = v6 - v7;
    if ( !v11 )
    {
      result = ParseSniExtension(v12, v7, a3);
      if ( (_DWORD)result )
        return result;
    }
    if ( !v4 )
      return 0i64;
  }
  return 2148074278i64;
}
