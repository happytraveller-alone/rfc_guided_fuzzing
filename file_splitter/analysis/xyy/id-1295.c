//----- (00000001800663BC) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateList(__int64 a1)
{
  __int64 v2; // rcx
  __int64 result; // rax
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 *v7; // rdi
  __int64 v8; // rdi
  unsigned int v9; // ebx
  __int64 v10; // r14
  struct _CRYPTOAPI_BLOB *v11; // rdx
  bool v12; // zf
  __int64 v13; // rdx
  char v14; // [rsp+40h] [rbp+8h] BYREF
  __int16 v15; // [rsp+48h] [rbp+10h] BYREF

  v2 = *(_QWORD *)(a1 + 32);
  v14 = 0;
  result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v2 + 32i64))(v2, 1i64, &v14);
  if ( !(_DWORD)result )
  {
    v4 = *(_QWORD *)(a1 + 32);
    v15 = __ROR2__(*(_WORD *)(a1 + 64), 8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v4 + 32i64))(v4, 2i64, &v15);
    if ( !(_DWORD)result )
    {
      v5 = *(_QWORD *)(a1 + 72);
      if ( !v5 )
        return (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 64i64) & 0x40051555) != 0 ? 0x54F : 0;
      v6 = *(_QWORD *)(v5 + 64);
      if ( v6 )
      {
        v7 = *(__int64 **)(v6 + 16);
        if ( v7 )
        {
          if ( *(_DWORD *)(v6 + 12) )
          {
            v8 = *v7;
            if ( v8 && *(_QWORD *)(v8 + 16) && *(_DWORD *)(v8 + 12) )
            {
              v9 = 0;
              while ( 1 )
              {
                v10 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 16) + 8i64 * v9) + 8i64);
                if ( !v10 )
                  return 87i64;
                v11 = *(struct _CRYPTOAPI_BLOB **)(v10 + 24);
                if ( !v11 )
                  return 87i64;
                if ( *(_BYTE *)(a1 + 80) )
                  goto LABEL_17;
                v12 = v9 == 0;
                if ( v9 )
                  break;
LABEL_18:
                result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateEntry(a1, v10, v12);
                if ( (_DWORD)result )
                  return result;
                if ( ++v9 >= *(_DWORD *)(v8 + 12) )
                  return 0i64;
              }
              if ( CertCompareCertificateName(*(_DWORD *)v10, v11 + 3, v11 + 5) )
                return 0i64;
LABEL_17:
              v12 = v9 == 0;
              goto LABEL_18;
            }
            return 87i64;
          }
        }
      }
      v13 = *(_QWORD *)(v5 + 32);
      if ( !v13 )
        return 87i64;
      result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertificateEntry(a1, v13, 1);
      if ( !(_DWORD)result )
        return 0i64;
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

