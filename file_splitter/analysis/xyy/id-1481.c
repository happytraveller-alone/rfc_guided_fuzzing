//----- (00000001800774B0) ----------------------------------------------------
__int64 __fastcall CTls13Record::SetFlightInfo(
        CTls13Record *this,
        unsigned __int16 a2,
        struct CTlsRecord::CMessageInfo *a3,
        unsigned int *a4)
{
  unsigned int v6; // esi
  int v7; // ebp
  unsigned __int16 v8; // di
  bool v9; // r14
  unsigned __int16 v10; // r9
  unsigned __int16 v11; // bx
  struct CTlsRecord::CMessageInfo *v12; // r12
  unsigned __int16 v13; // dx
  int v14; // ebp
  int v15; // eax
  bool v16; // cf
  unsigned __int16 v17; // dx
  unsigned int v18; // eax
  int v19; // ecx
  int v21; // [rsp+0h] [rbp-38h]
  struct CTlsRecord::CMessageInfo *v22; // [rsp+8h] [rbp-30h]

  if ( *((_QWORD *)this + 6) || !a2 || !a3 || !a4 )
    return 87i64;
  v6 = 0;
  v7 = *((_DWORD *)a3 + 1);
  v8 = *((_WORD *)this + 40);
  v21 = v7;
  if ( (*((_BYTE *)a3 + 8) & 2) != 0 )
  {
    v9 = 1;
    v10 = v8 - 1;
  }
  else
  {
    v9 = 0;
    v10 = *((_WORD *)this + 40);
  }
  v11 = v10;
  v12 = a3;
  v22 = (struct CTlsRecord::CMessageInfo *)((char *)a3 + 12 * a2);
  if ( a3 < v22 )
  {
    while ( 1 )
    {
      v13 = *(_WORD *)v12;
      if ( *(_WORD *)v12 )
      {
        if ( *((_DWORD *)v12 + 1) == 21 && v13 > v8 )
          return 87i64;
        if ( *((_DWORD *)v12 + 1) == v7
          && (*((_DWORD *)v12 + 1) != 21 || v11 >= v13)
          && ((*((_DWORD *)v12 + 2) & 2) != 0) == v9 )
        {
          v14 = v8;
        }
        else
        {
          v15 = v11;
          v16 = v9;
          v9 = (*((_DWORD *)v12 + 2) & 2) != 0;
          v11 = v8 - 1;
          v14 = v8;
          v21 = *((_DWORD *)v12 + 1);
          v6 += v8 + (v16 ? 21 : 5) - v15;
          if ( (*((_DWORD *)v12 + 2) & 2) == 0 )
            v11 = v8;
          v10 = v11;
        }
        if ( v13 >= v11 )
        {
          v17 = v13 - v11;
          v11 = 0;
          v18 = v17;
          v13 = v17 % v10;
          v19 = v14 + (v9 ? 21 : 5);
          v6 += v19 * (unsigned __int16)(v18 / v10);
          if ( !v13 )
            goto LABEL_30;
          v10 = v8 - 1;
          v9 = (*((_DWORD *)v12 + 2) & 2) != 0;
          v6 += v19;
          v21 = *((_DWORD *)v12 + 1);
          if ( (*((_DWORD *)v12 + 2) & 2) == 0 )
            v10 = v8;
          v11 = v10;
        }
        v11 -= v13;
      }
      else
      {
        if ( *((_DWORD *)v12 + 1) != 23 )
          return 87i64;
        v14 = v8;
      }
LABEL_30:
      v12 = (struct CTlsRecord::CMessageInfo *)((char *)v12 + 12);
      if ( v12 >= v22 )
      {
        if ( v11 < v10 )
          v6 += v14 + (v9 ? 21 : 5) - v11;
        break;
      }
      v7 = v21;
    }
  }
  *((_WORD *)this + 8) = a2;
  *((_QWORD *)this + 3) = a3;
  *((_QWORD *)this + 4) = a3;
  *((_DWORD *)this + 10) = v6;
  *a4 = v6;
  return 0i64;
}
