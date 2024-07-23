//----- (000000018000A590) ----------------------------------------------------
__int64 __fastcall CTlsExtClient::ParseExtension(__int64 a1, __int64 a2, unsigned __int8 *a3, unsigned __int16 a4)
{
  unsigned int v4; // ebp
  unsigned int v5; // edi
  unsigned __int8 *v8; // r9
  int v9; // r8d
  __int64 v10; // rax
  __int64 v11; // rcx
  unsigned int v12; // r13d
  int v13; // r9d
  CCipherMill *v14; // rcx
  __int64 result; // rax
  _DWORD *v16; // rax
  unsigned __int16 v17; // r8
  __int64 v18; // rcx
  int v19; // edx
  __int64 v20; // rax
  CCipherMill *v21; // rcx
  __int64 v22; // rdx
  char *v23; // r14
  CCipherMill *v24; // r15
  __int64 v25; // rdx
  CSsl3TlsClientContext *v26; // rcx
  __int64 v27; // rcx
  CSsl3TlsClientContext *v28; // r10
  __int16 v29; // cx
  unsigned __int16 v30; // ax
  unsigned __int8 *v31; // r14
  unsigned __int16 *v32; // rdx
  unsigned __int8 *v33; // r14
  unsigned __int16 v34; // cx
  unsigned __int8 *v35; // r14
  unsigned int v36; // ecx
  _BYTE *v37; // r14
  unsigned int Size; // [rsp+30h] [rbp-48h]
  void *Buf2; // [rsp+38h] [rbp-40h]
  void *v40; // [rsp+40h] [rbp-38h]

  v4 = 0;
  v5 = a4;
  v8 = 0i64;
  v9 = 5;
  switch ( (_DWORD)a2 )
  {
    case 5:
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 136i64) |= 0x20000ui64;
      goto LABEL_20;
    case 6:
      if ( (_WORD)v5 )
      {
        v36 = *a3;
        v37 = a3 + 1;
        if ( v36 == v5 - 1 )
        {
          if ( !*(_BYTE *)(a1 + 52) )
            return 0i64;
          if ( v36 )
          {
            while ( *v37 != 64 )
            {
              ++v4;
              ++v37;
              if ( v4 >= v36 )
                goto LABEL_80;
            }
            *(_BYTE *)(*(_QWORD *)(a1 + 8) + 922i64) = 1;
          }
LABEL_80:
          v9 = 6;
          goto LABEL_20;
        }
      }
      return 2148074278i64;
    case 0xE:
      v28 = *(CSsl3TlsClientContext **)(a1 + 56);
      if ( (*((_DWORD *)v28 + 34) & 0x2000i64) == 0 || (unsigned __int16)(v5 - 5) > 0xFFu )
      {
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v22 = 37i64;
        goto LABEL_126;
      }
      v29 = *a3;
      v30 = a3[1];
      v31 = a3 + 2;
      if ( (v30 | (unsigned __int16)(v29 << 8)) != 2 )
      {
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v22 = 38i64;
        goto LABEL_126;
      }
      v32 = (unsigned __int16 *)v31;
      v33 = v31 + 2;
      v34 = *v33;
      v35 = v33 + 1;
      if ( (_BYTE)v34 )
      {
        if ( (unsigned __int16)(v5 - 5) < v34 )
        {
          v21 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            return 2148074278i64;
          }
          v22 = 39i64;
          goto LABEL_126;
        }
        v8 = v35;
      }
      result = CSsl3TlsClientContext::SetNegotiatedSrtpParameters(v28, v32, 2u, v8, v34);
      if ( !(_DWORD)result )
      {
        v9 = 14;
        goto LABEL_20;
      }
      break;
    case 0x10:
      v16 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD, __int64, __int64, _QWORD))(**(_QWORD **)(a1 + 8) + 88i64))(
                        *(_QWORD *)(a1 + 8),
                        a2,
                        5i64,
                        0i64);
      if ( v16 && *v16 )
      {
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v22 = 33i64;
        goto LABEL_126;
      }
      if ( (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 136i64) & 0x4000000) == 0 || (unsigned __int16)(v5 - 4) > 0xFEu )
      {
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v22 = 34i64;
        goto LABEL_126;
      }
      v17 = _byteswap_ushort(*(_WORD *)a3);
      if ( v17 != v5 - 2 )
      {
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v22 = 35i64;
        goto LABEL_126;
      }
      result = CSsl3TlsClientContext::SetSelectedApplicationProtocol(*(CSsl3TlsClientContext **)(a1 + 56), a3 + 2, v17);
      if ( !(_DWORD)result )
      {
        v9 = 16;
        goto LABEL_20;
      }
      break;
    case 0x17:
      if ( !*(_BYTE *)(*(_QWORD *)(a1 + 56) + 1344i64) )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
        v27 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 120i64);
        if ( v27 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
          *(_WORD *)(v27 + 66) |= 4u;
        return 2148074278i64;
      }
      v9 = 23;
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 136i64) |= 0x8000000ui64;
      goto LABEL_20;
    case 0x18:
      v26 = *(CSsl3TlsClientContext **)(a1 + 56);
      if ( (*((_DWORD *)v26 + 34) & 0x80000000) == 0 || v5 < 4 )
      {
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v22 = 40i64;
        goto LABEL_126;
      }
      if ( (unsigned __int16)(v5 - 3) < a3[2] || a3[2] != 1 )
      {
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return 2148074278i64;
        v22 = 41i64;
        goto LABEL_126;
      }
      result = CSsl3TlsClientContext::SetNegotiatedTBParameters(v26, *a3, a3[1], a3 + 3, a3[2]);
      if ( !(_DWORD)result )
      {
        v9 = 24;
        goto LABEL_20;
      }
      break;
    case 0x23:
      v9 = 35;
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 136i64) |= 0x400000ui64;
LABEL_20:
      CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 120i64), 1, v9);
      return 0i64;
    case 0xFF01:
      v10 = *(_QWORD *)(a1 + 8);
      if ( *(_DWORD *)(v10 + 416) && !*(_BYTE *)(v10 + 553) )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 42i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
          v10 = *(_QWORD *)(a1 + 8);
        }
        CSslContext::SetErrorAndFatalAlert(v10, 1207, -2146892986, 0x28u);
        v18 = *(_QWORD *)(a1 + 8);
        *(_DWORD *)(v18 + 68) = 96;
        *(_WORD *)(v18 + 96) = 10242;
        return 2148074310i64;
      }
      *(_BYTE *)(v10 + 553) = 1;
      v11 = *(_QWORD *)(a1 + 8);
      v12 = *(_DWORD *)(v11 + 456);
      Buf2 = (void *)(v11 + 377);
      v40 = (void *)(v11 + 420);
      Size = *(_DWORD *)(v11 + 416);
      if ( (_WORD)v5 )
      {
        v13 = *a3;
        if ( v13 + 1 == v5 )
        {
          if ( (_WORD)v5 == 1 )
          {
            v14 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 45i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
              v14 = WPP_GLOBAL_Control;
            }
            if ( !v12 )
              return 0i64;
            if ( v14 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v14 + 28) & 1) != 0 )
              WPP_SF_DD(*((_QWORD *)v14 + 2), 0x2Eu, (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids, v5, v12);
            v19 = 1207;
            goto LABEL_38;
          }
          v23 = (char *)(a3 + 1);
          if ( v13 != *(_DWORD *)(v11 + 416) + v12 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_DD(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0x2Fu,
                (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
                v13,
                *(_DWORD *)(v11 + 416));
              v11 = *(_QWORD *)(a1 + 8);
            }
            v19 = 1207;
            goto LABEL_39;
          }
          v24 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 48i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
              v24 = WPP_GLOBAL_Control;
            }
            if ( v24 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_DWORD *)v24 + 7) & 0x800) != 0 )
              {
                WPP_SF_(*((_QWORD *)v24 + 2), 49i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
                v24 = WPP_GLOBAL_Control;
              }
              if ( v24 != (CCipherMill *)&WPP_GLOBAL_Control )
              {
                if ( (*((_DWORD *)v24 + 7) & 0x800) != 0 )
                {
                  WPP_SF_(*((_QWORD *)v24 + 2), 50i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
                  v24 = WPP_GLOBAL_Control;
                }
                if ( v24 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v24 + 7) & 0x800) != 0 )
                {
                  WPP_SF_(*((_QWORD *)v24 + 2), 51i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
                  v24 = WPP_GLOBAL_Control;
                }
              }
            }
          }
          if ( memcmp_0(v23, Buf2, Size) )
          {
            if ( v24 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v24 + 28) & 1) == 0 )
              goto LABEL_73;
            v25 = 52i64;
