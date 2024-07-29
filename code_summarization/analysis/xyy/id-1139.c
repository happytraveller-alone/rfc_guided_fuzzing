//----- (000000018005C318) ----------------------------------------------------
unsigned __int8 __fastcall DoesTlsParameterContainAlpnId(struct _TLS_PARAMETERS *a1, struct _UNICODE_STRING *a2)
{
  unsigned int v4; // edi

  if ( !a1 || !*(_DWORD *)a1 || !a2 )
    return 0;
  v4 = 0;
  while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*((_QWORD *)a1 + 1) + 16i64 * v4), a2, 1u) )
  {
    if ( ++v4 >= *(_DWORD *)a1 )
      return 0;
  }
  return 1;
}
