// File count: 1496
// Total lines: 182
---------------------------------------
__int64 __fastcall CTls13ExtServer::ParsePreSharedKeyExtension(
        CTls13ExtServer *this,
        unsigned __int8 *a2,
        unsigned __int16 a3,
        __int64 a4)
{
  unsigned int v5; // ebx
  __int64 v6; // rcx
  __int16 v7; // di
  __int16 v8; // ax
  unsigned __int16 v9; // r8
  unsigned __int8 *v10; // rdx
  unsigned __int16 v11; // di
  unsigned __int8 *v12; // r14
  unsigned __int16 *v13; // rdx
  unsigned __int16 v14; // r8
  unsigned __int16 v15; // si
  unsigned __int16 v16; // r12
  unsigned __int8 *v17; // r15
  __int16 v18; // dx
  unsigned __int16 v19; // di
  __int16 v20; // ax
  unsigned __int8 *v21; // r14
  unsigned __int8 *v22; // r10
  unsigned __int16 v23; // dx
  unsigned __int16 v24; // di
  unsigned __int16 v25; // si
  __int64 v26; // rax
  unsigned __int8 *v27; // r15
  unsigned __int16 v28; // r13
  __int64 v29; // rcx
  unsigned __int8 *v30; // r11
  __int64 v31; // rax
  unsigned __int8 v32; // al
  _QWORD *v33; // rdi
  __int64 v34; // rax
  unsigned __int16 v36; // [rsp+78h] [rbp+10h]
  unsigned __int8 *v37; // [rsp+88h] [rbp+20h]

  v5 = 0;
  if ( !a2 || a3 < 2u )
    goto LABEL_35;
  v6 = *((_QWORD *)this + 1);
  a4 = *(_QWORD *)(v6 + 80);
  if ( a4 )
  {
    if ( (*(_DWORD *)(v6 + 136) & 0x2000000) == 0
      || (*(_BYTE *)(a4 + 156) & 0x20) != 0
      || !*((_BYTE *)this + 27)
      || (*(_DWORD *)(v6 + 64) & 0x1000) == 0 )
    {
      return v5;
    }
    v7 = *a2;
    v8 = a2[1];
    v9 = a3 - 2;
    v10 = a2 + 2;
    v11 = v8 | (v7 << 8);
    if ( v11 <= v9 )
    {
      v12 = v10;
      v13 = (unsigned __int16 *)&v10[v11];
      v14 = v9 - v11;
      if ( v14 >= 2u )
      {
        v15 = _byteswap_ushort(*v13);
        if ( v15 == v14 - 2 )
        {
          v16 = 0;
          v36 = v15 + 2;
          v17 = (unsigned __int8 *)(v13 + 1);
          if ( !v11 )
            return v5;
          while ( 1 )
          {
            if ( !v15 )
              return v5;
            if ( v11 < 0x26u )
              break;
            v18 = *v12;
            v19 = v11 - 2;
            v20 = v12[1];
            v21 = v12 + 2;
            v22 = v21;
            v23 = v20 | (v18 << 8);
            if ( v23 > v19 )
              break;
            v24 = v19 - v23;
            if ( v24 < 4u )
              break;
            v12 = &v21[v23 + 4];
            v25 = v15 - 1;
            v11 = v24 - 4;
            v26 = *v17;
            v27 = v17 + 1;
            v28 = v26;
            if ( (unsigned __int16)v26 > v25 )
              break;
            v29 = *((_QWORD *)this + 5);
            v15 = v25 - v26;
            v30 = v27;
            v37 = v27;
            v17 = &v27[v26];
            a4 = 32i64;
            v31 = *(_QWORD *)(v29 + 120);
            if ( v23 == 32 )
            {
              if ( v31 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
              {
                *(_WORD *)(v31 + 64) |= 1u;
                *(_DWORD *)(v31 + 24) = 1;
                v29 = *((_QWORD *)this + 5);
              }
              if ( !v22 )
              {
                v32 = 0;
                goto LABEL_30;
              }
              v32 = CSessionCacheManager::LookupCacheForServerItem(
                      CSessionCacheManager::m_pSessionCacheManager,
                      (struct CSslContext *)v29,
                      v22,
                      0x20u,
                      (struct CSessionCacheServerItem **)(v29 + 992));
            }
            else
            {
              if ( v31 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
              {
                *(_DWORD *)(v31 + 24) = 1;
                *(_WORD *)(v31 + 64) |= 2u;
                v29 = *((_QWORD *)this + 5);
              }
              v32 = CSsl3TlsServerContext::UnprotectAndDeserializeSessionState(
                      (CSsl3TlsServerContext *)v29,
                      v22,
                      v23,
                      (unsigned __int8 *const)(v29 + 1249),
                      *(unsigned __int8 *)(v29 + 1281));
            }
            v30 = v37;
LABEL_30:
            if ( v32 )
            {
              v5 = CTls13ServerContext::VerifyBinder(*((CTls13ServerContext **)this + 5), v30, v28, v36, v16);
              if ( !v5 )
                return v5;
              goto LABEL_36;
            }
            ++v16;
            if ( !v11 )
              return v5;
          }
        }
      }
    }
LABEL_35:
    v5 = 315;
    goto LABEL_36;
  }
  v5 = 1359;
LABEL_36:
  v33 = (_QWORD *)*((_QWORD *)this + 5);
  v34 = v33[124];
  if ( v34 )
  {
    *(_BYTE *)(v34 + 236) = 0;
    (*(void (__fastcall **)(_QWORD *))(*v33 + 240i64))(v33);
  }
  v33[11] = 0i64;
  if ( v5 == 315 )
  {
    v5 = -2146893048;
    LOBYTE(a4) = 50;
    CSslContext::SetErrorAndFatalAlert(*((_QWORD *)this + 1), 1202i64, 2148074248i64, a4);
  }
  return v5;
}
// 180078403: variable 'a4' is possibly undefined
// 18005B470: using guessed type __int64 __fastcall CSslContext::SetErrorAndFatalAlert(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