LABEL_72:
            WPP_SF_(*((_QWORD *)v24 + 2), v25, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
LABEL_73:
            v19 = 108;
LABEL_38:
            v11 = *(_QWORD *)(a1 + 8);
LABEL_39:
            CSslContext::SetErrorAndFatalAlert(v11, v19, -2146892986, 0x28u);
            v20 = *(_QWORD *)(a1 + 8);
            *(_DWORD *)(v20 + 68) = 96;
            *(_WORD *)(v20 + 96) = 10242;
            return 2148074310i64;
          }
          if ( memcmp_0(&v23[Size], v40, v12) )
          {
            if ( v24 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v24 + 28) & 1) == 0 )
              goto LABEL_73;
            v25 = 53i64;
            goto LABEL_72;
          }
          v9 = 65281;
          goto LABEL_20;
        }
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0 )
        {
          WPP_SF_DD(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x2Cu,
            (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
            v13,
            v5);
        }
        return 2148074278i64;
      }
      v21 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v22 = 43i64;
LABEL_126:
      WPP_SF_(*((_QWORD *)v21 + 2), v22, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
      return 2148074278i64;
    default:
      CSchannelTelemetryContext::LogUnknownTlsExtension(
        *(CSchannelTelemetryContext **)(*(_QWORD *)(a1 + 8) + 120i64),
        a2);
      return 0i64;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

