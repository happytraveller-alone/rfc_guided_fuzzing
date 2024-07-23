//----- (000000018005B120) ----------------------------------------------------
unsigned int __fastcall CTls13ClientContext::ImportApplicationTrafficSecret(
        CTls13ClientContext *this,
        unsigned __int64 a2,
        char a3,
        unsigned __int8 *a4,
        unsigned int a5)
{
  return CTls13Context::ImportApplicationTrafficSecret(
           (CTls13ClientContext *)((char *)this + 1448),
           a2,
           (unsigned __int64 *)((char *)this + (a3 != 0 ? 8 : 0) + 1448),
           a4,
           a5);
}

