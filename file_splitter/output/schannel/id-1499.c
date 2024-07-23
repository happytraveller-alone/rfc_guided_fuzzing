// File count: 1499
// Total lines: 49
----------------------------------------
__int64 __fastcall CTls13ExtClient::ParseSupportedVersionsExtension(
        CTls13ExtClient *this,
        unsigned __int8 *a2,
        __int16 a3)
{
  __int64 v3; // r10
  unsigned int v4; // ecx
  __int64 result; // rax
  int v6; // eax
  __int64 v7; // r10
  __int64 v8; // rdx
  int v9; // eax
  __int16 v10; // ax
  __int64 v11; // r10
  __int64 v12; // r9

  if ( !a2 || a3 != 2 )
    return 2148074248i64;
  v3 = *((_QWORD *)this + 8);
  v4 = a2[1] | (*a2 << 8);
  if ( v4 < 0x304 )
  {
    CSslContext::SetErrorAndFatalAlert(v3, 100, -2146893048, 0x2Fu);
    return 2148074248i64;
  }
  if ( !*(_QWORD *)(v3 + 80) )
    return 2148074244i64;
  v6 = ConvertSslVersionToSchannelProtocol(v4);
  v9 = *(_DWORD *)(v8 + 152) & v6 & 0xA2AA0;
  if ( v9 )
  {
    *(_DWORD *)(v7 + 64) = v9;
    v10 = ConvertSchannelProtocolToSsl(v9);
    *(_WORD *)(v11 + 34) = v10;
    result = 0i64;
    *(_BYTE *)(v12 + 27) = 1;
  }
  else
  {
    CSslContext::SetErrorAndFatalAlert(v7, 1201, -2146893007, 0x46u);
    return 2148074289i64;
  }
  return result;
}
// 18007861D: variable 'v8' is possibly undefined
// 18007863B: variable 'v7' is possibly undefined
// 180078652: variable 'v11' is possibly undefined
// 180078659: variable 'v12' is possibly undefined
