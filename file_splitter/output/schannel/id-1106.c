// File count: 1106
// Total lines: 8
-----------------------------------------
void __fastcall CTls13ServerContext::GetReadWriteApplicationTrafficSecrets(
        CTls13ServerContext *this,
        unsigned __int64 *a2,
        unsigned __int64 *a3)
{
  CTls13Context::GetApplicationTrafficSecrets((CTls13ServerContext *)((char *)this + 1000), a2, a3);
}
