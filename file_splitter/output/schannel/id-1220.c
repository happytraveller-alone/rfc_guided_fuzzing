// File count: 1220
// Total lines: 24
----------------------------------------
void __fastcall CSsl3TlsClientContext::SetActiveClientCred(
        CSsl3TlsClientContext *this,
        struct CSslCredential *a2,
        char a3)
{
  unsigned __int64 v3; // rax
  __int64 v7; // rcx

  v3 = *((_QWORD *)this + 17);
  if ( (v3 & 0x80000) != 0 )
  {
    v7 = *((_QWORD *)this + 116);
    if ( v7 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v7 + 8i64))(v7, 1i64);
      v3 = *((_QWORD *)this + 17) & 0xFFFFFFFFFFF7FFFFui64;
      *((_QWORD *)this + 17) = v3;
    }
  }
  *((_QWORD *)this + 116) = a2;
  if ( a3 )
    *((_QWORD *)this + 17) = v3 | 0x80000;
}
