//----- (000000018005E1B0) ----------------------------------------------------
char *__fastcall CSslScratchAllocator::Allocate(CSslScratchAllocator *this, unsigned __int64 a2, char a3)
{
  unsigned __int16 v4; // ax
  unsigned __int16 *v5; // r8
  __int64 v7; // r11
  char *v8; // rcx

  if ( a2 > 0xFFFF )
    return 0i64;
  v4 = a2 + *((_WORD *)this + 10);
  if ( v4 < (unsigned __int16)a2 )
    return 0i64;
  v5 = (unsigned __int16 *)*((_QWORD *)this + 1);
  *((_WORD *)this + 10) = v4;
  if ( !v5 )
    return (char *)SPExternalAlloc((unsigned __int16)a2);
  v7 = *v5;
  if ( v5[1] - (int)v7 <= (unsigned __int16)a2 )
    return (char *)SPExternalAlloc((unsigned __int16)a2);
  if ( a3 )
  {
    v5[1] -= a2;
    v8 = (char *)(*((_QWORD *)this + 1) + *(unsigned __int16 *)(*((_QWORD *)this + 1) + 2i64));
  }
  else
  {
    *v5 = a2 + v7;
    v8 = (char *)v5 + v7;
  }
  return v8 + 4;
}

