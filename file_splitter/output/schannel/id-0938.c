// File count: 938
// Total lines: 42
-----------------------------------------
void __fastcall GenerateUserFatalAlertMessage(struct CSslUserContext *a1, __int64 a2, char a3)
{
  _BYTE *v4; // rdx
  unsigned int v5; // ebx
  struct _SecBufferDesc v6; // [rsp+20h] [rbp-30h] BYREF
  int v7[2]; // [rsp+30h] [rbp-20h] BYREF
  _BYTE *v8; // [rsp+38h] [rbp-18h]
  unsigned int v9; // [rsp+40h] [rbp-10h]
  int v10; // [rsp+44h] [rbp-Ch]
  _BYTE *v11; // [rsp+48h] [rbp-8h]

  v4 = *(_BYTE **)(a2 + 8);
  v5 = *(_DWORD *)a2;
  *(_DWORD *)a2 = 0;
  if ( a3 )
  {
    if ( v4 )
    {
      if ( v5 >= *((_DWORD *)a1 + 16) + *((_DWORD *)a1 + 17) + 2 )
      {
        v4[1] = a3;
        *v4 = 2;
        v6.ulVersion = 0;
        v11 = v4 + 2;
        v9 = v5 - 2;
        v8 = v4;
        v7[0] = 2;
        v10 = 2;
        v6.cBuffers = 2;
        v6.pBuffers = (PSecBuffer)v7;
        v7[1] = 1;
        if ( !(unsigned int)SslSealMessageConnection(a1, 0x40000000, &v6) )
        {
          if ( v5 >= v7[0] + v9 )
            v5 = v7[0] + v9;
          *(_DWORD *)a2 = v5;
        }
      }
    }
  }
}
