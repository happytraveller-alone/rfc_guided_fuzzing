// File count: 465
// Total lines: 8
------------------------------------------
__int64 __fastcall CTls13ServerContext::SetGenericExtensionBuffers(
        CTls13ServerContext *this,
        struct _SecBufferDesc *const a2,
        struct _SecBuffer *const a3)
{
  return CTls13Context::SetGenericExtensionBuffers((CTls13ServerContext *)((char *)this + 1000), a2, a3);
}
