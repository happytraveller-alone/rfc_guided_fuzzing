//----- (0000000180027AF0) ----------------------------------------------------
void __fastcall TlgAggregateInternalRegisteredProviderEtwCallback(
        const struct _GUID *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5,
        struct _EVENT_FILTER_DESCRIPTOR *a6,
        _QWORD *a7)
{
  void (__fastcall *v8)(const struct _GUID *, _QWORD, __int64, __int64, unsigned __int64, struct _EVENT_FILTER_DESCRIPTOR *, _QWORD); // rax

  v8 = (void (__fastcall *)(const struct _GUID *, _QWORD, __int64, __int64, unsigned __int64, struct _EVENT_FILTER_DESCRIPTOR *, _QWORD))a7[39];
  if ( v8 )
    v8(a1, a2, a3, a4, a5, a6, a7[40]);
  if ( a2 == 1 )
  {
    LookUpTableFlushComplete((__int64)a7);
  }
  else if ( a2 == 2 )
  {
    LookUpTableFlushPartial((__int64)a7);
  }
}
