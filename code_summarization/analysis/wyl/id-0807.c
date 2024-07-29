//----- (0000000180042918) ----------------------------------------------------
__int64 __fastcall SpMapAuthIdentity(void *a1, struct LSA_SCHANNEL_CRED *a2, __int64 a3)
{
  HCERTSTORE v6; // r14
  int v8; // ebx
  int v9; // esi
  HLOCAL v10; // rdi
  unsigned int LastError; // ebx
  unsigned __int16 *v12; // rcx
  bool v13; // si
  CCipherMill *v14; // rcx
  unsigned __int16 v15; // dx
  unsigned __int16 *v16; // rcx
  PCCERT_CONTEXT CertificateInStore; // rbx
  _QWORD *v18; // rax
  int v19; // [rsp+30h] [rbp-69h] BYREF
  enum _CRED_MARSHAL_TYPE CredType; // [rsp+34h] [rbp-65h] BYREF
  PVOID Credential; // [rsp+38h] [rbp-61h] BYREF
  struct _UNICODE_STRING v22; // [rsp+40h] [rbp-59h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+50h] [rbp-49h] BYREF
  int pvFindPara; // [rsp+60h] [rbp-39h] BYREF
  __int64 v25; // [rsp+68h] [rbp-31h]
  char v26[24]; // [rsp+70h] [rbp-29h] BYREF
  __int128 v27; // [rsp+88h] [rbp-11h] BYREF
  __int128 v28; // [rsp+98h] [rbp-1h]
  __int64 v29; // [rsp+A8h] [rbp+Fh]
  int v30; // [rsp+B0h] [rbp+17h]

  Credential = 0i64;
  v19 = 0;
  v29 = 0i64;
  v30 = 0;
  v6 = 0i64;
  v27 = 0i64;
  v28 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v26) )
    return 1359i64;
  v8 = v26[8] & 0x40;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
  RtlInitUnicodeString(&DestinationString, 0i64);
  RtlInitUnicodeString(&v22, 0i64);
  v9 = 72;
  v10 = SPExternalAlloc(0x48u);
  if ( v10 )
  {
    if ( v8 )
    {
      LastError = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, void *))(LsaTable + 80))(
                    0i64,
                    44i64,
                    &v27,
                    a1);
      if ( LastError )
        goto LABEL_36;
      *(_DWORD *)v10 = v27;
      if ( DWORD1(v27) >= 0x48 )
        v9 = DWORD1(v27);
      *((_DWORD *)v10 + 1) = v9;
      *((_DWORD *)v10 + 4) = HIDWORD(v27);
      *((_QWORD *)v10 + 1) = DWORD2(v27);
      *((_DWORD *)v10 + 8) = DWORD1(v28);
      *((_QWORD *)v10 + 3) = (unsigned int)v28;
      *((_DWORD *)v10 + 12) = HIDWORD(v28);
      *((_QWORD *)v10 + 5) = DWORD2(v28);
      *((_DWORD *)v10 + 13) = v29;
      *((_DWORD *)v10 + 16) = v30;
      *((_QWORD *)v10 + 7) = HIDWORD(v29);
    }
    else
    {
      LastError = (*(__int64 (__fastcall **)(_QWORD, __int64, HLOCAL, void *))(LsaTable + 80))(0i64, 72i64, v10, a1);
      if ( LastError )
        goto LABEL_36;
    }
    v12 = (unsigned __int16 *)*((_QWORD *)v10 + 1);
    v13 = (*((_BYTE *)v10 + 52) & 1) == 0;
    if ( v12 )
    {
      LastError = CopyClientString(v12, *((_DWORD *)v10 + 4), (*((_BYTE *)v10 + 52) & 1) == 0, &DestinationString);
      if ( LastError )
      {
        v14 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_36;
        v15 = 35;
        goto LABEL_19;
      }
    }
    v16 = (unsigned __int16 *)*((_QWORD *)v10 + 5);
    if ( !v16 || (LastError = CopyClientString(v16, *((_DWORD *)v10 + 12), v13, &v22)) == 0 )
    {
      if ( CredIsMarshaledCredentialW(DestinationString.Buffer)
        && CredUnmarshalCredentialW(DestinationString.Buffer, &CredType, &Credential)
        && CredType == CertCredential )
      {
        LastError = SslImpersonateClient(a3, &v19);
        if ( !LastError )
        {
          v6 = CertOpenStore((LPCSTR)0xA, 1u, 0i64, 0x10004u, L"MY");
          if ( v6
            && (v25 = (__int64)Credential + 4,
                pvFindPara = 20,
                (CertificateInStore = CertFindCertificateInStore(v6, 1u, 0, 0x10000u, &pvFindPara, 0i64)) != 0i64) )
          {
            v18 = SPExternalAlloc(0x38u);
            *((_QWORD *)a2 + 1) = v18;
            if ( v18 )
            {
              *v18 = CertificateInStore;
              *(_QWORD *)(*((_QWORD *)a2 + 1) + 8i64) = v22.Buffer;
              v22.Buffer = 0i64;
              LastError = 0;
              *((_DWORD *)a2 + 1) = 1;
            }
            else
            {
              LastError = 14;
            }
          }
          else
          {
            LastError = GetLastError();
          }
        }
      }
      else
      {
        LastError = -2146893043;
      }
      goto LABEL_36;
    }
    v14 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v15 = 36;
LABEL_19:
      WPP_SF_L(*((_QWORD *)v14 + 2), v15, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, LastError);
    }
LABEL_36:
    SPExternalFree(v10);
    goto LABEL_37;
  }
  LastError = 14;
LABEL_37:
  if ( DestinationString.Buffer )
    LocalFree(DestinationString.Buffer);
  if ( v22.Buffer )
  {
    memset(v22.Buffer, 0, v22.Length);
    LocalFree(v22.Buffer);
  }
  if ( Credential )
    CredFree(Credential);
  if ( v6 )
    CertCloseStore(v6, 0);
  if ( v19 )
    RevertToSelf();
  return LastError;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18008275C: using guessed type wchar_t aMy[3];
// 180092620: using guessed type __int64 LsaTable;
