// File count: 218
// Total lines: 123
----------------------------------------
__int64 __fastcall InsertEventEntryInLookUpTable(
        __int64 a1,
        __int128 *a2,
        unsigned __int8 a3,
        __int64 a4,
        unsigned __int8 a5)
{
  __int64 v5; // rbx
  signed __int64 v7; // rdi
  unsigned int v9; // ebp
  int v10; // r14d
  volatile signed __int64 *i; // rsi
  unsigned int v12; // eax
  unsigned int v13; // eax
  __int64 v15; // rsi
  int v16; // eax
  unsigned __int8 v17; // dl
  unsigned int v18; // r10d
  signed __int64 v19; // r8
  __int64 v20; // rax
  int v21; // r11d
  volatile signed __int64 *v22; // r9
  volatile signed __int64 v23; // rtt
  __int64 v24; // [rsp+70h] [rbp+8h] BYREF
  __int128 *v25; // [rsp+78h] [rbp+10h]

  v25 = a2;
  v5 = *(_QWORD *)(a1 + 48);
  v7 = 0i64;
  v24 = 0i64;
  v9 = 0;
  v10 = ComputeEventEntryHash(a5, a3, a4);
  AcquireSRWLockShared((PSRWLOCK)(v5 + 264));
  for ( i = (volatile signed __int64 *)(v5 + 8i64 * (v10 & 0x1F));
        ;
        i = (volatile signed __int64 *)((((__int64)v16 >> 63) & 0xFFFFFFFFFFFFFFF8ui64) + v15 + 32) )
  {
    if ( !*i )
    {
      if ( *(_DWORD *)(v5 + 256) >= 0x400u )
      {
        ++*(_DWORD *)(v5 + 300);
        v9 = 234;
        goto LABEL_11;
      }
      if ( !v7 )
      {
        v12 = CreateNewEventEntry(v25, a3, a4, a5, v10, &v24);
        v7 = v24;
        v9 = v12;
        if ( !v24 )
        {
          if ( v12 == 8 )
            ++*(_DWORD *)(v5 + 304);
          else
            ++*(_DWORD *)(v5 + 308);
          goto LABEL_11;
        }
      }
      if ( !_InterlockedCompareExchange64(i, v7, 0i64) )
      {
        v24 = 0i64;
        if ( _InterlockedIncrement((volatile signed __int32 *)(v5 + 256)) == 1 )
          EnableFlushTimer(*(struct _TP_TIMER **)(v5 + 344), *(_DWORD *)(v5 + 352));
        v13 = *(_DWORD *)(v5 + 256);
        v7 = v24;
        if ( *(_DWORD *)(v5 + 288) < v13 )
          *(_DWORD *)(v5 + 288) = v13;
        goto LABEL_11;
      }
      v7 = v24;
    }
    v15 = *i;
    v16 = v10 == *(_DWORD *)(v15 + 40) ? CompareEventEntry(a3, a4, v15) : v10 - *(_DWORD *)(v15 + 40);
    if ( !v16 )
      break;
  }
  if ( v15 )
  {
    v17 = 2;
    v18 = a5 + 2;
    if ( v18 > 2 )
    {
      do
      {
        v19 = **(_QWORD **)(a4 + 16i64 * v17);
        v20 = *(_QWORD *)(v15 + 16);
        v21 = *(unsigned __int8 *)(v20 + 16i64 * v17 + 13);
        v22 = *(volatile signed __int64 **)(v20 + 16i64 * v17);
        if ( v21 == 113 )
        {
          _InterlockedExchangeAdd64(v22, v19);
        }
        else if ( (unsigned int)(v21 - 114) <= 1 )
        {
          do
          {
            if ( (_BYTE)v21 == 114 )
            {
              if ( v19 >= *v22 )
                break;
            }
            else if ( v19 <= *v22 )
            {
              break;
            }
            v23 = *v22;
          }
          while ( v23 != _InterlockedCompareExchange64(v22, v19, *v22) );
        }
        ++v17;
      }
      while ( v17 < v18 );
      v7 = v24;
    }
  }
LABEL_11:
  ReleaseSRWLockShared((PSRWLOCK)(v5 + 264));
  if ( v7 )
    DestroyEventEntry(v7);
  return v9;
}
