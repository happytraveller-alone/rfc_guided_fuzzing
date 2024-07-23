// File count: 91
// Total lines: 94
------------------------------------------
__int64 __fastcall CTlsSignatureSuiteList::GetRunningHashList(
        CTlsSignatureSuiteList *this,
        const unsigned __int16 *a2,
        int a3,
        enum _eTlsHashAlgorithm *const a4,
        wchar_t **a5,
        unsigned int *a6)
{
  unsigned __int8 v6; // bl
  unsigned int v10; // ebp
  unsigned int v11; // r14d
  signed int v12; // edi
  unsigned int HashDetailsFromIndex; // eax
  wchar_t *v14; // rsi
  int v15; // eax
  char v16; // cl
  enum _eTlsHashAlgorithm *v17; // rdx
  unsigned __int16 v18; // r9
  __int64 v19; // r10
  int v20; // eax
  enum _eTlsHashAlgorithm v21; // r8d
  int v22; // eax
  __int64 v24; // rcx
  __int64 v25; // [rsp+20h] [rbp-48h]
  enum _eTlsHashAlgorithm v26; // [rsp+30h] [rbp-38h] BYREF
  wchar_t *String2; // [rsp+38h] [rbp-30h] BYREF

  v6 = 0;
  v26 = TlsHashAlgorithm_None;
  String2 = 0i64;
  v10 = -2146893007;
  v11 = 0;
  v12 = 4;
  if ( g_dwHashInfoTotalCount > 4 )
  {
    while ( 1 )
    {
      HashDetailsFromIndex = I_GetHashDetailsFromIndex(v12, &String2, 0i64, (__int64)a4, v25, &v26);
      v14 = String2;
      v10 = HashDetailsFromIndex;
      if ( !HashDetailsFromIndex && !wcsnicmp(a2, String2, 0x40ui64) )
        break;
      v15 = g_dwHashInfoTotalCount;
      if ( ++v12 >= g_dwHashInfoTotalCount )
        goto LABEL_5;
    }
    v15 = g_dwHashInfoTotalCount;
LABEL_5:
    if ( v12 < v15 && v14 )
    {
      v16 = v26;
      v17 = (enum _eTlsHashAlgorithm *)&unk_18007C3B8;
      v11 = 1;
      *a4 = v26;
      v10 = 0;
      v18 = 1 << v16;
      *a5 = v14;
      v19 = 12i64;
      do
      {
        if ( v6 < 0xCu )
        {
          v20 = *((unsigned __int16 *)this + 17);
          if ( _bittest(&v20, v6) )
          {
            if ( (a3 & *(v17 - 4)) != 0 )
            {
              v21 = *v17;
              v22 = v18;
              if ( !_bittest(&v22, *v17) )
              {
                v24 = v11;
                v18 |= 1 << v21;
                ++v11;
                a4[v24] = v21;
                a5[v24] = (wchar_t *)*((_QWORD *)v17 + 1);
              }
            }
          }
        }
        v17 += 18;
        ++v6;
        --v19;
      }
      while ( v19 );
    }
  }
  *a6 = v11;
  return v10;
}
// 180006E5D: variable 'a4' is possibly undefined
// 180006E5D: variable 'v25' is possibly undefined
// 180092324: using guessed type int g_dwHashInfoTotalCount;
