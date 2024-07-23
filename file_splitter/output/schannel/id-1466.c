// File count: 1466
// Total lines: 49
----------------------------------------
SECURITY_STATUS __fastcall ComputeSignatureLength(
        __int64 **this,
        enum _eTlsSignatureAlgorithm a2,
        enum _eTlsHashAlgorithm a3,
        DWORD *pcbResult)
{
  SECURITY_STATUS result; // eax
  DWORD v9; // esi
  __int64 *v10; // rax
  __int64 v11; // r10
  __int64 *v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rcx
  DWORD cbHashValue[4]; // [rsp+40h] [rbp-78h] BYREF
  BYTE pbHashValue[64]; // [rsp+50h] [rbp-68h] BYREF

  memset_0(pbHashValue, 0, sizeof(pbHashValue));
  cbHashValue[0] = 0;
  if ( !this || !pcbResult )
    return 87;
  *pcbResult = 0;
  result = CSsl3TlsContext::GetHashAlgorithmSize((CSsl3TlsContext *)this, a2, a3, cbHashValue);
  if ( result )
    return result;
  v9 = cbHashValue[0];
  if ( cbHashValue[0] > 0x40 )
    return -2146893052;
  if ( ((_DWORD)this[8] & 0x40051555) == 0 )
  {
    v14 = ((__int64 (__fastcall *)(__int64 **))(*this)[31])(this);
    if ( v14 )
      return NCryptSignHash(*(_QWORD *)(v14 + 104), 0i64, pbHashValue, v9, 0i64, *pcbResult, pcbResult, 0x40u);
    return -2146893052;
  }
  v10 = this[3];
  if ( !v10 )
    return -2146893052;
  v11 = v10[1];
  v12 = this[1];
  if ( v12 )
    v13 = *v12;
  else
    v13 = 0i64;
  return SslSignHash(v13, v11, pbHashValue, cbHashValue[0], 0i64, *pcbResult, pcbResult, 0);
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098540: using guessed type __int64 __fastcall SslSignHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180075B20: using guessed type DWORD cbHashValue[4];
