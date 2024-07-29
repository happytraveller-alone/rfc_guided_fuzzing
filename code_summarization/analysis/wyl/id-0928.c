//----- (000000018004D944) ----------------------------------------------------
__int64 __fastcall ParseSsl2Hello(struct SPBuffer *a1)
{
  unsigned __int8 *v1; // r8
  unsigned int v2; // r9d

  v1 = (unsigned __int8 *)*((_QWORD *)a1 + 1);
  if ( *(_DWORD *)a1 >= 2u
    && (v2 = ((((char)*v1 >> 31) & 0x4000) + 0x3FFF) & (v1[1] | (*v1 << 8)), v2 + 2 <= *(_DWORD *)a1)
    && v2 >= 0xB
    && v1[2] == 1
    && (v1[4] | (v1[3] << 8)) >= 2u
    && (v1[8] | ((unsigned __int64)v1[7] << 8))
     + (v1[10] | ((unsigned __int64)v1[9] << 8))
     + (v1[6] | ((unsigned __int64)v1[5] << 8))
     + 9 <= v2 )
  {
    return 0i64;
  }
  else
  {
    return 2148074278i64;
  }
}

