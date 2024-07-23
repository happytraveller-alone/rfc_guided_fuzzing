// File count: 323
// Total lines: 51
-----------------------------------------
__int64 __fastcall CSslLookaside::RunBalancer(CSslLookaside *this, unsigned int a2)
{
  int v4; // eax
  int v5; // ecx
  int v6; // r9d
  char v7; // cl
  int v8; // edx
  int v9; // edx
  int v10; // edi
  PSLIST_ENTRY v11; // rax

  if ( *((_BYTE *)this + 32) && a2 )
  {
    v4 = *((_DWORD *)this + 15);
    v5 = v4 - *((_DWORD *)this + 14);
    *((_DWORD *)this + 14) = v4;
    v6 = *((_DWORD *)this + 17) - *((_DWORD *)this + 16);
    *((_DWORD *)this + 16) = *((_DWORD *)this + 17);
    if ( 60 * v5 / a2 >= *((_DWORD *)this + 12) )
    {
      if ( v6 )
        return 0i64;
      v8 = *((_DWORD *)this + 13);
      if ( v8 <= v5 )
        return 0i64;
      v7 = *((_BYTE *)this + 33) + 1;
    }
    else
    {
      v7 = *((_BYTE *)this + 33);
      v8 = *((_DWORD *)this + 13);
    }
    v9 = v8 >> v7;
    v10 = v9 + 1;
    if ( v9 != -1 )
    {
      do
      {
        if ( *((_DWORD *)this + 13) <= *((_DWORD *)this + 10) )
          break;
        v11 = InterlockedPopEntrySList((PSLIST_HEADER)this + 1);
        SPExternalFree(v11);
        _InterlockedDecrement((volatile signed __int32 *)this + 13);
        --v10;
      }
      while ( v10 );
    }
  }
  return 0i64;
}
