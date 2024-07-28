//----- (000000018005C020) ----------------------------------------------------
__int64 __fastcall ConvertPubKeyToBcryptHdl(struct CSslContext *a1, const unsigned __int16 *a2, void **a3)
{
  unsigned int v6; // edi
  BOOL v7; // ebx

  v6 = 0;
  if ( !wcsncmp(a2, L"ECDSA", 5ui64) )
  {
    RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64), 1u);
    v7 = CryptImportPublicKeyInfoEx2(
           **(_DWORD **)(*((_QWORD *)a1 + 11) + 48i64),
           (PCERT_PUBLIC_KEY_INFO)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)a1 + 11) + 48i64) + 24i64) + 96i64),
           0x80000000,
           0i64,
           a3);
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64));
    if ( !v7 )
      return (unsigned int)-2146893052;
  }
  else
  {
    return (unsigned int)ImportNcryptExportBcrypt(a1, a2, a3);
  }
  return v6;
}
