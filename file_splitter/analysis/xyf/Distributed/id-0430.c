//----- (0000000180019220) ----------------------------------------------------
__int64 __fastcall CTlsExtServer::GetServerHelloExtensionsLength(
        CTlsExtServer *this,
        char a2,
        char a3,
        unsigned __int16 *a4)
{
  unsigned int v6; // ecx
  __int64 v8; // r9
  __int64 v9; // rax
  _DWORD *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rax
  _DWORD *v13; // r8
  unsigned int v14; // ecx
  unsigned int v15; // edx

  v6 = *((_DWORD *)this + 5);
  if ( !v6 )
  {
    v8 = *((_QWORD *)this + 1);
    if ( *(_BYTE *)(v8 + 922) )
    {
      v6 = 6;
      *((_BYTE *)this + 25) = 1;
      *((_DWORD *)this + 5) = 6;
    }
    if ( a2 )
    {
      v6 += 4;
      *((_BYTE *)this + 24) = 1;
      *((_DWORD *)this + 5) = v6;
    }
    if ( (*(_DWORD *)(v8 + 136) & 0x400000) != 0 )
      *((_DWORD *)this + 5) = v6 + 4;
    v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 88i64))(v8);
    if ( v9 && *(_DWORD *)v9 == 1 && *(_DWORD *)(v9 + 4) == 2 )
      *((_DWORD *)this + 5) += *(unsigned __int8 *)(v9 + 8) + 7;
    v10 = (_DWORD *)*((_QWORD *)this + 1);
    if ( (v10[34] & 0x8000000) != 0 )
      *((_DWORD *)this + 5) += 4;
    v11 = (*(__int64 (__fastcall **)(_DWORD *))(*(_QWORD *)v10 + 96i64))(v10);
    if ( v11 )
      *((_DWORD *)this + 5) += *(unsigned __int8 *)(v11 + 2) + 9;
    v12 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 1) + 104i64))(*((_QWORD *)this + 1));
    if ( v12 )
      *((_DWORD *)this + 5) += *(unsigned __int8 *)(v12 + 2) + 7;
    v13 = (_DWORD *)*((_QWORD *)this + 1);
    v6 = *((_DWORD *)this + 5);
    if ( a3 )
    {
      v14 = v6 + 5;
      *((_BYTE *)this + 26) = 1;
      *((_DWORD *)this + 5) = v14;
      v15 = v14 + v13[104];
      *((_DWORD *)this + 5) = v15;
      v6 = v15 + v13[114];
      *((_DWORD *)this + 5) = v6;
    }
    if ( (v13[34] & 0x200000) != 0 )
    {
      v6 += 4;
      *((_DWORD *)this + 5) = v6;
    }
    if ( v6 )
    {
      v6 += 2;
      *((_DWORD *)this + 5) = v6;
    }
  }
  if ( v6 > 0xFFFF )
    return 1359i64;
  *a4 = *((_WORD *)this + 10);
  return 0i64;
}

