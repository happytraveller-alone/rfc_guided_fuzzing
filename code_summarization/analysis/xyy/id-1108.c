//----- (000000018005B150) ----------------------------------------------------
unsigned int __fastcall CTls13ServerContext::ImportApplicationTrafficSecret(
        CTls13ServerContext *this,
        unsigned __int64 a2,
        char a3,
        unsigned __int8 *a4,
        unsigned int a5)
{
  return CTls13Context::ImportApplicationTrafficSecret(
           (CTls13ServerContext *)((char *)this + 1088),
           a2,
           (unsigned __int64 *)((char *)this + (-(__int64)(a3 != 0) & 0xFFFFFFFFFFFFFFF8ui64) + 1088),
           a4,
           a5);
}
