//----- (000000018005B1B0) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::ParseCcsRecord(
        CTls13ServerContext *this,
        unsigned __int8 *const a2,
        unsigned int a3,
        int a4)
{
  return CTls13Context::ParseCcsRecord((__int64)this + 1000, (__int64)a2, a3, a4, *((_DWORD *)this + 17));
}

