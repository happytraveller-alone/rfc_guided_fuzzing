//----- (000000018004DA80) ----------------------------------------------------
__int64 __fastcall ProcessRecord(int a1, _BYTE *a2, unsigned int a3, __int64 a4)
{
  __int64 result; // rax
  __int64 v8; // rbx

  if ( a1 != 22 )
    return 0i64;
  while ( a3 >= 4 )
  {
    if ( *a2 != 1 )
      return 2148074248i64;
    v8 = (unsigned __int8)a2[3] + ((unsigned __int8)a2[1] << 16) + ((unsigned __int8)a2[2] << 8);
    if ( v8 + 4 > (unsigned __int64)a3 )
    {
      *(_QWORD *)(a4 + 8) = 0i64;
      *(_DWORD *)a4 = v8 - a3 + 4;
      return 2148074264i64;
    }
    result = ParseClientHello(a2 + 4, v8, (struct SPBuffer *)a4);
    if ( !(_DWORD)result )
    {
      a2 += v8 + 4;
      a3 += -4 - v8;
      if ( a3 )
        continue;
    }
    return result;
  }
  *(_QWORD *)(a4 + 8) = 0i64;
  *(_DWORD *)a4 = 4 - a3;
  return 2148074264i64;
}
