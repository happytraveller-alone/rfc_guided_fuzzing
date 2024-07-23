// File count: 1396
// Total lines: 22
----------------------------------------
__int64 __fastcall CTls13ServerContext::UpdateHandshakeHash(
        CTls13ServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  __int64 v4; // rdx
  __int64 *v5; // rax

  v4 = 0i64;
  if ( !*((_BYTE *)this + 1233) )
    return CSsl3TlsContext::UpdateHandshakeHash(this, a2, a3);
  v5 = (__int64 *)*((_QWORD *)this + 1);
  if ( v5 )
    v4 = *v5;
  return CTls13Context::HashPostHandshakeMessage(
           (CTls13ServerContext *)((char *)this + 1000),
           v4,
           *((_QWORD *)this + 74),
           a2,
           a3);
}
