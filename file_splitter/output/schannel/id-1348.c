//----- (000000018006A960) ----------------------------------------------------
void __fastcall CTls13ClientContext::CleanupConnectedState(CTls13ClientContext *this)
{
  CTls13Context::CleanupTls13SharedConnectedState((CTls13ClientContext *)((char *)this + 1368));
  CSsl3TlsClientContext::CleanupConnectedState(this);
}

