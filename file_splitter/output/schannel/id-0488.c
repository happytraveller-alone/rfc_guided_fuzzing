// File count: 488
// Total lines: 20
-----------------------------------------
void __fastcall UpdateInternalStatsOnFlush(__int64 a1, unsigned int a2)
{
  __int64 *v2; // r8
  __int64 v3; // rax

  if ( a2 )
  {
    v2 = (__int64 *)(a1 + 280);
    if ( *(_DWORD *)(a1 + 296) > a2 || (v3 = *v2) == 0 )
    {
      v3 = *v2;
      *(_DWORD *)(a1 + 296) = a2;
    }
    if ( *(_DWORD *)(a1 + 292) < a2 )
      *(_DWORD *)(a1 + 292) = a2;
    *v2 = v3 + 1;
    *(_QWORD *)(a1 + 272) += a2;
  }
}
