//----- (000000018005A4F8) ----------------------------------------------------
void __fastcall CTls13ClientContext::~CTls13ClientContext(CTls13ClientContext *this)
{
  CTls13Context *v1; // rbx

  v1 = (CTls13ClientContext *)((char *)this + 1368);
  *(_QWORD *)this = &CTls13ClientContext::`vftable'{for `CSsl3TlsClientContext'};
  *((_QWORD *)this + 171) = &CTls13ClientContext::`vftable'{for `CTls13Context'};
  CTls13Context::CleanupTls13SharedConnectedState((CTls13ClientContext *)((char *)this + 1368));
  CSsl3TlsClientContext::CleanupConnectedState(this);
  *((_QWORD *)this + 207) = &CTls13ClientHandshake::`vftable';
  CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::~CTls13Handshake<CTls13ClientContext,CTls13ExtClient>((_QWORD *)this + 207);
  CTls13Context::~CTls13Context(v1);
  CSsl3TlsClientContext::~CSsl3TlsClientContext((struct CSessionCacheItem **)this);
}
// 18007D550: using guessed type void *CTls13ClientHandshake::`vftable';
// 18007FAE0: using guessed type void *CTls13ClientContext::`vftable'{for `CSsl3TlsClientContext'};
// 18007FCF0: using guessed type void *CTls13ClientContext::`vftable'{for `CTls13Context'};

