//----- (000000018005D5D4) ----------------------------------------------------
__int64 __fastcall CSessionCacheItem::GetPrfHashDetails(
        CSessionCacheItem *this,
        unsigned __int8 *a2,
        enum _eTlsHashAlgorithm *a3)
{
  __int64 v3; // rax
  struct hsel *HashInfo; // rax
  _DWORD *v5; // r8
  _BYTE *v6; // r10

  v3 = *((_QWORD *)this + 22);
  if ( !v3 )
    return 1359i64;
  HashInfo = GetHashInfo(*(_DWORD *)(v3 + 44));
  if ( !HashInfo )
    return 1359i64;
  if ( v6 )
  {
    if ( *((_DWORD *)HashInfo + 7) > 0x40u )
    {
      *v6 = 0;
      return 1359i64;
    }
    *v6 = *((_BYTE *)HashInfo + 28);
  }
  if ( v5 )
    *v5 = *((_DWORD *)HashInfo + 8);
  return 0i64;
}
// 18005D5FA: variable 'v6' is possibly undefined
// 18005D61A: variable 'v5' is possibly undefined

