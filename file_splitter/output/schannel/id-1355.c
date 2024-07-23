// File count: 1355
// Total lines: 58
----------------------------------------
__int64 __fastcall CTls13ServerContext::FindClientShare(
        CTls13ServerContext *this,
        __int16 a2,
        const unsigned __int8 **a3,
        unsigned __int16 *a4)
{
  unsigned __int16 v7; // cx
  const unsigned __int8 *v8; // r10
  __int16 v9; // dx
  unsigned __int16 v10; // bx
  __int16 v11; // ax
  const unsigned __int8 *v12; // r10
  unsigned __int16 v13; // dx
  unsigned __int16 v14; // cx

  if ( a3 )
    *a3 = 0i64;
  if ( a4 )
    *a4 = 0;
  if ( (a3 == 0i64) != (a4 == 0i64) )
    return 87i64;
  v7 = *((_WORD *)this + 752);
  v8 = (const unsigned __int8 *)*((_QWORD *)this + 187);
  if ( !v7 )
    return 1168i64;
  while ( 1 )
  {
    if ( v7 < 4u
      || (v9 = v8[2],
          v10 = _byteswap_ushort(*(_WORD *)v8),
          v11 = v8[3],
          v12 = v8 + 4,
          v13 = v11 | (v9 << 8),
          v14 = v7 - 4,
          !v13)
      || v13 > v14 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 1202, -2146893048, 0x32u);
      return 2148074248i64;
    }
    if ( a2 == v10 )
      break;
    v8 = &v12[v13];
    v7 = v14 - v13;
    if ( !v7 )
      return 1168i64;
  }
  if ( a3 )
  {
    if ( a4 )
    {
      *a3 = v12;
      *a4 = v13;
    }
  }
  return 0i64;
}
