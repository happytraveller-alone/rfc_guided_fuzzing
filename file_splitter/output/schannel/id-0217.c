//----- (000000018001278C) ----------------------------------------------------
ULONG __fastcall _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteAgg(_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),void const *>::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperArray<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>>(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        const WCHAR **a8,
        __int64 a9,
        __int64 a10,
        const WCHAR **a11,
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
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29)
{
  __int64 v30; // rcx
  const WCHAR *v31; // rdx
  __int64 v32; // rax
  int v33; // r8d
  const WCHAR *v34; // rdx
  int v35; // eax
  ULONG result; // eax
  unsigned __int8 AggregateFieldTypes; // al
  EVENT_DESCRIPTOR EventDescriptor; // [rsp+38h] [rbp-D0h] BYREF
  unsigned int v39; // [rsp+48h] [rbp-C0h]
  struct _EVENT_DATA_DESCRIPTOR UserData; // [rsp+58h] [rbp-B0h] BYREF
  unsigned __int8 *v41; // [rsp+68h] [rbp-A0h]
  int v42; // [rsp+70h] [rbp-98h]
  int v43; // [rsp+74h] [rbp-94h]
  __int64 v44; // [rsp+78h] [rbp-90h]
  __int64 v45; // [rsp+80h] [rbp-88h]
  __int64 v46; // [rsp+88h] [rbp-80h]
  __int64 v47; // [rsp+90h] [rbp-78h]
  __int64 v48; // [rsp+98h] [rbp-70h]
  __int64 v49; // [rsp+A0h] [rbp-68h]
  __int64 v50; // [rsp+A8h] [rbp-60h]
  __int64 v51; // [rsp+B0h] [rbp-58h]
  const WCHAR *v52; // [rsp+B8h] [rbp-50h]
  int v53; // [rsp+C0h] [rbp-48h]
  int v54; // [rsp+C4h] [rbp-44h]
  __int64 v55; // [rsp+C8h] [rbp-40h]
  __int64 v56; // [rsp+D0h] [rbp-38h]
  __int64 v57; // [rsp+D8h] [rbp-30h]
  __int64 v58; // [rsp+E0h] [rbp-28h]
  const WCHAR *v59; // [rsp+E8h] [rbp-20h]
  int v60; // [rsp+F0h] [rbp-18h]
  int v61; // [rsp+F4h] [rbp-14h]
  __int64 v62; // [rsp+F8h] [rbp-10h]
  __int64 v63; // [rsp+100h] [rbp-8h]
  __int64 v64; // [rsp+108h] [rbp+0h]
  __int64 v65; // [rsp+110h] [rbp+8h]
  __int64 v66; // [rsp+118h] [rbp+10h]
  __int64 v67; // [rsp+120h] [rbp+18h]
  __int64 v68; // [rsp+128h] [rbp+20h]
  __int64 v69; // [rsp+130h] [rbp+28h]
  __int64 v70; // [rsp+138h] [rbp+30h]
  __int64 v71; // [rsp+140h] [rbp+38h]
  __int64 v72; // [rsp+148h] [rbp+40h]
  __int64 v73; // [rsp+150h] [rbp+48h]
  __int64 v74; // [rsp+158h] [rbp+50h]
  __int64 v75; // [rsp+160h] [rbp+58h]
  __int64 v76; // [rsp+168h] [rbp+60h]
  __int64 v77; // [rsp+170h] [rbp+68h]
  __int64 v78; // [rsp+178h] [rbp+70h]
  int v79; // [rsp+180h] [rbp+78h]
  int v80; // [rsp+184h] [rbp+7Ch]
  __int64 v81; // [rsp+188h] [rbp+80h]
  __int64 v82; // [rsp+190h] [rbp+88h]
  __int64 v83; // [rsp+198h] [rbp+90h]
  __int64 v84; // [rsp+1A0h] [rbp+98h]
  __int64 v85; // [rsp+1A8h] [rbp+A0h]
  __int64 v86; // [rsp+1B0h] [rbp+A8h]
  __int64 v87; // [rsp+1B8h] [rbp+B0h]
  __int64 v88; // [rsp+1C0h] [rbp+B8h]
  __int64 v89; // [rsp+1C8h] [rbp+C0h]
  __int64 v90; // [rsp+1D0h] [rbp+C8h]
  __int64 v91; // [rsp+1D8h] [rbp+D0h]
  __int64 v92; // [rsp+1E0h] [rbp+D8h]
  __int64 v93; // [rsp+1E8h] [rbp+E0h]
  __int64 v94; // [rsp+1F0h] [rbp+E8h]
  __int64 v95; // [rsp+1F8h] [rbp+F0h]
  __int64 v96; // [rsp+200h] [rbp+F8h]
  __int64 v97; // [rsp+208h] [rbp+100h]
  __int64 v98; // [rsp+210h] [rbp+108h]
  __int64 v99; // [rsp+218h] [rbp+110h]
  __int64 v100; // [rsp+220h] [rbp+118h]

  v99 = a29;
  v97 = a28;
  v95 = a27;
  v93 = a26;
  v91 = a25;
  v89 = a24;
  v87 = a23;
  v85 = a22;
  v83 = a21;
  v81 = a20;
  v100 = 4i64;
  v98 = 1i64;
  v96 = 4i64;
  v94 = 4i64;
  v78 = *(_QWORD *)a19;
  v79 = 4 * *(unsigned __int16 *)(a19 + 8);
  v74 = a18;
  v72 = a17;
  v70 = a16;
  v68 = a15;
  v66 = a14;
  v64 = a13;
  v62 = a12;
  v76 = a19 + 8;
  v30 = -1i64;
  v92 = 4i64;
  v90 = 4i64;
  v31 = *a11;
  v88 = 4i64;
  v86 = 4i64;
  v84 = 4i64;
  v82 = 2i64;
  v77 = 2i64;
  v80 = 0;
  v75 = 4i64;
  v73 = 4i64;
  v71 = 2i64;
  v69 = 2i64;
  v67 = 8i64;
  v65 = 8i64;
  v63 = 1i64;
  if ( v31 )
  {
    v32 = -1i64;
    do
      ++v32;
    while ( v31[v32] );
    v33 = 2 * v32 + 2;
  }
  else
  {
    v31 = &Class;
    v33 = 2;
  }
  v57 = a10;
  v55 = a9;
  v59 = v31;
  v60 = v33;
  v61 = 0;
  v34 = *a8;
  v58 = 4i64;
  v56 = 4i64;
  if ( v34 )
  {
    do
      ++v30;
    while ( v34[v30] );
    v35 = 2 * v30 + 2;
  }
  else
  {
    v34 = &Class;
    v35 = 2;
  }
  v53 = v35;
  v50 = a7;
  v48 = a6;
  v46 = a5;
  *(_DWORD *)&EventDescriptor.Id = *a2 << 24;
  *(_DWORD *)&EventDescriptor.Level = *(unsigned __int16 *)(a2 + 1);
  v52 = v34;
  v54 = 0;
  EventDescriptor.Keyword = *(_QWORD *)(a2 + 3);
  UserData.Ptr = (ULONGLONG)off_180091488;
  v51 = 8i64;
  v49 = 8i64;
  v47 = 8i64;
  v44 = a4;
  v45 = 8i64;
  UserData.Size = *(unsigned __int16 *)off_180091488;
  v42 = *(unsigned __int16 *)(a2 + 11);
  v41 = a2 + 11;
  UserData.Reserved = 2;
  v43 = 1;
  v39 = (unsigned int)&TraceLoggingMetadataEnd - (unsigned int)&TraceLoggingMetadata;
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
               0x1Du,
               (__int64)&UserData,
               AggregateFieldTypes);
    else
      return EventWriteTransfer_0(RegHandle, &EventDescriptor, 0i64, 0i64, 0x1Du, &UserData);
  }
  return result;
}
// 180091488: using guessed type void *off_180091488;
// 1800914A8: using guessed type __int64 qword_1800914A8;

