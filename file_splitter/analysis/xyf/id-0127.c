//----- (000000018000A534) ----------------------------------------------------
void *__fastcall SetHandshakeHeader(__int64 a1, char a2, const void *a3, unsigned int a4, __int16 a5, int a6)
{
  void *result; // rax

  *(_BYTE *)a1 = a2;
  if ( a6 )
  {
    *(_BYTE *)(a1 + 5) = a5;
    *(_BYTE *)(a1 + 4) = HIBYTE(a5);
    result = (void *)HIWORD(a4);
    *(_BYTE *)(a1 + 9) = BYTE2(a4);
    *(_WORD *)(a1 + 7) = 0;
    *(_BYTE *)(a1 + 6) = 0;
    *(_BYTE *)(a1 + 11) = a4;
    *(_BYTE *)(a1 + 10) = BYTE1(a4);
  }
  else
  {
    result = (void *)HIWORD(a4);
  }
  *(_BYTE *)(a1 + 1) = (_BYTE)result;
  *(_BYTE *)(a1 + 3) = a4;
  *(_BYTE *)(a1 + 2) = BYTE1(a4);
  if ( a3 )
    return memcpy_0((void *)(a1 + 4 + (a6 != 0 ? 8 : 0)), a3, a4);
  return result;
}

