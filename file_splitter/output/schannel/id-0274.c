//----- (00000001800156A0) ----------------------------------------------------
__int64 __fastcall CopyUnicodeString(char a1, struct _UNICODE_STRING *a2, struct _UNICODE_STRING *a3)
{
  unsigned int v5; // edi
  unsigned __int64 v6; // rax
  WCHAR *v7; // rax
  unsigned int Length; // edx
  PWSTR Buffer; // rcx
  __int128 v11; // [rsp+30h] [rbp-18h] BYREF

  v5 = 0;
  v11 = 0i64;
  if ( a2 && a3 )
  {
    if ( a1 )
    {
      v5 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, struct _UNICODE_STRING *))(LsaTable + 80))(
             0i64,
             16i64,
             &v11,
             a2);
      if ( v5 )
        goto LABEL_25;
    }
    else
    {
      v11 = (__int128)*a2;
    }
    v6 = (unsigned __int64)v11 >> 16;
    if ( WORD1(v11)
      && (_WORD)v11
      && *((_QWORD *)&v11 + 1)
      && (v11 & 1) == 0
      && (BYTE2(v11) & 1) == 0
      && (unsigned __int16)v11 <= WORD1(v11)
      && WORD1(v11) != 0xFFFF )
    {
      a3->Length = v11;
      a3->MaximumLength = v6;
      v7 = (WCHAR *)SPExternalAlloc((unsigned __int16)v6);
      a3->Buffer = v7;
      if ( !v7 )
      {
        v5 = -2146893056;
LABEL_25:
        Buffer = a3->Buffer;
        if ( Buffer )
        {
          SPExternalFree(Buffer);
          a3->Buffer = 0i64;
        }
        *(_DWORD *)&a3->Length = 0;
        return v5;
      }
      if ( a1 )
      {
        v5 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, WCHAR *, _QWORD))(LsaTable + 80))(
               0i64,
               WORD1(v11),
               v7,
               *((_QWORD *)&v11 + 1));
        if ( v5 )
          goto LABEL_25;
      }
      else
      {
        memcpy_0(v7, *((const void **)&v11 + 1), a3->MaximumLength);
      }
      Length = a3->Length;
      if ( a3->Buffer[((unsigned __int64)a3->Length >> 1) - 1] )
        return v5;
      if ( Length > 2 )
      {
        a3->Length = Length - 2;
        return v5;
      }
    }
    v5 = -2146892963;
    goto LABEL_25;
  }
  return 2148074333i64;
}
// 180092620: using guessed type __int64 LsaTable;

