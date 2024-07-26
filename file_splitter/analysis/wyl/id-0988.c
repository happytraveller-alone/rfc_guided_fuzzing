//----- (0000000180052CC4) ----------------------------------------------------
ULONG __fastcall _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteAgg(_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),void const *>::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperArray<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperArray<4>,_tlgWrapperByVal<4>>(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        const WCHAR **a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26)
{
  const WCHAR *v27; // rcx
  __int64 v28; // rax
  int v29; // edx
  ULONG result; // eax
  unsigned __int8 AggregateFieldTypes; // al
  EVENT_DESCRIPTOR EventDescriptor; // [rsp+30h] [rbp-D0h] BYREF
  unsigned int v33; // [rsp+40h] [rbp-C0h]
  struct _EVENT_DATA_DESCRIPTOR UserData; // [rsp+50h] [rbp-B0h] BYREF
  unsigned __int8 *v35; // [rsp+60h] [rbp-A0h]
  int v36; // [rsp+68h] [rbp-98h]
  int v37; // [rsp+6Ch] [rbp-94h]
  __int64 v38; // [rsp+70h] [rbp-90h]
  __int64 v39; // [rsp+78h] [rbp-88h]
  const WCHAR *v40; // [rsp+80h] [rbp-80h]
  int v41; // [rsp+88h] [rbp-78h]
  int v42; // [rsp+8Ch] [rbp-74h]
  __int64 v43; // [rsp+90h] [rbp-70h]
  __int64 v44; // [rsp+98h] [rbp-68h]
  __int64 v45; // [rsp+A0h] [rbp-60h]
  __int64 v46; // [rsp+A8h] [rbp-58h]
  __int64 v47; // [rsp+B0h] [rbp-50h]
  __int64 v48; // [rsp+B8h] [rbp-48h]
  __int64 v49; // [rsp+C0h] [rbp-40h]
  __int64 v50; // [rsp+C8h] [rbp-38h]
  __int64 v51; // [rsp+D0h] [rbp-30h]
  __int64 v52; // [rsp+D8h] [rbp-28h]
  __int64 v53; // [rsp+E0h] [rbp-20h]
  __int64 v54; // [rsp+E8h] [rbp-18h]
  __int64 v55; // [rsp+F0h] [rbp-10h]
  __int64 v56; // [rsp+F8h] [rbp-8h]
  __int64 v57; // [rsp+100h] [rbp+0h]
  __int64 v58; // [rsp+108h] [rbp+8h]
  __int64 v59; // [rsp+110h] [rbp+10h]
  int v60; // [rsp+118h] [rbp+18h]
  int v61; // [rsp+11Ch] [rbp+1Ch]
  __int64 v62; // [rsp+120h] [rbp+20h]
  __int64 v63; // [rsp+128h] [rbp+28h]
  __int64 v64; // [rsp+130h] [rbp+30h]
  __int64 v65; // [rsp+138h] [rbp+38h]
  __int64 v66; // [rsp+140h] [rbp+40h]
  __int64 v67; // [rsp+148h] [rbp+48h]
  __int64 v68; // [rsp+150h] [rbp+50h]
  __int64 v69; // [rsp+158h] [rbp+58h]
  __int64 v70; // [rsp+160h] [rbp+60h]
  __int64 v71; // [rsp+168h] [rbp+68h]
  __int64 v72; // [rsp+170h] [rbp+70h]
  __int64 v73; // [rsp+178h] [rbp+78h]
  __int64 v74; // [rsp+180h] [rbp+80h]
  __int64 v75; // [rsp+188h] [rbp+88h]
  __int64 v76; // [rsp+190h] [rbp+90h]
  __int64 v77; // [rsp+198h] [rbp+98h]
  __int64 v78; // [rsp+1A0h] [rbp+A0h]
  __int64 v79; // [rsp+1A8h] [rbp+A8h]
  __int64 v80; // [rsp+1B0h] [rbp+B0h]
  __int64 v81; // [rsp+1B8h] [rbp+B8h]
  __int64 v82; // [rsp+1C0h] [rbp+C0h]
  __int64 v83; // [rsp+1C8h] [rbp+C8h]
  __int64 v84; // [rsp+1D0h] [rbp+D0h]
  __int64 v85; // [rsp+1D8h] [rbp+D8h]
  __int64 v86; // [rsp+1E0h] [rbp+E0h]
  int v87; // [rsp+1E8h] [rbp+E8h]
  int v88; // [rsp+1ECh] [rbp+ECh]
  __int64 v89; // [rsp+1F0h] [rbp+F0h]
  __int64 v90; // [rsp+1F8h] [rbp+F8h]

  v89 = a26;
  v90 = 4i64;
  v88 = 0;
  v85 = 2i64;
  v83 = 4i64;
  v86 = *(_QWORD *)a25;
  v87 = 4 * *(unsigned __int16 *)(a25 + 8);
  v82 = a24;
  v80 = a23;
  v78 = a22;
  v76 = a21;
  v74 = a20;
  v72 = a19;
  v70 = a18;
  v68 = a17;
  v66 = a16;
  v64 = a15;
  v62 = a14;
  v84 = a25 + 8;
  v81 = 4i64;
  v79 = 1i64;
  v77 = 4i64;
  v59 = *(_QWORD *)a13;
  v60 = 4 * *(unsigned __int16 *)(a13 + 8);
  v55 = a12;
  v53 = a11;
  v51 = a10;
  v49 = a9;
  v47 = a8;
  v45 = a7;
  v43 = a6;
  v75 = 4i64;
  v73 = 4i64;
  v71 = 4i64;
  v69 = 4i64;
  v67 = 4i64;
  v65 = 4i64;
  v63 = 2i64;
  v57 = a13 + 8;
  v58 = 2i64;
  v61 = 0;
  v56 = 4i64;
  v54 = 4i64;
  v52 = 2i64;
  v50 = 2i64;
  v48 = 8i64;
  v46 = 8i64;
  v44 = 1i64;
  v27 = *a5;
  if ( *a5 )
  {
    v28 = -1i64;
    do
      ++v28;
    while ( v27[v28] );
    v29 = 2 * v28 + 2;
  }
  else
  {
    v27 = &Class;
    v29 = 2;
  }
  *(_DWORD *)&EventDescriptor.Id = *a2 << 24;
  v40 = v27;
  *(_DWORD *)&EventDescriptor.Level = *(unsigned __int16 *)(a2 + 1);
  v41 = v29;
  v42 = 0;
  EventDescriptor.Keyword = *(_QWORD *)(a2 + 3);
  UserData.Ptr = (ULONGLONG)off_180091488;
  v38 = a4;
  v39 = 8i64;
  UserData.Size = *(unsigned __int16 *)off_180091488;
  v36 = *(unsigned __int16 *)(a2 + 11);
  v35 = a2 + 11;
  UserData.Reserved = 2;
  v37 = 1;
  v33 = (unsigned int)&TraceLoggingMetadataEnd - (unsigned int)&TraceLoggingMetadata;
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
               0x1Bu,
               (__int64)&UserData,
               AggregateFieldTypes);
    else
      return EventWriteTransfer_0(RegHandle, &EventDescriptor, 0i64, 0i64, 0x1Bu, &UserData);
  }
  return result;
}
// 180091488: using guessed type void *off_180091488;
// 1800914A8: using guessed type __int64 qword_1800914A8;

