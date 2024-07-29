//----- (00000001800586FC) ----------------------------------------------------
__int64 __fastcall QueryCredentialManagerForCert(struct CSsl3TlsClientContext *this, unsigned __int16 *a2)
{
  int ClientLogonId; // ebx
  int v5; // eax
  HCERTSTORE v6; // rdi
  PCCERT_CONTEXT CertificateInStore; // rsi
  DWORD LastError; // eax
  void *pvPara; // [rsp+20h] [rbp-50h]
  __int64 v11; // [rsp+40h] [rbp-30h] BYREF
  PVOID Credential; // [rsp+48h] [rbp-28h] BYREF
  struct _LUID v13; // [rsp+50h] [rbp-20h] BYREF
  int pvFindPara; // [rsp+58h] [rbp-18h] BYREF
  __int64 v15; // [rsp+60h] [rbp-10h]
  int v16; // [rsp+B0h] [rbp+40h] BYREF
  enum _CRED_MARSHAL_TYPE CredType; // [rsp+B8h] [rbp+48h] BYREF

  v11 = 0i64;
  v16 = 0;
  Credential = 0i64;
  v13 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
  ClientLogonId = SslGetClientLogonId(&v13);
  if ( !ClientLogonId )
  {
    ClientLogonId = SslImpersonateClient(*(_QWORD *)(*((_QWORD *)this + 10) + 752i64), &v16);
    if ( !ClientLogonId )
    {
      v5 = (*(__int64 (__fastcall **)(struct _LUID *, __int64, unsigned __int16 *, __int64, _DWORD, __int64 *))(LsaTable + 328))(
             &v13,
             1i64,
             a2,
             3i64,
             0,
             &v11);
      ClientLogonId = v5;
      if ( v5 >= 0 )
      {
        if ( CredIsMarshaledCredentialW(*(LPCWSTR *)(v11 + 72))
          && CredUnmarshalCredentialW(*(LPCWSTR *)(v11 + 72), &CredType, &Credential)
          && CredType == CertCredential )
        {
          v6 = CertOpenStore((LPCSTR)0xA, 1u, 0i64, 0x10004u, L"MY");
          if ( v6 )
          {
            v15 = (__int64)Credential + 4;
            pvFindPara = 20;
            CertificateInStore = CertFindCertificateInStore(v6, 1u, 0, 0x10000u, &pvFindPara, 0i64);
            if ( CertificateInStore )
            {
              if ( v16 )
              {
                RevertToSelf();
                v16 = 0;
              }
              ClientLogonId = AssignNewClientCredential(this, CertificateInStore);
              if ( ClientLogonId >= 0 )
                ClientLogonId = 0;
              CertFreeCertificateContext(CertificateInStore);
            }
            else
            {
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                LastError = GetLastError();
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  14i64,
                  &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
                  LastError);
              }
              ClientLogonId = -2146893042;
            }
            CertCloseStore(v6, 0);
          }
          else
          {
            GetLastError();
            ClientLogonId = -2146893042;
          }
        }
        else
        {
          ClientLogonId = -2146893043;
        }
      }
      else if ( v5 == -1073741275
             && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
             && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
      }
    }
  }
  if ( v11 )
    (*(void (**)(void))(LsaTable + 48))();
  if ( Credential )
    CredFree(Credential);
  if ( v16 )
    RevertToSelf();
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && ClientLogonId || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(pvPara) = ClientLogonId;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0xFu,
      (__int64)&WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
      ClientLogonId,
      pvPara);
  }
  return (unsigned int)ClientLogonId;
}
// 1800589EE: variable 'pvPara' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18008275C: using guessed type wchar_t aMy[3];
// 180092620: using guessed type __int64 LsaTable;
