//----- (0000000180015030) ----------------------------------------------------
__int64 __fastcall EcdsaPublicKeyFromCert(__int64 a1, __int64 a2, _DWORD *a3, unsigned int *a4)
{
  unsigned int v4; // r10d
  __int64 v6; // r8
  int v7; // eax
  _BYTE *v8; // rdx
  int v9; // ebx
  int v10; // edi
  int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx

  v4 = 0;
  if ( a2 )
  {
    v6 = *(_QWORD *)(a2 + 40);
    if ( v6 )
    {
      v7 = *(_DWORD *)(a2 + 32);
      if ( v7 )
      {
        if ( a1 )
        {
          v8 = *(_BYTE **)(a1 + 32);
          if ( v8 )
          {
            v9 = *(_DWORD *)(a1 + 24);
            if ( v9 )
            {
              if ( (v7 & 0xFFFFFFFC) >= 0xC )
              {
                v10 = *(_DWORD *)(v6 + 4);
                v11 = (*(_DWORD *)(v6 + 8) >> 3) + ((*(_DWORD *)(v6 + 8) & 7) != 0);
                if ( v11 )
                {
                  v12 = 2 * v11 + 16;
                  if ( a3 )
                  {
                    if ( *a4 >= v12 )
                    {
                      a3[3] = v11;
                      v13 = 2 * v11;
                      *a3 = 518;
                      a3[1] = 8707;
                      a3[2] = v10;
                      if ( v13 + 1 == v9 && ((*v8 - 4) & 0xFC) == 0 && *v8 != 5 )
                      {
                        memcpy_0(a3 + 4, v8 + 1, v13);
                        return 0i64;
                      }
                      return 2148074333i64;
                    }
                    v4 = -2146893023;
                  }
                  *a4 = v12;
                  return v4;
                }
              }
            }
          }
        }
      }
    }
  }
  return 2148074333i64;
}

