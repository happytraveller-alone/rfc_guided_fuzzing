// File count: 1126
// Total lines: 47
----------------------------------------
__int64 __fastcall CSsl3TlsContext::GenerateTlsAlertMessage(
        CSsl3TlsContext *this,
        struct SPBuffer *a2,
        char a3,
        char a4)
{
  int v8; // r10d
  __int16 v9; // r11
  unsigned int v10; // ecx
  unsigned int v11; // r10d
  __int64 v12; // rsi
  unsigned int v13; // edi
  __int64 result; // rax
  __int64 v15; // rcx

  v8 = 2;
  v9 = *((_WORD *)this + 16) & 4;
  if ( v9 )
  {
    v10 = *((_DWORD *)this + 13);
    v11 = *((_DWORD *)this + 12) + 2;
    if ( v10 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v10 -= v11 % v10;
      v11 += v10;
    }
    v8 = *((_DWORD *)this + 11) + v11;
  }
  v12 = *((unsigned int *)this + 15);
  if ( v9 )
    v13 = *((_DWORD *)this + 11);
  else
    v13 = 0;
  if ( (unsigned __int8)(a3 - 1) > 1u )
    return 87i64;
  result = CSsl3TlsContext::AllocateOutputBuffer(this, a2, (int)v12 + v8);
  if ( !(_DWORD)result )
  {
    v15 = v12 + *((_QWORD *)a2 + 1);
    *(_BYTE *)(v15 + v13) = a3;
    *(_BYTE *)(v15 + v13 + 1) = a4;
    return CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, 21, 2u);
  }
  return result;
}
