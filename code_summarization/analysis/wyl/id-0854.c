//----- (000000018004538C) ----------------------------------------------------
__int64 __fastcall RtlStringCchCopyNW(char *a1, __int64 a2, char *a3, unsigned __int64 a4)
{
  __int64 v4; // r10
  __int64 result; // rax
  __int64 v6; // r9
  signed __int64 v7; // r8
  unsigned __int16 v8; // ax
  unsigned __int16 *v9; // rax

  v4 = a2;
  if ( (unsigned __int64)(a2 - 1) > 0x7FFFFFFE )
  {
    result = 3221225485i64;
    if ( !a2 )
      return result;
    goto LABEL_12;
  }
  if ( a4 > 0x7FFFFFFE )
  {
    result = 3221225485i64;
LABEL_12:
    *(_WORD *)a1 = 0;
    return result;
  }
  v6 = a4 - a2;
  v7 = a3 - a1;
  do
  {
    if ( !(v6 + v4) )
      break;
    v8 = *(_WORD *)&a1[v7];
    if ( !v8 )
      break;
    *(_WORD *)a1 = v8;
    a1 += 2;
    --v4;
  }
  while ( v4 );
  v9 = (unsigned __int16 *)(a1 - 2);
  if ( v4 )
    v9 = (unsigned __int16 *)a1;
  *v9 = 0;
  return v4 == 0 ? 0x80000005 : 0;
}

