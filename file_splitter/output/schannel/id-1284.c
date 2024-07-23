// File count: 1284
// Total lines: 47
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::DetermineCertVerifyCodePoint(__int64 a1)
{
  __int64 v1; // rdx
  __int64 result; // rax
  CTlsSignatureSuiteList *v4; // rdi
  __int16 v5; // cx

  v1 = *(_QWORD *)(a1 + 72);
  if ( !v1 )
    return 87i64;
  v4 = (CTlsSignatureSuiteList *)(*(_QWORD *)(a1 + 8) + 510i64);
  if ( *(_QWORD *)(a1 + 8) == -510i64 )
    return 1359i64;
  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::DetermineCertVerifySignatureAlgorithm(
             a1,
             *(const struct _CERT_CONTEXT **)(v1 + 32));
  if ( !(_DWORD)result )
  {
    v5 = __ROR2__(
           CTlsSignatureSuiteList::GetMinimumCodePointToSign(
             v4,
             (enum _eTlsSignatureAlgorithm)*(_DWORD *)(a1 + 104),
             *(_DWORD *)(*(_QWORD *)(a1 + 72) + 428i64),
             *(_DWORD *)(*(_QWORD *)(a1 + 8) + 64i64),
             *(_DWORD *)(*(_QWORD *)(a1 + 72) + 140i64)),
           8);
    *(_WORD *)(a1 + 120) = v5;
    if ( v5 )
    {
      GetSignatureSuiteInfoByCodePoint(
        v5,
        0i64,
        (enum _eTlsHashAlgorithm *)(a1 + 100),
        0i64,
        (const unsigned __int16 **)(a1 + 112),
        0i64,
        0i64);
      return 0i64;
    }
    else
    {
      return 2148074289i64;
    }
  }
  return result;
}
