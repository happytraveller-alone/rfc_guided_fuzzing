//----- (0000000180064928) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeGenericExtensionsSize(
        __int64 a1,
        int a2)
{
  __int64 v2; // rax
  __int64 *v4; // r8
  __int64 v5; // rax
  __int64 *v6; // r10
  __int64 v7; // r9
  unsigned __int16 v8; // ax
  int v9; // edx
  int v10; // r11d

  v2 = *(_QWORD *)(a1 + 8);
  *(_WORD *)(a1 + 122) = 0;
  v4 = (__int64 *)(v2 + 1480);
  if ( v2 != -1480 )
  {
    v5 = *(unsigned __int8 *)(v2 + 1488);
    if ( (_BYTE)v5 )
    {
      v6 = &v4[v5];
      while ( v4 < v6 )
      {
        v7 = *v4;
        if ( !*v4 )
          return 2148074244i64;
        if ( *(unsigned __int16 *)(v7 + 2) == a2 )
        {
          v8 = *(_WORD *)(a1 + 122);
          if ( v8 > 0xFFFBu )
            return 2148074333i64;
          v9 = (unsigned __int16)(v8 + 4);
          *(_WORD *)(a1 + 122) = v9;
          v10 = *(unsigned __int16 *)(v7 + 8);
          if ( v9 > 0xFFFF - v10 )
            return 2148074333i64;
          *(_WORD *)(a1 + 122) = v10 + v9;
        }
        ++v4;
      }
    }
  }
  return 0i64;
}
