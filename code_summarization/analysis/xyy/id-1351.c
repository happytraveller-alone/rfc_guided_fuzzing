//----- (000000018006AA84) ----------------------------------------------------
__int64 __fastcall CTls13ClientContext::DowngradeClientToSsl3Tls(CTls13ClientContext *this)
{
  void *v2; // rax
  __int64 result; // rax
  __int64 v4; // rax
  __int64 v5; // rcx

  v2 = SPExternalAlloc(0x558u);
  if ( !v2 )
    return 14i64;
  v4 = CSsl3TlsClientContext::CSsl3TlsClientContext(v2, this);
  v5 = *(_QWORD *)(v4 + 128);
  *((_QWORD *)this + 16) = v5;
  *(_QWORD *)(v5 + 16) = v4;
  result = 1359i64;
  *((_QWORD *)this + 17) |= 0x40000ui64;
  return result;
}
// 180060138: using guessed type __int64 __fastcall CSsl3TlsClientContext::CSsl3TlsClientContext(_QWORD, _QWORD);

