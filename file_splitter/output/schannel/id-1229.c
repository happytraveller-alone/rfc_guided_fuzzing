// File count: 1229
// Total lines: 79
----------------------------------------
__int64 __fastcall GetSslEccCurveTypeOrderFromCipherSuiteList(__int64 a1, _QWORD *a2, unsigned int *a3)
{
  unsigned int v3; // ebx
  unsigned int v6; // edi
  _DWORD *v7; // r15
  unsigned int i; // ebp
  __int64 v9; // rdx
  __int64 v10; // rax
  unsigned int v11; // esi
  const wchar_t **v12; // r14
  const wchar_t *v13; // rax
  int v14; // edx
  __int64 v15; // rcx
  const wchar_t *v18; // [rsp+78h] [rbp+20h]

  v3 = 0;
  v6 = 0;
  if ( a2 && a3 )
  {
    v7 = SPExternalAlloc(0xCu);
    if ( v7 )
    {
      for ( i = 0; i < *(_DWORD *)a1; ++i )
      {
        v9 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8i64 * i);
        v10 = -1i64;
        do
          ++v10;
        while ( *(_WORD *)(v9 + 2 * v10) );
        if ( (unsigned int)v10 >= 5 )
        {
          v11 = 0;
          v12 = (const wchar_t **)&off_18007FE80;
          v13 = (const wchar_t *)(v9 + 2 * ((unsigned int)v10 - 5i64));
          v18 = v13;
          while ( wcsicmp(v13, *v12) )
          {
            v13 = v18;
            ++v11;
            v12 += 99;
            if ( v11 >= 3 )
              goto LABEL_12;
          }
          v14 = 0;
          if ( v6 )
          {
            while ( v7[v14] != *((_DWORD *)&off_18007FE80 + 198 * v11 + 195) )
            {
              if ( ++v14 >= v6 )
                goto LABEL_18;
            }
          }
          else
          {
LABEL_18:
            v15 = v6++;
            v7[v15] = *((_DWORD *)&off_18007FE80 + 198 * v11 + 195);
          }
LABEL_12:
          if ( v6 == 3 )
            break;
        }
      }
      *a3 = v6;
      *a2 = v7;
    }
    else
    {
      return (unsigned int)-1073741670;
    }
  }
  else
  {
    return (unsigned int)-1073741811;
  }
  return v3;
}
// 18007FE80: using guessed type wchar_t *off_18007FE80;
