// File count: 460
// Total lines: 12
-----------------------------------------
__int64 __fastcall CTls13ServerContext::TlsParseClientHello(
        CTls13ServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *const a4,
        unsigned int *a5,
        unsigned int **a6,
        unsigned int *a7)
{
  return CTls13ServerHandshake::ParseClientHello((CTls13ServerContext *)((char *)this + 1288), a2, a3, a4, a5, a6, a7);
}
