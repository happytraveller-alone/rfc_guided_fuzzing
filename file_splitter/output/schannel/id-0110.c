// File count: 110
// Total lines: 97
-----------------------------------------
void __fastcall FreeTlsParameters(struct _TLS_PARAMETERS *a1, unsigned int a2)
{
  unsigned int v2; // r12d
  char *v5; // rbx
  unsigned int i; // edi
  void *v7; // rcx
  __int64 j; // r14
  __int64 v9; // rdi
  void *v10; // rcx
  void *v11; // rdx
  void *v12; // rcx
  __int64 v13; // rcx
  void *v14; // rcx
  unsigned int v15; // r15d
  void *v16; // rcx

  v2 = 0;
  if ( a2 )
  {
    v5 = (char *)a1 + 20;
    while ( a1 )
    {
      for ( i = 0; i < *((_DWORD *)v5 - 5); ++i )
      {
        v13 = *(_QWORD *)(v5 - 12);
        if ( v13 )
        {
          v14 = *(void **)(v13 + 16i64 * i + 8);
          if ( v14 )
            SPExternalFree(v14);
        }
      }
      v7 = *(void **)(v5 - 12);
      if ( v7 )
      {
        SPExternalFree(v7);
        *(_QWORD *)(v5 - 12) = 0i64;
        *((_DWORD *)v5 - 5) = 0;
      }
      for ( j = 0i64; (unsigned int)j < *(_DWORD *)v5; j = (unsigned int)(j + 1) )
      {
        v9 = *(_QWORD *)(v5 + 4);
        if ( !v9 )
          break;
        v10 = *(void **)(v9 + 48 * j + 16);
        if ( v10 )
          SPExternalFree(v10);
        v11 = *(void **)(v9 + 48 * j + 32);
        if ( v11 )
        {
          v15 = 0;
          if ( *(_DWORD *)(v9 + 48 * j + 24) )
          {
            do
            {
              v16 = v11;
              if ( v11 && *((_QWORD *)v11 + 2 * v15 + 1) )
              {
                SPExternalFree(*((void **)v11 + 2 * v15 + 1));
                v11 = *(void **)(v9 + 48 * j + 32);
                v16 = v11;
              }
              ++v15;
            }
            while ( v15 < *(_DWORD *)(v9 + 48 * j + 24) );
            if ( !v16 )
              continue;
          }
          else
          {
            v16 = *(void **)(v9 + 48 * j + 32);
          }
          SPExternalFree(v16);
          *(_QWORD *)(v9 + 48 * j + 32) = 0i64;
        }
      }
      v12 = *(void **)(v5 + 4);
      if ( v12 )
      {
        SPExternalFree(v12);
        *(_QWORD *)(v5 + 4) = 0i64;
        *(_DWORD *)v5 = 0;
      }
      ++v2;
      v5 += 40;
      if ( v2 >= a2 )
        goto LABEL_16;
    }
  }
  else
  {
LABEL_16:
    if ( a1 )
      SPExternalFree(a1);
  }
}
