// File count: 1052
// Total lines: 46
----------------------------------------
void __fastcall DbgDumpSubCreds(struct LSA_SCHANNEL_SUB_CRED *a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // edi
  struct LSA_SCHANNEL_SUB_CRED *v5; // rbx
  CCipherMill *v6; // rcx
  __int64 v7; // rdx
  __int64 v8; // [rsp+20h] [rbp-28h]

  if ( a1 )
  {
    v3 = 0;
    v5 = a1;
    if ( a2 )
    {
      v6 = WPP_GLOBAL_Control;
      do
      {
        if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 4) != 0 )
        {
          LODWORD(v8) = *((_DWORD *)v5 + 12);
          WPP_SF_dD(*((_QWORD *)v6 + 2), 0xBu, a3, v3, v8);
          v6 = WPP_GLOBAL_Control;
        }
        v7 = *(_QWORD *)v5;
        if ( *(_QWORD *)v5 )
        {
          a3 = *(_QWORD *)(v7 + 24);
          if ( a3 )
          {
            if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 4) != 0 )
            {
              WPP_SF_dDDs(*((_QWORD *)v6 + 2), v7, a3, v3, *(_DWORD *)v7, *(_DWORD *)a3, *(_QWORD *)(a3 + 24));
              v6 = WPP_GLOBAL_Control;
            }
          }
        }
        ++v3;
        v5 = (struct LSA_SCHANNEL_SUB_CRED *)((char *)v5 + 56);
      }
      while ( v3 < a2 );
    }
  }
}
// 180058B1C: variable 'a3' is possibly undefined
// 180058B1C: variable 'v8' is possibly undefined
