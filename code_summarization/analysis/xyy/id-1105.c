//----- (000000018005B0E0) ----------------------------------------------------
void __fastcall CTls13ClientContext::GetReadWriteApplicationTrafficSecrets(
        CTls13ClientContext *this,
        unsigned __int64 *a2,
        unsigned __int64 *a3)
{
  CTls13Context::GetApplicationTrafficSecrets((CTls13ClientContext *)((char *)this + 1368), a3, a2);
}
