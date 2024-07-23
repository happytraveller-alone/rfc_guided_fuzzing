//----- (0000000180001E7C) ----------------------------------------------------
void __fastcall ReverseInPlace(unsigned __int8 *a1, unsigned int a2)
{
  unsigned int v2; // ebx
  unsigned __int8 *v3; // r11
  unsigned __int8 v4; // r8
  unsigned int v5; // eax
  __int64 v6; // rax

  v2 = 0;
  if ( a2 >> 1 )
  {
    v3 = a1;
    do
    {
      v4 = *v3;
      v5 = a2 - v2++;
      v6 = v5 - 1;
      *v3++ = a1[v6];
      a1[(unsigned int)v6] = v4;
    }
    while ( v2 < a2 >> 1 );
  }
}

// 数组反转