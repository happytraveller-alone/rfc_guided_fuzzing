//----- (00000001800011A0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::AllocateAndGenerateCcsAndFinish(CSsl3TlsContext *this, struct SPBuffer *a2)
{
  int v2; // r9d
  unsigned int v5; // ecx
  unsigned int v6; // r9d
  char v7; // al
  int v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // r8d
  __int64 result; // rax

  v2 = 1;
  if ( (*((_BYTE *)this + 32) & 4) != 0 )
  {
    v5 = *((_DWORD *)this + 13);
    v6 = *((_DWORD *)this + 12) + 1;
    if ( v5 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v5 -= v6 % v5;
      v6 += v5;
    }
    v2 = *((_DWORD *)this + 11) + v6;
  }
  v7 = *((_BYTE *)this + 233);
  if ( (*((_BYTE *)this + 64) & 0x30) != 0 )
    v8 = v7 != 0 ? 48 : 40;
  else
    v8 = v7 != 0 ? 24 : 16;
  if ( (*((_BYTE *)this + 32) & 1) != 0 )
  {
    v9 = *((_DWORD *)this + 12) + v8;
    v10 = *((_DWORD *)this + 13);
    if ( v10 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v10 -= v9 % v10;
      v9 += v10;
    }
    v8 = *((_DWORD *)this + 11) + v9;
  }
  result = CSsl3TlsContext::AllocateOutputBuffer(this, a2, v2 + v8 + 2 * *((_DWORD *)this + 15));
  if ( !(_DWORD)result )
    return CSsl3TlsContext::GenerateCcsAndFinishMessage(this, a2);
  return result;
}

