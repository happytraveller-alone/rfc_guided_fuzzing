//----- (0000000180076AC8) ----------------------------------------------------
__int64 __fastcall PskGenerateExchangeValue(struct CSsl3TlsContext *a1, int a2, unsigned __int8 *a3, unsigned int *a4)
{
  unsigned int v4; // edi
  unsigned __int8 *v6; // r14
  int v7; // esi
  unsigned __int16 *v9; // rdx
  unsigned int v10; // eax
  int v11; // ebx

  v4 = 0;
  v6 = a3;
  v7 = (int)a3;
  LOWORD(a3) = 0;
  if ( *(_DWORD *)(*((_QWORD *)a1 + 1) + 48i64) == 4 )
  {
    v9 = (unsigned __int16 *)*((_QWORD *)a1 + 107);
    if ( v9 )
    {
      LODWORD(a3) = *v9;
      v10 = (_DWORD)a3 + 2;
    }
    else
    {
      v10 = 0;
      if ( a2 )
        v10 = 2;
    }
    if ( v6 )
    {
      if ( *a4 >= v10 )
      {
        if ( v10 )
        {
          v6[1] = (unsigned __int8)a3;
          v7 = (_DWORD)v6 + 2;
          *v6 = BYTE1(a3);
          if ( (_WORD)a3 )
          {
            v11 = (unsigned __int16)a3;
            memcpy_0(v6 + 2, v9 + 1, (unsigned __int16)a3);
            v7 += v11;
          }
        }
        *a4 = v7 - (_DWORD)v6;
      }
      else
      {
        *a4 = v10;
        return (unsigned int)-2146893023;
      }
    }
    else
    {
      *a4 = v10;
    }
  }
  else
  {
    return 1359;
  }
  return v4;
}
