//----- (0000000180005324) ----------------------------------------------------
void __fastcall CSslContext::SetEccCurveInfo(CSslContext *this, int a2)
{
  __int64 v2; // rax
  __int64 *v4; // r9
  unsigned int v5; // r10d
  unsigned int v6; // r8d
  __int64 v7; // r11
  __int64 v8; // rdx

  v2 = *((_QWORD *)this + 1);
  *((_DWORD *)this + 4) = a2;
  v4 = *(__int64 **)(v2 + 848);
  if ( v4 )
  {
    v5 = *((_DWORD *)v4 + 2);
    v6 = 0;
    if ( v5 )
    {
      v7 = *v4;
      while ( 1 )
      {
        v8 = 780i64 * v6;
        if ( *(_DWORD *)(v7 + v8 + 772) == a2 )
          break;
        if ( ++v6 >= v5 )
          return;
      }
      if ( v7 + v8 )
        *((_DWORD *)this + 5) = *(_DWORD *)(v7 + v8 + 776);
    }
  }
}

