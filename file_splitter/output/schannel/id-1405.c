// File count: 1405
// Total lines: 103
---------------------------------------
__int64 __fastcall CSsl3TlsContext::FragmentMessage(__int64 a1, char *a2, char a3)
{
  unsigned int v3; // r12d
  int v4; // edi
  bool v5; // cf
  __int64 v7; // rcx
  unsigned int v8; // esi
  unsigned int v9; // ebx
  unsigned int v10; // edi
  int v11; // r9d
  unsigned int v12; // edx
  unsigned int v13; // r8d
  __int64 v14; // r14
  unsigned int v15; // r15d
  struct DTlsRec *v16; // r13
  __int64 v17; // rax
  unsigned int v19; // [rsp+20h] [rbp-68h]
  __int16 v20; // [rsp+24h] [rbp-64h]
  unsigned int v21; // [rsp+2Ch] [rbp-5Ch]
  int v22; // [rsp+30h] [rbp-58h]
  char v23; // [rsp+90h] [rbp+8h]
  unsigned int v26; // [rsp+A8h] [rbp+20h]

  v3 = 0;
  v4 = *(unsigned __int16 *)(a1 + 218);
  v5 = *(_BYTE *)(a1 + 233) != 0;
  v7 = *(unsigned int *)(a1 + 60);
  v8 = 8;
  v9 = v5 ? 12 : 4;
  v10 = v4 - v9;
  if ( a2 )
  {
    v19 = (unsigned __int8)a2[3] + (((unsigned __int8)a2[2] + ((unsigned __int8)a2[1] << 8)) << 8);
    v23 = *a2;
    v20 = (unsigned __int8)a2[5] + ((unsigned __int8)a2[4] << 8);
    v11 = v19 % v10;
    v22 = v19 % v10;
    v12 = (v10 + v19 - 1) / v10;
    if ( v12 <= 1 )
    {
      v12 = 1;
      v10 = v19 % v10;
    }
    v13 = 0;
    v21 = v12;
    v26 = 0;
    if ( v12 )
    {
      v14 = v7;
      v15 = v10;
      while ( 1 )
      {
        if ( v12 > 1 && v13 == v12 - 1 )
        {
          v15 = v11;
          v10 = v11;
        }
        v10 += v7 + v9;
        v16 = DTlsMsgMgr::AddOutgoingRec(*(DTlsMsgMgr **)(a1 + 576), v10);
        if ( !v16 )
          break;
        if ( v15 )
          memcpy_0((void *)(v9 + v14 + *((_QWORD *)v16 + 1)), &a2[v9 + (unsigned __int64)v3], v15);
        **((_BYTE **)v16 + 1) = a3;
        v13 = v26 + 1;
        v17 = *((_QWORD *)v16 + 1);
        v11 = v22;
        v26 = v13;
        *(_BYTE *)(v17 + 12) = v15 + v9;
        *(_BYTE *)(v17 + 11) = (unsigned __int16)(v15 + v9) >> 8;
        v7 = *((_QWORD *)v16 + 1);
        *(_BYTE *)(v14 + v7 + 2) = BYTE1(v19);
        *(_BYTE *)(v14 + v7 + 1) = BYTE2(v19);
        *(_BYTE *)(v14 + v7 + 7) = BYTE1(v3);
        *(_BYTE *)(v14 + v7 + 6) = BYTE2(v3);
        *(_BYTE *)(v14 + v7 + 10) = BYTE1(v15);
        *(_BYTE *)(v14 + v7 + 9) = BYTE2(v15);
        *(_BYTE *)(v14 + v7 + 5) = v20;
        *(_BYTE *)(v14 + v7 + 4) = HIBYTE(v20);
        *(_BYTE *)(v14 + v7) = v23;
        *(_BYTE *)(v14 + v7 + 8) = v3;
        *(_BYTE *)(v14 + v7 + 3) = v19;
        v3 += v15;
        v12 = v21;
        *(_BYTE *)(v14 + v7 + 11) = v15;
        LODWORD(v7) = v14;
        *((_DWORD *)v16 + 1) = v9 + v15 + v14;
        if ( v13 >= v21 )
          return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 87;
  }
  return v8;
}
