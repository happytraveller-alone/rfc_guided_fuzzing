//----- (0000000180075FAC) ----------------------------------------------------
__int64 __fastcall CTlsExtServer::ParseServerNameExtension(
        CSsl3TlsServerContext **this,
        const unsigned __int8 *a2,
        unsigned int a3)
{
  const unsigned __int8 *v4; // rbx
  unsigned int v5; // edi
  unsigned __int8 v6; // cl
  unsigned int v7; // edi
  unsigned __int16 *v8; // rbx
  unsigned __int16 v9; // si
  const unsigned __int8 *v10; // rbx
  unsigned int v11; // edi
  __int64 result; // rax

  if ( a3 >= 2 && _byteswap_ushort(*(_WORD *)a2) >= 3u )
  {
    v4 = a2 + 2;
    v5 = a3 - 2;
    if ( a3 == 2 )
      return 0i64;
    while ( 1 )
    {
      v6 = *v4;
      v7 = v5 - 1;
      v8 = (unsigned __int16 *)(v4 + 1);
      if ( v7 < 2 )
        break;
      v9 = _byteswap_ushort(*v8);
      if ( !v9 )
        break;
      v10 = (const unsigned __int8 *)(v8 + 1);
      v11 = v7 - 2;
      if ( v11 < v9 )
        break;
      if ( !v6 )
      {
        result = CSsl3TlsServerContext::SetServerNameIndication(this[4], v10, v9);
        if ( (_DWORD)result )
          return result;
      }
      v4 = &v10[v9];
      v5 = v11 - v9;
      if ( !v5 )
        return 0i64;
    }
  }
  return 2148074278i64;
}

