//----- (000000018004F9DC) ----------------------------------------------------
__int64 __fastcall SpMarshallSupplementalCredsV4(__int64 a1, unsigned __int8 *a2, unsigned int *a3, char **a4)
{
  unsigned int v4; // ebx
  unsigned int v8; // r14d
  CCipherMill *v9; // rcx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  char *v13; // rax
  char *v14; // rsi
  bool v15; // zf
  char *v16; // r15

  v4 = 0;
  v8 = 80;
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 28i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
    v9 = WPP_GLOBAL_Control;
  }
  if ( a2 && a4 && a3 && (unsigned int)(*(_DWORD *)a2 - 3) <= 1 )
  {
    v10 = *((_DWORD *)a2 + 1);
    if ( v10 )
      v8 = 8 * v10 + 80;
    v11 = *((_DWORD *)a2 + 10);
    if ( v11 )
      v8 += 4 * v11;
    v12 = *((_DWORD *)a2 + 6);
    if ( v12 )
      v8 += 8 * v12;
    v13 = (char *)LocalAlloc(0x40u, v8);
    v14 = v13;
    if ( v13 )
    {
      v15 = *(_DWORD *)a2 == 3;
      *(_OWORD *)v13 = *(_OWORD *)a2;
      *((_OWORD *)v13 + 1) = *((_OWORD *)a2 + 1);
      *((_OWORD *)v13 + 2) = *((_OWORD *)a2 + 2);
      *((_OWORD *)v13 + 3) = *((_OWORD *)a2 + 3);
      if ( v15 )
        *((_QWORD *)v13 + 8) = *((_QWORD *)a2 + 8);
      else
        *((_OWORD *)v13 + 4) = *((_OWORD *)a2 + 4);
      v16 = v13 + 80;
      if ( *((_DWORD *)a2 + 1) )
      {
        memcpy_0(v13 + 80, *((const void **)a2 + 1), 8i64 * *((unsigned int *)a2 + 1));
        *((_QWORD *)v14 + 1) = v16;
        *((_DWORD *)v14 + 1) = *((_DWORD *)a2 + 1);
        v16 += 8 * *((unsigned int *)a2 + 1);
      }
      if ( *((_DWORD *)a2 + 6) )
      {
        memcpy_0(v16, *((const void **)a2 + 4), 8i64 * *((unsigned int *)a2 + 6));
        *((_QWORD *)v14 + 4) = v16;
        *((_DWORD *)v14 + 6) = *((_DWORD *)a2 + 6);
        v16 += 8 * *((unsigned int *)a2 + 6);
      }
      if ( *((_DWORD *)a2 + 10) )
      {
        memcpy_0(v16, *((const void **)a2 + 6), 4i64 * *((unsigned int *)a2 + 10));
        *((_QWORD *)v14 + 6) = v16;
        *((_DWORD *)v14 + 10) = *((_DWORD *)a2 + 10);
      }
      *a3 = v8;
      *a4 = v14;
    }
    else
    {
      v4 = -1073741801;
    }
    v9 = WPP_GLOBAL_Control;
  }
  else
  {
    v4 = -1073741811;
  }
  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v9 + 2), 29i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, v4);
  return v4;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

