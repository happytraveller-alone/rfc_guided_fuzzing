//----- (000000018006CEE0) ----------------------------------------------------
__int64 __fastcall CTls13ClientContext::GenerateResponse(CTls13ClientContext *this, struct SPBuffer *a2)
{
  unsigned int CertVerifyHashForRemoteSigning; // edi
  int v5; // ecx
  char v6; // cl
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned __int8 v10; // [rsp+30h] [rbp+8h] BYREF

  CertVerifyHashForRemoteSigning = 0;
  v5 = *((_DWORD *)this + 17) - 100;
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 23i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
      v10 = 0;
      CertVerifyHashForRemoteSigning = CSsl3TlsClientContext::CheckForClientCertificatePrivateKeys(this, &v10);
      if ( !v10 )
      {
        if ( *((_BYTE *)this + 1315)
          && *((_BYTE *)this + 266)
          && *((_QWORD *)this + 116)
          && !*((_QWORD *)this + 117)
          && !*((_DWORD *)this + 236) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          }
          CertVerifyHashForRemoteSigning = CTls13ClientContext::GenerateCertVerifyHashForRemoteSigning(this);
          if ( CertVerifyHashForRemoteSigning == 590610 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
            }
            *((_DWORD *)this + 17) = 77;
          }
        }
        else
        {
          CertVerifyHashForRemoteSigning = CTls13ClientContext::GenerateClientFinished(this, a2);
          if ( !CertVerifyHashForRemoteSigning )
          {
            if ( !*((_BYTE *)this + 1601) )
            {
              *((_WORD *)this + 16) |= 0xCu;
              v6 = *((_BYTE *)this + 233);
              if ( !v6 && *((_QWORD *)this + 19) )
              {
                SslFreeObject(*((_QWORD *)this + 19), 0i64);
                v6 = *((_BYTE *)this + 233);
              }
              v7 = *((_QWORD *)this + 21);
              *((_QWORD *)this + 21) = 0i64;
              *((_QWORD *)this + 19) = v7;
              if ( !v6 )
                *((_QWORD *)this + 23) = 0i64;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              }
            }
            v8 = *(_QWORD *)this;
            *((_BYTE *)this + 1584) = 3;
            (*(void (__fastcall **)(CTls13ClientContext *))(v8 + 448))(this);
            CertVerifyHashForRemoteSigning = 0;
            *((_BYTE *)this + 1601) = 1;
          }
        }
      }
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
    *((_DWORD *)this + 16) = *((_DWORD *)this + 463);
    CertVerifyHashForRemoteSigning = (*(__int64 (__fastcall **)(CTls13ClientContext *, struct SPBuffer *))(*(_QWORD *)this + 216i64))(
                                       this,
                                       a2);
    if ( !CertVerifyHashForRemoteSigning )
      *((_DWORD *)this + 17) = 71;
  }
  return CertVerifyHashForRemoteSigning;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

