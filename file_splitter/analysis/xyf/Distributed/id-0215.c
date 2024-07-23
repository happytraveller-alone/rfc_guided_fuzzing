//----- (00000001800124A0) ----------------------------------------------------
void __fastcall CSsl3TlsContext::SetStateConnected(CSsl3TlsContext *this)
{
  __int64 v1; // rax
  unsigned __int16 v3; // ax
  DTlsHandshakeQueue *v4; // rcx

  v1 = *(_QWORD *)this;
  *((_DWORD *)this + 17) = 4;
  (*(void (**)(void))(v1 + 456))();
  if ( *((_BYTE *)this + 233) )
  {
    v3 = CSslContext::computeMaxPayload(this, *((unsigned __int16 *)this + 108));
    v4 = (DTlsHandshakeQueue *)*((_QWORD *)this + 73);
    *((_WORD *)this + 109) = v3;
    DTlsHandshakeQueue::DtlsHandshakeDone(v4);
    **((_DWORD **)this + 72) = 0;
    *((_WORD *)this + 110) = 0;
  }
}

