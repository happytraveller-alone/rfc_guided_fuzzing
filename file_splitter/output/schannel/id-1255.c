// File count: 1255
// Total lines: 76
----------------------------------------
DWORD __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertVerifySignatureSize(__int64 a1)
{
  __int64 v1; // rax
  DWORD v3; // ecx
  DWORD result; // eax
  int v5; // edx
  int v6; // edx
  HLOCAL v7; // rax
  void *v8; // rsi
  unsigned __int16 v9; // cx
  BOOL v10; // ebx
  int pvStructInfo; // [rsp+30h] [rbp-20h] BYREF
  void *v12; // [rsp+38h] [rbp-18h]
  int v13; // [rsp+40h] [rbp-10h]
  __int64 v14; // [rsp+48h] [rbp-8h]
  DWORD pcbResult; // [rsp+70h] [rbp+20h] BYREF
  DWORD pcbEncoded; // [rsp+78h] [rbp+28h] BYREF

  v1 = *(_QWORD *)(a1 + 72);
  pcbResult = 0;
  if ( *(_BYTE *)(v1 + 78) && !*(_BYTE *)(v1 + 79) )
  {
    v3 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 944i64);
    pcbResult = v3;
    if ( !v3 )
      return 1359;
    goto LABEL_8;
  }
  result = ComputeSignatureLength(
             *(__int64 ***)(a1 + 8),
             *(enum _eTlsSignatureAlgorithm *)(a1 + 104),
             *(enum _eTlsHashAlgorithm *)(a1 + 100),
             &pcbResult);
  if ( !result )
  {
    v3 = pcbResult;
LABEL_8:
    if ( v3 <= 0xFFFF )
    {
      v5 = *(_DWORD *)(a1 + 104);
      *(_WORD *)(a1 + 140) = v3;
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 != 2 )
          return 1359;
        v7 = SPExternalAlloc((unsigned __int16)v3);
        v8 = v7;
        if ( !v7 )
          return 14;
        memset_0(v7, 255, *(unsigned __int16 *)(a1 + 140));
        v9 = *(_WORD *)(a1 + 140);
        pcbEncoded = 0;
        pvStructInfo = v9 >> 1;
        v13 = pvStructInfo;
        v12 = v8;
        v14 = (__int64)v8 + (v9 >> 1);
        v10 = CryptEncodeObject(1u, (LPCSTR)0x2F, &pvStructInfo, 0i64, &pcbEncoded);
        SPExternalFree(v8);
        if ( !v10 )
          return GetLastError();
        if ( pcbEncoded > 0xFFFF )
          return 1359;
        *(_WORD *)(a1 + 142) = pcbEncoded;
      }
      else
      {
        *(_WORD *)(a1 + 142) = v3;
      }
      return 0;
    }
    return 1359;
  }
  return result;
}
