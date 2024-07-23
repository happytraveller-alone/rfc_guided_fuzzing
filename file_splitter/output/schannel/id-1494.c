// File count: 1494
// Total lines: 32
----------------------------------------
__int64 __fastcall CTls13ExtServer::ParseKeyShareExtension(
        CTls13ExtServer *this,
        unsigned __int8 *a2,
        unsigned __int16 a3)
{
  __int16 v3; // ax
  __int16 v4; // r9
  const unsigned __int8 *v5; // rdx
  unsigned __int16 v6; // r9
  unsigned __int16 v7; // r8

  if ( a2 && a3 >= 2u )
  {
    v3 = a2[1];
    v4 = *a2;
    v5 = a2 + 2;
    v6 = v3 | (v4 << 8);
    v7 = a3 - 2;
    if ( v6 )
    {
      if ( v6 >= 2u && v6 == v7 )
        return CTls13ServerContext::StoreClientShares(*((CTls13ServerContext **)this + 5), v5, v7);
    }
    else if ( *(_DWORD *)(*((_QWORD *)this + 1) + 68i64) != 71 )
    {
      return 0i64;
    }
  }
  CSslContext::SetErrorAndFatalAlert(*((_QWORD *)this + 1), 1202, -2146893048, 0x32u);
  return 2148074248i64;
}
