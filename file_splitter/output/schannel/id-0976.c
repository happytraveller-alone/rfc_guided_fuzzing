//----- (0000000180051F10) ----------------------------------------------------
__int64 __fastcall UploadCertContextCallback(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // ebx
  CCipherMill *v8; // rcx
  const CERT_CONTEXT *v9; // r14
  __int64 v10; // rcx
  __int64 v11; // rsi
  DWORD pcbElement; // [rsp+20h] [rbp-10h] BYREF
  DWORD pcbData; // [rsp+24h] [rbp-Ch] BYREF
  __int64 pvData; // [rsp+28h] [rbp-8h] BYREF

  v4 = 0;
  pcbData = 8;
  pvData = 0i64;
  pcbElement = 0;
  if ( !(unsigned int)SchannelInit(1) )
    return 2148074244i64;
  v8 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 28i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
    v8 = WPP_GLOBAL_Control;
  }
  if ( a4
    && *(_QWORD *)(a4 + 8)
    && *(_DWORD *)a4 >= 0xCu
    && a3
    && (v9 = *(const CERT_CONTEXT **)(a3 + 8)) != 0i64
    && *(_DWORD *)a3 == 40 )
  {
    if ( CertGetCertificateContextProperty(*(PCCERT_CONTEXT *)(a3 + 8), 1u, &pvData, &pcbData) )
    {
      v10 = pvData;
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
      v10 = 0i64;
      pvData = 0i64;
    }
    v11 = *(_QWORD *)(a4 + 8);
    pcbElement = *(_DWORD *)a4;
    *(_QWORD *)v11 = v10;
    pcbElement -= 12;
    if ( CertSerializeCertificateStoreElement(v9, 0, (BYTE *)(v11 + 12), &pcbElement) )
    {
      *(_DWORD *)(v11 + 8) = pcbElement;
      *(_DWORD *)a4 = pcbElement + 12;
      v8 = WPP_GLOBAL_Control;
    }
    else
    {
      v8 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
        v8 = WPP_GLOBAL_Control;
      }
      v4 = -2146893043;
    }
  }
  else
  {
    v4 = -2146893052;
  }
  if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)v8 + 2), 31i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  return v4;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

