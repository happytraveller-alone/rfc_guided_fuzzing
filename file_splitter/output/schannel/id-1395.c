// File count: 1395
// Total lines: 51
----------------------------------------
__int64 __fastcall CTls13ClientContext::UpdateHandshakeHash(
        CTls13ClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  __int64 v3; // rax
  __int64 *v6; // rcx
  __int64 v8; // r9
  int v9; // ecx
  __int64 v10; // rax

  v3 = 0i64;
  if ( !*((_BYTE *)this + 1601) )
  {
    if ( *((_DWORD *)this + 137) )
      return CSsl3TlsContext::UpdateHandshakeHash(this, a2, a3);
    v8 = *((_QWORD *)this + 110);
    if ( !v8 )
      return 1359i64;
    v9 = *((_DWORD *)this + 218);
    if ( !v9 )
      return 1359i64;
    if ( a2 )
    {
      if ( !a3 )
        return 87i64;
    }
    else if ( a3 )
    {
      return 87i64;
    }
    v10 = *((unsigned int *)this + 458);
    if ( a3 <= v9 - (int)v10 )
    {
      memcpy_0((void *)(v8 + v10), a2, a3);
      *((_DWORD *)this + 458) += a3;
      return 0i64;
    }
    return 87i64;
  }
  v6 = (__int64 *)*((_QWORD *)this + 1);
  if ( v6 )
    v3 = *v6;
  return CTls13Context::HashPostHandshakeMessage(
           (CTls13ClientContext *)((char *)this + 1368),
           v3,
           *((_QWORD *)this + 74),
           a2,
           a3);
}
