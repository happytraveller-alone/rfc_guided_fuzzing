// File count: 1173
// Total lines: 39
----------------------------------------
__int64 __fastcall SPFindIssuerInCache(unsigned __int8 *Buf1, unsigned int a2)
{
  unsigned int v2; // edi
  size_t v3; // rsi
  __int64 v5; // r14
  unsigned int TickCount; // r15d
  _QWORD **v7; // r14
  _QWORD *v8; // rbx
  unsigned int v9; // ecx
  __int64 v10; // r9

  v2 = 0;
  v3 = a2;
  if ( !Buf1 || !a2 || !dword_180092778 )
    return 0i64;
  v5 = (unsigned int)ComputeIssuerCacheIndex(Buf1, a2) % dword_1800926FC;
  TickCount = GetTickCount();
  RtlAcquireResourceShared(&stru_180092718, 1u);
  v7 = (_QWORD **)((char *)IssuerCache + 16 * v5);
  v8 = *v7;
  while ( v8 != v7 )
  {
    v9 = *((_DWORD *)v8 - 6);
    v8 = (_QWORD *)*v8;
    if ( !HasTimeElapsed(v9, TickCount, dword_1800926F8)
      && (_DWORD)v3 == *(_DWORD *)(v10 + 16)
      && !memcmp_0(Buf1, *(const void **)(v10 + 8), v3) )
    {
      v2 = 1;
      break;
    }
  }
  RtlReleaseResource(&stru_180092718);
  return v2;
}
// 18005DD7A: variable 'v10' is possibly undefined
// 1800926FC: using guessed type int dword_1800926FC;
// 180092778: using guessed type int dword_180092778;
