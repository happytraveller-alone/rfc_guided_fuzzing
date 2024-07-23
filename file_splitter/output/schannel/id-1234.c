// File count: 1234
// Total lines: 52
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::GenerateHelloRequest(CSsl3TlsServerContext *this, struct SPBuffer *a2)
{
  char v2; // r14
  unsigned int v5; // edi
  unsigned int v6; // r8d
  unsigned int v7; // esi
  unsigned int v8; // r8d
  unsigned int v9; // ecx
  __int64 result; // rax
  int v11; // eax
  unsigned int v12; // edi
  __int16 v13; // [rsp+20h] [rbp-18h]
  int v14; // [rsp+28h] [rbp-10h]

  v2 = *((_BYTE *)this + 233);
  v5 = v2 != 0 ? 12 : 4;
  v6 = v5;
  if ( (*((_BYTE *)this + 32) & 4) != 0 )
  {
    v7 = *((_DWORD *)this + 11);
    v8 = v5 + *((_DWORD *)this + 12);
    v9 = *((_DWORD *)this + 13);
    if ( v9 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v9 -= v8 % v9;
      v8 += v9;
    }
    v6 = v7 + v8;
  }
  else
  {
    v7 = 0;
  }
  result = CSsl3TlsContext::AllocateOutputBuffer(this, a2, *((_DWORD *)this + 15) + v6);
  if ( !(_DWORD)result )
  {
    v14 = *((unsigned __int8 *)this + 233);
    v13 = *((_WORD *)this + 110);
    *((_WORD *)this + 110) = v13 + 1;
    SetHandshakeHeader(v7 + *((_QWORD *)a2 + 1) + (v2 != 0 ? 13i64 : 5i64), 0, 0i64, 0, v13, v14);
    v11 = CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, 22, v5);
    v12 = v11;
    if ( v11 )
      CSslContext::SetErrorAndFatalAlert((__int64)this, 953, v11, 0x50u);
    else
      *((_BYTE *)this + 555) = 1;
    return v12;
  }
  return result;
}
