// File count: 1261
// Total lines: 72
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateListSize(__int64 a1)
{
  unsigned __int16 *v1; // r14
  __int64 v3; // rcx
  __int64 result; // rax
  __int64 v5; // rax
  __int64 *v6; // rbx
  __int64 v7; // rbx
  unsigned int v8; // esi
  __int64 v9; // r15
  struct _CRYPTOAPI_BLOB *v10; // rdx
  int v11; // edx
  __int64 v12; // rdx
  unsigned __int16 v13; // [rsp+40h] [rbp+8h] BYREF

  v1 = (unsigned __int16 *)(a1 + 64);
  *(_WORD *)(a1 + 64) = 0;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
    return (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 64i64) & 0x40051555) != 0 ? 0x54F : 0;
  v5 = *(_QWORD *)(v3 + 64);
  if ( v5 )
  {
    v6 = *(__int64 **)(v5 + 16);
    if ( v6 )
    {
      if ( *(_DWORD *)(v5 + 12) )
      {
        v7 = *v6;
        if ( v7 && *(_QWORD *)(v7 + 16) && *(_DWORD *)(v7 + 12) )
        {
          v8 = 0;
          while ( 1 )
          {
            v9 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 16) + 8i64 * v8) + 8i64);
            if ( !v9 )
              break;
            v10 = *(struct _CRYPTOAPI_BLOB **)(v9 + 24);
            if ( !v10 )
              break;
            if ( !*(_BYTE *)(a1 + 80) && v8 && CertCompareCertificateName(*(_DWORD *)v9, v10 + 3, v10 + 5) )
              return 0i64;
            v13 = 0;
            result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateEntrySize(
                       a1,
                       v9,
                       v8 == 0,
                       &v13);
            if ( (_DWORD)result )
              return result;
            v11 = *v1;
            if ( 0xFFFF - v11 < v13 )
              break;
            ++v8;
            *v1 = v13 + v11;
            if ( v8 >= *(_DWORD *)(v7 + 12) )
              return 0i64;
          }
        }
        return 87i64;
      }
    }
  }
  v12 = *(_QWORD *)(v3 + 32);
  if ( !v12 )
    return 87i64;
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateEntrySize(a1, v12, 1, v1);
  if ( !(_DWORD)result )
    return 0i64;
  return result;
}
