//----- (0000000180009670) ----------------------------------------------------
__int64 __fastcall CTlsExtClient::GetClientHelloExtensionsLength(CTlsExtClient *this, unsigned int *a2)
{
  __int64 v4; // rcx
  unsigned int v5; // edi
  __int64 v6; // rsi
  int v7; // edx
  int v8; // r8d
  int v9; // edx
  const unsigned __int16 *v10; // rax
  __int64 result; // rax
  __int64 v12; // rcx
  __int64 v13; // rax
  int v14; // ecx
  unsigned __int16 *v15; // r8
  unsigned __int16 *v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rcx
  unsigned int v19; // edx
  __int64 v20; // rax
  __int64 v21; // r8
  unsigned int v22; // ecx
  __int64 v23; // rax
  __int64 v24; // rax
  unsigned __int16 *v25; // rax
  int v26; // ecx
  int v27; // r9d
  unsigned __int8 *v28; // rax
  __int64 v29; // [rsp+30h] [rbp+8h] BYREF

  v4 = *((_QWORD *)this + 7);
  v5 = 0;
  v6 = *(_QWORD *)(v4 + 80);
  v7 = *((_DWORD *)this + 5) + 5;
  v29 = 0i64;
  *((_BYTE *)this + 26) = 1;
  v8 = *(_DWORD *)(v4 + 416);
  v9 = v8 + v7;
  *((_DWORD *)this + 5) = v9;
  if ( (*(_DWORD *)(v4 + 64) & 0x2A88) == 0 && (*(_BYTE *)(v4 + 64) & 0x20) != 0 )
  {
    if ( *(_BYTE *)(*((_QWORD *)this + 1) + 553i64) && v8 )
      v5 = v9 + 2;
    else
      *((_BYTE *)this + 26) = 0;
    *((_DWORD *)this + 5) = v5;
    *a2 = v5;
    return 0i64;
  }
  if ( (*(_DWORD *)(v4 + 64) & 0xA2A80) != 0 )
  {
    if ( (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 320i64))(v4) )
    {
      v10 = (const unsigned __int16 *)(*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 7) + 320i64))(*((_QWORD *)this + 7));
      result = CTlsExtClient::BuildServerNameString(this, v10);
      if ( (_DWORD)result )
        return result;
      v12 = *((_QWORD *)this + 5);
      if ( v12 )
      {
        v13 = -1i64;
        do
          ++v13;
        while ( *(_BYTE *)(v12 + v13) );
        *((_DWORD *)this + 12) = v13;
        *((_DWORD *)this + 5) += v13 + 9;
      }
    }
    v14 = *((_DWORD *)this + 5);
    if ( (*(_DWORD *)(v6 + 160) & 0x700) != 0 )
    {
      v14 += 9;
      *((_BYTE *)this + 24) = 1;
      *((_DWORD *)this + 5) = v14;
    }
    v15 = (unsigned __int16 *)*((_QWORD *)this + 7);
    if ( v15[460] )
    {
      *((_BYTE *)this + 32) = 1;
      *((_DWORD *)this + 5) = v14 + 2 * (v15[460] + 6);
    }
    v16 = (unsigned __int16 *)(*(__int64 (__fastcall **)(unsigned __int16 *))(*(_QWORD *)v15 + 320i64))(v15);
    if ( (unsigned int)CheckUserMappingTarget(v16) && (*(_QWORD *)(v6 + 872) || *(_QWORD *)(v6 + 880)) )
    {
      *((_DWORD *)this + 5) += 6;
      *((_BYTE *)this + 25) = 1;
    }
    v17 = *((_QWORD *)this + 7);
    if ( *(_BYTE *)(v17 + 925) )
      *((_DWORD *)this + 5) += 2 * *(unsigned __int16 *)(v17 + 474) + 6;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v17 + 224i64))(v17, &v29);
    if ( v29 )
      *((_DWORD *)this + 5) += *(_DWORD *)(v29 + 432) + 4;
    v18 = *((_QWORD *)this + 1);
    v19 = *((_DWORD *)this + 5);
    v20 = *(_QWORD *)(v18 + 784);
    if ( v20 )
    {
      v19 += *(unsigned __int16 *)(v20 + 4) + 6;
      *((_DWORD *)this + 5) = v19;
    }
    if ( CSslGlobals::m_fDisableClientExtendedMS )
    {
      v24 = *(_QWORD *)(v18 + 120);
      if ( !v24 || !CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        goto LABEL_23;
      *(_WORD *)(v24 + 66) |= 8u;
    }
    else
    {
      *(_BYTE *)(*((_QWORD *)this + 7) + 1344i64) = 1;
      *((_DWORD *)this + 5) += 4;
    }
    v19 = *((_DWORD *)this + 5);
LABEL_23:
    v21 = *((_QWORD *)this + 7);
    v22 = v19;
    if ( *(_BYTE *)(v21 + 233) )
    {
      v25 = *(unsigned __int16 **)(v21 + 800);
      if ( v25 )
      {
        v26 = *v25;
        v27 = 7;
        v28 = *(unsigned __int8 **)(v21 + 1336);
        if ( v28 )
          v27 = *v28 + 7;
        v22 = v27 + v19 + v26;
        *((_DWORD *)this + 5) = v22;
      }
    }
    v23 = *(_QWORD *)(v21 + 816);
    if ( v23 )
    {
      v22 += *(unsigned __int8 *)(v23 + 2) + 7;
      *((_DWORD *)this + 5) = v22;
    }
    if ( v22 )
    {
      v22 += 2;
      *((_DWORD *)this + 5) = v22;
    }
    *a2 = v22;
  }
  return 0i64;
}
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 1800927B8: using guessed type int CSslGlobals::m_fDisableClientExtendedMS;

