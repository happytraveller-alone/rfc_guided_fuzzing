//----- (000000018005B250) ----------------------------------------------------
__int64 __fastcall CTls13ClientContext::SetGenericExtensionBuffers(
        CTls13ClientContext *this,
        struct _SecBufferDesc *const a2,
        struct _SecBuffer *const a3)
{
  return CTls13Context::SetGenericExtensionBuffers((CTls13ClientContext *)((char *)this + 1368), a2, a3);
}

