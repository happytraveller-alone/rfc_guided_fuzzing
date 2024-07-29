//----- (000000018005F4A4) ----------------------------------------------------
__int64 __fastcall CSslCredential::FillInCredStructWithCertInfo(CSslCredential *this)
{
  __int64 v1; // rbx
  DWORD v3; // eax
  DWORD csz; // esi
  WCHAR *v5; // rax
  DWORD LastError; // ebx
  DWORD PublicKeyLength; // eax
  DWORD v8; // eax
  DWORD v9; // esi
  WCHAR *v10; // rax
  void *v11; // rcx
  void *v12; // rcx

  v1 = *((_QWORD *)this + 4);
  v3 = CertNameToStrW(*(_DWORD *)v1, (PCERT_NAME_BLOB)(*(_QWORD *)(v1 + 24) + 48i64), 0x20000003u, 0i64, 0);
  csz = v3;
  if ( !v3 )
    goto LABEL_12;
  *((_DWORD *)this + 106) = 2 * v3;
  v5 = (WCHAR *)SPExternalAlloc(2 * v3);
  *((_QWORD *)this + 52) = v5;
  if ( v5 )
  {
    if ( CertNameToStrW(*(_DWORD *)v1, (PCERT_NAME_BLOB)(*(_QWORD *)(v1 + 24) + 48i64), 0x20000003u, v5, csz) )
    {
      PublicKeyLength = CertGetPublicKeyLength(0x10001u, (PCERT_PUBLIC_KEY_INFO)(*(_QWORD *)(v1 + 24) + 96i64));
      *((_DWORD *)this + 107) = PublicKeyLength;
      if ( !PublicKeyLength )
      {
        LastError = GetLastError();
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            39i64,
            &WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
            LastError);
        goto LABEL_13;
      }
      v8 = CertNameToStrW(*(_DWORD *)v1, (PCERT_NAME_BLOB)(*(_QWORD *)(v1 + 24) + 80i64), 0x20000003u, 0i64, 0);
      v9 = v8;
      if ( v8 )
      {
        *((_DWORD *)this + 102) = 2 * v8;
        v10 = (WCHAR *)SPExternalAlloc(2 * v8);
        *((_QWORD *)this + 50) = v10;
        if ( !v10 )
          goto LABEL_3;
        if ( CertNameToStrW(*(_DWORD *)v1, (PCERT_NAME_BLOB)(*(_QWORD *)(v1 + 24) + 80i64), 0x20000003u, v10, v9) )
          return 0i64;
      }
    }
LABEL_12:
    LastError = GetLastError();
    goto LABEL_13;
  }
LABEL_3:
  LastError = 14;
LABEL_13:
  v11 = (void *)*((_QWORD *)this + 50);
  if ( v11 )
  {
    SPExternalFree(v11);
    *((_QWORD *)this + 50) = 0i64;
  }
  v12 = (void *)*((_QWORD *)this + 52);
  if ( v12 )
  {
    SPExternalFree(v12);
    *((_QWORD *)this + 52) = 0i64;
  }
  return LastError;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
