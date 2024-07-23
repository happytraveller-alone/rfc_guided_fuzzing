// File count: 51
// Total lines: 47
------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::DigestCertificateStatus(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  unsigned int v5; // ebx
  HLOCAL v6; // rax
  HLOCAL v7; // rbp
  __int64 v8; // rax
  unsigned __int8 v10; // r9
  int v11; // edx

  if ( (*((_DWORD *)this + 34) & 0x20000) == 0 )
  {
    v10 = 10;
    v11 = 200;
LABEL_11:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v11, -2146893018, v10);
    return 2148074278i64;
  }
  if ( a3 < 4 )
    goto LABEL_10;
  if ( *a2 != 1 )
    return 0i64;
  v5 = a2[3] + (a2[1] << 16) + (a2[2] << 8);
  if ( v5 > a3 - 4 )
  {
LABEL_10:
    v10 = 50;
    v11 = 201;
    goto LABEL_11;
  }
  v6 = SPExternalAlloc(v5);
  v7 = v6;
  if ( v6 )
  {
    memcpy_0(v6, a2 + 4, v5);
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u);
    v8 = *((_QWORD *)this + 165);
    *(_DWORD *)(v8 + 344) = v5;
    *(_QWORD *)(v8 + 336) = v7;
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
    return 0i64;
  }
  return 14i64;
}
