//----- (0000000180061C24) ----------------------------------------------------
__int64 __fastcall CCipherMill::EnumEccCurvesFromCipherToProvTable(
        CCipherMill *this,
        struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *a2,
        unsigned int a3,
        unsigned int *a4,
        struct _NCRYPT_SSL_ECC_CURVE **a5)
{
  unsigned int v5; // ebx
  unsigned int v9; // edi
  struct _NCRYPT_SSL_ECC_CURVE *v10; // r8
  unsigned int v11; // r10d
  unsigned int v12; // r9d
  _DWORD *v13; // rax
  unsigned int v14; // edx
  __int64 v15; // rdx
  __int64 v16; // rax
  char *v17; // r9
  char *v18; // rcx
  __int128 v19; // xmm0

  v5 = 0;
  v9 = 0;
  if ( !a4 || !a5 )
    return 3221225485i64;
  *a5 = 0i64;
  *a4 = 0;
  v10 = (struct _NCRYPT_SSL_ECC_CURVE *)SPExternalAlloc(0x924u);
  if ( v10 )
  {
    v11 = 0;
    if ( a3 )
    {
      while ( 1 )
      {
        v12 = 0;
        v13 = &unk_18008018C;
        while ( *(_DWORD *)(*(_QWORD *)a2 + 676i64) != *v13 )
        {
          ++v12;
          v13 += 198;
          if ( v12 >= 3 )
            goto LABEL_16;
        }
        v14 = 0;
        if ( v9 )
        {
          while ( *((_DWORD *)&off_18007FE80 + 198 * v12 + 195) != *((_DWORD *)v10 + 195 * v14 + 193) )
          {
            if ( ++v14 >= v9 )
              goto LABEL_13;
          }
        }
        else
        {
LABEL_13:
          v15 = 792i64 * v12;
          v16 = 6i64;
          v17 = (char *)v10 + 780 * v9;
          v18 = (char *)&off_18007FE80 + v15 + 8;
          do
          {
            v19 = *(_OWORD *)v18;
            v18 += 128;
            *(_OWORD *)v17 = v19;
            v17 += 128;
            *((_OWORD *)v17 - 7) = *((_OWORD *)v18 - 7);
            *((_OWORD *)v17 - 6) = *((_OWORD *)v18 - 6);
            *((_OWORD *)v17 - 5) = *((_OWORD *)v18 - 5);
            *((_OWORD *)v17 - 4) = *((_OWORD *)v18 - 4);
            *((_OWORD *)v17 - 3) = *((_OWORD *)v18 - 3);
            *((_OWORD *)v17 - 2) = *((_OWORD *)v18 - 2);
            *((_OWORD *)v17 - 1) = *((_OWORD *)v18 - 1);
            --v16;
          }
          while ( v16 );
          ++v9;
          *(_QWORD *)v17 = *(_QWORD *)v18;
          *((_DWORD *)v17 + 2) = *((_DWORD *)v18 + 2);
        }
LABEL_16:
        if ( v9 == 3 )
          break;
        ++v11;
        a2 = (struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *)((char *)a2 + 16);
        if ( v11 >= a3 )
        {
          if ( !v9 )
            goto LABEL_20;
          break;
        }
      }
      *a5 = v10;
      *a4 = v9;
    }
    else
    {
LABEL_20:
      SPExternalFree(v10);
    }
  }
  else
  {
    return 14;
  }
  return v5;
}
// 18007FE80: using guessed type wchar_t *off_18007FE80;
