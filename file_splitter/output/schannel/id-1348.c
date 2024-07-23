// File count: 1348
// Total lines: 6
-----------------------------------------
void __fastcall CTls13ClientContext::CleanupConnectedState(CTls13ClientContext *this)
{
  CTls13Context::CleanupTls13SharedConnectedState((CTls13ClientContext *)((char *)this + 1368));
  CSsl3TlsClientContext::CleanupConnectedState(this);
}
