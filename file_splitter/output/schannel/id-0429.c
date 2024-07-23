// File count: 429
// Total lines: 41
-----------------------------------------
void __fastcall CSsl3TlsServerContext::SetDowngradeProtection(CSsl3TlsServerContext *this)
{
  __int64 v1; // rax
  int v3; // r9d
  int v4; // ecx
  const unsigned __int8 near *v5; // rax
  bool v6; // cl
  bool v7; // al

  v1 = *((_QWORD *)this + 10);
  if ( v1 )
  {
    v3 = *(_DWORD *)(v1 + 152);
    v4 = *((_DWORD *)this + 16);
    if ( (v4 & 0x400) != 0 && (v3 & 0x1000) != 0 )
    {
      v5 = CSsl3TlsContext::m_rgbTls12Downgrade;
LABEL_4:
      *((_QWORD *)this + 41) = v5;
      return;
    }
    if ( *((_BYTE *)this + 233) )
    {
      v6 = (v4 & 0x40000) == 0;
      v7 = (v3 & 0x40000) != 0;
    }
    else
    {
      v6 = (v4 & 0x1400) == 0;
      v7 = (v3 & 0x1400) != 0;
    }
    if ( v6 && v7 )
    {
      v5 = CSsl3TlsContext::m_rgbTls11OrBelowDowngrade;
      goto LABEL_4;
    }
  }
}
// 180082BB8: using guessed type const unsigned __int8 near *const CSsl3TlsContext::m_rgbTls11OrBelowDowngrade;
// 180082BC0: using guessed type const unsigned __int8 near *const CSsl3TlsContext::m_rgbTls12Downgrade;
