//----- (00000001800520E0) ----------------------------------------------------
__int64 __fastcall UploadCertStoreCallback(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  unsigned int v5; // ebx
  CCipherMill *v9; // rcx
  _DWORD *v10; // r14
  int v11; // edx
  _QWORD *v12; // r10
  DWORD LastError; // eax
  __int128 pvSaveToPara; // [rsp+30h] [rbp-28h] BYREF

  v5 = 0;
  pvSaveToPara = 0i64;
  if ( !(unsigned int)SchannelInit(1) )
    return 2148074244i64;
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
      v9 = WPP_GLOBAL_Control;
    }
    if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)v9 + 2), 33i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
      v9 = WPP_GLOBAL_Control;
    }
  }
  if ( a4 )
  {
    v10 = (_DWORD *)*((_QWORD *)a4 + 1);
    if ( v10 )
    {
      v11 = *a4;
      if ( (unsigned int)*a4 >= 4 )
      {
        if ( a3 )
        {
          v12 = *(_QWORD **)(a3 + 8);
          if ( v12 )
          {
            if ( a1 )
            {
              if ( a1 == 1 && *(_DWORD *)a3 == 40 )
              {
                v12 = (_QWORD *)v12[4];
LABEL_19:
                *((_QWORD *)&pvSaveToPara + 1) = v10 + 1;
                LODWORD(pvSaveToPara) = v11 - 4;
                if ( !CertSaveStore(v12, 1u, 1u, 2u, &pvSaveToPara, 0) )
                {
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                  {
                    LastError = GetLastError();
                    WPP_SF_D(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      34i64,
                      &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids,
                      LastError);
                  }
                  v5 = -2146893043;
                }
                *v10 = pvSaveToPara;
                *a4 = pvSaveToPara + 4;
                v9 = WPP_GLOBAL_Control;
                goto LABEL_26;
              }
            }
            else if ( *(_DWORD *)a3 == 8 )
            {
              goto LABEL_19;
            }
          }
        }
      }
    }
  }
  v5 = -2146893052;
LABEL_26:
  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)v9 + 2), 35i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  return v5;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

