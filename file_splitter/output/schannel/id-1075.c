// File count: 1075
// Total lines: 75
----------------------------------------
__int64 __fastcall CCipherMill::GetCipherState(
        CCipherMill *this,
        struct CSslContext *a2,
        struct CCipherSuiteInfo **a3,
        int a4,
        unsigned int a5)
{
  CMasterCipherInfo *v8; // rax
  unsigned int v9; // edi
  unsigned int v10; // ebx
  _QWORD *v11; // rdx
  struct CCipherSuiteInfo *v12; // r8
  __int64 v13; // rax
  unsigned int v14; // r10d
  unsigned int v15; // r9d
  __int64 result; // rax

  RtlAcquireResourceShared(&Resource, 1u);
  v8 = xmmword_1800925B0;
  if ( (*((_DWORD *)a2 + 34) & 0x20000000) != 0 )
    v8 = *(&xmmword_1800925B0 + 1);
  v9 = 0;
  if ( v8 )
  {
    v10 = *((_DWORD *)v8 + 2);
    if ( v10 )
    {
      v11 = (_QWORD *)(*(_QWORD *)v8 + 848i64);
      while ( 1 )
      {
        v12 = (struct CCipherSuiteInfo *)(v11 - 106);
        if ( *((_DWORD *)v11 - 205) == a4 )
        {
          v13 = *v11;
          if ( !a5 )
            goto LABEL_15;
          if ( v13 )
          {
            v14 = *(_DWORD *)(v13 + 8);
            v15 = 0;
            if ( v14 )
              break;
          }
        }
LABEL_12:
        ++v9;
        v11 += 108;
        if ( v9 >= v10 )
          goto LABEL_19;
      }
      while ( a5 != *(_DWORD *)(780i64 * v15 + *(_QWORD *)v13 + 772) )
      {
        if ( ++v15 >= v14 )
          goto LABEL_12;
      }
      v13 = *v11;
LABEL_15:
      if ( v13 )
        _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v13 + 16) + 12i64));
      _InterlockedIncrement((volatile signed __int32 *)(*((_QWORD *)v12 + 107) + 12i64));
      *a3 = v12;
    }
  }
  else
  {
    v10 = 0;
  }
LABEL_19:
  RtlReleaseResource(&Resource);
  result = 1168i64;
  if ( v9 != v10 )
    return 0i64;
  return result;
}
