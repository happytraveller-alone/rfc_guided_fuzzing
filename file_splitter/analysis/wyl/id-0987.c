//----- (0000000180052B68) ----------------------------------------------------
ULONG __fastcall _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteAgg(_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),void const *>::Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned short>>(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        const WCHAR **a6)
{
  const WCHAR *v7; // rcx
  __int64 v8; // rax
  int v9; // edx
  ULONG result; // eax
  unsigned __int8 AggregateFieldTypes; // al
  EVENT_DESCRIPTOR EventDescriptor; // [rsp+30h] [rbp-39h] BYREF
  unsigned int v13; // [rsp+40h] [rbp-29h]
  struct _EVENT_DATA_DESCRIPTOR UserData; // [rsp+50h] [rbp-19h] BYREF
  unsigned __int8 *v15; // [rsp+60h] [rbp-9h]
  int v16; // [rsp+68h] [rbp-1h]
  int v17; // [rsp+6Ch] [rbp+3h]
  __int64 v18; // [rsp+70h] [rbp+7h]
  __int64 v19; // [rsp+78h] [rbp+Fh]
  __int64 v20; // [rsp+80h] [rbp+17h]
  __int64 v21; // [rsp+88h] [rbp+1Fh]
  const WCHAR *v22; // [rsp+90h] [rbp+27h]
  int v23; // [rsp+98h] [rbp+2Fh]
  int v24; // [rsp+9Ch] [rbp+33h]

  v7 = *a6;
  if ( *a6 )
  {
    v8 = -1i64;
    do
      ++v8;
    while ( v7[v8] );
    v9 = 2 * v8 + 2;
  }
  else
  {
    v7 = &Class;
    v9 = 2;
  }
  v20 = a5;
  *(_DWORD *)&EventDescriptor.Id = *a2 << 24;
  v22 = v7;
  *(_DWORD *)&EventDescriptor.Level = *(unsigned __int16 *)(a2 + 1);
  EventDescriptor.Keyword = *(_QWORD *)(a2 + 3);
  UserData.Ptr = (ULONGLONG)off_180091488;
  v23 = v9;
  v24 = 0;
  v21 = 4i64;
  v18 = a4;
  v19 = 4i64;
  UserData.Size = *(unsigned __int16 *)off_180091488;
  v16 = *(unsigned __int16 *)(a2 + 11);
  v15 = a2 + 11;
  UserData.Reserved = 2;
  v17 = 1;
  v13 = (unsigned int)&TraceLoggingMetadataEnd - (unsigned int)&TraceLoggingMetadata;
  result = -1073741811;
  if ( (void (__fastcall *)(const struct _GUID *, unsigned int, __int64, __int64, unsigned __int64, struct _EVENT_FILTER_DESCRIPTOR *, _QWORD *))qword_1800914A8 == TlgAggregateInternalRegisteredProviderEtwCallback )
  {
    AggregateFieldTypes = ExtractAggregateFieldTypes(
                            (__int64)TlgAggregateInternalRegisteredProviderEtwCallback,
                            (__int64)&UserData);
    if ( AggregateFieldTypes )
      return InsertEventEntryInLookUpTable(
               (__int64)&dword_180091480,
               (__int128 *)&EventDescriptor,
               5u,
               (__int64)&UserData,
               AggregateFieldTypes);
    else
      return EventWriteTransfer_0(RegHandle, &EventDescriptor, 0i64, 0i64, 5u, &UserData);
  }
  return result;
}
// 180091488: using guessed type void *off_180091488;
// 1800914A8: using guessed type __int64 qword_1800914A8;
