//----- (00000001800124F0) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::WriteEvent(CSchannelTelemetryContext *this, char a2, __int64 a3)
{
  const WCHAR *v3; // rdi
  int v6; // eax
  __int64 v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int16 v10; // [rsp+F0h] [rbp-80h] BYREF
  __int16 v11; // [rsp+F2h] [rbp-7Eh] BYREF
  int v12; // [rsp+F4h] [rbp-7Ch] BYREF
  int v13; // [rsp+F8h] [rbp-78h] BYREF
  int v14; // [rsp+FCh] [rbp-74h] BYREF
  int v15; // [rsp+100h] [rbp-70h] BYREF
  int v16; // [rsp+104h] [rbp-6Ch] BYREF
  int v17; // [rsp+108h] [rbp-68h] BYREF
  int v18; // [rsp+10Ch] [rbp-64h] BYREF
  int v19; // [rsp+110h] [rbp-60h] BYREF
  int v20; // [rsp+114h] [rbp-5Ch] BYREF
  int v21; // [rsp+118h] [rbp-58h] BYREF
  int v22; // [rsp+11Ch] [rbp-54h] BYREF
  int v23; // [rsp+120h] [rbp-50h] BYREF
  __int64 v24; // [rsp+128h] [rbp-48h] BYREF
  const WCHAR *v25; // [rsp+130h] [rbp-40h] BYREF
  __int64 v26; // [rsp+138h] [rbp-38h] BYREF
  __int64 v27; // [rsp+140h] [rbp-30h] BYREF
  __int64 v28; // [rsp+148h] [rbp-28h] BYREF
  __int16 v29; // [rsp+150h] [rbp-20h]
  __int64 v30; // [rsp+158h] [rbp-18h] BYREF
  const WCHAR *v31; // [rsp+160h] [rbp-10h] BYREF
  const WCHAR *v32; // [rsp+168h] [rbp-8h] BYREF
  const WCHAR *v33; // [rsp+170h] [rbp+0h] BYREF
  __int16 v34; // [rsp+178h] [rbp+8h]
  char v35; // [rsp+1A0h] [rbp+30h] BYREF
  char v36; // [rsp+1B0h] [rbp+40h] BYREF
  __int16 v37; // [rsp+1B8h] [rbp+48h] BYREF

  v3 = (const WCHAR *)((char *)this + 152);
  if ( this == (CSchannelTelemetryContext *)-152i64
    || !wcsstr(v3, L".data.microsoft.com") && !wcsstr(v3, L".telemetry.microsoft.com") )
  {
    v6 = *((_DWORD *)this + 3);
    if ( a2 )
    {
      if ( v6 )
      {
        if ( v6 == 1
          && (unsigned int)dword_180091480 > 5
          && (qword_180091490 & 0x400000000000i64) != 0
          && (qword_180091498 & 0x400000000000i64) == qword_180091498 )
        {
          v23 = *((_DWORD *)this + 395);
          v28 = (__int64)this + 1176;
          v29 = *((_WORD *)this + 788);
          v22 = *((_DWORD *)this + 11);
          v21 = *((_DWORD *)this + 28);
          v9 = *((unsigned __int16 *)this + 892);
          v35 = *((_BYTE *)this + 108);
          v20 = *((_DWORD *)this + 26);
          v19 = *((_DWORD *)this + 15);
          v18 = *((_DWORD *)this + 14);
          v17 = *((_DWORD *)this + 13);
          v16 = *((_DWORD *)this + 12);
          v15 = *((_DWORD *)this + 10);
          v14 = *((_DWORD *)this + 9);
          v33 = (const WCHAR *)((char *)this + 1584);
          v13 = *((_DWORD *)this + 18);
          v12 = *((_DWORD *)this + 17);
          v11 = *((_WORD *)this + 33);
          v10 = *((_WORD *)this + 32);
          v27 = *((_QWORD *)this + 16);
          v26 = *((_QWORD *)this + 15);
          v36 = *((_BYTE *)this + 24);
          v37 = v9;
          v34 = v9;
          v25 = (const WCHAR *)((char *)this + 664);
          v24 = 1i64;
          _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteAgg(_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),void const *>::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperArray<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperArray<4>,_tlgWrapperByVal<4>>(
            v9,
            byte_1800847A6,
            a3,
            (__int64)&v24,
            &v25,
            (__int64)&v36,
            (__int64)&v26,
            (__int64)&v27,
            (__int64)&v10,
            (__int64)&v11,
            (__int64)&v12,
            (__int64)&v13,
            (__int64)&v33,
            (__int64)&v37,
            (__int64)&v14,
            (__int64)&v15,
            (__int64)&v16,
            (__int64)&v17,
            (__int64)&v18,
            (__int64)&v19,
            (__int64)&v20,
            (__int64)&v35,
            (__int64)&v21,
            (__int64)&v22,
            (__int64)&v28,
            (__int64)&v23);
        }
      }
      else if ( (unsigned int)dword_180091480 > 5
             && (qword_180091490 & 0x400000000000i64) != 0
             && (qword_180091498 & 0x400000000000i64) == qword_180091498 )
      {
        v12 = *((_DWORD *)this + 28);
        v35 = *((_BYTE *)this + 108);
        v13 = *((_DWORD *)this + 26);
        v14 = *((_DWORD *)this + 15);
        v15 = *((_DWORD *)this + 14);
        v8 = *((unsigned __int16 *)this + 892);
        v16 = *((_DWORD *)this + 13);
        v17 = *((_DWORD *)this + 12);
        v18 = *((_DWORD *)this + 10);
        v19 = *((_DWORD *)this + 9);
        v28 = (__int64)this + 1584;
        v20 = *((_DWORD *)this + 18);
        v21 = *((_DWORD *)this + 17);
        v10 = *((_WORD *)this + 33);
        v11 = *((_WORD *)this + 32);
        v30 = *((_QWORD *)this + 16);
        v31 = (const WCHAR *)*((_QWORD *)this + 15);
        v36 = *((_BYTE *)this + 24);
        v32 = (const WCHAR *)((char *)this + 664);
        v22 = *((_DWORD *)this + 8);
        v23 = bDomainJoined;
        v24 = *((_QWORD *)this + 12);
        v25 = (const WCHAR *)v24;
        v26 = v24;
        v37 = v8;
        v29 = v8;
        v33 = v3;
        v27 = 1i64;
        _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteAgg(_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),void const *>::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperArray<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>>(
          v8,
          byte_1800843DE,
          a3,
          (__int64)&v27,
          (__int64)&v26,
          (__int64)&v25,
          (__int64)&v24,
          &v33,
          (__int64)&v23,
          (__int64)&v22,
          &v32,
          (__int64)&v36,
          (__int64)&v31,
          (__int64)&v30,
          (__int64)&v11,
          (__int64)&v10,
          (__int64)&v21,
          (__int64)&v20,
          (__int64)&v28,
          (__int64)&v37,
          (__int64)&v19,
          (__int64)&v18,
          (__int64)&v17,
          (__int64)&v16,
          (__int64)&v15,
          (__int64)&v14,
          (__int64)&v13,
          (__int64)&v35,
          (__int64)&v12);
      }
    }
    else if ( v6 )
    {
      if ( v6 == 1 )
        CSchannelTelemetryContext::WriteServerEvent(this);
    }
    else if ( (unsigned int)dword_180091480 > 5
           && (qword_180091490 & 0x400000000000i64) != 0
           && (qword_180091498 & 0x400000000000i64) == qword_180091498 )
    {
      v23 = *((_DWORD *)this + 28);
      v35 = *((_BYTE *)this + 108);
      v22 = *((_DWORD *)this + 26);
      v21 = *((_DWORD *)this + 15);
      v20 = *((_DWORD *)this + 14);
      v7 = *((unsigned __int16 *)this + 892);
      v19 = *((_DWORD *)this + 13);
      v18 = *((_DWORD *)this + 12);
      v17 = *((_DWORD *)this + 10);
      v16 = *((_DWORD *)this + 9);
      v28 = (__int64)this + 1584;
      v15 = *((_DWORD *)this + 18);
      v14 = *((_DWORD *)this + 17);
      v11 = *((_WORD *)this + 33);
      v10 = *((_WORD *)this + 32);
      v27 = *((_QWORD *)this + 16);
      v26 = *((_QWORD *)this + 15);
      v36 = *((_BYTE *)this + 24);
      v25 = (const WCHAR *)((char *)this + 664);
      v13 = *((_DWORD *)this + 8);
      v12 = bDomainJoined;
      v33 = (const WCHAR *)*((_QWORD *)this + 12);
      v32 = v33;
      v31 = v33;
      v37 = v7;
      v29 = v7;
      v24 = (__int64)v3;
      v30 = 1i64;
      _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteAgg(_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),void const *>::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned short>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperArray<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>>(
        v7,
        byte_1800845BE,
        a3,
        (__int64)&v30,
        (__int64)&v31,
        (__int64)&v32,
        (__int64)&v33,
        (const WCHAR **)&v24,
        (__int64)&v12,
        (__int64)&v13,
        &v25,
        (__int64)&v36,
        (__int64)&v26,
        (__int64)&v27,
        (__int64)&v10,
        (__int64)&v11,
        (__int64)&v14,
        (__int64)&v15,
        (__int64)&v28,
        (__int64)&v37,
        (__int64)&v16,
        (__int64)&v17,
        (__int64)&v18,
        (__int64)&v19,
        (__int64)&v20,
        (__int64)&v21,
        (__int64)&v22,
        (__int64)&v35,
        (__int64)&v23);
    }
  }
}
// 18001277C: variable 'a3' is possibly undefined
// 1800843DE: using guessed type unsigned __int8 byte_1800843DE[480];
// 1800845BE: using guessed type unsigned __int8 byte_1800845BE[488];
// 1800847A6: using guessed type unsigned __int8 byte_1800847A6[437];
// 180091490: using guessed type __int64 qword_180091490;
// 180091498: using guessed type __int64 qword_180091498;
// 180092648: using guessed type int bDomainJoined;

