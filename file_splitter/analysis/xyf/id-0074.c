//----- (0000000180005FC4) ----------------------------------------------------
__int64 __fastcall ConvertSslVersionToSchannelProtocol(int a1)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v7; // ecx
  int v8; // ecx

  v1 = a1 - 2;
  if ( !v1 )
    return 12i64;
  v2 = v1 - 766;
  if ( !v2 )
    return 48i64;
  v3 = v2 - 1;
  if ( !v3 )
    return 192i64;
  v4 = v3 - 1;
  if ( !v4 )
    return 768i64;
  v5 = v4 - 1;
  if ( !v5 )
    return 3072i64;
  v7 = v5 - 1;
  if ( !v7 )
    return 12288i64;
  v8 = v7 - 64505;
  if ( !v8 )
    return 786432i64;
  if ( v8 == 2 )
    return 196608i64;
  return 0i64;
}

