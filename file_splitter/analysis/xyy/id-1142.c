//----- (000000018005C734) ----------------------------------------------------
char __fastcall IsDheAlgorithmBlacklisted(
        struct _TLS_PARAMETERS *a1,
        unsigned int a2,
        unsigned int a3,
        struct _UNICODE_STRING *a4,
        unsigned __int8 a5)
{
  __int64 v5; // r10
  unsigned int v7; // ebp
  struct _TLS_PARAMETERS *v8; // rbx
  struct kexch *KeyExchangeInfo; // rax
  struct _TLS_PARAMETERS *v10; // r14
  char v11; // si
  unsigned int v12; // edi
  unsigned __int64 v13; // rdi
  unsigned __int64 i; // rcx
  int v16; // [rsp+20h] [rbp-28h]
  int v17; // [rsp+20h] [rbp-28h]
  int v18; // [rsp+28h] [rbp-20h]

  v5 = a2;
  v7 = a3;
  v8 = a1;
  if ( !a2 || !a1 )
    return 0;
  if ( !a3 )
  {
    KeyExchangeInfo = GetKeyExchangeInfo(43522);
    if ( KeyExchangeInfo )
    {
      v7 = *((_DWORD *)KeyExchangeInfo + 12);
      goto LABEL_6;
    }
    return 0;
  }
LABEL_6:
  v10 = (struct _TLS_PARAMETERS *)((char *)v8 + 40 * v5);
  if ( v8 < v10 )
  {
    v11 = 1;
    do
    {
      if ( *((_DWORD *)v8 + 5) )
      {
        if ( *(_DWORD *)v8 )
        {
          if ( !a4 )
            goto LABEL_33;
          v12 = 0;
          while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*((_QWORD *)v8 + 1) + 16i64 * v12), a4, 1u) )
          {
            if ( ++v12 >= *(_DWORD *)v8 )
              goto LABEL_33;
          }
        }
        if ( !a5 || (*((_BYTE *)v8 + 32) & 1) == 0 )
        {
          v13 = *((_QWORD *)v8 + 3);
          for ( i = v13 + 48i64 * *((unsigned int *)v8 + 5);
                v13 < i;
                i = *((_QWORD *)v8 + 3) + 48i64 * *((unsigned int *)v8 + 5) )
          {
            if ( !*(_DWORD *)v13 && *(_WORD *)(v13 + 8) == 4 && !wcsncmp(*(const wchar_t **)(v13 + 16), L"DH", 2ui64) )
            {
              if ( !*(_DWORD *)(v13 + 24) && !*(_DWORD *)(v13 + 40) && !*(_DWORD *)(v13 + 44) )
              {
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  v16 = 0;
                  WPP_SF_Sd(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    0xCu,
                    (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
                    L"DH",
                    v16);
                }
                return v11;
              }
              if ( v7 )
              {
                if ( *(_DWORD *)(v13 + 40) )
                {
                  if ( *(_DWORD *)(v13 + 40) > v7 )
                    goto LABEL_39;
                }
                else if ( !*(_DWORD *)(v13 + 44) )
                {
                  goto LABEL_31;
                }
                if ( *(_DWORD *)(v13 + 44) && *(_DWORD *)(v13 + 44) < v7 )
                {
LABEL_39:
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                  {
                    v18 = 0;
                    v17 = v7;
                    WPP_SF_Sdd(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      0xEu,
                      (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
                      L"DH",
                      v17,
                      v18);
                  }
                  return v11;
                }
              }
            }
LABEL_31:
            v13 += 48i64;
          }
        }
      }
LABEL_33:
      v8 = (struct _TLS_PARAMETERS *)((char *)v8 + 40);
    }
    while ( v8 < v10 );
  }
  return 0;
}
// 18005C790: variable 'v5' is possibly undefined
