//----- (0000000180058B94) ----------------------------------------------------
void __fastcall DbgDumpTlsParams(struct _TLS_PARAMETERS *a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // r15d
  unsigned int v4; // esi
  CCipherMill *v5; // rbx
  _DWORD *v6; // rdi
  __int64 v7; // r14
  unsigned int v8; // r12d
  unsigned int v9; // ebp
  __int64 v10; // r14
  __m128i v11; // xmm0
  char *v12; // rcx
  unsigned __int64 v13; // r9
  __int16 v14; // ax
  char *v15; // rax
  __int64 v16; // [rsp+20h] [rbp-F8h]
  __int64 v17; // [rsp+28h] [rbp-F0h]
  unsigned int v18; // [rsp+50h] [rbp-C8h]
  char v19[128]; // [rsp+60h] [rbp-B8h] BYREF

  if ( a1 )
  {
    v18 = a2;
    v3 = a2;
    v4 = 0;
    if ( (_DWORD)a2 )
    {
      v5 = WPP_GLOBAL_Control;
      v6 = (_DWORD *)((char *)a1 + 32);
      do
      {
        if ( v5 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
        {
          LODWORD(v17) = *(v6 - 4);
          LODWORD(v16) = *v6;
          WPP_SF_dDD(*((_QWORD *)v5 + 2), a2, a3, v4, v16, v17);
          v5 = WPP_GLOBAL_Control;
        }
        v7 = *((_QWORD *)v6 - 1);
        v8 = *(v6 - 3);
        if ( v7 )
        {
          v9 = 0;
          if ( v8 )
          {
            v10 = v7 + 40;
            do
            {
              memset_0(v19, 0, sizeof(v19));
              v11 = *(__m128i *)(v10 - 32);
              a2 = 64i64;
              v12 = v19;
              a3 = (unsigned __int64)(unsigned __int16)_mm_cvtsi128_si32(v11) >> 1;
              v13 = _mm_srli_si128(v11, 8).m128i_u64[0] - (_QWORD)v19;
              do
              {
                if ( !(a3 + a2 - 64) )
                  break;
                v14 = *(_WORD *)&v12[v13];
                if ( !v14 )
                  break;
                *(_WORD *)v12 = v14;
                v12 += 2;
                --a2;
              }
              while ( a2 );
              v15 = v12 - 2;
              if ( a2 )
                v15 = v12;
              *(_WORD *)v15 = 0;
              if ( v5 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
              {
                WPP_SF_dddSdd(*((_QWORD *)v5 + 2), a2, a3, v4, v9, *(_DWORD *)(v10 - 40), (__int64)v19);
                v5 = WPP_GLOBAL_Control;
              }
              ++v9;
              v10 += 48i64;
            }
            while ( v9 < v8 );
            v3 = v18;
          }
        }
        ++v4;
        v6 += 10;
      }
      while ( v4 < v3 );
    }
  }
}
// 180058C14: variable 'a2' is possibly undefined
// 180058C14: variable 'a3' is possibly undefined
// 180058C14: variable 'v16' is possibly undefined
// 180058C14: variable 'v17' is possibly undefined

