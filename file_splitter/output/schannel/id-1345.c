// File count: 1345
// Total lines: 22
----------------------------------------
__int64 __fastcall CTls13ClientContext::SetServerKeyShare(CTls13ClientContext *this)
{
  unsigned __int64 *v1; // rax
  unsigned __int64 v3; // rcx
  unsigned int v4; // edi

  v1 = (unsigned __int64 *)*((_QWORD *)this + 1);
  if ( v1 )
    v3 = *v1;
  else
    v3 = 0i64;
  v4 = CTls13Context::SetPeerPublicKey(
         (CTls13ClientContext *)((char *)this + 1368),
         *((_WORD *)this + 919),
         *((const unsigned __int8 **)this + 230),
         *((_WORD *)this + 924),
         v3);
  if ( !v4 )
    CSslContext::SetEccCurveInfo(this, *((unsigned __int16 *)this + 919));
  return v4;
}
