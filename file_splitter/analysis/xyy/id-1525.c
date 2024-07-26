//----- (000000018007ADF4) ----------------------------------------------------
__int64 __fastcall PacValidateInfo3(struct _NETLOGON_VALIDATION_SAM_INFO3 *const a1)
{
  unsigned int v2; // ecx
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edi

  v2 = *((_DWORD *)a1 + 39);
  if ( v2 > 0x4000 )
    return 3221225818i64;
  v3 = *((_DWORD *)a1 + 74);
  if ( v3 > 0x4000 )
    return 3221225818i64;
  v4 = *((_DWORD *)a1 + 68);
  if ( v4 > 0x4000 || v2 + v4 + v3 > 0x4000 )
    return 3221225818i64;
  if ( RtlValidSid(*((PSID *)a1 + 28))
    && *RtlSubAuthorityCountSid(*((PSID *)a1 + 28)) != 15
    && ((*((_DWORD *)a1 + 42) & 0x200) == 0
     || !*((_DWORD *)a1 + 74)
     || RtlValidSid(*((PSID *)a1 + 36)) && *RtlSubAuthorityCountSid(*((PSID *)a1 + 36)) != 15) )
  {
    v5 = 0;
    if ( !*((_DWORD *)a1 + 68) )
      return 0i64;
    while ( RtlValidSid(*(PSID *)(*((_QWORD *)a1 + 35) + 16i64 * v5)) )
    {
      if ( ++v5 >= *((_DWORD *)a1 + 68) )
        return 0i64;
    }
  }
  return 3221225592i64;
}

