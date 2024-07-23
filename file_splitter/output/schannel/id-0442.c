// File count: 442
// Total lines: 224
----------------------------------------
__int64 __fastcall CCipherMill::FindAcceptableCipherSuite(
        CCipherMill *this,
        struct CSsl3TlsServerContext *a2,
        struct CCipherSuiteInfo *a3,
        char a4,
        struct _UNICODE_STRING *String2,
        unsigned __int8 a6,
        enum _eTlsHashAlgorithm a7,
        unsigned int *a8,
        unsigned __int8 *a9)
{
  __int64 v11; // r8
  unsigned int v12; // r11d
  unsigned __int64 v13; // r10
  unsigned int v14; // esi
  unsigned int v15; // ebp
  int v16; // r9d
  int v17; // edi
  int v18; // eax
  unsigned int *v19; // rdx
  int v20; // r10d
  int v21; // r8d
  int v22; // ebx
  int v23; // edx
  unsigned __int8 v24; // r9
  _DWORD *i; // rax
  int v26; // ecx
  int v27; // ecx
  char v28; // al
  char v29; // r8
  unsigned int AcceptableKeyXCurve; // ebx
  __int64 v32; // rax
  int v33; // ecx
  struct hsel *HashInfo; // rax
  __int64 v35; // [rsp+20h] [rbp-98h]
  __int64 v36; // [rsp+20h] [rbp-98h]
  __int64 v37; // [rsp+70h] [rbp-48h]
  int v38; // [rsp+C0h] [rbp+8h]
  const wchar_t *v39; // [rsp+C8h] [rbp+10h]

  if ( !a2 || !a3 || !a8 || !a9 )
    return 2148074333i64;
  v11 = *((_QWORD *)a2 + 10);
  v12 = *(_DWORD *)(v11 + 196);
  v13 = *(_QWORD *)(v11 + 200);
  v14 = *(_DWORD *)(v11 + 164);
  v15 = *(_DWORD *)(v11 + 168);
  v16 = *(_DWORD *)(v11 + 192);
  v17 = *((_DWORD *)a2 + 16);
  v39 = (const wchar_t *)((char *)a3 + 74);
  v18 = *(_DWORD *)(v11 + 156);
  v37 = v11;
  LODWORD(v11) = *(_DWORD *)(v11 + 176);
  v38 = 1;
  v19 = *(unsigned int **)(v37 + 184);
  *a8 = 0;
  *a9 = 0;
  if ( !CCipherMill::IsCipherSuiteAllowed(
          (__int64)g_cCipherMill,
          v19,
          v11,
          v16,
          (v18 & 0x1000) != 0,
          v18 & 0x800,
          v15,
          v14,
          v17,
          (__int64)a3,
          String2,
          v13,
          v12,
          a6) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_S(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x29u,
        (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
        v39);
    return (unsigned int)-2146893007;
  }
  v20 = *((_DWORD *)a3 + 12);
  if ( v20 == 4 )
    return 0;
  if ( *((_DWORD *)a2 + 17) == 71 )
  {
    if ( (*((_BYTE *)a2 + 32) & 1) != 0 && (v32 = *((_QWORD *)a2 + 1)) != 0 )
      v33 = *(_DWORD *)(v32 + 28);
    else
      v33 = 0;
    if ( *((_DWORD *)a3 + 7) != v33 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x2Au,
          (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
          v39);
        return (unsigned int)-2146893007;
      }
      return (unsigned int)-2146893007;
    }
  }
  v21 = *((_DWORD *)a2 + 16);
  if ( (v21 & 0x40400) != 0 && a2 != (struct CSsl3TlsServerContext *)-510i64 )
  {
    v22 = *((_DWORD *)a3 + 9);
    switch ( v22 )
    {
      case 9216:
        goto LABEL_11;
      case 8704:
        v23 = 2;
        v38 = 2;
        goto LABEL_12;
      case 8707:
        v23 = 3;
        v38 = 3;
        goto LABEL_12;
      case 41984:
LABEL_11:
        v23 = 1;
LABEL_12:
        v24 = 0;
        for ( i = &unk_18007C3A8; i - 6 < (_DWORD *)&CSsl3TlsServerContext::`vftable'; i += 18 )
        {
          v26 = i[1];
          if ( v26 == v23 && (v21 & *i) != 0 && ((v21 & 0x3000) == 0 || v26 != 3 || !i[10]) && v24 < 0xCu )
          {
            v27 = *((unsigned __int16 *)a2 + 272);
            if ( _bittest(&v27, v24) )
              goto LABEL_20;
            v23 = v38;
          }
          ++v24;
        }
        break;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LODWORD(v35) = *((_DWORD *)a3 + 9);
      WPP_SF_SD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x2Bu,
        (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
        v39,
        v35);
      return (unsigned int)-2146893007;
    }
    return (unsigned int)-2146893007;
  }
LABEL_20:
  v28 = a4;
  if ( (v21 & 0x1000) == 0 )
  {
    v29 = 0;
    goto LABEL_22;
  }
  v29 = 1;
  if ( !a4 )
    goto LABEL_22;
  HashInfo = GetHashInfo(*((_DWORD *)a3 + 11));
  if ( HashInfo )
  {
    if ( a7 != *((_DWORD *)HashInfo + 8) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LODWORD(v35) = a7;
        WPP_SF_Sd(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x2Cu,
          (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
          v39,
          v35);
        return (unsigned int)-2146893007;
      }
      return (unsigned int)-2146893007;
    }
    v28 = a4;
LABEL_22:
    if ( v20 == 3 || v29 )
    {
      AcceptableKeyXCurve = CCipherMill::FindAcceptableKeyXCurve((CCipherMill *)a6, a2, a3, v28, a6, String2, a8, a9);
      if ( AcceptableKeyXCurve )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LODWORD(v36) = AcceptableKeyXCurve;
          WPP_SF_SD(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x2Du,
            (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
            (const wchar_t *)a3 + 37,
            v36);
        }
        return AcceptableKeyXCurve;
      }
    }
    else if ( v20 == 2
           && IsDheAlgorithmBlacklisted(*(struct _TLS_PARAMETERS **)(v37 + 200), *(_DWORD *)(v37 + 196), 0, String2, a6) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x2Eu,
          (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
          v39);
        return (unsigned int)-2146893007;
      }
      return (unsigned int)-2146893007;
    }
    return 0;
  }
  return 1359i64;
}
// 18001CDD3: variable 'v20' is possibly undefined
// 18003101B: variable 'v35' is possibly undefined
// 1800310ED: variable 'v29' is possibly undefined
// 1800311AF: variable 'v36' is possibly undefined
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
