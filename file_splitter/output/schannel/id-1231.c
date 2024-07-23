// File count: 1231
// Total lines: 157
---------------------------------------
__int64 __fastcall CSsl3TlsServerContext::DigestCertVerify(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  unsigned __int16 *v4; // r13
  unsigned int v5; // ecx
  unsigned int v6; // r14d
  __int64 v8; // rax
  unsigned int v9; // edx
  int v11; // esi
  __int64 v12; // rax
  int v13; // edi
  unsigned __int8 v14; // r9
  int v15; // edx
  unsigned __int16 *v16; // rax
  int v17; // r8d
  int v18; // edx
  __int64 result; // rax
  __int16 v20; // r14
  unsigned int *v21; // r9
  unsigned __int8 v22; // r9
  int v23; // r8d
  int v24; // eax
  int v25; // esi
  unsigned __int8 *v26; // r15
  DWORD v27; // esi
  DWORD PublicKeyLength; // edi
  const unsigned __int16 *v29; // rdx
  enum _eTlsHashAlgorithm v30; // [rsp+40h] [rbp-20h] BYREF
  enum _eTlsSignatureAlgorithm v31; // [rsp+44h] [rbp-1Ch] BYREF
  unsigned __int16 *v32; // [rsp+48h] [rbp-18h]
  unsigned __int16 *v33; // [rsp+50h] [rbp-10h] BYREF
  unsigned int v34; // [rsp+A0h] [rbp+40h] BYREF
  unsigned int v35; // [rsp+B8h] [rbp+58h] BYREF

  v4 = 0i64;
  v5 = 0;
  v33 = 0i64;
  v6 = 0;
  v30 = TlsHashAlgorithm_None;
  v34 = 0;
  v8 = *((_QWORD *)this + 11);
  v9 = 0;
  v35 = 0;
  if ( !v8 || !*(_QWORD *)(v8 + 48) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
    v14 = 40;
    v15 = 1300;
    goto LABEL_40;
  }
  v11 = 3;
  v12 = *(_QWORD *)(*((_QWORD *)this + 124) + 40i64);
  if ( !v12 )
  {
    v13 = 8707;
LABEL_12:
    v16 = L"ECDSA";
    goto LABEL_13;
  }
  v13 = *(_DWORD *)(*(_QWORD *)v12 + 4i64);
  if ( v13 == 8704 )
  {
    v11 = 2;
    v16 = L"DSA";
    goto LABEL_13;
  }
  if ( v13 == 8707 )
    goto LABEL_12;
  if ( v13 != 9216 && v13 != 41984 )
  {
    v14 = 43;
    v15 = 1302;
LABEL_40:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v15, -2146893018, v14);
    return 1359i64;
  }
  v11 = 1;
  v16 = L"RSA";
  v6 = 2;
  v34 = 2;
LABEL_13:
  v17 = *((_DWORD *)this + 16);
  v32 = v16;
  if ( (v17 & 0x40400) != 0 )
  {
    if ( a3 < 2 )
    {
      v18 = 1307;
LABEL_16:
      CSslContext::SetErrorAndFatalAlert((__int64)this, v18, -2146893018, 0x32u);
      return 2148074278i64;
    }
    v20 = *(_WORD *)a2;
    if ( !CTlsSignatureSuiteList::IsSupportedCodePoint((CSsl3TlsServerContext *)((char *)this + 474), *(_WORD *)a2) )
    {
      v22 = 47;
      v23 = -2146893048;
LABEL_19:
      CSslContext::SetErrorAndFatalAlert((__int64)this, 1307, v23, v22);
      return 2148074289i64;
    }
    v31 &= (unsigned int)v21;
    GetSignatureSuiteInfoByCodePoint(v20, &v31, &v30, v21, (const unsigned __int16 **)&v33, &v35, &v34);
    a2 += 2;
    a3 -= 2;
    if ( v31 != v11 )
    {
      v22 = 40;
      v23 = -2146893007;
      goto LABEL_19;
    }
    v4 = v33;
    v6 = v34;
    v5 = v30;
    v9 = v35;
  }
  if ( a3 < 2 || (v24 = a2[1], v25 = *a2, v26 = a2 + 2, v27 = v24 + (v25 << 8), v27 + 2 > a3) )
  {
    v18 = 1300;
    goto LABEL_16;
  }
  result = CheckClientVerifyMessage(this, v32, v4, v5, v9, v6, v26, v27);
  if ( (_DWORD)result && v13 == 8707 )
  {
    RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
    PublicKeyLength = CertGetPublicKeyLength(
                        **(_DWORD **)(*((_QWORD *)this + 11) + 48i64),
                        (PCERT_PUBLIC_KEY_INFO)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 11) + 48i64) + 24i64) + 96i64));
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
    switch ( PublicKeyLength )
    {
      case 0x100u:
        v29 = L"ECDSA_P256";
        break;
      case 0x180u:
        v29 = L"ECDSA_P384";
        break;
      case 0x209u:
        v29 = L"ECDSA_P521";
        break;
      default:
        v14 = 43;
        v15 = 1301;
        goto LABEL_40;
    }
    return CheckClientVerifyMessage(this, v29, v4, v30, v35, v6, v26, v27);
  }
  return result;
}
// 18006225C: variable 'v21' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800821D8: using guessed type wchar_t aEcdsaP384[11];
// 180082E10: using guessed type wchar_t aEcdsaP521[11];
